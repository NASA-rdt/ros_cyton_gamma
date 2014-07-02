#ifndef ecAxisAlignedBoundingBox_H_
#define ecAxisAlignedBoundingBox_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecAxisAlignedBoundingBox.h
/// @class EcAxisAlignedBoundingBox
/// @brief Holds a class to describe an axis aligned bounding box (AABB).
/// @details A description for an axis-aligned bounding box.  NOTE:
///          this class does not inherit from EcShape to keep it lightweight.
///          For general bounding box queries use EcBoundingBox (oriented)
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecXmlVector.h>

class EcBox;
class EcCapsule;
class EcCircularLozenge;
class EcCone;
class EcCylinder;
class EcLozenge;
class EcSphere;
class EcTerrain;
class EcTriangularLozenge;

/** Holds a class to describe an axis aligned bounding box (AABB).
*/
class EC_FOUNDATION_GEOMETRY_DECL EcAxisAlignedBoundingBox : public EcXmlCompoundType
{
public:
   /**
    * @brief Default constructor.
    */
   EcAxisAlignedBoundingBox
      (
      );

   /**
    * @brief Constructor the min max extents in local coordinates.
    * @param[in] xMin
    * @param[in] xMax
    * @param[in] yMin
    * @param[in] yMax
    * @param[in] zMin
    * @param[in] zMax
    */
   EcAxisAlignedBoundingBox
      (
      const EcReal& xMin,
      const EcReal& xMax,
      const EcReal& yMin,
      const EcReal& yMax,
      const EcReal& zMin,
      const EcReal& zMax
      );

   /**
    * @brief Construct from a collection of bounding boxes.
    * @param[in] bbList a collection of bounding boxes
    */
   EcAxisAlignedBoundingBox
      (
      std::vector<EcAxisAlignedBoundingBox>& bbList
      );

   /**
    * @brief Destructor.
    * @details 
    * @return 
    */
   virtual ~EcAxisAlignedBoundingBox
      (
      );

   /**
    * @brief Copy constructor.
    * @param[in] orig
    */
   EcAxisAlignedBoundingBox
      (
      const EcAxisAlignedBoundingBox& orig
      );

   /**
    * @brief Assignment operator.
    * @param[in] orig
    * @return EcAxisAlignedBoundingBox&
    */
   EcAxisAlignedBoundingBox& operator=
      (
      const EcAxisAlignedBoundingBox& orig
      );

   /**
    * @brief Equality operator.
    * @param[in] orig
    * @return EcBoolean
    */
   EcBoolean operator==
      (
      const EcAxisAlignedBoundingBox& orig
      ) const;

   /**
    * @brief Initialize XML components for reading and writing.
    * @return EcBoolean
    */
   virtual EcBoolean xmlInit
      (
      );

