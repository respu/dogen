/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda
 *
 * This file is distributed under the Kitanda Proprietary Software
 * Licence. See doc/LICENCE.TXT for details.
 *
 */
#ifndef DOGEN_PROTOTYPE_DOMAIN_UNVERSIONED_KEY_HPP
#define DOGEN_PROTOTYPE_DOMAIN_UNVERSIONED_KEY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>

namespace dogen {
namespace prototype {

class unversioned_key_serializer;

class unversioned_key {
public:
    unversioned_key(const unversioned_key&) = default;
    ~unversioned_key() = default;
    unversioned_key(unversioned_key&&) = default;

public:
    unversioned_key();

public:
    explicit unversioned_key(unsigned int id);

public:
    friend class unversioned_key_serializer;

public:
    void to_stream(std::ostream& stream) const;

public:
    unsigned int id() const {
        return id_;
    }

    void id(unsigned int value) {
        id_ = value;
    }

public:
    bool operator==(const unversioned_key& rhs) const {
        return id_ == rhs.id_;
    }

    bool operator!=(const unversioned_key rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(unversioned_key& other);
    unversioned_key& operator=(unversioned_key other);

private:
    unsigned int id_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::prototype::unversioned_key& lhs,
    dogen::prototype::unversioned_key& rhs) {
    lhs.swap(rhs);
}

}

#endif