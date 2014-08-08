#ifndef ecTerrain_H_
#define ecTerrain_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecTerrain.h
/// @class EcTerrain
/// @brief Holds a class to describe a terrain field (height data)
/// @details Coordinates are East-North-Up (ENU)  (Height is in positive Z)
///          height vector maps to 2-D height field as follows
///          inner loop marches from west (left) to east (right)
///          outer loop marches from south (bottom) to north (top)
///          outer loop marches with m_WestToEastSpacing spacing
///          origin is in lower left corner
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShape.h"
#include "ecBox.h"
#include <planarGeometry/ecPlanarShapeLayers.h>

class EcAxisAlignedBoundingBox;
class EcCapsule;
class EcCircle;
class EcCircularLozenge;
class EcCone;
class EcCylinder;
class EcGeomTriangle;
class EcLineSegment;
class EcLozenge;
class EcPlane;
class EcRectangle;
class EcSphere;
class EcTetrahedron;
class EcTriangularLozenge;

class EC_FOUNDATION_GEOMETRY_DECL EcTerrain : public EcShape
{
public:
   /// default constructor
   EcTerrain
      (
      );

   /// destructor
   virtual ~EcTerrain
      (
      );

   /// copy constructor
   EcTerrain
      (
      const EcTerrain& orig
      );

