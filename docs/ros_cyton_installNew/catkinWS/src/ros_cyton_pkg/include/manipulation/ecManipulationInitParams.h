#ifndef ecManipulationInitParams_H_
#define ecManipulationInitParams_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationInitParams.h
/// @class EcManipulationInitParams
/// @brief This class is a container for paremeters used for manipulation initialization
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

// Forward declarations
class EcStatedSystem;

class EC_ACTIN_MANIPULATION_DECL EcManipulationInitParams
{
public:
   /// constructor
   EcManipulationInitParams
      (
      const EcStatedSystem&    objectStatedSystem,
      EcU32                    objectIndex,
      const EcStatedSystem&    manipStatedSystem,
      EcU32                    manipIndex
      ) :
      m_ObjectStatedSystem(objectStatedSystem),
      m_ObjectIndex       (objectIndex),
      m_ManipStatedSystem (manipStatedSystem),
      m_ManipIndex        (manipIndex)
   {
   }

   /// get object stated system
   const EcStatedSystem& objectStatedSystem
      (
      ) const
   {
      return m_ObjectStatedSystem;
   }

   /// get object index
   EcU32 objectIndex
      (
      ) const
   {
      return m_ObjectIndex;
   }

   /// get manipulator stated system
   const EcStatedSystem& manipStatedSystem
      (
      ) const
   {
      return m_ManipStatedSystem;
   }

   /// get manipulator index
   EcU32 manipIndex
      (
      ) const
   {
      return m_ManipIndex;
   }

private:
   const EcStatedSystem&    m_ObjectStatedSystem;  ///< object stated system
   EcU32                    m_ObjectIndex;         ///< object index
   const EcStatedSystem&    m_ManipStatedSystem;   ///< manipulator stated system
   EcU32                    m_ManipIndex;          ///< manipulator index
};

#endif // ecManipulationInitParams_H_
