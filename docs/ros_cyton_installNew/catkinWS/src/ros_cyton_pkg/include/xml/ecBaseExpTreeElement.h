#ifndef ecBaseExpTreeElement_H_
#define ecBaseExpTreeElement_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseExpTreeElement.h
/// @class EcBaseExpressionTreeElement
/// @brief Abstract base class for the element types
///        of EcBaseExpressionTreeContainer
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecXmlCompType.h"

class EcXmlBaseVariableCompoundType;

class EC_STABLE_XML_DECL EcBaseExpressionTreeElement : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseExpressionTreeElement
      (
      );

   /// constructor given container pointer
   explicit EcBaseExpressionTreeElement
      (
      const EcXmlBaseVariableCompoundType* containerPointer
      );

   /// destructor
   virtual ~EcBaseExpressionTreeElement
      (
      );

   /// copy constructor
   EcBaseExpressionTreeElement
      (
      const EcBaseExpressionTreeElement& orig
      );

   /// assignment operator
   EcBaseExpressionTreeElement& operator=
      (
      const EcBaseExpressionTreeElement& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseExpressionTreeElement& orig
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const=0;

   /// registers components for class
   virtual void registerComponents
      (
      );

   /// gets the container
   virtual const EcXmlBaseVariableCompoundType* container
      (
      ) const;

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

protected:
   /// a pointer to the container
   const EcXmlBaseVariableCompoundType* m_pContainer;
};

#endif // ecBaseExpTreeElement_H_
