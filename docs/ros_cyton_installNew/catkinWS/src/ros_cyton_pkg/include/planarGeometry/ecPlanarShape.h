#ifndef ecPlanarShape_H_
#define ecPlanarShape_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarShape.h
/// @class EcPlanarShape
/// @brief Virtual base class for all planar (2D) shapes
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <foundCommon/ecDataMap.h>
#include <xml/ecBaseExpTreeElement.h>

// forward declaration
class EcPlanarVector;

/// a vector of const shape pointers
class EcPlanarShape;
/// type definition of EcPlanarShapeConstPointerVector
typedef std::vector<const EcPlanarShape*> EcPlanarShapeConstPointerVector;

/// Virtual base class for all planar (2D) shapes
class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarShape : public EcBaseExpressionTreeElement
{
public:
   /// enumeration for planar shape types
   typedef enum
   {
      AABOX,  /// A planar axis-aligned box defined by a center and extents
      CIRCLE, /// A planar circle defined by a center and radius
      UNION,  /// A composite shape that is the union of other shapes
      POLYGON /// A planar polygon defined by points specified in a clockwise direction
   } EcPlanarShapeTypes;

   /// default constructor
   EcPlanarShape
      (
      );

   /// destructor
   virtual ~EcPlanarShape
      (
      );

   /// copy constructor
   EcPlanarShape
      (
      const EcPlanarShape& orig
      );

   /// assignment operator
   EcPlanarShape& operator=
      (
      const EcPlanarShape& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarShape& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcPlanarVector& point
      ) const = 0;

   /// return the surface property of this shape
   virtual const EcString& surfaceProperty
      (
      ) const;

   /// sets the surface property of this shape
   virtual void setSurfaceProperty
      (
      const EcString& surfaceProp
      );

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const = 0;

   /// get the shape identifier
   virtual const EcString& identifier
      (
      ) const;

   /// set the shape identifier
   virtual void setIdentifier
      (
      const EcString& identifier
      );

   /// get the children for this shape
   /// return the children of this shape
   virtual const EcPlanarShapeConstPointerVector& children
      (
      ) const;

   /// recursively collect child shape pointers
   virtual void collectChildPointers
      (
      EcPlanarShapeConstPointerVector& childrenPointerVector
      ) const;

   /// get the number of shapes that comprise this shape,
   /// this is always one for non-composite shapes
   virtual EcU32 numberOfShapes
      (
      ) const;

protected:
   /// contains the surface property of this shape (assumes homogeneous)
   EcXmlString                             m_SurfaceProperty;

   /// optional identifier for this shape
   EcXmlString                             m_ShapeIdentifier;

   /// Non-XML Data

   /// a vector of pointers to shapes that are children of this shape
   mutable EcPlanarShapeConstPointerVector m_ChildrenPointerVector;
};

#endif // ecPlanarShape_H_
