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
#include "dogen/om_formatters/types/result.hpp"

namespace dogen {
namespace om_formatters {

result::result(const std::list<dogen::om_formatters::formatted_file>& files)
    : files_(files) { }

void result::swap(result& other) noexcept {
    using std::swap;
    swap(files_, other.files_);
}

bool result::operator==(const result& rhs) const {
    return files_ == rhs.files_;
}

result& result::operator=(result other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::list<dogen::om_formatters::formatted_file>& result::files() const {
    return files_;
}

std::list<dogen::om_formatters::formatted_file>& result::files() {
    return files_;
}

void result::files(const std::list<dogen::om_formatters::formatted_file>& v) {
    files_ = v;
}

void result::files(const std::list<dogen::om_formatters::formatted_file>&& v) {
    files_ = std::move(v);
}

} }