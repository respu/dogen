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
#ifndef DOGEN_CPP_TYPES_CPP_LOCATION_REQUEST_HPP
#define DOGEN_CPP_TYPES_CPP_LOCATION_REQUEST_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <list>
#include <string>
#include "dogen/config/types/cpp_facet_types.hpp"
#include "dogen/cpp/serialization/cpp_location_request_fwd_ser.hpp"
#include "dogen/cpp/types/cpp_aspect_types.hpp"
#include "dogen/cpp/types/cpp_file_types.hpp"

namespace dogen {
namespace cpp {

class cpp_location_request final {
public:
    cpp_location_request(const cpp_location_request&) = default;
    cpp_location_request(cpp_location_request&&) = default;
    ~cpp_location_request() = default;

public:
    cpp_location_request();

public:
    cpp_location_request(
        const dogen::config::cpp_facet_types& facet_type,
        const dogen::cpp::cpp_file_types& file_type,
        const dogen::cpp::cpp_aspect_types& aspect_type,
        const std::string& model_name,
        const std::list<std::string>& external_package_path,
        const std::list<std::string>& package_path,
        const std::string& file_name);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_location_request& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_location_request& v, unsigned int version);

public:
    dogen::config::cpp_facet_types facet_type() const;
    void facet_type(const dogen::config::cpp_facet_types& v);

    dogen::cpp::cpp_file_types file_type() const;
    void file_type(const dogen::cpp::cpp_file_types& v);

    dogen::cpp::cpp_aspect_types aspect_type() const;
    void aspect_type(const dogen::cpp::cpp_aspect_types& v);

    const std::string& model_name() const;
    std::string& model_name();
    void model_name(const std::string& v);
    void model_name(const std::string&& v);

    const std::list<std::string>& external_package_path() const;
    std::list<std::string>& external_package_path();
    void external_package_path(const std::list<std::string>& v);
    void external_package_path(const std::list<std::string>&& v);

    const std::list<std::string>& package_path() const;
    std::list<std::string>& package_path();
    void package_path(const std::list<std::string>& v);
    void package_path(const std::list<std::string>&& v);

    const std::string& file_name() const;
    std::string& file_name();
    void file_name(const std::string& v);
    void file_name(const std::string&& v);

public:
    bool operator==(const cpp_location_request& rhs) const;
    bool operator!=(const cpp_location_request& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(cpp_location_request& other) noexcept;
    cpp_location_request& operator=(cpp_location_request other);

private:
    dogen::config::cpp_facet_types facet_type_;
    dogen::cpp::cpp_file_types file_type_;
    dogen::cpp::cpp_aspect_types aspect_type_;
    std::string model_name_;
    std::list<std::string> external_package_path_;
    std::list<std::string> package_path_;
    std::string file_name_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::cpp::cpp_location_request& lhs,
    dogen::cpp::cpp_location_request& rhs) {
    lhs.swap(rhs);
}

}

#endif