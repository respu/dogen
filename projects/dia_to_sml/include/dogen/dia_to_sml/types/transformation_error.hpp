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
#ifndef DOGEN_DIA_TO_SML_TYPES_TRANSFORMATION_ERROR_HPP
#define DOGEN_DIA_TO_SML_TYPES_TRANSFORMATION_ERROR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/exception/info.hpp>
#include <string>

namespace dogen {
namespace dia_to_sml {

/**
 * @brief A fatal error has occurred while transforming a Dia model
 * into its SML representation.
 */
class transformation_error : public virtual std::exception, public virtual boost::exception {
public:
    transformation_error() = default;
    ~transformation_error() noexcept = default;

public:
    transformation_error(const std::string& message) : message_(message) { }

public:
    const char* what() const noexcept { return(message_.c_str()); }

private:
    const std::string message_;
};

} }

#endif
