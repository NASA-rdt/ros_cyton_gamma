#ifndef ecFeedforwardKinLoopsManipJointController_H_
#define ecFeedforwardKinLoopsManipJointController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecFeedforwardKinLoopsManipJointController.h
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecBaseManipulatorJointController.h"
#include "ecIndJointControllerContainer.h"
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


/** Holds a description of feedforward-feedback controllers for a manipulator with kinemtic loops
*/
class EC_ACTIN_SIMULATION_DECL EcFeedforwardKinLoopsManipulatorJointController : public EcBaseManipulatorJointController
{
public:
   /// type definition of ProxyJointMap
   typedef EcXmlMapType< EcXmlString, EcXmlPairType< EcXmlString, EcXmlBoolean> > ProxyJointMap;

   /// default constructor
   EcFeedforwardKinLoopsManipulatorJointController
      (
      );

   /// destructor
   virtual ~EcFeedforwardKinLoopsManipulatorJointController
      (
      );

   /// copy constructor
   EcFeedforwardKinLoopsManipulatorJointController
      (
      const EcFeedforwardKinLoopsManipulatorJointController& orig
      );

   /// assignment operator
   EcFeedforwardKinLoopsManipulatorJointController& operator=
      (
      const EcFeedforwardKinLoopsManipulatorJointController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFeedforwardKinLoopsManipulatorJointController& orig
      ) const;

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

   /// gets the joint controllers
   virtual const EcStringIndividualJointControllerContainerMap& jointControllerCollection
      (
      ) const;

   /// sets the joint controllers
   virtual void setJointControllerCollection
      (
      const EcStringIndividualJointControllerContainerMap& value
      );

   /// gets the proxy joints.
   virtual const ProxyJointMap& proxyJoints
      (
      ) const;

   /** sets the proxy joints. This is for some complex arms where some motors are located at different
   locations than the actual joints. For example, if joint3 is an elbow joint but its motor is located
   at joint1/1 and the forces are transmitted via some linkages. We can set up the proxy joints as follows

   EcXmlPairType< EcXmlString, EcXmlBoolean > pair;
   pair.setFirst(EcXmlString("joint1/1"));
   pair.setSecond(EcTrue);
   proxyJoints.add(EcXmlString("joint3"), pair);

   The individual controllers for joint3 and joint1/1 should be turned on
   and off, respectively. The torque for joint3 will be computed and then replace that of joint1/1 in the simulation.
   If the senses of joint3 and joint1/1 are opposite, then the flag needs to be set to false in
   pair.setSecond(EcFalse);
   */
   virtual void setProxyJoints
      (
      const ProxyJointMap& value
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
   static EcFeedforwardKinLoopsManipulatorJointController nullObject
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
   /// initialize components so we don't have to look up the map all the time
   void initialize
      (
      const EcIndividualManipulator& manipulator
      ) const;

   /// the joint controllers
   EcStringIndividualJointControllerContainerMap   m_JointControllerCollection;

   /// proxy joints map
   ProxyJointMap    m_ProxyJoints;

   // non-XML data below

   /// a utility acceleration state
   mutable EcAccelerationState m_AccelerationState;

   /// a forward-dynamics torque tool
   mutable EcTotalTorqueTool m_TotalTorqueTool;

   /// forward-dynamics torques
   mutable EcManipulatorTorque m_TotalTorques;

   /// a hybrid torque/acceleration tool
   mutable EcCrbiAccelerationTool   m_CrbiAccTool;

   /// a vector of EcBaseIndividualJointController
   mutable std::vector< const EcBaseIndividualJointController* >    m_vpJointControllers;
   /// number of direct torque joints
   mutable EcU32           m_NumDirectTorqueJoints;
   /// a vector of EcBoolean indicating which joint is under directo torque control 
   mutable EcBooleanVector m_DirectTorqueJoints;
   /// proxy joint indices
   mutable std::vector< std::pair< EcU32, EcU32 > >     m_vProxyJointIndices;
   /// proxy joint directions
   mutable std::vector< EcInt8 > m_vProxyJointDirections;

   /// a utility external force vector
   mutable EcManipulatorExternalForce m_ManipulatorExternalForce;
};

#endif // ecFeedforwardKinLoopsManipJointController_H_
