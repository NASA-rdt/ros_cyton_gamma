#ifndef ecManipulationDirectorVisitor_H_
#define ecManipulationDirectorVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectorVisitor.h
/// @class EcManipulationDirectorVisitor
/// @brief Virtual base class for defining visitor algorithms for manipulationDirector objects
//
//------------------------------------------------------------------------------

#include <foundCore/ecTypes.h>

// Forward declarations
class EcManipulationDirector;
class EcManipulationDirectorState;
class EcManipulationScene;
class EcManipulationSceneState;
class EcManipulationScript;
class EcManipulationScriptState;

/// Virtual base class for defining visitor algorithms for manipulationDirector objects
class EcManipulationDirectorVisitor
{
public:
   virtual EcBoolean success
      (
      ) const = 0;

   virtual void visit
      (
      EcManipulationDirector&      director,
      EcManipulationDirectorState* pState = 0
      ) = 0;

   virtual void visit
      (
      EcManipulationScript&      script,
      EcManipulationScriptState* pState = 0
      ) = 0;

   virtual void visit
      (
      EcManipulationScene&      scene,
      EcManipulationSceneState* pState = 0
      ) = 0;
};

#endif // ecManipulationDirectorVisitor_H_