   /**
    * @brief Clone - a virtual constructor to an EcXmlObject pointer.
    * @return EcXmlObject*
    */
   virtual EcXmlObject* clone
      (
      ) const;

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
      ) const;

   /**
    * @brief Virtual new that returns an EcXmlObject.
    * @return EcXmlObject*
    */
   virtual EcXmlObject* newObject
      (
      ) const;

   /**
    * @brief Get the minimum X value in DH coordinates.
    * @return EcReal
    */
   virtual EcReal xMin
      (
      ) const;

   /**
    * @brief Set the minimum X value in DH coordinates.
    * @param[in] xVal
    * @return void
    */
   virtual void setXMin
      (
      const EcReal& xVal
      );

   /**
    * @brief Get the maximum X value in DH coordinates.
    * @return EcReal
    */
   virtual EcReal xMax
      (
      ) const;

   /**
    * @brief Set the maximum X value in DH coordinates.
    * @param[in] xVal
    * @return void
    */
   virtual void  setXMax
      (
      const EcReal& xVal
      );

   /**
    * @brief Get the minimum Y value in DH coordinates.
    * @return EcReal
    */
   virtual EcReal yMin
      (
      ) const;

   /**
    * @brief Set the minimum Y value in DH coordinates.
    * @param[in] yVal
    * @return void
    */
   virtual void setYMin
      (
      const EcReal& yVal
      );

   /**
    * @brief Get the maximum Y value in DH coordinates.
    * @return EcReal
    */
   virtual EcReal yMax
      (
      ) const;

   /**
    * @brief Set the maximum X value in DH coordinates.
    * @param[in] yVal
    * @return void
    */
   virtual void setYMax
      (
      const EcReal& yVal
      );

   /**
    * @brief Get the minimum Z value in DH coordinates.
    * @return EcReal
    */
   virtual EcReal zMin
      (
      ) const;

   /**
    * @brief Set the minimum Z value in DH coordinates.
    * @param[in] zVal
    * @return void
    */
   virtual void setZMin
      (
      const EcReal& zVal
      );

   /**
    * @brief Get the maximum Z value in DH coordinates.
    * @return EcReal
    */
   virtual EcReal zMax
      (
      ) const;

   /**
    * @brief Set the maximum Z value in DH coordinates.
    * @param[in] zVal
    * @return void
    */
   virtual void setZMax
      (
      const EcReal& zVal
      );

   /**
    * @brief Check if the x-axes overlaps with the box passed in.
    * @details Overlap testing is in the strict sense.  If the two boxes are just
    * touching along a common edge, the boxes are reported as overlapping.
    * @param[in] rkBox
    * @return EcBoolean
    */
   virtual EcBoolean hasXOverlap
      (
      const EcAxisAlignedBoundingBox& rkBox
      )const;

   /**
    * @brief Check if the y-axes overlaps with the box passed in.
    * @details Overlap testing is in the strict sense.  If the two boxes are just
    * touching along a common edge, the boxes are reported as overlapping.
    * @param[in] rkBox
    * @return EcBoolean
    */
   virtual EcBoolean hasYOverlap
      (
      const EcAxisAlignedBoundingBox& rkBox
      ) const;

   /**
    * @brief Check if the z-axes overlaps with the box passed in.
    * @details Overlap testing is in the strict sense.  If the two boxes are just
    * touching along a common edge, the boxes are reported as overlapping.
    * @param[in] rkBox
    * @return EcBoolean
    */
   virtual EcBoolean hasZOverlap
      (
      const EcAxisAlignedBoundingBox& rkBox
      ) const;

   /**
    * @brief Check if this box intersects with the box passed in.
    * @param[in] box
    * @return EcBoolean
    */
   virtual EcBoolean testIntersection
      (
      const EcAxisAlignedBoundingBox& box
      ) const;

   /**
    * @brief return EcTrue if an overlap occurs and returns the intersection region as an aabb (intBox).
    * @details If there is no intersection, intBox is undefined
    * @param[in] box
    * @param[in] intBox
    * @return EcBoolean
    */
   virtual EcBoolean findIntersection
      (
      const EcAxisAlignedBoundingBox& box,
      EcAxisAlignedBoundingBox& intBox
      ) const;

   /**
    * @brief Make this box encompass the current box as well as this one.
    * @param[in] other
    * @return void
    */
   virtual void expandSelfToInclude
      (
      const EcAxisAlignedBoundingBox& other
      );

   /**
    * @brief Make this box encompass the current box as well as this one.
    * @param[in] bbList
    * @return void
    */
   virtual void expandSelfToInclude
      (
      const EcXmlVectorType<EcAxisAlignedBoundingBox>& bbList
      );

   /**
    * @brief Return the midpoint of the AABB.
    * @return EcVector
    */
   virtual EcVector midPoint
      (
      )const;

   /**
    * @brief Longest axis of the bounding box.
    * @return EcU32
    */
   virtual EcU32 longestAxis
      (
      )const;

   /**
    * @brief Get the error metric for this bounding box.
    * @return EcReal
    */
   virtual EcReal errorMetric
      (
      ) const;

   /**
    * @brief Resize the bounding box from a oriented box.
    * @param[in] box
    * @return void
    */
   virtual void resize
      (
      const EcBox& box
      );

   /**
    * @brief Resize the bounding box from a capsule.
    * @param[in] capsule
    * @return void
    */
   virtual void resize
      (
      const EcCapsule& capsule
      );

   /**
    * @brief Resize the bounding box from a cone.
    * @param[in] cone
    * @return void
    */
   virtual void resize
      (
      const EcCone& cone
      );

   /**
    * @brief Resize the bounding box from a cylinder.
    * @param[in] cylinder
    * @return void
    */
   virtual void resize
      (
      const EcCylinder& cylinder
      );

   /**
    * @brief Resize the bounding box from a lozenge.
    * @param[in] lozenge
    * @return void
    */
   virtual void resize
      (
      const EcLozenge& lozenge
      );

   /**
    * @brief Resize the bounding box from a sphere.
    * @param[in] sphere
    * @return void
    */
   virtual void resize
      (
      const EcSphere& sphere
      );

   /**
    * @brief Resize the bounding box from a terrain.
    * @param[in] box
    * @return void
    */
   virtual void resize
      (
      const EcTerrain& box
      );

   /**
    * @brief Uniformly enlarge the box by value.
    * @param[in] value
    * @return void
    */
   virtual void enlarge
      (
      const EcReal& value
      );

   /**
    * @brief Read this object from an XML stream
    * @param[in] stream
    * @return EcBoolean
    */
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /**
    * @brief 
    * @details 
    * @param[in] stream
    * @return EcBoolean
    */
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /**
    * @brief Get an empty polygon.
    * @return EcAxisAlignedBoundingBox
    */
   static EcAxisAlignedBoundingBox nullObject
      (
      );

   /**
    * @brief The creator function for this object.
    * @return EcXmlObject*
    */
   static EcXmlObject* creator
      (
      ) ;

   /**
    * @brief Returns a class token.
    * @return const EcToken&
    */
   static const EcToken& classToken
      (
      );

   /**
    * @brief Virtual method returning the token for this object.
    * @return const EcToken&
    */
   virtual const EcToken& token
      (
      )const;

   /**
    * @brief Make this box encompass the current box as well as this one.
    * @param[in] bbList
    * @return void
    */
   virtual void resizeToVector
      (
      const EcXmlVectorType<EcAxisAlignedBoundingBox>& bbList
      );

protected:
   /// vector holding the minimum extent values
   EcXmlVector m_MinExtentValues;

   /// vector holding the minimum extent values
   EcXmlVector m_MaxExtentValues;
};

/// A vector of AABBs
typedef EcXmlVectorType<EcAxisAlignedBoundingBox> EcAxisAlignedBoundingBoxVector;

/// A 2D vector
typedef EcXmlVectorType<EcAxisAlignedBoundingBoxVector> EcAxisAlignedBoundingBoxVectorVector;

#endif // ecAxisAlignedBoundingBox_H_
