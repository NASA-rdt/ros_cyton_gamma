#ifndef ecManipulationSceneDirectionState_H_
#define ecManipulationSceneDirectionState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirectionState.h
/// @class EcManipulationSceneDirectionState
/// @brief Abstract class defining the interface for manipulation scene direction states.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

/// Abstract class defining the interface for manipulation scene direction states.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirectionState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationSceneDirectionState
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirectionState
      (
      );

   /// copy constructor
   EcManipulationSceneDirectionState
      (
      const EcManipulationSceneDirectionState& orig
      );

   /// assignment operator
   EcManipulationSceneDirectionState& operator=
      (
      const EcManipulationSceneDirectionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirectionState& orig
      ) const;
};

#endif // ecManipulationSceneDirectionState_H_
