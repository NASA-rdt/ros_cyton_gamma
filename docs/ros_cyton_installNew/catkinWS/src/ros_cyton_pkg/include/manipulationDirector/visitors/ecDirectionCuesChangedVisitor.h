#ifndef ecDirectionCuesChangedVisitor_H_
#define ecDirectionCuesChangedVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecDirectionCuesChangedVisitor.h
/// @class EcDirectionCuesChangedVisitor
/// @brief Visitor implementation for changing a direction's cues
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <manipulationDirector/ecManipulationDirectorVisitor.h>
#include <manipulationDirector/ecManipulationSceneCue.h>

/// Visitor implementation for changing a direction's cues
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcDirectionCuesChangedVisitor : public EcManipulationDirectorVisitor
{
public:
   EcDirectionCuesChangedVisitor
      (
      EcU32                               sceneIndex,
      const EcString&                     role,
      EcU32                               directionIndex,
      const EcManipulationSceneCueVector& oldCues,
      const EcManipulationSceneCueVector& newCues
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
   EcU32                        m_SceneIndex;
   EcString                     m_Role;
   EcU32                        m_DirectionIndex;
   EcManipulationSceneCueVector m_OldCues;
   EcManipulationSceneCueVector m_NewCues;
   EcBoolean                    m_Success;
};

#endif // ecDirectionCuesChangedVisitor_H_
