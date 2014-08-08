#ifndef ecCoordJointPositionControlMethod_H_
#define ecCoordJointPositionControlMethod_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCoordJointPositionControlMethod.h
/// @class EcCoordJointPositionControlMethod
/// @brief Holds a description of a position control method, which
///        uses coordinated joint control to move to desired placements
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPositionControlMethod.h"
#include "ecJointSolutionFinderContainer.h"

/// Holds a description of a position control method, which uses coordinated joint control to move to desired placements
class EC_ACTIN_CONTROL_DECL EcCoordJointPositionControlMethod : public EcPositionControlMethod
{
public:
   /// default constructor
   EcCoordJointPositionControlMethod
      (
      );

   /// destructor
   virtual ~EcCoordJointPositionControlMethod
      (
      );

   /// copy constructor
   EcCoordJointPositionControlMethod
      (
      const EcCoordJointPositionControlMethod& orig
      );

   /// assignment operator
   EcCoordJointPositionControlMethod& operator=
      (
      const EcCoordJointPositionControlMethod& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCoordJointPositionControlMethod& orig
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// get the joint solution finder container
   virtual const EcJointSolutionFinderContainer& jointSolutionFinderContainer
      (
      ) const;

   /// set the joint solution finder container
   virtual void setJointSolutionFinderContainer
      (
      const EcJointSolutionFinderContainer& value
      );

   /// set the joint solution finder
   virtual void setJointSolutionFinder
      (
      const EcJointSolutionFinder& value
      );

   /// get the tolerance used to determine whether all the joints have reached the joint solution
   virtual EcReal jointTolerance
      (
      ) const;

   /// set the tolerance used to determine whether all the joints have reached the joint solution
   virtual void setJointTolerance
      (
      EcReal value
      );

   /// get the tolerance used to determine whether to use normal control or this (coordinated joint) control
   virtual EcReal goalTolerance
      (
      ) const;

   /// set the tolerance used to determine whether to use normal control or this (coordinated joint) control
   virtual void setGoalTolerance
      (
      EcReal value
      );

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

   /// \copydoc EcPositionControlMethod::preCalculateStateCondition()
   virtual void preCalculateStateCondition
      (
      );

   /// \copydoc EcPositionControlMethod::postCalculateStateCondition()
   virtual void postCalculateStateCondition
      (
      );

   /// \copydoc EcPositionControlMethod::calculateVelocityState()
   virtual void calculateVelocityState
      (
      );

   /// \copydoc EcPositionControlMethod::connectComponents()
   virtual void connectComponents
      (
      );

   /// \copydoc EcPositionControlMethod::isConverging()
   virtual EcBoolean isConverging
      (
      ) const;

protected:

   /// check whether the joint solutions have been reached by the coordinated joint controllers or
   /// whether we're making progress towards the joint solutions. Returns true if the joint solutions
   /// have been reach or we're NOT making progress.
   virtual EcBoolean checkJointSolutions
      (
      );

   /// initialize
   virtual void initialize
      (
      );

protected:
   /// the joint solution finder container
   EcJointSolutionFinderContainer            m_JointSolutionFinderContainer;

   /// the tolerance used to determine whether all the joints have reached the joint solution
   EcXmlReal                                 m_JointTolerance;

   /// the tolerance used to determine whether to use normal control or this (coordinated joint) control
   EcXmlReal                                 m_GoalTolerance;

   // non-XML data
   /// the desired joint end-effector placement for the manipulator
   mutable EcManipulatorEndEffectorPlacement    m_DesiredJointPlacement;

   /// the input desired joint end-effector velocity for the manipulator
   mutable EcManipulatorEndEffectorVelocity     m_DesiredJointVelocity;

   /// the computed end-effector velocity used in velocity control
   mutable EcManipulatorEndEffectorVelocity     m_VelocityControlVelocity;

   // store the joint solutions
   mutable EcXmlRealVector             m_JointSolution;  ///< the joint solution from the joint solution finder
   /// the desired end-effector placement for joint control set from m_JointSolution
   mutable EcEndEffectorPlacement      m_JointSolutionPlacement;

   EcBoolean      m_IsCalculatingState;      ///< flag indicating whether the control is calculating the state
   EcBoolean      m_JointSolutionFound;      ///< flag indicating whether the joint solution is found
   EcBoolean      m_ReadyForNextPlacement;   ///< flag indicating whether the control is ready for the next placement
   /// the convergence value used to help determine whether the joint controller is converging to the found solution
   EcReal         m_ConvergenceValue;
   EcBoolean      m_IsConverging;            ///< flag indicating whether the joint controller is converging to the found solution

   EcBoolean      m_CoordControl;            ///< flag indicating whether to use normal or coordinated control
   EcReal         m_ConvergenceToolTolerance;///< the tolerance of the convergence tool

   EcU32Vector    m_JointEeIndices;          ///< Indices of joints contained in the joint EE used in coordinated control
};

#endif // ecCoordJointPositionControlMethod_H_
