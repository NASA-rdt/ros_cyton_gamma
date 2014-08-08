#ifndef ecManipulationScriptState_H_
#define ecManipulationScriptState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationScriptState.h
/// @class EcManipulationScriptState
/// @brief Holds EcManipulationScript state information
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationSceneState.h"

#include <xml/ecXmlCompType.h>

// Forward declaration
class EcManipulationScript;

/// Holds EcManipulationScript state information
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationScriptState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationScriptState
      (
      );

   /// destructor
   virtual ~EcManipulationScriptState
      (
      );

   /// copy constructor
   EcManipulationScriptState
      (
      const EcManipulationScriptState& orig
      );

   /// assignment operator
   EcManipulationScriptState& operator=
      (
      const EcManipulationScriptState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationScriptState& orig
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

   /// get the currently active scene index in the script
   virtual EcU32 activeScene
      (
      ) const;

   /// get the flag indicating to advance to the next scene
   EcBoolean advanceToNextScene
      (
      ) const;

   /// get the progress of the script
   EcReal progress
      (
      ) const;

   /// get the current item index 
   EcU32 currentItemIndex
      (
      ) const;

   /// get the scene states contained in this script state
   virtual const EcManipulationSceneStateVector& sceneStates
      (
      ) const;

   /// set the scene states contained in this script state
   virtual void setSceneStates
      (
      const EcManipulationSceneStateVector& sceneStates
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   friend class EcManipulationScript;

   /// Vector of manipulation scene states that define the script state
   EcManipulationSceneStateVector m_SceneStates;

   /// Currently active scene index in the script
   EcXmlU32                       m_ActiveScene;

   /// Flag indicating to advance to the next scene
   EcXmlBoolean                   m_AdvanceToNextScene;

   /// Progress of the script (0.0 = not started, 1.0 = completed)
   EcXmlReal                      m_Progress;

   /// Progress of the script (0.0 = not started, 1.0 = completed)
   EcXmlU32                       m_CurrentItemIndex;
};

#endif // ecManipulationScriptState_H_
