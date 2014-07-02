#ifndef ecJointControllerSystem_H_
#define ecJointControllerSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointControllerSystem.h
/// @class EcJointControllerSystem
/// @brief Holds joint controllers for a manipulator system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <manipulator/ecManipTorque.h>

#include "ecBaseJointControllerSys.h"
#include "ecManipJointController.h"
#include "ecManipulatorJointControllerVector.h"

/// Holds joint controllers for a manipulator system.
class EC_ACTIN_SIMULATION_DECL EcJointControllerSystem : public EcBaseJointControllerSystem
{
public:
   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcJointControllerSystem);

   /// merge operation with another EcJointControllerSystem
   virtual EcBoolean mergeWith
      (
      const EcJointControllerSystem& orig
      );

   /// merge with another generic joint controller system
   virtual EcBoolean mergeWith
      (
      const EcBaseJointControllerSystem* pOther,
      const EcStatedSystem& otherStatedSystem
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the manipulator-level joint controllers (old form)
   /**
   \deprecated
   */
   virtual const EcXmlVectorType<EcManipulatorJointController>& manipulatorJointControllers
      (
      ) const;

   /// sets the manipulator-level joint controllers (old form)
   /**
   \deprecated
   */
   virtual void setManipulatorJointControllers
      (
      const EcXmlVectorType<EcManipulatorJointController>& manipulatorJointControllers
      );

   /// gets the manipulator-level joint controllers
   virtual const EcManipulatorJointControllerVector& variableManipulatorJointControllers
      (
      ) const;

   /// sets the manipulator-level joint controllers
   virtual void setVariableManipulatorJointControllers
      (
      const EcManipulatorJointControllerVector& variableManipulatorJointControllers
      );

   /// gets the flag indicating whether or not sensor noise should be added.
   virtual EcBoolean sensorNoiseFlag
      (
      ) const;

   /// sets the flag indicating whether or not sensor noise should be added.
   virtual void setSensorNoiseFlag
      (
      EcBoolean value
      );

   /// gets the one sigma values for joint position sensors for all manipulators
   virtual const EcXmlRealVectorVector& jointPositionOneSigmas
      (
      ) const;

   /// sets the one sigma values for joint position sensors for all manipulators
   virtual void setJointPositionOneSigmas
      (
      const EcXmlRealVectorVector& values
      );

   /// gets the one sigma values for joint velocity sensors for all manipulators
   virtual const EcXmlRealVectorVector& jointVelocityOneSigmas
      (
      ) const;

   /// sets the one sigma values for joint velocity sensors for all manipulators
   virtual void setJointVelocityOneSigmas
      (
      const EcXmlRealVectorVector& values
      );

   // No doxygen tags - pull them from base class.
   virtual EcBoolean setSpecifyControlTorqueFlags
      (
      const EcBooleanVectorVector& flags
      );

   /// calculates control torques
   virtual void calculateControlTorques
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      EcManipulatorTorqueVector& manipulatorTorqueVector
      ) const;

   /// calculates control inputs
   virtual void calculateControlInputs
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      EcManipulatorControlInputVector& manipulatorControlInputVector
      ) const;

   /// \copydoc EcBaseJointControllerSystem::addJointController
   virtual EcU32 addJointController
      (
      );

   /// \copydoc EcBaseJointControllerSystem::deleteJointController
   virtual EcBoolean deleteJointController
      (
      const EcU32 index
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

   /// get a null object
   static EcJointControllerSystem nullObject
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// add sensor noise to the measurements
   virtual void addSensorNoise
      (
      const EcXmlRealVector& measurements,
      const EcXmlRealVector& oneSigmas,
      EcXmlRealVector& measurementsWithNoise
      ) const;

protected:
   /// convert the old form of holding joint controllers to the new form
   virtual void convertOldFormToNew
      (
      );

   /// the joint controllers for the individual manipulators (old form)
   EcXmlVectorType<EcManipulatorJointController>  m_ManipulatorJointControllers;

   /// the variable-type joint controllers for the individual manipulators
   EcManipulatorJointControllerVector  m_VariableManipulatorJointControllers;

   /// the flag indicating whether or not the sensor noise should be added
   EcXmlBoolean            m_SensorNoiseFlag;

   /// the one sigma values for joint position sensors for all manipulators
   mutable EcXmlRealVectorVector       m_vJointPositionOneSigmas;

   /// the one sigma values for joint velocity sensors for all manipulators
   mutable EcXmlRealVectorVector       m_vJointVelocityOneSigmas;

   /// non-XML data
   /// utility position state
   mutable EcPositionState             m_UtilityPositionState;

   /// utility velocity state
   mutable EcVelocityState             m_UtilityVelocityState;
};

#endif // ecJointControllerSystem_H_
