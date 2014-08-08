#ifndef ecSingProxFunction_H_
#define ecSingProxFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSingProxFunction.h
/// @class EcSingularityProximityFunction
/// @brief Provides a measure of proximity to a singularity.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <iostream>
#include <foundCore/ecConstants.h>
#include "ecScalarManipFunction.h"
#include <control/ecJacobianTool.h>

// forward declarations
class EcIndividualManipulator;
class EcEndEffectorSet;

/** Provides a measure of proximity to a singularity.
*/
class EC_ACTIN_MEASURE_DECL EcSingularityProximityFunction : public EcScalarManipulatorFunction
{
public:
   /// default constructor
   EcSingularityProximityFunction
      (
      );

   /// destructor
   virtual ~EcSingularityProximityFunction
      (
      );

   /// copy constructor
   EcSingularityProximityFunction
      (
      const EcSingularityProximityFunction& orig
      );

   /// assignment operator
   EcSingularityProximityFunction& operator=
      (
      const EcSingularityProximityFunction& orig
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

   /// gets a pointer to the input weights
   virtual const EcXmlRealVector* inputWeights
      (
      ) const;

   /// sets the pointer to the input weights
   virtual void setInputWeights
      (
      const EcXmlRealVector* inputWeights
      );

   /// gets a pointer to the output weights
   virtual const EcXmlRealVector* outputWeights
      (
      ) const;

   /// sets the pointer to the output weights
   virtual void setOutputWeights
      (
      const EcXmlRealVector* outputWeights
      );

   /// gets the damping factor
   virtual EcReal dampingFactor
      (
      ) const;

   /// sets the damping factor
   virtual void setDampingFactor
      (
      EcReal dampingFactor
      );

   /// evaluate the function using an active state
   virtual EcReal evaluate
      (
      EcManipulatorActiveState& actState,
      EcBoolean nominal = EcTrue
      ) const;

   /// get a null object
   static EcSingularityProximityFunction nullObject
      (
      );

protected:
   /// a pointer to the manipulator
   const EcIndividualManipulator* m_pManipulator;

   /// a pointer to an end-effector set
   const EcEndEffectorSet*         m_pEndEffectorSet;

   /// a pointer to input weights
   const EcXmlRealVector*          m_pInputWeights;

   /// a pointer to output weights
   const EcXmlRealVector*          m_pOutputWeights;

   /// a damping factor
   EcReal m_DampingFactor;

   /// utility Jacobian tool
   mutable EcJacobianTool m_JacobianTool;

   /// utility Jacobian
   mutable EcManipulatorJacobian m_Jacobian;

   /// utility array for J*J-transpose
   mutable EcReArray m_JJT;

   /// utility array for the Cholesky decompositiion of JJT
   mutable EcReArray m_L;
};

#endif // ecSingProxFunction_H_
