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
#include "include/IfcDistributionFlowElement.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelConnectsElements.h"
#include "include/IfcRelConnectsPortToElement.h"
#include "include/IfcRelConnectsWithRealizingElements.h"
#include "include/IfcRelContainedInSpatialStructure.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelFillsElement.h"
#include "include/IfcRelFlowControlElements.h"
#include "include/IfcRelInterferesElements.h"
#include "include/IfcRelNests.h"
#include "include/IfcRelProjectsElement.h"
#include "include/IfcRelReferencedInSpatialStructure.h"
#include "include/IfcRelSpaceBoundary.h"
#include "include/IfcRelVoidsElement.h"
#include "include/IfcText.h"

// ENTITY IfcDistributionFlowElement 
IfcDistributionFlowElement::IfcDistributionFlowElement() {}
IfcDistributionFlowElement::IfcDistributionFlowElement( int id ) { m_id = id; }
IfcDistributionFlowElement::~IfcDistributionFlowElement() {}
shared_ptr<IfcPPObject> IfcDistributionFlowElement::getDeepCopy()
{
	shared_ptr<IfcDistributionFlowElement> copy_self( new IfcDistributionFlowElement() );
	if( m_GlobalId ) { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy() ); }
	if( m_OwnerHistory ) { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy() ); }
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy() ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy() ); }
	if( m_ObjectType ) { copy_self->m_ObjectType = dynamic_pointer_cast<IfcLabel>( m_ObjectType->getDeepCopy() ); }
	if( m_ObjectPlacement ) { copy_self->m_ObjectPlacement = dynamic_pointer_cast<IfcObjectPlacement>( m_ObjectPlacement->getDeepCopy() ); }
	if( m_Representation ) { copy_self->m_Representation = dynamic_pointer_cast<IfcProductRepresentation>( m_Representation->getDeepCopy() ); }
	if( m_Tag ) { copy_self->m_Tag = dynamic_pointer_cast<IfcIdentifier>( m_Tag->getDeepCopy() ); }
	return copy_self;
}
void IfcDistributionFlowElement::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCDISTRIBUTIONFLOWELEMENT" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->getId(); } else { stream << "*"; }
	stream << ",";
	if( m_Representation ) { stream << "#" << m_Representation->getId(); } else { stream << "*"; }
	stream << ",";
	if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "*"; }
	stream << ");";
}
void IfcDistributionFlowElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcDistributionFlowElement::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDistributionFlowElement, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcDistributionFlowElement, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_GlobalId = IfcGloballyUniqueId::createObjectFromStepData( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromStepData( args[2] );
	m_Description = IfcText::createObjectFromStepData( args[3] );
	m_ObjectType = IfcLabel::createObjectFromStepData( args[4] );
	readEntityReference( args[5], m_ObjectPlacement, map );
	readEntityReference( args[6], m_Representation, map );
	m_Tag = IfcIdentifier::createObjectFromStepData( args[7] );
}
void IfcDistributionFlowElement::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcDistributionElement::getAttributes( vec_attributes );
}
void IfcDistributionFlowElement::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcDistributionElement::getAttributesInverse( vec_attributes_inverse );
	if( m_HasControlElements_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> HasControlElements_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_HasControlElements_inverse.size(); ++i )
		{
			if( !m_HasControlElements_inverse[i].expired() )
			{
				HasControlElements_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcRelFlowControlElements>( m_HasControlElements_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "HasControlElements_inverse", HasControlElements_inverse_vec_obj ) );
	}
}
void IfcDistributionFlowElement::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcDistributionElement::setInverseCounterparts( ptr_self_entity );
}
void IfcDistributionFlowElement::unlinkSelf()
{
	IfcDistributionElement::unlinkSelf();
}