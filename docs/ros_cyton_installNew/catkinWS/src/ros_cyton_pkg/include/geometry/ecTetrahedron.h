#ifndef ecTetrahedron_H_
#define ecTetrahedron_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecTetrahedron.h
/// @class EcTetrahedron
/// @brief Describes a tetrahedron shape.  A tetrahedron is described
///        as V0 + s1*E1 + s2*E2 + s3*E3 where Ei = Vi - V0 and
///        s1+s2+s3 <=1
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBox.h"
#include "ecGeomTriangle.h"
#include "ecLineSegment.h"
#include "ecPlane.h"
#include "ecShape.h"

class EcAxisAlignedBoundingBox;

/// Holds a class to describe a tetrahedron
class EC_FOUNDATION_GEOMETRY_DECL EcTetrahedron : public EcShape
{
public:
   /// default constructor
   EcTetrahedron
      (
      );

   /// construct a tetrahedron from four points
   EcTetrahedron
      (
      const EcVector& V0,
      const EcVector& V1,
      const EcVector& V2,
      const EcVector& V3
      );

   /// destructor
   virtual ~EcTetrahedron
      (
      );

   /// copy constructor
   EcTetrahedron
      (
      const EcTetrahedron& orig
      );

   /// assignment operator
   EcTetrahedron& operator=
      (
      const EcTetrahedron& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTetrahedron& orig
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

   /// returns v0 ;
   virtual const EcVector& v0
      (
      ) const ;

   /// returns v1 ;
   virtual EcVector v1
      (
      ) const ;

   /// returns v2 ;
   virtual EcVector v2
      (
      ) const ;

   /// returns v3 ;
   virtual EcVector v3
      (
      ) const ;


   /// sets v0 ;
   virtual void setV0
      (
      const EcVector& vec
      )  ;

   /// sets v1 ;
   virtual void setV1
      (
      const EcVector& vec
      ) ;

   /// sets v2 ;
   virtual void setV2
      (
      const EcVector& vec
      )  ;

   /// sets v3 ;
   virtual void setV3
      (
      const EcVector& vec
      ) ;

   /// compute the vertices of the tetrahedron
   const EcVector* computeVertices
      (
      ) const;

   /// calculate center
   /// Must calculate vertices or faces first before calling this function.
   EcVector center
      (
      ) const;

   /// compute the edges and normals
   const EcLineSegment* computeEdges
      (
      EcVector* vNormals
      ) const;

   /**
    * @brief Compute the faces of the tetrahedron.
    * @details The faces (EcGeomTriangle) must be in the same order as planes
    * @return const EcGeomTriangle* a vector of faces of size 4
    */
   const EcGeomTriangle* computeFaces
      (
      ) const;

   /// returns true if the collection of points are properly inside the
   /// tetrahedron
   virtual EcBoolean isInside
      (
      const EcVectorVector& vPoints
      ) const ;

   /// scale the object by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleSelfBy
      (
      EcReal scaleFactor
      );

   /// transform the shape by the given coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// get the distance squared to a line segment
   /// returns zero if they are just touching or if they overlap.
   virtual EcReal distanceSquaredTo
      (
      const EcLineSegment& line
      ) const;

   /// get the distance to a line segment
   /// returns zero if they are just touching or if they overlap.
   virtual EcReal distanceTo
      (
      const EcLineSegment& line
      ) const;

   /// get the distance to a line segment
   /// returns zero if they are just touching or if they overlap.
   virtual EcReal distanceTo
      (
      const EcLineSegment& line,
      EcReal& lParam,
      EcVector& closest
      ) const;

   /// compute the distance to a plane
   EcReal distanceTo
      (
      const EcPlane& plane
      ) const;

   /// return the distance to the plane
   EcReal distanceTo
      (
      const EcPlane& plane,
      EcVector& closestOnTetra,
      EcVector& closestOnPlane
      ) const ;

   /// get the distance to a point
   /// returns zero if the point is on the surface of the
   /// capsule and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /// get the distance to a point and the closest point
   /// returns zero if the point is on the surface of the
   /// capsule and a negative number if it is inside.
   virtual EcReal distanceTo
      (
      const EcVector& vec,
      EcVector& closest
      ) const;

   /// compute the distance to a rectangle
   EcReal distanceTo
      (
      const EcRectangle& rectangle
      ) const ;

   /// compute the distance to a rectangle and the closest points
   EcReal distanceTo
      (
      const EcRectangle& rectangle,
      EcVector& closestTetra,
      EcVector& closestRect
      ) const ;

   /// compute the distance to a triangle
   EcReal distanceTo
      (
      const EcGeomTriangle& triangle
      ) const ;

   /// compute the distance to a triangle
   EcReal distanceTo
      (
      const EcGeomTriangle& triangle,
      EcVector& closestTetra,
      EcVector& closestTri
      ) const ;

   /// compute the distance to a disk
   EcReal distanceTo
      (
      const EcCircle& disk,
      EcVector& closestTetra,
      EcVector& closestDisk
      ) const ;

   /// get the distance to a bounding box
   virtual EcReal distanceTo
      (
      const EcBox& box,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestTetra,
      EcVector& closestBox
      ) const ;

   /// get the distance to a tetrahedron
   virtual EcReal distanceTo
      (
      const EcTetrahedron& other,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestThis,
      EcVector& closestOther
      ) const ;

   /**
   \copydoc EcShape::intersectLineSegment()
   */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
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

   /// check the intersect with a triangle
   EcReal checkIntersect
      (
      const EcGeomTriangle& triangle
      ) const;

   /// check the intersect with a rectangle
   EcReal checkIntersect
      (
      const EcRectangle& rectangle
      ) const;

   /// check the intersection between this shape and a plane
   virtual EcBoolean checkIntersect
      (
      const EcPlane& plane
      ) const;

   /// check the intersection with another tetrahedron
   virtual EcBoolean checkIntersect
      (
      const EcBox& box
      ) const;

   /// check the intersection with another tetrahedron
   virtual EcBoolean checkIntersect
      (
      const EcTetrahedron& other
      ) const;

   /// returns the four planes of the tetrahedron
   const EcPlane* planes
      (
      ) const;

   /// calculate the volume
   virtual EcReal volume
      (
      ) const;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
         const EcShape& shape
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

   /// get an empty polygon
   static EcTetrahedron nullObject
      (
      );

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
      const EcXmlVectorVector& points
      );

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

