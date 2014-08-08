#ifndef ecBaseForceController_H_
#define ecBaseForceController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseForceController.h
/// @class EcBaseForceController
/// @brief The base class for force controller
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipSensorForce.h"
#include "ecForceControlFunctionContainer.h"
#include "ecForceSensorVector.h"
#include <control/ecEndEffectorVector.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecXmlPairType.h>

class EcForceSensorSet;
class EcEndEffectorSet;
class EcManipulatorEndEffectorPlacement;
class EcPositionControlSystem;

/// XML vector type of string pairs
typedef EcXmlVectorType< EcXmlStringStringPair >   EcXmlStringStringPairVector;

class EC_ACTIN_FORCECONTROL_DECL EcBaseForceController : public EcXmlCompoundType
{
public:

   /// default constructor
   EcBaseForceController
      (
      );

   /// destructor
   virtual ~EcBaseForceController
      (
      );

   /// copy constructor
   EcBaseForceController
      (
      const EcBaseForceController& orig
      );

   /// assignment operator
   EcBaseForceController& operator=
      (
      const EcBaseForceController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseForceController& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// get the label of this controller
   virtual const EcString& label
      (
      ) const;

   /// set the label of this controller
   virtual void setLabel
      (
      const EcString& value
      );

   /// get whether the controller is on
   virtual EcBoolean isOn
      (
      ) const;

   /// turn on/off and reset the force controller
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// get the vector of identifiers of force sensors associated with this force controller
   virtual const EcXmlStringStringPairVector& forceSensorIdentifiers
      (
      ) const;

   /// set the vector of identifiers of force sensors associated with this force controller. Each identifier is a pair of strings. The first string is the label of the link to which the sensor is attached. The second string is the type (token) of the sensor.
   virtual void setForceSensorIdentifiers
      (
      const EcXmlStringStringPairVector& value
      );

   /// get the vector of identifiers of end effectors associated with this force controller
   virtual const EcXmlStringStringPairVector& endEffectorIdentifiers
      (
      ) const;

   /// set the vector of identifiers of end effectors associated with this force controller. Each identifier is a pair of strings. The first string is the label of the link to which the end effector is attached. The second string is the type (token) of the end effector.
   virtual void setEndEffectorIdentifiers
      (
      const EcXmlStringStringPairVector& value
      );

   /// get the force control function container. It contains the specific force control algorithm used in this controller.
   virtual const EcForceControlFunctionContainer& controlFunctionContainer
      (
      ) const;

   /// set the force control function container.
   virtual void setControlFunctionContainer
      (
      const EcForceControlFunctionContainer& value
      );

   /// set the force control function (algorithm) used in this controller.
   virtual void setControlFunction
      (
      const EcForceControlFunction& value
      );

   /// get the indices of the force sensors associated with this force controller from the given sensor set.
   virtual EcU32Vector forceSensorIndices
       (
       const EcForceSensorSet& forceSensorSet
       ) const;

   /// this is an alternative method to setForceSensorIdentifiers(). This will extract and internally set the identifiers of the sensors from the sensor set speicified by the indices.
   virtual void setForceSensors
      (
      const EcForceSensorSet& forceSensorSet,
      const EcU32Vector& indices
      );

   /// get the indices of the end effectors associated with this force controller from the given end effector set.
   virtual EcU32Vector endEffectorIndices
       (
       const EcEndEffectorSet& endEffectorSet
       ) const;

   /// this is an alternative method to setEndEffectorIdentifiers(). This will extract and internally set the identifiers of the end effectors from the end effector set speicified by the indices.
   virtual void setEndEffectors
      (
      const EcEndEffectorSet& endEffectorSet,
      const EcU32Vector& indices
      );

   /// initialize the force controller. This will associate the sensor and end-effector identifiers with the given sensors and end-effectors. Return false if any of the force sensor/end-effector identifiers does not belong in the provided force sensor/end-effector sets or true otherwise.
   virtual EcBoolean initialize
      (
      const EcForceSensorSet& forceSensorSet,
      const EcEndEffectorSet& endEffectorSet
      );

   /// modify the desired end-effector placement based on the force information
   virtual void adjustDesiredPlacement
      (
      EcReal deltaTime,
      EcU32 manipIndex,
      const EcManipulatorSensorForce& measuredForce,
      const EcManipulatorSensorForce& desiredForce,
      const EcPositionControlSystem& posContSys,
      const EcManipulatorEndEffectorPlacement& actualPlacement,
      EcManipulatorEndEffectorPlacement& desiredPlacement
      ) const=0;

   /// reset to initial state
   virtual void reset
      (
      );

protected:
   /// clear all the internal vectors
   virtual void clearAll
      (
      );
protected:
   /// the label
   EcXmlString                            m_Label;

   /// an on-off flag
   EcXmlBoolean                           m_IsOn;

   /// the identifiers of all sensors involved in this force controller
   EcXmlStringStringPairVector            m_vForceSensorIdentifiers;

   /// the identifiers of all end-effectors involved in this force controller
   EcXmlStringStringPairVector            m_vEndEffectorIdentifiers;

   /// the control function container
   EcForceControlFunctionContainer        m_ControlFunctionContainer;

   // non-XML data
   EcU32Vector          m_vForceSensorIndices;      ///< the indices for the force sensors
   EcU32Vector          m_vEndEffectorIndices;      ///< the indices for the end effectors
   EcForceSensorVector  m_vForceSensors;            ///< the force sensors involved
   EcEndEffectorVector  m_vEndEffectors;            ///< the end effectors involved
};

#endif // ecBaseForceController_H_
