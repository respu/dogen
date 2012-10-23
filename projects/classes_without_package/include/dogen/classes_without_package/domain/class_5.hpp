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
#ifndef DOGEN_CLASSES_WITHOUT_PACKAGE_DOMAIN_CLASS_5_HPP
#define DOGEN_CLASSES_WITHOUT_PACKAGE_DOMAIN_CLASS_5_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "dogen/classes_without_package/domain/versioned_key.hpp"
#include "dogen/classes_without_package/serialization/class_5_fwd_ser.hpp"

namespace dogen {
namespace classes_without_package {

class class_5_serializer;

class class_5 final {
public:
    class_5() = default;
    class_5(const class_5&) = default;
    class_5(class_5&&) = default;
    ~class_5() = default;

public:
    explicit class_5(const dogen::classes_without_package::versioned_key& versioned_key);

public:
    friend class dogen::classes_without_package::class_5_serializer;

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const class_5& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, class_5& v, unsigned int version);

public:
    dogen::classes_without_package::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const dogen::classes_without_package::versioned_key& v) {
        versioned_key_ = v;
    }

public:
    bool operator==(const class_5& rhs) const;
    bool operator!=(const class_5& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(class_5& other) noexcept;
    class_5& operator=(class_5 other);

private:
    dogen::classes_without_package::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::classes_without_package::class_5& lhs,
    dogen::classes_without_package::class_5& rhs) {
    lhs.swap(rhs);
}

}

#endif
