#ifndef ecFiniteDifferenceTool_H_
#define ecFiniteDifferenceTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecFiniteDifferenceTool.h
/// @class EcFiniteDifferenceTool
/// @brief Provides a tool for calculating differential values using
///        the method of finite differences.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCore/ecConstants.h>
#include <manipulator/ecManipActiveState.h>

// forward declarations
class EcScalarManipulatorFunction;
class EcIndividualManipulator;
class EcSystemActiveState;

/** Provides a tool for calculating differential values using
 the method of finite differences.
*/
class EC_ACTIN_CONTROL_DECL EcFiniteDifferenceTool
{
public:
   /// default constructor
   EcFiniteDifferenceTool
      (
      );

   /// destructor
   virtual ~EcFiniteDifferenceTool
      (
      );

   /// copy constructor
   EcFiniteDifferenceTool
      (
      const EcFiniteDifferenceTool& orig
      );

   /// assignment operator
   EcFiniteDifferenceTool& operator=
      (
      const EcFiniteDifferenceTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFiniteDifferenceTool& orig
      ) const;

   /// get function
   virtual const EcScalarManipulatorFunction* function
      (
      ) const;

   /// set function
   virtual void setFunction
      (
      const EcScalarManipulatorFunction* function
      );

   /// get manipulator
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// set manipulator
   virtual void setManipulator
      (
      const EcIndividualManipulator* manipulator
      );

   /// get active state
   virtual const EcManipulatorActiveState& activeState
      (
      ) const;

   /// get epsilon
   virtual EcReal epsilon
      (
      ) const;

   /// set epsilon
   virtual void setEpsilon
      (
      EcReal epsilon
      );

   /// get the fixed-base flag
   virtual EcBoolean isFixedBase
      (
      ) const;

   /// set the fixed-base flag
   virtual void setIsFixedBase
      (
      EcBoolean isFixedBase
      );

   /// calculate the gradient of the function.
   virtual EcBoolean calculateGradient
      (
      EcManipulatorActiveState&  actState,
      EcReArray& gradient
      );

   /// calculate directional derivative in the nullspace
   virtual EcBoolean calculateDirectionalDerivativeInNull
      (
      EcManipulatorActiveState&  actState,
      const EcReArray& nullSpace,
      EcReArray& dirDerInNull
      );

   /// get a null object
   static EcFiniteDifferenceTool nullObject
      (
      );

protected:
   const EcScalarManipulatorFunction*  m_pFunction;         ///< const pointer to the function
   const EcIndividualManipulator*      m_pManipulator;      ///< const pointer to the manipulator
   EcReal                              m_Epsilon;           ///< the perturbation value
   EcBoolean                           m_IsFixedBase;       ///< flag indicating if the manipulator is fixed base
   EcSystemActiveState*                m_pSystemActiveState;///< pointer to the system active state

   // utility objects
   EcManipulatorActiveState    m_ActiveState;         ///< the utility active state
   EcPositionState             m_ChangingPosState;    ///< the perturbed position state
   EcReArray                   m_UtilityNullSpace;    ///< the utility null space
};

#endif // ecFiniteDifferenceTool_H_
