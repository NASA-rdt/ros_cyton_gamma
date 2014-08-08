#ifndef ecShapeProximityData_H_
#define ecShapeProximityData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeProximityData.h
/// @class EcShapeProximityData
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralMotion.h>
#include "ecPlane.h"
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>

// XXX FIXME: selfTest requires access to protected methods.
namespace Ec { namespace test { class EcShapeProximityDataTester; } }

/// Holds a class to describe a shape proximity related data
class EC_FOUNDATION_GEOMETRY_DECL EcShapeProximityData : public EcXmlCompoundType
{
public:
   /// type of closest
   typedef enum
   {
      POINT,
      LINE,
      FACET,
      CLOSEST_NONE
   } EcClosestType;

   /// friction mode
   typedef enum
   {
      STATIC_FRICTION_MODE,
      KINETIC_FRICTION_MODE,
      UNDEFINED_FRICTION_MODE
   } EcFrictionMode;

   /// default constructor
   EcShapeProximityData
      (
      );

   /// destructor
   virtual ~EcShapeProximityData
      (
      );

   /// copy constructor
   EcShapeProximityData
      (
      const EcShapeProximityData& orig
      );

   /// assignment operator
   EcShapeProximityData& operator=
      (
      const EcShapeProximityData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeProximityData& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// get token
   virtual const EcToken& token
      (
      ) const;

   /// clone
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

   /// the distance to the object
   virtual const EcReal& distance
      (
      ) const;

   /// set the distance to the object
   virtual void setDistance
      (
      const EcReal& dist
      );

   /// sets a boolean indicating whether or not a collision occured
   virtual void setCollisionOccurred
      (
      EcBoolean col
      );

   /// returns a boolean indicating whether or not a collision occured
   virtual EcBoolean collisionOccurred
      (
      ) const;

   /// set the proximity vector (direction of closest points)
   virtual void setProximityVector
      (
      const EcVector& vec
      );

   /// get the proximity vector (direction of closest points)
   virtual const EcVector& proximityVector
      (
      ) const;

   /// set the update time
   virtual void setUpdateTime
      (
      const EcU64& uTime
      );

   /// get the update time
   virtual const EcU64& updateTime
      (
      ) const;

   /// set the update time
   virtual void setDistanceUpdateTime
      (
      const EcU64& uTime
      );

   /// get the update time
   virtual const EcU64& distanceUpdateTime
      (
      ) const;

   /// set the line of action
   virtual void setLineOfAction
      (
      const EcVector& loa
      );

   /// get the line of action
   virtual const EcVector& lineOfAction
      (
      ) const;

   /// set the collision point 1 in primary coordinates
   virtual void setCollisionPointPrimaryObject1
      (
      const EcVector& colPoint
      );

   /// get the collision point 1 in primary coordinates
   virtual const EcVector& collisionPointPrimaryObject1
      (
      )const;

   /// set the collision point 2 in primary coordinates
   virtual void setCollisionPointPrimaryObject2
      (
      const EcVector& colPoint
      );

   /// get the velocity point 2 in primary coordinates
   virtual const EcVector& collisionPointPrimaryObject2
      (
      )const;

   /// set the first impact collision point 1 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   virtual void setStaticStartCollisionPointInPrimary1
      (
      const EcVector& colPoint
      );

   /// get the first impact collision point 1 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   virtual const EcVector& staticStartCollisionPointInPrimary1
      (
      )const;

   /// set the first impact collision point 2 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   virtual void setStaticStartCollisionPointInPrimary2
      (
      const EcVector& colPoint
      );

   /// get the first impact collision point 2 in primary coordinates
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   virtual const EcVector& staticStartCollisionPointInPrimary2
      (
      )const;

   /// return the relative transformation for transforming object 2
   /// into the reference frame of object 1
   virtual const EcCoordinateSystemTransformation& relXformObject1
      (
      )const;

   /// set the relative transformation for transforming object 2
   /// into the reference frame of object 1
   virtual void setRelXformObject1
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// set the last velocity of the primary frame of object 1 in system coordinates
   virtual void setLastVelocityPrimaryObject1
      (
      const EcGeneralVelocity& vel
      );

   /// get the last velocity of the primary frame of object 1 in system coordinates
   virtual const EcGeneralVelocity& lastVelocityPrimaryObject1
      (
      )const;

   /// set the last velocity of the primary frame of object 2 in system coordinates
   virtual void setLastVelocityPrimaryObject2
      (
      const EcGeneralVelocity& vel
      );

   /// get the last velocity of the primary frame of object 2 in system coordinates
   virtual const EcGeneralVelocity& lastVelocityPrimaryObject2
      (
      )const;

   /// set the current velocity of the primary frame of object 1 in system coordinates
   virtual void setVelocityPrimaryObject1
      (
      const EcGeneralVelocity& vel
      );

   /// get the current velocity of the primary frame of object 1 in system coordinates
   virtual const EcGeneralVelocity& velocityPrimaryObject1
      (
      )const;

   /// set the current velocity of the primary frame of object 2 in system coordinates
   virtual void setVelocityPrimaryObject2
      (
      const EcGeneralVelocity& vel
      );

   /// get the current velocity of the primary frame of object 2 in system coordinates
   virtual const EcGeneralVelocity& velocityPrimaryObject2
      (
      )const;

   /// set the proximity sense
   virtual void setProximitySense
      (
      const EcBoolean& sense
      )const;

   /// set the proximity sense
   virtual const EcBoolean&  proximitySense
      (
      )const;

   /// set the in-static friction mode flag
   virtual void setFrictionMode
      (
      const EcFrictionMode& insmode
      );

   /// get the in-static friction mode flag
   virtual const EcFrictionMode&  frictionMode
      (
      )const;

   /// get the object 1 primary frame
   virtual const EcCoordinateSystemTransformation& staticStartPrimaryFrame1InSystem
      (
      )const;

   /// set the object 1 primary frame
   virtual void setStaticStartPrimaryFrame1InSystem
      (
      const EcCoordinateSystemTransformation& staticStartPrimaryFrame1InSystem
      );

   /// get the object 2 primary frame
   virtual const EcCoordinateSystemTransformation& staticStartPrimaryFrame2InSystem
      (
      )const;

   /// set the object 2 primary frame
   virtual void setStaticStartPrimaryFrame2InSystem
      (
      const EcCoordinateSystemTransformation& primaryFrame2InSystem
      );

   /// set the data elements related to dynamics modeling
   virtual void setDynamicSimulationDataFromLast
      (
      const EcShapeProximityData& data
      );

   /// set the data elements related to dynamics modeling
   virtual void setAndInvertDynamicSimulationDataFromLast
      (
      const EcShapeProximityData& data
      );

   /// set the directional data elements
   void setAndInvertDirectionalData
      (
      const EcShapeProximityData& other
      );

   /// insert penetration point for shape 1
   virtual void insertPenetrationPointShape1Primary
      (
      const EcVector& point
      );

   /// insert penetration point for shape 1
   virtual void insertPenetrationPointShape2Primary
      (
      const EcVector& point
      );

   /// get penetration points for shape 1
   virtual const EcVector* getPenetrationPointShape1Primary
      (
      const EcU32& nthElement
      ) const;

   /// insert penetration points for shape 1
   virtual const EcVector* getPenetrationPointShape2Primary
      (
      const EcU32& nthElement
      ) const;

   /// penetration point for the the specified shape
   /// returns zero if the object index or the point
   /// index is out of range
   virtual const EcVector& penetrationPointPrimary
      (
      EcU32 shapeIndex,
      EcU32 pointIndex
      ) const;

   /// get the number of penetration points this value
   /// is the same for both shapes.
   virtual const EcU32 numPenetrationPoints
      (
      )const;

   /// reset the penetration point buffers, this should
   /// be called at the begining of a new collision
   virtual void resetPenetrationPointBuffers
      (
      );

   /// copy over all the data, but invert the directional data
   /// so that other.velocityPrimaryObject2 is set to
   /// this.velocityPrimaryObject1 for instance
   virtual void copyDataWithDirectionalInversion
      (
      const EcShapeProximityData& other
      );

   /// get the type for closest point 1
   virtual const EcClosestType& closestPoint1
      (
      )const;

   /// set the type for closest point 1
   virtual void setClosestPoint1
      (
      const EcClosestType& val
      );

   /// get the type for closest point 2
   virtual const EcClosestType& closestPoint2
      (
      )const;

   /// set the type for closest point 2
   virtual void setClosestPoint2
      (
      const EcClosestType& val
      );

   /// gets a boolean indicating whether or not a first collision occurred before
   virtual const EcBoolean& firstCollisionOccurred
      (
      )const;

   /// sets a boolean indicating whether or not a first collision occurred before
   virtual void setFirstCollisionOccurred
      (
      EcBoolean col
      );

   /// get the witness points
   virtual void getWitnessPoints
      (
      EcVector& witnessPoint1,
      EcVector& witnessPoint2
      ) const;

   /// set the witness points
   virtual void setWitnessPoints
      (
      const EcVector& witnessPoint1,
      const EcVector& witnessPoint2
      );

   /// get the witness points update time
   virtual EcU64 witnessPointsUpdateTime
      (
      ) const;

   /// set the witness points update time
   virtual void setWitnessPointsUpdateTime
      (
      EcU64 updateTime
      );

protected:
   /// XXX FIXME: selfTest requires access to protected methods.
   friend class Ec::test::EcShapeProximityDataTester;

   /// insert penetration point into circular buffer
   virtual void insertPenetrationPoint
      (
      const EcVector& point,
      EcVectorVector& points,
      EcInt32& index
      );

   /// get penetration points
   virtual const EcVector* penetrationPoint
      (
      const EcU32& numElements,
      const EcVectorVector& circularBuffer,
      const EcInt32& circularBufferHeadIndex
      ) const;

   /// distance to shape
   EcReal m_Distance;

   /// boolean describing whether or not a collision resulted from the query
   EcBoolean m_CollisionOccurred;

   /// the vector of the closest points between the shapes
   EcVector m_ProximityVector;

   /// line of action.  The direction of the collision
   EcVector m_LineOfAction;

   /// the point of collision in primary local coordinates.  Null vector if
   /// no collision occured
   EcVector m_CollisionPointPrimaryObject1;

   /// the point of collision in primary local coordinates.  Null vector if
   /// no collision occured
   EcVector m_CollisionPointPrimaryObject2;

   /// the point of first impact in primary local coordinates.  Null vector if
   /// no collision occured
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   EcVector m_StaticStartCollisionPointInPrimary1;

   /// the point of first impact in primary local coordinates.  Null vector if
   /// no collision occured
   /// this is used for computing static friction and is the first
   /// collision point between the two bodies in which static friction
   /// is imposed
   EcVector m_StaticStartCollisionPointInPrimary2;

   /// transformation to convert primary frame of object 2 to the
   /// primary frame of object 1
   EcCoordinateSystemTransformation m_RelativeTransformPrimaryFrame1;

   /// last-time-step velocity of the first object in its primary frame
   EcGeneralVelocity m_LastVelocityPrimaryObject1;

   /// last-time-step velocity of the second object in its primary frame
   EcGeneralVelocity m_LastVelocityPrimaryObject2;

   /// current velocity of the first object in its primary frame
   EcGeneralVelocity m_VelocityPrimaryObject1;

   /// current velocity of the second object in its primary frame
   EcGeneralVelocity m_VelocityPrimaryObject2;

   /// flag indicating whether these shapes are currently being bound
   /// by dry(static) friction force, kinetic friction force, or undefined
   EcFrictionMode m_FrictionMode;

   /// since the cache is symmetric about the the manipulator ID, the entry for
   /// (1,0,0) and (0,0,0) is the same as the entry for (0,0,0) and (1,0,0).
   /// Some of the data may need to be converted so that the output is always
   /// consistent for requests of the form (shape1,shape2).  This value is
   /// EcFALSE if no swap was needed, or EcTRUE if the data was swapped before
   /// being added.
   mutable EcBoolean m_ProximitySense;

   /// the body 1 static start primary frame in system coordinates
   EcCoordinateSystemTransformation m_StaticStartPrimaryFrame1InSystem;

   /// the body 2 static start primary frame in system coordinates
   EcCoordinateSystemTransformation m_StaticStartPrimaryFrame2InSystem;

   /// the contact plane for shape 1 in primary coordinates
   EcPlane m_ContactPlaneShape1PrimarySystem;

   /// the contact plane for shape 2 in primary coordinates
   EcPlane m_ContactPlaneShape2PrimarySystem;

   /// a circular buffer of penetration points for shape 1
   /// the penetration point in the deepest point of penetration
   /// on the shape
   EcVectorVector m_PenetrationPointsPrimaryObject1;

   /// a circular buffer of penetration points for shape 1
   /// the penetration point in the deepest point of penetration
   /// on the shape
   EcVectorVector m_PenetrationPointsPrimaryObject2;

   /// boolean describing whether or not a first collision occurred before
   EcBoolean m_FirstCollisionOccurred;

   /// the witness point on shape 1
   EcVector m_WitnessPoint1;

   /// the witness point on shape 2
   EcVector m_WitnessPoint2;

   //-------used internally----------

   /// the time of the last data update
   EcU64 m_LastUpdateTime;

   /// the time of the last distance update, distance can be updated without
   /// an update of additional data being updated
   EcU64 m_LastDistanceUpdateTime;

   /// index pointing to the most recent data in the queue
   EcInt32 m_PenetrationPointBuffer1HeadIndex;

   /// index pointing to the most recent data in the queue
   EcInt32 m_PenetrationPointBuffer2HeadIndex;

   /// The closest type for this object
   EcClosestType   m_ClosestType1;

   /// The closest type for the other object
   EcClosestType   m_ClosestType2;

   /// the time of the last witness points update. witness points can be updated without an update of additional data being updated
   EcU64 m_LastWitnessPointsUpdateTime;

   /// const data

   /// the circular buffer size
   static const EcU32 m_thePenetrationPointBufferSize;
};

#endif // ecShapeProximityData_H_
