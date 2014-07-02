#ifndef ecShape_H_
#define ecShape_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShape.h
/// @class EcShape
/// @brief Virtual base class for all shapes.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPolygonWithKey.h"

#include <foundCommon/ecDataMap.h>
#include <xml/ecBaseExpTreeElement.h>


// forward declaration
class EcAxisAlignedBoundingBox;
class EcBasePhysicalExtent;
class EcCapsule;
class EcLineSegment;
class EcManipulatorLink;
class EcManipulatorSystem;
class EcShapePointEvent;
class EcShapeProximityDescriptor;
class EcShapeQueryData;
class EcStatedSystem;
class EcSystemActiveCollisionState;
class EcSystemShapeProximityState;

class EcShape;
/// a map of const shape pointers
typedef std::map<EcString,const EcShape*> EcShapeConstPointerMap;

/// a vector of const shape pointers
typedef std::vector<const EcShape*> EcShapeConstPointerVector;

/// a vector of non-const shape pointers
typedef std::vector<EcShape*> EcShapePointerVector;

/** Holds a class to describe a 3D shape
*/
class EC_FOUNDATION_GEOMETRY_DECL EcShape : public EcBaseExpressionTreeElement
{
public:
   /// enumerations for supported geometry
   typedef enum
   {
      POINT_POLYGON,    ///  A point polygon representation
                        ///  (consisting of a co-planar collection of points)
      POLY_PHYSICAL,    ///  A point physical extent
      TRI_PHYSICAL,     ///  A triangular physical extent
      SPHERE,           ///  A sphere defined by a radius and center
      CAPSULE,          ///  A capsule defined by a line segment and a radius
      ELLIPSOID,        ///  An ellipsoid defined by x^2/a^2 + y^2/b^2 + z^2/c^2 = 1
      TETRAHEDRON,      ///  A tetrahedron defined by a base point and three edges
      OBB,              ///  An oriented bounding box defined by a center,
                        ///  three axes and three extents
      LOZENGE,          ///  A lozenge defined by a 3D rectangle and a radius
      HALFSPACE,        ///  A half-space defined by a plane, the normal points
                        ///  out of the half-space
      GRID,             ///  A grid shape made up of bricks
      CYLINDER,         ///  A Cylinder defined by a line segment and a radius
      CONE,             ///  A Cone defined by a line segment and 2 radii
      CIRCULARLOZENGE,  ///  All points within a specified distance from a 3D circular disk
      TRIANGULARLOZENGE,///  All points within a specified distance from a 3D filled triangle
      TERRAIN,          ///  A terrain shape
      // Note: Add new algorithms before UNION.  UNION sets MAX_SHAPE_TYPES.
      UNION,            ///  A composite shape that is the union of other shapes
      INTERSECTION,     ///  A composite shape that is the intersection of other shapes

   } EcShapeValues ;

   /// enumerations for collision data accessing
   typedef enum
   {
     ALL,      // get all collision events
     DEEPEST   // return only collision data of the deepest penetration.
   } EcCollisionQueryOptions;

   /// default constructor
   EcShape
      (
      );

   /// destructor
   virtual ~EcShape
      (
      );

   /// copy constructor
   EcShape
      (
      const EcShape& orig
      );

   /// assignment operator
   EcShape& operator=
      (
      const EcShape& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShape& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
         const EcShape& shape
      ) = 0;

   /// get support point given a vector, will use physicalExt if deformable
   virtual EcVector computeSupportPoint
      (
      const EcVector& v
      ) const;

   /// get support point given a vector
   virtual EcVector supportPoint
      (
      const EcVector& v
      ) const;

   /// scale the shape and the lower-fidelity reprentation shape by the specified value
   /// (scaleFactor=1.0 does not change the shape)
   virtual void scaleBy
      (
      EcReal scaleFactor
      );

   /// scale the shape itself by the specified value
   /// (scaleFactor=1.0 does not change the shape)
   virtual void scaleSelfBy
      (
      EcReal scaleFactor
      )=0;

   /// transform the shape by the given coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// get the distance to a line segment
   virtual EcReal distanceTo
      (
      const EcLineSegment& seg
      ) const = 0;

   /// get the distance to a point
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const = 0;

   /// check the intersection with line segment
   virtual EcBoolean checkIntersect
      (
      const EcLineSegment& lineSegment
      ) const = 0;

