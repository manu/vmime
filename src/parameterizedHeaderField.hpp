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

#ifndef VMIME_PARAMETERIZEDHEADERFIELD_HPP_INCLUDED
#define VMIME_PARAMETERIZEDHEADERFIELD_HPP_INCLUDED


#include "base.hpp"
#include "headerFieldFactory.hpp"
#include "parameter.hpp"
#include "exception.hpp"
#include "parameterFactory.hpp"


namespace vmime
{


class parameterizedHeaderField : virtual public headerField
{
	friend class headerFieldFactory::registerer <parameterizedHeaderField>;

protected:

	parameterizedHeaderField();

public:

	void copyFrom(const component& other);
	parameterizedHeaderField& operator=(const parameterizedHeaderField& other);

	/** Checks whether (at least) one parameter with this name exists.
	  *
	  * @return true if at least one parameter with the specified name
	  * exists, or false otherwise
	  */
	const bool hasParameter(const string& paramName) const;

	/** Find the first parameter that matches the specified name.
	  * If no parameter is found, an exception is thrown.
	  *
	  * @throw exceptions::no_such_parameter if no parameter with this name exists
	  * @return first parameter with the specified name
	  */
	parameter* findParameter(const string& paramName) const;

	/** Find the first parameter that matches the specified name.
	  * If no parameter is found, one will be created and inserted into
	  * the parameter list.
	  *
	  * @return first parameter with the specified name or a new field
	  * if no parameter is found
	  */
	parameter* getParameter(const string& paramName);

	/** Add a parameter at the end of the list.
	  *
	  * @param param parameter to append
	  */
	void appendParameter(parameter* param);

	/** Insert a new parameter before the specified parameter.
	  *
	  * @param beforeParam parameter before which the new parameter will be inserted
	  * @param param parameter to insert
	  * @throw exceptions::no_such_parameter if the parameter is not in the list
	  */
	void insertParameterBefore(parameter* beforeParam, parameter* param);

	/** Insert a new parameter before the specified position.
	  *
	  * @param pos position at which to insert the new parameter (0 to insert at
	  * the beginning of the list)
	  * @param param parameter to insert
	  */
	void insertParameterBefore(const int pos, parameter* param);

	/** Insert a new parameter after the specified parameter.
	  *
	  * @param afterParam parameter after which the new parameter will be inserted
	  * @param param parameter to insert
	  * @throw exceptions::no_such_parameter if the parameter is not in the list
	  */
	void insertParameterAfter(parameter* afterParam, parameter* param);

	/** Insert a new parameter after the specified position.
	  *
	  * @param pos position of the parameter before the new parameter
	  * @param param parameter to insert
	  */
	void insertParameterAfter(const int pos, parameter* param);

	/** Remove the specified parameter from the list.
	  *
	  * @param param parameter to remove
	  * @throw exceptions::no_such_parameter if the parameter is not in the list
	  */
	void removeParameter(parameter* param);

	/** Remove the parameter at the specified position.
	  *
	  * @param pos position of the parameter to remove
	  */
	void removeParameter(const int pos);

	/** Remove all parameters from the list.
	  */
	void removeAllParameters();

	/** Return the number of parameters in the list.
	  *
	  * @return number of parameters
	  */
	const int getParameterCount() const;

	/** Tests whether the list of parameters is empty.
	  *
	  * @return true if there is no parameter, false otherwise
	  */
	const bool isEmpty() const;

	/** Return the parameter at the specified position.
	  *
	  * @param pos position
	  * @return parameter at position 'pos'
	  */
	parameter* getParameterAt(const int pos);

	/** Return the parameter at the specified position.
	  *
	  * @param pos position
	  * @return parameter at position 'pos'
	  */
	const parameter* const getParameterAt(const int pos) const;

	/** Return the parameter list.
	  *
	  * @return list of parameters
	  */
	const std::vector <const parameter*> getParameterList() const;

	/** Return the parameter list.
	  *
	  * @return list of parameters
	  */
	const std::vector <parameter*> getParameterList();

private:

	std::vector <parameter*> m_params;

public:

	using headerField::parse;
	using headerField::generate;

	void parse(const string& buffer, const string::size_type position, const string::size_type end, string::size_type* newPosition = NULL);
	void generate(utility::outputStream& os, const string::size_type maxLineLength = lineLengthLimits::infinite, const string::size_type curLinePos = 0, string::size_type* newLinePos = NULL) const;
};


} // vmime


#endif // VMIME_PARAMETERIZEDHEADERFIELD_HPP_INCLUDED
