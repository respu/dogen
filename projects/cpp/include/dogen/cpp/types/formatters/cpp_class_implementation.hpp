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
#ifndef DOGEN_CPP_TYPES_FORMATTERS_CPP_CLASS_IMPLEMENTATION_HPP
#define DOGEN_CPP_TYPES_FORMATTERS_CPP_CLASS_IMPLEMENTATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
types/#pragma once
#endif

#include <iosfwd>
#include <string>
#include "dogen/cpp/types/view_models/class_view_model.hpp"
#include "dogen/cpp/types/formatters/cpp_indenter.hpp"
#include "dogen/cpp/types/formatters/cpp_utility.hpp"
#include "dogen/cpp/types/view_models/property_view_model.hpp"

namespace dogen {
namespace cpp {
namespace formatters {

class cpp_class_implementation {
public:
    typedef view_models::class_view_model class_view_model;
    typedef view_models::property_view_model property_view_model;

public:
    cpp_class_implementation() = default;
    cpp_class_implementation(const cpp_class_implementation&) = default;
    ~cpp_class_implementation() = default;
    cpp_class_implementation(cpp_class_implementation&&) = default;
    cpp_class_implementation&
    operator=(const cpp_class_implementation&) = default;

public:
    explicit cpp_class_implementation(std::ostream& stream);

protected:
    void default_constructor(const class_view_model& vm);
    void move_constructor(const class_view_model& vm);
    void complete_constructor(const class_view_model& vm);
    void to_stream(const class_view_model& vm);
    void swap(const class_view_model& vm);
    void equals_method(const class_view_model& vm);
    void equals_operator(const class_view_model& vm);
    void assignment_operator(const class_view_model& vm);
    void getters_and_setters(const class_view_model& vm);
    void non_pod_getters_and_setters(const std::string class_name,
        const property_view_model& vm);
    void pod_getters_and_setters(const std::string class_name,
        const property_view_model& vm);

public:
    virtual void format(const class_view_model& vm) = 0;

protected:
    std::ostream& stream_;
    cpp_indenter indenter_;
    cpp_utility utility_;
};

} } }

#endif