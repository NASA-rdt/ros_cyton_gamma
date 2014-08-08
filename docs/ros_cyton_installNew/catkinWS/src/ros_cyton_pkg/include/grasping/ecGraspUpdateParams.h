#ifndef ecGraspUpdateParams_H_
#define ecGraspUpdateParams_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspUpdateParams.h
/// @class EcGraspUpdateParams
/// @brief This class is a container for paremeters used for grasp updates
/// @todo accessor implementation should be moved to the cpp file
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <foundCommon/ecDataMap.h>

// Forward declarations
class EcForceControlSystem;
class EcPositionControlSystem;
class EcStatedSystem;

class EC_ACTIN_GRASPING_DECL EcGraspUpdateParams
{
public:

   /// constructor with values
   EcGraspUpdateParams
      (
      const EcStatedSystem&          objectStatedSystem,
      EcU32                          objectIndex,
      const EcPositionControlSystem& manipPositionControlSystem,
      const EcForceControlSystem&    manipForceControlSystem,
      const EcStatedSystem&          manipStatedSystem,
      EcU32                          manipIndex
      ) :
      m_ObjectStatedSystem         (objectStatedSystem),
      m_ObjectIndex                (objectIndex),
      m_ManipPositionControlSystem (manipPositionControlSystem),
      m_ManipForceControlSystem    (manipForceControlSystem),
      m_ManipStatedSystem          (manipStatedSystem),
      m_ManipIndex                 (manipIndex),
      m_DataMap                    ()
   {
   }

   /// accessor for the object stated system
   const EcStatedSystem& objectStatedSystem
      (
      ) const
   {
      return m_ObjectStatedSystem;
   }

   /// accessor for the object index
   EcU32 objectIndex
      (
      ) const
   {
      return m_ObjectIndex;
   }

   /// accessor for the manipulator position control system
   const EcPositionControlSystem& manipPositionControlSystem
      (
      ) const
   {
      return m_ManipPositionControlSystem;
   }

   /// accesssor for the manipulator force control system
   const EcForceControlSystem& manipForceControlSystem
      (
      ) const
   {
      return m_ManipForceControlSystem;
   }

   /// accessor for the manipulator stated system
   const EcStatedSystem& manipStatedSystem
      (
      ) const
   {
      return m_ManipStatedSystem;
   }

   /// accessor for the manipulator index
   EcU32 manipIndex
      (
      ) const
   {
      return m_ManipIndex;
   }

   /// accessor for the data map
   EcDataMap& dataMap
      (
      ) const
   {
      return m_DataMap;
   }

private:
   const EcStatedSystem&          m_ObjectStatedSystem;
   EcU32                          m_ObjectIndex;
   const EcPositionControlSystem& m_ManipPositionControlSystem;
   const EcForceControlSystem&    m_ManipForceControlSystem;
   const EcStatedSystem&          m_ManipStatedSystem;
   EcU32                          m_ManipIndex;
   mutable EcDataMap              m_DataMap;
};

#endif // ecGraspUpdateParams_H_
