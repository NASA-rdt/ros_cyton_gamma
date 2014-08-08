#ifndef ecInsertDirectionVisitor_H_
#define ecInsertDirectionVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecInsertDirectionVisitor.h
/// @class EcInsertDirectionVisitor
/// @brief Visitor implementation for inserting a direction
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <manipulationDirector/ecManipulationSceneDirectionContainer.h>
#include <manipulationDirector/ecManipulationDirectorVisitor.h>

/// Visitor implementation for inserting a direction
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcInsertDirectionVisitor : public EcManipulationDirectorVisitor
{
public:
   EcInsertDirectionVisitor
      (
      EcU32                               sceneIndex,
      const EcString&                     role,
      const EcManipulationSceneDirection& direction,
      EcU32                               directionIndex
      );

   EcInsertDirectionVisitor
      (
      EcU32                                        sceneIndex,
      const EcString&                              role,
      const EcManipulationSceneDirectionContainer& directionContainer,
      EcU32                                        directionIndex
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
   EcU32                                 m_SceneIndex;
   EcString                              m_Role;
   EcManipulationSceneDirectionContainer m_DirectionContainer;
   EcU32                                 m_DirectionIndex;
   EcBoolean                             m_Success;
};

#endif // ecInsertDirectionVisitor_H_
