#ifndef ecFeedforwardManipJointController_H_
#define ecFeedforwardManipJointController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecFeedforwardManipJointController.h
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecBaseManipulatorJointController.h"
#include "ecIndJointController.h"

#include <manipulator/ecCrbiAccelerationTool.h>
#include <manipulator/ecManipExternalForce.h>
#include <manipulator/ecPositionState.h>
#include <manipulator/ecTotalTorqueTool.h>
#include <manipulator/ecVelocityState.h>
#include <xml/ecXmlVectorType.h>

class EcManipulatorTorque;
class EcIndividualManipulator;
class EcStatedSystem;

/** Holds a description of feedforward-feedback controllers for an entire manipulator.
*/
class EC_ACTIN_SIMULATION_DECL EcFeedforwardManipulatorJointController : public EcBaseManipulatorJointController
{
public:
   /// default constructor
   EcFeedforwardManipulatorJointController
      (
      );

   /// destructor
   virtual ~EcFeedforwardManipulatorJointController
      (
      );

   /// copy constructor
   EcFeedforwardManipulatorJointController
      (
      const EcFeedforwardManipulatorJointController& orig
      );

   /// assignment operator
   EcFeedforwardManipulatorJointController& operator=
      (
      const EcFeedforwardManipulatorJointController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFeedforwardManipulatorJointController& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
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

   /// gets the collection of controllers for each joint
   virtual const EcIndividualJointControllerCollection& jointControllerCollection
      (
      ) const;

   /// sets the collection of controllers for each joint
   virtual void setJointControllerCollection
      (
      const EcIndividualJointControllerCollection& jointControllerCollection
      );

   /// gets the default joint controller
   virtual const EcIndividualJointController& defaultJointController
      (
      ) const;

   /// sets the default joint controller
   virtual void setDefaultJointController
      (
      const EcIndividualJointController& defaultJointController
      );

   /// calculate control torques
   virtual void calculateControlTorques
      (
         const EcPositionState& actualPositionState,
         const EcVelocityState& actualVelocityState,
         const EcPositionState& desiredPositionState,
         const EcVelocityState& desiredVelocityState,
         const EcIndividualManipulator& manipulator,
         const EcStatedSystem& statedSystem,
         EcManipulatorTorque& manipulatorTorque
      ) const;

   /// calculate control inputs
   virtual void calculateControlInputs
      (
         const EcPositionState& actualPositionState,
         const EcVelocityState& actualVelocityState,
         const EcPositionState& desiredPositionState,
         const EcVelocityState& desiredVelocityState,
         const EcIndividualManipulator& manipulator,
         const EcStatedSystem& statedSystem,
         EcManipulatorControlInput& manipulatorControlInput
      ) const;

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
   static EcFeedforwardManipulatorJointController nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the joint controllers
   EcIndividualJointControllerCollection m_JointControllerCollection;

   /// the default joint controller
   EcIndividualJointController m_DefaultJointController;

   /// non-XML data below

   /// a utility external force vector
   mutable EcManipulatorExternalForce m_ManipulatorExternalForce;

   /// a utility acceleration state
   mutable EcAccelerationState m_AccelerationState;

   /// a forward-dynamics torque tool
   mutable EcTotalTorqueTool m_TotalTorqueTool;

   /// forward-dynamics torques
   mutable EcManipulatorTorque m_TotalTorques;

   /// is-on flags
   mutable EcBooleanVector m_IsOnFlags;

   /// a hybrid torque/acceleration tool
   mutable EcCrbiAccelerationTool   m_CrbiAccTool;
};

#endif // ecFeedforwardManipJointController_H_
