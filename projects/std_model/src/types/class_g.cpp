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
#include "dogen/std_model/types/class_g.hpp"

namespace dogen {
namespace std_model {

class_g::class_g(
    const std::unordered_map<dogen::std_model::class_a, std::vector<dogen::std_model::pkg1::class_c> >& prop_0,
    const std::unordered_map<dogen::std_model::pkg1::class_c, std::list<dogen::std_model::class_a> >& prop_1,
    const std::unordered_map<dogen::std_model::class_a_unversioned_key, dogen::std_model::class_a>& prop_2,
    const std::unordered_map<dogen::std_model::class_a_versioned_key, dogen::std_model::class_a>& prop_3)
    : prop_0_(prop_0),
      prop_1_(prop_1),
      prop_2_(prop_2),
      prop_3_(prop_3) { }

void class_g::swap(class_g& other) noexcept {
    using std::swap;
    swap(prop_0_, other.prop_0_);
    swap(prop_1_, other.prop_1_);
    swap(prop_2_, other.prop_2_);
    swap(prop_3_, other.prop_3_);
}

bool class_g::operator==(const class_g& rhs) const {
    return prop_0_ == rhs.prop_0_ &&
        prop_1_ == rhs.prop_1_ &&
        prop_2_ == rhs.prop_2_ &&
        prop_3_ == rhs.prop_3_;
}

class_g& class_g::operator=(class_g other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::unordered_map<dogen::std_model::class_a, std::vector<dogen::std_model::pkg1::class_c> >& class_g::prop_0() const {
    return prop_0_;
}

std::unordered_map<dogen::std_model::class_a, std::vector<dogen::std_model::pkg1::class_c> >& class_g::prop_0() {
    return prop_0_;
}

void class_g::prop_0(const std::unordered_map<dogen::std_model::class_a, std::vector<dogen::std_model::pkg1::class_c> >& v) {
    prop_0_ = v;
}

void class_g::prop_0(const std::unordered_map<dogen::std_model::class_a, std::vector<dogen::std_model::pkg1::class_c> >&& v) {
    prop_0_ = std::move(v);
}

const std::unordered_map<dogen::std_model::pkg1::class_c, std::list<dogen::std_model::class_a> >& class_g::prop_1() const {
    return prop_1_;
}

std::unordered_map<dogen::std_model::pkg1::class_c, std::list<dogen::std_model::class_a> >& class_g::prop_1() {
    return prop_1_;
}

void class_g::prop_1(const std::unordered_map<dogen::std_model::pkg1::class_c, std::list<dogen::std_model::class_a> >& v) {
    prop_1_ = v;
}

void class_g::prop_1(const std::unordered_map<dogen::std_model::pkg1::class_c, std::list<dogen::std_model::class_a> >&& v) {
    prop_1_ = std::move(v);
}

const std::unordered_map<dogen::std_model::class_a_unversioned_key, dogen::std_model::class_a>& class_g::prop_2() const {
    return prop_2_;
}

std::unordered_map<dogen::std_model::class_a_unversioned_key, dogen::std_model::class_a>& class_g::prop_2() {
    return prop_2_;
}

void class_g::prop_2(const std::unordered_map<dogen::std_model::class_a_unversioned_key, dogen::std_model::class_a>& v) {
    prop_2_ = v;
}

void class_g::prop_2(const std::unordered_map<dogen::std_model::class_a_unversioned_key, dogen::std_model::class_a>&& v) {
    prop_2_ = std::move(v);
}

const std::unordered_map<dogen::std_model::class_a_versioned_key, dogen::std_model::class_a>& class_g::prop_3() const {
    return prop_3_;
}

std::unordered_map<dogen::std_model::class_a_versioned_key, dogen::std_model::class_a>& class_g::prop_3() {
    return prop_3_;
}

void class_g::prop_3(const std::unordered_map<dogen::std_model::class_a_versioned_key, dogen::std_model::class_a>& v) {
    prop_3_ = v;
}

void class_g::prop_3(const std::unordered_map<dogen::std_model::class_a_versioned_key, dogen::std_model::class_a>&& v) {
    prop_3_ = std::move(v);
}

} }