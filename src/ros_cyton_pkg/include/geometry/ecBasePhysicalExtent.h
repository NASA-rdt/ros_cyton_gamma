#ifndef ecBasePhysicalExtent_H_
#define ecBasePhysicalExtent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecBasePhysicalExtent.h
/// @class EcBasePhysicalExtent
/// @brief A base class describing the physical extent of a link.  It
///        includes a description of the mesh and the surface
///        properties.
/// @details Holds a description of a physical extent (surface) of a rigid body.
///          This includes the polygons describing the surface and properties of the
///          surface.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecCapsule.h"
#include "ecLineAndNeighbors.h"
#include "ecShape.h"
#include "ecGeometryOverwriteDescriptor.h"
#include <foundCommon/ecPlanarVector.h>
#include <xml/ecXmlCompType.h>
#include <boost/weak_ptr.hpp>

class EcAxisAlignedBoundingBox;
class EcTriPhysicalExtent;

namespace osg { class Node; }

/// Holds a description of a physical extent (surface) of a rigid body.
/** This includes the polygons describing the surface and properties of the
 surface.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcBasePhysicalExtent : public EcShape
{
public:
   /// neighbor flags
   typedef struct EcNeighborFlags
   {
      /// facet vert
      EcBoolean m_FacetVert;
      /// vert facet
      EcBoolean m_VertFacet;
      /// vert vert
      EcBoolean m_VertVert;
      /// vert line
      EcBoolean m_VertLine;
      /// line facet
      EcBoolean m_LineFacet;
      /// facet line
      EcBoolean m_FacetLine;
      /// vert normal
      EcBoolean m_VertNormal;
      /// line normal
      EcBoolean m_LineNormal;
      /// facet normal
      EcBoolean m_FacetNormal;
   } EcNeighborFlags;

   /// A pair of EcU32
   typedef std::pair<EcU32,EcU32> EcU32Pair;

   /// A vector of pairs of EcU32
   typedef std::vector<EcU32Pair> EcU32PairVector;

   /**
    * @brief Default constructor.
    */
   EcBasePhysicalExtent
      (
      );

   /**
    * @brief Destructor.
    */
   virtual ~EcBasePhysicalExtent
      (
      );

   /**
    * @brief Copy constructor.
    * @param[in] orig the object to be copied
    */
   EcBasePhysicalExtent
      (
      const EcBasePhysicalExtent& orig
      );

   /**
    * @brief Assignment operator.
    * @param[in] orig the object to be assigned from
    * @return EcBasePhysicalExtent& this
    */
   EcBasePhysicalExtent& operator=
      (
      const EcBasePhysicalExtent& orig
      );

   /**
    * @brief Equality operator.
    * @param[in] orig
    * @return EcBoolean
    */
   EcBoolean operator==
      (
      const EcBasePhysicalExtent& orig
      ) const;

   /**
    * @brief Clone - a virtual constructor to an EcXmlObject pointer.
    * @return EcXmlObject*
    */
   virtual EcXmlObject* clone
      (
      ) const = 0;

   /**
    * @brief Register components with the parent.
    * @return void
    */
   virtual void registerComponents
      (
      );

   /**
    * @brief Equality - virtual equality to an EcXmlObject pointer.
    * @param[in] other
    * @return EcBoolean
    */
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /**
    * @brief Virtual new that returns an EcXmlObject.
    * @return EcXmlObject*
    */
   virtual EcXmlObject* newObject
      (
      ) const = 0;

   /**
    * @brief Gets convexity flag.
    * @return EcBoolean
    */
   virtual EcBoolean isConvex
      (
      ) const;

   /**
    * @brief Reset all the neighbor flags to false.
    * @return void
    */
   void resetNeighborFlags
      (
      );

   /**
    * @brief Sets convexity flag.
    * @param[in] value
    * @return void
    */
   virtual void setIsConvex
      (
      EcBoolean value=EcTrue
      );

   /**
    * @brief Gets 3D point collection.
    * @return const EcXmlVectorVector&
    */
   virtual const EcXmlVectorVector& points
      (
      ) const;

   /**
    * @brief Sets 3D point collection.
    * @param[in] points
    * @return void
    */
   virtual void setPoints
      (
      const EcXmlVectorVector& points
      );

   /**
    * @brief Get the point corresponding to the index
    * @param[in] index index into the point vector
    * @return const EcVector&
    */
   virtual const EcVector& point
      (
         EcU32 index
      ) const;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
         const EcShape& shape
      );

   /// truncate values in the physical extents to the precision specified
   virtual void truncateValues
      (
      const EcReal& precision
      );

   /**
    * @brief Get a physical extent from the top shape in the CSG tree.
    * @details NOTE: This is for backward compatibility
    * @return EcBasePhysicalExtent*
    */
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const = 0;

   /// All subclasses need to be able to reduce everything to triangles.
   virtual const boost::shared_ptr<EcTriPhysicalExtent const> triPhysicalExtent
      (
      ) const = 0;

   /// gets normal collection
   virtual const EcXmlVectorVector& normals
      (
      ) const;

   /// sets normal collection
   virtual void setNormals
      (
      const EcXmlVectorVector& normals
      );

   /// gets raster-map point collection
   virtual const EcPlanarVectorVector& rasterMapPoints
      (
      ) const;

   /// sets raster-map point collection
   virtual void setRasterMapPoints
      (
      const EcPlanarVectorVector& rasterMapPoints
      );

   /// get modified facet indices
   virtual const EcXmlU32U32PairVector& modifiedFacetIndices
      (
      ) const;

   /// set modified facet indices
   virtual void setModifiedFacetIndices
      (
      const EcXmlU32U32PairVector& modifiedFacetIndices
      );

	/// initialize the modified facet indices
	virtual void initModifiedFacetIndices
		(
		);

	/// gets the vector of the polygon change descriptor
	virtual const EcGeometryOverwriteDescriptor& geometryOverwriteDescriptor
		(
		)const;

	/// gets the vector of the modified shape key (non const version)
	virtual EcGeometryOverwriteDescriptor& geometryOverwriteDescriptor
		(
		);

	/// sets the vector of the modified shape key
	virtual void setGeometryOverwriteDescriptor
		(
		const EcGeometryOverwriteDescriptor& geometryOverwriteDescriptor
		);

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const =0;

   /// gets capsule bounding volume
   virtual const EcCapsule& capsuleBoundingVolume
      (
      ) const;

   /// sets capsule bounding volume
   virtual void setCapsuleBoundingVolume
      (
      const EcCapsule& capsuleBoundingVolume
      );

   /// normalize the points in a physical extent
   virtual void normalizePoints
      (
      );

   /// transform the extent into a new coordinate system
   /// xform represents the old reference frame in the new
   /// reference frame
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// scale the object by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleSelfBy
      (
      EcReal scaleFactor
      );

   /// scale the object by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleSelfBy
      (
      EcReal xScaleFactor,
      EcReal yScaleFactor,
      EcReal zScaleFactor
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
      const EcLineSegment& line
      ) const = 0;

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcVector& point
      ) const = 0;

   /// Same as EcShape::intersectLineSegment(const EcLineSegment&, EcShapePointEvent&) except that
   /// it also returns the normal of the surface at the intersection
   virtual void intersectLineSegmentWithNormal
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent,
      EcVector& normal
      ) const = 0;

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// merge the other extent into this one.
   virtual void mergeWith
      (
      const EcBasePhysicalExtent& other
      ) = 0;

   /// expand the capsule bounding volume if it exists.
   /// here for backwards compatibility
   virtual EcBoolean expandCapsule
      (
      );

   /// get support point given a vector
   virtual EcVector supportPoint
      (
      const EcVector& v
      ) const;

   /// returns the impacted surface based on the points of intersection
   /// passed in.
   EcString const& impactedSurface
      (
      const EcU32 & intPointIndex,
      const EcVector & point
      ) const = 0;

   /// gets neighbor pair Vec 2D
   virtual const EcXmlU32U32PairVectorVector& vertexNeighborFacetsVector
      (
      ) const;

   /// sets neighbor Facets Vec
   virtual void setVertexNeighborFacetsVector
      (
      const EcXmlU32U32PairVectorVector& vertexNeighborFacetsVector
      );

   /// gets line and its neighbors
   virtual const EcLineAndNeighborsVector& lineAndNeighborsVector
      (
      ) const;

   /// sets line and its neighbors
   void setLineAndNeighborsVector
      (
      const EcLineAndNeighborsVector& lineAndNeighborsVector
      );

   /// get the tip point index
   virtual const EcU32& tipPointIndex
      (
      ) const;

   /// set the tip point index
   virtual void setTipPointIndex
      (
      const EcU32& tipPointIndex
      );

   /// get the end point index
   virtual const EcU32& endPointIndex
      (
      ) const;

   /// set the end point index
   virtual void setEndPointIndex
      (
      const EcU32& endPointIndex
      );

   /// find vertex's Neighbor facets
   virtual EcBoolean findVertexNeighborFacetsVector
      (
      )=0;

   /// find the convex hull of the passed in physical extent
   virtual EcBoolean convexHull
      (
      const EcXmlVectorVector& points
      )=0;

   /// best neighbor for support point calculation.
   virtual EcBoolean bestNeighbor
      (
      const EcVector& v,   // direction
      EcReal& value,       // value of dot product
      EcU32&  vertID       // best vert ID
      ) const = 0;

   /// Return the index of the vertex point that's nearest to tooltip
   virtual EcU32 pickNearestVertexIndex
      (
      const EcVector& toolTip,
      const EcXmlVectorVector& originalPointVector
      );

   /// check whether or not the face has been changed
   virtual void checkModifiedFacetIndices
      (
      const EcXmlU32U32Pair& pair
      );

   /// dump data out for matlab
   virtual EcBoolean dump
      (
      const EcString& filePath
      ) const;

   /// get number of groups
   virtual EcU32 numberOfGroups
      (
      ) const = 0;

   /// get number of Facets in a group
   virtual EcU32 numberOfFacetsInGroup
      (
      const EcU32& groupId
      ) const = 0;

   /// get number of points in a Facet
   virtual EcU32 numberOfPointsInFacet
      (
      const EcU32& groupId,
      const EcU32& facetId
      ) const = 0;

   /// get number of normals in a polygon
   virtual EcU32 numberOfNormalsInFacet
      (
      const EcU32& groupId,
      const EcU32& facetId
      ) const = 0;

   /// return total number of facets, sum of all groups
   virtual EcU32 totalNumberOfFacets
      (
      ) const;

   /// get support point ID (last calculated)
   virtual EcU32 supportPointID
      (
      ) const;

   /// get closest point ID given last support point and the closest point
   virtual EcU32 getClosestPointID
      (
      const EcVector& closestPoint,
      const EcU32&    pointID
      ) const = 0;

   /// get the point index of a Facet
   virtual EcU32 getFacetPointIndex
      (
      const EcU32& groupId,
      const EcU32& facetId,
      const EcU32& pointId
      ) const = 0;

   /// get the point index of a Facet without checking the bound.
   /// Use only if bounds checked beforehand.
   virtual EcU32 getFacetPointIndexNoCheck
      (
      const EcU32& groupId,
      const EcU32& facetId,
      const EcU32& pointId
      ) const = 0;

   /// get the normal index of a Facet
   virtual EcU32 getFacetNormalIndex
      (
      const EcU32& groupId,
      const EcU32& facetId,
      const EcU32& pointId
      ) const = 0;

   /// get the normal index of a Facet without checking the bound.
   /// Use only if bounds checked beforehand.
   virtual EcU32 getFacetNormalIndexNoCheck
      (
      const EcU32& groupId,
      const EcU32& facetId,
      const EcU32& pointId
      ) const = 0;

   /// get surface key of a group
   virtual const EcString& getGroupSurfaceKey
      (
      const EcU32& groupId
      ) const = 0;

   /// get the plane of one facet
   virtual EcPlane getFacetPlane
      (
      const EcU32& groupId,
      const EcU32& facetId
      ) const = 0;

   /// check the facet intersection with a point
   virtual EcBoolean checkFacetIntersect
      (
      const EcU32 groupId,
      const EcU32 facetId,
      const EcVector& pt
      ) const = 0;

   /// check the facet intersection with a line
   virtual EcBoolean checkFacetIntersect
      (
      const EcU32 groupId,
      const EcU32 facetId,
      const EcLineSegment& line
      ) const = 0;

   /// return a Facet given group and facet id
   virtual const EcPolygon& getPolygon
      (
      const EcU32 groupId,
      const EcU32 facetId
      ) const = 0;

   /// set points pointer for all facets
   virtual void setPointCollectionPointer
      (
      )=0;

   /// return the surface property for the physical extent
   virtual const EcString& surfaceProperty
      (
      ) const = 0;

   /// set the surface property for the physical extent.
   /// NOTE this will set all the polygons to the surface
   /// property specified.
   virtual void setSurfaceProperty
      (
      const EcString& surfaceProp
      )=0;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
         const EcXmlVectorVector& points
      );

   /// initialize normal and neighbor data
   virtual void init
      (
      );

   /// return if is modified
   virtual EcBoolean isModified
      (
      ) const;

   /// get vector of vertex's neighbor vertices (indexed)
   virtual const EcXmlU32VectorVector&   vertexNeighborVerticesVector
      (
      ) const;

   /// set vector of vertex's neighbor vertices (indexed)
   virtual void setVertexNeighborVerticesVector
      (
      const EcXmlU32VectorVector&   vertexNeighborVerticesVector
      );

   /// get vector of vertex's neighbor lines (indexed)
   virtual const EcXmlU32VectorVector& vertexNeighborLinesVector
      (
      ) const;

   /// set vector of vertex's neighbor lines (indexed)
   virtual void setVertexNeighborLinesVector
      (
      const EcXmlU32VectorVector& vertexNeighborLinesVector
      );

   /// get vector of Facet's neighbor lines
   virtual const EcXmlU32Vector3D& facetNeighborLinesVector
      (
      ) const;

   /// set vector of Facet's neighbor lines
   virtual void setFacetNeighborLinesVector
      (
      const EcXmlU32Vector3D& facetNeighborLinesVector
      );

   /// get the normal vector of facet
   virtual const EcXmlVectorVectorVector& normalsOfFacets
      (
      ) const;

   /// set the normal vector of facet
   virtual void setNormalsOfFacets
      (
      const EcXmlVectorVectorVector& normalsOfFacets
      );

   /// get normal of points
   virtual const EcXmlVectorVector& normalsOfPoints
      (
      ) const;

   /// set normal of points
   virtual void setNormalsOfPoints
      (
      const EcXmlVectorVector& normalsOfPoints
      );

   /// get the normal vector of lines
   virtual const EcXmlVectorVector& normalsOfLines
      (
      ) const;

   /// set the normal vector of lines
   virtual void setNormalsOfLines
      (
      const EcXmlVectorVector& normalsOfLines
      );

   /// gets the bool to clean up the modified
   virtual const EcBoolean& modIsCleanedUp
      (
      ) const;

   /// sets the bool to clean up the modified
   virtual void setModIsCleanedUp
      (
      const EcBoolean& value
      );

   /// find the vertices's neighbor vertices.
   virtual EcBoolean findVertexNeighborVertices
      (
      );

   /// Description:  find lines and their neighbors (poly or tri and vertices index)
   virtual EcBoolean findLineAndNeighbors
      (
      );

   /// find the vertices' neighbor lines
   virtual EcBoolean findVertexNeighborLines
      (
      );

   /// find Facet's Neighbor lines
   virtual EcBoolean findFacetNeighborLinesVector
      (
      );

   /// find normals of facets
   virtual EcBoolean findNormalOfFacets
      (
      );

   /// find normals of points
   virtual EcBoolean findNormalOfPoints
      (
      );

   /// find normals of lines
   virtual EcBoolean findNormalOfLines
      (
      );

   /// get render node
   virtual boost::weak_ptr<osg::Node> getRenderNode
      (
      ) const;

   /// set render node
   virtual void setRenderNode
      (
      boost::shared_ptr<osg::Node> node
      ) const;

   /// get all the used point indices
   virtual void usedPoints
      (
      EcXmlVectorVector& pointVector
      ) const;


   virtual const EcToken& token
      (
      ) const;

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:
   /// recalculate the capsule bounding volume to enclose all points
   /// returns true if there were any points
   virtual EcBoolean recalculateCapsule
      (
      );

   /// validate normals in each facet
   virtual void validateNormals
      (
      )=0;

   /// initialize normal and neighbor data
   virtual void initNeighborInformation
      (
      );

   /// a flag indicating convexity for the link surface
   EcXmlBoolean                   m_IsConvex;

   /// a vector of polygon 3D vertices
   EcXmlVectorVector              m_Points;

   /// an optional vector of polygon vertex normals
   EcXmlVectorVector              m_Normals;

   /// a vector of UV coordinates into raster data
   EcPlanarVectorVector           m_RasterMapPoints;

   /// flags indicating status of neighbor information calculation.
   EcNeighborFlags                m_NeighborFlags;

   /// a default capsule bounding volume
   mutable EcCapsule              m_CapsuleBoundingVolume;

   /// flag indicating whether the capsule has been sized yet
   mutable EcBoolean              m_IsCapsuleSet;

   /// a vector of neighbor Facets of a vertex
   EcXmlU32U32PairVectorVector    m_VertexNeighborFacetsVector;

   /// vector of lines and its neighbor information
   EcLineAndNeighborsVector       m_LineAndNeighborsVector;

   /// a vector of vertex's neighbor vertices (indexed)
   EcXmlU32VectorVector           m_VertexNeighborVerticesVector;

   /// a vector of vertex's neighbor lines (indexed)
   EcXmlU32VectorVector           m_VertexNeighborLinesVector;

   /// Facet's neighbor lines
   EcXmlU32Vector3D               m_FacetNeighborLinesVector;

   /// normal vector of vertices
   EcXmlVectorVector              m_NormalsOfPoints;

   /// normal vector of Lines
   EcXmlVectorVector              m_NormalsOfLines;

   /// normal vector of Facets
   EcXmlVectorVectorVector        m_NormalsOfFacets;

   /// a default material type
   static const EcString          m_TheNullMaterialType;

   /// the point index that representing the whole object.
   EcXmlU32                       m_TipPointIndex;

   /// the end point index that use in line segment with m_TipPointIndex.
   EcXmlU32                       m_EndPointIndex;

   /// a vector indicating if a vert has been visited
   mutable EcBooleanVector        m_VertVisitedVector;

   /// a vector indicating if a vert has been visited in the previous round
   mutable EcBooleanVector        m_VertVisitedPrevVector;

   /// a utility string
   mutable EcString               m_UtilString;

   /// flag indicating whether the underlying geometry has been modified since
   /// the last query.
   mutable EcBoolean              m_IsModified;

   /// vector storing the modified facet's indices
   EcXmlU32U32PairVector          m_ModifiedFacetIndices;

   /// Opaque pointer for rendering purposes.
   mutable boost::weak_ptr<osg::Node> m_pRenderNode;

   /// vector storing the polygon change descriptor
   EcGeometryOverwriteDescriptor  m_GeometryOverwriteDescriptor;

   /// bool to clean up the modification
   EcBoolean                      m_ModIsCleanedUp;
};

#endif // ecBasePhysicalExtent_H_
