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
#ifndef DOGEN_CPP_TYPES_FORMATTERS_CPP_QUALIFIED_NAME_HPP
#define DOGEN_CPP_TYPES_FORMATTERS_CPP_QUALIFIED_NAME_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <string>
#include "dogen/cpp/types/view_models/class_view_model.hpp"
#include "dogen/cpp/types/view_models/parent_view_model.hpp"
#include "dogen/cpp/types/view_models/enumeration_view_model.hpp"

namespace dogen {
namespace cpp {
namespace formatters {

class cpp_qualified_name {
public:
    typedef view_models::class_view_model class_view_model;
    typedef view_models::enumeration_view_model enumeration_view_model;
    typedef view_models::parent_view_model parent_view_model;

public:
    cpp_qualified_name() = delete;
    cpp_qualified_name(const cpp_qualified_name&) = default;
    ~cpp_qualified_name() = default;
    cpp_qualified_name(cpp_qualified_name&&) = default;
    cpp_qualified_name& operator=(const cpp_qualified_name&) = default;

public:
    explicit cpp_qualified_name(std::ostream& stream);

public:
    void format(const class_view_model& vm);
    void format(const enumeration_view_model& vm);
    void format(const parent_view_model& vm);

private:
    std::ostream& stream_;
};

} } }

#endif