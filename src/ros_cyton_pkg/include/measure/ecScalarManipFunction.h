#ifndef ecScalarManipFunction_H_
#define ecScalarManipFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecScalarManipFunction.h
/// @class EcScalarManipulatorFunction
/// @brief Provides a base class for scalar functions of a
///        manipulator's position state.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCore/ecConstants.h>

// forward declarations

class EcManipulatorActiveState;

/** Provides a base class for scalar functions of a manipulator's state.
*/
class EC_ACTIN_MEASURE_DECL EcScalarManipulatorFunction
{
public:
   /// default constructor
   EcScalarManipulatorFunction
      (
      );

   /// destructor
   virtual ~EcScalarManipulatorFunction
      (
      );

   /// copy constructor
   EcScalarManipulatorFunction
      (
      const EcScalarManipulatorFunction& orig
      );

   /// assignment operator
   EcScalarManipulatorFunction& operator=
      (
      const EcScalarManipulatorFunction& orig
      );

   /// evaluate the function using an active state
   /// Normally, EcScalarManipulatorFunction is used in conjuction with EcFiniteDifferenceTool, which calls
   /// evaluate method at least twice - once for the nominal case and at least once more for perturbed cases
   /// nominal indicates whether the current evaluate is called for nominal (true) or perturbed (false) case.
   virtual EcReal evaluate
      (
      EcManipulatorActiveState& manipActState,
      EcBoolean nominal = EcTrue
      ) const = 0;
};

#endif // ecScalarManipFunction_H_
