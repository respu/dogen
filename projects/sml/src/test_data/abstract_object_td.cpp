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
#include "dogen/sml/test_data/abstract_object_td.hpp"
#include "dogen/sml/test_data/entity_td.hpp"
#include "dogen/sml/test_data/factory_td.hpp"
#include "dogen/sml/test_data/generation_types_td.hpp"
#include "dogen/sml/test_data/keyed_entity_td.hpp"
#include "dogen/sml/test_data/operation_td.hpp"
#include "dogen/sml/test_data/origin_types_td.hpp"
#include "dogen/sml/test_data/property_td.hpp"
#include "dogen/sml/test_data/qname_td.hpp"
#include "dogen/sml/test_data/repository_td.hpp"
#include "dogen/sml/test_data/service_td.hpp"
#include "dogen/sml/test_data/type_td.hpp"
#include "dogen/sml/test_data/value_object_td.hpp"

namespace {

dogen::sml::property
create_dogen_sml_property(const unsigned int position) {
    return dogen::sml::property_generator::create(position);
}

std::list<dogen::sml::property> create_std_list_dogen_sml_property(unsigned int position) {
    std::list<dogen::sml::property> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_dogen_sml_property(position + i));
    }
    return r;
}

dogen::sml::operation
create_dogen_sml_operation(const unsigned int position) {
    return dogen::sml::operation_generator::create(position);
}

std::list<dogen::sml::operation> create_std_list_dogen_sml_operation(unsigned int position) {
    std::list<dogen::sml::operation> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_dogen_sml_operation(position + i));
    }
    return r;
}

dogen::sml::qname
create_dogen_sml_qname(const unsigned int position) {
    return dogen::sml::qname_generator::create(position);
}

boost::optional<dogen::sml::qname>
create_boost_optional_dogen_sml_qname(unsigned int position) {
    boost::optional<dogen::sml::qname> r(
        create_dogen_sml_qname(position));
    return r;
}

std::list<dogen::sml::qname> create_std_list_dogen_sml_qname(unsigned int position) {
    std::list<dogen::sml::qname> r;
    for (unsigned int i(0); i < 10; ++i) {
        r.push_back(create_dogen_sml_qname(position + i));
    }
    return r;
}

bool create_bool(const unsigned int position) {
    return (position % 2) == 0;
}

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

}

namespace dogen {
namespace sml {


void abstract_object_generator::
populate(const unsigned int position, result_type& v) {
    dogen::sml::type_generator::populate(position, v);
    v.properties(create_std_list_dogen_sml_property(position + 0));
    v.operations(create_std_list_dogen_sml_operation(position + 1));
    v.parent_name(create_boost_optional_dogen_sml_qname(position + 2));
    v.original_parent_name(create_boost_optional_dogen_sml_qname(position + 3));
    v.leaves(create_std_list_dogen_sml_qname(position + 4));
    v.is_parent(create_bool(position + 5));
    v.number_of_type_arguments(create_unsigned_int(position + 6));
    v.is_visitable(create_bool(position + 7));
    v.is_immutable(create_bool(position + 8));
    v.is_versioned(create_bool(position + 9));
    v.is_comparable(create_bool(position + 10));
    v.is_fluent(create_bool(position + 11));
    v.modeled_concepts(create_std_list_dogen_sml_qname(position + 12));
}

abstract_object_generator::result_type*
abstract_object_generator::create_ptr(const unsigned int position) {
    if ((position % 5) == 0)
        return dogen::sml::factory_generator::create_ptr(position);
    if ((position % 5) == 1)
        return dogen::sml::repository_generator::create_ptr(position);
    if ((position % 5) == 2)
        return dogen::sml::value_object_generator::create_ptr(position);
    if ((position % 5) == 3)
        return dogen::sml::keyed_entity_generator::create_ptr(position);
    if ((position % 5) == 4)
        return dogen::sml::entity_generator::create_ptr(position);
    return dogen::sml::service_generator::create_ptr(position);
}


} }
