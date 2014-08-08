#ifndef ecErrorReductionFunction_H_
#define ecErrorReductionFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecErrorReductionFunction.h
/// @class EcErrorReductionFunction
/// @brief Computes  f(q) = J'AJCe used to drive joints in a
///        direction that minimizes velocity errors cause by
///        high frequency noise on the joints.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecConstants.h>
#include "ecScalarManipFunction.h"
#include <control/ecJacobianTool.h>

// forward declarations
class EcEndEffectorSet;
class EcIndividualManipulator;
class EcManipulatorEndEffectorForce;
class EcSystemActiveState;

/** Computes  f(q) = J'AJCe used to drive joints in a
               direction that minimizes velocity errors cause by
               high frequency noise on the joints.
*/
class EC_ACTIN_MEASURE_DECL EcErrorReductionFunction: public EcScalarManipulatorFunction
{
public:
   /// default constructor
   EcErrorReductionFunction
      (
      );

   /// destructor
   virtual ~EcErrorReductionFunction
      (
      );

   /// copy constructor
   EcErrorReductionFunction
      (
      const EcErrorReductionFunction& orig
      );

   /// assignment operator
   EcErrorReductionFunction& operator=
      (
      const EcErrorReductionFunction& orig
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
      EcManipulatorActiveState& manipActState,
      EcBoolean nominal = EcTrue
      ) const;

   /// sets the covariance matrix
   virtual void setCovMatrix
      (
         EcReArray *value
      ) ;

   /// gets the covariance matrix
   virtual EcReArray getCovMatrix
      (
      ) const ;

   /// sets the A matrix
   virtual void setAMatrix
      (
         EcReArray *value
      ) ;

   /// gets the A matrix
   virtual EcReArray getAMatrix
      (
      ) const ;

   /// get a null object
   static EcErrorReductionFunction nullObject
      (
      );

protected:

   /// a pointer to the manipulator
   const EcIndividualManipulator* m_pManipulator;

   /// a pointer to an end-effector set
   const EcEndEffectorSet*         m_pEndEffectorSet;

   /// manipulator end effector forces
   const EcManipulatorEndEffectorForce* m_pManipEndEffectorForces;

   /// utility Jacobian tool
   mutable EcJacobianTool m_JacobianTool;

   /// utility Jacobian
   mutable EcManipulatorJacobian m_Jacobian;

   /// A matrix
   mutable EcReArray *m_pA ;

   /// covarience matrix
   mutable EcReArray *m_pCovMatrix ;

   /// utility array for J^T*A
   mutable EcReArray m_JTA;

   /// utility array for J^T*A*J
   mutable EcReArray m_JTAJ;

   /// utility array for J^T*A*J*C
   mutable EcReArray m_JTAJC;
};

#endif // ecErrorReductionFunction_H_
