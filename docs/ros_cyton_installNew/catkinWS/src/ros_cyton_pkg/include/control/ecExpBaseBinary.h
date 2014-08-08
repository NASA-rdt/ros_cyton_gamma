#ifndef ecExpBaseBinary_H_
#define ecExpBaseBinary_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpBaseBinary.h
/// @class EcExpressionBaseBinary
/// @brief A parent of binary expressions.  It loads two children.  The
///        subclass defines the operation, while this class defines reading, writing,
///        and access.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecExpElement.h"

class EcExpressionContainer;

/** A parent of binary expressions.  It loads two children.*/
/** The subclass defines the operation, while this class defines reading, writing, and
 access.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionBaseBinary : public EcExpressionElement
{
public:
   /// default constructor - should not be used
   EcExpressionBaseBinary
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionBaseBinary
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionBaseBinary
      (
      );

   /// copy constructor
   EcExpressionBaseBinary
      (
      const EcExpressionBaseBinary& orig
      );

   /// assignment operator
   EcExpressionBaseBinary& operator=
      (
      const EcExpressionBaseBinary& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionBaseBinary& orig
      ) const;

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets a pointer to the left expression
   virtual const EcExpressionElement* left
      (
      ) const;

   /// sets the left expression through a copy
   virtual void setLeft
      (
      const EcExpressionElement& left
      );

   /// gets a pointer to the right expression
   virtual const EcExpressionElement* right
      (
      ) const;

   /// sets the right expression through a copy
   virtual void setRight
      (
      const EcExpressionElement& right
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

   /// the left expression element
   EcExpressionElement*  m_pLeft;

   /// the right expression element
   EcExpressionElement*  m_pRight;
};

#endif // ecExpBaseBinary_H_
