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
#ifndef DOGEN_SML_TO_CPP_HASH_CONTEXT_HASH_HPP
#define DOGEN_SML_TO_CPP_HASH_CONTEXT_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "dogen/sml_to_cpp/types/context.hpp"

namespace dogen {
namespace sml_to_cpp {

struct context_hasher {
public:
    static std::size_t hash(const context& v);
};

} }

namespace std {

template<>
struct hash<dogen::sml_to_cpp::context> {
public:
    size_t operator()(const dogen::sml_to_cpp::context& v) const {
        return dogen::sml_to_cpp::context_hasher::hash(v);
    }
};

}
#endif
