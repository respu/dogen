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
#ifndef DOGEN_SML_TYPES_ABSTRACT_OBJECT_HPP
#define DOGEN_SML_TYPES_ABSTRACT_OBJECT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <boost/optional.hpp>
#include <iosfwd>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include "dogen/sml/serialization/abstract_object_fwd_ser.hpp"
#include "dogen/sml/types/generation_types.hpp"
#include "dogen/sml/types/operation.hpp"
#include "dogen/sml/types/origin_types.hpp"
#include "dogen/sml/types/property.hpp"
#include "dogen/sml/types/qname.hpp"
#include "dogen/sml/types/type.hpp"

namespace dogen {
namespace sml {

/**
 * @brief Abstract representation of the object concept in the OOP paradigm.
 */
class abstract_object : public dogen::sml::type {
public:
    abstract_object(const abstract_object&) = default;

public:
    abstract_object();

    virtual ~abstract_object() noexcept = 0;

public:
    abstract_object(abstract_object&& rhs);

public:
    abstract_object(
        const std::string& documentation,
        const std::vector<std::pair<std::string, std::string> >& implementation_specific_parameters,
        const dogen::sml::qname& name,
        const dogen::sml::generation_types& generation_type,
        const dogen::sml::origin_types& origin_type,
        const std::list<dogen::sml::property>& properties,
        const std::list<dogen::sml::operation>& operations,
        const boost::optional<dogen::sml::qname>& parent_name,
        const boost::optional<dogen::sml::qname>& original_parent_name,
        const std::list<dogen::sml::qname>& leaves,
        const bool is_parent,
        const unsigned int number_of_type_arguments,
        const bool is_visitable,
        const bool is_immutable,
        const bool is_versioned,
        const bool is_comparable,
        const bool is_fluent,
        const std::list<dogen::sml::qname>& modeled_concepts);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const abstract_object& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, abstract_object& v, unsigned int version);

public:
    virtual void to_stream(std::ostream& s) const;

public:
    /**
     * @brief State of this entity.
     *
     * Does not include inherited attributes.
     */
    /**@{*/
    const std::list<dogen::sml::property>& properties() const;
    std::list<dogen::sml::property>& properties();
    void properties(const std::list<dogen::sml::property>& v);
    void properties(const std::list<dogen::sml::property>&& v);
    /**@}*/

    /**
     * @brief Operations (methods) that can be executed.
     */
    /**@{*/
    const std::list<dogen::sml::operation>& operations() const;
    std::list<dogen::sml::operation>& operations();
    void operations(const std::list<dogen::sml::operation>& v);
    void operations(const std::list<dogen::sml::operation>&& v);
    /**@}*/

    /**
     * @brief Qualified name for the object's parent, if it it has one.
     */
    /**@{*/
    const boost::optional<dogen::sml::qname>& parent_name() const;
    boost::optional<dogen::sml::qname>& parent_name();
    void parent_name(const boost::optional<dogen::sml::qname>& v);
    void parent_name(const boost::optional<dogen::sml::qname>&& v);
    /**@}*/

    /**
     * @brief Qualified name for the root of the inheritance hierarchy, if the object is part of one.
     */
    /**@{*/
    const boost::optional<dogen::sml::qname>& original_parent_name() const;
    boost::optional<dogen::sml::qname>& original_parent_name();
    void original_parent_name(const boost::optional<dogen::sml::qname>& v);
    void original_parent_name(const boost::optional<dogen::sml::qname>&& v);
    /**@}*/

    /**
     * @brief All concrete types which are indirectly or directly derived from this type.
     */
    /**@{*/
    const std::list<dogen::sml::qname>& leaves() const;
    std::list<dogen::sml::qname>& leaves();
    void leaves(const std::list<dogen::sml::qname>& v);
    void leaves(const std::list<dogen::sml::qname>&& v);
    /**@}*/

    /**
     * @brief True if this class is the parent of one or more classes, false otherwise.
     */
    /**@{*/
    bool is_parent() const;
    void is_parent(const bool v);
    /**@}*/

    /**
     * @brief How many type arguments does this type have
     */
    /**@{*/
    unsigned int number_of_type_arguments() const;
    void number_of_type_arguments(const unsigned int v);
    /**@}*/

    /**
     * @brief If true, a visitor is to be generated for this type and its descendants.
     *
     * Only applicable if is_parent is true.
     */
    /**@{*/
    bool is_visitable() const;
    void is_visitable(const bool v);
    /**@}*/

    /**
     * @brief If true, do not generate setters for the type's properties.
     */
    /**@{*/
    bool is_immutable() const;
    void is_immutable(const bool v);
    /**@}*/

    /**
     * @brief If true, add a version property to the type.
     */
    /**@{*/
    bool is_versioned() const;
    void is_versioned(const bool v);
    /**@}*/

    /**
     * @brief If true, generates the less than operator.
     *
     * A type is only comparable if all of its properties are primitives or strings,
     * or other comparable model types.
     */
    /**@{*/
    bool is_comparable() const;
    void is_comparable(const bool v);
    /**@}*/

    /**
     * @brief If true, generate fluent setters.
     */
    /**@{*/
    bool is_fluent() const;
    void is_fluent(const bool v);
    /**@}*/

    /**
     * @brief List of concepts modeled by this object.
     */
    /**@{*/
    const std::list<dogen::sml::qname>& modeled_concepts() const;
    std::list<dogen::sml::qname>& modeled_concepts();
    void modeled_concepts(const std::list<dogen::sml::qname>& v);
    void modeled_concepts(const std::list<dogen::sml::qname>&& v);
    /**@}*/

protected:
    bool compare(const abstract_object& rhs) const;
public:
    virtual bool equals(const dogen::sml::type& other) const = 0;

protected:
    void swap(abstract_object& other) noexcept;

private:
    std::list<dogen::sml::property> properties_;
    std::list<dogen::sml::operation> operations_;
    boost::optional<dogen::sml::qname> parent_name_;
    boost::optional<dogen::sml::qname> original_parent_name_;
    std::list<dogen::sml::qname> leaves_;
    bool is_parent_;
    unsigned int number_of_type_arguments_;
    bool is_visitable_;
    bool is_immutable_;
    bool is_versioned_;
    bool is_comparable_;
    bool is_fluent_;
    std::list<dogen::sml::qname> modeled_concepts_;
};

inline abstract_object::~abstract_object() noexcept { }

inline bool operator==(const abstract_object& lhs, const abstract_object& rhs) {
    return lhs.equals(rhs);
}

} }



#endif
