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
#include "dogen/std_model/test_data/class_a_td.hpp"
#include "dogen/std_model/test_data/class_a_unversioned_key_td.hpp"
#include "dogen/std_model/test_data/class_a_versioned_key_td.hpp"
#include "dogen/std_model/test_data/pkg1/class_c_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return position;
}

dogen::std_model::class_a
create_dogen_std_model_class_a(const unsigned int position) {
    return dogen::std_model::class_a_generator::create(position);
}

std::vector<dogen::std_model::class_a> create_std_vector_dogen_std_model_class_a(unsigned int position) {
    std::vector<dogen::std_model::class_a> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_dogen_std_model_class_a(position + i));
    }
    return r;
}

dogen::std_model::class_a_unversioned_key
create_dogen_std_model_class_a_unversioned_key(const unsigned int position) {
    return dogen::std_model::class_a_unversioned_key_generator::create(position);
}

std::vector<dogen::std_model::class_a_unversioned_key> create_std_vector_dogen_std_model_class_a_unversioned_key(unsigned int position) {
    std::vector<dogen::std_model::class_a_unversioned_key> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_dogen_std_model_class_a_unversioned_key(position + i));
    }
    return r;
}

dogen::std_model::class_a_versioned_key
create_dogen_std_model_class_a_versioned_key(const unsigned int position) {
    return dogen::std_model::class_a_versioned_key_generator::create(position);
}

std::vector<dogen::std_model::class_a_versioned_key> create_std_vector_dogen_std_model_class_a_versioned_key(unsigned int position) {
    std::vector<dogen::std_model::class_a_versioned_key> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_dogen_std_model_class_a_versioned_key(position + i));
    }
    return r;
}

}

namespace dogen {
namespace std_model {
namespace pkg1 {

class_c_generator::class_c_generator() : position_(0) { }

void class_c_generator::
populate(const unsigned int position, result_type& v) {
    v.prop_0(create_int(position + 0));
    v.prop_1(create_std_vector_dogen_std_model_class_a(position + 1));
    v.prop_2(create_std_vector_dogen_std_model_class_a_unversioned_key(position + 2));
    v.prop_3(create_std_vector_dogen_std_model_class_a_versioned_key(position + 3));
}

class_c_generator::result_type
class_c_generator::create(const unsigned int position) {
    class_c r;
    class_c_generator::populate(position, r);
    return r;
}
class_c_generator::result_type*
class_c_generator::create_ptr(const unsigned int position) {
    class_c* p = new class_c();
    class_c_generator::populate(position, *p);
    return p;
}

class_c_generator::result_type
class_c_generator::operator()() {
    return create(position_++);
}

} } }
