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
#include <boost/variant/apply_visitor.hpp>
#include "dogen/boost_model/hash/class_derived_hash.hpp"
#include "dogen/boost_model/hash/class_e_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value)
{
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct boost_variant_int_double_visitor : public boost::static_visitor<> {
    boost_variant_int_double_visitor() : hash(0) {}
    void operator()(const int v) const {
        combine(hash, v);
    }

    void operator()(const double v) const {
        combine(hash, v);
    }

    mutable std::size_t hash;
};

inline std::size_t hash_boost_variant_int_double(const boost::variant<int, double>& v) {
    boost_variant_int_double_visitor vis;
    boost::apply_visitor(vis, v);
    return vis.hash;
}

struct boost_variant_int_dogen_boost_model_class_derived_double_visitor : public boost::static_visitor<> {
    boost_variant_int_dogen_boost_model_class_derived_double_visitor() : hash(0) {}
    void operator()(const int v) const {
        combine(hash, v);
    }

    void operator()(const dogen::boost_model::class_derived& v) const {
        combine(hash, v);
    }

    void operator()(const double v) const {
        combine(hash, v);
    }

    mutable std::size_t hash;
};

inline std::size_t hash_boost_variant_int_dogen_boost_model_class_derived_double(const boost::variant<int, dogen::boost_model::class_derived, double>& v) {
    boost_variant_int_dogen_boost_model_class_derived_double_visitor vis;
    boost::apply_visitor(vis, v);
    return vis.hash;
}

}

namespace dogen {
namespace boost_model {

std::size_t class_e_hasher::hash(const class_e&v) {
    std::size_t seed(0);

    combine(seed, hash_boost_variant_int_double(v.prop_0()));
    combine(seed, hash_boost_variant_int_dogen_boost_model_class_derived_double(v.prop_1()));

    return seed;
}

} }