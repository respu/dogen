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
#ifndef DOGEN_TRIVIAL_INHERITANCE_DOMAIN_PARENT_WITH_MEMBERS_HPP
#define DOGEN_TRIVIAL_INHERITANCE_DOMAIN_PARENT_WITH_MEMBERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "dogen/trivial_inheritance/domain/versioned_key.hpp"

namespace dogen {
namespace trivial_inheritance {

class parent_with_members_serializer;

class parent_with_members {
public:
    parent_with_members(const parent_with_members&) = default;
    parent_with_members(parent_with_members&&) = default;

public:
    parent_with_members();

public:
    parent_with_members(
        int prop_0,
        dogen::trivial_inheritance::versioned_key versioned_key);

public:
    friend class dogen::trivial_inheritance::parent_with_members_serializer;

public:
    virtual std::ostream& to_stream(std::ostream& stream) const;

public:
    int prop_0() const {
        return prop_0_;
    }

    void prop_0(int value) {
        prop_0_ = value;
    }

    dogen::trivial_inheritance::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(dogen::trivial_inheritance::versioned_key value) {
        versioned_key_ = value;
    }

public:
    bool operator==(const parent_with_members& rhs) const;

    bool operator!=(const parent_with_members rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(parent_with_members& other);
    parent_with_members& operator=(parent_with_members other);

private:
    int prop_0_;
    dogen::trivial_inheritance::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::trivial_inheritance::parent_with_members& lhs,
    dogen::trivial_inheritance::parent_with_members& rhs) {
    lhs.swap(rhs);
}

}

#endif