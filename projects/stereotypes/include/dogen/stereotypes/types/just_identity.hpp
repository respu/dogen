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
#ifndef DOGEN_STEREOTYPES_TYPES_JUST_IDENTITY_HPP
#define DOGEN_STEREOTYPES_TYPES_JUST_IDENTITY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "dogen/stereotypes/serialization/just_identity_fwd_ser.hpp"

namespace dogen {
namespace stereotypes {

/**
 * @brief Type only has one property which is its identity.
 */
class just_identity final {
public:
    just_identity(const just_identity&) = default;
    just_identity(just_identity&&) = default;
    ~just_identity() = default;

public:
    just_identity();

public:
    explicit just_identity(const int prop_0);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const just_identity& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, just_identity& v, unsigned int version);

public:
    int prop_0() const;
    void prop_0(const int v);

public:
    bool operator==(const just_identity& rhs) const;
    bool operator!=(const just_identity& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(just_identity& other) noexcept;
    just_identity& operator=(just_identity other);

private:
    int prop_0_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::stereotypes::just_identity& lhs,
    dogen::stereotypes::just_identity& rhs) {
    lhs.swap(rhs);
}

}

#endif
