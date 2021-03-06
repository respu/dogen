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
#include "dogen/stereotypes/serialization/aggregate_root_ser.hpp"
#include "dogen/stereotypes/serialization/base_concept_model_ser.hpp"
#include "dogen/stereotypes/serialization/base_with_concept_ser.hpp"
#include "dogen/stereotypes/serialization/composite_identity_ser.hpp"
#include "dogen/stereotypes/serialization/composite_identity_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/composite_identity_ver_ser.hpp"
#include "dogen/stereotypes/serialization/composite_identity_ver_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/composite_identity_ver_versioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/entity_ser.hpp"
#include "dogen/stereotypes/serialization/fluent_ser.hpp"
#include "dogen/stereotypes/serialization/further_refined_ser.hpp"
#include "dogen/stereotypes/serialization/identity_and_other_ser.hpp"
#include "dogen/stereotypes/serialization/identity_and_other_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/identity_and_other_ver_ser.hpp"
#include "dogen/stereotypes/serialization/identity_and_other_ver_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/identity_and_other_ver_versioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/identity_pod_ser.hpp"
#include "dogen/stereotypes/serialization/identity_pod_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/identity_pod_versioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/immutable_four_ser.hpp"
#include "dogen/stereotypes/serialization/immutable_one_non_primitive_ser.hpp"
#include "dogen/stereotypes/serialization/immutable_one_primitive_ser.hpp"
#include "dogen/stereotypes/serialization/immutable_two_ser.hpp"
#include "dogen/stereotypes/serialization/immutable_zero_ser.hpp"
#include "dogen/stereotypes/serialization/just_identity_ser.hpp"
#include "dogen/stereotypes/serialization/just_identity_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/just_identity_ver_ser.hpp"
#include "dogen/stereotypes/serialization/just_identity_ver_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/just_identity_ver_versioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/multi_concept_model_ser.hpp"
#include "dogen/stereotypes/serialization/multiple_refinement_concept_model_ser.hpp"
#include "dogen/stereotypes/serialization/pkg1/keyed_in_package_ser.hpp"
#include "dogen/stereotypes/serialization/pkg1/keyed_in_package_unversioned_key_ser.hpp"
#include "dogen/stereotypes/serialization/refinement_concept_model_ser.hpp"
#include "dogen/stereotypes/serialization/registrar_ser.hpp"
#include "dogen/stereotypes/serialization/second_refinement_concept_model_ser.hpp"
#include "dogen/stereotypes/serialization/simple_concept_model_ser.hpp"
#include "dogen/stereotypes/serialization/some_type_ser.hpp"
#include "dogen/stereotypes/serialization/value_ser.hpp"
#include "dogen/stereotypes/serialization/versioned_ser.hpp"
