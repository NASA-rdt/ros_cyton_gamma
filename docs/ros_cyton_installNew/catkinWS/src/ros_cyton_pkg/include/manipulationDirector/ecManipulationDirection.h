#ifndef ecManipulationDirection_H_
#define ecManipulationDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirection.h
/// @class EcManipulationDirection
/// @brief Virtual base class of EcManipulationSceneDirection for implementing "manipulation" directions from the director.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationSceneDirection.h"

// Forward declarations
class EcDataMap;
class EcManipulationDirectorState;
class EcManipulationSceneDirectionState;
class EcManipulatorEndEffectorPlacement;

/// Virtual base class of EcManipulationSceneDirection for implementing "manipulation" directions from the director.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationDirection : public EcManipulationSceneDirection
{
public:
   /// default constructor
   EcManipulationDirection
      (
      );

   /// destructor
   virtual ~EcManipulationDirection
      (
      );

   /// copy constructor
   EcManipulationDirection
      (
      const EcManipulationDirection& orig
      );

   /// assignment operator
   EcManipulationDirection& operator=
      (
      const EcManipulationDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationDirection& orig
      ) const;

   /// update the manipulation direction
   virtual EcManipulationStatus::Enum update
      (
      EcReal                                    time,
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      EcManipulationDirectorState&              dstate,
      EcManipulationSceneDirectionState&        sdstate
      ) const = 0;

   /// get a flag indicating if this direction is currently active
   virtual EcBoolean isActive
      (
      const EcManipulationSceneDirectionState& dstate
      ) const = 0;

   /// get the active control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationSceneDirectionState& dstate
      ) const = 0;

   /// get the active control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationSceneDirectionState& dstate
      ) const = 0;

   /// get the active end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationSceneDirectionState& dstate
      ) const = 0;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationSceneDirectionState& dstate
      ) const = 0;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationSceneDirectionState& dstate
      ) const = 0;

   /// get the progress of this direction
   virtual EcReal progress
      (
      const EcManipulationSceneDirectionState& dstate
      ) const = 0;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationSceneDirectionState& dstate,
      const EcString& separator
      ) const = 0;

   /// get the indices of end-effectors that should use profiled position control.
   /// Can be empty to indicate that no end-effector needs to use profiled position control.
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationSceneDirectionState& astate
      ) const = 0;
};

#endif // ecManipulationDirection_H_
