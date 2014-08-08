#ifndef ecActionDirectionState_H_
#define ecActionDirectionState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecActionDirectionState.h
/// @class EcActionDirectionState
/// @brief Concrete implementation of EcManipulationSceneDirectionState for holding EcActionDirection state information.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationSceneDirectionState.h"
#include <manipulation/ecManipulationActionStateContainer.h>

// Forward declarations
class EcActionDirection;
class EcManipulationAction;

/// Concrete implementation of EcManipulationSceneDirectionState for holding EcActionDirection state information.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcActionDirectionState : public EcManipulationSceneDirectionState
{
public:
   /// default constructor
   EcActionDirectionState
      (
      );

   /// destructor
   virtual ~EcActionDirectionState
      (
      );

   /// copy constructor
   EcActionDirectionState
      (
      const EcActionDirectionState& orig
      );

   /// assignment operator
   EcActionDirectionState& operator=
      (
      const EcActionDirectionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcActionDirectionState& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the action
   virtual const EcManipulationAction* action
      (
      ) const;

   /// return a string token
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

protected:
   friend class EcActionDirection;

   const EcManipulationAction* m_pAction;

   EcManipulationActionStateContainer m_ActionStateContainer;
};

#endif // ecActionDirectionState_H_
