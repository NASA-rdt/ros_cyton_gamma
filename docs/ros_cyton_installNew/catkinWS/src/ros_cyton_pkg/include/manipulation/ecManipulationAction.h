#ifndef ecManipulationAction_H_
#define ecManipulationAction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationAction.h
/// @class EcManipulationAction
/// @brief Virtual base class for manipulation actions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationStatus.h"

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcDataMap;
class EcEndEffectorSet;
class EcManipulationActionState;
class EcManipulationActionStateContainer;
class EcManipulationUpdateParams;
class EcManipulatorEndEffectorPlacement;

/// Virtual base class for manipulation actions.
class EC_ACTIN_MANIPULATION_DECL EcManipulationAction : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationAction
      (
      );

   /// destructor
   virtual ~EcManipulationAction
      (
      );

   /// copy constructor
   EcManipulationAction
      (
      const EcManipulationAction& orig
      );

   /// assignment operator
   EcManipulationAction& operator=
      (
      const EcManipulationAction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationAction& orig
      ) const;

   /// initialize the manipulation action
   virtual EcBoolean init
      (
      EcManipulationActionStateContainer& astateContainer
      ) const = 0;

   /// update the manipulation action
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const = 0;

   /// get the active control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationActionState& astate
      ) const = 0;

   /// get the active control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationActionState& astate
      ) const = 0;

   /// get the active end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationActionState& astate
      ) const = 0;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationActionState& astate
      ) const = 0;

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const = 0;

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationActionState& astate
      ) const = 0;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationActionState& astate
      ) const = 0;

   /// get the overall progress of this action
   virtual EcReal progress
      (
      const EcManipulationActionState& astate
      ) const = 0;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationActionState& astate,
      const EcString& separator
      ) const = 0;

   /// get the indices of end-effectors that should use profiled position control.
   /// Can be empty to indicate that no end-effector needs to use profiled position control.
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationActionState& astate
      ) const = 0;

   /// returns the index of current item in an manipulation action while execution
   virtual EcU32 currentItemAtPlay
      (
      const EcManipulationActionState& astate
      ) const ;
  
};

#endif // ecManipulationAction_H_
