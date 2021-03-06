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
#include "dogen/cpp/hash/class_info_hash.hpp"
#include "dogen/cpp/hash/enum_info_hash.hpp"
#include "dogen/cpp/hash/exception_info_hash.hpp"
#include "dogen/cpp/hash/namespace_info_hash.hpp"
#include "dogen/cpp/hash/registrar_info_hash.hpp"
#include "dogen/cpp/hash/visitor_info_hash.hpp"
#include "dogen/sml/hash/qname_hash.hpp"
#include "dogen/sml_to_cpp/hash/context_hash.hpp"
#include "dogen/sml_to_cpp/hash/relationships_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value)
{
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_std_unordered_map_dogen_sml_qname_dogen_cpp_class_info(const std::unordered_map<dogen::sml::qname, dogen::cpp::class_info>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_sml_qname_dogen_sml_to_cpp_relationships(const std::unordered_map<dogen::sml::qname, dogen::sml_to_cpp::relationships>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_sml_qname_dogen_cpp_exception_info(const std::unordered_map<dogen::sml::qname, dogen::cpp::exception_info>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_sml_qname_dogen_cpp_enum_info(const std::unordered_map<dogen::sml::qname, dogen::cpp::enum_info>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_sml_qname_dogen_cpp_registrar_info(const std::unordered_map<dogen::sml::qname, dogen::cpp::registrar_info>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_sml_qname_dogen_cpp_namespace_info(const std::unordered_map<dogen::sml::qname, dogen::cpp::namespace_info>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

inline std::size_t hash_std_unordered_map_dogen_sml_qname_dogen_cpp_visitor_info(const std::unordered_map<dogen::sml::qname, dogen::cpp::visitor_info>& v){
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i.first);
        combine(seed, i.second);
    }
    return seed;
}

}

namespace dogen {
namespace sml_to_cpp {

std::size_t context_hasher::hash(const context&v) {
    std::size_t seed(0);

    combine(seed, hash_std_unordered_map_dogen_sml_qname_dogen_cpp_class_info(v.classes()));
    combine(seed, hash_std_unordered_map_dogen_sml_qname_dogen_sml_to_cpp_relationships(v.relationships()));
    combine(seed, hash_std_unordered_map_dogen_sml_qname_dogen_cpp_exception_info(v.exceptions()));
    combine(seed, hash_std_unordered_map_dogen_sml_qname_dogen_cpp_enum_info(v.enumerations()));
    combine(seed, hash_std_unordered_map_dogen_sml_qname_dogen_cpp_registrar_info(v.registrars()));
    combine(seed, hash_std_unordered_map_dogen_sml_qname_dogen_cpp_namespace_info(v.namespaces()));
    combine(seed, hash_std_unordered_map_dogen_sml_qname_dogen_cpp_visitor_info(v.visitors()));

    return seed;
}

} }
