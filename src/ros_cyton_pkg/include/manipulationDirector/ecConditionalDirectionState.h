#ifndef ecConditionalDirectionState_H_
#define ecConditionalDirectionState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecConditionalDirectionState.h
/// @class EcConditionalDirectionState
/// @brief Concrete implementation of EcManipulationSceneDirectionState for holding EcConditionalDirection state information.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationSceneDirectionState.h"
#include "ecManipulationSceneDirectionStateContainer.h"

#include <xml/ecXmlEnumType.h>

// Forward declarations
class EcConditionalDirection;
class EcManipulationDirection;

/// Concrete implementation of EcManipulationSceneDirectionState for holding EcConditionalDirection state information.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcConditionalDirectionState : public EcManipulationSceneDirectionState
{
public:
   enum
   {
      NO_FAILURE,
      PRE_CONDITION_FAILURE,
      PERSISTENT_CONDITION_FAILURE,
      POST_CONDITION_FAILURE,
      DIRECTION_FAILURE
   };

   /// default constructor
   EcConditionalDirectionState
      (
      );

   /// destructor
   virtual ~EcConditionalDirectionState
      (
      );

   /// copy constructor
   EcConditionalDirectionState
      (
      const EcConditionalDirectionState& orig
      );

   /// assignment operator
   EcConditionalDirectionState& operator=
      (
      const EcConditionalDirectionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcConditionalDirectionState& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
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
   friend class EcConditionalDirection;

   /// flag indicating if the preconditions have been checked
   EcXmlBoolean m_PreConditionsChecked;

   /// enumeration indicating the failure type
   EcXmlEnumU32 m_FailureType;

   /// index of the failure
   EcXmlU32     m_FailureIndex;

   /// flag indicating if the current active direction is complete
   EcXmlBoolean m_ActiveDirectionIsComplete;

   /// index of the current active direction
   EcXmlU32     m_ActiveDirectionIndex;

   /// states for exception directions to execute on precondition failure
   EcManipulationSceneDirectionStateContainerVectorVector m_PreConditionExceptionStates;

   /// states for exception directions to execute on persistent condition failure
   EcManipulationSceneDirectionStateContainerVectorVector m_PersistentConditionExceptionStates;

   /// states for exception directions to execute on postcondition failure
   EcManipulationSceneDirectionStateContainerVectorVector m_PostConditionExceptionStates;

   /// states for directions to execute during the nominal execution
   EcManipulationSceneDirectionStateContainerVector       m_DirectionStates;

   /// states exception directions to execute on direction failure
   EcManipulationSceneDirectionStateContainerVectorVector m_DirectionExceptionStates;

   /// progress of the direction (0.0 = not started, 1.0 = completed)
   EcXmlReal m_Progress;

   const EcManipulationDirection*     m_pActiveDirection;

   EcManipulationSceneDirectionState* m_pActiveDirectionState;
};

#endif // ecConditionalDirectionState_H_
