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
#ifndef DOGEN_STEREOTYPES_SERIALIZATION_SIMPLE_CONCEPT_MODEL_SER_HPP
#define DOGEN_STEREOTYPES_SERIALIZATION_SIMPLE_CONCEPT_MODEL_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "dogen/stereotypes/types/simple_concept_model.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(dogen::stereotypes::simple_concept_model)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const dogen::stereotypes::simple_concept_model& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, dogen::stereotypes::simple_concept_model& v, unsigned int version);

} }

#endif
