#ifndef ecManipulationSceneDirectionSimpleState_H_
#define ecManipulationSceneDirectionSimpleState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirectionSimpleState.h
/// @class EcManipulationSceneDirectionSimpleState
/// @brief Abstract class defining the interface for manipulation scene direction states.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

/// Abstract class defining the interface for manipulation scene direction states.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirectionSimpleState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationSceneDirectionSimpleState
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirectionSimpleState
      (
      );

   /// copy constructor
   EcManipulationSceneDirectionSimpleState
      (
      const EcManipulationSceneDirectionSimpleState& orig
      );

   /// assignment operator
   EcManipulationSceneDirectionSimpleState& operator=
      (
      const EcManipulationSceneDirectionSimpleState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirectionSimpleState& orig
      ) const;

   /// get the progress
   virtual EcReal progress
      (
      ) const = 0;
};

#endif // ecManipulationSceneDirectionSimpleState_H_
