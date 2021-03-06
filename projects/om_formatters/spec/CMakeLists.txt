# -*- mode: cmake; tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#
set(om_formatters_spec_files "")
file(GLOB_RECURSE om_formatters_spec_files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(om_formatters_spec ${om_formatters_spec_files})
set(binary_name "dogen_om_formatters_spec")
set_target_properties(om_formatters_spec PROPERTIES OUTPUT_NAME ${binary_name})

target_link_libraries(om_formatters_spec
    om
    om_formatters
    utility
    ${LIBXML2_LIBRARIES}
    ${Boost_LIBRARIES}
    ${PQXX_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT})

set(om_formatters_spec_cmd ${stage_bin_dir}/${binary_name} ${boost_test_parameters})

add_custom_target(run_om_formatters_spec
    COMMAND ${om_formatters_spec_cmd}
    WORKING_DIRECTORY ${stage_bin_dir}
    DEPENDS om_formatters_spec)
add_dependencies(run_all_specs run_om_formatters_spec)

add_boost_tests(om_formatters ${om_formatters_spec_files})
install(TARGETS om_formatters_spec RUNTIME DESTINATION bin COMPONENT tests)
