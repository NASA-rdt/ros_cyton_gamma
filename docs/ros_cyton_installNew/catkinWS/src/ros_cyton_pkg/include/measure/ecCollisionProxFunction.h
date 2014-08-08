#ifndef ecCollisionProxFunction_H_
#define ecCollisionProxFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecCollisionProxFunction.h
/// @class EcCollisionProximityFunction
/// @brief Provides a measure of proximity to obstacles.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecScalarManipFunction.h"
#include <manipulator/ecManipulatorProximityTool.h>
#include <manipulator/ecManipSysState.h>

#undef  TIMING_ANALYSIS
#if defined(TIMING_ANALYSIS)
#include <foundCore/ecTimerUtil.h>
#endif

// forward declarations
class EcIndividualManipulator;
class EcManipulatorActiveState;
class EcManipulatorLinkProximityState;
/// type definition of EcManipulatorActiveStateVector
typedef EcXmlVectorType<EcManipulatorActiveState> EcManipulatorActiveStateVector;

/// Provides a measure of proximity to obstacles.
class EC_ACTIN_MEASURE_DECL EcCollisionProximityFunction : public EcScalarManipulatorFunction
{
public:
   /// default constructor
   EcCollisionProximityFunction
      (
      );

   /// destructor
   virtual ~EcCollisionProximityFunction
      (
      );

   /// copy constructor
   EcCollisionProximityFunction
      (
      const EcCollisionProximityFunction& orig
      );

   /// assignment operator
   EcCollisionProximityFunction& operator=
      (
      const EcCollisionProximityFunction& orig
      );

   /// gets a pointer to the manipulator
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// sets the manipulator pointer
   virtual void setManipulator
      (
      const EcIndividualManipulator* pManipulator
      );

   /// gets the exponent
   virtual EcReal exponent
      (
      ) const;
   /// sets the exponent
   virtual void setExponent
      (
      EcReal exponent
      );

   /// gets the boundary value
   virtual EcReal boundaryValue
      (
      ) const;

   /// sets the boundary value
   virtual void setBoundaryValue
      (
      EcReal boundaryValue
      );

   /// gets the precision level, this is the level in the BVH to
   /// anchor on
   virtual const EcU32& precisionLevel
      (
      );

   /// sets the precision level.  this is the level in the BVH to
   /// anchor on
   virtual void setPrecisionLevel
      (
      const EcU32 & precLeve
      );

   /// gets the cutoff distance
   virtual EcReal avoidanceDistance
      (
      ) const;

   /// sets the cutoff distance
   virtual void setAvoidanceDistance
      (
      EcReal avoidanceDistance
      );

   /// set flag indicating whether to check for manipulator self-collisions
   virtual void setCheckSelfCollision
      (
         EcBoolean val
      );

   /// get flag indicating whether to check for manipulator self-collisions
   virtual EcBoolean checkSelfCollision
      (
      )const;

   /// set flag indicating whether to check for environmental collisions
   virtual void setCheckEnvironmentCollisions
      (
         EcBoolean val
      );

   /// get flag indicating whether to check for environmental collisions
   virtual EcBoolean checkEnvironmentCollisions
      (
      )const;

   /// set the stated system pointer
   virtual void setStatedSystem
      (
      const EcStatedSystem* pSystem
      );

   /// get the stated system pointer
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// set the system active state
   virtual void setSystemActiveState
      (
      EcSystemActiveState& sysActiveState
      );

    /// set the interval processing
   virtual void setUseIntervalProcessing
      (
      EcBoolean flag
      );

   /// get the interval processing
   virtual EcBoolean useIntervalProcessing
      (
      )const;

   /// evaluate the function using an active state
   virtual EcReal evaluate
      (
      EcManipulatorActiveState& activeState,
      EcBoolean nominal = EcTrue
      ) const;

   /// get a null object
   static EcCollisionProximityFunction nullObject
      (
      );

protected:
   /// a pointer to the manipulator
   const EcIndividualManipulator* m_pManipulator;

   /// the exponent of a polynomial function
   EcXmlReal                       m_Exponent;

   /// the value at a bounding volume boundary
   EcReal m_BoundaryValue;

   /// the cutoff distance
   EcReal m_AvoidanceDistance;

   /// specifies the level in the BVH to use for distance
   /// queries
   EcU32 m_PrecisionLevel;

   /// the collision avoidance method
   EcBoolean m_UseIntervalProcessing;

   /// check for manipulator self-collisions
   EcXmlBoolean                     m_CheckSelfCollisions;

   /// check for collisions with the environment (this includes other
   /// manipulators)
   EcXmlBoolean                     m_CheckEnvironmentCollisions;

   /// pointer to collection of manipulators in the system.
   /// NOTE: all obstacles are considered manipulators
   const EcStatedSystem*            m_pStatedSystem;

   /// a pointer to the system active state
   EcSystemActiveState*             m_pSystemActiveState;

   /// manipulator proximity tool.  Used for computing distances
   EcManipulatorProximityTool       m_ManipulatorProximityTool;

   /// position states. Used for attachments
   mutable EcPositionStateVector            m_PositionStates;

#if defined(TIMING_ANALYSIS)
   static EcTimerUtil m_Timer;
   static EcU32 m_LoopCounter;
#endif
};

#endif // ecCollisionProxFunction_H_
