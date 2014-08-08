#ifndef ecBox_H_
#define ecBox_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBox.h
/// @class EcBox
/// @brief A description for a 3D oriented bounding box
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLineSegment.h"
#include "ecRectangle.h"
#include "ecShape.h"
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlVectorVector.h>

// forward declarations
class EcPlane;
class EcRectangle;
class EcGeomTriangle;
class EcStatedSystem;
class EcAxisAlignedBoundingBox;

/// Holds a class to describe a 3D oriented bounding box.
class EC_FOUNDATION_GEOMETRY_DECL EcBox : public EcShape
{
public:
   /// default constructor
   /// Constructs a Box of dimension (0.1, 0.1, 0.1) units
   EcBox
      (
      );

   /// constructor from a center, axes and extents
   EcBox
   (
      const EcVector& center,
      const EcXmlVectorVector& axes,
      const EcVector& extents
   );

   /// constructor from a coordinate system transformation and extents
   EcBox
   (
      const EcCoordinateSystemTransformation& xform,
      const EcVector& extents
   );

   /// destructor
   virtual ~EcBox
      (
      );

   /// copy constructor
   EcBox
      (
      const EcBox& orig
      );

   /// assignment operator
   EcBox& operator=
      (
      const EcBox& orig
      );

   /// operator= for AABB
   virtual EcBox& operator=
      (
      const EcAxisAlignedBoundingBox& aabb
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBox& orig
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

   /// get extents
   const EcVector& extents
      (
      ) const;

   /// set extents
   virtual void setExtents
      (
      const EcVector& extents
      );

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

   /// return the distance to the plane
   EcReal distanceTo
      (
      const EcPlane& plane
      ) const ;

   /// return the distance to the plane
   EcReal distanceTo
      (
      const EcPlane& plane,
      EcVector& closestOnBox,
      EcVector& closestOnPlane
      ) const ;

   /// get primary frame
   virtual const EcCoordinateSystemTransformation& primaryFrame
      (
      ) const;

   /// set primary frame
   virtual void setPrimaryFrame
      (
      const EcCoordinateSystemTransformation& primaryFrame
      );

   /// get center
   virtual const EcVector& center
      (
      ) const;

   /// set center
   virtual void setCenter
      (
      const EcVector& center
      );

  /// set axes
  virtual void setAxes
      (
         const EcXmlVectorVector& axes
      );

  /// expand this shape to fit this collection of points
  virtual void fitToPoints
      (
         const EcXmlVectorVector& points
      )  ;

   /**
    * @brief Get the distance to a line segment.
    * @details Returns zero if they intersect.
    * @param[in] lineSeg a line segment
    * @return EcReal distance
    */
   virtual EcReal distanceTo
      (
      const EcLineSegment& lineSeg
      ) const;

   /**
    * @brief Get the distance to a point.
    * @see distanceTo(const EcVector&, EcVector&) const
    * @param[in] pt point
    * @return EcReal distance
    */
   virtual EcReal distanceTo
      (
      const EcVector& pt
      ) const;

   /**
    * @brief Get the distance to a point and the closest point on the box
    * @details Returns zero if the point is on the surface of the
    *          box and a negative number if it is inside. In this case, the
    *          closest point on the box is the same as the input point
    * @param[in] pt point
    * @param[out] closest closest point on the box
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcVector& pt,
      EcVector& closest
      ) const;

   /**
    * @brief Compute the distance to a triangle.
    * @see distanceTo(const EcGeomTriangle&, EcVector&, EcVector&) const
    * @param[in] triangle
    * @return EcReal distance
    */
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle
      ) const;

