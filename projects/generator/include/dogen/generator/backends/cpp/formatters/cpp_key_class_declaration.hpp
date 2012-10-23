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
#ifndef DOGEN_GENERATOR_BACKENDS_CPP_FORMATTERS_CPP_KEY_CLASS_DECLARATION_HPP
#define DOGEN_GENERATOR_BACKENDS_CPP_FORMATTERS_CPP_KEY_CLASS_DECLARATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "dogen/generator/backends/cpp/formatters/cpp_class_declaration.hpp"
#include "dogen/generator/backends/cpp/view_models/class_view_model.hpp"

namespace dogen {
namespace generator {
namespace backends {
namespace cpp {
namespace formatters {

class cpp_key_class_declaration : public cpp_class_declaration {
public:
    typedef view_models::class_view_model class_view_model;

public:
    cpp_key_class_declaration() = delete;
    cpp_key_class_declaration(const cpp_key_class_declaration&) = default;
    cpp_key_class_declaration(cpp_key_class_declaration&&) = default;
    cpp_key_class_declaration&
    operator=(const cpp_key_class_declaration&) = default;

public:
    cpp_key_class_declaration(std::ostream& stream,
        const bool disable_complete_constructor, const bool is_versioned,
        const bool disable_io, const bool disable_serialization);
    virtual ~cpp_key_class_declaration() noexcept {}

private:
    void hand_crafted_constructors(const class_view_model& vm);
    void to_unversioned_key();

public:
    virtual void format(const class_view_model& vm) override;

private:
    const bool disable_complete_constructor_;
    const bool is_versioned_;
    const bool disable_io_;
};

} } } } }

#endif
