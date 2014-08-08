#ifndef ecMoveDirectionVisitor_H_
#define ecMoveDirectionVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecMoveDirectionVisitor.h
/// @class EcMoveDirectionVisitor
/// @brief Visitor implementation for moving a direction
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <manipulationDirector/ecManipulationDirectorVisitor.h>

/// Visitor implementation for moving a direction
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcMoveDirectionVisitor : public EcManipulationDirectorVisitor
{
public:
   EcMoveDirectionVisitor
      (
      EcU32           sceneIndex,
      const EcString& role,
      EcU32           oldDirectionIndex,
      EcU32           newDirectionIndex
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
   EcU32     m_SceneIndex;
   EcString  m_Role;
   EcU32     m_OldDirectionIndex;
   EcU32     m_NewDirectionIndex;
   EcBoolean m_Success;
};

#endif // ecMoveDirectionVisitor_H_
