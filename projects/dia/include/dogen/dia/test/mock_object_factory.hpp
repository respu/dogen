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
#ifndef DOGEN_DIA_TEST_MOCK_OBJECT_FACTORY_HPP
#define DOGEN_DIA_TEST_MOCK_OBJECT_FACTORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <array>
#include "dogen/dia/types/object.hpp"

namespace dogen {
namespace dia {
namespace test {

/**
 * @brief Generates mock dia objects that are more realistic than the
 * test data objects.
 */
class mock_object_factory {
public:
    /**
     * @brief Given a number, returns a dia object ID.
     */
    static std::string to_oject_id(const unsigned int number);

    /**
     * @brief Generates a new UML class.
     *
     * @param number identifier used for object ID generation.
     */
    static object build_class(const unsigned int number = 0);

    /**
     * @brief Generates a new UML large package.
     *
     * @param number identifier used for object ID generation.
     */
    static object build_large_package(const unsigned int number = 0);

    /**
     * @brief Generates two UML classes and a generalisation between
     * the two.
     *
     * @param number identifier used for object ID generation.
     */
    static std::array<object, 3> build_generalization(unsigned int number = 0);

    /**
     * @brief Generates two UML classes and a generalisation between
     * the two, and places all objects inside a package.
     *
     * @param number identifier used for object ID generation.
     */
    static std::array<object, 4>
    build_generalization_inside_large_package(unsigned int number = 0);

    /**
     * @brief Generates two UML classes and an association between
     * the two.
     *
     * @param number identifier used for object ID generation.
     */
    static std::array<object, 3> build_association(unsigned int number = 0);

};

} } }

#endif