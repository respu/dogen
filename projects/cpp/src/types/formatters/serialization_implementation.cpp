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
#include <list>
#include <string>
#include <ostream>
#include <boost/throw_exception.hpp>
#include "dogen/cpp/types/generation_failure.hpp"
#include "dogen/cpp/types/formatters/namespace_helper.hpp"
#include "dogen/cpp/types/formatters/licence.hpp"
#include "dogen/cpp/types/formatters/includes.hpp"
#include "dogen/cpp/types/formatters/qualified_name.hpp"
#include "dogen/cpp/types/formatters/indenter.hpp"
#include "dogen/utility/log/logger.hpp"
#include "dogen/cpp/types/formatters/serialization_implementation.hpp"

using namespace dogen::utility::log;

namespace {

auto lg(logger_factory("serialization_implementation"));

const std::string boost_ns("boost");
const std::string serialization_ns("serialization");
const std::string missing_class_view_model(
    "Meta type is pod but class view model is empty");
const std::string enumeration_view_model_not_supported(
    "Enumerations do not have an implementation");

}

namespace dogen {
namespace cpp {
namespace formatters {

serialization_implementation::
serialization_implementation(std::ostream& stream,
    const bool disable_xml_serialization) :
    stream_(stream),
    utility_(stream_, indenter_),
    disable_xml_serialization_(disable_xml_serialization) { }

file_formatter::shared_ptr
serialization_implementation::create(std::ostream& stream,
    const bool disable_xml_serialization) {
    return file_formatter::shared_ptr(
        new serialization_implementation(stream, disable_xml_serialization));
}

void serialization_implementation::save_function(const class_view_model& vm) {
    const auto parents(vm.parents());
    const auto props(vm.properties());
    const bool has_properties(!props.empty());
    const bool has_parents(!parents.empty());
    const bool has_properties_or_parents(has_properties || has_parents);

    stream_ << indenter_ << "template<typename Archive>" << std::endl
            << indenter_ << "void save(Archive& "
            << (has_properties_or_parents ? "ar," : "/*ar*/,")
            << std::endl;

    {
        positive_indenter_scope s(indenter_);
        stream_ << indenter_ << "const ";
        qualified_name qualified_name(stream_);
        qualified_name.format(vm);

        stream_ << (has_properties_or_parents ? "& v," : "& /*v*/,")
                << std::endl
                << indenter_ << "const unsigned int /*version*/) ";

        utility_.open_scope();
        {
            for (const auto p : parents) {
                if (disable_xml_serialization_) {
                    stream_ << indenter_ << "ar << base_object<";
                    qualified_name.format(p);
                    stream_ << ">(v);" << std::endl;
                } else {
                    stream_ << indenter_ << "ar << make_nvp("
                            << utility_.quote(p.name()) << ", base_object<";
                    qualified_name.format(p);
                    stream_ << ">(v));" << std::endl;
                }
            }

            if (has_properties && has_parents)
                utility_.blank_line();

            for (const auto p : props) {
                std::ostringstream s;
                s << "v." << utility_.as_member_variable(p.name());
                if (p.type().is_filesystem_path())
                    s << ".generic_string()";

                if (disable_xml_serialization_) {
                    stream_ << indenter_ << "ar << " << s.str() << ";"
                            << std::endl;
                } else {
                    stream_ << indenter_ << "ar << make_nvp("
                            << utility_.quote(p.name())
                            << ", " << s.str() << ");"
                            << std::endl;
                }
            }
        }
    }
    utility_.close_scope();
    utility_.blank_line();
}

void serialization_implementation::load_function(const class_view_model& vm) {
    const auto parents(vm.parents());
    const auto props(vm.properties());
    const bool has_properties(!props.empty());
    const bool has_parents(!parents.empty());
    const bool has_properties_or_parents(has_properties || has_parents);

    stream_ << indenter_ << "template<typename Archive>" << std::endl
            << indenter_ << "void load(Archive& "
            << (has_properties_or_parents ? "ar," : "/*ar*/,")
            << std::endl;

    {
        positive_indenter_scope s(indenter_);
        stream_ << indenter_;
        qualified_name qualified_name(stream_);
        qualified_name.format(vm);

        stream_ << (has_properties_or_parents ? "& v," : "& /*v*/,")
                << std::endl
                << indenter_ << "const unsigned int /*version*/) ";

        utility_.open_scope();
        {
            for (const auto p : parents) {
                if (disable_xml_serialization_) {
                    stream_ << indenter_
                            << "ar >> "
                            << utility_.quote(p.name())
                            << ", base_object<";
                    qualified_name.format(p);
                    stream_ << ">(v);" << std::endl;
                } else {
                    stream_ << indenter_
                            << "ar >> make_nvp("
                            << utility_.quote(p.name())
                            << ", base_object<";
                    qualified_name.format(p);
                    stream_ << ">(v));" << std::endl;
                }
            }

            if (has_properties && has_parents)
                utility_.blank_line();

            for (const auto p : props) {
                std::ostringstream s;
                if (p.type().is_filesystem_path()) {
                    s << p.name() + "_tmp";
                    stream_ << indenter_ << "std::string " << s.str() << ";"
                            << std::endl;
                } else
                    s << "v." << utility_.as_member_variable(p.name());

                if (disable_xml_serialization_) {
                    stream_ << indenter_ << "ar >> " << s.str() << ";"
                            << std::endl;
                } else {
                    stream_ << indenter_ << "ar >> make_nvp("
                            << utility_.quote(p.name())
                            << ", " << s.str() << ");"
                            << std::endl;
                }

                if (p.type().is_filesystem_path()) {
                    stream_ << indenter_ << "v."
                            << utility_.as_member_variable(p.name())
                            << " = " << s.str() << ";"
                            << std::endl;
                }
            }
        }
    }
    utility_.close_scope();
    utility_.blank_line();
}

void serialization_implementation::
template_instantiations(const class_view_model& vm) {
    stream_ << indenter_ << "template void save("
            << "archive::polymorphic_oarchive& ar, const ";
    qualified_name qualified_name(stream_);
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl;
    stream_ << indenter_ << "template void load("
            << "archive::polymorphic_iarchive& ar, ";
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl;
    utility_.blank_line();

    stream_ << indenter_ << "template void save(archive::text_oarchive& ar, "
            << "const ";
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl;
    stream_ << indenter_ << "template void load(archive::text_iarchive& ar, ";
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl;
    utility_.blank_line();

    stream_ << indenter_ << "template void save(archive::binary_oarchive& ar, "
            << "const ";
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl;
    stream_ << indenter_ << "template void load(archive::binary_iarchive& ar, ";
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl;
    utility_.blank_line();

    if (!disable_xml_serialization_) {
        stream_ << indenter_ << "template void save(archive::xml_oarchive& ar, "
                << "const ";
        qualified_name.format(vm);
        stream_ << "& v, unsigned int version);" << std::endl;
        stream_ << indenter_ << "template void load(archive::xml_iarchive& ar, ";
        qualified_name.format(vm);
        stream_ << "& v, unsigned int version);" << std::endl;
        utility_.blank_line();
    }

    stream_ << "#ifdef __linux__" << std::endl
            << indenter_ << "template void save(eos::portable_oarchive& ar, "
            << "const ";
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl;
    stream_ << indenter_ << "template void load(eos::portable_iarchive& ar, ";
    qualified_name.format(vm);
    stream_ << "& v, unsigned int version);" << std::endl
            << "#endif" << std::endl;
    utility_.blank_line();
}

void serialization_implementation::format_class(const file_view_model& vm) {
    const auto o(vm.class_vm());
    if (!o) {
        BOOST_LOG_SEV(lg, error) << missing_class_view_model;
        BOOST_THROW_EXCEPTION(generation_failure(missing_class_view_model));
    }

    const view_models::class_view_model& cvm(*o);
    qualified_name qualified_name(stream_);
    if (cvm.is_parent() || !cvm.parents().empty()) {
        stream_ << indenter_ << "BOOST_CLASS_TRACKING(" << std::endl;
        {
            positive_indenter_scope s(indenter_);
            stream_ << indenter_;
            qualified_name.format(cvm);
            stream_ << "," << std::endl;
            stream_ << indenter_ << "boost::serialization"
                    << "::track_selectively)"
                    << std::endl;
        }
        utility_.blank_line();
    }

    {
        std::list<std::string> ns { boost_ns, serialization_ns };
        namespace_helper nsh(stream_, ns);
        utility_.blank_line();
        save_function(cvm);
        load_function(cvm);
    }
    utility_.blank_line(2);

    {
        std::list<std::string> ns { boost_ns, serialization_ns };
        namespace_helper nsh(stream_, ns);
        utility_.blank_line();
        template_instantiations(cvm);
    }
}

void serialization_implementation::
format_enumeration(const file_view_model&) {
    BOOST_LOG_SEV(lg, error) << enumeration_view_model_not_supported;
    BOOST_THROW_EXCEPTION(generation_failure(enumeration_view_model_not_supported));
}

void serialization_implementation::format(const file_view_model& vm) {
    licence licence(stream_);
    licence.format();

    includes includes(stream_);
    includes.format(vm);

    // FIXME: massive hack for EOS workaround
    stream_ << "#ifdef __linux__" << std::endl
            << "#include \"eos/portable_iarchive.hpp\"" << std::endl
            << "#include \"eos/portable_oarchive.hpp\"" << std::endl
            << "#endif" << std::endl;
    utility_.blank_line();

    if (vm.meta_type() == sml::meta_types::enumeration)
        format_enumeration(vm);
    else if (vm.meta_type() == sml::meta_types::pod)
        format_class(vm);
}

} } }