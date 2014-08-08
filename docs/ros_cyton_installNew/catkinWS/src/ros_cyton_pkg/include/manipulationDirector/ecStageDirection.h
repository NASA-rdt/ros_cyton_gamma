#ifndef ecStageDirection_H_
#define ecStageDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageDirection.h
/// @class EcStageDirection
/// @brief Virtual base class of EcManipulationSceneDirection for implementing "stage" directions from the director.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationSceneDirection.h"

// Forward declarations
class EcManipulationDirectorState;

/// Virtual base class of EcManipulationSceneDirection for implementing "stage" directions from the director.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcStageDirection : public EcManipulationSceneDirection
{
public:
   /// default constructor
   EcStageDirection
      (
      );

   /// destructor
   virtual ~EcStageDirection
      (
      );

   /// copy constructor
   EcStageDirection
      (
      const EcStageDirection& orig
      );

   /// assignment operator
   EcStageDirection& operator=
      (
      const EcStageDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageDirection& orig
      ) const;

   /// apply the stage direction
   virtual EcBoolean apply
      (
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      EcManipulationDirectorState&              dstate
      ) const = 0;
};

#endif // ecStageDirection_H_
