#ifndef ecManipulationActionState_H_
#define ecManipulationActionState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationActionState.h
/// @class EcManipulationActionState
/// @brief Abstract class defining the interface for manipulation action states.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

/// Abstract class defining the interface for manipulation action states.
class EC_ACTIN_MANIPULATION_DECL EcManipulationActionState : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationActionState
      (
      );

   /// destructor
   virtual ~EcManipulationActionState
      (
      );

   /// copy constructor
   EcManipulationActionState
      (
      const EcManipulationActionState& orig
      );

   /// assignment operator
   EcManipulationActionState& operator=
      (
      const EcManipulationActionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationActionState& orig
      ) const;
};

#endif // ecManipulationActionState_H_
