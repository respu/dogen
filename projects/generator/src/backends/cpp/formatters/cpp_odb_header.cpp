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
#include <ostream>
#include <boost/throw_exception.hpp>
#include "dogen/generator/generation_failure.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_licence.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_header_guards.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_namespace.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_includes.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_namespace_helper.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_qualified_name.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_indenter.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_odb_header.hpp"
#include "dogen/utility/log/logger.hpp"

using namespace dogen::utility::log;

namespace {

auto lg(logger_factory("odb_header"));

const std::string std_ns("std");

const std::string missing_class_view_model(
    "Meta type is pod but class view model is empty");
const std::string missing_enumeration_view_model(
    "Meta type is enumeration but enumeration view model is empty");

}

namespace dogen {
namespace generator {
namespace backends {
namespace cpp {
namespace formatters {

odb_header::
odb_header(std::ostream& stream) :
    stream_(stream),
    utility_(stream_, indenter_) {
}

file_formatter::shared_ptr odb_header::create(std::ostream& stream) {
    return file_formatter::shared_ptr(new odb_header(stream));
}

void odb_header::format_enumeration(const file_view_model& vm) {
    const auto o(vm.enumeration_vm());
    if (!o) {
        BOOST_LOG_SEV(lg, error) << missing_enumeration_view_model;
        BOOST_THROW_EXCEPTION(
            generation_failure(missing_enumeration_view_model));
    }

    const auto evm(*o);
    {
        namespace_helper ns(stream_, evm.namespaces());
        utility_.blank_line();

        stream_ << indenter_ << "#ifdef ODB_COMPILER" << std::endl;
        utility_.blank_line();
        stream_ << indenter_ << "#endif" << std::endl;
        utility_.blank_line();
    }
    utility_.blank_line(2);
}

void odb_header::format_class(const file_view_model& vm) {
    const auto o(vm.class_vm());
    if (!o) {
        BOOST_LOG_SEV(lg, error) << missing_class_view_model;
        BOOST_THROW_EXCEPTION(generation_failure(missing_class_view_model));
    }

    const auto evm(*o);
    {
        namespace_helper ns(stream_, evm.namespaces());
        utility_.blank_line();

        stream_ << indenter_ << "#ifdef ODB_COMPILER" << std::endl;

        utility_.blank_line();
        stream_ << indenter_ << "#pragma db object(" << evm.name()
                << ")" << std::endl;

        utility_.blank_line();
        for (const auto p : evm.properties()) {
            stream_ << indenter_ << "#pragma db member("
                    << evm.name() << "::"
                    << utility_.as_member_variable(p.name())
                    << ") "
                    << p.name()
                    << std::endl;
        }
        utility_.blank_line();
        stream_ << indenter_ << "#endif" << std::endl;
        utility_.blank_line();
    }
    utility_.blank_line(2);
}

void odb_header::format(const file_view_model& vm) {
    licence licence(stream_);
    licence.format();

    header_guards guards(stream_);
    guards.format_start(vm.header_guard());
    stream_ << std::endl;

    cpp_includes includes(stream_);
    includes.format(vm);

    if (vm.meta_type() == sml::meta_types::pod)
        format_class(vm);
    if (vm.meta_type() == sml::meta_types::enumeration)
        format_enumeration(vm);

    guards.format_end();
}

} } } } }