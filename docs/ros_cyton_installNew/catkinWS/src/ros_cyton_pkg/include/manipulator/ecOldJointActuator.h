#ifndef ecOldJointActuator_H_
#define ecOldJointActuator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecOldJointActuator.h
/// @class EcOldJointActuator
/// @brief A description of a joint actuator.  In includes inertia,
///        friction, and gear ratio.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlVectorType.h>
#include "ecBaseJointActuator.h"

/// Holds a description of an actuator on a joint.
/** Data includes friction, inertia, and gear ratio.
\todo This is here only for backward-compatibility. It will be removed in version 3.0.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcOldJointActuator : public EcBaseJointActuator
{
public:
   /// default constructor
   EcOldJointActuator
      (
      );

   /// constructor with values
   EcOldJointActuator
      (
      EcReal inertia,
      EcReal frictionCoefficient,
      EcReal gearRaio,
      EcReal lowerLimit,
      EcReal upperLimit,
      EcReal maxOutputRate,
      EcReal stopperZone,
      EcReal minTorque,
      EcReal maxTorque,
      EcReal stopperSpringCoefficient,
      EcReal stopperDampingCoefficient
      );

   /// destructor
   virtual ~EcOldJointActuator
      (
      );

   /// copy constructor
   EcOldJointActuator
      (
      const EcOldJointActuator& orig
      );

   /// assignment operator
   EcOldJointActuator& operator=
      (
      const EcOldJointActuator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcOldJointActuator& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
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

   virtual const EcToken& token
      (
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets inertia
   virtual EcReal inertia
      (
      ) const;

   /// sets inertia
   virtual void setInertia
      (
      EcReal value
      );

   /// gets viscous friction coefficient
   virtual EcReal frictionCoefficient
      (
      ) const;

   /// sets viscous friction coefficient
   virtual void setFrictionCoefficient
      (
      EcReal value
      );

   /// returns the gear ratio of this actuator, i.e. the ratio between the motor speed and the output (link) speed.
   virtual EcReal gearRatio
      (
      ) const;

   /// sets gearRatio
   virtual void setGearRatio
      (
      EcReal value
      );

   /// gets lower limit
   virtual EcReal lowerLimit
      (
      ) const;

   /// sets joint lower limit
   virtual void setLowerLimit
      (
      EcReal value
      );

   /// gets upper limit
   virtual EcReal upperLimit
      (
      ) const;

   /// sets joint upper limit
   virtual void setUpperLimit
      (
      EcReal value
      );

   /// gets maximum joint speed
   virtual EcReal maxOutputRate
      (
      ) const;

   /// sets maximum joint speed
   virtual void setMaxOutputRate
      (
      EcReal value
      );

   /// gets stopper zone
   virtual EcReal stopperZone
      (
      ) const;

   /// sets stopper zone
   virtual void setStopperZone
      (
      EcReal value
      );

   /// gets (joint level, not motor level) stopper spring coefficient
   virtual EcReal stopperSpringCoefficient
      (
      ) const;

   /// sets (joint level, not motor level) stopper spring coefficient
   virtual void setStopperSpringCoefficient
      (
      EcReal value
      );

   /// gets (joint level, not motor level) stopper damping coefficient
   virtual EcReal stopperDampingCoefficient
      (
      ) const;

   /// sets (joint level, not motor level) stopper damping coefficient
   virtual void setStopperDampingCoefficient
      (
      EcReal value
      );

   /// gets joint actuator max torque, which is essentially maxTorque*gearRatio
   virtual EcReal maxOutputTorque
      (
      ) const;

   /// gets joint actuator min torque, which is essentially minTorque*gearRatio
   virtual EcReal minOutputTorque
      (
      ) const;

   /// gets motor max torque
   virtual EcReal maxTorque
      (
      ) const;

   /// sets motor max torque
   virtual void setMaxTorque
      (
      EcReal value
      );

   /// gets motor min torque
   virtual EcReal minTorque
      (
      ) const;

   /// sets motor min torque
   virtual void setMinTorque
      (
      EcReal value
      );

   /// gets static Coulomb friction
   virtual EcReal staticCoulombFriction
      (
      ) const;

   /// sets static Coulomb friction
   /**
   \param[in] value The static Coulomb friction value to be set. Must be >= 0.0. If negative, nothing happens.
   */
   virtual void setStaticCoulombFriction
      (
      EcReal value
      );

   /// gets kinetic Coulomb friction as percentage (between 0 and 1) of the static Coulomb friction
   virtual EcReal kineticCoulombFrictionPercentage
      (
      ) const;

   /// sets kinetic Coulomb friction percentage
   /**
   \param[in] value The kinetic Coulomb friction as percentage of the static Coulomb friction. The value must be between 0 and 1. If not, nothing happens.
   */
   virtual void setKineticCoulombFrictionPercentage
      (
      EcReal value
      );

   /// gets spring coefficient used to compute static Coulomb friction in the breaking spring/damper model
   virtual EcReal staticCoulombSpringCoefficient
      (
      ) const;

   /// sets spring coefficient used to compute static Coulomb friction in the breaking spring/damper model
   /**
   \param[in] value The spring coefficient value to be set. Must be >= 0.0. If negative, nothing happens.
   */
   virtual void setStaticCoulombSpringCoefficient
      (
      EcReal value
      );

   /// gets damper coefficient used to compute static Coulomb friction in the breaking spring/damper model
   virtual EcReal staticCoulombDamperCoefficient
      (
      ) const;

   /// sets damper coefficient used to compute static Coulomb friction in the breaking spring/damper model
   /**
   \param[in] value The damper coefficient value to be set. Must be >= 0.0. If negative, nothing happens.
   */
   virtual void setStaticCoulombDamperCoefficient
      (
      EcReal value
      );

   /// gets the limiting velocity that determines if the dry friction is in stick (static) or slip (kinetic) mode. If the joint actuator speed is greater than this limit, then it's in slip mode. Otherwise, it's in stick mode.
   virtual EcReal limitingVelocityStickRegion
      (
      ) const;

   /// sets the limiting velocity that determines if the dry friction is in stick (static) or slip (kinetic) mode. If the joint actuator speed is greater than this limit, then it's in slip mode. Otherwise, it's in stick mode.
   /**
   \param[in] value The limit velocity value to be set. Must be >= 0.0. If negative, nothing happens.
   */
   virtual void setLimitingVelocityStickRegion
      (
      EcReal value
      );

   /// returns true if this joint actuator is rigid or false otherwise (e.g. flexible or backlash)
   virtual EcBoolean isRigid
      (
      ) const;

   /// sets whether this actuator is flexible or rigid
   /**
   \param[in] value True if this joint actuator is rigid or false otherwise (e.g. flexible or backlash)
   */
   virtual void setIsRigid
      (
      EcBoolean value
      );

   /// gets the spring constant for the joint flexibility. Undefined if isRigid returns true.
   virtual EcReal jointFlexibilityStiffness
      (
      ) const;

   /// sets the spring constant for the joint flexibility. Undefined if isRigid returns true.
   /**
   \param[in] value The spring constant value to be set. Must be >= 0.0. If negative, nothing happens.
   */
   virtual void setJointFlexibilityStiffness
      (
      EcReal value
      );

   /// gets the damping constant for the joint flexibility. Undefined if isRigid returns true.
   virtual EcReal jointFlexibilityDamping
      (
      ) const;

   /// sets the damping constant for the joint flexibility. Undefined if isRigid returns true.
   /**
   \param[in] value The damping constant value to be set. Must be >= 0.0. If negative, nothing happens.
   */
   virtual void setJointFlexibilityDamping
      (
      EcReal value
      );

   /// gets the backlash amount.
   /**
   The backlash amount is essentially the amount within which the motor can displace without before it transmit motion/torque to the link.
   */
   virtual EcReal backlash
      (
      ) const;

   /// sets the backlash amount.
   /**
   \param[in] value The backlash value to be set. Must be >= 0.0. If negative, nothing happens.
   */
   virtual void setBacklash
      (
      EcReal value
      );

   /// calculate the total output torque of this actuator
   /**
   If the actuator is not rigid, this is the torque due to joint flexibility and/or gear backlash, which is the output torque that drives the link.
   If the actuator is rigid, this is the input (controlled) torque minus actuator resistive torques including viscous friction, dry friction,
   stopper, and so forth.
   \param[in] inputTorque The input torque to the actuator.
   \param[in] linkTorque The torque from the manipulator link attached to this actuator.
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal outputTorque
      (
      EcReal inputTorque,
      EcReal linkTorque,
      EcManipulatorActiveState& activeState
      ) const;

   /// calculate the linear local torque on the joint
   /// This is the torque or force that must be applied to overcome viscous friction,
   /// stopper, and so forth.  Not including acceleration nor any nonlinear forces such as dry friction or gear backlash
   /**
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal linearTorque
      (
      EcManipulatorActiveState& activeState
      ) const;

   /// calculate the stopper torque on the joint
   /// this is the torque or force that must be applied to overcome the stopper
   /// at a joint limit.
   /**
   \param[in] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal stopperTorque
      (
      const EcManipulatorActiveState& activeState
      ) const;

   /// calculate the friction torque on the joint
   /// this is the torque or force that must be applied to overcome viscous friction
   /**
   \param[in] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal viscousFrictionTorque
      (
      const EcManipulatorActiveState& activeState
      ) const;

   /// calculate the dry (stick-slip) friction torque on the joint
   /**
   \param[in] torque The torque acting on the joint.
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator. The values of actuator state inside activeState can also be changed depending on stick-slip condition.
   */
   virtual EcReal dryFrictionTorque
      (
      EcReal torque,
      EcManipulatorActiveState& activeState
      ) const;

   /// calculate the acceleration of the motor
   /**
   \param[in] inputTorque The input (controlled) torque.
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual void acceleration
      (
      EcReal inputTorque,
      EcManipulatorActiveState& activeState
      ) const;

   /// calculate the effective inertia at the joint
   /**
   Note: If the actuator is not rigid, then the effective inertia is set to zero. This is necessary to allow correct computation of joint
   acceleration at the manipulator level.
   */
   virtual EcReal effectiveInertia
      (
      EcReal jointPosition
      ) const;

   /// scale the actuator properties by a distance scale factor
   /// and a joint-parameter scale factor.  A rotational joint, for example,
   /// would use (2,1) to double the size.  A prismatic joint would use
   /// (2,2) to double the size.
   virtual void scaleBy
      (
      EcReal distanceScaleFactor,
      EcReal jointParameterScaleFactor
      );

   /// initialize the actuator states of this actuator using (and setting) an active state
   virtual void initializeActuatorStates
      (
      EcManipulatorActiveState& activeState
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// get an zero-information joint actuator
   static EcOldJointActuator nullObject
      (
      );

protected:
   /// compute output torque in non-rigid case
   virtual EcReal nonRigidOutputTorque
      (
      EcManipulatorActiveState& activeState
      ) const;

protected:
   /// actuator inertia
   EcXmlReal   m_Inertia;

   /// actuator viscous friction coefficient
   EcXmlReal   m_FrictionCoefficient;

   /// actuator gear ratio
   EcXmlReal   m_GearRatio;

   /// joint lower limit
   EcXmlReal   m_LowerLimit;

   /// joint upper limit
   EcXmlReal   m_UpperLimit;

   /// joint speed limit
   EcXmlReal   m_MaxOutputRate;

   /// the stopper zone
   EcXmlReal   m_StopperZone;

   /// the minimum torque available from the actuator
   EcXmlReal   m_MinTorque;

   /// the maximum torque available from the actuator
   EcXmlReal   m_MaxTorque;

   /// the stopper spring coefficient
   EcXmlReal   m_StopperSpringCoefficient;

   /// the stopper damping coefficient
   EcXmlReal   m_StopperDampingCoefficient;

   /// the static Coulomb friction
   EcXmlReal   m_StaticCoulombFriction;

   /// the kinetic Coulomb friction as percentage of m_StaticCoulombFriction
   EcXmlReal   m_KineticCoulombFrictionPercentage;

   /// the spring coefficient used to compute static Coulomb friction
   EcXmlReal   m_StaticCoulombSpringCoefficient;

   /// the damper coefficient used to compute static Coulomb friction
   EcXmlReal   m_StaticCoulombDamperCoefficient;

   /// the limiting velocity for stick region
   EcXmlReal   m_LimitingVelocityStickRegion;

   /// the flag indicating whether or not this joint is rigid
   EcXmlBoolean   m_IsRigid;

   /// the spring constant in actuator flexibility, used only when m_IsRigid is false
   EcXmlReal   m_JointFlexibilityStiffness;

   /// the damping constant in actuator flexibility, used only when m_IsRigid is false
   EcXmlReal   m_JointFlexibilityDamping;

   /// the backlash amount. This is basically the dead zone before a motion/torque is transmitted to the link when actuator changes direction
   EcXmlReal   m_Backlash;
};

#endif // ecOldJointActuator_H_
