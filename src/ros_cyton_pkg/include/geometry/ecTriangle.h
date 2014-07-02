#ifndef ecTriangle_H_
#define ecTriangle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecTriangle.h
/// @class EcTriangle
/// @brief A tiangle class.  It holds a list of indices into a
///        vertex list,
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlane.h"
#include <xml/ecXmlObject.h>
#include <xml/ecXmlPairType.h>

class EcBasePhysicalExtent;
class EcGeomTriangle;
class EcLineSegment;
class EcPolygon;
class EcRectangle;
class EcXmlVectorVector;
class EcPolygonWithKey;

/** Holds a class to describe a 3D polygon.  All vertices are
 defined through indices into a vector of points.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcTriangle : public EcXmlObject
{
public:
   /// default constructor
   EcTriangle
      (
      );

   /// destructor
   virtual ~EcTriangle
      (
      );

   /// copy constructor
   EcTriangle
      (
      const EcTriangle& orig
      );

   /// assignment operator
   EcTriangle& operator=
      (
      const EcTriangle& orig
      );

   /// assignment operator
   EcTriangle& operator=
      (
      const EcPolygonWithKey& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTriangle& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// set point indices.
   virtual void setPointIndices
      (
      const EcU32& indexX,
      const EcU32& indexY,
      const EcU32& indexZ
      );

   /// get a point index by order
   virtual EcU32 pointIndex
      (
      EcU32 order
      ) const;

   /// set normal indices.
   virtual void setNormalIndices
      (
      const EcU32& indexX,
      const EcU32& indexY,
      const EcU32& indexZ
      );

   /// get a normal index by order
   virtual EcU32 normalIndex
      (
      EcU32 order
      ) const;

   /// set raster map indices.
   virtual void setRasterMapIndices
      (
      const EcU32& indexX,
      const EcU32& indexY,
      const EcU32& indexZ
      );

   /// get a raster map index by order
   virtual EcU32 rasterMapIndex
      (
      EcU32 order
      ) const;

   /// get the number of points
   virtual EcU32 numPoints
      (
      ) const;

   /// get the number of defined normals
   virtual EcU32 numNormals
      (
      ) const;

   /// get the point corresponding to the index
   virtual const EcVector& point
      (
      EcU32 index
      ) const;

   /// set the pointer to the point collection
   virtual void setPointCollectionPointer
      (
      const EcXmlVectorVector* points
      );

   /// get the pointer to the point collection
   virtual const EcXmlVectorVector* pointCollectionPointer
      (
      ) const;

   /// get the number of raster map points
   virtual EcU32 numRasterPoints
      (
      ) const;

   /// distance to a triangle
   virtual EcReal geomTriangleDistanceTo
      (
      const EcGeomTriangle& tri
      ) const;

   /// distance to a polygon
   virtual EcReal polygonDistanceTo
      (
      const EcPolygon& poly
      ) const;

   /// distance to another triangle (not GeomTriangle)
   virtual EcReal triangleDistanceTo
      (
      const EcTriangle& tri
      ) const;

   /// compute the distance to a line segment
   virtual EcReal lineSegmentDistanceTo
      (
      const EcLineSegment& seg
      ) const;

   /// compute the distance to a point
   virtual EcReal pointDistanceTo
      (
      const EcVector& pnt
      ) const;

   /// distance to a rectangle
   virtual EcReal rectangleDistanceTo
      (
      const EcRectangle& rec
      ) const;

   /// check intersection with another triangle
   virtual EcBoolean triangleCheckIntersect
      (
      const EcTriangle& otherTriangle
      ) const;

   /// check intersection with a triangle
   virtual EcBoolean geomTriangleCheckIntersect
      (
      const EcGeomTriangle& tri
      ) const;

   /// check intersect with a line
   virtual EcBoolean lineSegmentCheckIntersect
      (
      const EcLineSegment& line
      ) const;

   /// check intersect with a point
   virtual EcBoolean pointCheckIntersect
      (
      const EcVector& point
      ) const;

   /// return the plane containing the triangle
   virtual EcPlane plane
      (
      ) const;

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

   /// write schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// get an empty triangle
   static EcTriangle nullObject
      (
      );

   /// render this triangle
   void render
      (
      const EcBoolean textureMapping,
      const EcBasePhysicalExtent& phy //store verts, normal,texture coord
      ) const;

   /// check the validity of the triangle
   virtual const EcBoolean normalValid
      (
      const EcU32 numNormals = 3
      ) const;

   /**
    * @brief calculate the surface normal for this triangle from 3 vertices.
    * @param[in] points
    * @param[out] vNormal
    * @param[in] normalIndex same as poly id
    * @return EcBoolean
    */
   virtual EcBoolean calculateNormal
      (
      const EcXmlVectorVector& points,
      EcVector& vNormal,
      const EcU32& normalIndex
      );

   /// calculate the area of single triangle
   static EcReal calculateAreaOfTriangle
      (
      const EcVector& pt0,
      const EcVector& pt1,
      const EcVector& pt2
      );

   /// calculate the normal of single triangle
   static EcVector calculateNormalOfTriangle
      (
      const EcVector& pt0,
      const EcVector& pt1,
      const EcVector& pt2
      );

protected:

   /// reads the array from an xml data stream
   virtual void readIndexArray
      (
      EcU32*  indices,
      EcXmlReader& stream
      );

   /// writes the array to an xml data stream
   virtual EcBoolean writeIndexArray
      (
      const EcU32*  const& indices,
      const EcU16&  numIndices,
      EcXmlWriter& stream
      ) const;

protected:

   /// the vector of integer indices for the 3D polygon vertices
   EcU32 m_vPointIndices[3];

   /// the optional vector of integer indices for the vertex normals
   EcU32 m_vNormalIndices[3];

   /// the vector of integer indices for the raster map points
   EcU32 m_vRasterMapPointIndices[3];

   /// a pointer to the point collection
   const EcXmlVectorVector* m_pPointCollection ;
};

/// A vector of triangles
typedef EcXmlVectorType<EcTriangle> EcTriangleVector;

/// A vector of triangle vectors
typedef EcXmlVectorType<EcTriangleVector> EcTriangleVectorVector;

/// A vector of EcTriangleVectorVector
typedef EcXmlVectorType<EcTriangleVectorVector> EcTriangleVector3D;

/// a pair of a string and a vector of polygons
typedef EcXmlPairType<EcXmlString,EcTriangleVector> EcXmlStringTriangleVectorPair;

/// a vector of the above pair
typedef EcXmlVectorType<EcXmlStringTriangleVectorPair> EcXmlStringTriangleVectorPairVector;

#endif // ecTriangle_H_
