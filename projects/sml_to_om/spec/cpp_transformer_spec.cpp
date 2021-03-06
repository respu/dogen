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
#include <boost/test/unit_test.hpp>
#include "dogen/utility/test/logging.hpp"
#include "dogen/sml/io/model_io.hpp"
#include "dogen/sml/types/entity.hpp"
#include "dogen/sml/test/mock_model_factory.hpp"
#include "dogen/config/test/mock_settings_factory.hpp"
#include "dogen/sml_to_om/types/all.hpp"
#include "dogen/sml_to_om/io/all_io.hpp"
#include "dogen/sml_to_om/test_data/all_td.hpp"

using dogen::sml::test::mock_model_factory;
using dogen::config::test::mock_settings_factory;

namespace {

const std::string empty;
const std::string test_module("sml_to_om");
const std::string test_suite("cpp_transformer_spec");

}

using namespace dogen::sml_to_om;
using namespace dogen::utility::test;

BOOST_AUTO_TEST_SUITE(cpp_transformer)

BOOST_AUTO_TEST_CASE(transforming_empty_model_results_in_expected_cpp_project) {
    SETUP_TEST_LOG_SOURCE("transforming_empty_model_results_in_expected_cpp_project");

    const auto m(mock_model_factory::build_single_type_model());
    BOOST_LOG_SEV(lg, debug) << "model: " << m;
    BOOST_REQUIRE(m.objects().size() == 1);

    dogen::sml_to_om::context c;
    const auto ft(mock_settings_factory::build_facets());
    dogen::sml_to_om::cpp_transformer t(ft, m, c);
    t.from_type(*m.objects().begin()->second);
    BOOST_LOG_SEV(lg, debug) << "context: " << c;
}

BOOST_AUTO_TEST_SUITE_END()
