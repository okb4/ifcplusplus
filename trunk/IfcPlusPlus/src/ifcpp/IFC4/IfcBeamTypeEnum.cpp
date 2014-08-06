/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcBeamTypeEnum.h"

// TYPE IfcBeamTypeEnum 
IfcBeamTypeEnum::IfcBeamTypeEnum() {}
IfcBeamTypeEnum::~IfcBeamTypeEnum() {}
shared_ptr<IfcPPObject> IfcBeamTypeEnum::getDeepCopy()
{
	shared_ptr<IfcBeamTypeEnum> copy_self( new IfcBeamTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcBeamTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCBEAMTYPEENUM("; }
	if( m_enum == ENUM_BEAM )
	{
		stream << ".BEAM.";
	}
	else if( m_enum == ENUM_JOIST )
	{
		stream << ".JOIST.";
	}
	else if( m_enum == ENUM_HOLLOWCORE )
	{
		stream << ".HOLLOWCORE.";
	}
	else if( m_enum == ENUM_LINTEL )
	{
		stream << ".LINTEL.";
	}
	else if( m_enum == ENUM_SPANDREL )
	{
		stream << ".SPANDREL.";
	}
	else if( m_enum == ENUM_T_BEAM )
	{
		stream << ".T_BEAM.";
	}
	else if( m_enum == ENUM_USERDEFINED )
	{
		stream << ".USERDEFINED.";
	}
	else if( m_enum == ENUM_NOTDEFINED )
	{
		stream << ".NOTDEFINED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcBeamTypeEnum> IfcBeamTypeEnum::createObjectFromStepData( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcBeamTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcBeamTypeEnum>(); }
	shared_ptr<IfcBeamTypeEnum> type_object( new IfcBeamTypeEnum() );
	if( boost::iequals( arg, L".BEAM." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_BEAM;
	}
	else if( boost::iequals( arg, L".JOIST." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_JOIST;
	}
	else if( boost::iequals( arg, L".HOLLOWCORE." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_HOLLOWCORE;
	}
	else if( boost::iequals( arg, L".LINTEL." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_LINTEL;
	}
	else if( boost::iequals( arg, L".SPANDREL." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_SPANDREL;
	}
	else if( boost::iequals( arg, L".T_BEAM." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_T_BEAM;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcBeamTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}