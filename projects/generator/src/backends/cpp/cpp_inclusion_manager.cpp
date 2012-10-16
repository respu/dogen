/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include "dogen/utility/log/logger.hpp"
#include "dogen/generator/backends/cpp/cpp_inclusion_manager.hpp"

namespace {

using namespace dogen::utility::log;
static logger lg(logger_factory("inclusion_manager"));

const std::string empty;
const std::string bool_type("bool");
const std::string versioned_name("versioned_key");
const std::string unversioned_name("unversioned_key");
const std::string vector_include("vector");
const std::string boost_optional_include("boost/optional.hpp");
const std::string pqxx_connection_include("pqxx/connection.hxx");
const std::string boost_format_include("boost/format.hpp");
const std::string boost_nvp("boost/serialization/nvp.hpp");
const std::string pqxx_result_include("pqxx/result.hxx");
const std::string pqxx_transaction_include("pqxx/transaction.hxx");
const std::string iosfwd("iosfwd");
const std::string algorithm("algorithm");
const std::string ostream("ostream");
const std::string state_saver("boost/io/ios_state.hpp");
const std::string functional("functional");
const std::string jsonify_include("dogen/utility/io/jsonify_io.hpp");
const std::string hash_combine("dogen/utility/hash/combine.hpp");
const std::string generator_include("dogen/utility/test_data/generator.hpp");
const std::string sequence_include("dogen/utility/test_data/sequence.hpp");

}

