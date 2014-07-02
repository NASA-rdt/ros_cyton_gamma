#ifndef ecManipulationSceneSimpleState_H_
#define ecManipulationSceneSimpleState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneSimpleState.h
/// @class EcManipulationSceneSimpleState
/// @brief Holds EcManipulationScene state information
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationSceneDirectionSimpleStateContainer.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcManipulationScene;

/// Holds EcManipulationScene state information
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneSimpleState : public EcXmlCompoundType
{
public:
   enum WaitingState
   {
      NO_WAITING,
      WAITING,
      SIMULTANEOUS_WAITING,
      SIMULTANEOUS_WAITING_COMPLETE
   };

   typedef EcXmlMapType<EcXmlString, EcManipulationSceneDirectionSimpleStateContainerVector> RoleDirectionStatesMap;

   /// default constructor
   EcManipulationSceneSimpleState
      (
      );

   /// destructor
   virtual ~EcManipulationSceneSimpleState
      (
      );

   /// copy constructor
   EcManipulationSceneSimpleState
      (
      const EcManipulationSceneSimpleState& orig
      );

   /// assignment operator
   EcManipulationSceneSimpleState& operator=
      (
      const EcManipulationSceneSimpleState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneSimpleState& orig
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

   /// get the progress of the scene
   virtual EcReal progress
      (
      ) const;

   /// get the index of Current item 
   virtual EcU32 currentItemIndex
      (
      )const;

   /// get the map of roles to active directions
   virtual const EcXmlStringU32Map& roleActiveDirectionMap
      (
      ) const;

   /// return a pointer to the directions for a specified role
   virtual const EcManipulationSceneDirectionSimpleStateContainerVector* roleDirectionStates
      (
      const EcString& role
      ) const;

   /// set the direction states for a specified role
   virtual EcBoolean setRoleDirectionStates
      (
      const EcString&                                               role,
      const EcManipulationSceneDirectionSimpleStateContainerVector& directionStates
      );

   /// get the map of roles to direction states
   virtual const RoleDirectionStatesMap& roleDirectionStatesMap
      (
      ) const;

   /// get the map of roles to waiting states
   virtual const EcXmlStringU32Map& roleWaitingStatesMap
      (
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   friend class EcManipulationScene;

   /// Map of manipulation scene directions keyed by role
   RoleDirectionStatesMap                                m_RoleDirectionStatesMap;

   /// Map of active manipulation scene directions keyed by role
   EcXmlStringU32Map                                     m_RoleActiveDirectionMap;

   /// Map of active manipulation scene waiting state keyed by role
   EcXmlStringU32Map                                     m_RoleWaitingStateMap;

   /// Progress of the scene (0.0 = not started, 1.0 = completed)
   EcXmlReal                                             m_Progress;

   EcXmlU32                                              m_CurrentItemIndex;
};

typedef EcXmlVectorType<EcManipulationSceneSimpleState> EcManipulationSceneSimpleStateVector;

#endif // ecManipulationSceneSimpleState_H_
