#ifndef ecXmlObjectVisitor_H_
#  error This file should not be compiled directly.
#endif
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlObjectVisitorTemplateInst.ipp
//
//------------------------------------------------------------------------------
#include <sstream>

/////////////////////////////////////////////////////////////////////////
// Functions:    param_cast
// Description:  Attempts to cast a parameterized type to an EcXmlObject *
/////////////////////////////////////////////////////////////////////////
template <typename ObjectType>
const EcXmlObject*
param_cast
   (
   const ObjectType* obj
   )
{
   // Direct dynamic cast of pointer type
   return dynamic_cast<const EcXmlObject*>(obj);
}
template <typename ObjectType>
const EcXmlObject*
param_cast
   (
   const ObjectType& obj
   )
{
   // Decay from reference to pointer type.
   return dynamic_cast<const EcXmlObject*>(&obj);
}

/////////////////////////////////////////////////////////////////////////
// Functions:    visit
// Description:  Specialized visit methods for particular derived objects.
/////////////////////////////////////////////////////////////////////////
template <typename BasicType>
void
EcXmlObjectVisitor::visit
   (
   const EcXmlBasicType<BasicType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   m_List.push_back(m_Token.token());

   // Use a stream operator to correctly convert
   std::ostringstream os;
   os << obj->value();
   m_List.push_back(os.str());

   // Store this item.
   process();
}


template <typename BasicType> void
EcXmlObjectVisitor::visit
   (
   const EcXmlEnumType<BasicType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()
   m_List.push_back(m_Token.token());
   m_List.push_back(obj->enumString());

   // Store this item.
   process();
}


template <typename ElementType>
void
EcXmlObjectVisitor::visit
   (
   const EcXmlVectorType<ElementType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   const typename EcXmlVectorType<ElementType>::VectorContainer& container = obj->vectorContainer();
  const size_t numChildren = container.size();

   // Modify the token slightly in order to display container size
   m_List.push_back(m_Token.token() + EcString(" (") + EcINT2STRING(EcU32(numChildren)) + EcString(")"));

   // Store this item.
   EcBoolean continueVisit = process();

   if(checkDepthTraversal(obj) && continueVisit)
   {
      // Go through the children
      for(size_t ii=0; ii<numChildren; ++ii)
      {
         // Try to cast
         const EcXmlObject* childObj = param_cast(container[ii]);
         if(childObj)
         {
            m_Token = EcXml::EcElementToken; //EcString("element ") + EcINT2STRING(ii);
            childObj->accept(this);
         }
         else
         {
            // XXX Should not need, not possible.
            EcPrint(Warning) << "Visitor: EcXmlVectorType " << ii << " is non-EcXmlObject\n";
         }
      }
   }
      afterDepthTraversal();
}


template <typename ElementType> void
EcXmlObjectVisitor::visit
   (
   const EcXmlSetType<ElementType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   const typename EcXmlSetType<ElementType>::SetContainer& container = obj->setContainer();

   // Modify the token slightly in order to display container size
   m_List.push_back(m_Token.token() + EcString(" (") + EcINT2STRING(EcU32(container.size())) + EcString(")"));

   // Store this item.
   EcBoolean continueVisit=process();

   if(checkDepthTraversal(obj) && continueVisit)
   {
      typename EcXmlSetType<ElementType>::SetContainer::const_iterator it = container.begin();
      for(EcU32 count=0; it!=container.end(); ++it,++count)
      {
         // Try to cast
         const EcXmlObject* childObj = param_cast(*it);
         if(childObj)
         {
            m_Token = EcXml::EcElementToken;//EcString("element ") + EcINT2STRING(count);
            childObj->accept(this);
         }
         else
         {
            // XXX Should not need, not possible.
            EcPrint(Warning) << "Visitor: EcXmlSetType " << count << " is non-EcXmlObject\n";
         }
      }
   }
   afterDepthTraversal();
}


template <typename ElementType> void
EcXmlObjectVisitor::visit
   (
   const EcXmlVariableElementType<ElementType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   m_List.push_back(m_Token.token());
   EcBoolean continueVisit=process();

   if(continueVisit)
   {
      const ElementType* childObj = obj->element();
      if(childObj && param_cast(childObj))
      {
         if(checkDepthTraversal(obj))
         {
            m_Token = childObj->token();
            childObj->accept(this);
         }
         afterDepthTraversal();
      }
      else
      {
         // XXX Should not need, not possible.
         EcPrint(Warning) << "Visitor: EcXmlVariableElementType is non-EcXmlObject\n";
      }
   }
}


