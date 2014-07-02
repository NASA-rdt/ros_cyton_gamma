#ifndef ecMultiArmWaypointSequenceState_H_
#define ecMultiArmWaypointSequenceState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultiArmWaypointSequenceState.h
/// @class EcMultiArmWaypointSequenceState
/// @brief A state for EcMultiArmWaypointSequence
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecWaypointSequenceState.h"

// Forward declarations

/// A manipulation sequence.
class EC_ACTIN_MANIPULATION_DECL EcMultiArmWaypointSequenceState : public EcManipulationActionState
{
public:
   /// default constructor
   EcMultiArmWaypointSequenceState
      (
      );

   /// destructor
   virtual ~EcMultiArmWaypointSequenceState
      (
      );

   /// copy constructor
   EcMultiArmWaypointSequenceState
      (
      const EcMultiArmWaypointSequenceState& orig
      );

   /// assignment operator
   EcMultiArmWaypointSequenceState& operator=
      (
      const EcMultiArmWaypointSequenceState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultiArmWaypointSequenceState& orig
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

   /// get the progress
   virtual EcReal progress
      (
      ) const;

   /// set the progress
   virtual void setProgress
      (
      EcReal value
      );

   /// get the sequence states
   virtual const EcWaypointSequenceStateVector& sequenceStates
      (
      ) const;

   /// get the sequence states
   virtual EcWaypointSequenceStateVector& sequenceStates
      (
      );

   /// set the sequence states
   virtual void setSequenceStates
      (
      const EcWaypointSequenceStateVector& value
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
   EcWaypointSequenceStateVector    m_vSequenceStates;   ///< a vector of waypoint sequence states
   EcXmlReal                        m_Progress;          ///< progress
};

#endif // ecMultiArmWaypointSequenceState_H_
