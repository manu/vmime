//
// VMime library (http://www.vmime.org)
// Copyright (C) 2002-2012 Vincent Richard <vincent@vincent-richard.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Linking this library statically or dynamically with other modules is making
// a combined work based on this library.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//

#include "vmime/utility/inputStreamAdapter.hpp"


namespace vmime {
namespace utility {


inputStreamAdapter::inputStreamAdapter(std::istream& is)
	: m_stream(is)
{
}


bool inputStreamAdapter::eof() const
{
	return (m_stream.eof());
}


void inputStreamAdapter::reset()
{
	m_stream.exceptions(std::ios_base::badbit);
	m_stream.seekg(0, std::ios::beg);
	m_stream.clear();
}


stream::size_type inputStreamAdapter::read
	(value_type* const data, const size_type count)
{
	m_stream.exceptions(std::ios_base::badbit);
	m_stream.read(data, count);
	return (m_stream.gcount());
}


stream::size_type inputStreamAdapter::skip(const size_type count)
{
	m_stream.exceptions(std::ios_base::badbit);
	m_stream.ignore(count);
	return (m_stream.gcount());
}


stream::size_type inputStreamAdapter::getPosition() const
{
	return m_stream.tellg();
}


void inputStreamAdapter::seek(const size_type pos)
{
	m_stream.seekg(pos, std::ios_base::beg);
}


} // utility
} // vmime

