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
#include "dogen/sml/test_data/nested_qname_td.hpp"
#include "dogen/sml/test_data/property_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

std::pair<std::string, std::string>
create_std_pair_std_string_std_string(unsigned int position) {
    std::pair<std::string, std::string> r(
        create_std_string(position),
        create_std_string(position));
    return r;
}

std::vector<std::pair<std::string, std::string> > create_std_vector_std_pair_std_string_std_string_(unsigned int position) {
    std::vector<std::pair<std::string, std::string> > r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_std_pair_std_string_std_string(position + i));
    }
    return r;
}

dogen::sml::nested_qname
create_dogen_sml_nested_qname(const unsigned int position) {
    return dogen::sml::nested_qname_generator::create(position);
}

}

namespace dogen {
namespace sml {

property_generator::property_generator() : position_(0) { }

void property_generator::
populate(const unsigned int position, result_type& v) {
    v.documentation(create_std_string(position + 0));
    v.implementation_specific_parameters(create_std_vector_std_pair_std_string_std_string_(position + 1));
    v.name(create_std_string(position + 2));
    v.type(create_dogen_sml_nested_qname(position + 3));
    v.default_value(create_std_string(position + 4));
}

property_generator::result_type
property_generator::create(const unsigned int position) {
    property r;
    property_generator::populate(position, r);
    return r;
}
property_generator::result_type*
property_generator::create_ptr(const unsigned int position) {
    property* p = new property();
    property_generator::populate(position, *p);
    return p;
}

property_generator::result_type
property_generator::operator()() {
    return create(position_++);
}

} }
