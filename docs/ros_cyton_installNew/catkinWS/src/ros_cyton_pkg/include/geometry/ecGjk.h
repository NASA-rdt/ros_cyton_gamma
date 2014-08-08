#ifndef ecGjk_H_
#define ecGjk_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGjk.h
/// @class EcGJK
/// @brief Implementation of GJK algorithm for distance calculation
///        between convex objects.  The primary method is distane(),
///        which calculates the distance between any two shapes with
///        positions and orientations.  A flag determines whether or
///        not penetration distance is calculated when the two shapes
///        overlap.  The closest points on the two objects are also
///        returned.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecConvexHull.h"
#include "ecGjkTriangle.h"
#include <foundCore/ecVector.h>
#include <matrixUtilities/ecReArray.h>

// forward declarations
class EcCoordinateSystemTransformation;
class EcShape;
class EcPhysicalExtent;

/// Holds a  class that implements the GJK algorithm for distance (including penetration distance) calculations.
class EC_FOUNDATION_GEOMETRY_DECL EcGJK
{
public:
   /// constructor
	EcGJK
      (
      );

   /// destructor
	virtual ~EcGJK
      (
      );

   /// copy constructor
   EcGJK
      (
      const EcGJK& orig
      );

   /// assignment operator
   EcGJK& operator=
      (
      const EcGJK& orig
      );

   /// equal operator
   virtual EcBoolean operator==
      (
      const EcGJK& orig
      ) const;

   /// calculate the distance and closest points for two shapes.
   /**
   Calculate the distance and closest points between two convex shapes A and B.
   \param[in] A The first convex shape
   \param[in] B The second convex shape
   \param[in] AToW The transformation from A to World
   \param[in] BToW The transformation from B to World
   \param[in] calPenDistanceFlag If the flag is set, penetration distance is calculated for intersecting shapes.
   \param[out] pA The closest point in A in local coordinates
   \param[out] pB The closest point in B in local coordinates
   \param[out] dist The distance between A and B (negative if penetrating)
   \param[out] pVec Optionally use this vector as initial direction. Default to NULL
   */
   virtual EcBoolean distance
      (
      const EcShape& A,
      const EcShape& B,
      const EcCoordinateSystemTransformation& AToW,
      const EcCoordinateSystemTransformation& BToW,
      const EcBoolean calPenDistanceFlag,
      EcVector& pA,
      EcVector& pB,
      EcReal& dist,
      EcVector* pVec=0
      );

   /// get function tolerance
   virtual const EcReal& tolerance
      (
      ) const;

   /// set function tolerance
   virtual void setTolerance
      (
      const EcReal tol
      );

   /// set max number of iteration for penetration distance calculation
   virtual void setMaxIterations
      (
      const EcU32 maxIterations
      );

   /// get max number of iteration for penetration distance calculation
   virtual EcU32 maxIterations
      (
      ) const;

protected:
   /// update the dot product buffer
   virtual void updateDotProduct
      (
      );

   /// update the dot product and sub determinate matrix
   virtual void updateSubDeterminants
      (
      );

   /// detect a repeat point
   virtual EcBoolean repeatPoint
      (
      const EcVector& w
      ) const;

   /// calculate the simplex containing the closest vector and return the vector
   virtual EcBoolean closestInUnion
      (
      EcVector& v
      ) ;

   /// determine if the set is the minimum convex hull containing the closest vector
   virtual EcBoolean minConvex
      (
      EcInt32 set
      ) const;

   /// compute the closest points
   virtual void pointsInLocal
      (
      const EcInt32 setBits,
      EcVector& pA,
      EcVector& pB
      ) const;

   /// find the closest point of the convex hull of set bits
   virtual void closestPoint
      (
      EcU32 bits,
      EcVector& v
      ) const;

   /// find the closest vector to an edge
   virtual EcBoolean vectorToEdge
      (
      const EcInt32 vID1,
      const EcInt32 vID2,
      EcVector& v
      ) const;

   /// split an edge of a triangle
   virtual EcBoolean splitEdge
      (
      const EcShape& A,
      const EcShape& B,
      const EcCoordinateSystemTransformation& AToW,
      const EcCoordinateSystemTransformation& BToW,
      const EcInt32 triID,
      const EcInt32 edgeID
      );

   /// closest distance to a triangle.
   virtual EcBoolean distanceToTriangle
      (
      EcGJKTriangle& tri
      );

   /// calculate the penetration distance
   virtual EcBoolean penetration
      (
      const EcShape& A,
      const EcShape& B,
      const EcCoordinateSystemTransformation& AToW,
      const EcCoordinateSystemTransformation& BToW,
      EcVector& pointA,
      EcVector& pointB,
      EcVector& distV
      );

   /// edge of a polyhedron shared by 2 triangles.
   /// Given one and find another.
   virtual EcBoolean edgeSharedBy
      (
      const EcInt32 triID,
      const EcInt32 edgeID,
      EcInt32&      triID2,
      EcInt32&      edgeID2
      ) const;

