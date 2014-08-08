#ifndef ecManipulatorCollisionTool_H_
#define ecManipulatorCollisionTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorCollisionTool.h
/// @class ecManipulatorCollisionTool
/// @brief Helper class for computing collision data between manipulators
///        and/or links
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <shapeProximity/ecShapeCollisionTool.h>
#include <shapeProximity/ecShapeProximityTool.h>

// forward declaration
class EcManipulatorActivePositionState;
class EcManipulatorActiveState;
class EcManipulatorLink;
class EcManipulatorSystem;
class EcShapeCollisionData;
class EcSystemActiveState;

/**
Helper class for computing collision data between manipulators and/or links
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorCollisionTool
{
public:

   /// default constructor
   EcManipulatorCollisionTool
      (
      );

   /// destructor
   ~EcManipulatorCollisionTool
      (
      );

   /// get the bounding volume level used in collision calculations
   EcU32 boundingVolumeLevel
      (
      ) const;

   /// set the bounding volume level used in collision calculations
   void setBoundingVolumeLevel
      (
      EcU32 level
      );

   /// compute collision data between two links
   /**
    * @param manipID1 The index of the manipulator of link 1
    * @param linkID1 The link index of link 1
    * @param manipID2 The index of the manipulator of link 2
    * @param linkID2 The link index of link 2
    * @param system The manipulator system containing all manipulators
    * @param[in,out] activeState The system active state. The method uses the position data stored in activeState to
    *       compute link collision and then store the collision data into other parts of activeState.
    * @return true if the two links are in collision or false otherwise
    */
   EcBoolean computeLinkCollisionData
      (
      EcU32 manipID1,
      EcU32 linkID1,
      EcU32 manipID2,
      EcU32 linkID2,
      const EcManipulatorSystem& system,
      EcSystemActiveState& activeState
      ) const;

protected:
   /// computes xform for shape2 in shape1 coordinate frame
   EcBoolean computeShape2In1Transform
      (
      const EcManipulatorLink& link1,
      const EcManipulatorLink& link2,
      EcManipulatorActivePositionState& activeState1,
      EcManipulatorActivePositionState& activeState2,
      EcCoordinateSystemTransformation &xform
      ) const;

   /// compute collision related information for each shape intersection
   /// and store the result in the shape collision data
   void computeAndStoreCollisionInformation
      (
      const EcShapeKey& key1,
      const EcShapeKey& key2,
      const EcManipulatorLink& link1,
      const EcManipulatorLink& link2,
      EcManipulatorActiveState& manipState1,
      EcManipulatorActiveState& manipState2,
      EcShapeCollisionData* colData
      ) const;


   /// the shape collision tool
   EcShapeCollisionTool    m_ShapeCollisionTool;
   
   /// the shape proximity tool
   EcShapeProximityTool    m_ShapeProximityTool;

   /// the bounding volume level used when calculating distances and collisions
   EcU32    m_BoundingVolumeLevel;

   /// an array of intersection pairs for caching
   mutable EcShapeProximityKeyVector  m_IntersectingShapes;
};

#endif // ecManipulatorCollisionTool_H_
