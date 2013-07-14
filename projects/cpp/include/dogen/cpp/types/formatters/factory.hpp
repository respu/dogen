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
#ifndef DOGEN_CPP_TYPES_FORMATTERS_FACTORY_HPP
#define DOGEN_CPP_TYPES_FORMATTERS_FACTORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "dogen/config/types/cpp_settings.hpp"
#include "dogen/cpp/types/content_descriptor.hpp"
#include "dogen/cpp/types/formatters/file_formatter.hpp"

namespace dogen {
namespace cpp {
namespace formatters {

class factory {
public:
    factory() = delete;
    factory(const factory&) = default;
    ~factory() = default;
    factory(factory&&) = default;
    factory& operator=(const factory&) = default;

public:
    typedef file_formatter::shared_ptr result_type;

public:
    factory(const config::cpp_settings& settings);

private:
    result_type create_main_formatter(std::ostream& s,
        const content_descriptor& cd) const;

    result_type create_registrar_formatter(
        std::ostream& s, const content_descriptor& cd) const;

    result_type create_null_formatter(std::ostream& s) const;

public:
    result_type create(std::ostream& s, const content_descriptor& cd) const;

private:
    const config::cpp_settings settings_;
    const bool disable_io_;
    const bool disable_serialization_;
};

} } }

#endif
