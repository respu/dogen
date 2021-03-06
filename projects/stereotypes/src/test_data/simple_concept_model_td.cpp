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
#include "dogen/stereotypes/test_data/entity_td.hpp"
#include "dogen/stereotypes/test_data/simple_concept_model_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return position;
}

dogen::stereotypes::entity
create_dogen_stereotypes_entity(const unsigned int position) {
    return dogen::stereotypes::entity_generator::create(position);
}

}

namespace dogen {
namespace stereotypes {

simple_concept_model_generator::simple_concept_model_generator() : position_(0) { }

void simple_concept_model_generator::
populate(const unsigned int position, result_type& v) {
    v.prop_0(create_int(position + 0));
    v.prop_1(create_dogen_stereotypes_entity(position + 1));
    v.prop_10(create_int(position + 2));
}

simple_concept_model_generator::result_type
simple_concept_model_generator::create(const unsigned int position) {
    simple_concept_model r;
    simple_concept_model_generator::populate(position, r);
    return r;
}
simple_concept_model_generator::result_type*
simple_concept_model_generator::create_ptr(const unsigned int position) {
    simple_concept_model* p = new simple_concept_model();
    simple_concept_model_generator::populate(position, *p);
    return p;
}

simple_concept_model_generator::result_type
simple_concept_model_generator::operator()() {
    return create(position_++);
}

} }
