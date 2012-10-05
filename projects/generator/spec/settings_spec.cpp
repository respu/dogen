/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda
 *
 * This file is distributed under the Kitanda Proprietary Software
 * Licence. See doc/LICENCE.TXT for details.
 *
 */
#include <sstream>
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include "dogen/utility/test/logging.hpp"
#include "dogen/generator/config/settings.hpp"
#include "dogen/generator/config/validator.hpp"
#include "dogen/generator/config/configuration_error.hpp"
#include "dogen/generator/test/mock_settings_factory.hpp"
#include "dogen/utility/test/exception_checkers.hpp"

namespace {

const std::string empty;
const boost::filesystem::path empty_dir;
const std::string test_module("generator");
const std::string test_suite("settings_spec");

const boost::filesystem::path target("some_target");
const boost::filesystem::path src_dir("src directory");
const boost::filesystem::path include_dir("include directory");
const boost::filesystem::path project_dir("proj directory");
const std::string epp("package::path");

const std::string missing_target("Mandatory parameter target is missing");
const std::string missing_source_include("You must supply source and include");
const std::string missing_project_dir("You must supply the project directory");
const std::string unexpected_source_include("Source and include directories");
const std::string unexpected_project_dir("Project directories cannot be");

dogen::generator::config::settings defaults() {
    return dogen::generator::test::mock_settings_factory::
        build_settings(target, src_dir, include_dir, epp);
}

dogen::generator::config::settings target_only() {
    return dogen::generator::test::mock_settings_factory::
        build_settings(target, empty_dir, empty_dir, empty);
}

dogen::generator::config::settings split_project(const bool split) {
    auto s(target_only());
    auto cpp(s.cpp());
    cpp.split_project(split);
    s.cpp(cpp);
    return s;
}

dogen::generator::config::settings
split_project(const bool split, const boost::filesystem::path& include,
    const boost::filesystem::path& src) {
    auto s(target_only());
    auto cpp(s.cpp());
    cpp.split_project(split);
    cpp.include_directory(include);
    cpp.source_directory(src);

    if (!split)
        cpp.project_directory(project_dir);
    s.cpp(cpp);
    return s;
}

dogen::generator::config::settings
split_project(const bool split, const boost::filesystem::path& proj) {
    auto s(target_only());
    auto cpp(s.cpp());
    cpp.split_project(split);
    cpp.project_directory(proj);

    if (split) {
        cpp.include_directory(include_dir);
        cpp.source_directory(src_dir);
    }
    s.cpp(cpp);
    return s;
}

}

using dogen::utility::test::contains_checker;
using dogen::generator::config::configuration_error;
using dogen::generator::config::validator;

BOOST_AUTO_TEST_SUITE(settings)

BOOST_AUTO_TEST_CASE(modeling_target_must_be_supplied) {
    SETUP_TEST_LOG_SOURCE("modeling_target_must_be_supplied");

    dogen::generator::config::settings s;
    BOOST_CHECK(s.modeling().target().empty());
    contains_checker<configuration_error> c(missing_target);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);

    validator::validate(defaults());
}

BOOST_AUTO_TEST_CASE(non_split_projects_require_project_directory) {
    SETUP_TEST_LOG_SOURCE("non_split_projects_require_project_directory");

    auto s(split_project(false));
    contains_checker<configuration_error> c(missing_project_dir);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);

    validator::validate(split_project(false, project_dir));
}

BOOST_AUTO_TEST_CASE(non_split_projects_with_include_or_source_throw) {
    SETUP_TEST_LOG_SOURCE("non_split_projects_with_include_or_source_throw");

    auto s(split_project(false, include_dir, src_dir));
    contains_checker<configuration_error> c(unexpected_source_include);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);

    s = split_project(false, include_dir, empty_dir);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);

    s = split_project(false, empty_dir, src_dir);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);
}

BOOST_AUTO_TEST_CASE(split_projects_require_source_and_include_directories) {
    SETUP_TEST_LOG_SOURCE("split_projects_require_source_and_include_directories");

    auto s(split_project(true));
    contains_checker<configuration_error> c(missing_source_include);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);

    s = split_project(true, include_dir, empty_dir);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);

    s = split_project(true, empty_dir, src_dir);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);

    validator::validate(split_project(true, include_dir, src_dir));
}

BOOST_AUTO_TEST_CASE(split_projects_with_project_directory_throws) {
    SETUP_TEST_LOG_SOURCE("split_projects_with_project_directory_throws");

    const auto s(split_project(true, project_dir));
    contains_checker<configuration_error> c(unexpected_project_dir);
    BOOST_CHECK_EXCEPTION(validator::validate(s), configuration_error, c);
}

BOOST_AUTO_TEST_SUITE_END()