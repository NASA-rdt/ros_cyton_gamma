#ifndef ecPlanarShapeUnion_H_
#define ecPlanarShapeUnion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarShapeUnion.h
/// @brief A union of non-composite EcPlanarhape objects
/// @details EcPlanarShapeUnion
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlanarShapeVector.h"

// forward declarations
class EcPlanarShapeContainer;

/// A union of non-composite EcPlanarhape objects
class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarShapeUnion : public EcPlanarShape
{
public:
   /// default constructor - should not be used
   EcPlanarShapeUnion
      (
      );

   /// destructor
   virtual ~EcPlanarShapeUnion
      (
      );

   /// copy constructor
   EcPlanarShapeUnion
      (
      const EcPlanarShapeUnion& orig
      );

   /// assignment operator
   EcPlanarShapeUnion& operator=
      (
      const EcPlanarShapeUnion& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarShapeUnion& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// Get the number of shapes that comprise this shape
   virtual EcU32 numberOfShapes
      (
      ) const;

   /// get all the shapes in the union
   virtual const EcPlanarShapeVector& shapesInUnion
      (
      ) const;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcPlanarVector& point
      ) const;

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// return the children of this shape
   virtual void collectChildPointers
      (
      EcPlanarShapeConstPointerVector& childrenPointerVector
      ) const;

   /// returns the number of shapes in the union
   virtual EcU32 numShapesInUnion
      (
      ) const;

   /// add a shape to the union. If a shape union (EcPlanarShapeUnion) is added, then its children are extracted and added to this shape union.
   virtual void addShapeToUnion
      (
      const EcPlanarShape& shape
      );

   /// delete a shape at index from the union.
   /**
   \return True if index is valid or false otherwise.
   */
   virtual EcBoolean deleteShapeFromUnion
      (
      EcU32 index
      );

   /// sets the surface property of all the shapes in the union.
   virtual void setSurfaceProperty
      (
      const EcString& surfaceProp
      );

   /// get an empty union
   static EcPlanarShapeUnion nullObject
      (
      );

   /// the creator function for this object
   static EcXmlObject* creator
      (
      );

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;

protected:
   /// counts the number of shapes in the union
   virtual void countShapes
      (
      EcU32& index
      ) const;

   /// vector of the shapes
   EcPlanarShapeVector m_ShapeVector;
};

#endif // ecPlanarShapeUnion_H_
