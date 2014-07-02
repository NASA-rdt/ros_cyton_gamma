#ifndef ecErrorSensFunction_H_
#define ecErrorSensFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecErrorSensFunction.h
/// @class EcErrorSensitivityFunction
/// @brief Provides a measure of joint error sensitivity.  This
///        measure is given by the weighted sum of the squares of errors in
///        end-effector velocities cause by an error in a joint angle.
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

/** Provides a measure of joint error sensitivity.  This measure is given
  by the weighted sum of the squares of errors in end-effector velocities
  cause by an error in a joint angle.
*/
class EC_ACTIN_MEASURE_DECL EcErrorSensitivityFunction : public EcScalarManipulatorFunction
{
public:
   /// default constructor
   EcErrorSensitivityFunction
      (
      );

   /// destructor
   virtual ~EcErrorSensitivityFunction
      (
      );

   /// copy constructor
   EcErrorSensitivityFunction
      (
      const EcErrorSensitivityFunction& orig
      );

   /// assignment operator
   EcErrorSensitivityFunction& operator=
      (
      const EcErrorSensitivityFunction& orig
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
   virtual const EcXmlRealVector* endEffectorWeights
      (
      ) const;

   /// sets the pointer to the input weights
   virtual void setEndEffectorWeights
      (
      const EcXmlRealVector* endEffectorWeights
      );

   /// gets the focus joint index
   virtual EcU32 focusJoint
      (
      ) const;

   /// sets the focus joint index
   virtual void setFocusJoint
      (
      EcU32 focusJoint
      );

   /// evaluate the function using an active state
   virtual EcReal evaluate
      (
      EcManipulatorActiveState& actState,
      EcBoolean nominal = EcTrue
      ) const;

   /// get a null object
   static EcErrorSensitivityFunction nullObject
      (
      );

protected:

   /// a pointer to the manipulator
   const EcIndividualManipulator*  m_pManipulator;

   /// a pointer to an end-effector set
   const EcEndEffectorSet*         m_pEndEffectorSet;

   /// a pointer to input weights
   const EcXmlRealVector*          m_pEndEffectorWeights;

   /// the focus joint
   EcU32                           m_FocusJoint;

   /// utility Jacobian tool
   mutable EcJacobianTool          m_JacobianTool;
   /// utility Jacobian
   mutable EcManipulatorJacobian   m_Jacobian;
};

#endif // ecErrorSensFunction_H_