   /// Intersect a line segment with the shape.
   /**
   If the initial isImpacted in pointEvent is false and the line segment intersects with the shape, isImpacted in pointEvent will be set to true and the distance in pointEvent will be set to the distance from the first endpoint along the line segment to the point of intersection of the shape. If the first endpoint of the line segment lies inside or on the surface of the shape (regardless of whether the other endpoint lies inside the shape), then the distance is set to 0 and isImpacted is set to true. If the line segment does not intersect with the shape, then nothing happens.
   If the initial isImpacted in pointEvent is true and the line segment intersects with the shape, the initial distance in pointEvent will be compared to the distance from the first endpoint along the line segment to the point of intersection. If the new distance is less than the initial distance, the distance in pointEvent will be set to the new distance. Otherwise, the distance in pointEvent will remain unchanged.
   */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const=0;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcVector& point
      ) const = 0;

   /// lower fidelity representation
   virtual const EcShape* lowerFidelityRepresentation
      (
      ) const;

   /// lowest fidelity not to exceed the given level
   virtual const EcShape* lowestFidelityNotToExceed
      (
      EcU32 level
      ) const;

   /// higher fidelity representation
   virtual const EcShape* higherFidelityRepresentation
      (
      ) const;

   /// lower fidelity representation
   /// sets and deletes pointer
   virtual void setLowerFidelityRepresentationPointer
      (
      EcShape* ptr
      );

   /// higher fidelity representation
   virtual void setHigherFidelityRepresentationPointer
      (
      EcShape* ptr
      );

   /// lower fidelity representation (makes a copy)
   virtual void setLowerFidelityRepresentation
      (
      const EcShape& shape
      );

   /// add a bounding volume to this shape
   virtual void addBoundingVolume
      (
      const EcShapeValues& bv
      );

   /// delete all the bounding volumes in the hierarchy
   virtual void deleteBoundingVolumes
      (
      );

   /// delete the physical extent
   virtual void deletePhysicalExtent
      (
      );

   /// returns the normal vector of the polygon intersected by the line
   /// segment passed in.  If the line segment intersects more than
   /// one polygon, the first polygon intersected is returned
   virtual EcBoolean normalOfIntersection
      (
      const EcLineSegment& seg,
      const EcCoordinateSystemTransformation& xform,
      EcVector& normalVector
      )const;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
      const EcXmlVectorVector& points
      ) = 0;

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const = 0;

   /// Get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility (non-const version)
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const =0;

   /// read value from unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      ) ;

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write this object to an XML schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// return the surface property of this shape
   virtual const EcString& surfaceProperty
      (
      ) const;

   /// sets the surface property of this shape
   virtual void setSurfaceProperty
      (
      const EcString& surfaceProp
      );

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const = 0;

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const = 0;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0 ;

   /// get function for detail level
   virtual EcU32 detailLevel
      (
      ) const;

   /// set function for detail level
   virtual void setDetailLevel
      (
      const EcU32 detLev
      );
   /// set the proximity database index for this shape, and the link pointer
   virtual void setIndexAndBackPointer
      (
      EcU32& index,
      const EcManipulatorLink* link,
      EcShapeConstPointerMap& shapePointerMap,
      EcShapePointerVector& shapePointerVec
      );

   /// get the proximity database index for this shape
   virtual EcU32 proximityDatabaseIndex
      (
      ) const;

   /// set the proximity database index for this shape
   virtual void setProximityDatabaseIndex
      (
      const EcU32& index
      );

   /// set the BVH level IDs for this shape and all shapes above this
   /// in the BVH hierarchy
   virtual void mapBVHLevel
      (
      EcU32& bvhLevel
      );

   /// get the shape identifier
   virtual const EcString& identifier
      (
      )const;

   /// set the shape identifier
   virtual void setIdentifier
      (
      const EcString& identifier
      );

   /// set the level of this shape in the bounding volume hierarchy
   virtual void setBVHLevel
      (
      const EcU32& level
      );

   /// get the level of this shape in the bounding volume hierarchy
   virtual const EcU32& bvhLevel
      (
      )const;

   /// get capsule vector in primary frame of shape.  NOTE:
   /// unions will have more than one
   virtual void capsuleBoundingVolumeVectorInPrimary
      (
      EcXmlVectorType<EcCapsule>&  capsuleVec,
      EcU32Vector& shapeIDVec
      )const;

   /**
    * @brief Subdivide a triangle into 4.
    * @param[out] points vertices
    * @param[out] polys store indices for each triangles
    * @param[in] triIds the indices of triangle that will be subdivided
    * @param[in] level stop when level ==0
    * @return void
    */
   virtual void subdivide
      (
      EcXmlVectorVector& points,
      EcPolygonWithKeyVector&  polys,
      const EcU32*     triIds,
      const EcInt32    level
      ) const;

   /**
    * @brief Create polygon/mesh of a sphere.
    * @param[out] physExtent polygon and indices
    * @param[in] radius radius
    * @param[in] center center
    * @param[in] detailLevel detail level
    * @return void
    */
   virtual void icosahedron
      (
      EcBasePhysicalExtent& physExtent,
      const EcReal radius,
      const EcVector center,
      const EcU32  detailLevel
      ) const;

   /// gets surface property collection
   virtual const EcStringDataMapMap& surfaces
      (
      ) const;

   /// gets surface property collection non-const
   virtual EcStringDataMapMap& surfaces
      (
      );

   /// get the impacted surface given the index and point of intersection passed in
   virtual const EcString& impactedSurface
      (
      const EcU32 & pointIndex,
      const EcVector & point
      ) const;

   /// lookup a surface property for this shape using an EcString
   virtual EcBoolean lookup
      (
      const EcString& key,
      const EcDataMap*& surfProp
      ) const ;

   /// lookup a surface property for this shape using an EcXmlString (preferred method)
   virtual EcBoolean lookup
      (
      const EcXmlString& xmlKey,
      const EcDataMap*& surfProp
      ) const ;

   /// set the surface properties collection for this shape
   virtual void setSurfaces
      (
      const EcStringDataMapMap& surfaces
      );

   /// lower fidelity representation  (Non-Const)
   virtual EcShape* lowerFidelityRepresentation
      (
      ) ;

   /// higher fidelity representation (Non-Const)
   virtual EcShape* higherFidelityRepresentation
      (
      ) ;

   /// set the pointer to the stated system containing this shape
   virtual void setStatedSystem
      (
      const EcStatedSystem* ss
      );

   /// get the children for this shape
   /// return the children of this shape
   virtual const EcShapeConstPointerVector& children
      (
      )const;

   /// get support point ID (last calculated)
   virtual EcU32 supportPointID
      (
      ) const;

   /// set support point ID
   virtual void setSupportPointID
      (
      const EcU32 supportPointID
      );

   /// get the bypass dynamics flag
   virtual const EcBoolean& bypassDynamics
      (
      )const;

   /// set the bypass dynamics flag
   virtual void setBypassDynamics
      (
      const EcBoolean& flag
      );

   /// recursively collect child shape pointers
   virtual void collectChildPointers
      (
      EcShapeConstPointerVector& childrenPointerVector
      )const ;

   /// get the number of shapes that comprise this shape,
   /// this is always one for non-composite shapes
   virtual EcU32 numberOfShapes
      (
      )const;

   /// add the shape passeed in as a new bounding volume
   virtual void addExplicitBoundingVolume
      (
      const EcShape& shape
      );

   /// set the properties of the surface identified by key.
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

   /// get the collection of bounding volumes at level bvhLevel
   /// representing this shape
   virtual void boundingVolumes
      (
      EcShapeConstPointerVector& boundingVolumes,
      const EcU32 bvhLevel = 1
      )const ;

   /// gets capsule bounding volume
   virtual const EcCapsule& capsuleBoundingVolume
      (
      ) const;

   /// sets capsule bounding volume
   virtual void setCapsuleBoundingVolume
      (
      const EcCapsule& capsuleBoundingVolume
      );

   /// create a bounding shape for this shape
   virtual EcShape* createBoundingShape
      (
      const EcShapeValues& bv
      ) const;

   /// get aabb for shape (abstract)
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const = 0;

