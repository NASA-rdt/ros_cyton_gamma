#ifndef ecManipulationPlacementAchievedTransitionEventState_H_
#define ecManipulationPlacementAchievedTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationPlacementAchievedTransitionEventState.h
/// @class EcManipulationPlacementAchievedTransitionEventState
/// @brief This class provides a manipulation frame transition event  state.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationFrameTransitionEventState.h"

#include <xml/ecXmlBasicType.h>

/// This class provides a manipulation frame transition event  state.
class EC_ACTIN_MANIPULATION_DECL EcManipulationPlacementAchievedTransitionEventState : public EcManipulationFrameTransitionEventState
{
public:
   /// default constructor
   EcManipulationPlacementAchievedTransitionEventState
      (
      );

   /// destructor
   virtual ~EcManipulationPlacementAchievedTransitionEventState
      (
      );

   /// copy constructor
   EcManipulationPlacementAchievedTransitionEventState
      (
      const EcManipulationPlacementAchievedTransitionEventState& orig
      );

   /// assignment operator
   EcManipulationPlacementAchievedTransitionEventState& operator=
      (
      const EcManipulationPlacementAchievedTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationPlacementAchievedTransitionEventState& orig
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

   /// get the convergence value used for testing convergence
   virtual EcReal convergenceValue
      (
      ) const;

   /// set the convergence value used for testing convergence
   virtual void setConvergenceValue
      (
      EcReal value
      );

   /// get the start time of the convergence window for testing convergence
   virtual EcReal convergenceWindowStartTime
      (
      ) const;

   /// set the start time of the convergence window for testing convergence
   virtual void setConvergenceWindowStartTime
      (
      EcReal time
      );

   /// get the progress of this event
   virtual EcReal progress
      (
      ) const;

   /// register XML member variables
   virtual void registerComponents
      (
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
   /// the convergence value used for testing convergence
   EcXmlReal    m_ConvergenceValue;

   /// the start time of the convergence window for testing convergence
   EcXmlReal    m_ConvergenceWindowStartTime;

   /// the initial convergence value
   EcXmlReal    m_InitialConvergenceValue;

   /// flag indicating if the initial convergence value has been set
   EcXmlBoolean m_InitialConvergenceValueIsSet;

   /// the progress of this event (0.0 = not started, 1.0 = completed)
   EcXmlReal    m_Progress;
};

#endif // ecManipulationPlacementAchievedTransitionEventState_H_
