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

#ifndef VMIME_MESSAGING_AUTHENTICATIONINFOS_HPP_INCLUDED
#define VMIME_MESSAGING_AUTHENTICATIONINFOS_HPP_INCLUDED


#include "types.hpp"


namespace vmime {
namespace messaging {


/** This class encapsulates user credentials.
  */

class authenticationInfos
{
public:

	authenticationInfos(const string& username, const string& password);
	authenticationInfos(const authenticationInfos& infos);

	/** Return the user account name.
	  *
	  * @return account name
	  */
	const string& getUsername() const;

	/** Return the user account password.
	  *
	  * @return account password
	  */
	const string& getPassword() const;

private:

	string m_username;
	string m_password;
};


} // messaging
} // vmime


#endif // VMIME_MESSAGING_AUTHENTICATIONINFOS_HPP_INCLUDED
