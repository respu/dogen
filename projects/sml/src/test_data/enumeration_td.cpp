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
#include <sstream>
#include "dogen/sml/test_data/enumeration_td.hpp"
#include "dogen/sml/test_data/enumerator_td.hpp"
#include "dogen/sml/test_data/generation_types_td.hpp"
#include "dogen/sml/test_data/qualified_name_td.hpp"

namespace {

dogen::sml::qualified_name
create_dogen_sml_qualified_name(const unsigned int position) {
    return dogen::sml::qualified_name_generator::create(position);
}

dogen::sml::generation_types
create_dogen_sml_generation_types(const unsigned int position) {
    return dogen::sml::generation_types_generator::create(position);
}

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

dogen::sml::enumerator
create_dogen_sml_enumerator(const unsigned int position) {
    return dogen::sml::enumerator_generator::create(position);
}

std::vector<dogen::sml::enumerator> create_std_vector_dogen_sml_enumerator(unsigned int position) {
    std::vector<dogen::sml::enumerator> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_dogen_sml_enumerator(position + i));
    }
    return r;
}

}

namespace dogen {
namespace sml {

enumeration_generator::enumeration_generator() : position_(0) { }

void enumeration_generator::
populate(const unsigned int position, result_type& v) {
    v.name(create_dogen_sml_qualified_name(position + 0));
    v.generation_type(create_dogen_sml_generation_types(position + 1));
    v.documentation(create_std_string(position + 2));
    v.enumerators(create_std_vector_dogen_sml_enumerator(position + 3));
}

enumeration_generator::result_type
enumeration_generator::create(const unsigned int position) {
    enumeration r;
    enumeration_generator::populate(position, r);
    return r;
}
enumeration_generator::result_type*
enumeration_generator::create_ptr(const unsigned int position) {
    enumeration* p = new enumeration();
    enumeration_generator::populate(position, *p);
    return p;
}

enumeration_generator::result_type
enumeration_generator::operator()() {
    return create(position_++);
}

} }