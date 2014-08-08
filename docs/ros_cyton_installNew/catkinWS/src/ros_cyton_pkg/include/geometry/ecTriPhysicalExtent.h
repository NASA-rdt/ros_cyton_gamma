#ifndef ecTriPhysicalExtent_H_
#define ecTriPhysicalExtent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecTriPhysicalExtent.h
/// @class EcTriPhysicalExtent
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
class EcColor;
class EcRectangle;

/** Holds a description of a physical extent (surface) of a rigid body.
 This includes the polygons describing the surface and properties of the
 surface.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcTriPhysicalExtent : public EcBasePhysicalExtent
{
public:
   /// default constructor
   EcTriPhysicalExtent
      (
      );

   /// destructor
   virtual ~EcTriPhysicalExtent
      (
      );

   /// copy constructor
   EcTriPhysicalExtent
      (
      const EcTriPhysicalExtent& orig
      );

   /// assignment operator
   EcTriPhysicalExtent& operator=
      (
      const EcTriPhysicalExtent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTriPhysicalExtent& orig
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

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent* physicalExtent
      (
      ) const;

   virtual const boost::shared_ptr<EcTriPhysicalExtent const> triPhysicalExtent
      (
      ) const;

   /// get polygon collection vector
   virtual const EcXmlStringTriangleVectorPairVector& surfKeyTriVecPairVector
      (
      ) const;

   /// set polygon collection vector
   virtual void setSurfKeyTriVecPairVector
      (
      const EcXmlStringTriangleVectorPairVector& SurfKeyTriVecPairVector
      );

   /// set points pointer for all triangles
   void setPointCollectionPointer
      (
      );

   /// get number of groups
   virtual EcU32 numberOfGroups
      (
      ) const;

   /// get number of triangles in a group
   virtual EcU32 numberOfFacetsInGroup
      (
      const EcU32& groupId
      ) const;

   /// get number of points in a triangle
   virtual EcU32 numberOfPointsInFacet
      (
      const EcU32& groupId,
      const EcU32& facetId
      ) const;

   /// get number of normals in a triangle
   virtual EcU32 numberOfNormalsInFacet
      (
      const EcU32& groupId,
      const EcU32& facetId
      ) const;

   /// get the point index of a triangle
   virtual EcU32 getFacetPointIndex
      (
      const EcU32& groupId,
      const EcU32& facetId,
      const EcU32& pointId
      ) const;

   /// get the point index of a triangle without checking the bound.
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

   /// get polygon
   virtual const EcPolygon& getPolygon
      (
      const EcU32 groupId,
      const EcU32 facetId
      ) const;

   /// get the plane of one facet
   virtual EcPlane getFacetPlane
      (
      const EcU32& groupId,
      const EcU32& facetId
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

   /// Find the convex hull of the passed in points.
   /// The resulting triangles will be in one group.
   virtual EcBoolean convexHull
      (
      const EcXmlVectorVector& points
      );

   /// Find the convex hull of the points within this object.
   /// The resulting triangles will be in one group.
   virtual EcBoolean convexHull
      (
      );

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const ;

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
      const EcTriPhysicalExtent& other
      );

   ///
   virtual void mergeWith
      (
      const EcBasePhysicalExtent& other
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// get an empty extent
   static EcTriPhysicalExtent nullObject
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

   /// returns the impacted surface based on the points of intersection
   /// passed in.
   virtual EcString const& impactedSurface
      (
      const EcU32 & intPointIndex,
      const EcVector & point
      ) const;

   /// set all polygons to default bounding color
   void setPolygonSurface
      (
      const EcString& surName
      );

   /// assign Neighbor Polygons Vec according to m_Polygons
   virtual EcBoolean findVertexNeighborFacetsVector
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

   /**
    * @brief Find the near neighbor for near vert id.
    * @param[in] oldID
    * @param[in] targetPos
    * @param[in] originalPointVector
    * @param[out] value new distance
    * @param[out] vertID new near vertex ID
    * @return EcBoolean
    */
   virtual EcBoolean nearNeighbor
      (
      const EcU32 oldID,
      const EcVector& targetPos,
      const EcXmlVectorVector& originalPointVector,
      EcReal& value,
      EcU32&  vertID
      ) const;

   /// Return the index of the vertex point that's nearest to tooltip
   virtual EcU32 pickNearestVertexIndex
      (
      const EcVector& toolTip,
      const EcXmlVectorVector& originalPointVector
      );

   /// Return the index of the vertex point that's nearest to tooltip
   virtual EcU32 getNearestVertexIndex
      (
      const EcU32& nearPtIndex,
      const EcVector& toolTip,
      const EcXmlVectorVector& originalPointVector
      );

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

   /// set all triangles to default bounding color
   void setTriSurface
      (
      const EcString& surName
      );

   /// sort polygons and store them as triangles.
   virtual EcBoolean sortPolys
      (
      const EcPolygonWithKeyVector& polygons
      );

   /// Description:  sets the normals and polygons together, will be sorted
   ///                immediately the normals must be set before the polygons,
   ///                and this method ensures that.
   void setNormalsAndPolygons
      (
      const EcXmlVectorVector& normals,
      const EcPolygonWithKeyVector& polygons
      );

   /// Description:   sets the normals and triangles together, the triangles already
   ///                sorted; the normals must be set before the triangles,
   ///                and this method ensures that.
   void setNormalsAndTriangles
      (
      const EcXmlVectorVector& normals,
      const EcXmlStringTriangleVectorPairVector& surfTrianglesPairVec
      );

   /// check whether or not the face has been changed
   virtual void checkModifiedFacetIndices
      (
      const EcXmlU32U32Pair& pair
      );

protected:
   /// validate normals in each triangle
   void validateNormals
      (
      );

   /**
    * @brief Check whether or not point is within triangle.
    * @param[in] pt point for test
    * @param[in] p1 point1 of triangle
    * @param[in] p2 point2 of triangle
    * @param[in] p3 point3 of triangle
    * @param[in] normal normal of triangle
    * @return EcBoolean
    */
   virtual EcBoolean pointIsWithinTriangle
      (
      const EcVector& pt,
      const EcVector& p1,
      const EcVector& p2,
      const EcVector& p3,
      const EcVector& normal
      ) const;

   /**
    * @brief Check whether edge intersect with triangle.
    * @param[in] p1 point1 of edge
    * @param[in] p2 point2 of edge
    * @param[in] v1 vertex1 of triangle
    * @param[in] v2 vertex2 of triangle
    * @param[in] v3 vertex3 of triangle
    * @param[in] normal normal of triangle
    * @param[in] d distance of triangle from origin
    * @param[out] contactPoint
    * @return EcBoolean
    */
   virtual EcBoolean edgeIntersectsWithTriangle
      (
      const EcVector& p1,
      const EcVector& p2,
      const EcVector& v1,
      const EcVector& v2,
      const EcVector& v3,
      const EcVector& normal,
      const EcReal& d,
      EcVector& contactPoint
      ) const;

   /// sorted by material triangle groups
   EcXmlStringTriangleVectorPairVector m_SurfKeyTriVecPairVector;

   /// a utility polygon
   mutable EcPolygon m_UtilPolygon;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the extent in a transformed frame.  xform expresses the old
/// representation frame in the new representation frame.
EC_FOUNDATION_GEOMETRY_DECL EcTriPhysicalExtent
transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcTriPhysicalExtent& pe
   );

#endif // ecTriPhysicalExtent_H_
