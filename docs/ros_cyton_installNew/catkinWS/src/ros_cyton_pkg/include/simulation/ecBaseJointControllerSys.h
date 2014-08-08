#ifndef ecBaseJointControllerSys_H_
#define ecBaseJointControllerSys_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseJointControllerSys.h
/// @class EcBaseJointControllerSystem
/// @brief Holds a base class for joint controllers, which provides an interface
///        for all joint controllers.  It is initialized with a manipulator system, and then
///        given an actual state and a desired state to use to calculate the joint
///        torques.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <manipulator/ecManipSystem.h>
#include <manipulator/ecManipTorque.h>
#include <xml/ecBaseExpTreeElement.h>
#include "ecManipControlInput.h"
#include "ecManipJointController.h"

// forward declarations
class EcManipulatorSystemState;

/** Holds the base class for joint controllers.  This provides the interface
 for the controllers.  It is initialized with a manipulator system, and then
 given an actual state and a desired state to use to calculate the joint
 torques.
*/
class EC_ACTIN_SIMULATION_DECL EcBaseJointControllerSystem : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseJointControllerSystem
      (
      );

   /// destructor
   virtual ~EcBaseJointControllerSystem
      (
      );

   /// copy constructor
   EcBaseJointControllerSystem
      (
      const EcBaseJointControllerSystem& orig
      );

   /// assignment operator
   EcBaseJointControllerSystem& operator=
      (
      const EcBaseJointControllerSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseJointControllerSystem& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const=0;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// set the system pointer
   virtual void setSystemPointer
      (
      const EcManipulatorSystem* systemPointer
      );

   /// set which control torques/inputs are specified and should NOT be computed in calculateControlTorques or calculateControlInputs methods.
   /**
   \param[in] flags The size of flags should be the same size as the number of manipulators in the system.
   \see EcBaseManipulatorJointController::setSpecifyControlTorqueFlags
   */
   virtual EcBoolean setSpecifyControlTorqueFlags
      (
      const EcBooleanVectorVector& flags
      )=0;

   /// calculates control torques
   virtual void calculateControlTorques
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      EcManipulatorTorqueVector& manipulatorTorqueVector
      ) const=0;

   /// calculates control inputs
   virtual void calculateControlInputs
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      EcManipulatorControlInputVector& manipulatorControlInputVector
      ) const=0;

   /// merge with another generic joint controller system
   virtual EcBoolean mergeWith
      (
      const EcBaseJointControllerSystem* pOther,
      const EcStatedSystem& otherStatedSystem
      )=0;

   /// gets the flag indicating whether or not sensor noise should be added.
   virtual EcBoolean sensorNoiseFlag
      (
      ) const=0;

   /// sets the flag indicating whether or not sensor noise should be added.
   virtual void setSensorNoiseFlag
      (
      EcBoolean value
      )=0;

   /// add a default joint controller
   /**
   \return The index of the newly added joint controller.
   */
   virtual EcU32 addJointController
      (
      )=0;

   /// delete a joint controller at the given index
   /// \param[in] index The index of the joint controller to delete.
   /// \return EcBoolean Success or failure of the command.
   virtual EcBoolean deleteJointController
      (
      const EcU32 index
      )=0;

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

protected:
   /// pointer to the manipulator system
   const EcManipulatorSystem* m_SystemPointer;
};

#endif // ecBaseJointControllerSys_H_
