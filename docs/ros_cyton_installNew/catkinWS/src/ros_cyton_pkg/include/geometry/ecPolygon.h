#ifndef ecPolygon_H_
#define ecPolygon_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPolygon.h
/// @class EcPolygon
/// @brief A polygon class.  It holds a list of indices into a
///        vertex list, as well as a surface property string.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlane.h"
#include "ecTriangle.h"
#include <xml/ecXmlVectorVector.h>
#include <xml/ecXmlPairType.h>

class EcGeomTriangle;
class EcRectangle;

/** Holds a class to describe a 3D polygon.  All vertices are
 defined through indices into a vector of points.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcPolygon : public EcXmlObject
{
public:
   /// xml object methods
   ECXMLOBJECT(EcPolygon);
   /// declaration for accept(EcXmlObjectVisitor*)
   ECXMLOBJECT_ACCEPT(EcPolygon)

   /// clear all data to initial state (empty polygon with null surface key)
   virtual void clear
      (
      );

   /// clears 3D index data to initial state (empty polygon) surface key remains
   virtual void clearIndices
      (
      );

   /// clears point index data
   virtual void clearPointIndices
      (
      );

   /// reserve space for the point indices
   virtual void reservePointIndices
      (
      EcU32 size
      );

   /// vararg method to set point indices.  Use with great care.
   /// The first entry is the number of indices.  Then the specified number
   /// of indices follows.  For example, to make a triangle, the first number
   /// must be "3".
   virtual void setPointIndices
      (
      EcU32 numIndices,...
      );

   /// add a new point index
   virtual void addPointIndex
      (
      const EcU32 index
      );

   /// get a point index by order
   virtual EcU32 pointIndex
      (
      EcU32 order
      ) const;

   /// clears normal index data
   virtual void clearNormalIndices
      (
      );

   /// reserve space for the normal indices
   virtual void reserveNormalIndices
      (
      EcU32 size
      );

   /// vararg method to set normal indices.  Use with great care.
   /// The first entry is the number of indices.  Then the specified number
   /// of indices follows.  For example, for a triangle, the first number
   /// must be "3".
   virtual void setNormalIndices
      (
      EcU32 numIndices,...
      );

   /// add a new normal index
   virtual void addNormalIndex
      (
      const EcU32 index
      );

   /// get a normal index by order
   virtual EcU32 normalIndex
      (
      EcU32 order
      ) const;

   /// clears raster index data to initial state (empty)
   virtual void clearRasterMapIndices
      (
      );

   /// reserve space for the raster map indices
   virtual void reserveRasterMapIndices
      (
      EcU32 size
      );

   /// vararg method to set raster map indices.  Use with great care.
   /// The first entry is the number of indices.  Then the specified number
   /// of indices follows.  For example, to make a triangle, the first number
   /// must be "3".
   virtual void setRasterMapIndices
      (
      EcU32 numIndices,...
      );

   /// add a new raster map index
   virtual void addRasterMapPointIndex
      (
      const EcU32 index
      );

   /// get a raster map index by order
   virtual EcU32 rasterMapIndex
      (
      EcU32 index
      ) const;

   /// get the number of points
   virtual EcU32 numPoints
      (
      ) const;

   /// get the number of defined normals
   virtual EcU32 numNormals
      (
      ) const;

   /// get the point corresponding to the index (index)
   virtual const EcVector& point
      (
         EcU32 index
      ) const ;

   /// set the pointer to the point collection
   virtual void setPointCollectionPointer
      (
        const EcXmlVectorVector* points
      ) ;

   /// get the pointer to the point collection
   virtual const EcXmlVectorVector* pointCollectionPointer
      (
      ) const ;

   /// get the number of raster map points
   virtual EcU32 numRasterPoints
      (
      ) const;

   /// rotate the vertices left by the value specified
   /// So, for increment 1, vertex1 becomes vertex0, and so forth
   virtual void leftRotateVertices
      (
      EcU32 amount=1
      );

   /// distance to a triangle
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& tri
      ) const;

   /// distance to a polygon
   virtual EcReal distanceTo
      (
      const EcPolygon& poly
      ) const;

   /// compute the distance to a line segment
   virtual EcReal distanceTo
      (
      const EcLineSegment& seg
      ) const;

   /// compute the distance to a point
   virtual EcReal distanceTo
      (
      const EcVector& pnt
      ) const;

   /// check intersection with another polygon
   virtual EcBoolean checkIntersect
      (
      const EcPolygon& otherPolygon
      ) const;

   /// check intersection with a triangle
   virtual EcBoolean checkIntersect
      (
      const EcGeomTriangle& tri
      ) const;

   /// check intersect with a line
   virtual EcBoolean checkIntersect
      (
      const EcLineSegment& line
      ) const;

   /// check intersect with a point
   virtual EcBoolean checkIntersect
      (
      const EcVector& point
      ) const;

   /// distance to a rectangle
   virtual EcReal distanceTo
      (
      const EcRectangle& rec
      ) const;

   /// return the plane containing the polygon
   virtual EcPlane plane
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

   /// get an empty polygon
   static EcPolygon nullObject
      (
      );

   /// 
   /**
    * @brief Dump buffer to a file for debugging.
    * @param[in] polys vector vector
    * @param[in] fileName file name
    * @return EcBoolean
    */
   static EcBoolean dump
      (
      const EcXmlVectorType<EcPolygon> polys,
      const char* fileName
      );

	/**
	 * @brief Triangulize this polygon.
	 * @param[in] triangles vector of triangles
	 * @return EcBoolean
	 */
	virtual EcBoolean triangulize
		(
		EcTriangleVector& triangles
		) const;

   /// return if normal is valid
	virtual const EcBoolean normalValid
		(
		const EcU32& numNormal
		) const;

	/**
	 * @brief Calculate the surface normal for this polygon, from 3 vertices.
	 * @param[in] points
	 * @param[in] vNormal
	 * @param[in] normalIndex same as poly id
	 * @return EcBoolean
	 */
	virtual EcBoolean calculateNormal
		(
		const EcXmlVectorVector& points,
		EcVector& vNormal,
		const EcU32& normalIndex
		);

