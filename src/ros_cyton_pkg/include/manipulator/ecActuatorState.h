#ifndef ecActuatorState_H_
#define ecActuatorState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecActuatorState.h
/// @class EcActuatorState
/// @brief A class containing internal actuator state.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of an actuator state.
class EC_FOUNDATION_MANIPULATOR_DECL EcActuatorState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcActuatorState
      (
      );

   /// destructor
   virtual ~EcActuatorState
      (
      );

   /// copy constructor
   EcActuatorState
      (
      const EcActuatorState& orig
      );

   /// assignment operator
   EcActuatorState& operator=
      (
      const EcActuatorState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcActuatorState& orig
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

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the actuator output torques. const version.
   virtual const EcXmlRealVector& outputTorques
      (
      ) const;

   /// gets the actuator output torques. non-const version.
   virtual EcXmlRealVector& outputTorques
      (
      );

   /// sets the actuator output torques.
   virtual void setOutputTorques
      (
      const EcXmlRealVector& torques
      );

   /// gets the motor positions - const version
   virtual const EcXmlRealVector& motorPositions
      (
      ) const;

   /// gets the motor positions - nonconst version
   virtual EcXmlRealVector& motorPositions
      (
      );

   /// sets the motor positions
   virtual void setMotorPositions
      (
      const EcXmlRealVector& value
      );

   /// gets the motor velocities - const version
   virtual const EcXmlRealVector& motorVelocities
      (
      ) const;

   /// gets the motor velocities - nonconst version
   virtual EcXmlRealVector& motorVelocities
      (
      );

   /// sets the motor velocities
   virtual void setMotorVelocities
      (
      const EcXmlRealVector& value
      );

   /// gets the motor accelerations - const version
   virtual const EcXmlRealVector& motorAccelerations
      (
      ) const;

   /// gets the motor accelerations - nonconst version
   virtual EcXmlRealVector& motorAccelerations
      (
      );

   /// sets the motor accelerations
   virtual void setMotorAccelerations
      (
      const EcXmlRealVector& value
      );

   /// gets the flags indicating whether or not actuators are rigid - const version
   virtual const EcXmlBooleanVector& nonRigidActuatorFlags
      (
      ) const;

   /// gets the flags indicating whether or not actuators are rigid - const version
   virtual EcXmlBooleanVector& nonRigidActuatorFlags
      (
      );

   /// sets the flags indicating whether or not actuators are rigid
   virtual void setNonRigidActuatorFlags
      (
      const EcXmlBooleanVector& value
      );

   /// return the spring/damper center points. The static friction is computed using a spring/damper model around this point. const version.
   virtual const EcXmlRealVector& springDamperCenters
      (
      ) const;

   /// return the spring/damper center points. The static friction is computed using a spring/damper model around this point. non-const version.
   virtual EcXmlRealVector& springDamperCenters
      (
      );

   /// set the spring/damper center points.
   virtual void setSpringDamperCenters
      (
      const EcXmlRealVector& centers
      );

   /// return the static friction modes. If true, then we compute static friction using breaking spring/damper. If false, then we use kinetic friction. const version.
   virtual const EcXmlBooleanVector& staticFrictionModes
      (
      ) const;

   /// return the static friction modes. If true, then we compute static friction using breaking spring/damper. If false, then we use kinetic friction. non-const version.
   virtual EcXmlBooleanVector& staticFrictionModes
      (
      );

   /// set the static friction mode. If the force computed by the spring/damper model exceeds a specified threshold, then the mode changes to kinetic. If the actuator motion changes direction, then the mode changes to static.
   virtual void setStaticFrictionModes
      (
      const EcXmlBooleanVector& staticFrictionMode
      );

   /// return the actuator velocities at the last time step. const version.
   virtual const EcXmlRealVector& lastVelocities
      (
      ) const;

   /// return the actuator velocities at the last time step. non-const version
   virtual EcXmlRealVector& lastVelocities
      (
      );

   /// set the actuator velocities at the last time step
   virtual void setLastVelocities
      (
      const EcXmlRealVector& velocities
      );

   /// return the actuator positions at which the motion reverses direction. const version.
   virtual const EcXmlRealVector& reverseMotionPositions
      (
      ) const;

   /// return the actuator positions at which the motion reverses direction. non-const version.
   virtual EcXmlRealVector& reverseMotionPositions
      (
      );

   /// set the actuator position at which the motion reverses direction
   virtual void setReverseMotionPositions
      (
      const EcXmlRealVector& positions
      );

   /// return the vector of power converter states for all actuators. The meanings of these states depend on the type of power converters for those actuators. const version.
   virtual const EcXmlRealVectorVector& powerConverterStates
      (
      ) const;

   /// return the vector of power converter states for all actuators. non-const version.
   virtual EcXmlRealVectorVector& powerConverterStates
      (
      );

   /// set the vector of power converter states for all actuators.
   virtual void setPowerConverterStates
      (
      const EcXmlRealVectorVector& values
      );

   /// resize all the components
   virtual void resize
      (
      EcU32 size
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// get an zero-information actuator state
   static EcActuatorState nullObject
      (
      );

protected:
   /// the actuator output torques
   EcXmlRealVector                  m_OutputTorques;

   /// the motor position state
   EcXmlRealVector                  m_MotorPositions;

   /// the motor velocity state
   EcXmlRealVector                  m_MotorVelocities;

   /// the motor acceleration state
   EcXmlRealVector                  m_MotorAccelerations;

   /// a vector containing flags indicating whether or not actuators are rigid. Rigid actuators are not include in integration step for simulation purposes
   EcXmlBooleanVector               m_NonRigidActuatorFlags;

   /// a vector containing spring/damper center points used in calculation of dry friction
   EcXmlRealVector                  m_SpringDamperCenters;

   /// a vector containing static friction modes. If true, then we compute static friction. If false, then we use kinetic friction.
   EcXmlBooleanVector               m_StaticFrictionModes;

   /// a vector containing the joint actuator velocities in the last time step
   EcXmlRealVector                  m_LastVelocities;

   /// a vector containing the joint positions at which the actuator motion reverses direction
   EcXmlRealVector                  m_ReverseMotionPositions;

   /// a vector of power converter states for all actuators
   EcXmlRealVectorVector            m_PowerConverterStates;
};

#endif // ecActuatorState_H_
