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
#include "dogen/trivial_inheritance/domain/parent_without_members.hpp"
#include "dogen/trivial_inheritance/io/versioned_key_io.hpp"

namespace dogen {
namespace trivial_inheritance {

parent_without_members::parent_without_members(dogen::trivial_inheritance::versioned_key versioned_key)
    : versioned_key_(versioned_key) { }

std::ostream& parent_without_members::to_stream(std::ostream& stream) const {
    stream << " { "
           << "\"__type__\": " << "\"parent_without_members\"" << ", "
           << "\"versioned_key\": " << versioned_key_
           << " }";
    return(stream);
}

void parent_without_members::swap(parent_without_members& other) {
    std::swap(versioned_key_, other.versioned_key_);
}

bool parent_without_members::operator==(const parent_without_members& rhs) const {
    return versioned_key_ == rhs.versioned_key_;
}

parent_without_members& parent_without_members::operator=(parent_without_members other) {
    std::swap(*this, other);
    return *this;
}

} }