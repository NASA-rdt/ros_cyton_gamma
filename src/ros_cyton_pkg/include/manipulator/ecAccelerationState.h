#ifndef ecAccelerationState_H_
#define ecAccelerationState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecAccelerationState.h
/// @class EcAccelerationState
/// @brief Holds a description of the acceleration state of a manipulator.
///        This includes the joint accelerations and the acceleration of the base.
///        The base acceleration is the motion of the base with respect to the
///        manipulator system frame, expressed in manipulator system frame coordinates,
///        with point of application at the origin of the base frame.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcGeneralMotion;
class EcReArray;
class EcVelocityState;

/** Holds a description of the acceleration state of a manipulator.
 This includes the joint accelerations and the acceleration of the base.
 The base acceleration is the motion of the base with respect to the
 manipulator system frame, expressed in manipulator system frame coordinates,
 with point of application at the origin of the base frame.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcAccelerationState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcAccelerationState
      (
      );

   /// destructor
   virtual ~EcAccelerationState
      (
      );

   /// copy constructor
   EcAccelerationState
      (
      const EcAccelerationState& orig
      );

   /// assignment operator
   EcAccelerationState& operator=
      (
      const EcAccelerationState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAccelerationState& orig
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

   /// gets joint accelerations - const version
   virtual const EcXmlRealVector& jointAccelerations
      (
      ) const;

   /// gets joint accelerations - nonconst version
   virtual EcXmlRealVector& jointAccelerations
      (
      );

   /// sets joint accelerations
   virtual void setJointAccelerations
      (
      const EcXmlRealVector& jointAccelerations
      );

   /// sets joint accelerations from an EcReArray
   virtual void setJointAccelerations
      (
      const EcReArray& jointAccelerations
      );

   /// gets general acceleration - const version
   virtual const EcGeneralMotion& generalAcceleration
      (
      ) const;

   /// gets general acceleration - nonconst version
   virtual EcGeneralMotion& generalAcceleration
      (
      );

   /// sets general acceleration
   virtual void setGeneralAcceleration
      (
      const EcGeneralMotion& generalAcceleration
      );

   /// resizes the array of joint accelerations
   virtual void resize
      (
      EcU32 size
      );

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcAccelerationState& accState2,
      EcReal tol
      ) const;

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// reads this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// writes this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// gets a null link
   static EcAccelerationState nullObject
      (
      );

   /// gets an acceleration state compatible with the
   /// given velocity state
   static EcAccelerationState zeroCompatibleState
      (
      const EcVelocityState& velocityState
      );

protected:
   /// the vector of joint accelerations
   EcXmlRealVector     m_JointAccelerations;

   /// the general acceleration of the base
   EcGeneralMotion     m_GeneralAcceleration;
};

/// a vector of manipulator acceleration states
typedef EcXmlVectorType<EcAccelerationState> EcAccelerationStateVector;

#endif // ecAccelerationState_H_
