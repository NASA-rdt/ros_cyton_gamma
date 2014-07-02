#ifndef ecBaseJointActuator_H_
#define ecBaseJointActuator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseJointActuator.h
/// @class EcBaseJointActuator
/// @brief A base class describing a joint actuator.  In includes inertia,
///        friction, and gear ratio.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

// forward declarations
class EcManipulatorLink;
class EcManipulatorActiveState;

/** Holds a description of an actuator on a joint.
 Data includes friction, inertia, and gear ratio.
TODO: This is here only for backward-compatibility. It will be removed in version 3.0.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseJointActuator : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseJointActuator
      (
      );

   /// constructor
   /*
   \param[in] pLink Pointer to the link that contains this actuator.
   */
   EcBaseJointActuator
      (
      const EcManipulatorLink* pLink
      );

   /// destructor
   virtual ~EcBaseJointActuator
      (
      );

   /// copy constructor
   EcBaseJointActuator
      (
      const EcBaseJointActuator& orig
      );

   /// assignment operator
   EcBaseJointActuator& operator=
      (
      const EcBaseJointActuator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseJointActuator& orig
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
      ) const = 0;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /// return a string token
   virtual const EcToken& token
      (
      ) const = 0;

   /// sets the manipulator link
   /*
   \param[in] pLink Pointer to the link that contains this actuator.
   */
   virtual void setManipulatorLink
      (
      const EcManipulatorLink* pLink
      );

   /// gets lower limit
   virtual EcReal lowerLimit
      (
      ) const = 0;

   /// sets joint lower limit
   virtual void setLowerLimit
      (
      EcReal value
      )=0;

   /// gets upper limit
   virtual EcReal upperLimit
      (
      ) const = 0;

   /// sets joint upper limit
   virtual void setUpperLimit
      (
      EcReal value
      )=0;

   /// gets maximum joint speed
   virtual EcReal maxOutputRate
      (
      ) const = 0;

   /// sets maximum joint speed
   virtual void setMaxOutputRate
      (
      EcReal value
      )=0;

   /// gets joint actuator max torque
   virtual EcReal maxOutputTorque
      (
      ) const = 0;

   /// gets joint actuator min torque
   virtual EcReal minOutputTorque
      (
      ) const = 0;

   /// gets motor max torque
   virtual EcReal maxTorque
      (
      ) const = 0;

   /// sets motor max torque
   virtual void setMaxTorque
      (
      EcReal value
      )=0;

   /// gets motor min torque
   virtual EcReal minTorque
      (
      ) const = 0;

   /// sets motor min torque
   virtual void setMinTorque
      (
      EcReal value
      )=0;

   /// gets inertia
   virtual EcReal inertia
      (
      ) const = 0;

   /// sets inertia
   virtual void setInertia
      (
      EcReal value
      )=0;

   /// gets viscous friction coefficient
   virtual EcReal frictionCoefficient
      (
      ) const = 0;

   /// sets viscous friction coefficient
   virtual void setFrictionCoefficient
      (
      EcReal value
      )=0;

   /// returns the gear ratio of this actuator, i.e. the ratio between the motor speed and the output (link) speed.
   virtual EcReal gearRatio
   (
   ) const = 0;

   /// returns true if this joint actuator is rigid or false otherwise (e.g. flexible or backlash)
   virtual EcBoolean isRigid
      (
      ) const = 0;

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
      ) const = 0;

   /// calculate the linear local torque on the joint
   /// This is the torque or force that must be applied to overcome viscous friction,
   /// stopper, and so forth.  Not including acceleration nor any nonlinear forces such as dry friction or gear backlash
   /**
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal linearTorque
      (
      EcManipulatorActiveState& activeState
      ) const = 0;

   /// calculate the acceleration of the motor
   /**
   \param[in] inputTorque The input (controlled) torque.
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual void acceleration
      (
      EcReal inputTorque,
      EcManipulatorActiveState& activeState
      ) const = 0;

   /// calculate the effective inertia at the joint
   virtual EcReal effectiveInertia
      (
      EcReal jointPosition
      ) const = 0;

   /// scale the actuator properties by a distance scale factor
   /// and a joint-parameter scale factor.  A rotational joint, for example,
   /// would use (2,1) to double the size.  A prismatic joint would use
   /// (2,2) to double the size.
   virtual void scaleBy
      (
      EcReal distanceScaleFactor,
      EcReal jointParameterScaleFactor
      )=0;

   /// initialize the actuator states of this actuator using (and setting) an active state
   virtual void initializeActuatorStates
      (
      EcManipulatorActiveState& activeState
      ) const = 0;

protected:
   /// Pointer to the link associated with this actuator
   const EcManipulatorLink*   m_pLink;
};

#endif // ecBaseJointActuator_H_
