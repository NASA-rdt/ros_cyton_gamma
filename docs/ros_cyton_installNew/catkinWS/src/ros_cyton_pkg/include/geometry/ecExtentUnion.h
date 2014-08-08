#ifndef ecExtentUnion_H_
#define ecExtentUnion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecExtentUnion.h
/// @brief Holds the definition for a class representing the
///        union of two EcShape objects
/// @details EcExtentUnion
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecShape.h"
#include "ecExtentExpressionBaseBinary.h"

class EcExpressionContainer;

/** Holds a  class that defines a shape based on the union of
    the two child child nodes
*/
class EC_FOUNDATION_GEOMETRY_DECL EcExtentUnion : public EcExtentExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExtentUnion
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExtentUnion
      (
      const EcShapeContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExtentUnion
      (
      );

   /// copy constructor
   EcExtentUnion
      (
      const EcExtentUnion& orig
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

   /// return a token
   virtual const EcToken& token
      (
      ) const;

   /// get the distance to a line segment
   virtual EcReal distanceTo
      (
      const EcLineSegment& seg
      ) const;

   /// get the distance to a point
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /**
   \copydoc EcShape::intersectLineSegment()
   */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// check the intersection with line segment
   virtual EcBoolean checkIntersect
      (
      const EcLineSegment& lineSegment
      ) const;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcVector& point
      ) const;


   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
         const EcXmlVectorVector& points
      );

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
      const EcShape& shape
      );

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const;

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const ;

   /// set the level of this shape in the bounding volume hierarchy
   virtual void setBVHLevel
      (
      const EcU32& level
      );

   /// set the shape index and pointer back to the parent link
   virtual void setIndexAndBackPointer
      (
      EcU32& index,
      const EcManipulatorLink* link,
      EcShapeConstPointerMap& shapePointerMap,
      EcShapePointerVector& shapePointerVec
      );

   /// return the children of this shape
   virtual void collectChildPointers
      (
      EcShapeConstPointerVector& childrenPointerVector
      )const;

   /// returns the number of shapes in the union, both bounding and none-bounding
   virtual EcU32 numShapesInUnion
      (
      )const;

   /// returns the number of bounding shapes in the union
   virtual EcU32 numBoundingShapesInUnion
      (
      )const;


   /// returns the number of non-bounding shapes in the union
   virtual EcU32 numNonBoundingShapesInUnion
      (
      )const;

   /**
    * @brief Return the nth none-bounding shape in the union.
    * @param[in] n nth shape
    * @param[in] counter counter from previous layer
    * @return const EcShape*
    */
   virtual const EcShape* getNthNonBoundingShape
      (
      const EcU32 n,
      EcU32& counter
      )const;

   /**
    * @brief Return the nth none-bounding shape in the union
    * @param[in] n nth shape
    * @return const EcShape*
    */
   virtual const EcShape* getNthNonBoundingShapeInUnion
      (
      const EcU32& n
      )const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// create a test object of three equidistant spheres

   /// creator function
   static EcXmlObject* creator
      (
      );

   /// get capsule vector in primary frame of shape.  NOTE:
   /// unions will have more than one
   virtual void  capsuleBoundingVolumeVectorInPrimary
      (
      EcXmlVectorType<EcCapsule>&  capsuleVec,
      EcU32Vector& shapeIDVec
      )const;

   /// get the collection of bounding volumes that represent this shape
   virtual void boundingVolumes
      (
      EcShapeConstPointerVector& boundingVolumes,
      const EcU32 bvhLevel
      )const ;

   /**
    * @brief Add a shape to the union.
    * @param[in] shape nth shape
    * @return void
    */
   virtual void addShapeToUnion
      (
      const EcShape& shape
      );

   /// gets capsule bounding volume
   virtual const EcCapsule& capsuleBoundingVolume
      (
      ) const;

   /// sets capsule bounding volume
   virtual void setCapsuleBoundingVolume
      (
      const EcCapsule& capsuleBoundingVolume
      );

   /// sets the surface property of all the shapes in the union.
   virtual void setSurfaceProperty
      (
      const EcString& surfaceProp
      ) ;

   /// set the surface properties collection of all the shapes in the union.
   virtual void setSurfaces
      (
      const EcStringDataMapMap& surfaces
      );

   /// set the properties of the surface identified by key of all the shapes in the union.
   /**
   \param[in] key A string to identify the surface material.
   \param[in] properties The surface properties to be set.
   \return True if key is found and the operation is successful or false otherwise.
   */
   virtual EcBoolean setSurfaceProperties
      (
      const EcString& key,
      const EcDataMap& properties
      );

   /// create a bounding shape for the union. If union has more than one leaf nodes, the returned bounding shape will be a union of bounding shapes of all the shapes in the union.
   virtual EcShape* createBoundingShape
      (
      const EcShapeValues& bv
      ) const;

protected:

   /// counts the number of shapes in the union
   virtual void countShapes
      (
      EcU32& index
      )const;


   /// counts the number of shapes in the union excluding bounding volumes
   virtual void countNonBoundingShapes
      (
      EcU32& index
      )const;

   /// expand a given capsule so that it bounds the shape
   virtual void expandCapsuleToBound
      (
      EcCapsule& capsule
      ) const;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the extent in a transformed frame.  xform expresses the old
/// representation frame in the new representation frame.
EC_FOUNDATION_GEOMETRY_DECL EcExtentUnion transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcExtentUnion& eu
   );

#endif // ecExtentUnion_H_