protected:

   /// reads the array from an xml data stream
   virtual void readIndexArray
      (
      EcU32*& indices,
      EcU16&  numIndices,
      EcU16&  reservedNumIndices,
      EcXmlReader& stream
      );

   /// writes the array to an xml data stream
   virtual EcBoolean writeIndexArray
      (
      const EcU32* const& indices,
      const EcU16&  numIndices,
      EcXmlWriter& stream
      ) const;

protected:
   /// the vector of integer indices for the 3D polygon vertices
   EcU32* m_pPointIndices;
   /// number of integer indices for the 3D polygon vertices
   EcU16  m_NumPointIndices;
   /// reserved number of integer indices for the 3D polygon vertices
   EcU16  m_ReservedNumPointIndices;

   /// the optional vector of integer indices for the vertex normals
   EcU32* m_pNormalIndices;
   /// number of optional vector of integer indices for the vertex normals
   EcU16  m_NumNormalIndices;
   /// number of reserved optional vector of integer indices for the vertex normals
   EcU16  m_ReservedNumNormalIndices;

   /// the vector of integer indices for the raster map points
   EcU32* m_pRasterMapPointIndices;
   /// number of integer indices for the raster map points
   EcU16  m_NumRasterMapPointIndices;
   /// number of reserved integer indices for the raster map points
   EcU16  m_ReservedNumRasterMapPointIndices;

   /// a pointer to the point collection
   const EcXmlVectorVector* m_pPointCollection;
};

/// A vector of polygons
typedef EcXmlVectorType<EcPolygon> EcPolygonVector;

/// A vector of polygon vectors
typedef EcXmlVectorType<EcPolygonVector> EcPolygonVectorVector;

/// A vector of EcPolygonVectorVector
typedef EcXmlVectorType<EcPolygonVectorVector> EcPolygonVector3D;

/// a pair of a string and a vector of polygons
typedef EcXmlPairType<EcXmlString,EcPolygonVector> EcXmlStringPolygonVectorPair;

/// a vector of the above pair
typedef EcXmlVectorType<EcXmlStringPolygonVectorPair> EcXmlStringPolygonVectorPairVector;

#endif // ecPolygon_H_
