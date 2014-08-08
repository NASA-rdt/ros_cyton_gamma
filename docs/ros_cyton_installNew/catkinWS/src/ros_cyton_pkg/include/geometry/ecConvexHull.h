#ifndef ecConvexHull_H_
#define ecConvexHull_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecConvexHull.h
/// @class EcConvexHull
/// @brief implementation of a qhull wrapper class.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPolygon.h"
#include "ecGjkTriangle.h"
#include <xml/ecXmlVectorVector.h>
#include "ecTriangle.h"

/// Holds a wrapper class for implementing qHull--the convex hull generating algorithm
class EC_FOUNDATION_GEOMETRY_DECL EcConvexHull
{
public:
   /// constructor
   EcConvexHull
      (
      );

   /// destructor
   virtual ~EcConvexHull
      (
      );

   /**
    * @brief Calculating convex hull of the input points.
    * @param[in] points original points
    * @param[in] convexFlagVec flag indicating if one vert belong to the convex hull
    * @return EcBoolean
    */
   virtual EcBoolean computeConvexHull
      (
      const EcXmlVectorVector& points,
      EcBooleanVector& convexFlagVec
      ) const;

   /**
    * @brief Calculating convex hull of the input points.
    * @param[in] points original points
    * @param[in] convexPoints points of the convex hull
    * @return EcBoolean
    */
   virtual EcBoolean computeConvexHull
      (
      const EcXmlVectorVector& points,
      EcXmlVectorVector& convexPoints
      ) const;

   /**
    * @brief Another wrapper to the qHull method.
    * @param[in] vectors
    * @param[in] triangles
    * @param[in] pConvexFlagVec flag indicating if one vert belong to the convex hull
    * @return EcBoolean
    */
   virtual EcBoolean computeConvexHull
     (
     const EcVectorVector& vectors,
     std::vector<EcGJKTriangle>& triangles,
     EcBooleanVector* pConvexFlagVec=EcNULL
     ) const;

   /**
    * @brief Compute convex hull of input vertices. Used by poly physical extent.
    * @param[in] points original points
    * @param[in] polygons new polygons
    * @return EcBoolean
    */
   virtual EcBoolean computeConvexHull
      (
      const EcXmlVectorVector& points,
      EcPolygonVector& polygons
      ) const;

   /**
    * @brief Compute convex hull of input vertices. Used by tri physical extent.
    * @param[in] points original points
    * @param[in] triangles new triangles
    * @return EcBoolean
    */
   virtual EcBoolean computeConvexHull
      (
      const EcXmlVectorVector& points,
      EcTriangleVector& triangles
      ) const;

   /**
    * @brief Compute convex hull of the input 2D points.
    * @details This version returns the vertices ids that are used for constructing the convex hull.
    * @param[in] points original points
    * @param[in] numPoints number of points
    * @param[in] convexVertIds vertex id of the points on the convex hull
    * @return EcBoolean
    */
   virtual EcBoolean compute2DConvexHull
      (
      const EcReal* points,
      const EcU32&  numPoints,
      EcU32Vector&  convexVertIds
      ) const;

   /// qhull method for computing convex hull
   virtual void qHull
      (
      EcReal *points,
      EcInt32 numPoints,
      EcInt32 dim,
      EcInt32 *&faces,
      EcInt32 &numFaces
      ) const;

   /// qhull method for computing convex hull
    virtual void qHull
      (
      EcReal *points,
      EcInt32 numPoints,
      EcInt32 *&faces,
      EcInt32 &numFaces
      ) const;

protected:
   /// array of faces
   mutable EcInt32* m_pFacesArray;
   /// size of the array of faces
   mutable EcU32    m_FacesArraySize;
   /// array of points
   mutable EcReal*  m_pPointsArray;
   /// size of the array of points
   mutable EcU32    m_PointsArraySize;
   /// temp vector of EcBoolean
   mutable EcBooleanVector  m_TempBoolVec;
};

#endif // ecConvexHull_H_
