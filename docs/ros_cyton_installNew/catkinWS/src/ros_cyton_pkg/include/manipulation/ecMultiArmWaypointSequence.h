#ifndef ecMultiArmWaypointSequence_H_
#define ecMultiArmWaypointSequence_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultiArmWaypointSequence.h
/// @class EcMultiArmWaypointSequence
/// @brief This represents a sequence of waypoints for used with
///        multi-arm robots
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecWaypointSequence.h"

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcMultiArmWaypointSequence : public EcManipulationAction
{
public:
   /// default constructor
   EcMultiArmWaypointSequence
      (
      );

   /// destructor
   virtual ~EcMultiArmWaypointSequence
      (
      );

   /// copy constructor
   EcMultiArmWaypointSequence
      (
      const EcMultiArmWaypointSequence& orig
      );

   /// assignment operator
   EcMultiArmWaypointSequence& operator=
      (
      const EcMultiArmWaypointSequence& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultiArmWaypointSequence& orig
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

   /// get the waypoint sequences
   virtual const EcWaypointSequenceVector& waypointSequences
      (
      ) const;

   /// get the waypointSequences -- nonconst
   virtual EcWaypointSequenceVector& waypointSequences
      (
      );

   /// set the waypoint sequences
   virtual void setWaypointSequences
      (
      const EcWaypointSequenceVector& value
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

   /// @copydoc EcManipulationAction::init()
   virtual EcBoolean init
      (
      EcManipulationActionStateContainer& astateContainer
      ) const;

   /// @copydoc EcManipulationAction::update()
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// @copydoc EcManipulationAction::activeControlDescription()
   virtual EcU32 activeControlDescription
      (
      const EcManipulationActionState& astate
      ) const;

   /// @copydoc EcManipulationAction::activeControlDescription()
   virtual EcU32 activeControlMethod
      (
      const EcManipulationActionState& astate
      ) const;

   /// @copydoc EcManipulationAction::activeEndEffectorSet()
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationActionState& astate
      ) const;

   /// @copydoc EcManipulationAction::dataMap()
   virtual const EcDataMap& dataMap
      (
      const EcManipulationActionState& astate
      ) const;

   /// @copydoc EcManipulationAction::findDataMapReferences()
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// @copydoc EcManipulationAction::endEffectorSet()
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationActionState&  astate
      ) const;

   /// @copydoc EcManipulationAction::endEffectorPlacement()
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationActionState& astate
      ) const;

   /// @copydoc EcManipulationAction::progress()
   virtual EcReal progress
      (
      const EcManipulationActionState& astate
      ) const;

   /// @copydoc EcManipulationAction::statusString()
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

protected:
   /// vector of waypoint sequences, one of each arm
   EcWaypointSequenceVector      m_vWaypointSequences;

   // non-XML
   mutable EcManipulatorEndEffectorPlacement   m_DesiredPlacement;   ///< desired placement
   mutable EcU32Vector    m_ProfiledPositionEndEffectorIndices;      ///< profiled position end effector indices

   static const EcDataMap                 m_theNullDataMap;          ///< the null data map
   static const EcEndEffectorSet          m_theNullEndEffectorSet;   ///< the null end effector set
};

#endif // ecMultiArmWaypointSequence_H_
