#ifndef ecManipulationUpdateParams_H_
#define ecManipulationUpdateParams_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationUpdateParams.h
/// @class EcManipulationUpdateParams
/// @brief This class is a container for paremeters used for manipulation updates
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <foundCommon/ecDataMap.h>

// Forward declarations
class EcForceControlSystem;
class EcPoseSet;
class EcPositionControlSystem;
class EcStatedSystem;

class EC_ACTIN_MANIPULATION_DECL EcManipulationUpdateParams
{
public:
   /// constructor
   EcManipulationUpdateParams
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
      m_pPoseSet                   (EcNULL),
      m_DataMap                    (),
      m_pCast                      (EcNULL)
   {
   }

   /// get objected system
   inline const EcStatedSystem& objectStatedSystem
      (
      ) const
   {
      return m_ObjectStatedSystem;
   }

   /// get object index
   inline EcU32 objectIndex
      (
      ) const
   {
      return m_ObjectIndex;
   }

   /// get manipulator position control system
   inline const EcPositionControlSystem& manipPositionControlSystem
      (
      ) const
   {
      return m_ManipPositionControlSystem;
   }

   /// get manipulator force control system
   inline const EcForceControlSystem& manipForceControlSystem
      (
      ) const
   {
      return m_ManipForceControlSystem;
   }

   /// get manipulator stated system
   inline const EcStatedSystem& manipStatedSystem
      (
      ) const
   {
      return m_ManipStatedSystem;
   }

   /// get manipulator index
   inline EcU32 manipIndex
      (
      ) const
   {
      return m_ManipIndex;
   }

   /// set pose set pointer
   inline void setPoseSetPtr
      (
      const EcPoseSet* poseSet
      )
   {
      m_pPoseSet=poseSet;
   }

   /// get pose set pointer
   inline const EcPoseSet* poseSetPtr
      (
      ) const
   {
      return m_pPoseSet;
   }

   /// get data map
   inline EcDataMap& dataMap
      (
      ) const
   {
      return m_DataMap;
   }

   /// set cast pointer
   inline void setCastPtr
      (
      const EcXmlStringU32Map* pCast
      )
   {
      m_pCast=pCast;
   }

   /// get cast pointer
   inline const EcXmlStringU32Map* castPtr
      (
      ) const
   {
      return m_pCast;
   }

private:
   const EcStatedSystem&          m_ObjectStatedSystem;           ///< object stated system
   EcU32                          m_ObjectIndex;                  ///< object index
   const EcPositionControlSystem& m_ManipPositionControlSystem;   ///< manipulator position control system
   const EcForceControlSystem&    m_ManipForceControlSystem;      ///< manipulator force control system
   const EcStatedSystem&          m_ManipStatedSystem;            ///< manipulator stated system
   EcU32                          m_ManipIndex;                   ///< manipulator index
   const EcPoseSet*               m_pPoseSet;                     ///< pose set
   mutable EcDataMap              m_DataMap;                      ///< data map
   const EcXmlStringU32Map*       m_pCast;                        ///< cast
};

#endif // ecManipulationUpdateParams_H_