protected:
   /// detail value for some of the shapes
   EcXmlU32                      m_DetailLevel;

   /// a map of surface properties by string key
   mutable EcStringDataMapMap    m_Surfaces;

   /// contains the surface property of this shape (assumes homogeneous)
   EcXmlString                   m_SurfaceProperty;

   /// optional identifier for this shape
   EcXmlString                   m_ShapeIdentifier;

   /// flag indicating whether to bypass collision dynamics for this shape
   EcXmlBoolean                  m_BypassDynamics;

   /// a pointer to a low-fidelity representation of this shape
   EcShape*                      m_pLowerFidelityRepresentation;

   // Non-XML Data

   /// a pointer to the link containing this shape
   const EcStatedSystem*         m_pStatedSystem;

   /// a pointer to a physical extent representing this shape
   mutable EcBasePhysicalExtent* m_pPhysicalExtent;

   /// a higher-fidelity representation of this shape
   mutable EcShape*              m_pHigherFidelityRepresentation;

   /// indicates the level of this shape in the Bounding Volume Hierarchy
   mutable EcU32                 m_BVHLevel;

   /// a vector of pointers to shapes that are children of this shape
   mutable EcShapeConstPointerVector m_ChildrenPointerVector;

   /// the index of this shape into the proximity database
   mutable EcU32                 m_ProximityDatabaseIndex;

   /// the support point ID
   mutable EcU32                 m_SupportPointID;

   /// flag indicating whether the shape ID for this shape is valid
   mutable EcBoolean             m_IsShapeValid;

   /// the collision tolerance value, below which we conclude a collision
   /// has occurred
   static const EcReal           m_theCollisionTolerance;
   //----utility data declared for speed

   /// a default capsule bounding volume
   mutable EcCapsule*            m_pCapsuleBoundingVolume;

   /// utility string
   mutable EcXmlString           m_UtilityXmlString;
};

#endif // ecShape_H_