   /// get support point index given a vector
   virtual EcVector supportPoint
      (
      const EcVector& v
      ) const;

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const;


   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const;

   /// the creator function for this object
   static EcXmlObject* creator
      (
      ) ;

   /// returns a class token
   static const EcToken& classToken
      (
      ) ;

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

   /// given a point on the face, return the normal vector (pointing outward)
   virtual EcVector faceNormal
      (
      const EcVector& point
      ) const;

protected:
   /// vertex (V0).  The other three vertices can be derived by this and
   /// the corresponding edges
   EcXmlVector m_V0;

   /// V1 - V0
   EcXmlVector m_Edge1;

   /// V2 - V0
   EcXmlVector m_Edge2;

   /// V3 - V0
   EcXmlVector m_Edge3;

   /// internal collection of vertices, not needed but here for speed
   mutable EcVector m_vVertices[4];

   /// internal collection of planes, not needed but here for speed
   mutable EcPlane m_vPlanes[4];

   /// internal collection of edges, not needed but here for speed
   mutable EcLineSegment m_vEdges[6];

   /// internal collection of edge normals, not needed but here for speed
   mutable EcVector m_vNormals[12];

   /// internal collection of faces, not needed but here for speed
   mutable EcGeomTriangle m_vTris[4];
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the capsule into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcTetrahedron operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcTetrahedron& m
   );

#endif // ecTetrahedron_H_
