#ifndef ecExpBaseUnary_H_
#define ecExpBaseUnary_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpBaseUnary.h
/// @class EcExpressionBaseUnary
/// @brief A parent of binary expressions.  It loads one child.  The
///        subclass defines the operation, while this class defines reading, writing,
///        and access.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecExpElement.h"

class EcExpressionContainer;

/// A parent of unary expressions.  It loads one child.
/** The subclass defines the operation, while this class defines reading, writing, and
 access.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionBaseUnary : public EcExpressionElement
{
public:
   /// default constructor - should not be used
   EcExpressionBaseUnary
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionBaseUnary
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionBaseUnary
      (
      );

   /// copy constructor
   EcExpressionBaseUnary
      (
      const EcExpressionBaseUnary& orig
      );

   /// assignment operator
   EcExpressionBaseUnary& operator=
      (
      const EcExpressionBaseUnary& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionBaseUnary& orig
      ) const;

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets a pointer to the child expression
   virtual const EcExpressionElement* child
      (
      ) const;

   /// sets the child expression through a copy
   virtual void setChild
      (
      const EcExpressionElement& child
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

   /// write this object to an XML stream
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

protected:
   /// read an individual element given its token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// the child expression element
   EcExpressionElement*  m_pChild;
};

#endif // ecExpBaseUnary_H_
