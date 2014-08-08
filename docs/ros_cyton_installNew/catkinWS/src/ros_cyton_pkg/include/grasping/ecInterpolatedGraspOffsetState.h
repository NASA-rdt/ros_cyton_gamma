#ifndef ecInterpolatedGraspOffsetState_H_
#define ecInterpolatedGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecInterpolatedGraspOffsetState.h
/// @class EcInterpolatedGraspOffsetState
/// @brief This class provides a grasp offset that is interpolated.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffsetState.h"
#include "ecGraspOffsetStateContainer.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a grasp offset that is interpolated.
class EC_ACTIN_GRASPING_DECL EcInterpolatedGraspOffsetState : public EcGraspOffsetState
{
public:
   /// default constructor
   EcInterpolatedGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcInterpolatedGraspOffsetState
      (
      );

   /// copy constructor
   EcInterpolatedGraspOffsetState
      (
      const EcInterpolatedGraspOffsetState& orig
      );

   /// assignment operator
   EcInterpolatedGraspOffsetState& operator=
      (
      const EcInterpolatedGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcInterpolatedGraspOffsetState& orig
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

   /// get the target offset
   virtual EcGraspOffsetState* targetOffsetState
      (
      );

   /// get the target offset
   virtual const EcGraspOffsetState* targetOffsetState
      (
      ) const;

   /// set the target offset
   virtual void setTargetOffsetState
      (
      const EcGraspOffsetStateContainer& targetOffsetState
      );

   /// get the initialization time
   virtual EcReal initializationTime
      (
      ) const;

   /// set the interpolation time
   virtual void setInitializationTime
      (
      EcReal time
      );

   /// get the initial offset
   virtual const EcEndEffectorPlacement& initialOffset
      (
      ) const;

   /// set the initial offset
   virtual void setInitialOffset
      (
      const EcEndEffectorPlacement& offset
      );

   /// get the current offset
   virtual const EcEndEffectorPlacement& currentOffset
      (
      ) const;

   /// set the current offset
   virtual void setCurrentOffset
      (
      const EcEndEffectorPlacement& offset
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
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
   /// target offset for the inerpolation
   EcGraspOffsetStateContainer      m_TargetOffsetState;

   /// time at initialization
   EcXmlReal                        m_InitializationTime;

   /// offset at the time of initialization
   EcEndEffectorPlacement m_InitialOffset;

   /// current offset
   EcEndEffectorPlacement m_CurrentOffset;
};

#endif // ecInterpolatedGraspOffsetState_H_
