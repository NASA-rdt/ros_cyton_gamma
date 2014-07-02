#ifndef ecShapeUnion_H_
#define ecShapeUnion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeUnion.h
/// @brief Holds the definition for a class representing the
///        union of EcShape objects
/// @details EcShapeUnion
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecShapeVector.h"

// forward declarations
class EcAxisAlignedBoundingBox;
class EcShapeContainer;
class EcExtentUnion;    // DEPRECATED - only needed for converting from old format

/** Holds the definition for a class representing the union of EcShape objects
*/
class EC_FOUNDATION_GEOMETRY_DECL EcShapeUnion : public EcShape
{
public:
   /// default constructor - should not be used
   EcShapeUnion
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcShapeUnion
      (
      const EcShapeContainer*  containerPointer
      );

   /// destructor
   virtual ~EcShapeUnion
      (
      );

   /// copy constructor
   EcShapeUnion
      (
      const EcShapeUnion& orig
      );

   /// assignment operator
   EcShapeUnion& operator=
      (
      const EcShapeUnion& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeUnion& orig
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

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// Get the number of shapes that comprise this shape
   virtual EcU32 numberOfShapes
      (
      ) const;

   /// return a token
   virtual const EcToken& token
      (
      ) const;

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

   /// get all the shapes in the union
   virtual const EcShapeVector& shapesInUnion
      (
      ) const;

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
      ) const;

   /// returns the number of shapes in the union, both bounding and none-bounding
   virtual EcU32 numShapesInUnion
      (
      ) const;

   /// returns the number of bounding shapes in the union
   virtual EcU32 numBoundingShapesInUnion
      (
      ) const;


   /// returns the number of non-bounding shapes in the union
   virtual EcU32 numNonBoundingShapesInUnion
      (
      ) const;

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
      ) const;

   /**
    * @brief Return the nth none-bounding shape in the union.
    * @param[in] n nth shape
    * @return const EcShape*
    */
   virtual const EcShape* getNthNonBoundingShapeInUnion
      (
      const EcU32& n
      ) const;

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
      ) const;

   /// add a shape to the union. If a shape union (EcShapeUnion) is added, then its children are extracted and added to this shape union.
   /// An EcExtentUnion can't be added since it's deprecated.
   virtual void addShapeToUnion
      (
      const EcShape& shape
      );

   /// delete a shape at index from the union.
   /**
   \return True if index is valid or false otherwise.
   */
   virtual EcBoolean deleteShapeFromUnion
      (
      EcU32 index
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

   /// return the surface property of this shape
   virtual const EcString& surfaceProperty
      (
      ) const;

   /// gets surface property collection
   virtual const EcStringDataMapMap& surfaces
      (
      ) const;

   /// gets surface property collection non-const
   virtual EcStringDataMapMap& surfaces
      (
      );

   /// sets the surface property of all the shapes in the union.
   virtual void setSurfaceProperty
      (
      const EcString& surfaceProp
      );

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

   /// set this shape union from the old-formatted EcExtentUnion. In addition, the lower-fidelity representation will be converted if it's also an extent union.
   virtual void setFromExtentUnion
      (
      const EcExtentUnion& extentUnion
      );

   /// gets consolidated flag
   virtual EcBoolean consolidatedFlag
      (
      ) const;

   /// sets consolidated flag
   virtual void setConsolidatedFlag
      (
      EcBoolean consolidatedFlag
      );

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:
   /// add shape to the bounding volumes
   virtual void addShapeToBoundingVolumes
      (
      const EcShape& shape
      );

   /// counts the number of shapes in the union
   virtual void countShapes
      (
      EcU32& index
      ) const;

   /// counts the number of shapes in the union excluding bounding volumes
   virtual void countNonBoundingShapes
      (
      EcU32& index
      ) const;

   /// expand a given capsule so that it bounds the shape
   virtual void expandCapsuleToBound
      (
      EcCapsule& capsule
      ) const;

   /// vector of the shapes
   EcShapeVector      m_vShapesInUnion;

   /// flag of consolidated
   EcXmlBoolean       m_ConsolidatedFlag;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the extent in a transformed frame.  xform expresses the old
/// representation frame in the new representation frame.
EC_FOUNDATION_GEOMETRY_DECL EcShapeUnion transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcShapeUnion& eu
   );

#endif // ecShapeUnion_H_
