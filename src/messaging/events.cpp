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

#include "messaging/events.hpp"

#include <algorithm>


namespace vmime {
namespace messaging {
namespace events {


//
// messageCountEvent
//

messageCountEvent::messageCountEvent
	(class folder* folder, const Types type, const std::vector <int>& nums)
		: m_folder(folder), m_type(type)
{
	m_nums.resize(nums.size());
	std::copy(nums.begin(), nums.end(), m_nums.begin());
}


const folder* messageCountEvent::folder() const { return (const_cast <class folder*>(m_folder)); }
const messageCountEvent::Types messageCountEvent::type() const { return (m_type); }
const std::vector <int>& messageCountEvent::numbers() const { return (m_nums); }


void messageCountEvent::dispatch(messageCountListener* listener) const
{
	if (m_type == TYPE_ADDED)
		listener->messagesAdded(*this);
	else
		listener->messagesRemoved(*this);
}


//
// messageChangedEvent
//

messageChangedEvent::messageChangedEvent
	(class folder* folder, const Types type, const std::vector <int>& nums)
		: m_folder(folder), m_type(type)
{
	m_nums.resize(nums.size());
	std::copy(nums.begin(), nums.end(), m_nums.begin());
}


const folder* messageChangedEvent::folder() const { return (const_cast <class folder*>(m_folder)); }
const messageChangedEvent::Types messageChangedEvent::type() const { return (m_type); }
const std::vector <int>& messageChangedEvent::numbers() const { return (m_nums); }


void messageChangedEvent::dispatch(messageChangedListener* listener) const
{
	listener->messageChanged(*this);
}


//
// folderEvent
//

folderEvent::folderEvent
	(class folder* folder, const Types type,
	 const utility::path& oldPath, const utility::path& newPath)
	: m_folder(folder), m_type(type), m_oldPath(oldPath), m_newPath(newPath)
{
}


const class folder* folderEvent::folder() const { return (m_folder); }
const folderEvent::Types folderEvent::type() const { return (m_type); }


void folderEvent::dispatch(class folderListener* listener) const
{
	switch (m_type)
	{
	case TYPE_CREATED: listener->folderCreated(*this); break;
	case TYPE_RENAMED: listener->folderRenamed(*this); break;
	case TYPE_DELETED: listener->folderDeleted(*this); break;
	}
}


} // events
} // messaging
} // vmime
