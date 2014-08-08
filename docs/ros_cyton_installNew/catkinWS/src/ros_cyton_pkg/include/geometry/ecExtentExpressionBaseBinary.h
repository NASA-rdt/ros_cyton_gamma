#ifndef ecExtentExpressionBaseBinary_H_
#define ecExtentExpressionBaseBinary_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecExtentExpressionBaseBinary.h
/// @class EcExtentExpressionBaseBinary
/// @brief A parent of binary extent operators.  It loads two
///        children.  The subclass defines the operation,
///        while this class defines reading, writing,  and access.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShape.h"

class EcAxisAlignedBoundingBox;
class EcShapeContainer;

/** A parent of binary expressions.  It loads two children.  The subclass
 defines the operation, while this class defines reading, writing, and
 access.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcExtentExpressionBaseBinary : public EcShape
{
public:
   /// default constructor - should not be used
   EcExtentExpressionBaseBinary
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExtentExpressionBaseBinary
      (
      const EcShapeContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExtentExpressionBaseBinary
      (
      );

   /// copy constructor
   EcExtentExpressionBaseBinary
      (
      const EcExtentExpressionBaseBinary& orig
      );

   /// assignment operator
   EcExtentExpressionBaseBinary& operator=
      (
      const EcExtentExpressionBaseBinary& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExtentExpressionBaseBinary& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets a pointer to the left expression
   virtual const EcShape* left
      (
      ) const;

   /// sets the left expression through a copy
   virtual void setLeft
      (
      const EcShape& left
      );

   /// gets a pointer to the right expression
   virtual const EcShape* right
      (
      ) const;

   /// sets the right expression through a copy
   virtual void setRight
      (
      const EcShape& right
      );

   /// Get the number of shapes that comprise this shape
   virtual EcU32 numberOfShapes
      (
      )const;

   /// return a token
   virtual const EcToken& token
      (
      ) const=0;

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

   /// scale the object by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleSelfBy
      (
      EcReal scaleFactor
      );

   /// transform the shape by the given coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:
   /// the left expression element
   EcShape*  m_pLeft;

   /// the right expression element
   EcShape*  m_pRight;
};

#endif // ecExtentExpressionBaseBinary_H_
