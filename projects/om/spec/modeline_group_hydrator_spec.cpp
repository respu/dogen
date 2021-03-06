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
#include "dogen/utility/test/canned_tests.hpp"
#include "dogen/utility/filesystem/path.hpp"
#include "dogen/utility/io/list_io.hpp"
#include "dogen/utility/io/unordered_map_io.hpp"
#include "dogen/om/types/all.hpp"
#include "dogen/om/io/all_io.hpp"
#include "dogen/om/test_data/all_td.hpp"

namespace {

const std::string empty;
const std::string test_module("om");
const std::string test_suite("modeline_group_hydrator_spec");

const std::string modeline_groups_dir("modeline_groups");

}

using namespace dogen::om;
using namespace dogen::utility::test;

BOOST_AUTO_TEST_SUITE(modeline_group_hydrator)

BOOST_AUTO_TEST_CASE(modeline_group_hydrator_loads_expected_templates_from_data_directory) {
    SETUP_TEST_LOG_SOURCE("modeline_group_hydrator_loads_expected_templates_from_data_directory");

    using namespace dogen::utility::filesystem;
    const std::list<boost::filesystem::path> d = {
        // executable_directory()
        data_files_directory() / modeline_groups_dir
    };

    dogen::om::modeline_group_hydrator f(d);
    const auto r(f.hydrate());

    BOOST_LOG_SEV(lg, debug) << "groups: " << r;
    BOOST_CHECK(!r.empty());

    for (const auto& groups : r) {
        BOOST_CHECK(!groups.first.empty());
        BOOST_CHECK(!groups.second.modelines().empty());
        for (const auto& modelines : groups.second.modelines()) {
            BOOST_CHECK(!modelines.first.empty());
            BOOST_CHECK(!modelines.second.fields().empty());

            // value  may be empty so nothing can be said about it.
            for (const auto& fields : modelines.second.fields())
                BOOST_CHECK(!fields.name().empty());
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
