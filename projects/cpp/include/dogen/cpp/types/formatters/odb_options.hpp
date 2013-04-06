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
#ifndef DOGEN_CPP_TYPES_FORMATTERS_ODB_OPTIONS_HPP
#define DOGEN_CPP_TYPES_FORMATTERS_ODB_OPTIONS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <string>
#include "dogen/cpp/types/formatters/indenter.hpp"
#include "dogen/cpp/types/view_models/odb_options_view_model.hpp"

namespace dogen {
namespace cpp {
namespace formatters {

class odb_options {
public:
    typedef view_models::odb_options_view_model odb_options_view_model;

public:
    odb_options() = delete;
    odb_options(const odb_options&) = default;
    ~odb_options() noexcept = default;
    odb_options(odb_options&&) = default;
    odb_options& operator=(const odb_options&) = default;

public:
    explicit odb_options(std::ostream& stream);

public:
    void format(const odb_options_view_model& vm);

private:
    std::ostream& stream_;
    indenter indenter_;
};

} } }

#endif