#ifndef ecBaseExpTreeContainer_H_
#define ecBaseExpTreeContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseExpTreeContainer.h
/// @class EcBaseExpressionTreeContainer
/// @brief Holds an abstract base class for a logical expression tree.
//
//------------------------------------------------------------------------------
#include "ecXmlBaseVarCompType.h"

template<class ExpressionType>
class EcBaseExpressionTreeContainer : public EcXmlBaseVariableCompoundType
{
public:
   /// #ECDECLARE_BIGFOUR(EcCls) Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcBaseExpressionTreeContainer);
   ECXMLOBJECT_ACCEPT(EcBaseExpressionTreeContainer)

   /// gets a pointer to the top expression (const)
   virtual const ExpressionType* topElement
      (
      ) const;

   /// gets a pointer to the top expression (nonconst)
   virtual ExpressionType* topElement
      (
      );

   /// sets the top expression through a copy
   virtual void setTopElement
      (
      const ExpressionType& topElement
      );

   /// sets the top expression pointer and later deletes this pointer
   /// Use with great care
   virtual void setAndDeleteTopElementPointer
      (
      ExpressionType* pTopElement
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

   /// write object schema to an XML stream
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// set the container pointer for the top element to this
   /// if needed
   virtual void setTopElementContainerToThis
      (
      );

protected:
   /// read an XML object from a stream after reading the start tag
   /// return value signals success or failure
   virtual EcBoolean readValueFromToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// the top expression element
   ExpressionType*  m_pTopElement;
};

#endif // ecBaseExpTreeContainer_H_
