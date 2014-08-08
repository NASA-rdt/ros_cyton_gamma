#ifndef ecStrOptFunction_H_
#define ecStrOptFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecStrOptFunction.h
/// @class EcStrengthOptimizationFunction
/// @brief Computes the sum of the normalized joint torques, to be
///        used for strength optimization.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <iostream>
#include <foundCore/ecConstants.h>
#include "ecScalarManipFunction.h"
#include <control/ecJacobianTool.h>
#include <control/ecManipEndEffectorForce.h>

// forward declarations
class EcIndividualManipulator;
class EcEndEffectorSet;

/** Provides a measure of proximity to a singularity.
*/
class EC_ACTIN_MEASURE_DECL EcStrengthOptimizationFunction : public EcScalarManipulatorFunction
{
public:
   /// default constructor
   EcStrengthOptimizationFunction
      (
      );

   /// destructor
   virtual ~EcStrengthOptimizationFunction
      (
      );

   /// copy constructor
   EcStrengthOptimizationFunction
      (
      const EcStrengthOptimizationFunction& orig
      );

   /// assignment operator
   EcStrengthOptimizationFunction& operator=
      (
      const EcStrengthOptimizationFunction& orig
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

   /// gets a pointer to the end-effector set
   virtual const EcEndEffectorSet* endEffectorSet
      (
      ) const;

   /// sets the pointer to the end-effector set
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet* pEndEffectorSet
      );

   /// gets a pointer to the end-effector forces
   virtual const EcManipulatorEndEffectorForce* endEffectorForces
      (
      ) const;

   /// sets the pointer to the end-effector forces
   virtual void setEndEffectorForces
      (
      const EcManipulatorEndEffectorForce* pEndEffectorForces
      );

   /// evaluate the function using an active state
   virtual EcReal evaluate
      (
      EcManipulatorActiveState& actState,
      EcBoolean nominal = EcTrue
      ) const;

   /// sets the degree to use for N-Norm optimization
   virtual void setNormDegree
      (
         EcReal value
      ) ;

   /// gets the degree to use for N-Norm optimization
   virtual EcReal getNormDegree
      (
      ) const ;

   /// get a null object
   static EcStrengthOptimizationFunction nullObject
      (
      );

protected:
   /// a pointer to the manipulator
   const EcIndividualManipulator* m_pManipulator;

   /// a pointer to an end-effector set
   const EcEndEffectorSet*         m_pEndEffectorSet;

   /// manipulator end effector forces
   const EcManipulatorEndEffectorForce* m_pManipEndEffectorForces;

   /// degree to use for N-Norm optimization
   EcReal m_Norm ;

   /// utility Jacobian tool
   mutable EcJacobianTool m_JacobianTool;

   /// utility Jacobian
   mutable EcManipulatorJacobian m_Jacobian;

   /// utility forces
   mutable EcRealVector m_UtilityForces;

   /// utility torque vector
   mutable EcRealVector m_UtilityTorqueVector;
};

#endif // ecStrOptFunction_H_
