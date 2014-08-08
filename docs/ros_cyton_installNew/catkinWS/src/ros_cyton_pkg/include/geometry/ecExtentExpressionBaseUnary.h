#ifndef ecExtentExpressionBaseUnary_H_
#define ecExtentExpressionBaseUnary_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecExtentExpressionBaseUnary.h
/// @class EcExtentExpressionBaseUnary
/// @brief A parent of unary expressions.  It loads one child.  The
///        subclass defines the operation, while this class defines reading, writing,
///        and access.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecShape.h"

class EcAxisAlignedBoundingBox;
class EcShapeContainer;

/** A parent of unary expressions.  It loads one child.  The subclass
 defines the operation, while this class defines reading, writing, and
 access.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcExtentExpressionBaseUnary : public EcShape
{
public:
   /// default constructor - should not be used
   EcExtentExpressionBaseUnary
      (
      );

   /// constructor from an EcShapeContainer pointer
   EcExtentExpressionBaseUnary
      (
      const EcShapeContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExtentExpressionBaseUnary
      (
      );

   /// copy constructor
   EcExtentExpressionBaseUnary
      (
      const EcExtentExpressionBaseUnary& orig
      );

   /// assignment operator
   EcExtentExpressionBaseUnary& operator=
      (
      const EcExtentExpressionBaseUnary& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExtentExpressionBaseUnary& orig
      ) const;

   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets a pointer to the child expression
   virtual const EcShape* child
      (
      ) const;

   /// sets the child expression through a copy
   virtual void setChild
      (
      const EcShape& child
      );

   /// return a token
   virtual const EcToken& token
      (
      ) const = 0;

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

   /// read value from unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:
   /// the child expression element
   EcShape*  m_pChild;
};

#endif // ecExtentExpressionBaseUnary_H_
