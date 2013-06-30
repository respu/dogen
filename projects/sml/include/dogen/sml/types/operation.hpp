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
#ifndef DOGEN_SML_TYPES_OPERATION_HPP
#define DOGEN_SML_TYPES_OPERATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <boost/optional.hpp>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include "dogen/sml/serialization/operation_fwd_ser.hpp"
#include "dogen/sml/types/nested_qname.hpp"

namespace dogen {
namespace sml {

/**
 * @brief Represents a method in an object.
 */
class operation final {
public:
    operation() = default;
    operation(const operation&) = default;
    ~operation() = default;

public:
    operation(operation&& rhs);

public:
    operation(
        const std::string& documentation,
        const std::vector<std::pair<std::string, std::string> >& implementation_specific_parameters,
        const std::string& name,
        const std::list<dogen::sml::nested_qname>& arguments,
        const boost::optional<dogen::sml::nested_qname>& return_type);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const operation& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, operation& v, unsigned int version);

public:
    /**
     * @brief Code comments.
     *
     * These are expected to follow the grammer of the comment processing tools
     * of the programming language in question, e.g. Doxygen for C++, JavaDoc
     * for Java, etc.
     */
    /**@{*/
    const std::string& documentation() const;
    std::string& documentation();
    void documentation(const std::string& v);
    void documentation(const std::string&& v);
    /**@}*/

    /**
     * @brief Associated generic parameters which may be opaque.
     */
    /**@{*/
    const std::vector<std::pair<std::string, std::string> >& implementation_specific_parameters() const;
    std::vector<std::pair<std::string, std::string> >& implementation_specific_parameters();
    void implementation_specific_parameters(const std::vector<std::pair<std::string, std::string> >& v);
    void implementation_specific_parameters(const std::vector<std::pair<std::string, std::string> >&& v);
    /**@}*/

    /**
     * @brief Name of the operation.
     */
    /**@{*/
    const std::string& name() const;
    std::string& name();
    void name(const std::string& v);
    void name(const std::string&& v);
    /**@}*/

    /**
     * @brief List of arguments that can be passed in to the operation.
     */
    /**@{*/
    const std::list<dogen::sml::nested_qname>& arguments() const;
    std::list<dogen::sml::nested_qname>& arguments();
    void arguments(const std::list<dogen::sml::nested_qname>& v);
    void arguments(const std::list<dogen::sml::nested_qname>&& v);
    /**@}*/

    /**
     * @brief Result of the operation, if any.
     */
    /**@{*/
    const boost::optional<dogen::sml::nested_qname>& return_type() const;
    boost::optional<dogen::sml::nested_qname>& return_type();
    void return_type(const boost::optional<dogen::sml::nested_qname>& v);
    void return_type(const boost::optional<dogen::sml::nested_qname>&& v);
    /**@}*/

public:
    bool operator==(const operation& rhs) const;
    bool operator!=(const operation& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(operation& other) noexcept;
    operation& operator=(operation other);

private:
    std::string documentation_;
    std::vector<std::pair<std::string, std::string> > implementation_specific_parameters_;
    std::string name_;
    std::list<dogen::sml::nested_qname> arguments_;
    boost::optional<dogen::sml::nested_qname> return_type_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::sml::operation& lhs,
    dogen::sml::operation& rhs) {
    lhs.swap(rhs);
}

}

#endif
