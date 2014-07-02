#ifndef ecRemoveDirectionVisitor_H_
#define ecRemoveDirectionVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecRemoveDirectionVisitor.h
/// @class EcRemoveDirectionVisitor
/// @brief Visitor implementation for removing a direction
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <manipulationDirector/ecManipulationDirectorVisitor.h>

/// Visitor implementation for removing a direction
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcRemoveDirectionVisitor : public EcManipulationDirectorVisitor
{
public:
   EcRemoveDirectionVisitor
      (
      EcU32           sceneIndex,
      const EcString& role,
      EcU32           directionIndex
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
   EcU32     m_DirectionIndex;
   EcBoolean m_Success;
};

#endif // ecRemoveDirectionVisitor_H_
