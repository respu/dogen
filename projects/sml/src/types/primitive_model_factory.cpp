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
#include <memory>
#include "dogen/sml/types/primitive.hpp"
#include "dogen/sml/types/primitive_model_factory.hpp"

namespace {

const std::string model_name("primitive_model");

const std::string bool_name("bool");
const std::string char_name("char");
const std::string uchar_name("unsigned char");
const std::string int_name("int");
const std::string uint_name("unsigned int");
const std::string long_name("long");
const std::string ulong_name("unsigned long");
const std::string long_long_name("long long");
const std::string ulong_long_name("unsigned long long");
const std::string short_name("short");
const std::string ushort_name("unsigned short");
const std::string double_name("double");
const std::string float_name("float");

}

namespace dogen {
namespace sml {

primitive primitive_model_factory::create_primitive(const std::string& name) {
    qname q;
    q.simple_name(name);

    primitive r;
    r.name(q);
    r.generation_type(generation_types::no_generation);
    r.origin_type(origin_types::system);
    return r;
}

model primitive_model_factory::create() {
    qname qn;
    qn.model_name(model_name);

    model r;
    r.name(qn);
    r.origin_type(origin_types::system);

    const auto lambda([&](const std::string& name){
            const auto p(create_primitive(name));
            r.primitives().insert(std::make_pair(p.name(), p));
        });

    lambda(bool_name);
    lambda(char_name);
    lambda(uchar_name);
    lambda(int_name);
    lambda(uint_name);
    lambda(long_name);
    lambda(ulong_name);
    lambda(long_long_name);
    lambda(ulong_long_name);
    lambda(short_name);
    lambda(ushort_name);
    lambda(double_name);
    lambda(float_name);

    return r;
}

} }
