#ifndef ecManipulationWaypoint_H_
#define ecManipulationWaypoint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationWaypoint.h
/// @class EcManipulationWaypoint
/// @brief A single waypoint of a waypoint sequence.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <control/ecManipEndEffectorPlace.h>
#include "ecManipulationStatus.h"
#include "ecManipulationUpdateParams.h"
#include "ecWaypointInterpolatorContainer.h"

// Forward declarations
class EcManipulationWaypointState;
class EcWaypointSequence;
class EcWaypointSequenceState;

/// A single waypoint of a waypoint sequence.
class EC_ACTIN_MANIPULATION_DECL EcManipulationWaypoint : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationWaypoint
      (
      );

   /// destructor
   virtual ~EcManipulationWaypoint
      (
      );

   /// copy constructor
   EcManipulationWaypoint
      (
      const EcManipulationWaypoint& orig
      );

   /// assignment operator
   EcManipulationWaypoint& operator=
      (
      const EcManipulationWaypoint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationWaypoint& orig
      ) const;

   /// Clone -- virtual constructor of EcBezierInterpolator
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// creates new object - a virtual new to an EcXmlObject pointer
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the xml token used for writing out.
   virtual const EcToken& token
      (
      ) const;

   /// returns whether this waypoint is a stop point
   virtual EcBoolean stopPoint
      (
      ) const;

   /// sets whether this waypoint is a stop point
   virtual void setStopPoint
      (
      EcBoolean value
      );

   /// gets the goal of this waypoint
   virtual const EcManipulatorEndEffectorPlacement& goal
      (
      ) const;

   /// sets the goal of this waypoint
   virtual void setGoal
      (
      const EcManipulatorEndEffectorPlacement& value
      );

   /// Get label used for referencing this waypoint. When a pose is used as a waypoint, this should be the same as
   /// the pose name.
   virtual const EcString& label
      (
      ) const;

   /// Set label used for referencing this waypoint
   virtual void setLabel
      (
      const EcString& value
      );

   /// gets the zone radius
   virtual EcReal zoneRadius
      (
      ) const;

   /// sets the zone radius
   virtual void setZoneRadius
      (
      EcReal value
      );

   /// gets the extended zone radius (not used for now)
   virtual EcReal extendedZoneRadius
      (
      ) const;

   /// sets the extended zone radius (not used for now)
   virtual void setExtendedZoneRadius
      (
      EcReal value
      );

   /// gets the end-effector index
   virtual EcU32 endEffectorIndex
      (
      ) const;

   /// sets the end-effector index
   virtual void setEndEffectorIndex
      (
      EcU32 value
      );

   /// gets the interpolator container
   virtual const EcWaypointInterpolatorContainer& interpolatorContainer
      (
      ) const;

   /// sets the interpolator container
   virtual void setInterpolatorContainer
      (
      const EcWaypointInterpolatorContainer& value
      );

   /// sets the interpolator
   virtual void setInterpolator
      (
      const EcWaypointInterpolator& value
      );

   /// gets the end-effector speed
   virtual EcReal endEffectorSpeed
      (
      ) const;

   /// sets the end-effector speed
   virtual void setEndEffectorSpeed
      (
      EcReal value
      );

   /// gets the end-effector acceleration
   virtual EcReal endEffectorAcceleration
      (
      ) const;

   /// sets the end-effector acceleration
   virtual void setEndEffectorAcceleration
      (
      EcReal value
      );

   /// gets the end-effector deceleration
   virtual EcReal endEffectorDeceleration
      (
      ) const;

   /// sets the end-effector deceleration
   virtual void setEndEffectorDeceleration
      (
      EcReal value
      );

   /// get the control method index
   virtual EcU32 controlMethodIndex
      (
      ) const;

   /// set the control method index
   virtual void setControlMethodIndex
      (
      EcU32 value
      );

   /// get the flag indicating whether to interpolate within the zone
   virtual EcBoolean interpolate
      (
      ) const;

   /// set the flag indicating whether to interpolate within the zone
   virtual void setInterpolate
      (
      EcBoolean value
      );

   /// get the angular zone. This is used to determine when the orientation of EE is within the zone.
   virtual EcReal angularZone
      (
      ) const;

   /// set the angular zone
   virtual void setAngularZone
      (
      EcReal value
      );

   /// get the tolerance. This is used to determine whether the goal is reached when it's a stop point.
   virtual EcReal tolerance
      (
      ) const;

   /// set the tolerance
   virtual void setTolerance
      (
      EcReal value
      );

   /// get the role name to be used to set the manipulator when using relative pose
   virtual const EcString& roleName
      (
      ) const;

   /// set the role name
   virtual void setRoleName
      (
      const EcString& value
      );

   /// initialize the manipulation waypoint
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcWaypointSequence& sequence,
      const EcWaypointSequenceState& sstate,
      EcU32 waypointIndex
      ) const;

   /// update the manipulation waypoint
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcWaypointSequence& sequence,
      const EcWaypointSequenceState& sstate,
      EcU32 waypointIndex
      ) const;

   /// get the desired end effector placement
   virtual const EcManipulatorEndEffectorPlacement& desiredEndEffectorPlacement
      (
      ) const;

   /// get the indices of end-effectors that should use profiled position control.
   /// Can be empty to indicate that no end-effector needs to use profiled position control.
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      ) const;

   /// get the progress of this waypoint
   virtual EcReal progress
      (
      ) const;

   /// read object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// Determine which goal to use. If the label is not empty, we are using a pose as the goal.
   /// The pose doesn't exist in the pose set, this will return false.
   /// If the label is not empty, it will use the specified goal.
   virtual EcBoolean findGoalToUse
      (
      const EcManipulationUpdateParams& params
      ) const;

   /// update with interpolation
   virtual EcManipulationStatus::Enum updateInterpolate
      (
      EcReal time,
      const EcManipulationUpdateParams& params
      ) const;

   /// update without interpolation
   virtual EcManipulationStatus::Enum updateNoInterpolate
      (
      const EcManipulationUpdateParams& params
      ) const;

   /// returns the current difference to the goal
   virtual EcReal calculateGoalDifference
      (
      const EcManipulationUpdateParams& params
      ) const;

   /// restore the end-effector speed and acceleration
   virtual void restoreEndEffector
      (
      const EcManipulationUpdateParams& params
      ) const;

   // XML data
   EcXmlBoolean   m_StopPoint;         ///< Flag indicating whether this is a stop point
   EcManipulatorEndEffectorPlacement   m_Goal;     ///< The goal (center of the zone)
   EcXmlString    m_Label;             ///< Identifier - also used to find a pose in a given pose set
   EcXmlReal      m_ZoneRadius;        ///< The zone radius
   EcXmlReal      m_ExtendedZoneRadius;///< The extended zone radius
   mutable EcWaypointInterpolatorContainer  m_InterpolatorContainer; ///< Container of the interpolator
   EcXmlReal      m_EndEffectorSpeed;  ///< The speed of the EE used to move to this point
   EcXmlReal      m_EndEffectorAcceleration;  ///< The acceleration of the EE used to move to this point
   EcXmlReal      m_EndEffectorDeceleration;  ///< The deceleration of the EE used to move to this point
   EcXmlU32       m_ControlMethodIndex;///< The index of control method to use
   EcXmlBoolean   m_Interpolate;       ///< Flag indicating whether to interpolate within the zone
   EcXmlReal      m_AngularZone;       ///< The angular zone
   EcXmlReal      m_Tolerance;         ///< The tolerance
   EcXmlString    m_RoleName;          ///< The role name used with relative pose

   // non-XML data
   mutable EcU32     m_EndEffectorIndex;     ///< end effector index
   mutable const EcManipulationWaypoint*    m_pPrevWaypoint;   ///< pointer to the previous waypoint
   mutable const EcManipulationWaypoint*    m_pNextWaypoint;   ///< pointer to the next waypoint
   mutable EcManipulatorEndEffectorPlacement    m_DesiredPlacement;  ///< desired placement
   mutable EcReal    m_InterpolationStartTime;                 ///< interpolation star time
   mutable EcManipulatorEndEffectorPlacement    m_GoalToUse;   ///< the goal. Could be the same as m_Goal or different depending
                                                               ///< on whether the pose identified by m_Label exists
   mutable EcU32Vector  m_ProfiledEndEffectorIndices;    ///< profiled end effector indices
   mutable EcBoolean    m_GoalMoved;                     ///< if goal is moved
   mutable EcBoolean    m_SupportedControlMethod;        ///< is the control method is supported
   mutable EcBoolean    m_CheckRotation;                 ///< if rotated

   mutable EcReal       m_EndSpeedCache;                 ///< end spped cache
   mutable EcReal       m_EndAccelerationCache;          ///< end acceleration cache
   mutable EcReal       m_EndDecelerationCache;          ///< end deceleration cache

   mutable EcReal       m_Progress;                      ///< progress
   mutable EcReal       m_InitialGoalDifference;         ///< initial goal difference
   mutable EcBoolean    m_InitialGoalDifferenceIsSet;    ///< if the initial goal difference is set
};

#endif // ecManipulationWaypoint_H_
