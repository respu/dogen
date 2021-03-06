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
#ifndef DOGEN_ENGINE_TYPES_WORKFLOW_HPP
#define DOGEN_ENGINE_TYPES_WORKFLOW_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <map>
#include <string>
#include <utility>
#include <functional>
#include <boost/optional.hpp>
#include <boost/filesystem/path.hpp>
#include "dogen/sml/types/model.hpp"
#include "dogen/config/types/settings.hpp"
#include "dogen/engine/types/backends/backend.hpp"
#include "dogen/engine/types/outputters/outputter.hpp"
#include "dogen/utility/serialization/archive_types.hpp"

namespace dogen {
namespace engine {

/**
 * @brief Core of Dogen. Implements the code generation workflow.
 *
 * The model which one intends to generate is known as the @e target
 * model. The code generator starts by reading in the target model and
 * all of its dependencies, of which there are two types:
 *
 * @li @e explicit: specified by the settings passed in; these are
 * models created by the user and any models that they, in turn,
 * depend on.
 *
 * @li @e implicit: these are added automatically. At present the only
 * implicit dependency is the primitives model, but its expected to be
 * extended further in the future.
 *
 * Collectively, all these models are referred to as the @e input
 * models. The input models are merged it into a single, unified SML
 * model, called the merged model, and all dependencies are resolved
 * and validated.
 *
 * The code generator then instantiates all backends requested by the
 * settings passed in. They use the merged model to generate source
 * code into a string. This is then outputted to the desired output
 * destination.
 */
class workflow {
public:
    workflow() = delete;
    workflow& operator=(const workflow&) = default;
    workflow(const workflow&) = default;

public:
    typedef std::function<std::ostream& ()> output_fn;

public:
    workflow(workflow&& rhs)
    : verbose_(std::move(rhs.verbose_)), settings_(std::move(rhs.settings_)) { }

    workflow(const config::settings& s);
    workflow(const config::settings& s, const output_fn& o);

private:
    /**
     * @brief Outputs the pair file name and contents to its output
     * destination.
     */
    void output(const outputters::outputter::value_type& o) const;

public: // public section for testing purposes only
    /**
     * @brief Returns true if the housekeeping of generated files is
     * required, false otherwise.
     */
    bool housekeeping_required() const;

    /**
     * @brief Execute the SML sub-workflow and return a generatable
     * model - or nothing, if no such model exists.
     */
    boost::optional<sml::model> make_generatable_model() const;

    /**
     * @brief Transforms the model into generated code, according to
     * the backend passed in.
     */
    void generate(backends::backend& b) const;

    /**
     * @brief Given a merged model, generates all of its
     * representations.
     */
    void generate(const sml::model& m) const;

public:
    /**
     * @brief Perform the entire code generation workflow.
     */
    void execute() const;

private:
    const bool verbose_;
    const config::settings settings_;
    const output_fn output_;
};

} }

#endif
