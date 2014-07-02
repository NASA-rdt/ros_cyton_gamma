#ifndef ecManipulationScript_H_
#define ecManipulationScript_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationScript.h
/// @class EcManipulationScript
/// @brief Organizes multiple manipulation scenes
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationScene.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcManipulationDirectorState;
class EcManipulationScriptSimpleState;
class EcManipulationScriptState;

/// Organizes multiple manipulation scenes
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationScript : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationScript
      (
      );

   /// destructor
   virtual ~EcManipulationScript
      (
      );

   /// copy constructor
   EcManipulationScript
      (
      const EcManipulationScript& orig
      );

   /// assignment operator
   EcManipulationScript& operator=
      (
      const EcManipulationScript& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationScript& orig
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

   /// add a scene to this script
   virtual EcBoolean add
      (
      const EcManipulationScene& scene
      );

   /// clear this script of all scenes
   virtual void clear
      (
      );

   /// return true if there there are no scenes in this script
   virtual EcBoolean empty
      (
      ) const;

   /// get the scenes contained in this script
   virtual const EcManipulationSceneVector& scenes
      (
      ) const;

   /// set the scenes contained in this script
   virtual void setScenes
      (
      const EcManipulationSceneVector& scenes
      );

   /// get the flag indicating if the completed script should loop back to the beginning
   virtual EcBoolean loopFlag
      (
      ) const;

   /// set the flag indicating if the completed script should loop back to the beginning
   virtual void setLoopFlag
      (
      EcBoolean flag
      );

   /// get a vector of primary role names that are referenced within this script
   virtual EcStringVector primaryRoleNames
      (
      ) const;

   /// get a vector of role names that are referenced within this script
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// initialize the script
   virtual EcBoolean init
      (
      const EcManipulationDirector& director,
      EcManipulationScriptState&    sstate
      ) const;

   /// update the script
   virtual EcManipulationStatus::Enum update
      (
      EcReal                                    time,
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      EcManipulationDirectorState&              dstate,
      EcManipulationScriptState&                sstate
      ) const;

   /// convert the manipulation script state
   virtual void convert
      (
      const EcManipulationScriptState& sstate,
      EcManipulationScriptSimpleState& ssstate
      ) const;

   /// determine the currently active roles
   virtual const EcStringVector& activeRoles
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// get the active control description index to be used for each active manipulator
   virtual const EcU32Vector& activeControlDescriptions
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// get the active control method index to be used for each active manipulator
   virtual const EcU32Vector& activeControlMethods
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// get the active end-effector set index to be used for each active manipulator
   virtual const EcU32Vector& activeEndEffectorSets
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// get the data map from each active manipulator
   virtual const std::vector<const EcDataMap*>& dataMaps
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// get the end-effector placement to be used for each active manipulator
   virtual const std::vector<const EcManipulatorEndEffectorPlacement*>& endEffectorPlacements
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// get the profiled position EE indices to be used for each active manipulator
   virtual const EcU32VectorVector& profiledPositionEndEffectorIndices
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// get the overall progress of the script
   virtual EcReal progress
      (
      const EcManipulationScriptState& sstate
      ) const;

   /// determine the status string from each active manipulator
   virtual EcStringVector statusStrings
      (
      const EcManipulationScriptState& sstate,
      const EcString& separator
      ) const;

   /// Accept a visitor
   virtual void acceptDirectorVisitor
      (
      EcManipulationDirectorVisitor& visitor,
      EcManipulationScriptState*     pState = 0
      );

   /// Traverse through sub objects with visitor
   virtual void traverseDirectorVisitor
      (
      EcManipulationDirectorVisitor& visitor,
      EcManipulationScriptState*     pState = 0
      );

   /// Traverse through a specified sub object with visitor
   virtual void traverseDirectorVisitor
      (
      EcU32                          index,
      EcManipulationDirectorVisitor& visitor,
      EcManipulationScriptState*     pState = 0
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// Vector of manipulation scenes that define the script
   EcManipulationSceneVector m_Scenes;

   /// Flag indicating if the completed script should loop back to the beginning
   EcXmlBoolean              m_LoopFlag;
};

#endif // ecManipulationScript_H_
