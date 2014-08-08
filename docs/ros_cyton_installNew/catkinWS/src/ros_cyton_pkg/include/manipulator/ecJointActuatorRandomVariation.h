#ifndef ecJointActuatorRandomVariation_H_
#define ecJointActuatorRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointActuatorRandomVariation.h
/// @brief Description of random variation of joint actuator
/// @details EcJointActuatorRandomVariation
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/// The class for generating random variations of joint actuator properties that can be used
/// in Monte-Carlo simulation
class EC_FOUNDATION_MANIPULATOR_DECL EcJointActuatorRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcJointActuatorRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the random noise of joint torque. This will be used during runtime to add noise to the generated torque.
   /**
   This value is the one sigma value describing the noise of the generated torque.
   */
   virtual EcReal torqueOneSigma
      (
      ) const;

   /// sets the random noise of joint torque.
   virtual void setTorqueOneSigma
      (
      EcReal value
      );

   /// gets the random noise of joint position sensor. This will be used during runtime to add noise to the joint position.
   /**
   This value is the one sigma value describing the noise of the joint position sensor.
   */
   virtual EcReal positionOneSigma
      (
      ) const;

   /// sets the random noise of joint position sensor.
   virtual void setPositionOneSigma
      (
      EcReal value
      );

   /// gets the random noise of joint velocity sensor. This will be used during runtime to add noise to the joint velocity.
   /**
   This value is the one sigma value describing the noise of the joint velocity sensor.
   */
   virtual EcReal velocityOneSigma
      (
      ) const;

   /// sets the random noise of joint velocity sensor.
   virtual void setVelocityOneSigma
      (
      EcReal value
      );

   /// create an object with default values
   static EcJointActuatorRandomVariation defaultObject
      (
      );

protected:
   /// the one sigma value of random noise of joint torque
   EcXmlReal      m_TorqueOneSigma;

   /// the one sigma value of random noise of joint position
   EcXmlReal      m_PositionOneSigma;

   /// the one sigma value of random noise of joint velocity
   EcXmlReal      m_VelocityOneSigma;
};

#endif // ecJointActuatorRandomVariation_H_
