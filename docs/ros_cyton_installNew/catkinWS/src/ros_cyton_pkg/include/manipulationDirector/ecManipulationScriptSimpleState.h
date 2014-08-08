#ifndef ecManipulationScriptSimpleState_H_
#define ecManipulationScriptSimpleState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationScriptSimpleState.h
/// @class EcManipulationScriptSimpleState
/// @brief Holds EcManipulationScript simple state information
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationSceneSimpleState.h"

#include <xml/ecXmlCompType.h>

// Forward declaration
class EcManipulationScript;

/// Holds EcManipulationScript simple state information
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationScriptSimpleState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationScriptSimpleState
      (
      );

   /// destructor
   virtual ~EcManipulationScriptSimpleState
      (
      );

   /// copy constructor
   EcManipulationScriptSimpleState
      (
      const EcManipulationScriptSimpleState& orig
      );

   /// assignment operator
   EcManipulationScriptSimpleState& operator=
      (
      const EcManipulationScriptSimpleState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationScriptSimpleState& orig
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

   /// get the progress of the script
   EcReal progress
      (
      ) const;

   /// get the index of current item
   EcU32 currentItemIndex
      (
      ) const;

   /// get the scene states contained in this script state
   virtual const EcManipulationSceneSimpleStateVector& sceneStates
      (
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   friend class EcManipulationScript;

   /// Vector of manipulation scene states that define the script state
   EcManipulationSceneSimpleStateVector m_SceneStates;

   /// Currently active scene index in the script
   EcXmlU32                             m_ActiveScene;

   /// Progress of the script (0.0 = not started, 1.0 = completed)
   EcXmlReal                            m_Progress;

   /// index of current item at play
   EcXmlU32                             m_CurrentItemIndex;
};

#endif // ecManipulationScriptSimpleState_H_
