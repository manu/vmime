//
// VMime library (http://vmime.sourceforge.net)
// Copyright (C) 2002-2004 Vincent Richard <vincent@vincent-richard.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef VMIME_MESSAGEID_HPP_INCLUDED
#define VMIME_MESSAGEID_HPP_INCLUDED


#include "base.hpp"
#include "component.hpp"


namespace vmime
{


/** Message identifier (basic type).
  */

class messageId : public component
{
public:

	messageId();
	messageId(const string& id);
	messageId(const messageId& mid);
	messageId(const string& left, const string& right);

public:

	/** Return the left part of the message identifier.
	  *
	  * @return left part of message identifier
	  */
	const string& getLeft() const;

	/** Set the left part of the message identifier.
	  *
	  * @param left left part of message identifier
	  */
	void setLeft(const string& left);

	/** Return the right part of the message identifier.
	  *
	  * @return right part of message identifier
	  */
	const string& getRight() const;

	/** Set the right part of the message identifier.
	  *
	  * @param right right part of message identifier
	  */
	void setRight(const string& right);


	messageId& operator=(const string& id);

	const bool operator==(const messageId& mid) const;
	const bool operator!=(const messageId& mid) const;

	/** Generate a random message identifier.
	  *
	  * @return randomly created message identifier
	  */
	static messageId generateId();

	/** Return the message identifier constructed by using
	  * the right part and the left part, separated by
	  * a '@' character.
	  *
	  * @return full message identifier
	  */
	const string getId() const;

	messageId* clone() const;
	void copyFrom(const component& other);
	messageId& operator=(const messageId& other);

private:

	string m_left;
	string m_right;

public:

	using component::parse;
	using component::generate;

	// Component parsing & assembling
	void parse(const string& buffer, const string::size_type position, const string::size_type end, string::size_type* newPosition = NULL);
	void generate(utility::outputStream& os, const string::size_type maxLineLength = lineLengthLimits::infinite, const string::size_type curLinePos = 0, string::size_type* newLinePos = NULL) const;
};


} // vmime


#endif // VMIME_MESSAGEID_HPP_INCLUDED
