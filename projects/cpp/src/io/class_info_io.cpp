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
#include <boost/algorithm/string.hpp>
#include <boost/io/ios_state.hpp>
#include <ostream>
#include "dogen/cpp/io/class_info_io.hpp"
#include "dogen/cpp/io/class_types_io.hpp"
#include "dogen/cpp/io/element_info_io.hpp"
#include "dogen/cpp/io/parent_info_io.hpp"
#include "dogen/cpp/io/property_info_io.hpp"
#include "dogen/sml/io/generation_types_io.hpp"

namespace dogen {
namespace cpp {

std::ostream& operator<<(std::ostream& s, const class_info& v) {
    v.to_stream(s);
    return(s);
}

} }