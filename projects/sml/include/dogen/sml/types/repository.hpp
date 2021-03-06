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
#ifndef DOGEN_SML_TYPES_REPOSITORY_HPP
#define DOGEN_SML_TYPES_REPOSITORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "dogen/sml/serialization/repository_fwd_ser.hpp"
#include "dogen/sml/types/abstract_object.hpp"

namespace dogen {
namespace sml {

/**
 * @brief Represents all objects of a certain type as a conceptual set.
 *
 * Acts very much like a collection, except with a more elaborate querying
 * ability. Objects of the appropriate type can be added or removed, and the
 * machinery behind the repository inserts them or deletes them from the
 * underlying storage (for example, a relational database).
 */
class repository final : public dogen::sml::abstract_object {
public:
    repository() = default;
    repository(const repository&) = default;
    repository(repository&&) = default;

    virtual ~repository() noexcept { }

public:
    repository(
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
    friend void boost::serialization::save(Archive& ar, const repository& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, repository& v, unsigned int version);

public:
    virtual void accept(const type_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(type_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const type_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(type_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    bool operator==(const repository& rhs) const;
    bool operator!=(const repository& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const dogen::sml::type& other) const override;

public:
    void swap(repository& other) noexcept;
    repository& operator=(repository other);

};

} }

namespace std {

template<>
inline void swap(
    dogen::sml::repository& lhs,
    dogen::sml::repository& rhs) {
    lhs.swap(rhs);
}

}

#endif
