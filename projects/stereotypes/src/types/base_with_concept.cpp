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
#include "dogen/stereotypes/types/base_with_concept.hpp"

namespace dogen {
namespace stereotypes {

base_with_concept::base_with_concept()
    : prop_0_(static_cast<int>(0)),
      prop_2_(static_cast<int>(0)) { }

base_with_concept::base_with_concept(
    const int prop_0,
    const int prop_2)
    : prop_0_(prop_0),
      prop_2_(prop_2) { }

void base_with_concept::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"dogen::stereotypes::base_with_concept\"" << ", "
      << "\"prop_0\": " << prop_0_ << ", "
      << "\"prop_2\": " << prop_2_
      << " }";
}

void base_with_concept::swap(base_with_concept& other) noexcept {
    using std::swap;
    swap(prop_0_, other.prop_0_);
    swap(prop_2_, other.prop_2_);
}

bool base_with_concept::compare(const base_with_concept& rhs) const {
    return prop_0_ == rhs.prop_0_ &&
        prop_2_ == rhs.prop_2_;
}

int base_with_concept::prop_0() const {
    return prop_0_;
}

void base_with_concept::prop_0(const int v) {
    prop_0_ = v;
}

int base_with_concept::prop_2() const {
    return prop_2_;
}

void base_with_concept::prop_2(const int v) {
    prop_2_ = v;
}

} }