namespace dogen {
namespace generator {
namespace backends {
namespace cpp {

cpp_inclusion_manager::cpp_inclusion_manager(const sml::model& model,
    const cpp_location_manager& location_manager,
    const config::cpp_settings settings)
    : model_(model), location_manager_(location_manager), settings_(settings) {

    const auto f(settings_.enabled_facets());
    disable_io_ = f.find(cpp_facet_types::io) == f.end();

    BOOST_LOG_SEV(lg, debug)
        << "Initial configuration:"
        << " disable_versioning: " << settings_.disable_versioning()
        << " use_integrated_io: " << settings_.use_integrated_io()
        << " disable_io: " << disable_io_
        << " model name: " << model_.name();
}

cpp_location_request cpp_inclusion_manager::
location_request_factory(cpp_facet_types ft, cpp_file_types flt,
    const sml::qualified_name& name) const {

    cpp_location_request r;
    r.facet_type(ft);
    r.file_type(flt);
    r.model_name(model_.name());
    r.package_path(name.package_path());
    r.file_name(name.type_name());
    r.external_package_path(name.external_package_path());
    return r;
}

void cpp_inclusion_manager::register_header(cpp_facet_types ft,
    const boost::filesystem::path& relative_path) {
    headers_for_facet_[ft].push_back(relative_path.generic_string());
}

std::list<std::string> cpp_inclusion_manager::
system(const std::string& /*name*/, cpp_facet_types ft,
    cpp_file_types flt, cpp_aspect_types at) const {

    std::list<std::string> r;

    if (at != cpp_aspect_types::versioned_key &&
        at != cpp_aspect_types::unversioned_key)
        return r;

    const bool is_header(flt == cpp_file_types::header);
    const bool is_implementation(flt == cpp_file_types::implementation);
    if (ft == cpp_facet_types::domain) {
        if (is_header) {
            r.push_back(iosfwd);
            r.push_back(algorithm);
        } else if (is_implementation)
            r.push_back(ostream);
    }

    if (is_header && ft == cpp_facet_types::hash)
        r.push_back(functional);

    if (ft == cpp_facet_types::io) {
        if (is_header)
            r.push_back(iosfwd);
        else if (ft == cpp_facet_types::io && is_implementation)
            r.push_back(ostream);
    }

    if (is_header && ft == cpp_facet_types::serialization &&
        !settings_.disable_xml_serialization())
        r.push_back(boost_nvp);

    return r;
}

std::list<std::string> cpp_inclusion_manager::
system(const sml::pod& pod, cpp_facet_types ft,
    cpp_file_types flt, cpp_aspect_types at) const {

    std::list<std::string> r;
    if (at != cpp_aspect_types::main)
        return r;

    const bool is_implementation(flt == cpp_file_types::implementation);
    const bool is_header(flt == cpp_file_types::header);
    if (ft == cpp_facet_types::domain) {
        if (is_header) {
            r.push_back(iosfwd);
            // FIXME: for some reason we had this if in formatter
            // if (!pod.properties().empty())
                r.push_back(algorithm);
        }

        if (is_implementation) {
            r.push_back(ostream);
            for(const auto p : pod.properties()) {
                if (p.type_name().type_name() == bool_type) {
                    r.push_back(state_saver);
                    break;
                }
            }
        }
    }

    if (is_header && ft == cpp_facet_types::hash)
        r.push_back(functional);

    if (ft == cpp_facet_types::database) {
        if (is_header) {
            r.push_back(vector_include);
            r.push_back(boost_optional_include);
            r.push_back(pqxx_connection_include);
        }

        if (is_implementation) {
            r.push_back(boost_format_include);
            r.push_back(pqxx_result_include);
            r.push_back(pqxx_transaction_include);
        }
    }

    if (ft == cpp_facet_types::io) {
        if (is_header)
            r.push_back(iosfwd);
        else if (is_implementation)
            r.push_back(ostream);
    }

    if (is_header && ft == cpp_facet_types::serialization &&
        !settings_.disable_xml_serialization())
        r.push_back(boost_nvp);

    return r;
}

std::string cpp_inclusion_manager::unversioned_dependency() const {
    sml::qualified_name qn;
    qn.type_name(unversioned_name);
    qn.external_package_path(model_.external_package_path());
    qn.model_name(model_.name());

    const auto d(cpp_facet_types::domain);
    const auto h(cpp_file_types::header);
    const auto rq(location_request_factory(d, h, qn));
    return location_manager_.relative_logical_path(rq).generic_string();
}

bool cpp_inclusion_manager::
has_versioned_dependency(const sml::pod& /*pod*/, cpp_facet_types ft,
    cpp_file_types flt) const {
    if (settings_.disable_versioning())
        return false;

    const bool is_implementation(flt == cpp_file_types::implementation);
    if (is_implementation && (ft == cpp_facet_types::hash ||
            ft == cpp_facet_types::io ||
            ft == cpp_facet_types::serialization ||
            ft == cpp_facet_types::database))
        return false;

    // FIXME: hacked for now
    if (is_implementation && ft == cpp_facet_types::domain &&
        (disable_io_ || settings_.use_integrated_io()))
        return false;

    // if (is_implementation && ft == cpp_facet_types::domain &&
    //     (disable_io_ || !use_integrated_io_))
    //     return false;

    const bool is_header(flt == cpp_file_types::header);
    if (is_header && (ft == cpp_facet_types::test_data ||
            ft == cpp_facet_types::database ||
            ft == cpp_facet_types::io))
        return false;

    return true;
}

std::string cpp_inclusion_manager::
versioned_dependency(cpp_facet_types ft, cpp_file_types flt) const {
    const bool is_implementation(flt == cpp_file_types::implementation);
    cpp_facet_types actual_facet(ft);
    if (is_implementation && ft == cpp_facet_types::domain)
        actual_facet = cpp_facet_types::io;

    sml::qualified_name qn;
    qn.type_name(versioned_name);
    qn.external_package_path(model_.external_package_path());
    qn.model_name(model_.name());

    const auto h(cpp_file_types::header);
    const auto rq(location_request_factory(actual_facet, h, qn));
    return location_manager_.relative_logical_path(rq).generic_string();
}

std::string cpp_inclusion_manager::
domain_header_dependency(const sml::qualified_name& name) const {
    const auto d(cpp_facet_types::domain);
    const auto h(cpp_file_types::header);
    const auto rq(location_request_factory(d, h, name));
    return location_manager_.relative_logical_path(rq).generic_string();
}

std::string cpp_inclusion_manager::header_dependency(
    const sml::qualified_name& name, cpp_facet_types facet_type) const {
    const auto h(cpp_file_types::header);
    const auto rq(location_request_factory(facet_type, h, name));
    return location_manager_.relative_logical_path(rq).generic_string();
}

std::list<std::string> cpp_inclusion_manager::
user(const sml::qualified_name& name, cpp_facet_types facet_type,
    cpp_file_types file_type, cpp_aspect_types aspect_type) const {

    if (aspect_type == cpp_aspect_types::includers) {
        const auto i(headers_for_facet_.find(facet_type));
        if (i != headers_for_facet_.end())
            return i->second;
    }

    typedef std::list<std::string> return_type;
    const bool is_header(file_type == cpp_file_types::header);
    const bool is_domain(facet_type == cpp_facet_types::domain);
    const bool is_versioned(aspect_type == cpp_aspect_types::versioned_key);

    std::list<std::string> r;
    if (is_versioned && is_header && is_domain)
        r.push_back(unversioned_dependency());

    if (is_header && !is_domain)
        r.push_back(domain_header_dependency(name));

    if (is_header && facet_type == cpp_facet_types::hash)
        r.push_back(hash_combine);

    if (is_header && facet_type == cpp_facet_types::test_data) {
        r.push_back(generator_include);
        r.push_back(sequence_include);
    }

    if (file_type == cpp_file_types::implementation) {

        r.push_back(header_dependency(name, facet_type));
        if (is_domain)
            r.push_back(jsonify_include);
    }

    return r;
}

std::list<std::string>
cpp_inclusion_manager::user(const std::string& name, cpp_facet_types ft,
    cpp_file_types flt, cpp_aspect_types at) const {

    sml::qualified_name qn;
    qn.external_package_path(model_.external_package_path());
    qn.type_name(name);
    qn.model_name(model_.name());
    return user(qn, ft, flt, at);
}

std::list<std::string> cpp_inclusion_manager::
user(const sml::pod& pod, cpp_facet_types ft, cpp_file_types flt,
    cpp_aspect_types at) const {
    std::list<std::string> r(user(pod.name(), ft, flt, at));

    if (has_versioned_dependency(pod, ft, flt))
        r.push_back(versioned_dependency(ft, flt));

    // FIXME: handle properties etc.
    return r;
}

} } } }