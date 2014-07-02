//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVariablePropertyEditor.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlVariablePropertyEditor.h"
#include <xml/ecXmlObject.h>

/////////////////////////////////////////////////////////////////////////
// Function:     constructor/destructor
// Description:
/////////////////////////////////////////////////////////////////////////
template<class ElementType, class WrapperType, class ContainerType, class WrapperFactoryType>
EcXmlVariablePropertyEditor<ElementType, WrapperType, ContainerType, WrapperFactoryType>::EcXmlVariablePropertyEditor
   (
   QWidget *parent
   ) :
QtPropertyEditor(parent)
{
   // get all available types
   ContainerType container;
   container.xmlInit();
   const EcXmlCreatorMap& creatorMap = container.creatorMap();

   // iterate through the map
   EcXmlCreatorMap::const_iterator iter= creatorMap.begin();
   for(; iter!=creatorMap.end(); ++iter)
   {
      ElementType* elementType=dynamic_cast<ElementType*>(iter->second());
      m_vpElementWrapperPairs.append(qMakePair(elementType, WrapperFactoryType::createQWrapper(elementType, this)));
      m_AvailableTypes << QString::fromStdString(elementType->token().token());
   }
}

template<class ElementType, class WrapperType, class ContainerType, class WrapperFactoryType>
EcXmlVariablePropertyEditor<ElementType, WrapperType, ContainerType, WrapperFactoryType>::~EcXmlVariablePropertyEditor
   (
   )
{
   for(int ii=0; ii<m_vpElementWrapperPairs.size(); ++ii)
   {
      EcDELETE(m_vpElementWrapperPairs[ii].first);
      EcDELETE(m_vpElementWrapperPairs[ii].second);
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     setElementIndex
// Description:
/////////////////////////////////////////////////////////////////////////
template<class ElementType, class WrapperType, class ContainerType, class WrapperFactoryType>
void EcXmlVariablePropertyEditor<ElementType, WrapperType, ContainerType, WrapperFactoryType>::setElementIndex
   (
   EcInt32 index
   )
{
   if(index>=0 && index<numAvailableTypes())
   {
      setObject(m_vpElementWrapperPairs[index].second);
      resetProperties();
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     numAvailableTypes
// Description:
/////////////////////////////////////////////////////////////////////////
template<class ElementType, class WrapperType, class ContainerType, class WrapperFactoryType>
EcInt32 EcXmlVariablePropertyEditor<ElementType, WrapperType, ContainerType, WrapperFactoryType>::numAvailableTypes
   (
   ) const
{
   return m_vpElementWrapperPairs.size();
}

/////////////////////////////////////////////////////////////////////////
// Function:     element
// Description:
/////////////////////////////////////////////////////////////////////////
template<class ElementType, class WrapperType, class ContainerType, class WrapperFactoryType>
const ElementType* EcXmlVariablePropertyEditor<ElementType, WrapperType, ContainerType, WrapperFactoryType>::element
   (
   EcInt32 index
   ) const
{
   if(index>=0 && index<numAvailableTypes())
   {
      return m_vpElementWrapperPairs[index].first;
   }
   else
   {
      return EcNULL;
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     setElement
// Description:
/////////////////////////////////////////////////////////////////////////
template<class ElementType, class WrapperType, class ContainerType, class WrapperFactoryType>
EcBoolean EcXmlVariablePropertyEditor<ElementType, WrapperType, ContainerType, WrapperFactoryType>::setElement
   (
   EcInt32 index,
   const ElementType& value
   )
{
   if(index>=0 && index<numAvailableTypes())
   {
      EcDELETE(m_vpElementWrapperPairs[index].first);
      EcDELETE(m_vpElementWrapperPairs[index].second);

      m_vpElementWrapperPairs[index].first = dynamic_cast<ElementType*>(value.clone());
      m_vpElementWrapperPairs[index].second = WrapperFactoryType::createQWrapper(m_vpElementWrapperPairs[index].first, this);
      return EcTrue;
   }
   else
   {
      return EcFalse;
   }
}
