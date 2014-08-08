#ifndef ecShapeCollisionData_H_
#define ecShapeCollisionData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeCollisionData.h
/// @class EcShapeCollisionData
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include "ecProximityKey.h"
#include <foundCommon/ecGeneralMotion.h>
#include <foundCommon/ecCoordSysXForm.h>

// forward declaration
class EcManipulatorLink;

/// Holds a class for caching collision data between two shapes
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcShapeCollisionData
{
public:
   /// friction mode
   typedef enum
   {
      STATIC_FRICTION_MODE,
      KINETIC_FRICTION_MODE,
      UNDEFINED_FRICTION_MODE
   } EcFrictionMode;

   /// constructor
   EcShapeCollisionData
      (
      );

   /// destructor
   ~EcShapeCollisionData
      (
      );

   /// copy constructor
   EcShapeCollisionData
      (
      const EcShapeCollisionData& orig
      );

   /// assignment operator
   EcShapeCollisionData& operator=
      (
      const EcShapeCollisionData& orig
      );

   /// set the update time
   void setUpdateTime
      (
      const EcU64& uTime
      );

   /// get the update time
   const EcU64& updateTime
      (
      ) const;

   /// set the shape keys
   void setShapeKeys
      (
      const EcShapeKey& key1,
      const EcShapeKey& key2
      );

   /// get the shape key of shape 1
   const EcShapeKey& shapeKey1
      (
      ) const;

   /// get the shape key of shape 2
   const EcShapeKey& shapeKey2
      (
      ) const;

   /// set the pointer of the link specified by the key in the collision
   void setLinkPointer
      (
      const EcShapeKey& key,
      const EcManipulatorLink* linkPtr
      );

   /// get the pointer of the link specified by the key in the collision
   const EcManipulatorLink* linkPointer
      (
      const EcShapeKey& key
      ) const;

   /// set the collision point in primary coordinates
   void setCollisionPointPrimaryObject
      (
      const EcShapeKey& key,
      const EcVector& colPoint
      );

   /// get the collision point in primary coordinates
   const EcVector& collisionPointPrimaryObject
      (
      const EcShapeKey& key
      ) const;

   /// set the first impact collision point in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   void setStaticStartCollisionPointInPrimary
      (
      const EcShapeKey& key,
      const EcVector& colPoint
      );

   /// get the first impact collision point in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   const EcVector& staticStartCollisionPointInPrimary
      (
      const EcShapeKey& key
      ) const;

   /// set the last velocity of the primary frame of object in system coordinates
   void setLastVelocityPrimaryObject
      (
      const EcShapeKey& key,
      const EcGeneralVelocity& vel
      );

   /// get the last velocity of the primary frame of object in system coordinates
   const EcGeneralVelocity& lastVelocityPrimaryObject
      (
      const EcShapeKey& key
      ) const;

   /// set the current velocity of the primary frame of object in system coordinates
   void setVelocityPrimaryObject
      (
      const EcShapeKey& key,
      const EcGeneralVelocity& vel
      );

   /// get the current velocity of the primary frame of object in system coordinates
   const EcGeneralVelocity& velocityPrimaryObject
      (
      const EcShapeKey& key
      ) const;

   /// get the primary frame of the start of static friction center
   const EcCoordinateSystemTransformation& staticStartPrimaryFrameInSystem
      (
      const EcShapeKey& key
      ) const;

   /// set the primary frame of the start of static friction center
   void setStaticStartPrimaryFrameInSystem
      (
      const EcShapeKey& key,
      const EcCoordinateSystemTransformation& staticStartPrimaryFrame
      );

   /// insert penetration point for shape
   void insertPenetrationPointShapePrimary
      (
      const EcShapeKey& key,
      const EcVector& point
      );

   /// get penetration points for shape
   const EcVector* getPenetrationPointShapePrimary
      (
      const EcShapeKey& key,
      EcU32 nthElement
      ) const;

   /// set the index of the closest point for shape
   /// used by GJK to compute the penetration distance
   void setClosestPointIndex
      (
      const EcShapeKey& key,
      EcU32 pointIndex
      );

   /// return the index of the closest point for shape
   /// used by GJK to compute the penetration distance
   EcU32 closestPointIndex
      (
      const EcShapeKey& key
      ) const;

   /// set the link pointer of the first link in the collision
   void setLink1Pointer
      (
      const EcManipulatorLink* ptr
      );

   /// get the link pointer of the first link in the collision
   const EcManipulatorLink* link1Pointer
      (
      ) const;

   /// set the link pointer of the second link in the collision
   void setLink2Pointer
      (
      const EcManipulatorLink* ptr
      );

   /// get the link pointer of the second link in the collision
   const EcManipulatorLink* link2Pointer
      (
      ) const;

   /// set the penetration distance (always <= 0.0)
   void setPenetrationDistance
      (
      EcReal dist
      );

   /// get the penetration distance (always <= 0.0)
   EcReal penetrationDistance
      (
      ) const;

   /// same as penetrationDistance. For compatilibity purposes.
   EcReal separationDistance
      (
      ) const;

   /// set the line of action
   void setLineOfAction
      (
      const EcVector& loa
      );

   /// get the line of action
   const EcVector& lineOfAction
      (
      ) const;

   /// same as lineOfAction. For compatilibity purposes.
   const EcVector& collisionNormal
      (
      ) const;

   /// set the collision point 1 in primary coordinates
   void setCollisionPointPrimaryObject1
      (
      const EcVector& colPoint
      );

   /// get the collision point 1 in primary coordinates
   const EcVector& collisionPointPrimaryObject1
      (
      ) const;

   /// same as collisionPointPrimaryObject1. For compatilibity purposes.
   const EcVector& contactPointRel1
      (
      ) const;

   /// set the collision point 2 in primary coordinates
   void setCollisionPointPrimaryObject2
      (
      const EcVector& colPoint
      );

   /// get the velocity point 2 in primary coordinates
   const EcVector& collisionPointPrimaryObject2
      (
      ) const;

   /// same as collisionPointPrimaryObject2. For compatilibity purposes.
   const EcVector& contactPointRel2
      (
      ) const;

   /// set the first impact collision point 1 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   void setStaticStartCollisionPointInPrimary1
      (
      const EcVector& colPoint
      );

   /// get the first impact collision point 1 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   const EcVector& staticStartCollisionPointInPrimary1
      (
      )const;

   /// set the first impact collision point 2 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   void setStaticStartCollisionPointInPrimary2
      (
      const EcVector& colPoint
      );

   /// get the first impact collision point 2 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   const EcVector& staticStartCollisionPointInPrimary2
      (
      )const;

   /// set the last velocity of the primary frame of object 1 in system coordinates
   void setLastVelocityPrimaryObject1
      (
      const EcGeneralVelocity& vel
      );

   /// get the last velocity of the primary frame of object 1 in system coordinates
   const EcGeneralVelocity& lastVelocityPrimaryObject1
      (
      )const;

   /// set the last velocity of the primary frame of object 2 in system coordinates
   void setLastVelocityPrimaryObject2
      (
      const EcGeneralVelocity& vel
      );

   /// get the last velocity of the primary frame of object 2 in system coordinates
   const EcGeneralVelocity& lastVelocityPrimaryObject2
      (
      )const;

   /// set the current velocity of the primary frame of object 1 in system coordinates
   void setVelocityPrimaryObject1
      (
      const EcGeneralVelocity& vel
      );

   /// get the current velocity of the primary frame of object 1 in system coordinates
   const EcGeneralVelocity& velocityPrimaryObject1
      (
      )const;

   /// set the current velocity of the primary frame of object 2 in system coordinates
   void setVelocityPrimaryObject2
      (
      const EcGeneralVelocity& vel
      );

   /// get the current velocity of the primary frame of object 2 in system coordinates
   const EcGeneralVelocity& velocityPrimaryObject2
      (
      )const;

   /// set the in-static friction mode flag
   void setFrictionMode
      (
      const EcFrictionMode& frictionMode
      );

   /// get the in-static friction mode flag
   const EcFrictionMode&  frictionMode
      (
      )const;

   /// get the object 1 primary frame
   const EcCoordinateSystemTransformation& staticStartPrimaryFrame1InSystem
      (
      )const;

   /// set the object 1 primary frame
   void setStaticStartPrimaryFrame1InSystem
      (
      const EcCoordinateSystemTransformation& staticStartPrimaryFrame1InSystem
      );

   /// get the object 2 primary frame
   const EcCoordinateSystemTransformation& staticStartPrimaryFrame2InSystem
      (
      )const;

   /// set the object 2 primary frame
   void setStaticStartPrimaryFrame2InSystem
      (
      const EcCoordinateSystemTransformation& primaryFrame2InSystem
      );

   /// insert penetration point for shape 1
   void insertPenetrationPointShape1Primary
      (
      const EcVector& point
      );

   /// insert penetration point for shape 2
   void insertPenetrationPointShape2Primary
      (
      const EcVector& point
      );

   /// get penetration points for shape 1
   const EcVector* getPenetrationPointShape1Primary
      (
      EcU32 nthElement
      ) const;

   /// insert penetration points for shape 2
   const EcVector* getPenetrationPointShape2Primary
      (
      EcU32 nthElement
      ) const;

   /// penetration point for the the specified shape
   /// returns zero if the object index or the point
   /// index is out of range
   const EcVector& penetrationPointPrimary
      (
      EcU32 shapeIndex,
      EcU32 pointIndex
      ) const;

   /// get the number of penetration points this value
   /// is the same for both shapes.
   const EcU32 numPenetrationPoints
      (
      )const;

   /// reset the penetration point buffers, this should
   /// be called at the begining of a new collision
   void resetPenetrationPointBuffers
      (
      );

   /// get the shape ID of shape one
   EcU32 shapeOneID
      (
      )const;

   /// get the shape ID of shape two
   EcU32 shapeTwoID
      (
      )const;

   /// get the manipulator ID of link one
   EcU32 manipulatorOneID
      (
      )const;

   /// get the manipulator ID for link two
   EcU32 manipulatorTwoID
      (
      )const;

   /// set the index of the closest point for shape 1
   /// used by GJK to compute the penetration distance
   void setClosestPointIndex1
      (
      EcU32 pointIndex
      );

   /// return the index of the closest point for shape 1
   /// used by GJK to compute the penetration distance
   EcU32 closestPointIndex1
      (
      ) const;

   /// set the index of the closest point for shape 2
   /// used by GJK to compute the penetration distance
   void setClosestPointIndex2
      (
      EcU32 pointIndex
      );

   /// return the index of the closest point for shape 2
   /// used by GJK to compute the penetration distance
   EcU32 closestPointIndex2
      (
      ) const;

protected:

   /// insert penetration point into circular buffer
   void insertPenetrationPoint
      (
      const EcVector& point,
      EcVectorVector& points,
      EcInt32& index
      );

   /// get penetration points
   const EcVector* penetrationPoint
      (
      EcU32 numElements,
      const EcVectorVector& circularBuffer,
      const EcInt32& circularBufferHeadIndex
      ) const;

   /// the penetration distance. Also same as separationDistance in EcCollisionDescriptor.
   EcReal m_PenetrationDistance;

   /// line of action.  The direction of the collision. Also same as collisionNormal in EcCollisionDescriptor.
   EcVector m_LineOfAction;

   /// flag indicating whether these shapes are currently being bound
   /// by dry(static) friction force, kinetic friction force, or undefined
   EcFrictionMode m_FrictionMode;

   /// shape keys
   EcShapeKey     m_ShapeKeys[2];

   /// pointer to the links involved in the collision
   const EcManipulatorLink* m_pLink[2];

   /// the points of collision in primary local coordinates.
   EcVector m_CollisionPointPrimaryObject[2];

   /// the points of first impact in primary local coordinates.  Null vector if
   /// no collision occured
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   EcVector m_StaticStartCollisionPointInPrimary[2];

   /// last-time-step velocities of the objects in their primary frame
   EcGeneralVelocity m_LastVelocityPrimaryObject[2];

   /// current velocities of the objects in their primary frame
   EcGeneralVelocity m_VelocityPrimaryObject[2];

   /// the bodies' static start primary frames in system coordinates
   EcCoordinateSystemTransformation m_StaticStartPrimaryFrameInSystem[2];

   /// circular buffers of penetration points for shapes
   /// the penetration point in the deepest point of penetration
   /// on the shape
   EcVectorVector m_PenetrationPointsPrimaryObject[2];

   /// the closest points used by GJK to compute the penetration distance
   /// for shapes
   EcU32 m_ClosestPoint[2];

   //-------used internally----------

   /// the time of the last data update
   EcU64 m_LastUpdateTime;

   /// indices pointing to the most recent data in the queue
   EcInt32 m_PenetrationPointBufferHeadIndex[2];

   /// const data

   /// the circular buffer size
   static const EcU32 m_thePenetrationPointBufferSize;
};

#endif // ecShapeCollisionData_H_
