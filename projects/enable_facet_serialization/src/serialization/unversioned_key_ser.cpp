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
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "dogen/enable_facet_serialization/serialization/unversioned_key_ser.hpp"

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const dogen::enable_facet_serialization::unversioned_key& v,
    const unsigned int /*version*/) {
    ar << v.id_;
}

template<typename Archive>
void load(Archive& ar,
    dogen::enable_facet_serialization::unversioned_key& v,
    const unsigned int /*version*/) {
    ar >> v.id_;
}

} }

BOOST_CLASS_EXPORT_IMPLEMENT(dogen::enable_facet_serialization::unversioned_key)

namespace boost {
namespace serialization {

template void save(archive::text_oarchive& ar, const dogen::enable_facet_serialization::unversioned_key& v, unsigned int version);
template void load(archive::text_iarchive& ar, dogen::enable_facet_serialization::unversioned_key& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const dogen::enable_facet_serialization::unversioned_key& v, unsigned int version);
template void load(archive::binary_iarchive& ar, dogen::enable_facet_serialization::unversioned_key& v, unsigned int version);

} }