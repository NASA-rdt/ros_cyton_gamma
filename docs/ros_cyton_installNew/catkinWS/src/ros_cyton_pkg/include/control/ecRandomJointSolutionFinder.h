#ifndef ecRandomJointSolutionFinder_H_
#define ecRandomJointSolutionFinder_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecRandomJointSolutionFinder.h
/// @class EcRandomJointSolutionFinder
/// @brief A joint solution finder using random approach
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecJointSolutionFinder.h"

// forward declarations
class EcManipulatorLink;

/// This class finds a joint solution for a given goal EE placement. It uses the Jacobian-transpose approach
/// to drive the EEs to the goal. It starts from the current joint configuration. If it fails, it then
/// randomizes the starting joint configuration until it finds the solution or the maximum iterations have been reached.
class EC_ACTIN_CONTROL_DECL EcRandomJointSolutionFinder : public EcJointSolutionFinder
{
public:
   /// default constructor
   EcRandomJointSolutionFinder
      (
      );

   /// destructor
   virtual ~EcRandomJointSolutionFinder
      (
      );

   /// copy constructor
   EcRandomJointSolutionFinder
      (
      const EcRandomJointSolutionFinder& orig
      );

   /// assignment operator
   EcRandomJointSolutionFinder& operator=
      (
      const EcRandomJointSolutionFinder& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRandomJointSolutionFinder& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the max number of iterations of randomly selecting the new starting configuration
   virtual EcU32 maxIterations
      (
      ) const;

   /// sets the max number of iterations of randomly selecting the new starting configuration
   virtual void setMaxIterations
      (
      EcU32 value
      );

   /// gets the probability threshold (between 0 and 1 inclusive). For each iteration, we draw a random number between 0 and 1.
   /// If it's less than this number, then we perform guided randamization of the statring configuration. Otherwise,
   /// we conduct pure randomization.
   virtual EcReal probabilityThreshold
      (
      ) const;

   /// sets the probability threshold.
   virtual void setProbabilityThreshold
      (
      EcReal value
      );

   /// gets the tolerance for checking the goal and the previous goal
   virtual EcReal goalTolerance
      (
      ) const;

   /// sets the tolerance for checking the goal and the previous goal
   virtual void setGoalTolerance
      (
      EcReal value
      );

   /// gets the flag indicating whether we should repeat the calculations (findSolution) if the new goal
   /// is approximately equal to the previous goal but we failed to find the solution for the
   /// previous goal
   virtual EcBoolean repeatIfFailed
      (
      ) const;

   /// sets the repeatIfFailed flag
   virtual void setRepeatIfFailed
      (
      EcBoolean value
      );

   /// \copydoc EcJointSolutionFinder::setVelocityController()
   virtual void setVelocityController
      (
      const EcVelocityController* value
      );

   /// \copydoc EcJointSolutionFinder::findSolution()
   virtual EcBoolean findSolution
      (
      const EcPositionState& currentState,
      const EcManipulatorEndEffectorPlacement& goal,
      EcXmlRealVector& solution
      ) const;

   /// return a token
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
   /// checks whether the goal is approximately equal to the previous goal
   virtual EcBoolean checkGoal
      (
      const EcManipulatorEndEffectorPlacement& goal,
      const EcManipulatorEndEffectorPlacement& prevGoal
      ) const;

   /// calculate the difference between the current manipulator end-effector placement
   /// and the goal placement
   virtual EcReal difference
      (
      const EcManipulatorEndEffectorPlacement& goal,
      EcManipulatorActiveState& activeState
      ) const;

   /// if the joint has a range greater than 1 revolution, it can have multiple solutions
   /// then we want to choose the joint value that is closest to the starting joint angle
   /**
    * @param[in] link Pointer to the link (joint)
    * @param[in] startJointPosition The starting joint position
    * @param[out] jointPosition The joint position after conditioning
    */
   virtual void conditionJointAngle
      (
      const EcManipulatorLink* link,
      const EcXmlReal& startJointPosition,
      EcXmlReal& jointPosition
      ) const;

   /// the max number of iterations of randomly selecting the new starting configuration
   EcXmlU32          m_MaxIterations;

   /// the probability threshold
   EcXmlReal         m_ProbabiltyThreshold;

   /// the tolerance for checking the goal and the previous goal
   EcXmlReal         m_GoalTolerance;

   /// flag indicating whether we should repeat the calculations (findSolution) if the new goal
   /// is approximately equal to the previous goal but we failed to find the solution for the
   /// previous goal
   EcXmlBoolean      m_RepeatIfFailed;

   // non-XML data below
   EcRealVector      m_LowerLimits;          ///< the lower joint limits
   EcRealVector      m_UpperLimits;          ///< the upper joint limits
   mutable EcPositionState    m_UtilityState;///< the utility state
   mutable EcManipulatorEndEffectorPlacement   m_PrevGoal;  ///< previous goal
   mutable EcXmlRealVector      m_PrevSolution; ///< previous joint solution
   mutable EcBoolean m_PrevSolutionFound;    ///< flag indicating whether the previous joint solultion was found
   mutable EcReal    m_InitialDiff;          ///< the initial difference between goal and actual EE placements
};

#endif // ecRandomJointSolutionFinder_H_