template <typename ElementType> void
EcXmlObjectVisitor::visit
   (
   const EcXmlVariableVectorType<ElementType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   const typename EcXmlVariableVectorType<ElementType>::VectorContainer& container = obj->vectorContainer();
   size_t numChildren = container.size();

   // Modify the token slightly in order to display container size
   m_List.push_back(m_Token.token() + EcString(" (") + EcINT2STRING(EcU32(numChildren)) + EcString(")"));

   // Store this item.
   EcBoolean continueVisit=process();

   if(checkDepthTraversal(obj) && continueVisit)
   {
      // Go through the children
      for(EcU32 ii=0; ii<numChildren; ++ii)
      {
         const ElementType* childObj = container[ii];
         if(childObj)
         {
            m_Token = childObj->token();
            childObj->accept(this);
         }
         else
         {
            // XXX Should not need, not possible.
            EcPrint(Warning) << "Visitor: EcXmlVariableVectorType " << ii << " is non-EcXmlObject\n";
         }
      }
   }
   afterDepthTraversal();
}


template <typename KeyType, typename ValueType> void
EcXmlObjectVisitor::visit
   (
   const EcXmlMapType<KeyType, ValueType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   const typename EcXmlMapType<KeyType,ValueType>::MapContainer& container = obj->mapContainer();

   // Modify the token slightly in order to display container size
   m_List.push_back(m_Token.token() + EcString(" (") + EcINT2STRING(EcU32(container.size())) + EcString(")"));

   // Store this item.
   EcBoolean continueVisit = process();

   if(checkDepthTraversal(obj) && continueVisit)
   {
      // Go through the children
      typename EcXmlMapType<KeyType,ValueType>::MapContainer::const_iterator it = container.begin();

      for(EcU32 count=0; it!=container.end(); ++it,++count)
      {
         // Try to cast
         const EcXmlObject* keyObj = param_cast(it->first);
         const EcXmlObject* valueObj = param_cast(it->second);
         // XXX How to display properly?
         if(keyObj)
         {
            m_Token = EcXml::EcKeyToken;// + EcString(" ") + EcINT2STRING(count);
            keyObj->accept(this);
         }
         else
         {
            // XXX Should not need, not possible.
            EcPrint(Warning) << "Visitor: EcXmlMapType key " << count << " is non-EcXmlObject\n";
         }
         if(valueObj)
         {
            m_Token = EcXml::EcValueToken;
            valueObj->accept(this);
         }
         else
         {
            // XXX Should not need, not possible.
            EcPrint(Warning) << "Visitor: EcXmlMapType value " << count << " is non-EcXmlObject\n";
         }
      }
   }
   afterDepthTraversal();
}


template <typename FirstType, typename SecondType> void
EcXmlObjectVisitor::visit
   (
   const EcXmlPairType<FirstType, SecondType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   m_List.push_back(m_Token.token());

   // Store this item.
   EcBoolean continueVisit = process();

   if(checkDepthTraversal(obj) && continueVisit)
   {
      // Go through the children

      // Try to cast
      const EcXmlObject* firstObj = param_cast(obj->first());
      const EcXmlObject* secondObj = param_cast(obj->second());
      // XXX How to display properly?
      if(firstObj)
      {
         m_Token = EcXml::EcFirstToken;
         firstObj->accept(this);
      }
      else
      {
         // What to do for non-EcXmlObjects?  Should we wedge it into the list?
         EcPrint(Warning) << "Visitor: EcXmlPairType first is non-EcXmlObject\n";
      }

      if(secondObj)
      {
         m_Token = EcXml::EcSecondToken;
         secondObj->accept(this);
      }
      else
      {
         // XXX Should not need, not possible.
         EcPrint(Warning) << "Visitor: EcXmlPairType second is non-EcXmlObject\n";
      }
   }
   afterDepthTraversal();
}


template <typename ExpressionType> void
EcXmlObjectVisitor::visit
   (
   const EcBaseExpressionTreeContainer<ExpressionType>* obj
   )
{
   ECXMLOBJECT_VISITOR_BEGIN()

   m_List.push_back(m_Token.token());
   EcBoolean continueVisit=process();

   if(continueVisit)
   {
      const ExpressionType* childObj = obj->topElement();
      // Make sure we have a valid pointer.
      if(childObj && param_cast(childObj)) // Check for EcXmlObject type
      {
         if(checkDepthTraversal(obj))
         {
            m_Token = childObj->token();
            param_cast(childObj)->accept(this);
            //childObj->accept(this);
         }
         afterDepthTraversal();
      }
      else if(childObj)
      {
         // XXX Should not need, not possible.
         EcPrint(Warning) << "EcBaseExpressionTreeContainer element is non-EcXmlObject\n";
      }
   }
}
