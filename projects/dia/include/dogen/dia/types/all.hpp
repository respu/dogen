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
#include "dogen/dia/types/attribute.hpp"
#include "dogen/dia/types/boolean.hpp"
#include "dogen/dia/types/child_node.hpp"
#include "dogen/dia/types/color.hpp"
#include "dogen/dia/types/composite.hpp"
#include "dogen/dia/types/connection.hpp"
#include "dogen/dia/types/diagram.hpp"
#include "dogen/dia/types/diagram_data.hpp"
#include "dogen/dia/types/enum_parser.hpp"
#include "dogen/dia/types/enumeration.hpp"
#include "dogen/dia/types/font.hpp"
#include "dogen/dia/types/hydration_error.hpp"
#include "dogen/dia/types/hydrator.hpp"
#include "dogen/dia/types/integer.hpp"
#include "dogen/dia/types/layer.hpp"
#include "dogen/dia/types/object.hpp"
#include "dogen/dia/types/object_types.hpp"
#include "dogen/dia/types/point.hpp"
#include "dogen/dia/types/real.hpp"
#include "dogen/dia/types/rectangle.hpp"
#include "dogen/dia/types/stereotypes.hpp"
#include "dogen/dia/types/string.hpp"