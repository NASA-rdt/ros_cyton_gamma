#ifndef ecManipulationDirectorUpdateParams_H_
#define ecManipulationDirectorUpdateParams_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectorUpdateParams.h
/// @class EcManipulationDirectorUpdateParams
/// @brief This class is a container for paremeters used for manipulation director updates
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

// Forward declarations
class EcForceControlSystem;
class EcPoseSet;
class EcPositionControlSystem;
class EcStatedSystem;

class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationDirectorUpdateParams
{
public:
   EcManipulationDirectorUpdateParams
      (
      const EcStatedSystem&          objectStatedSystem,
      const EcPositionControlSystem& manipPositionControlSystem,
      const EcForceControlSystem&    manipForceControlSystem,
      const EcStatedSystem&          manipStatedSystem,
      const EcPoseSet*               pPoseSet
      ) :
      m_ObjectStatedSystem         (objectStatedSystem),
      m_ManipPositionControlSystem (manipPositionControlSystem),
      m_ManipForceControlSystem    (manipForceControlSystem),
      m_ManipStatedSystem          (manipStatedSystem),
      m_pPoseSet                   (pPoseSet)
   {
   }

   inline const EcStatedSystem& objectStatedSystem
      (
      ) const
   {
      return m_ObjectStatedSystem;
   }

   inline const EcPositionControlSystem& manipPositionControlSystem
      (
      ) const
   {
      return m_ManipPositionControlSystem;
   }

   inline const EcForceControlSystem& manipForceControlSystem
      (
      ) const
   {
      return m_ManipForceControlSystem;
   }

   inline const EcStatedSystem& manipStatedSystem
      (
      ) const
   {
      return m_ManipStatedSystem;
   }

   inline const EcPoseSet* poseSetPtr
      (
      ) const
   {
      return m_pPoseSet;
   }

private:
   const EcStatedSystem&          m_ObjectStatedSystem;
   const EcPositionControlSystem& m_ManipPositionControlSystem;
   const EcForceControlSystem&    m_ManipForceControlSystem;
   const EcStatedSystem&          m_ManipStatedSystem;
   const EcPoseSet*               m_pPoseSet;
};

#endif // ecManipulationDirectorUpdateParams_H_
