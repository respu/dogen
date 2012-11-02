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
#ifndef DOGEN_STD_MODEL_DOMAIN_BASE_HPP
#define DOGEN_STD_MODEL_DOMAIN_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include <string>
#include <vector>
#include "dogen/std_model/domain/versioned_key.hpp"
#include "dogen/std_model/serialization/base_fwd_ser.hpp"

namespace dogen {
namespace std_model {

class base {
public:
    base() = default;
    base(const base&) = default;
    base(base&&) = default;

    virtual ~base() noexcept = 0;

public:
    base(
        const std::vector<std::string>& prop_0,
        const dogen::std_model::versioned_key& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const base& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, base& v, unsigned int version);

public:
    virtual void to_stream(std::ostream& s) const;

public:
    std::vector<std::string> prop_0() const {
        return prop_0_;
    }

    void prop_0(const std::vector<std::string>& v) {
        prop_0_ = v;
    }

    dogen::std_model::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(const dogen::std_model::versioned_key& v) {
        versioned_key_ = v;
    }

protected:
    bool operator==(const base& rhs) const;
    bool operator!=(const base& rhs) const {
        return !this->operator==(rhs);
    }

public:
    virtual bool equals(const base& other) const = 0;

protected:
    void swap(base& other) noexcept;

private:
    std::vector<std::string> prop_0_;
    dogen::std_model::versioned_key versioned_key_;
};

inline base::~base() noexcept { }

} }



#endif