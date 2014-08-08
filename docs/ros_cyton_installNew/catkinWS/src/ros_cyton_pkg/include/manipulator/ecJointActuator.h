#ifndef ecJointActuator_H_
#define ecJointActuator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointActuator.h
/// @brief A class describing joint actuators.
/// @details EcJointActuator
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

#include "ecMechActComponentContainer.h"
#include "ecManufacturerData.h"
#include "ecPowerConverterContainer.h"
#include "ecPassThroughPowerConverter.h"

class EcManipulatorLink;
class EcOldJointActuator;

/**
A class describing joint actuators.

A joint actuator consists of two parts. First is the mechanical component that describes mechanical properties of the actuator such as inertia, friction, speed ratio, etc. The second part is the power converter that describes the underlying conversion of power to mechanical power. Examples of power converters are electric DC motor, hydraulic cylinder, etc.

Both mechanical component and power converter reside in containers so they are changeable parts.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcJointActuator : public EcXmlCompoundType
{
public:
   /// default constructor
   EcJointActuator
      (
      );

   /// constructor with values
   EcJointActuator
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
   virtual ~EcJointActuator
      (
      );

   /// copy constructor
   EcJointActuator
      (
      const EcJointActuator& orig
      );

   /// assignment operator
   EcJointActuator& operator=
      (
      const EcJointActuator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointActuator& orig
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

   /// gets the token
   virtual const EcToken& token
      (
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// sets the manipulator link
   /*
   \param[in] pLink Pointer to the link that contains this actuator.
   */
   virtual void setManipulatorLink
      (
      const EcManipulatorLink* pLink
      );

   /// gets the container for the mechanical component
   virtual const EcMechanicalActuatorComponentContainer& mechanicalComponentContainer
      (
      ) const;

   /// gets the container for the mechanical component non-const version
   /// Warning this is not thread safe
   virtual EcMechanicalActuatorComponentContainer& mechanicalComponentContainer
      (
      );

   /// sets the container for the mechanical component
   virtual void setMechanicalPartContainer
      (
      const EcMechanicalActuatorComponentContainer& value
      );

   /// sets the mechanical component of the actuator
   virtual void setMechanicalComponent
      (
      const EcMechanicalActuatorComponent& value
      );

   /// gets the container for the power converter
   virtual const EcPowerConverterContainer& powerConverterContainer
      (
      ) const;

   /// sets the container for the power converter
   virtual void setPowerConverterContainer
      (
      const EcPowerConverterContainer& value
      );

   /// sets the power converter of the actuator
   virtual void setPowerConverter
      (
      const EcBasePowerConverter& value
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

   /// gets joint actuator max torque
   virtual EcReal maxOutputTorque
      (
      ) const;

   /// gets joint actuator min torque
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

   /// returns true if this joint actuator is rigid or false otherwise (e.g. flexible or backlash)
   virtual EcBoolean isRigid
      (
      ) const;

   /// sets the isRigid flag to deterimine if the joint is assumed rigid or not
   virtual void setIsRigid
      (
      EcBoolean value
      );

   /// gets the manufacture data of the prime mover (motor)
   virtual const EcManufacturerData& primeMoveManufacturerData
      (
      ) const;

   /// sets the manufacture data of the prime mover (motor)
   virtual void setPrimeMoveManufacturerData
      (
      const EcManufacturerData& value
      );

   /// gets the vector of the manufacture data of the gearheads
   virtual const EcManufacturerDataVector& gearheadManufacturerDataVector
      (
      ) const;

   /// sets the vector of the manufacture data of the gearheads
   virtual void setGearheadManufacturerDataVector
      (
      const EcManufacturerDataVector& value
      );

   /// calculate the effective inertia at the joint
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
   static EcJointActuator nullObject
      (
      );

   /// standard actuator object
   static EcJointActuator defaultObject
      (
      );

   /// set the properties from the old joint actuator format. This is temporarily provided for backward compatibility and can be removed in the future.
   virtual void setFromOldJointActuator
      (
      const EcOldJointActuator& oldActuator
      );
protected:
   /// the container for the mechanical component
   EcMechanicalActuatorComponentContainer   m_MechanicalComponentContainer;

   /// the container for the power converter
   EcPowerConverterContainer        m_PowerConverterContainer;

   /// the manufacture data of the prime mover (motor)
   EcManufacturerData               m_PrimeMoverManufacturerData;

   /// a vector of the manufacture data of the gearheads
   EcManufacturerDataVector         m_vGearheadManufacturerData;

   /// non-XML data
   const EcManipulatorLink*         m_pLink;
};

/// type definition of XML vector of EcJointActuator
typedef EcXmlVectorType<EcJointActuator> EcJointActuatorVector;

#endif // ecJointActuator_H_
