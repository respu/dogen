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
#ifndef DOGEN_CPP_TYPES_PROJECT_HPP
#define DOGEN_CPP_TYPES_PROJECT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <boost/optional.hpp>
#include <list>
#include "dogen/cpp/serialization/project_fwd_ser.hpp"
#include "dogen/cpp/types/cmakelists_info.hpp"
#include "dogen/cpp/types/odb_options_info.hpp"
#include "dogen/cpp/types/source_file.hpp"

namespace dogen {
namespace cpp {

/**
 * @brief Represents a project composed of makefiles and C++ source code.
 */
class project final {
public:
    project() = default;
    project(const project&) = default;
    ~project() = default;

public:
    project(project&& rhs);

public:
    project(
        const std::list<dogen::cpp::source_file>& files,
        const dogen::cpp::odb_options_info& odb_options,
        const dogen::cpp::cmakelists_info& src_cmakelists,
        const boost::optional<dogen::cpp::cmakelists_info>& include_cmakelists);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const project& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, project& v, unsigned int version);

public:
    /**
     * @brief C++ include and source files.
     */
    /**@{*/
    const std::list<dogen::cpp::source_file>& files() const;
    std::list<dogen::cpp::source_file>& files();
    void files(const std::list<dogen::cpp::source_file>& v);
    void files(const std::list<dogen::cpp::source_file>&& v);
    /**@}*/

    /**
     * @brief The ODB options file.
     */
    /**@{*/
    const dogen::cpp::odb_options_info& odb_options() const;
    dogen::cpp::odb_options_info& odb_options();
    void odb_options(const dogen::cpp::odb_options_info& v);
    void odb_options(const dogen::cpp::odb_options_info&& v);
    /**@}*/

    /**
     * @brief The CMake makefile for the source directory.
     */
    /**@{*/
    const dogen::cpp::cmakelists_info& src_cmakelists() const;
    dogen::cpp::cmakelists_info& src_cmakelists();
    void src_cmakelists(const dogen::cpp::cmakelists_info& v);
    void src_cmakelists(const dogen::cpp::cmakelists_info&& v);
    /**@}*/

    /**
     * @brief The CMake makefile for the include directory.
     */
    /**@{*/
    const boost::optional<dogen::cpp::cmakelists_info>& include_cmakelists() const;
    boost::optional<dogen::cpp::cmakelists_info>& include_cmakelists();
    void include_cmakelists(const boost::optional<dogen::cpp::cmakelists_info>& v);
    void include_cmakelists(const boost::optional<dogen::cpp::cmakelists_info>&& v);
    /**@}*/

public:
    bool operator==(const project& rhs) const;
    bool operator!=(const project& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(project& other) noexcept;
    project& operator=(project other);

private:
    std::list<dogen::cpp::source_file> files_;
    dogen::cpp::odb_options_info odb_options_;
    dogen::cpp::cmakelists_info src_cmakelists_;
    boost::optional<dogen::cpp::cmakelists_info> include_cmakelists_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::cpp::project& lhs,
    dogen::cpp::project& rhs) {
    lhs.swap(rhs);
}

}

#endif
