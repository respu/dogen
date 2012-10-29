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
#ifndef DOGEN_GENERATOR_BACKENDS_CPP_FORMATTERS_CPP_ENUMERATION_DECLARATION_HPP
#define DOGEN_GENERATOR_BACKENDS_CPP_FORMATTERS_CPP_ENUMERATION_DECLARATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <string>
#include "dogen/generator/backends/cpp/view_models/enumeration_view_model.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_indenter.hpp"
#include "dogen/generator/backends/cpp/formatters/cpp_utility.hpp"

namespace dogen {
namespace generator {
namespace backends {
namespace cpp {
namespace formatters {

class cpp_enumeration_declaration {
public:
    typedef view_models::enumeration_view_model enumeration_view_model;

public:
    cpp_enumeration_declaration() = default;
    ~cpp_enumeration_declaration() = default;
    cpp_enumeration_declaration(const cpp_enumeration_declaration&) = default;
    cpp_enumeration_declaration(cpp_enumeration_declaration&&) = default;
    cpp_enumeration_declaration& operator=(
        const cpp_enumeration_declaration&) = default;

public:
    cpp_enumeration_declaration(std::ostream& stream);

public:
    void format(const enumeration_view_model& vm);

protected:
    std::ostream& stream_;
    cpp_indenter indenter_;
    cpp_utility utility_;
};

} } } } }

#endif