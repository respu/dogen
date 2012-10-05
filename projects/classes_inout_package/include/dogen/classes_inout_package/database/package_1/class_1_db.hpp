/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda
 *
 * This file is distributed under the Kitanda Proprietary Software
 * Licence. See doc/LICENCE.TXT for details.
 *
 */
#ifndef DOGEN_CLASSES_INOUT_PACKAGE_DATABASE_PACKAGE_1_CLASS_1_DB_HPP
#define DOGEN_CLASSES_INOUT_PACKAGE_DATABASE_PACKAGE_1_CLASS_1_DB_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/optional.hpp>
#include <pqxx/connection.hxx>
#include <vector>
#include "dogen/classes_inout_package/domain/package_1/class_1.hpp"

namespace dogen {
namespace classes_inout_package {
namespace package_1 {

class class_1_data_exchanger {
public:
    class_1_data_exchanger() = default;
    class_1_data_exchanger(const class_1_data_exchanger&) = delete;
    ~class_1_data_exchanger() = default;
    class_1_data_exchanger(class_1_data_exchanger&&) = delete;

private:
    std::string format_sql(const std::string& format_str,
        const boost::optional<versioned_key> id = boost::optional<versioned_key>());

    std::vector<dogen::classes_inout_package::package_1::class_1> load_internal(
        pqxx::connection& connection,
        const boost::optional<versioned_key> id =boost::optional<versioned_key>());

    void erase_internal(pqxx::connection& connection,
        const boost::optional<versioned_key> id = boost::optional<versioned_key>());

public:
    std::vector<dogen::classes_inout_package::package_1::class_1> load(
        pqxx::connection& connection,
        const boost::optional<versioned_key> id =boost::optional<versioned_key>());

    void save(
        pqxx::connection& connection,
        std::vector<dogen::classes_inout_package::package_1::class_1> values);

    void erase(pqxx::connection& connection);
    void erase(pqxx::connection& connection, versioned_key id);
};

} } }
#endif