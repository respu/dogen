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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. Seethe
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General PublicLicense
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#ifndef DOGEN_DMP_DOMAIN_PACKAGE1_FIRST_CLASS_HPP
#define DOGEN_DMP_DOMAIN_PACKAGE1_FIRST_CLASS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "dogen/dmp/domain/versioned_key.hpp"

namespace dogen {
namespace dmp {
namespace package1 {

class first_class_serializer;

class first_class {
public:
    first_class(const first_class&) = default;
    ~first_class() = default;
    first_class(first_class&&) = default;

public:
    first_class();

public:
    first_class(
        int public_attribute,
        int private_attribute,
        dogen::dmp::versioned_key versioned_key);

public:
    friend class dogen::dmp::package1::first_class_serializer;

public:
    void to_stream(std::ostream& stream) const;

public:
    int public_attribute() const {
        return public_attribute_;
    }

    void public_attribute(int value) {
        public_attribute_ = value;
    }

    int private_attribute() const {
        return private_attribute_;
    }

    void private_attribute(int value) {
        private_attribute_ = value;
    }

    dogen::dmp::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(dogen::dmp::versioned_key value) {
        versioned_key_ = value;
    }

public:
    bool operator==(const first_class& rhs) const {
        return public_attribute_ == rhs.public_attribute_ &&
            private_attribute_ == rhs.private_attribute_ &&
            versioned_key_ == rhs.versioned_key_;
    }

    bool operator!=(const first_class rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(first_class& other);
    first_class& operator=(first_class other);

private:
    int public_attribute_;
    int private_attribute_;
    dogen::dmp::versioned_key versioned_key_;
};

} } }

namespace std {

template<>
inline void swap(
    dogen::dmp::package1::first_class& lhs,
    dogen::dmp::package1::first_class& rhs) {
    lhs.swap(rhs);
}

}

#endif