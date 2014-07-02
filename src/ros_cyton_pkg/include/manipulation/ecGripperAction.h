#ifndef ecGripperAction_H_
#define ecGripperAction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGripperAction.h
/// @class EcGripperAction
/// @brief A manipulation action for a simple 1-DOF gripper
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <control/ecEndEffectorSet.h>
#include <foundCommon/ecDataMap.h>
#include "ecManipulationAction.h"

// Forward declarations
class EcDataMap;

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcGripperAction : public EcManipulationAction
{
public:
   /// default constructor
   EcGripperAction
      (
      );

   /// destructor
   virtual ~EcGripperAction
      (
      );

   /// copy constructor
   EcGripperAction
      (
      const EcGripperAction& orig
      );

   /// assignment operator
   EcGripperAction& operator=
      (
      const EcGripperAction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGripperAction& orig
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

   /// get the gripper's fully open position. This is the position value of the end-effector that represents
   /// the gripper at the fully open position.
   virtual EcReal gripperOpenPosition
      (
      ) const;

   /// set the gripper's fully open position
   virtual void setGripperOpenPosition
      (
      EcReal value
      );

   /// get the gripper's fully closed position. This is the position value of the end-effector that represents
   /// the gripper at the fully closed position.
   virtual EcReal gripperClosedPosition
      (
      ) const;

   /// set the gripper's fully closed position
   virtual void setGripperClosedPosition
      (
      EcReal value
      );

   /// get the desired gripper's position in percent. 0 for fully closed and 100 for fully open.
   virtual EcReal gripperDesiredPositionPercentage
      (
      ) const;

   /// set the desired gripper's position in percent
   virtual void setGripperDesiredPositionPercentage
      (
      EcReal value
      );

   /// get the desired gripper's position in value
   virtual EcReal gripperDesiredPosition
      (
      ) const;

   /// get the EE index of the gripper
   virtual EcU32 endEffectorIndex
      (
      ) const;

   /// set the EE index of the gripper
   virtual void setEndEffectorIndex
      (
      EcU32 value
      );

   /// get the EE set index
   virtual EcU32 endEffectorSetIndex
      (
      ) const;

   /// set the EE set index
   virtual void setEndEffectorSetIndex
      (
      EcU32 value
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   //---
   // Implementation of EcManipulationAction interface
   //---

   /// initialize the manipulation sequence
   virtual EcBoolean init
      (
      EcManipulationActionStateContainer& astateContainer
      ) const;

   /// update the manipulation sequence
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationActionState& astate
      ) const;

   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationActionState&  astate
      ) const;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the overall progress of this action
   virtual EcReal progress
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationActionState& astate,
      const EcString& separator
      ) const;

   /// @copydoc EcManipulationAction::profiledPositionEndEffectorIndices()
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationActionState& astate
      ) const;

protected:
   /// compute goal position
   void computeGoalPosition
      (
      ) const;

   // XML data
   EcXmlReal      m_GripperOpenPosition;                 ///< gripper open position
   EcXmlReal      m_GripperClosedPosition;               ///< gripper closed position
   EcXmlReal      m_GripperDesiredPositionPercentage;    ///< gripper desired position percentage
   EcXmlU32       m_EndEffectorIndex;                    ///< end effector index
   EcXmlU32       m_EndEffectorSetIndex;                 ///< end effector set index

   // non-XML data
   mutable EcManipulatorEndEffectorPlacement    m_DesiredPlacement;  ///< desired placement
   mutable EcReal m_DesiredPosition;                     ///< desired position
   mutable EcReal m_InitialPosition;                     ///< initial position
   mutable EcBoolean m_InitialPositionIsSet;             ///< if the initial position is set

   static const EcDataMap                 m_theNullDataMap;          ///< the null data map
   static const EcEndEffectorSet          m_theNullEndEffectorSet;   ///< the null end effector set
   static const EcU32Vector               m_theNullU32Vector;        ///< the null U32 vector
};

#endif // ecGripperAction_H_
