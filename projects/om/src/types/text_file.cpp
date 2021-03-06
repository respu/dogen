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
#include <ostream>
#include "dogen/om/io/code_generation_marker_io.hpp"
#include "dogen/om/io/licence_io.hpp"
#include "dogen/om/io/modeline_io.hpp"
#include "dogen/om/types/text_file.hpp"

namespace boost {

inline std::ostream& operator<<(std::ostream& s, const boost::optional<dogen::om::code_generation_marker>& v) {
    s << "{ " << "\"__type__\": " << "\"boost::optional\"" << ", ";

    if (v)
        s << "\"data\": " << *v;
    else
        s << "\"data\": ""\"<empty>\"";
    s << " }";
    return s;
}

}

namespace dogen {
namespace om {

text_file::text_file(text_file&& rhs)
    : full_path_(std::move(rhs.full_path_)),
      relative_path_(std::move(rhs.relative_path_)),
      modeline_(std::move(rhs.modeline_)),
      marker_(std::move(rhs.marker_)),
      licence_(std::move(rhs.licence_)) { }

text_file::text_file(
    const boost::filesystem::path& full_path,
    const boost::filesystem::path& relative_path,
    const dogen::om::modeline& modeline,
    const boost::optional<dogen::om::code_generation_marker>& marker,
    const dogen::om::licence& licence)
    : full_path_(full_path),
      relative_path_(relative_path),
      modeline_(modeline),
      marker_(marker),
      licence_(licence) { }

void text_file::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"dogen::om::text_file\"" << ", "
      << "\"full_path\": " << "\"" << full_path_.generic_string() << "\"" << ", "
      << "\"relative_path\": " << "\"" << relative_path_.generic_string() << "\"" << ", "
      << "\"modeline\": " << modeline_ << ", "
      << "\"marker\": " << marker_ << ", "
      << "\"licence\": " << licence_
      << " }";
}

void text_file::swap(text_file& other) noexcept {
    using std::swap;
    swap(full_path_, other.full_path_);
    swap(relative_path_, other.relative_path_);
    swap(modeline_, other.modeline_);
    swap(marker_, other.marker_);
    swap(licence_, other.licence_);
}

bool text_file::compare(const text_file& rhs) const {
    return full_path_ == rhs.full_path_ &&
        relative_path_ == rhs.relative_path_ &&
        modeline_ == rhs.modeline_ &&
        marker_ == rhs.marker_ &&
        licence_ == rhs.licence_;
}

const boost::filesystem::path& text_file::full_path() const {
    return full_path_;
}

boost::filesystem::path& text_file::full_path() {
    return full_path_;
}

void text_file::full_path(const boost::filesystem::path& v) {
    full_path_ = v;
}

void text_file::full_path(const boost::filesystem::path&& v) {
    full_path_ = std::move(v);
}

const boost::filesystem::path& text_file::relative_path() const {
    return relative_path_;
}

boost::filesystem::path& text_file::relative_path() {
    return relative_path_;
}

void text_file::relative_path(const boost::filesystem::path& v) {
    relative_path_ = v;
}

void text_file::relative_path(const boost::filesystem::path&& v) {
    relative_path_ = std::move(v);
}

const dogen::om::modeline& text_file::modeline() const {
    return modeline_;
}

dogen::om::modeline& text_file::modeline() {
    return modeline_;
}

void text_file::modeline(const dogen::om::modeline& v) {
    modeline_ = v;
}

void text_file::modeline(const dogen::om::modeline&& v) {
    modeline_ = std::move(v);
}

const boost::optional<dogen::om::code_generation_marker>& text_file::marker() const {
    return marker_;
}

boost::optional<dogen::om::code_generation_marker>& text_file::marker() {
    return marker_;
}

void text_file::marker(const boost::optional<dogen::om::code_generation_marker>& v) {
    marker_ = v;
}

void text_file::marker(const boost::optional<dogen::om::code_generation_marker>&& v) {
    marker_ = std::move(v);
}

const dogen::om::licence& text_file::licence() const {
    return licence_;
}

dogen::om::licence& text_file::licence() {
    return licence_;
}

void text_file::licence(const dogen::om::licence& v) {
    licence_ = v;
}

void text_file::licence(const dogen::om::licence&& v) {
    licence_ = std::move(v);
}

} }