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
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include "dogen/utility/log/logger.hpp"
#include "dogen/sml/io/meta_types_io.hpp"
#include "dogen/sml/io/pod_types_io.hpp"
#include "dogen/cpp/types/building_error.hpp"
#include "dogen/cpp/types/file_info_factory.hpp"

using namespace dogen::utility::log;

namespace {

auto lg(logger_factory("cpp.file_info_factory"));

const std::string empty;
const std::string dot(".");
const std::string separator("_");
const std::string visitor_postfix("_visitor");

}

namespace dogen {
namespace cpp {

file_info_factory::file_info_factory(const locator& l, includer& i)
    : locator_(l), includer_(i) { }

std::string file_info_factory::
to_header_guard_name(const boost::filesystem::path& rp) const {
    bool is_first(true);
    std::ostringstream stream;
    for (auto p : rp) {
        std::string s(p.string());
        boost::replace_all(s, dot, separator);
        boost::to_upper(s);
        stream << (is_first ? empty : separator) << s;
        is_first = false;
    }
    return stream.str();
}

location_request file_info_factory::
location_request_factory(const content_descriptor& cd) const {
    location_request r;
    r.facet_type(cd.facet_type());
    r.file_type(cd.file_type());
    r.aspect_type(cd.aspect_type());
    r.model_name(cd.name().model_name());
    r.package_path(cd.name().package_path());
    r.file_name(cd.name().type_name());
    r.external_package_path(cd.name().external_package_path());
    return r;
}

file_info file_info_factory::create(const content_descriptor& cd) const {
    file_info r;
    r.facet_type(cd.facet_type());
    r.file_type(cd.file_type());
    r.aspect_type(cd.aspect_type());
    r.category_type(cd.category_type());
    r.meta_type(cd.name().meta_type());

    const auto rq(location_request_factory(cd));
    r.file_path(locator_.absolute_path(rq));

    const auto rp(locator_.relative_logical_path(rq));
    r.relative_path(rp);
    if (cd.file_type() == file_types::header)
        r.header_guard(to_header_guard_name(rp));

    return r;
}

std::list<file_info> file_info_factory::create(const enumeration_info& ei,
    const std::list<content_descriptor>& cds) const {

    std::list<file_info> r;
    for (const auto cd : cds) {
        file_info fi(create(cd));
        fi.enumeration_info(ei);

        // FIXME: hack until we update includer
        sml::enumeration e;
        e.name(cd.name());
        const auto il(includer_.includes_for_enumeration(e,
                cd.facet_type(), cd.file_type(), cd.aspect_type()));

        fi.system_includes(il.system());
        fi.user_includes(il.user());
        r.push_back(fi);
    }
    return r;
}

std::list<file_info> file_info_factory::create(const exception_info& ei,
    const std::list<content_descriptor>& cds) const {

    std::list<file_info> r;
    for (const auto cd : cds) {
        file_info fi(create(cd));
        fi.exception_info(ei);

        // FIXME: hack until we update includer
        sml::exception e;
        e.name(cd.name());
        const auto il(includer_.includes_for_exception(e,
                cd.facet_type(), cd.file_type(), cd.aspect_type()));

        fi.system_includes(il.system());
        fi.user_includes(il.user());
        r.push_back(fi);
    }
    return r;
}

std::list<file_info> file_info_factory::create(const namespace_info& ni,
    const std::list<content_descriptor>& cds) const {

    std::list<file_info> r;
    for (const auto cd : cds) {
        file_info fi(create(cd));
        fi.namespace_info(ni);
        r.push_back(fi);
    }
    return r;
}

std::list<file_info> file_info_factory::create(const sml::pod& p,
    const class_info& ci, const std::list<content_descriptor>& cds) const {

    std::list<file_info> r;
    for (const auto cd : cds) {
        file_info fi(create(cd));

        if (cd.aspect_type() != aspect_types::forward_decls &&
            p.generation_type() == sml::generation_types::partial_generation)
            fi.aspect_type(aspect_types::null_aspect);

        fi.class_info(ci);

        const auto il(includer_.includes_for_pod(p,
                cd.facet_type(), cd.file_type(), cd.aspect_type()));
        fi.system_includes(il.system());
        fi.user_includes(il.user());
        r.push_back(fi);
    }
    return r;
}

std::list<file_info> file_info_factory::create_includer(
    const std::list<content_descriptor>& cds) const {

    std::list<file_info> r;
    for (const auto cd : cds) {
        file_info fi(create(cd));
        fi.aspect_type(aspect_types::includers);

        const auto il(includer_.includes_for_includer_files(cd.facet_type()));
        fi.system_includes(il.system());
        fi.user_includes(il.user());
        r.push_back(fi);
    }
    return r;
}

std::list<file_info>
file_info_factory::create_registrar(const registrar_info& ri,
    const std::list<content_descriptor>& cds) const {

    std::list<file_info> r;
    for (const auto cd : cds) {
        file_info fi(create(cd));
        fi.registrar_info(ri);

        const auto il(includer_.includes_for_registrar(cd.file_type()));
        fi.system_includes(il.system());
        fi.user_includes(il.user());
        r.push_back(fi);
    }
    return r;
}

std::list<file_info>
file_info_factory::create_visitor(const visitor_info& ri,
    const std::list<content_descriptor>& cds) const {

    std::list<file_info> r;
    for (const auto cd : cds) {
        // auto cd2(cd);
        // cd2.name().type_name(cd2.name().type_name() + visitor_postfix);

        file_info fi(create(cd));
        fi.visitor_info(ri);

        const auto il(includer_.includes_for_visitor(cd.name()));
        fi.system_includes(il.system());
        fi.user_includes(il.user());
        r.push_back(fi);
    }
    return r;
}

} }