   /// assignment operator
   EcTerrain& operator=
      (
      const EcTerrain& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTerrain& orig
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

   /// get east to west size
   virtual const EcXmlU32& westToEastSize
      (
      ) const;

   /// set east to west size
   virtual void setWestToEastSize
      (
      const EcXmlU32& westToEastSize
      );

   /// get south to north size
   virtual const EcXmlU32& southToNorthSize
      (
      ) const;

   /// set south to north size
   virtual void setSouthToNorthSize
      (
      const EcXmlU32& southToNorthSize
      );

   /// get origin
   virtual const EcCoordinateSystemTransformation& origin
      (
      ) const;

   /// set origin
   virtual void setOrigin
      (
      const EcCoordinateSystemTransformation& origin
      );

   /// get West to East spacing
   virtual EcReal westToEastSpacing
      (
      ) const;

   /// set West to East spacing
   virtual void setWestToEastSpacing
      (
      EcReal westToEast
      );

   /// get South to North spacing
   virtual EcReal southToNorthSpacing
      (
      ) const;

   /// set South to North spacing
   virtual void setSouthToNorthSpacing
      (
      EcReal northToSouth
      );

   /// get heights
   virtual const EcRealVector& heights
      (
      ) const;

   /// set height loaded
   virtual const EcRealVector& heightsLoaded
      (
      ) const;

   /// set heights
   virtual void setHeights
      (
      const EcRealVector& heights
      );

   /// get bitmap
   virtual const EcXmlString& bitmapFilename
      (
      ) const;

   /// set bitmap
   virtual void setBitmapFilename
      (
      const EcXmlString& bitmapFilename
      );

   /// get distance threshold
   virtual EcReal distanceThreshold
      (
      ) const;

   /// set distance threshold
   virtual void setDistanceThreshold
      (
      EcReal distanceThreshold
      );

   /// get lozenge multiplier
   virtual EcReal lozengeMultiplier
      (
      ) const;

   /// set lozenge multiplier
   virtual void setLozengeMultiplier
      (
      EcReal lozengeMultiplier
      );

   /// get lozenge max radius
   virtual EcReal lozengeMaxRadius
      (
      ) const;

   /// set lozenge max radius
   virtual void setLozengeMaxRadius
      (
      EcReal lozengeMaxRadius
      );

   /// get render subsample size
   virtual EcU32 renderSubsampleSize
      (
      ) const;

   /// set render subsample size
   virtual void setRenderSubsampleSize
      (
      EcU32 subsampleSize
      );

   /// get simulation subsample size
   virtual EcU32 simulationSubsampleSize
      (
      ) const;

   /// set simulation subsample size
   virtual void setSimulationSubsampleSize
      (
      EcU32 subsampleSize
      );

   /// get surface property layers
   virtual const EcPlanarShapeLayers& surfacePropertyLayers
      (
      ) const;

   /// set surface property layers
   virtual void setSurfacePropertyLayers
      (
      const EcPlanarShapeLayers& layers
      );

   /// get height filename
   virtual const EcXmlString& heightFilename
      (
      ) const;

   /// set height filename
   virtual void setHeightFilename
      (
      const EcXmlString& heightFilename
      );

   /// get bounding box scale factor
   virtual EcReal boundingBoxScaleFactor
      (
      ) const;

   /// set bounding box scale factor
   virtual void setBoundingBoxScaleFactor
      (
      EcReal boundingBoxScaleFactor
      );

   /// read height field
   virtual EcBoolean readHeightField
      (
      ) const;

   /// write height field
   virtual EcBoolean writeHeightField
      (
      ) const;

   /// read height field share
   virtual EcBoolean readHeightFieldShare
      (
      const EcToken& token,
      EcXmlReader& stream
      ) const;

   /// write height field share
   virtual EcBoolean writeHeightFieldShare
      (
      EcXmlWriter& stream
      ) const;

   /// get the surface property at a specified position on the terrain
   virtual const EcString& surfacePropertyAtPoint
      (
      EcReal east,
      EcReal north
      ) const;

   /// returns the type of shape.
   virtual EcU32 type
      (
      ) const;

   /// expand this shape to fit this collection of points
   virtual void fitToPoints
      (
      const EcXmlVectorVector& points
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

   /// get two triangles for cell
   virtual EcBoolean getTrianglesForCell
      (
      const EcU32 row,
      const EcU32 col,
      EcGeomTriangle& triangle1,
      EcGeomTriangle& triangle2,
      const EcReal lozengeMultiplier = 0
      ) const;

   /// get the distance to a triangle and return the closest point
   /**
   \param[in] triangle The triangle
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnRectangle The point on the triangle closest to the terrain
   \return EcReal the distance or penetration depth to triangle
   */
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnRectangle
      ) const;

   /// get the distance to a triangle and return the closest point
   /**
   \param[in] triangle The triangle
   \return EcReal the distance or penetration depth to triangle
   */
   virtual EcReal distanceTo
      (
      const EcGeomTriangle& triangle
      ) const;

   /// get the distance to a point and radius
   /**
   \param[in] center The center point
   \param[in] radius The distance from point
   \param[out] closestPointOnTerrain The point on the filled terrain triangle closest to the sphere
   \return EcReal the distance or penetration depth to radius from point
   */
   virtual EcReal distanceTo
      (
      const EcVector& center,
      const EcReal radius,
      EcVector& closestPointOnTerrain
      ) const;

   /// get the distance to a point and radius
   /**
   \param[in] center The center point
   \param[in] radius The distance from point
   \return EcReal the distance or penetration depth to radius from point
   */
   virtual EcReal distanceTo
      (
      const EcVector& center,
      const EcReal radius
      ) const;

   /// get the distance to a point
   /**
   \param[in] point The point
   \return EcReal the distance from point
   */
   virtual EcReal distanceTo
      (
      const EcVector& point
      ) const;

   /// get the distance to a point and return the closest point
   /**
   \param[in] sphere The sphere
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnSphere The point on the sphere closest to the terrain
   \return EcReal the distance or penetration depth to sphere
   */
   virtual EcReal distanceTo
      (
      const EcSphere& sphere,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnSphere
      ) const;

   /// get the distance to a sphere
   /**
   \param[in] sphere The sphere
   \return EcReal the distance from sphere
   */
   virtual EcReal distanceTo
      (
      const EcSphere& sphere
      ) const;

   /// get the distance to a line and radius
   /**
   \param[in] line The line
   \param[in] radius The distance from point
   \param[out] closestPointOnTerrain The point on the filled terrain triangle closest to the sphere
   \param[out] closestPointOnCapsule The point on the capsule closest to the terrain
   \return EcReal the distance or penetration depth to radius from point
   */
   virtual EcReal distanceTo
      (
      const EcLineSegment& line,
      const EcReal radius,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnCapsule
      ) const;

   /// get the distance to a line and radius
   /**
   \param[in] line The line
   \param[in] radius The distance from point
   \return EcReal the distance or penetration depth to radius from point
   */
   virtual EcReal distanceTo
      (
      const EcLineSegment& line,
      const EcReal radius
      ) const;

   /// get the distance to a line
   /**
   \param[in] line The line
   \return EcReal the distance or penetration depth to radius from point
   */
   virtual EcReal distanceTo
      (
      const EcLineSegment& line
      ) const;

   /// get the distance to a capsule
   /**
   \param[in] capsule The capsule
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnCapsule The point on the capsule closest to the terrain
   \return EcReal the distance or penetration depth to capsule
   */
   virtual EcReal distanceTo
      (
      const EcCapsule& capsule,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnCapsule
      ) const;

   /// get the distance to a capsule
   /**
   \param[in] capsule The capsule
   \return EcReal the distance or penetration depth to capsule
   */
   virtual EcReal distanceTo
      (
      const EcCapsule& capsule
      ) const;

   /// get the distance to a cylinder and return the closest point
   /**
   \param[in] cylinder The cylinder
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnCylinder The point on the cylinder closest to the terrain
   \return EcReal the distance or penetration depth to cylinder
   */
   virtual EcReal distanceTo
      (
      const EcCylinder& cylinder,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnCylinder
      ) const;

   /// get the distance to a cylinder and return the closest point
   /**
   \param[in] cylinder The cylinder
   \return EcReal the distance or penetration depth to cylinder
   */
   virtual EcReal distanceTo
      (
      const EcCylinder& cylinder
      ) const;

   /// get the distance to a cone and return the closest point
   /**
   \param[in] cone The cone
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnCone The point on the cone closest to the terrain
   \return EcReal the distance or penetration depth to cone
   */
   virtual EcReal distanceTo
      (
      const EcCone& cone,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnCone
      ) const;

   /// get the distance to a box and return the closest point
   /**
   \param[in] box The box
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnBox The point on the box closest to the terrain
   \return EcReal the distance or penetration depth to box
   */
   virtual EcReal distanceTo
      (
      const EcBox& box,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnBox
      ) const;

   /// get the distance to a tetrahedron and return the closest point
   /**
   \param[in] tetra The tetrahedron
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnTetra The point on the tetrahedron closest to the terrain
   \return EcReal the distance or penetration depth to tetrahedron
   */
   virtual EcReal distanceTo
      (
      const EcTetrahedron& tetra,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnTetra
      ) const;

   /// get the distance to a rectangle and return the closest point
   /**
   \param[in] rectangle The rectangle
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnRectangle The point on the rectangle closest to the terrain
   \return EcReal the distance or penetration depth to rectangle
   */
   virtual EcReal distanceTo
      (
      const EcRectangle& rectangle,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnRectangle
      ) const;

   /// get the distance to a rectangle and return the closest point
   /**
   \param[in] rect The rectangle
   \return EcReal the distance or penetration depth to rectangle
   */
   virtual EcReal distanceTo
      (
      const EcRectangle& rect
      ) const;

   /// get the distance to a lozenge and return the closest point
   /**
   \param[in] lozenge The lozenge
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnLozenge The point on the lozenge closest to the terrain
   \return EcReal the distance or penetration depth to lozenge
   */
   virtual EcReal distanceTo
      (
      const EcLozenge& lozenge,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnLozenge
      ) const;

   /// get the distance to a lozenge
   /**
   \param[in] lozenge The lozenge
   \return EcReal the distance or penetration depth to lozenge
   */
   virtual EcReal distanceTo
      (
      const EcLozenge& lozenge
      ) const;

   /// get the distance to a lozenge and return the closest point
   /**
   \param[in] lozenge The lozenge
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnLozenge The point on the lozenge closest to the terrain
   \return EcReal the distance or penetration depth to lozenge
   */
   virtual EcReal distanceTo
      (
      const EcTriangularLozenge& lozenge,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnLozenge
      ) const;

   /// get the distance to a lozenge
   /**
   \param[in] lozenge The lozenge
   \return EcReal the distance or penetration depth to lozenge
   */
   virtual EcReal distanceTo
      (
      const EcTriangularLozenge& lozenge
      ) const;

   /// get the distance to a circle and return the closest point
   /**
   \param[in] circle The circle
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnCircle The point on the circle closest to the terrain
   \return EcReal the distance or penetration depth to circle
   */
   virtual EcReal distanceTo
      (
      const EcCircle& circle,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnCircle
      ) const;

   /// get the distance to a circle and return the closest point
   /**
   \param[in] circle The circle
   \return EcReal the distance or penetration depth to circle
   */
   virtual EcReal distanceTo
      (
      const EcCircle& circle
      ) const;

   /// get the distance to a lozenge and return the closest point
   /**
   \param[in] lozenge The lozenge
   \param[out] closestPointOnTerrain The point on the filled triangle closest to the sphere
   \param[out] closestPointOnLozenge The point on the lozenge closest to the terrain
   \return EcReal the distance or penetration depth to lozenge
   */
   virtual EcReal distanceTo
      (
      const EcCircularLozenge& lozenge,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnLozenge
      ) const;

   /// get the distance to a lozenge and return the closest point
   /**
   \param[in] lozenge The lozenge
   \return EcReal the distance or penetration depth to lozenge
   */
   virtual EcReal distanceTo
      (
      const EcCircularLozenge& lozenge
      ) const;

   /// get the distance to a plane
   /**
   \param[in] plane The plane
   \return EcReal the distance or penetration depth to plane
   */
   virtual EcReal distanceTo
      (
      const EcPlane& plane
      ) const;

   /// get the distance to a plane
   /**
   \param[in] plane The plane
   \param[out] closestPointOnTerrain closest point on the terrain
   \param[out] closestPointOnPlane closest point on the plane
   \return EcReal the distance or penetration depth to plane and the closest points
   */
   virtual EcReal distanceTo
      (
      const EcPlane& plane,
      EcVector& closestPointOnTerrain,
      EcVector& closestPointOnPlane
      ) const;

   /**
   \copydoc EcShape::intersectLineSegment()
   **/
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

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// read special height token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
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

   /// method to determine if the shape is convex or not
   virtual EcBoolean isConvex
      (
      ) const;

   /// add point for physical extent
   virtual void addPoint
      (
      EcU32 indexWtoE,
      EcU32 indexStoN,
      EcXmlVectorVector& points
      ) const;

   /// get a physical extent for this shape
   virtual void physicalExtent
      (
      std::vector<EcBasePhysicalExtent*>& physExtent
      ) const;

   /// resizes this shape to completely contain the shape passed in
   virtual void fitFromShape
      (
      const EcShape& shape
      );

   /// get a physical extent from the top shape in the CSG tree
   /// NOTE: This is for backward compatibility
   virtual EcBasePhysicalExtent*  physicalExtent
      (
      ) const  ;

   /// get an empty capsule
   static EcTerrain nullObject
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

   /// returns the impacted surface based on the intersection data
   /// provided.  EcTerrain uses the vector point.
   virtual const EcString& impactedSurface
      (
      const EcU32& intPointIndex,
      const EcVector& point
      ) const;

   /// get terrain points
   virtual void points
       (
       EcXmlVectorVector& points
       ) const;

   /// get bounding box
   virtual const EcBox& boundingBox
      (
      ) const;

   /// set bounding box
   virtual void setBoundingBox
      (
      const EcBox& box
      );

   /// calculate bounding box
   virtual void calculateBoundingBox
      (
      EcBoolean heightFlag = EcFalse
      ) const;

   /// get center
   virtual const EcVector& center
      (
      ) const;

   /// get dimensions
   virtual const EcVector& dimensions
      (
      ) const;

   /// get bounds
   virtual void getBounds
      (
      EcVector& minX,
      EcVector& maxX,
      EcVector& minY,
      EcVector& maxY,
      EcVector& minZ,
      EcVector& maxZ
      ) const;

   /// get support point ID (last calculated)
   virtual EcU32 supportPointID
      (
      ) const;

   /// calculate the max height for each cell
   virtual void calcMaxHeightForCells
      (
      ) const;

   /// get box for shape
   virtual void getBox
      (
      EcBox& box
      ) const;

   /// get aabb for shape
   virtual void getAabb
      (
      EcAxisAlignedBoundingBox& aabb
      ) const;

protected:

   /// ge the height for a give east-west (x) and north-south (y) value
   virtual EcReal terrainHeight
      (
      EcReal x,
      EcReal y
      ) const;

   /// get the terrain points that bound the input point
   /// output mode:
   ///    0 -- point not over terrain (no points valid)
   ///    1 -- normal (all four points valid)
   ///    2 -- point on cell corner (point 1)
   ///    3 -- point on cell horizontal boundary line (points 1 and 2)
   ///    4 -- point on cell vertical boundary line (points 1 and 4)
   virtual void terrainPoints
      (
      EcReal x,
      EcReal y,
      EcInt32& indexWE,
      EcInt32& indexNS,
      EcVector& p1,
      EcVector& p2,
      EcVector& p3,
      EcVector& p4,
      EcU16& mode
      ) const;

   /**
    * @brief Given the line segment, find the intersection with the terrain boundary.
    * @details If the start point is already inside the boundary, return the start point.
    * @param[in] lineSeg the line segment
    * @param[out] interPt the intersection point
    * @return EcTrue if the line segment intersects the terrain boundary or the start point
    *         is already inside the boundary. EcFalse if no intersection.
    */
   virtual EcBoolean terrainBoundaryIntersectLineSegment
      (
      const EcLineSegment& lineSeg,
      EcVector& interPt
      ) const;

protected:

   /// XML Data
   EcXmlU32 m_WestToEastSize;                   /// West to East size
   EcXmlU32 m_SouthToNorthSize;                 /// South to North size
   EcCoordinateSystemTransformation m_Origin;   /// Origin of terrain
   EcXmlReal m_WestToEastSpacing;               /// West to East spacing
   EcXmlReal m_SouthToNorthSpacing;             /// North to South spacing

   mutable EcRealVector m_Heights;              /// Height vector

   EcXmlString m_BitmapFilename;                /// Bitmap filename
   EcXmlReal m_DistanceThreshold;               /// Horizontal distance threshold
   EcXmlReal m_LozengeMultiplier;               /// Multiplier for lozenge radius
   EcXmlReal m_LozengeMaxRadius;                /// Max radius for lozenge
   EcXmlU32 m_RenderSubsampleSize;              /// Subsample size
   EcXmlU32 m_SimulationSubsampleSize;          /// Subsample size
   EcPlanarShapeLayers m_SurfacePropertyLayers; /// Layers defining surface property regions
   EcXmlString m_HeightFilename;                /// Height filename
   EcXmlReal m_BoundingBoxScaleFactor;          /// Bounding box scale factor
   mutable EcXmlVector m_MinX;                  /// min X (farthest West)
   mutable EcXmlVector m_MaxX;                  /// max X (farthest East)
   mutable EcXmlVector m_MinY;                  /// min Y (farthest South)
   mutable EcXmlVector m_MaxY;                  /// max Y (farthest North)
   mutable EcXmlVector m_MinZ;                  /// min height
   mutable EcXmlVector m_MaxZ;                  /// max height;

   // non-XML Data

   /// vector of max cell heights
   mutable EcRealVector m_HeightMaxForCells;

   /// max height for terrain
   mutable EcReal m_HeightMax;

   /// bounding box for terrain
   mutable EcBox m_BoundingBox;

   /// center point of terrain
   mutable EcVector m_Center;

   /// dimensions of terrain
   mutable EcVector m_Dimensions;

   /// bounding volume reset flag
   mutable EcBoolean m_BoundingBoxReset;
};

/// A vector of terrains
typedef EcXmlVectorType<EcTerrain> EcTerrainVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// transform the terrain into an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcTerrain operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcTerrain& m
   );

#endif // ecTerrain_H_
