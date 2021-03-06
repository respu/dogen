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
#include "dogen/engine/types/backends/backend.hpp"
#include "dogen/engine/types/backends/cpp_backend.hpp"
#include "dogen/engine/types/backends/factory.hpp"
#include "dogen/engine/types/engine.hpp"
#include "dogen/engine/types/generation_failure.hpp"
#include "dogen/engine/types/housekeeper.hpp"
#include "dogen/engine/types/outputters/factory.hpp"
#include "dogen/engine/types/outputters/file_outputter.hpp"
#include "dogen/engine/types/outputters/outputter.hpp"
#include "dogen/engine/types/outputters/stream_outputter.hpp"
#include "dogen/engine/types/persister.hpp"
#include "dogen/engine/types/provider.hpp"
#include "dogen/engine/types/provider_interface.hpp"
#include "dogen/engine/types/workflow.hpp"
