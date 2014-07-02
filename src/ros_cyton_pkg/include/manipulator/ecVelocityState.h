#ifndef ecVelocityState_H_
#define ecVelocityState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecVelocityState.h
/// @class EcVelocityState
/// @brief Holds a description of the position state of a manipulator.
///        This includes the joint velocities and the frame velocity of the base.
///        The base velocity is the motion of the base with respect to the
///        system, expressed in system coordinates, with point of application
///        at the origin of the base frame.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declaration
class EcReArray;

/** Holds a description of the position state of a manipulator.
 This includes the joint velocities and the velocity of the base.
 The base velocity is the motion of the base with respect to the
 system, expressed in system coordinates, with point of application
 at the origin of the base frame.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcVelocityState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcVelocityState
      (
      );

   /// destructor
   virtual ~EcVelocityState
      (
      );

   /// copy constructor
   EcVelocityState
      (
      const EcVelocityState& orig
      );

   /// assignment operator
   EcVelocityState& operator=
      (
      const EcVelocityState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVelocityState& orig
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

   /// gets joint velocities - const version
   virtual const EcXmlRealVector& jointVelocities
      (
      ) const;

   /// gets joint velocities - nonconst version
   virtual EcXmlRealVector& jointVelocities
      (
      );

   /// sets joint velocities
   virtual void setJointVelocities
      (
      const EcXmlRealVector& jointVelocities
      );

   /// sets joint velocities from an EcReArray
   virtual void setJointVelocities
      (
      const EcReArray& jointVelocities
      );

   /// gets general velocity - const version
   virtual const EcGeneralVelocity& generalVelocity
      (
      ) const;

   /// gets general velocity - nonconst version
   virtual EcGeneralVelocity& generalVelocity
      (
      );

   /// sets general velocity
   virtual void setGeneralVelocity
      (
      const EcGeneralVelocity& generalVelocity
      );

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcVelocityState& velState2,
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

   /// read this object from a binary stream
   virtual EcBoolean readBin
      (
      std::istream& stream
      );

   /// write this object to a binary stream
   virtual EcBoolean writeBin
      (
      std::ostream& stream
      ) const;

   /// gets a null link
   static EcVelocityState nullObject
      (
      );

   /// linearly interpolate between two velocity states
   virtual EcBoolean linearInterpolation
      (
      const EcVelocityState& velocityState1,
      const EcVelocityState& velocityState2,
      const EcReal& factor
      );

protected:
   /// the vector of joint velocities
   EcXmlRealVector     m_JointVelocities;

   /// the general velocity of the base.  Expressed in
   /// system coordinates, with point of application the
   /// origin of the base frame.
   EcGeneralVelocity   m_GeneralVelocity;
};

/// a vector of manipulator velocity states
typedef EcXmlVectorType<EcVelocityState> EcVelocityStateVector;

#endif // ecVelocityState_H_
