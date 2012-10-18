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
#include "dogen/generator/backends/cpp/formatters/cpp_qualified_name.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_class_declaration.hpp"

namespace dogen {
namespace generator {
namespace backends {
namespace cpp {
namespace formatters {

cpp_class_declaration::cpp_class_declaration(std::ostream& stream)
    : stream_(stream), utility_(stream_, indenter_) { }

void cpp_class_declaration::open_class(const class_view_model& vm) {
    stream_ << indenter_ << "class " << vm.name();

    const auto parents(vm.parents());
    if (!parents.empty()) {
        stream_ << " :";

        if (parents.size() == 1) {
            stream_ << " public " << parents.front().name();
        } else {
            bool is_first(true);
            cpp_positive_indenter_scope s(indenter_);
            for (const auto p : vm.parents()) {
                stream_ << (is_first ? "" : ",") << std::endl << indenter_;
                stream_ << " public " << p.name();
                is_first = false;
            }
        }
    }
    stream_ << " {" << std::endl;
}

void cpp_class_declaration::close_class() {
    stream_ << indenter_ << "};" << std::endl;
}

void cpp_class_declaration::default_constructor(const class_view_model& vm) {
    if (!vm.has_primitive_properties())
        return;

    const auto props(vm.properties());
    utility_.public_access_specifier();
    stream_ << indenter_ << vm.name() << "();" << std::endl;
    utility_.blank_line();
}

void cpp_class_declaration::complete_constructor(const class_view_model& vm) {
    const auto props(vm.properties());
    if (props.empty())
        return;

    utility_.public_access_specifier();
    if (props.size() == 1) {
        const auto p(*props.begin());
        stream_ << indenter_ << "explicit " << vm.name() << "("
                << p.type() << " " << p.name() << ");" << std::endl;
        utility_.blank_line();
        return;
    }

    stream_ << indenter_ << vm.name() << "(";
    {
        cpp_positive_indenter_scope s(indenter_);
        bool is_first(true);
        for (const auto p : vm.properties()) {
            stream_ << (is_first ? "" : ",") << std::endl;
            stream_ << indenter_ << p.type() << " " << p.name();
            is_first = false;
        }
        stream_ << ");" << std::endl;
    }
    utility_.blank_line();
}

void cpp_class_declaration::destructor(const class_view_model& vm) {
    /*
     * need to define a destructor for parent and derived classes due
     * to strange clang errors: undefined reference to `vtable.
     */
    if (vm.is_parent() && !vm.parents().empty()) {
        stream_ << indenter_ << "virtual ~" << vm.name()
                << "() noexcept { }" << std::endl;
    }
}

void cpp_class_declaration::compiler_generated_constuctors(const class_view_model& vm) {
    utility_.public_access_specifier();

    if (!vm.has_primitive_properties())
        stream_ << indenter_ << vm.name() << "() = default;" << std::endl;

    stream_ << indenter_ << vm.name() << "(const " << vm.name()
            << "&) = default;" << std::endl
            << indenter_ << vm.name() << "(" << vm.name() << "&&) = default;"
            << std::endl;

    if (!vm.is_parent() && vm.parents().empty()) {
        stream_ << indenter_ << "~" << vm.name() << "() = default;"
                << std::endl;
    }

    if (vm.properties().empty()) {
        stream_ << indenter_ << vm.name() << "& operator=(const " << vm.name()
                << "&) = default;" << std::endl;
    }

    utility_.blank_line();
}

void cpp_class_declaration::friends(const class_view_model& vm) {
    utility_.public_access_specifier();
    stream_ << indenter_ << "friend class ";

    cpp_qualified_name qualified_name(stream_);
    qualified_name.format(vm);

    stream_ << "_serializer;" << std::endl;
    utility_.blank_line();
}

void cpp_class_declaration::getters_and_setters(const class_view_model& vm) {
    if (vm.properties().empty())
        return;

    utility_.public_access_specifier();
    for (const auto p : vm.properties()) {
        stream_ << indenter_ << p.type() << " " << p.name()
                << "() const ";
        utility_.open_scope();
        {
            cpp_positive_indenter_scope s(indenter_);
            stream_ << indenter_ << "return "
                    << utility_.as_member_variable(p.name()) << ";"
                    << std::endl;
        }
        utility_.close_scope();
        utility_.blank_line();

        stream_ << indenter_ << "void " << p.name() << "("
                << p.type() << " value) ";
        utility_.open_scope();
        {
            cpp_positive_indenter_scope s(indenter_);
            stream_ << indenter_ << utility_.as_member_variable(p.name())
                    << " = value;" << std::endl;
        }
        utility_.close_scope();
        utility_.blank_line();
    }
}

void cpp_class_declaration::member_variables(const class_view_model& vm) {
    if (vm.properties().empty())
        return;

    utility_.private_access_specifier();
    for (const auto p : vm.properties()) {
        stream_ << indenter_ << p.type() << " "
                << utility_.as_member_variable(p.name()) << ";"
                << std::endl;
    }
}

void cpp_class_declaration::equality(const class_view_model& vm) {
    utility_.public_access_specifier();
    stream_ << indenter_ << "bool operator==(const " << vm.name()
            <<  "& ";

    if (vm.properties().empty())
        stream_ << "/*rhs*/";
    else
        stream_ << "rhs";

    stream_ << ") const;" << std::endl;
    utility_.blank_line();

    stream_ << indenter_ << "bool operator!=(const " << vm.name()
            << " rhs) const ";
    utility_.open_scope();
    {
        cpp_positive_indenter_scope s(indenter_);
        stream_ << indenter_ << "return !this->operator==(rhs);" << std::endl;
    }
    utility_.close_scope();
    utility_.blank_line();
}

void cpp_class_declaration::to_stream(const class_view_model& vm) {
    if (!vm.is_parent() && vm.parents().empty())
        return;

    utility_.public_access_specifier();
    if (vm.is_parent()) {
        stream_ << indenter_
                << "virtual std::ostream& to_stream("
                << "std::ostream& stream) const;"
                << std::endl;
    } else {
        stream_ << indenter_
                << "std::ostream& to_stream(std::ostream& stream) "
                << "const override;"
                << std::endl;
    }
    utility_.blank_line();
}

void cpp_class_declaration::swap_and_assignment(const class_view_model& vm) {
    if (vm.properties().empty())
        return;

    utility_.public_access_specifier();
    stream_ << indenter_ << "void swap(" << vm.name() << "& other);"
            << std::endl
            << indenter_ << vm.name() << "& operator=(" << vm.name()
            << " other);"
            << std::endl;
    utility_.blank_line();
}

} } } } }
