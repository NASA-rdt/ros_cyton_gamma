#ifndef ecForceControlSystem_H_
#define ecForceControlSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceControlSystem.h
/// @class EcForceControlSystem
/// @brief Holds a description of a force control system, which
///        use a position control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceControlDescription.h"
#include "ecForceSensorSet.h"

#include <control/ecEndEffectorSet.h>
#include <xml/ecXmlVectorType.h>

/// vector of EcManipulatorEndEffectorPlacement
typedef EcXmlVectorType<EcManipulatorEndEffectorPlacement>
   EcManipulatorEndEffectorPlacementVector;

/**
This is a class for position-based force control system. Force control works by adjusting the desired end-effector placements to achieve the desired end-effector forces.
*/
class EC_ACTIN_FORCECONTROL_DECL EcForceControlSystem : public EcXmlCompoundType
{
public:

   /// default constructor
   EcForceControlSystem
      (
      );

   /// destructor
   virtual ~EcForceControlSystem
      (
      );

   /// copy constructor
   EcForceControlSystem
      (
      const EcForceControlSystem& orig
      );

   /// assignment operator
   EcForceControlSystem& operator=
      (
      const EcForceControlSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceControlSystem& orig
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

   /// token
   virtual const EcToken& token
      (
      ) const;


   /// gets a flag indicating whether or not the position control system is on
   virtual EcBoolean isOn
      (
      ) const;

   /// sets a flag indicating whether or not the position control system is on
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// gets the control description vectors
   virtual const EcForceControlDescriptionVectorVector& controlDescriptionVectors
      (
      ) const;

   /// sets the control description vectors
   virtual void setControlDescriptionVectors
      (
      const EcForceControlDescriptionVectorVector& controlDescriptionVectors
      );

   /// adds a control description to a manipulator
   /**
   \param[in] manipIndex The index of the manipulator to which the control description will be added.
   \param[in] controlDescription The control description to be added.
   \return True if successful or false if manipIndex is out of range.
   */
   virtual EcBoolean addControlDescription
      (
      EcU32 manipIndex,
      const EcForceControlDescription& controlDescription
      );

   /// sets a control description at a specified index of a given manipulator
   /**
   \param[in] manipIndex The index of the manipulator to which the control description will be added.
   \param[in] controlDescriptionIndex The index of the control description to be set.
   \param[in] controlDescription The control description to be added.
   \return True if successful or false if manipIndex or controlDescriptionIndex is out of range.
   */
   virtual EcBoolean setControlDescription
      (
      EcU32 manipIndex,
      EcU32 controlDescriptionIndex,
      const EcForceControlDescription& controlDescription
      );

   /// deletes a control description from a manipulator
   /**
   Deletes a control description from a manipulator. Note the after this operation, the indices of control descriptions for that manipulator may be shifted.
   \param[in] manipIndex The index of the manipulator from which a control description will be deleted.
   \param[in] controlDescriptionIndex The index of the control description to be deleted. If this index is currently the active index, then the active index will be changed to 0.
   \return True if successful or false if manipIndex or controlDescriptionIndex is out of range. Also, if there's only one control description for this manipulator, then it will not be deleted and false will be returned.
   */
   virtual EcBoolean deleteControlDescription
      (
      EcU32 manipIndex,
      EcU32 controlDescriptionIndex
      );

   /// deletes the list of control descriptions of a manipulator
   /**
   Deletes the list of control descriptions of a manipulator. Since end-effector set and end-effector relative data are parts of control description, they will also be deleted.
   \param[in] manipIndex The index of the manipulator from which the control descriptions will be deleted.
   \return True if successful or false if manipIndex is out of range.
   */
   virtual EcBoolean deleteControlDescriptions
      (
      EcU32 manipIndex
      );

   /// gets the list of control descriptions for a manipulator
   /**
   \param[in] manipIndex The index of the manipulator from which the control description is queried.
   \return The list of control descriptions for the specified manipulator or null object if manipIndex is out of range.
   */
   virtual const EcForceControlDescriptionVector& controlDescriptions
      (
      EcU32 manipIndex
      ) const;

   /// sets the control descriptions of a manipulator
   /**
   \param[in] controlDescriptions The control descriptions to be set.
   \param[in] manipIndex The index of the manipulator to which the control descriptions will be set.
   \return True if successful or false if manipIndex is out of range.
   */
   virtual EcBoolean setControlDescriptions
      (
      EcU32 manipIndex,
      const EcForceControlDescriptionVector& controlDescriptions
      );

   /// adds a list of control descriptions for a new manipulator.
   /**
   Adds a list of control descriptions for a new manipulator (not yet in index). This will increment the index by one. The index of active control description for the new manipulator will be set to 0. Call setActiveControlDescription(EcU32, EcU32) to set the active control description as desired.
   \param[in] controlDescriptions The vector of control descriptions to be added.
   \return The index of the newly added vector of control descriptions.
   */
   virtual EcU32 addControlDescriptions
      (
      const EcForceControlDescriptionVector& controlDescriptions
      );

   /// gets the active control description for the specified manipulator index
   /**
   \param[in] manipIndex The manipulator index in query.
   \return The active control description for manipIndex.
   */
   virtual const EcForceControlDescription& activeControlDescription
      (
      EcU32 manipIndex
      ) const;

   /// sets the active control description of a manipulator by index
   /**
   \param[in] manipIndex The index of the manipulator to which the control descriptions will be set.
   \param[in] activeControlDescriptionIndex The index of the active control description to be set.
   \return True if successful or false if either manipIndex or activeControlDescriptionIndex is out of range.
   */
   virtual EcBoolean setActiveControlDescription
      (
      EcU32 manipIndex,
      EcU32 activeControlDescriptionIndex
      );

   /// gets the index of the active control description of the specified manipulator
   /**
   \param[in] manipIndex The index of the manipulator in query.
   \return The index of the active control description of the specified manipulator.
   */
   virtual EcU32 activeControlDescriptionIndex
      (
      EcU32 manipIndex
      ) const;

   /// get the force sensor sets for all the manipulators
   virtual const EcForceSensorSetVector& forceSensorSets
      (
      ) const;

   /// set the force sensor sets for all the manipulators
   virtual void setForceSensorSets
      (
      const EcForceSensorSetVector& sensorSetVec
      );

   /// set the force sensor set for a given manipulator
   virtual EcBoolean setForceSensorSet
      (
      EcU32 manipIndex,
      const EcForceSensorSet& sensorSet
      );

   /// get the desired sensor forces for all manipulators
   virtual const EcManipulatorSensorForceVector& desiredForceVector
      (
      ) const;

   /// set the desired force for a particular sensor
   virtual EcBoolean setDesiredForce
      (
      EcU32 manipIndex,
      EcU32 sensorIndex,
      const EcXmlRealVector& desiredForce
      );

   /// set the desired sensor force for a given manipulator
   virtual EcBoolean setDesiredForce
      (
      EcU32 manipIndex,
      const EcManipulatorSensorForce& desiredForce
      );

   /// set the desired sensor forces for all manipulators
   virtual void setDesiredForceVector
      (
      const EcManipulatorSensorForceVector& desiredForceVec
      );

   /// get the measured sensor force for all manipulators
   virtual const EcManipulatorSensorForceVector& measuredForceVector
      (
      ) const;

   /// set the measured sensor force for a particular sensor
   virtual EcBoolean setMeasuredForce
      (
      EcU32 manipIndex,
      EcU32 sensorIndex,
      const EcXmlRealVector& measuredForce
      );

   /// set the measured sensor force for a given manipulator
   virtual EcBoolean setMeasuredForce
      (
      EcU32 manipIndex,
      const EcManipulatorSensorForce& measuredForce
      );

   /// set the measured sensor forces for all manipulators
   virtual void setMeasuredForceVector
      (
      const EcManipulatorSensorForceVector& measuredForceVec
      );

   /// turn on/off a group of force controllers for a given manipulator
   /**
   \return False if manipIndex is invalid or true otherwise
   */
   virtual EcBoolean enableForceControllers
      (
      EcU32 manipIndex,
      const EcU32Vector& controllerIndices,
      EcBoolean isOn
      );

   /// turn on/off individual force controllers for a given manipulator
   /**
   \return False if manipIndex is invalid or true otherwise
   */
   virtual EcBoolean enableForceControllers
      (
      EcU32 manipIndex,
      const EcBooleanVector& controllersOn
      );

   /// initialize the force control system with the vector of end-effector sets.
   virtual void initialize
      (
      const EcEndEffectorSetVector& eeSetVec
      );

   /// adjust desiredPlacementVec to achieve the desired end-effector forces
   virtual EcBoolean adjustDesiredPlacementVector
      (
      const EcReal& time,
      const EcPositionControlSystem& posCont,
      const EcManipulatorEndEffectorPlacementVector& actualPlacementVec,
      EcManipulatorEndEffectorPlacementVector& desiredPlacementVec
      ) const;

   /// simulate sensor reading when sensor is dynamically simulated.
   virtual EcBoolean simulateMeasuredForces
      (
      EcSystemActiveState&      actState,
      const EcStatedSystem&     statedSystem
      ) const;

   /// Merges this with another so that this contains both.
   virtual EcBoolean mergeWith
      (
      const EcForceControlSystem& other
      );

   /// \copydoc EcXmlCompoundType::read()
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

protected:
   /// gets the active control description for the specified manipulator index -- non-const, internal use only
   virtual EcForceControlDescription& activeControlDesc
      (
      EcU32 manipIndex
      );

   /// initlialize the desired and measured forces to the proper sizes
   virtual void initializeForces
      (
      );
protected:
   /// a flag indicating whether or not the force control system is on
   EcXmlBoolean                  m_IsOn;

   /// vectors of control description vectors
   EcForceControlDescriptionVectorVector        m_ControlDescriptionVectors;

   /// the indices of active control descriptions
   EcXmlU32Vector                               m_ActiveControlDescriptionIndices;

   /// a vector for all the force sensor sets in the system
   EcForceSensorSetVector                       m_vForceSensorSets;

   // non-XML data
   /// the desired sensor forces
   mutable EcManipulatorSensorForceVector               m_vDesiredForces;

   /// the measured sensor forces
   mutable EcManipulatorSensorForceVector               m_vMeasuredlForces;

   /// the time of the previous cycle
   mutable EcReal             m_PrevTime;

   /// the null control description for error recovery
   static EcForceControlDescription             m_theNullControlDescription;

   /// the null control description vector for error recovery
   static const EcForceControlDescriptionVector m_theNullControlDescriptions;

   /// the null force sensor set for error recovery
   static const EcForceSensorSet   m_theNullForceSensorSet;
};

#endif // ecForceControlSystem_H_
