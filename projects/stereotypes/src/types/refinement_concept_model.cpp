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
#include "dogen/stereotypes/types/refinement_concept_model.hpp"

namespace dogen {
namespace stereotypes {

refinement_concept_model::refinement_concept_model()
    : prop_0_(static_cast<int>(0)),
      prop_1_(static_cast<int>(0)) { }

refinement_concept_model::refinement_concept_model(
    const int prop_0,
    const int prop_1)
    : prop_0_(prop_0),
      prop_1_(prop_1) { }

void refinement_concept_model::swap(refinement_concept_model& other) noexcept {
    using std::swap;
    swap(prop_0_, other.prop_0_);
    swap(prop_1_, other.prop_1_);
}

bool refinement_concept_model::operator==(const refinement_concept_model& rhs) const {
    return prop_0_ == rhs.prop_0_ &&
        prop_1_ == rhs.prop_1_;
}

refinement_concept_model& refinement_concept_model::operator=(refinement_concept_model other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int refinement_concept_model::prop_0() const {
    return prop_0_;
}

void refinement_concept_model::prop_0(const int v) {
    prop_0_ = v;
}

int refinement_concept_model::prop_1() const {
    return prop_1_;
}

void refinement_concept_model::prop_1(const int v) {
    prop_1_ = v;
}

} }