   /**
    * @brief Compute the distance to a triangle and the closest points.
    * @details Returns zero if they intersect.
    * @param[in] triangle
    * @param[out] closestBox closest point on the box
    * @param[out] closestTri closest point on the triangle
    * @return EcReal distance
    */
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle,
      EcVector& closestBox,
      EcVector& closestTri
      ) const;

   /**
    * @brief Compute the distance to a rectangle.
    * @see distanceTo(const EcRectangle&, EcVector&, EcVector&) const
    * @param[in] rectangle
    * @return EcReal
    */
   virtual EcReal distanceTo
      (
      const EcRectangle& rectangle
      ) const ;

   /**
    * @brief Compute the distance to a rectangle and the closest points.
    * @details Returns zero if they intersect.
    * @param[in] rectangle
    * @param[out] closestBox closest point on the box
    * @param[out] closestRect closest point on the rectangle
    * @return EcReal distance
    */
   virtual EcReal distanceTo
      (
      const EcRectangle& rectangle,
      EcVector& closestBox,
      EcVector& closestRect
      ) const ;

   /**
    * @brief Compute the distance to a disk and the closest points.
    * @details Returns zero if they intersect.
    * @param[in] disk
    * @param[out] closestBox closest point on the box
    * @param[out] closestDisk closest point on the disk
    * @return EcReal distance
    */
   virtual EcReal distanceTo
      (
      const EcCircle& disk,
      EcVector& closestBox,
      EcVector& closestDisk
      ) const ;

   /**
    * @brief Get the distance to another bounding box.
    * @param[in] other
    * @param[in] xform transformation from other to this
    * @param[out] closestThis closest point on this box to the other in this frame
    * @param[out] closestOther closest point on the other box to this in the other frame
    * @return EcReal positive distance if no intersection, otherwise 0.
    */
   virtual EcReal distanceTo
      (
      const EcBox& other,
      const EcCoordinateSystemTransformation& xform,
      EcVector& closestThis,
      EcVector& closestOther
      ) const ;

   /**
    * @brief compute the distance squared to a point, return the closest point on the box to the point.
    * @details Returns zero if they intersect (the point is on or in the box).
    * @param[in] point
    * @param[out] closest closest point on the box
    * @return EcReal distance
    */
   virtual EcReal distanceSquaredTo
      (
      const EcVector& point,
      EcVector& closest
      ) const;

   /**
    * @brief Compute the distance squared to a line segment, return the closest point.
    * @details Returns zero if they intersect.
    * @param[in] seg line segment input
    * @param[out] lParm the point on the line
    * @param[out] closestPoint closest point on the box
    * @return EcReal distance
    */
   virtual EcReal distanceSquaredTo
      (
      const EcLineSegment& seg,
      EcReal& lParm,
      EcVector& closestPoint
      ) const;

   /**
    * @brief Compute the distance squared to a line, return the closest point.
    * @details Returns zero if they intersect.
    * @param[in] seg line segment input
    * @param[out] lParm the point on the line
    * @param[out] closestPoint closest point on the box
    * @return EcReal distance
    */
   virtual EcReal distanceSquaredToLine
      (
      EcLineSegment seg,
      EcReal& lParm,
      EcVector& closestPoint
      ) const;

   /// check the intersection with triangle
   EcBoolean checkIntersect
      (
      const EcGeomTriangle& rect
      ) const;

   /// check the intersection with rectangle
   EcBoolean checkIntersect
      (
      const EcRectangle& rect,
      const EcReal& offset = 0
      ) const;

   /// check the intersection with plane
   EcBoolean checkIntersect
      (
      const EcPlane& plane,
      const EcReal& offset = 0
      ) const;

   /// get axes
   virtual const EcXmlVectorVector& axes
      (
      ) const;

   /**
    * @copydoc EcShape::intersectLineSegment()
    */
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent
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

   /// check the intersection with another bounding box
   virtual EcBoolean checkIntersect
      (
      const EcBox& other
      ) const;

   /// calculate the volume
   virtual EcReal volume
      (
      ) const;

   /// compute the vertices of the bounding box
   const EcVector* computeVertices
      (
      ) const;

   /// compute the edges and normals of the bounding box
   const EcLineSegment* computeEdges
      (
      EcVector* vNormals
      ) const;

   /**
    * @brief Compute the faces of the bounding box.
    * @details The faces (EcRectangle) are constructed so that
    *          edge0 crosses edge1 is the face normal.
    * @return const EcRectangle* a vector of faces of size 6
    */
   const EcRectangle* computeFaces
      (
      ) const;

   /// project the bounding box onto a line
   void projectBox
      (
         const EcVector& line,
         EcReal& min,
         EcReal& max
      ) const;

   /// get an axis
   virtual EcVector axis
      (
         EcU32 index
      ) const;

   /// get an extent
   virtual EcReal extent
      (
         EcU32 index
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

   /// get an empty polygon
   static EcBox nullObject
      (
      );

   /// creates a unit cube
   static EcBox unitCube
      (
      const EcDataMap& colorMap=EcDataMap::redColor()
      );

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// the creator function for this object
   static EcXmlObject* creator
      (
      ) ;

   /// returns a class token
   static const EcToken& classToken
      (
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

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      )const;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
         const EcShape& shape
      );

   ///  get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const   ;

   ///  get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const ;

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

   /// Compute the squared distance from a line to a face of the bounding box
   virtual void face
      (
      EcU32 i0,
      EcU32 i1,
      EcU32 i2,
      EcVector& pnt,
      const EcVector& dir,
      const EcVector& pmE,
      EcReal &lParam,
      EcReal& sqrDistance
      ) const;

   /// Utility method handling the case where the direction
   /// vector contains no zeros
   virtual void caseNoZeros
      (
      EcVector& pnt,
      const EcVector& dir,
      EcReal& lParam,
      EcReal& sqrDistance
      ) const;


   /// Utility method handling the case where the direction
   /// vector contains one zero
   virtual void case0
      (
      EcU32 i0,
      EcU32 i1,
      EcU32 i2,
      EcVector& pnt,
      const EcVector& dir,
      EcReal &lParam,
      EcReal& sqrDistance
      ) const;

   /// Utility method handling the case where the direction
   /// vector contains two zeros
   virtual void case00
      (
      EcU32 i0,
      EcU32 i1,
      EcU32 i2,
      EcVector& pnt,
      const EcVector& dir,
      EcReal &lParam,
      EcReal& sqrDistance
      ) const;

   /// Utility method handling the case where the direction
   /// vector contains one zero
   virtual void case000
      (
      EcVector& pnt,
      EcReal& sqrDistance
      ) const;

   /// convert the primary frame to axes
   virtual void primaryFrameToAxes
      (
      );

   /// convert axes to the rotation in the primary frame
   virtual void axesToPrimaryFrame
      (
      );

protected:
   /// a point of the bounding box is reached as follows
   /// P = C + s0*U0 + s1 * U1 + s2 * U2
   /// the extents of the rectangle
   EcXmlVector m_Extents;

   /// the frame in which the box is square, with the ordered
   /// extents along x, y, and z.
   EcCoordinateSystemTransformation m_PrimaryFrame;

   /// non-XML below

   /// the axes on the rectangle <u0, u1,u2>
   EcXmlVectorVector m_Axes;

   /// internal collection of vertices, not needed but here for speed
   mutable EcVector m_vVertices[8];

   /// internal collection of edges, not needed but here for speed
   mutable EcLineSegment m_vEdges[12];

   /// internal collection of edge normals, not needed but here for speed
   mutable EcVector m_vNormals[24];

   /// internal collection of faces, not needed but here for speed
   mutable EcRectangle m_vFaces[6];
};

/// A vector of bounding boxes
typedef EcXmlVectorType<EcBox> EcBoxVector;

/// -----------------------------------------------
/// extra operators below
/// -----------------------------------------------

/// transform the capsule into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcBox operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcBox& m
   );

#endif // ecBox_H_
