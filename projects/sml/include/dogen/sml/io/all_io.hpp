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
#include "dogen/sml/io/boost_model_factory_io.hpp"
#include "dogen/sml/io/category_types_io.hpp"
#include "dogen/sml/io/enumeration_io.hpp"
#include "dogen/sml/io/enumerator_io.hpp"
#include "dogen/sml/io/exception_io.hpp"
#include "dogen/sml/io/generation_types_io.hpp"
#include "dogen/sml/io/identifier_parser_io.hpp"
#include "dogen/sml/io/merger_io.hpp"
#include "dogen/sml/io/meta_types_io.hpp"
#include "dogen/sml/io/model_io.hpp"
#include "dogen/sml/io/nested_qualified_name_builder_io.hpp"
#include "dogen/sml/io/nested_qualified_name_io.hpp"
#include "dogen/sml/io/node_io.hpp"
#include "dogen/sml/io/package_io.hpp"
#include "dogen/sml/io/pod_io.hpp"
#include "dogen/sml/io/pod_types_io.hpp"
#include "dogen/sml/io/primitive_io.hpp"
#include "dogen/sml/io/primitive_model_factory_io.hpp"
#include "dogen/sml/io/property_io.hpp"
#include "dogen/sml/io/qualified_name_io.hpp"
#include "dogen/sml/io/reference_io.hpp"
#include "dogen/sml/io/std_model_factory_io.hpp"