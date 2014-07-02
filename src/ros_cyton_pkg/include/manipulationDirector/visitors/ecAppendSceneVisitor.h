#ifndef ecAppendSceneVisitor_H_
#define ecAppendSceneVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecAppendSceneVisitor.h
/// @class EcAppendSceneVisitor
/// @brief Visitor implementation for appending a scene
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <manipulationDirector/ecManipulationDirectorVisitor.h>
#include <manipulationDirector/ecManipulationScene.h>
#include <manipulationDirector/ecManipulationSceneState.h>

/// Visitor implementation for appending a scene
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcAppendSceneVisitor : public EcManipulationDirectorVisitor
{
public:
   EcAppendSceneVisitor
      (
      const EcManipulationScene& scene
      );

   virtual EcBoolean success
      (
      ) const;

   virtual void visit
      (
      EcManipulationDirector&      director,
      EcManipulationDirectorState* pState = 0
      );

   virtual void visit
      (
      EcManipulationScript&      script,
      EcManipulationScriptState* pState = 0
      );

   virtual void visit
      (
      EcManipulationScene&      scene,
      EcManipulationSceneState* pState = 0
      );

protected:
   EcManipulationScene      m_Scene;
   EcManipulationSceneState m_SceneState;
   EcBoolean                m_Success;
};

#endif // ecAppendSceneVisitor_H_
