#ifndef ecTruncatedIcosahedron_H_
#define ecTruncatedIcosahedron_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecTruncatedIcosahedron.h
/// @class EcTruncatedIcosahedron
/// @brief Provides a tool for operating with a truncated
///        icosahedron, or buckyball, a three-dimensional polytope with 60 vertices,
///        90 edges, 12 pentagon faces, and 20 hexagon faces.  All vertices lie on
///        the surface of a sphere.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCore/ecConstants.h>
#include <foundCore/ecVector.h>
#include <xml/ecXmlVectorType.h>

// XXX FIXME: selfTest requires access to protected methods.
namespace Ec { namespace test { class EcTruncatedIcosahedronTester; } }

/** Provides a tool for operating with a truncated
 icosahedron, or buckyball, a three-dimensional polytope with 60 vertices,
 90 edges, 12 pentagon faces, and 20 hexagon faces.  All vertices lie on
 the surface of a sphere.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcTruncatedIcosahedron
{
public:
   /// dimensions
   enum{NUM_VERTICES=60,
        NUM_EDGES=90,
        NUM_FACES=32,
        NUM_PENTAGONS=12,
        NUM_HEXAGONS=20};

   /// a number specifying an invalid sample
   enum{INVALID=0xFFFFFFFF};

   /// default constructor
   EcTruncatedIcosahedron
      (
      );

   /// destructor
   virtual ~EcTruncatedIcosahedron
      (
      );

   /// copy constructor
   EcTruncatedIcosahedron
      (
      const EcTruncatedIcosahedron& orig
      );

   /// assignment operator
   EcTruncatedIcosahedron& operator=
      (
      const EcTruncatedIcosahedron& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTruncatedIcosahedron& orig
      ) const;

   /// get vertex from its global index
   virtual EcVector vertex
      (
      EcU32 index
      ) const;

   /// get a global vertex index from an edge and its local index (0,1)
   virtual EcU32 edgeVertexIndex
      (
      EcU32 edgeIndex,
      EcU32 vertexIndex
      ) const;

   /// get a vertex from an edge and a local index (0,1)
   virtual EcVector edgeVertex
      (
      EcU32 edgeIndex,
      EcU32 vertexIndex
      ) const;

   /// get the edges emanating from a vertex
   virtual const EcU32Vector& vertexEdges
      (
      EcU32 vertexIndex
      ) const;

   /// get the edge orientations for edges emanating from a vertex
   /// true means the vertex is the first for the edge, false means
   /// it is the second.
   virtual const EcBooleanVector& vertexEdgeOrientations
      (
      EcU32 vertexIndex
      ) const;

   /// get the neighbors of an edge
   virtual const EcU32Vector& edgeNeighbors
      (
      EcU32 edgeIndex
      ) const;

   /// get a global edge index from a pentagon and a local edge index (0,1,2,3,4)
   virtual EcU32 pentagonEdgeIndex
      (
      EcU32 pentagonIndex,
      EcU32 edgeIndex
      ) const;

   /// get a global edge index from a hexagon and a local edge index (0,1,2,3,4,5)
   virtual EcU32 hexagonEdgeIndex
      (
      EcU32 hexagonIndex,
      EcU32 edgeIndex
      ) const;

   /// get a vertex from a pentagon and a local vertex index (0,1,2,3,4)
   virtual EcVector pentagonVertex
      (
      EcU32 pentagonIndex,
      EcU32 vertexIndex
      ) const;

   /// get a vertex from a hexagon and a local vertex index (0,1,2,3,4,5)
   virtual EcVector hexagonVertex
      (
      EcU32 hexagonIndex,
      EcU32 vertexIndex
      ) const;

   /// edge length--the length of each edge in the 600-cell
   static EcReal edgeLength
      (
      );

protected:
   /// XXX FIXME: selfTest requires access to protected methods.
   friend class Ec::test::EcTruncatedIcosahedronTester;

   /// setup vertices, edgeds, triangles, and tetrahedrons
   virtual EcBoolean setup
      (
      );

   /// add a cuboid to a vertex list.  This takes every combination
   /// of +/- the vector entries.  It is assumed that the vertices
   /// vector has been correctly sized.
   virtual void addCuboid
      (
      EcVectorVector& vertices,
      EcU32& index,
      const EcVector& vector
      ) const;

protected:
   /// the following data is always the same
   /// vertices
   EcVectorVector        m_Vertices;
   /// edges
   EcU32VectorVector     m_Edges;
   /// pentagon edges
   EcU32VectorVector     m_PentagonEdges;
   /// hexagon edges
   EcU32VectorVector     m_HexagonEdges;
   /// vertex edges
   EcU32VectorVector     m_VertexEdges;
   /// vertex edge orientations
   EcBooleanVectorVector m_VertexEdgeOrientations;
   /// edge neighbors
   EcU32VectorVector     m_EdgeNeighbors;
};

#endif // ecTruncatedIcosahedron_H_
