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

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRepresentationContext.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcStyledRepresentation.h"

// ENTITY IfcStyledRepresentation 
IfcStyledRepresentation::IfcStyledRepresentation() {}
IfcStyledRepresentation::IfcStyledRepresentation( int id ) { m_id = id; }
IfcStyledRepresentation::~IfcStyledRepresentation() {}
shared_ptr<IfcPPObject> IfcStyledRepresentation::getDeepCopy()
{
	shared_ptr<IfcStyledRepresentation> copy_self( new IfcStyledRepresentation() );
	if( m_ContextOfItems ) { copy_self->m_ContextOfItems = dynamic_pointer_cast<IfcRepresentationContext>( m_ContextOfItems->getDeepCopy() ); }
	if( m_RepresentationIdentifier ) { copy_self->m_RepresentationIdentifier = dynamic_pointer_cast<IfcLabel>( m_RepresentationIdentifier->getDeepCopy() ); }
	if( m_RepresentationType ) { copy_self->m_RepresentationType = dynamic_pointer_cast<IfcLabel>( m_RepresentationType->getDeepCopy() ); }
	for( size_t ii=0; ii<m_Items.size(); ++ii )
	{
		auto item_ii = m_Items[ii];
		if( item_ii )
		{
			copy_self->m_Items.push_back( dynamic_pointer_cast<IfcRepresentationItem>(item_ii->getDeepCopy() ) );
		}
	}
	return copy_self;
}
void IfcStyledRepresentation::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCSTYLEDREPRESENTATION" << "(";
	if( m_ContextOfItems ) { stream << "#" << m_ContextOfItems->getId(); } else { stream << "*"; }
	stream << ",";
	if( m_RepresentationIdentifier ) { m_RepresentationIdentifier->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_RepresentationType ) { m_RepresentationType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	writeEntityList( stream, m_Items );
	stream << ");";
}
void IfcStyledRepresentation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcStyledRepresentation::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStyledRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcStyledRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	readEntityReference( args[0], m_ContextOfItems, map );
	m_RepresentationIdentifier = IfcLabel::createObjectFromStepData( args[1] );
	m_RepresentationType = IfcLabel::createObjectFromStepData( args[2] );
	readEntityReferenceList( args[3], m_Items, map );
}
void IfcStyledRepresentation::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcStyleModel::getAttributes( vec_attributes );
}
void IfcStyledRepresentation::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcStyleModel::getAttributesInverse( vec_attributes_inverse );
}
void IfcStyledRepresentation::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcStyleModel::setInverseCounterparts( ptr_self_entity );
}
void IfcStyledRepresentation::unlinkSelf()
{
	IfcStyleModel::unlinkSelf();
}