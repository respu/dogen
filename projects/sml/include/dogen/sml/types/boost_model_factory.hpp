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
#ifndef DOGEN_SML_TYPES_BOOST_MODEL_FACTORY_HPP
#define DOGEN_SML_TYPES_BOOST_MODEL_FACTORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <boost/shared_ptr.hpp>
#include "dogen/sml/types/abstract_object.hpp"
#include "dogen/sml/types/module.hpp"
#include "dogen/sml/types/value_object_types.hpp"
#include "dogen/sml/types/model.hpp"

namespace dogen {
namespace sml {

/**
 * @brief Generates the system model for the boost libraries.
 */
class boost_model_factory {
public:
    boost_model_factory() = delete;
    boost_model_factory(const boost_model_factory&) = delete;
    ~boost_model_factory() = delete;
    boost_model_factory(boost_model_factory&&) = delete;
    boost_model_factory& operator=(const boost_model_factory&) = delete;

private:
    /**
     * @brief Create a new module.
     */
    static module create_module(const std::string& name,
        const std::list<std::string>& module_path);

    /**
     * @brief Create a new value object.
     */
    static boost::shared_ptr<abstract_object>
    create_value_object(const std::string& name,
        const std::list<std::string>& module_path, value_object_types t);

public:
    /**
     * @brief Create the boost model.
     */
    static model create();
};

} }

#endif
