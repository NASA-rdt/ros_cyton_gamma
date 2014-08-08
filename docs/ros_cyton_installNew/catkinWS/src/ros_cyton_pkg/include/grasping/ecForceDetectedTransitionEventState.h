#ifndef ecForceDetectedTransitionEventState_H_
#define ecForceDetectedTransitionEventState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceDetectedTransitionEventState.h
/// @class EcForceDetectedTransitionEventState
/// @brief This class provides a grasp frame transition event based
///        on force.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspFrameTransitionEventState.h"

#include <xml/ecXmlBasicType.h>

class EC_ACTIN_GRASPING_DECL EcForceDetectedTransitionEventState : public EcGraspFrameTransitionEventState
{
public:
   /// default constructor
   EcForceDetectedTransitionEventState
      (
      );

   /// destructor
   virtual ~EcForceDetectedTransitionEventState
      (
      );

   /// copy constructor
   EcForceDetectedTransitionEventState
      (
      const EcForceDetectedTransitionEventState& orig
      );

   /// assignment operator
   EcForceDetectedTransitionEventState& operator=
      (
      const EcForceDetectedTransitionEventState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceDetectedTransitionEventState& orig
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

   /// get the timeout start time for force detection test
   virtual EcReal timeoutStartTime
      (
      ) const;

   /// set the timeout start time for force detection test
   virtual void setTimeoutStartTime
      (
      EcReal time
      );

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
   /// the timeout start time for force detection test
   EcXmlReal m_TimeoutStartTime;
};

#endif // ecForceDetectedTransitionEventState_H_
