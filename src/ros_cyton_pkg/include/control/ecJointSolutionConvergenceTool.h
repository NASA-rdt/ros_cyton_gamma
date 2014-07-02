#ifndef ecJointSolutionConvergenceTool_H_
#define ecJointSolutionConvergenceTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointSolutionConvergenceTool.h
/// @class EcJointSolutionConvergenceTool
/// @brief A base class for a joint solution finder
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipEndEffectorPlace.h"
#include "ecManipEndEffectorVel.h"

#include <manipulator/ecPositionState.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcManipulatorActiveState;
class EcManipulatorEndEffectorPlacement;
class EcVelocityController;

/// Holds a base class for a joint solution finder.
class EC_ACTIN_CONTROL_DECL EcJointSolutionConvergenceTool : public EcXmlCompoundType
{
public:
   /// default constructor
   EcJointSolutionConvergenceTool
      (
      );

   /// destructor
   virtual ~EcJointSolutionConvergenceTool
      (
      );

   /// copy constructor
   EcJointSolutionConvergenceTool
      (
      const EcJointSolutionConvergenceTool& orig
      );

   /// assignment operator
   EcJointSolutionConvergenceTool& operator=
      (
      const EcJointSolutionConvergenceTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointSolutionConvergenceTool& orig
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the maximum iterations. This value is used to terminate the single convergence to the goal placement to be within the tolerance.
   virtual EcU32 maxIterations
      (
      ) const;

   /// sets the maximum iterations
   virtual void setMaxIterations
      (
      EcU32 value
      );

   /// gets the tolerance used on each EE to determine if each of them has reached the goal
   virtual EcReal tolerance
      (
      ) const;

   /// sets the tolerance used on each EE to determine if each of them has reached the goal
   virtual void setTolerance
      (
      EcReal value
      );

   /// gets the maximum threshold used to cap the joint differentials
   virtual EcReal maxThreshold
      (
      ) const;

   /// sets the maximum threshold used to cap the joint differentials
   virtual void setMaxThreshold
      (
      EcReal value
      );

   /// gets the minimum threshold used to cap the joint differentials
   virtual EcReal minThreshold
      (
      ) const;

   /// sets the minimum threshold used to cap the joint differentials
   virtual void setMinThreshold
      (
      EcReal value
      );

   /// sets the pointer to the velocity controller to be used in this convergence tool
   virtual void setVelocityController
      (
      const EcVelocityController* value
      );

   /// try to converge to the goal from a given starting configuration
   virtual EcBoolean convergeToGoal
      (
      const EcManipulatorEndEffectorPlacement& goal,
      const EcPositionState& start,
      EcXmlRealVector& solution
      ) const;

   /// sets the indices of joints contained in the joint EE
   virtual void setJointEndEffectorIndices
      (
      const EcU32Vector& value
      );

protected:
   /// calculate the joint differentials given the placement differentials
   virtual void calculateJointDifferentials
      (
      EcManipulatorEndEffectorVelocity& placementDifferentials,
      EcRealVector& jointDifferentials
      ) const=0;

   /// calculate the actual end-effector placement given the state
   virtual void calculateActualPlacement
      (
      EcManipulatorActiveState& activeState,
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector placement differentials (errors)
   virtual void calculatePlacementDifferentials
      (
      const EcManipulatorEndEffectorPlacement& goal,
      EcManipulatorActiveState& activeState,
      EcManipulatorEndEffectorVelocity& differentials
      ) const;

   /// determine against the tolerance whether the current EE placement has converged to the goal
   virtual EcBoolean converged
      (
      const EcManipulatorEndEffectorPlacement& goal,
      const EcManipulatorEndEffectorPlacement& current
      ) const;

   /// check the joint limits. Return true if the joint positions are within the limits. It also tries to convert joint angles
   /// for revolute joints (since 0 degree is the same angle as 360, etc).
   virtual EcBoolean checkJointLimits
      (
      EcXmlRealVector& jointPositions
      ) const;

   /// determine if we're converging to a solution. By default, it returns true. The derived class should override if desired.
   /// If this returns false, convergeToGoal will terminate and return false.
   virtual EcBoolean isConverging
      (
      ) const;
protected:
   /// the maximum iterations
   EcXmlU32                   m_MaxIterations;

   /// the tolerance used on each EE to determine if each of them has reached the goal
   EcXmlReal                  m_Tolerance;

   /// the maximum threshold used to cap the joint differentials
   EcXmlReal                  m_MaxThreshold;

   /// the minimum threshold used to cap the joint differentials
   EcXmlReal                  m_MinThreshold;

   // non-XML data below
   /// the pointer to the velocity controller
   const EcVelocityController*      m_pVelocityController;

   mutable EcRealVector       m_JointDifferentials;      ///< the joint differentials
   mutable EcManipulatorEndEffectorPlacement m_UtilityPlacement;        ///< the utility placement
   mutable EcManipulatorEndEffectorVelocity  m_PlacementDifferentials;  ///< the placement differentials
   mutable EcManipulatorEndEffectorVelocity  m_UtilityVelocity;         ///< the utility EE velocity
   mutable EcPositionState    m_UtilityState;            ///< the utility state
   mutable EcU32              m_Iterations;              ///< number of iterations

   EcU32Vector                m_JointEeIndices;          ///< Indices of joints contained in the joint EE used in coordinated control
};

#endif // ecJointSolutionConvergenceTool_H_
