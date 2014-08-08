#ifndef ecXmlVarElemType_H_
#define ecXmlVarElemType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVarElemType.h
/// @class EcXmlVariableElementType
/// @brief Holds an abstract base class for a variable element type.
//
//------------------------------------------------------------------------------
#include "ecXmlBaseVarCompType.h"

template<class ElementType>
class EcXmlVariableElementType : public EcXmlBaseVariableCompoundType
{
public:
   /// #ECDECLARE_BIGFOUR(EcCls) Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcXmlVariableElementType);
   ECXMLOBJECT_ACCEPT(EcXmlVariableElementType)

   /// gets a pointer to the top expression (const)
   virtual const ElementType* element
      (
      ) const;

   /// gets a pointer to the top expression (nonconst)
   virtual ElementType* element
      (
      );

   /// sets the top expression through a copy
   virtual void setElement
      (
      const ElementType& topElement
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

protected:
   /// read an XML object from a stream after reading the start tag
   /// return value signals success or failure
   virtual EcBoolean readValueFromToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// the top expression element
   ElementType* m_pElement;
};

#endif // ecXmlVarElemType_H_
