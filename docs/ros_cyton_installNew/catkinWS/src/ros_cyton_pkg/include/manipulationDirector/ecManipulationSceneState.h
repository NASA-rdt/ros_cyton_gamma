#ifndef ecManipulationSceneState_H_
#define ecManipulationSceneState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneState.h
/// @class EcManipulationSceneState
/// @brief Holds EcManipulationScene state information
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationSceneDirectionStateContainer.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcDataMap;
class EcManipulationDirection;
class EcManipulationScene;
class EcManipulatorEndEffectorPlacement;

/// Holds EcManipulationScene state information
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneState : public EcXmlCompoundType
{
public:
   enum WaitingState
   {
      NO_WAITING,
      WAITING,
      SIMULTANEOUS_WAITING,
      SIMULTANEOUS_WAITING_COMPLETE
   };

   typedef EcXmlMapType<EcXmlString, EcManipulationSceneDirectionStateContainerVector> RoleDirectionStatesMap;

   /// default constructor
   EcManipulationSceneState
      (
      );

   /// destructor
   virtual ~EcManipulationSceneState
      (
      );

   /// copy constructor
   EcManipulationSceneState
      (
      const EcManipulationSceneState& orig
      );

   /// assignment operator
   EcManipulationSceneState& operator=
      (
      const EcManipulationSceneState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneState& orig
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

   EcU32 currentItemIndex
      (
      )const;

   /// get the map of roles to active directions
   virtual const EcXmlStringU32Map& roleActiveDirectionMap
      (
      ) const;

   /// return a pointer to the directions for a specified role
   virtual const EcManipulationSceneDirectionStateContainerVector* roleDirectionStates
      (
      const EcString& role
      ) const;

   /// set the direction states for a specified role
   virtual EcBoolean setRoleDirectionStates
      (
      const EcString&                                         role,
      const EcManipulationSceneDirectionStateContainerVector& directionStates
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

   typedef std::pair<const EcManipulationDirection*, const EcManipulationSceneDirectionState*> ActiveManipulationPairType;
   typedef std::map<EcString, ActiveManipulationPairType> RoleActiveManipulationMapType;

   /// Map of manipulation scene directions keyed by role
   RoleDirectionStatesMap                                m_RoleDirectionStatesMap;

   /// Map of active manipulation scene directions keyed by role
   EcXmlStringU32Map                                     m_RoleActiveDirectionMap;

   /// Map of active manipulation scene waiting state keyed by role
   EcXmlStringU32Map                                     m_RoleWaitingStateMap;

   /// Progress of the scene (0.0 = not started, 1.0 = completed)
   EcXmlReal                                             m_Progress;

   EcXmlU32                                              m_CurrentItemIndex;

   // Non-XML calculated variables

   /// Vector of the currently active roles
   EcStringVector                                        m_ActiveRoles;

   RoleActiveManipulationMapType                         m_RoleActiveManipulationMap;

   EcU32Vector                                           m_ActiveControlDescriptions;
   EcU32Vector                                           m_ActiveControlMethods;
   EcU32Vector                                           m_ActiveEndEffectorSets;
   std::vector<const EcDataMap*>                         m_DataMaps;
   std::vector<const EcManipulatorEndEffectorPlacement*> m_EndEffectorPlacements;
   EcU32VectorVector                                     m_ProfiledPositionEndEffectorIndices;
};

typedef EcXmlVectorType<EcManipulationSceneState> EcManipulationSceneStateVector;

#endif // ecManipulationSceneState_H_
