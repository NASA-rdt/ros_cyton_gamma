#ifndef ecPolyPhysicalExtent_H_
#define ecPolyPhysicalExtent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPolyPhysicalExtent.h
/// @class EcPolyPhysicalExtent
/// @brief A class describing the physical extent of a link.  It
///        includes a description of the mesh and the surface
///        properties.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBasePhysicalExtent.h"
#include "ecPolygonWithKey.h"

// forward declarations
class EcBox;
class EcTriPhysicalExtent;

// XXX FIXME: selfTest requires access to protected methods.
namespace Ec { namespace test { class EcPolyPhysicalExtentTester; } }

/** Holds a description of a physical extent (surface) of a rigid body.
 This includes the polygons describing the surface and properties of the
 surface.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcPolyPhysicalExtent : public EcBasePhysicalExtent
{
public:
   /// default constructor
   EcPolyPhysicalExtent
      (
      );

   /// destructor
   virtual ~EcPolyPhysicalExtent
      (
      );

   /// copy constructor
   EcPolyPhysicalExtent
      (
      const EcPolyPhysicalExtent& orig
      );

   /// assignment operator
   EcPolyPhysicalExtent& operator=
      (
      const EcPolyPhysicalExtent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPolyPhysicalExtent& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const;

	/// cyc am not sure about this revisit
	virtual void physicalExtent
		(
			std::vector<EcBasePhysicalExtent*>& physExtent
		) const;

   /// set points pointer for all polygons
	virtual void setPointCollectionPointer
		(
		);

   /// sets the normals and polygons together, will be sorted immediately
   /// the normals must be set before the polygons, and this method ensures
   /// that.
   virtual void setNormalsAndPolygons
      (
      const EcXmlVectorVector& normals,
      const EcPolygonWithKeyVector& polygons
      );

   /// sets the normals and polygons together, polygons sorted
   /// already.  The normals must be set before the polygons,
   /// and this method ensures that.
   virtual void setNormalsAndPolygons
      (
      const EcXmlVectorVector& normals,
      const EcXmlStringPolygonVectorPairVector& surKeyPolysPairVec
      );

   /// Represent this PE as a group of triangles
   virtual const boost::shared_ptr<EcTriPhysicalExtent const> triPhysicalExtent
		(
		) const;

   /// get surface key polygon vector pair vector
	virtual const EcXmlStringPolygonVectorPairVector& surfKeyPolyVecPairVector
		(
		) const;

   /// set surface key polygon vector pair vector
	virtual void setSurfKeyPolyVecPairVector
		(
		const EcXmlStringPolygonVectorPairVector& surfKeyPolyVecPairVector
		);

	/// get number of groups
	virtual EcU32 numberOfGroups
		(
		) const;

	/// get number of polygons in a group
	virtual EcU32 numberOfFacetsInGroup
		(
		const EcU32& groupId
		) const;

	/// get number of points in a polygon
	virtual EcU32 numberOfPointsInFacet
		(
		const EcU32& groupId,
		const EcU32& facetId
		) const;

   /// get number of normals in a polygon
   virtual EcU32 numberOfNormalsInFacet
      (
      const EcU32& groupId,
      const EcU32& facetId
      ) const;

	/// get the point index of a polygon
	virtual EcU32 getFacetPointIndex
		(
		const EcU32& groupId,
		const EcU32& facetId,
		const EcU32& pointId
		) const;

	/// get the point index of a polygon without checking the bound.
	/// Use only if bounds checked beforehand.
	virtual EcU32 getFacetPointIndexNoCheck
		(
		const EcU32& groupId,
		const EcU32& facetId,
		const EcU32& pointId
		) const;

   /// get the normal index of a Facet
   virtual EcU32 getFacetNormalIndex
      (
      const EcU32& groupId,
      const EcU32& facetId,
      const EcU32& pointId
      ) const;

   /// get the normal index of a Facet without checking the bound.
   /// Use only if bounds checked beforehand.
   virtual EcU32 getFacetNormalIndexNoCheck
      (
      const EcU32& groupId,
      const EcU32& facetId,
      const EcU32& pointId
      ) const;

   /// get surface key of a group
   virtual const EcString& getGroupSurfaceKey
      (
      const EcU32& groupId
      ) const;

	/// get the plane of one facet
	virtual EcPlane getFacetPlane
	   (
		const EcU32& groupId,
		const EcU32& facetId
		) const;

	/**
	 * @brief Return a polygon given group and facet id
	 * @param[in] groupId group Id
	 * @param[in] facetId facet id
	 * @return const EcPolygon&
	 */
	const EcPolygon& getPolygon
		(
		const EcU32 groupId,
		const EcU32 facetId
		) const;

   /// check the facet intersection with a point
	virtual EcBoolean checkFacetIntersect
		(
		const EcU32 groupId,
		const EcU32 facetId,
		const EcVector& pt
		) const;

	/// check the facet intersection with a line
	virtual EcBoolean checkFacetIntersect
		(
		const EcU32 groupId,
		const EcU32 facetId,
		const EcLineSegment& line
		) const;

   /// gets capsule bounding volume
   virtual const EcCapsule& capsuleBoundingVolume
      (
      ) const;

   /// sets capsule bounding volume
   virtual void setCapsuleBoundingVolume
      (
      const EcCapsule& capsuleBoundingVolume
      );

   /// reorganize physical extent to improve performance
   virtual void optimizeForRendering
      (
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

   /// @copydoc EcShape::intersectLineSegment()
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
      ) const;

   /// @copydoc EcBasePhysicalExtent::intersectLineSegmentWithNormal()
   virtual void intersectLineSegmentWithNormal
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent,
      EcVector& normal
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

   /// returns the plane in which the polygon lies
   virtual EcPlane plane
      (
      ) const;

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
         const EcXmlVectorVector& points
      )  ;

   /// merge the other extent into this one.
   virtual void mergeWith
      (
      const EcBasePhysicalExtent& other
      );

	/// merge with another poly physical extent
	virtual void mergeWith
		(
		const EcPolyPhysicalExtent& other
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

   /// get an empty extent
   static EcPolyPhysicalExtent nullObject
      (
      );

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;

   /// the creator function for this object
   static EcXmlObject* creator
      (
      );

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// expand the capsule bounding volume if it exists.
   /// here for backwards compatibility
   virtual EcBoolean expandCapsule
      (
      );

   /// returns the impacted surface based on the points of intersection
   /// passed in.
   virtual EcString const& impactedSurface
      (
      const EcU32 & intPointIndex,
      const EcVector & point
      ) const;

   /// assign Neighbor Polygons Vec according to m_Polygons
   virtual EcBoolean findVertexNeighborFacetsVector
      (
      );

   /// Find the convex hull of the passed in points
   virtual EcBoolean convexHull
      (
      const EcXmlVectorVector& points
      );

	/// Find the convex hull of the points within this object. The resulting
	/// polyPhysicalExtent will have all the polygons in one group.
	virtual EcBoolean convexHull
		(
		);

   /**
    * @brief Best neighbor for support point calculation.
    * @param[in] v direction
    * @param[out] value value of dot product
    * @param[out] vertID best vert ID
    * @return EcBoolean
    */
   virtual EcBoolean bestNeighbor
      (
      const EcVector& v,
      EcReal& value,
      EcU32&  vertID
      ) const;


   /// get closest point ID given last support point and the closest point
   virtual EcU32 getClosestPointID
      (
      const EcVector& closestPoint,
      const EcU32&    pointID
      ) const;

   /// dump data out for matlab
   virtual EcBoolean dump
      (
      const EcString& filePath
      ) const;

   /// return the surface property for the physical extent
   virtual const EcString& surfaceProperty
      (
      ) const;


   /// set the surface property for the physical extent.
   /// NOTE this will set all the polygons to the surface
   /// property specified.
   virtual void setSurfaceProperty
      (
      const EcString& surfaceProp
      );

	/// set all polygons to default bounding color
   void setPolygonSurface
      (
      const EcString& surName
      );

   /// sort polygons by surface
   virtual EcBoolean sortPolys
      (
      const EcPolygonWithKeyVector& polygons
      );

   /// triangulize polygons. No new points will be introduced.
   ///               Assume all polygons are convex!
   virtual EcBoolean triangulize
      (
      EcTriPhysicalExtent& triPhy
      ) const;

protected:
   /// XXX FIXME: selfTest requires access to protected methods.
   friend class Ec::test::EcPolyPhysicalExtentTester;

   /// sets polygon collection, will be sorted immediately.  It
   /// is protected so that it will not be called before the
   /// normals are set
   virtual void setPolygons
      (
      const EcPolygonWithKeyVector& polygons
      );

	/// validate normals in each polygon
	virtual void validateNormals
		(
		);

   /// sorted surfaceKey,polyVector pair
   EcXmlStringPolygonVectorPairVector m_SurfKeyPolyVecPairVector;
};

/// A vector of PolyPhysicalExtent
typedef EcXmlVectorType<EcPolyPhysicalExtent> EcPolyPhysicalExtentVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the extent in a transformed frame.  xform expresses the old
/// representation frame in the new representation frame.
EC_FOUNDATION_GEOMETRY_DECL EcPolyPhysicalExtent transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcPolyPhysicalExtent& pe
   );

#endif // ecPolyPhysicalExtent_H_
