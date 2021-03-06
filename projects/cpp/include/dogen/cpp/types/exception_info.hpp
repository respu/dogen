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
#ifndef DOGEN_CPP_TYPES_EXCEPTION_INFO_HPP
#define DOGEN_CPP_TYPES_EXCEPTION_INFO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include <list>
#include <string>
#include "dogen/cpp/serialization/exception_info_fwd_ser.hpp"
#include "dogen/cpp/types/entity.hpp"

namespace dogen {
namespace cpp {

/**
 * @brief Represents a C++ exception.
 */
class exception_info final : public dogen::cpp::entity {
public:
    exception_info() = default;
    exception_info(const exception_info&) = default;
    exception_info(exception_info&&) = default;

    virtual ~exception_info() noexcept { }

public:
    exception_info(
        const std::string& documentation,
        const std::string& name,
        const std::list<std::string>& namespaces);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const exception_info& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, exception_info& v, unsigned int version);

public:
    virtual void accept(const entity_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(entity_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const entity_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(entity_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    /**
     * @brief Name of the entity.
     *
     * Must be valid according to the rules for C++ names.
     */
    /**@{*/
    const std::string& name() const;
    std::string& name();
    void name(const std::string& v);
    void name(const std::string&& v);
    /**@}*/

    /**
     * @brief List of namespaces, in order, to which the exception belongs to.
     */
    /**@{*/
    const std::list<std::string>& namespaces() const;
    std::list<std::string>& namespaces();
    void namespaces(const std::list<std::string>& v);
    void namespaces(const std::list<std::string>&& v);
    /**@}*/

public:
    bool operator==(const exception_info& rhs) const;
    bool operator!=(const exception_info& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const dogen::cpp::entity& other) const override;

public:
    void swap(exception_info& other) noexcept;
    exception_info& operator=(exception_info other);

private:
    std::string name_;
    std::list<std::string> namespaces_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::cpp::exception_info& lhs,
    dogen::cpp::exception_info& rhs) {
    lhs.swap(rhs);
}

}

#endif
