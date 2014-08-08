#ifndef ecGridPhysicalExtent_H_
#define ecGridPhysicalExtent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecGridPhysicalExtent.h
/// @class EcGridPhysicalExtent
/// @brief A class describing the physical extent of a grid.  It
///        includes a description of the mesh and the surface
///        properties.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBasePhysicalExtent.h"
#include "ecBrick.h"

class EcAxisAlignedBoundingBox;

/** A class describing the physical extent of a grid.  It
    includes a description of the mesh and the surface
    properties.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcGridPhysicalExtent : public EcBasePhysicalExtent
{
public:
   /// default constructor
   EcGridPhysicalExtent
      (
      );

   /// destructor
   virtual ~EcGridPhysicalExtent
      (
      );

   /// copy constructor
   EcGridPhysicalExtent
      (
      const EcGridPhysicalExtent& orig
      );

   /// assignment operator
   EcGridPhysicalExtent& operator=
      (
      const EcGridPhysicalExtent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGridPhysicalExtent& orig
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
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const;

	/// cyc am not sure about this revisit
	virtual void physicalExtent
		(
			std::vector<EcBasePhysicalExtent*>& physExtent
		) const;

   /// Represent this PE as a group of triangles
   virtual const boost::shared_ptr<EcTriPhysicalExtent const> triPhysicalExtent
		(
		) const;

   /// set points pointer for all polygons
	virtual void setPointCollectionPointer
		(
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

   /// get number of points in a polygon
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

   /// get the distance to a triangle
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& tri
      ) const;

   /// get the distance to a rectangle
   virtual EcReal distanceTo
      (
      const EcRectangle& rec
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
      const EcLineSegment& line
      ) const;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcVector& point
      ) const;

   /// check the intersection with triangle
   virtual EcBoolean checkIntersect
      (
      const EcGeomTriangle& tri
      ) const;

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// merge the other extent into this one.
   virtual void mergeWith
      (
      const EcBasePhysicalExtent& other
      );

	/// merge with another poly physical extent
	virtual void mergeWith
		(
		const EcGridPhysicalExtent& other
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
   static EcGridPhysicalExtent nullObject
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

   /// get bricks
   virtual const EcBrickVector& bricks
      (
      ) const;

   /// set bricks
   virtual void setBricks
      (
      const EcBrickVector& vBrick
      );

   /// set lut table
   virtual void setLutTable
      (
      const EcXmlVectorVector &lutTable
      );

   /// get lut table
   virtual const EcXmlVectorVector &lutTable
      (
      ) const;

   /**
    * @brief Get volume values.
    * @param[out] lutScale
    * @param[out] minSize
    * @param[out] maxSize
    * @param[out] cellSize
    * @param[out] inflection
    * @return void
    */
   virtual void getVolumeValues
      (
      EcReal   &lutScale,
      EcVector &minSize,
      EcVector &maxSize,
      EcVector &cellSize,
      EcVector &inflection
      ) const;

   /**
    * @brief Set volume values.
    * @param[in] lutScale
    * @param[in] minSize
    * @param[in] maxSize
    * @param[in] cellSize
    * @param[in] inflection
    * @return void
    */
   virtual void setVolumeValues
      (
      const EcReal   &lutScale,
      const EcVector &minSize,
      const EcVector &maxSize,
      const EcVector &cellSize,
      const EcVector &inflection
      );

   /// set data format
   virtual void setDataFormat
      (
      const EcU32 format
      );

   /// get data format
   virtual EcU32 dataFormat
      (
      ) const;

   /// get real pointer to data
   virtual const EcReal* getData
      (
      ) const;

   /// get point size
   virtual EcU32 pointSize
      (
      ) const;

   /// get brick size
   virtual EcU32 brickSize
      (
      ) const;

   /// get data size
   virtual EcU32 dataSize
      (
      ) const;

protected:

	/// validate normals in each polygon
	virtual void validateNormals
		(
		);

   /// brick vector
   EcBrickVector                  m_vBrick;

   /// data array pointer
   mutable EcReal*                m_pData;
   /// data size
   mutable EcU32                  m_DataSize;
   /// data format
   mutable EcXmlU32               m_DataFormat;

   /// a utility polygon
	mutable EcPolygon					 m_UtilPolygon;
   /// lut scale
   mutable EcXmlReal              m_LutScale;
   /// min size
   mutable EcXmlVector            m_MinSize;
   /// max size
   mutable EcXmlVector            m_MaxSize;
   /// cell size
   mutable EcXmlVector            m_CellSize;
   /// inflection
   mutable EcXmlVector            m_Inflection;
   /// lut table
   mutable EcXmlVectorVector      m_LutTable;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the extent in a transformed frame.  xform expresses the old
/// representation frame in the new representation frame.
EC_FOUNDATION_GEOMETRY_DECL EcGridPhysicalExtent transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcGridPhysicalExtent& pe
   );

#endif // ecGridPhysicalExtent_H_
