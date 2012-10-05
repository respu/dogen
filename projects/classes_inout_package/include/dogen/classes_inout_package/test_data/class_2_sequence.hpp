/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda
 *
 * This file is distributed under the Kitanda Proprietary Software
 * Licence. See doc/LICENCE.TXT for details.
 *
 */
#ifndef DOGEN_CLASSES_INOUT_PACKAGE_TEST_DATA_CLASS_2_SEQUENCE_HPP
#define DOGEN_CLASSES_INOUT_PACKAGE_TEST_DATA_CLASS_2_SEQUENCE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/classes_inout_package/domain/class_2.hpp"
#include "dogen/utility/test_data/generator.hpp"
#include "dogen/utility/test_data/sequence.hpp"

namespace dogen {
namespace classes_inout_package {

namespace detail {

class class_2_generator {
public:
    typedef dogen::classes_inout_package::class_2 value_type;

public:
    value_type next_term(const unsigned int position);
    unsigned int length() const;
};

}

typedef dogen::utility::test_data::sequence<
    detail::class_2_generator> class_2_sequence;

} }

#endif