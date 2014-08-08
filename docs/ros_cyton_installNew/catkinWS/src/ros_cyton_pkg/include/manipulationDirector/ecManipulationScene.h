#ifndef ecManipulationScene_H_
#define ecManipulationScene_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationScene.h
/// @class EcManipulationScene
/// @brief Organizes manipulation scene directions for multiple manipulator roles
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationSceneCue.h"
#include "ecManipulationSceneDirectionContainer.h"
#include <manipulation/ecManipulationStatus.h>

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcDataMap;
class EcManipulationDirector;
class EcManipulationDirectorState;
class EcManipulationDirectorUpdateParams;
class EcManipulationDirectorVisitor;
class EcManipulationSceneSimpleState;
class EcManipulationSceneState;
class EcManipulatorEndEffectorPlacement;

/// Organizes manipulation scene directions for multiple manipulator roles
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationScene : public EcXmlCompoundType
{
public:
   typedef EcXmlMapType<EcXmlString, EcManipulationSceneDirectionContainerVector> RoleDirectionsMap;
   typedef EcXmlMapType<EcXmlU32, EcManipulationSceneCueVector>                   DirectionCuesMap;
   typedef EcXmlMapType<EcXmlString, DirectionCuesMap>                            RoleCuesMap;

   /// default constructor
   EcManipulationScene
      (
      );

   /// destructor
   virtual ~EcManipulationScene
      (
      );

   /// copy constructor
   EcManipulationScene
      (
      const EcManipulationScene& orig
      );

   /// assignment operator
   EcManipulationScene& operator=
      (
      const EcManipulationScene& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationScene& orig
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

   /// return true if there there are no roles or directions in this scene
   virtual EcBoolean empty
      (
      ) const;

   /// clear this scene of all roles and directions
   virtual void clear
      (
      );

   /// merge a scene into this scene
   virtual void merge
      (
      const EcManipulationScene& scene
      );

   /// add a direction
   virtual EcBoolean add
      (
      const EcString&                     role,
      const EcManipulationSceneDirection& direction
      );

   /// add a direction
   virtual EcBoolean add
      (
      const EcString&                              role,
      const EcManipulationSceneDirectionContainer& direction
      );

   /// add a cue
   virtual EcBoolean add
      (
      const EcString&               role,
      EcU32                         directionIndex,
      const EcManipulationSceneCue& cue
      );

   /// return a pointer to the cues for a specified role
   virtual const DirectionCuesMap* roleCues
      (
      const EcString& role
      ) const;

   /// get the map of roles to cues
   virtual const RoleCuesMap& roleCuesMap
      (
      ) const;

   /// set the map of roles to cues
   virtual EcBoolean setRoleCuesMap
      (
      const RoleCuesMap& map
      );

   /// return a pointer to the directions for a specified role
   virtual const EcManipulationSceneDirectionContainerVector* roleDirections
      (
      const EcString& role
      ) const;

   /// set the directions for a specified role
   virtual EcBoolean setRoleDirections
      (
      const EcString&                                    role,
      const EcManipulationSceneDirectionContainerVector& directions
      );

   /// get the map of roles to directions
   virtual const RoleDirectionsMap& roleDirectionsMap
      (
      ) const;

   /// set the map of roles to directions
   virtual EcBoolean setRoleDirectionsMap
      (
      const RoleDirectionsMap& map
      );

   /// get the tag used for referencing this scene
   virtual const EcString& tag
      (
      ) const;

   /// set the tag used for referencing this scene
   virtual void setTag
      (
      const EcString& tag
      );

   /// get a vector of primary role names that are referenced within this scene
   virtual EcStringVector primaryRoleNames
      (
      ) const;

   /// get a vector of role names that are referenced within this scene
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// initialize the scene
   virtual EcBoolean init
      (
      const EcManipulationDirector& director,
      EcManipulationSceneState&     sstate
      ) const;

   /// update the scene
   virtual EcManipulationStatus::Enum update
      (
      EcReal                                    time,
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      EcManipulationDirectorState&              dstate,
      EcManipulationSceneState&                 sstate
      ) const;

   /// convert the manipulation scene state
   virtual void convert
      (
      const EcManipulationSceneState& sstate,
      EcManipulationSceneSimpleState& ssstate
      ) const;

   /// get the currently active roles
   virtual const EcStringVector& activeRoles
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// get the active control description index to be used for each active manipulator
   virtual const EcU32Vector& activeControlDescriptions
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// get the active control method index to be used for each active manipulator
   virtual const EcU32Vector& activeControlMethods
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// get the active end-effector set index to be used for each active manipulator
   virtual const EcU32Vector& activeEndEffectorSets
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// get the data map from each active manipulator
   virtual const std::vector<const EcDataMap*>& dataMaps
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// get the end-effector placement to be used for each active manipulator
   virtual const std::vector<const EcManipulatorEndEffectorPlacement*>& endEffectorPlacements
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// get the profiled position EE indices to be used for each active manipulator
   virtual const EcU32VectorVector& profiledPositionEndEffectorIndices
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// get the overall progress of the scene
   virtual EcReal progress
      (
      const EcManipulationSceneState& sstate
      ) const;

   /// determine the status string from each active manipulator
   virtual EcStringVector statusStrings
      (
      const EcManipulationSceneState& sstate,
      const EcString& separator
      ) const;

   /// Accept a visitor
   virtual void acceptDirectorVisitor
      (
      EcManipulationDirectorVisitor& visitor,
      EcManipulationSceneState*      pState = 0
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   virtual EcBoolean addCueImpl
      (
      const EcString&               role,
      EcU32                         directionIndex,
      const EcManipulationSceneCue& cue
      );

   virtual void calculateProgress
      (
      EcManipulationSceneState& sstate
      ) const;

   virtual EcBoolean initRole
      (
      const EcXmlString&            roleKey,
      const EcManipulationDirector& director,
      EcManipulationSceneState&     sstate
      ) const;

   virtual EcBoolean isWaiting
      (
      const EcXmlString&        roleKey,
      EcU32                     directionIndex,
      EcManipulationSceneState& sstate
      ) const;

   virtual EcManipulationStatus::Enum updateRole
      (
      EcReal                                    time,
      const EcXmlString&                        roleKey,
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      EcManipulationDirectorState&              dstate,
      EcManipulationSceneState&                 sstate
      ) const;

   /// Tag used for referencing this scene
   EcXmlString       m_Tag;

   /// Map of manipulation scene directions keyed by role
   RoleDirectionsMap m_RoleDirectionsMap;

   /// Map of manipulation cues keyed by role
   RoleCuesMap       m_RoleCuesMap;
};

typedef EcXmlVectorType<EcManipulationScene> EcManipulationSceneVector;

#endif // ecManipulationScene_H_
