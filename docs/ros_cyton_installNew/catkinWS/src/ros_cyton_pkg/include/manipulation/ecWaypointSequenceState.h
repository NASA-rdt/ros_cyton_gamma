#ifndef ecWaypointSequenceState_H_
#define ecWaypointSequenceState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecWaypointSequenceState.h
/// @class EcWaypointSequenceState
/// @brief A state for a waypoint sequence
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include "ecManipulationActionState.h"

// Forward declarations
class EcManipulatorEndEffectorPlacement;

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcWaypointSequenceState : public EcManipulationActionState
{
public:
   /// default constructor
   EcWaypointSequenceState
      (
      );

   /// destructor
   virtual ~EcWaypointSequenceState
      (
      );

   /// copy constructor
   EcWaypointSequenceState
      (
      const EcWaypointSequenceState& orig
      );

   /// assignment operator
   EcWaypointSequenceState& operator=
      (
      const EcWaypointSequenceState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcWaypointSequenceState& orig
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

   /// get the current waypoint index
   virtual EcU32 currentWaypointIndex
      (
      ) const;

   /// set the current waypoint index
   virtual void setCurrentWaypointIndex
      (
      EcU32 index
      );

   /// get the flag indicating if the current waypoint needs initialization
   virtual EcBoolean currentWaypointNeedsInit
      (
      ) const;

   /// set the flag indicating if the current waypoint needs initialization
   virtual void setCurrentWaypointNeedsInit
      (
      EcBoolean flag
      );

   /// get the flag indicating if the current waypoint has completed
   virtual EcBoolean currentWaypointIsComplete
      (
      ) const;

   /// set the flag indicating if the current waypoint has completed
   virtual void setCurrentWaypointIsComplete
      (
      EcBoolean flag
      );

   /// get the progress of the sequence
   virtual EcReal progress
      (
      ) const;

   /// set the progress of the sequence
   virtual void setProgress
      (
      EcReal value
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

protected:
   /// the current active waypoint
   EcXmlU32       m_CurrentWaypointIndex;

   /// the flag indicating if the current waypoint needs initialization
   EcXmlBoolean   m_CurrentWaypointNeedsInit;

   /// the flag indicating if the current waypoint has completed
   EcXmlBoolean   m_CurrentWaypointIsComplete;

   /// the progress of the sequence (0.0 = not started, 1.0 = completed)
   EcXmlReal      m_Progress;
};

#include <xml/ecXmlVectorType.h>
/// type definition of EcWaypointSequenceStateVector
typedef EcXmlVectorType<EcWaypointSequenceState> EcWaypointSequenceStateVector;

#endif // ecWaypointSequenceState_H_
