/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
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
#include "dogen/utility/io/list_io.hpp"
#include "dogen/utility/test/logging.hpp"
#include "dogen/utility/test/exception_checkers.hpp"
#include "dogen/sml/types/qname.hpp"
#include "dogen/sml/io/qname_io.hpp"
#include "dogen/sml/types/model.hpp"
#include "dogen/sml/io/model_io.hpp"
#include "dogen/config/test/mock_settings_factory.hpp"
#include "dogen/sml/test/mock_model_factory.hpp"
#include "dogen/cpp/io/all_io.hpp"
#include "dogen/cpp/types/building_error.hpp"
#include "dogen/cpp/types/content_descriptor_factory.hpp"

using dogen::config::cpp_facet_types;

namespace {

const std::string test_module("cpp");
const std::string test_suite("content_descriptor_factory_spec");

}

using dogen::sml::test::mock_model_factory;
using dogen::utility::test::contains_checker;
using dogen::config::test::mock_settings_factory;

BOOST_AUTO_TEST_SUITE(content_descriptor_factory)

BOOST_AUTO_TEST_CASE(creating_content_descriptor_with_all_facets_enabled_produces_expected_results) {
    SETUP_TEST_LOG_SOURCE("creating_content_descriptor_with_all_facets_enabled_produces_expected_results");

    const auto qn(mock_model_factory::build_qname());
    BOOST_LOG_SEV(lg, debug) << "qname: " << qn;

    const auto ft(mock_settings_factory::build_facets());
    dogen::cpp::content_descriptor_factory f(ft);
    const auto cds(f.create(qn, dogen::cpp::content_types::enumeration));
    BOOST_LOG_SEV(lg, debug) << "content descriptors: " << cds;

    std::set<dogen::config::cpp_facet_types> found_facets;
    for (const auto& cd : cds) {
        found_facets.insert(cd.facet_type());
        BOOST_CHECK(cd.name() == qn);
    }
    BOOST_CHECK(found_facets == ft);
}

BOOST_AUTO_TEST_CASE(creating_content_descriptor_with_some_facets_enabled_produces_expected_results) {
    SETUP_TEST_LOG_SOURCE("creating_content_descriptor_with_some_facets_enabled_produces_expected_results");

    const auto qn(mock_model_factory::build_qname());
    BOOST_LOG_SEV(lg, debug) << "qname: " << qn;

    const auto ft(mock_settings_factory::build_facets(false));
    dogen::cpp::content_descriptor_factory f(ft);
    const auto cds(f.create(qn, dogen::cpp::content_types::enumeration));
    BOOST_LOG_SEV(lg, debug) << "content descriptors: " << cds;

    std::set<dogen::config::cpp_facet_types> found_facets;
    for (const auto& cd : cds) {
        found_facets.insert(cd.facet_type());
        BOOST_CHECK(cd.name() == qn);
    }
    BOOST_CHECK(found_facets == ft);
}

BOOST_AUTO_TEST_CASE(creating_content_descriptor_from_model_produces_expected_results) {
    SETUP_TEST_LOG_SOURCE("creating_content_descriptor_from_model_produces_expected_results");

    const auto m(mock_model_factory::build_single_type_model());
    BOOST_LOG_SEV(lg, debug) << "model: " << m;

    const auto ft(mock_settings_factory::build_facets());
    dogen::cpp::content_descriptor_factory f(ft);
    const auto cds(f.create(m));
    BOOST_LOG_SEV(lg, debug) << "content descriptors: " << cds;

    std::set<dogen::config::cpp_facet_types> found_facets;
    for (const auto& cd : cds) {
        found_facets.insert(cd.facet_type());
        BOOST_CHECK(cd.name().model_name() == m.name().model_name());
        BOOST_CHECK(cd.name().external_module_path()
            == m.name().external_module_path());
    }
    BOOST_CHECK(found_facets.size() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
