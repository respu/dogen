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
#include "dogen/sml/test_data/abstract_object_td.hpp"
#include "dogen/sml/test_data/factory_td.hpp"



namespace dogen {
namespace sml {

factory_generator::factory_generator() : position_(0) { }

void factory_generator::
populate(const unsigned int position, result_type& v) {
    dogen::sml::abstract_object_generator::populate(position, v);
}

factory_generator::result_type
factory_generator::create(const unsigned int position) {
    factory r;
    factory_generator::populate(position, r);
    return r;
}
factory_generator::result_type*
factory_generator::create_ptr(const unsigned int position) {
    factory* p = new factory();
    factory_generator::populate(position, *p);
    return p;
}

factory_generator::result_type
factory_generator::operator()() {
    return create(position_++);
}

} }
