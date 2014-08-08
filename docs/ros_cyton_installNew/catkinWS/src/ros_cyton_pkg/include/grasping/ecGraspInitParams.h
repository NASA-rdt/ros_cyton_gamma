#ifndef ecGraspInitParams_H_
#define ecGraspInitParams_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspInitParams.h
/// @class EcGraspInitParams
/// @brief This class is a container for paremeters used for grasp initialization
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecShapeFeatureHistogram.h"

// Forward declarations
class EcGraspDescriptor;
class EcStatedSystem;

class EC_ACTIN_GRASPING_DECL EcGraspInitParams
{
public:

   /// constructor with parameters
   EcGraspInitParams
      (
      const EcGraspDescriptor& graspDescriptor,
      const EcStatedSystem&    objectStatedSystem,
      EcU32                    objectIndex,
      const EcStatedSystem&    manipStatedSystem,
      EcU32                    manipIndex
      ) :
      m_GraspDescriptor   (graspDescriptor),
      m_ObjectStatedSystem(objectStatedSystem),
      m_ObjectIndex       (objectIndex),
      m_ManipStatedSystem (manipStatedSystem),
      m_ManipIndex        (manipIndex)
   {
   }

   /// accessor for the grasp descriptor
   const EcGraspDescriptor& graspDescriptor
      (
      ) const
   {
      return m_GraspDescriptor;
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

   /// accessor for the shape feature histogram
   EcShapeFeatureHistogram& shapeFeatureHistogram
      (
      ) const
   {
      return m_ShapeFeatureHistogram;
   }

private:
   const EcGraspDescriptor& m_GraspDescriptor;
   const EcStatedSystem&    m_ObjectStatedSystem;
   EcU32                    m_ObjectIndex;
   const EcStatedSystem&    m_ManipStatedSystem;
   EcU32                    m_ManipIndex;
   mutable EcShapeFeatureHistogram m_ShapeFeatureHistogram;
};

#endif // ecGraspInitParams_H_
