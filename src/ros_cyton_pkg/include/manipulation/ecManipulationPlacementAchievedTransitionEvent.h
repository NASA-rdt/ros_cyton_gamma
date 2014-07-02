#ifndef ecManipulationPlacementAchievedTransitionEvent_H_
#define ecManipulationPlacementAchievedTransitionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationPlacementAchievedTransitionEvent.h
/// @class EcManipulationPlacementAchievedTransitionEvent
/// @brief This class provides a manipulation frame transition event based
///        on placement.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationFrameTransitionEvent.h"

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlVectorType.h>

/// This class provides a manipulation frame transition event based on placement.
class EC_ACTIN_MANIPULATION_DECL EcManipulationPlacementAchievedTransitionEvent : public EcManipulationFrameTransitionEvent
{
public:
   /// default constructor
   EcManipulationPlacementAchievedTransitionEvent
      (
      );

   /// destructor
   virtual ~EcManipulationPlacementAchievedTransitionEvent
      (
      );

   /// copy constructor
   EcManipulationPlacementAchievedTransitionEvent
      (
      const EcManipulationPlacementAchievedTransitionEvent& orig
      );

   /// assignment operator
   EcManipulationPlacementAchievedTransitionEvent& operator=
      (
      const EcManipulationPlacementAchievedTransitionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationPlacementAchievedTransitionEvent& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get the window of time for testing convergence
   virtual EcReal convergenceWindow
      (
      ) const;

   /// set the window of time for testing convergence
   virtual void setConvergenceWindow
      (
      EcReal convergenceWindow
      );

   /// get the vector of placement indices to test
   virtual const EcXmlU32Vector& testIndices
      (
      ) const;

   /// set the vector of placement indices to test
   virtual void setTestIndices
      (
      const EcXmlU32Vector& testIndices
      );

   /// get the placement tolerance
   virtual EcReal tolerance
      (
      ) const;

   /// set the placement tolerance
   virtual void setTolerance
      (
      EcReal tolerance
      );

   /// get the soft failure flag
   virtual EcBoolean softFailure
      (
      ) const;

   /// set the soft failure flag
   virtual void setSoftFailure
      (
      EcBoolean flag
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// calculate the end state
   virtual EcManipulationFrameTransitionEventStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame
      ) const;

   /// initialize the transition event
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame,
      EcManipulationFrameTransitionEventStateContainer& estateContainer
      ) const;

   /// update the trasition event
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationFrame& frame,
      const EcManipulationFrameState& fstate,
      EcManipulationFrameTransitionEventState& estate
      ) const;

   /// get the overall progress of this transition event
   virtual EcReal progress
      (
      const EcManipulationFrameTransitionEventState& estate
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
   /// window of time for testing convergence
   EcXmlReal m_ConvergenceWindow;

   /// vector of placement indices to test
   EcXmlU32Vector m_TestIndices;

   /// the tolerance for the placement
   EcXmlReal m_Tolerance;

   /// flag indicating if the failure should be soft (treat EcManipulationStatus::FAILED as EcManipulationStatus::SUCCESS and continue)
   EcXmlBoolean m_SoftFailure;
};

#endif // ecManipulationPlacementAchievedTransitionEvent_H_
