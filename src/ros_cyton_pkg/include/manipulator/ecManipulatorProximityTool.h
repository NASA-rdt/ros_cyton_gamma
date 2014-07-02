#ifndef ecManipulatorProximityTool_H_
#define ecManipulatorProximityTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorProximityTool.h
/// @class EcManipulatorProximityTool
/// @brief Helper class to calculate distance between manipulators and/or links
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <shapeProximity/ecShapeProximityTool.h>

// forward declaration
class EcManipulatorActivePositionState;
class EcManipulatorLink;
class EcManipulatorSystem;
class EcStatedSystem;
class EcSystemActiveState;

/**
Helper class to calculate distance between manipulators and/or links
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorProximityTool
{
public:

   /// default constructor
   EcManipulatorProximityTool
      (
      );

   /// destructor
   virtual ~EcManipulatorProximityTool
      (
      );

   /// copy constructor
   EcManipulatorProximityTool
      (
      const EcManipulatorProximityTool& orig
      );

   /// assignment operator
   EcManipulatorProximityTool& operator=
      (
      const EcManipulatorProximityTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorProximityTool& orig
      ) const;

   /// the bounding volume level in the BV hierarchy used for collision calculations
   EcU32 boundingVolumeLevel
      (
      ) const;

   /// set the bounding volume level in the BV hierarchy used for collision calculations
   void setBoundingVolumeLevel
      (
      EcU32 value
      );

   /// compute distance between two links
   /**
    * @param manipID1 The index of the manipulator of link 1
    * @param linkID1 The link index of link 1
    * @param manipID2 The index of the manipulator of link 2
    * @param linkID2 The link index of link 2
    * @param system The manipulator system containing all manipulators
    * @param activeState1 The active state of manipulator of link 1
    * @param activeState2 The active state of manipulator of link 2
    * @param[out] computedDistance The (non-negative) distance between the two links
    * @return True if the success (all the manipulator and link indices are valid) or false otherwise.
    */
   EcBoolean linkToLinkDistance
      (
      EcU32 manipID1,
      EcU32 linkID1,
      EcU32 manipID2,
      EcU32 linkID2,
      const EcManipulatorSystem& system,
      EcManipulatorActivePositionState& activeState1,
      EcManipulatorActivePositionState& activeState2,
      EcReal& computedDistance
      ) const;

   /// check collision between two links
   /// return true if the two links are in collision or false otherwise
   /**
    * @param manipID1 The index of the manipulator of link 1
    * @param linkID1 The link index of link 1
    * @param manipID2 The index of the manipulator of link 2
    * @param linkID2 The link index of link 2
    * @param statedSystem The stated system containing all manipulators
    * @param activeState1 The active state of manipulator of link 1
    * @param activeState2 The active state of manipulator of link 2
    * @param tolerance If the distance between the two links is less than tolerance, they are considered
    *          to be in collision.
    * @return true if the two links are in collision or false otherwise
    */
   EcBoolean checkLinkCollision
      (
      EcU32 manipID1,
      EcU32 linkID1,
      EcU32 manipID2,
      EcU32 linkID2,
      const EcStatedSystem& statedSystem,
      EcManipulatorActivePositionState& activeState1,
      EcManipulatorActivePositionState& activeState2,
      EcReal tolerance = 0.0
      ) const;

   /// compute the distance between two manipulators
   /**
    * @param manipID1 The index of manipulator 1
    * @param manipID2 The index of manipulator 2
    * @param system The manipulator system containing all manipulators
    * @param activeState1 The active state of manipulator 1
    * @param activeState2 The active state of manipulator 2
    * @param[out] computedDistance The (non-negative) distance between the two manipulators
    * @return True if the success (all the manipulator indices are valid) or false otherwise.
    */
   EcBoolean manipulatorToManipulatorDistance
      (
      EcU32 manipID1,
      EcU32 manipID2,
      const EcManipulatorSystem& system,
      EcManipulatorActivePositionState& activeState1,
      EcManipulatorActivePositionState& activeState2,
      EcReal& computedDistance
      ) const;

   /// check collision on a manipulator
   /**
    * @param manipID The manipulator index
    * @param statedSystem The stated system containing all manipulators
    * @param systemActiveState The system active state. The method uses the position data stored in systemActiveState to
    *       compute collision and then store the collision data into other parts of systemActiveState.
    * @param tolerance If the distances between this manipulator and others are less than tolerance, the manipulator is
    *          considered to be in collision
    * @param otherManipID The index of the other manipulator that is in collision with this manipulator
    * @param thisLinkID The index of the link of this manipulator that is in collision
    * @param otherLinkID The index of the other link that is in collision
    * @param otherClosestManipID The index of the other manipulator that is closest to this manipulator
    * @param thisClosestLinkID The index of the link of this manipulator that is closest to another manipulator
    * @param otherClosestLinkID The index of the other link that is closest to this manipulator
    * @param closestDistance The closest distance between this manipulator and other manipulators
    * @return true if the manipulator is in collision or false otherwise
    */
   EcBoolean checkManipulatorCollision
      (
      EcU32 manipID,
      const EcStatedSystem& statedSystem,
      EcSystemActiveState& systemActiveState,
      EcReal tolerance,
      EcU32& otherManipID,
      EcU32& thisLinkID,
      EcU32& otherLinkID,
      EcU32& otherClosestManipID,
      EcU32& thisClosestLinkID,
      EcU32& otherClosestLinkID,
      EcReal& closestDistance
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

   /// the shape proximity tool
   EcShapeProximityTool m_ShapeProximityTool;

   /// the bounding volume level used when calculating distances and collisions
   EcU32 m_BoundingVolumeLevel;
};

#endif // ecManipulatorProximityTool_H_
