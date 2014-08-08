#ifndef ecWaypointSequence_H_
#define ecWaypointSequence_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecWaypointSequence.h
/// @class EcWaypointSequence
/// @brief This represents a sequence of waypoints.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <control/ecEndEffectorSet.h>
#include <foundCommon/ecDataMap.h>
#include "ecManipulationAction.h"
#include "ecManipulationWaypointVector.h"

// Forward declarations

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcWaypointSequence : public EcManipulationAction
{
public:
   /// default constructor
   EcWaypointSequence
      (
      );

   /// destructor
   virtual ~EcWaypointSequence
      (
      );

   /// copy constructor
   EcWaypointSequence
      (
      const EcWaypointSequence& orig
      );

   /// assignment operator
   EcWaypointSequence& operator=
      (
      const EcWaypointSequence& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcWaypointSequence& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// add a waypoint to the back of the vector
   virtual void add
      (
      const EcManipulationWaypoint& waypoint
      );

   /// insert a waypoint at the index. If index is greater than or equal to the vector size,
   /// then this is equivalent to add
   virtual void insert
      (
      EcU32 index,
      const EcManipulationWaypoint& waypoint
      );

   /// remove the specified waypoint
   virtual EcBoolean deleteWaypoint
      (
      EcU32 index
      );

   /// swap the two waypoints at index1 and index2
   virtual EcBoolean swap
      (
      EcU32 index1,
      EcU32 index2
      );

   /// get the waypoints
   virtual const EcManipulationWaypointVector& waypoints
      (
      ) const;

   /// get the waypoints -- nonconst
   virtual EcManipulationWaypointVector& waypoints
      (
      );

   /// set the waypoints
   virtual void setWaypoints
      (
      const EcManipulationWaypointVector& value
      );

   /// get the EE set index
   virtual EcU32 endEffectorSetIndex
      (
      ) const;

   /// set the EE set index
   virtual void setEndEffectorSetIndex
      (
      EcU32 value
      );

   /// get the control description index
   virtual EcU32 controlDescriptionIndex
      (
      ) const;

   /// set the control description index
   virtual void setControlDescriptionIndex
      (
      EcU32 value
      );

   /// get the EE index
   virtual EcU32 endEffectorIndex
      (
      ) const;

   /// set the EE index
   virtual void setEndEffectorIndex
      (
      EcU32 value
      );

   /// get the current waypoint
   virtual const EcManipulationWaypoint* currentWaypoint
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the current waypoint
   virtual EcManipulationWaypoint* currentWaypoint
      (
      const EcManipulationActionState& astate
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   //---
   // Implementation of EcManipulationAction interface
   //---

   /// initialize the manipulation sequence
   virtual EcBoolean init
      (
      EcManipulationActionStateContainer& astateContainer
      ) const;

   /// update the manipulation sequence
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationActionState& astate
      ) const;

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationActionState&  astate
      ) const;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the overall progress of this action
   virtual EcReal progress
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationActionState& astate,
      const EcString& separator
      ) const;

   /// @copydoc EcManipulationAction::profiledPositionEndEffectorIndices()
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationActionState& astate
      ) const;


   /// @copydoc
   virtual EcU32 currentItemAtPlay
      (
      const EcManipulationActionState& astate
      ) const;

protected:
   EcManipulationWaypointVector     m_vWaypoints;              ///< a vector of waypoints
   EcXmlU32                         m_EndEffectorSetIndex;     ///< end effector set index
   EcXmlU32                         m_ControlDescriptionIndex; ///< control description index
   EcXmlU32                         m_EndEffectorIndex;        ///< end effector index

   static const EcDataMap                 m_theNullDataMap;          ///< the null data map
   static const EcEndEffectorSet          m_theNullEndEffectorSet;   ///< the null end effector set
};

#include <xml/ecXmlVectorType.h>
/// type definition of EcWaypointSequenceVector
typedef EcXmlVectorType<EcWaypointSequence> EcWaypointSequenceVector;

#endif // ecWaypointSequence_H_