   /// split a triangle
   virtual EcBoolean splitTriangle
      (
      const EcShape&  A,
      const EcShape&  B,
      const EcCoordinateSystemTransformation& AToW,
      const EcCoordinateSystemTransformation& BToW,
      const EcInt32   triID,
      const EcVector& v,
      const EcReal    minDist,
      const EcBoolean initFlag = EcFalse
      );

   /// reset variables for new computation
   virtual void reset
      (
      );

   /// reset important variables for new penetration computation
   virtual void resetPenetration
      (
      );

   /// compare Grammer's inverse with direct inverse (for debuging)
   virtual void debugInverse
      (
      const EcInt32 sub
      ) const;

   /// save the last valid state
   virtual void saveCache
      (
      ) const;

   /// restore from last valid state
   virtual void restoreFromCache
      (
      );

   /// dump current state to a file for debug
   virtual void dump
      (
      const EcString& filename
      ) const;

   /// dump current simplex to a file for debug
   virtual void dumpSimplex
      (
      const EcString& filename
      ) const;

   /**
    * @brief Calculate distance from the origin to a triangle formed by 3 points.
    * @param[in] x0 vertex 0
    * @param[in] x1 vertex 1
    * @param[in] x2 vertex 2
    * @param[in] ifPlanar planar distance only, skip edge and vert
    * @return EcReal
    */
   virtual EcReal distanceToTriangle
      (
      const EcVector& x0,
      const EcVector& x1,
      const EcVector& x2,
      const EcBoolean ifPlanar=EcFalse
      ) const;

   /// store collection of each point's neighbor triangles
   virtual EcBoolean assignNeighborTrisVec
      (
      );

protected:
   /// support points of object A
   EcVector    m_A[4];
   /// support points of object B
   EcVector    m_B[4];
   /// support points of A - B in world coordinates
   EcVector    m_W[4];

   /// store current simplex
   EcInt32     m_Simplex;
   /// store new found support point
   EcInt32     m_New;
   /// bit version of m_New (=2^m_New)
   EcInt32     m_NewBit;
   /// m_Simplex|m_NewBit
   EcInt32     m_Union;

   /// cached sub-determinants for Cramer's rule
   EcReal      m_Det[16][4];
   /// cached dot product
   EcReal      m_DP[4][4];
   /// for stopping criteria
   EcReal      m_Tolerance;
   /// if spliting with at least one triangle valid.
   EcBoolean   m_Dividable;

   /// for penetration:
   /// store the triangles
   std::vector<EcGJKTriangle> m_Triangles;
   /// store the triangles (cache last)
   std::vector<EcGJKTriangle> m_TrianglesC;
   /// vertices of A-B
   EcVectorVector             m_VerticesAMinusB;
   /// vertices in A
   EcVectorVector             m_VerticesA;
   /// vertices in B
   EcVectorVector             m_VerticesB;
   /// max number of iteration for penetration
   EcU32                      m_MaxIterations;
   /// collection of each point's neighbor triangles
   EcU32VectorVector          m_NeighborTrisVec;
   /// keep track of m_NeighborTrisVec size
   EcU32                      m_NTrisVecSize;

   /// the following variables are used to redue memory allocation, deallocation.
   /// triangle vector initially allocates this much memory
   EcU32                m_InitNumTri;
   /// initial buffer size for vertices
   EcU32                m_InitNumVert;

   /// the following are temporary matrices and vectors used for penetration calculation
   /// temp 3x3 matrix
   mutable EcReArray      m_A3;
   /// temp 4x4 matrix
   mutable EcReArray      m_A4;
   /// temp vector of length 3
   mutable EcRealVector   m_B3;
   /// temp vector of length 4
   mutable EcRealVector   m_B4;
   /// temp vector of length 3
   mutable EcRealVector   m_X3;
   /// temp vector of length 4
   mutable EcRealVector   m_X4;
   /// temp matrix
   mutable EcReArray      m_ATemp;
   /// temp vector
   mutable EcRealVector   m_BTemp;
   /// temp vector
   mutable EcRealVector   m_XTemp;
   /// utility qhull
   mutable EcConvexHull   m_QHull;
   /// temp GJK triangle
   mutable EcGJKTriangle  m_GJKTri;

   /// cache last valid set
   /// support points of object A
   mutable EcVector    m_AC[4];
   /// support points of object B
   mutable EcVector    m_BC[4];
   /// support points of A - B in world coordinates
   mutable EcVector    m_WC[4];

   /// store current simplex
   mutable EcInt32     m_SimplexC;
   /// store new found support point
   mutable EcInt32     m_NewC;
   /// bit version of m_New (=2^m_New)
   mutable EcInt32     m_NewBitC;
   /// m_Simplex|m_NewBit
   mutable EcInt32     m_UnionC;
   /// a vector of indices
   mutable EcU32Vector m_vIndices;
};

#endif // ecGjk_H_
