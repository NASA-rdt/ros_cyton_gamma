#ifndef EcBaseStateEqualityConstraint_H_
#define EcBaseStateEqualityConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseStateEqualityConstraint.h
/// @class EcBaseStateEqualityConstraint
/// @brief Abstract base class for position state restriction
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeElement.h>
#include <matrixUtilities/ecReArray.h>
#include <manipulator/ecManipActiveState.h>

class EcVelocityState;
class EcAccelerationState;
class EcIndividualManipulator;

/**
An abstract base class representing a position state constraint in the form
f(x) = 0, where x is a position state of a manipulator
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseStateEqualityConstraint : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseStateEqualityConstraint
      (
      );

   /// destructor
   virtual ~EcBaseStateEqualityConstraint
      (
      );

   /// copy constructor
   EcBaseStateEqualityConstraint
      (
      const EcBaseStateEqualityConstraint& orig
      );

   /// assignment operator
   EcBaseStateEqualityConstraint& operator=
      (
      const EcBaseStateEqualityConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseStateEqualityConstraint& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// return the degrees of constraint
   virtual EcU32 doc
      (
      ) const = 0;

   /// restrain the position state
   virtual EcBoolean constrainPosition
      (
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState
      ) const = 0;

   /// restrain the velocity state
   virtual EcBoolean constrainVelocity
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      EcVelocityState& velocityState
      ) const = 0;

   /// restrain the acceleration state
   virtual EcBoolean constrainAcceleration
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      EcAccelerationState& accelerationState
      ) const = 0;

   /// returns the jacobian of the function.
   /**
   The columnsize of the returned Jacobian should be the number of joints for fixed-based manipulators and the number of joints + 6
   for floating-based manipulators. For floating-base manipulators, the 6-element component that represents the mobile base
   should be appended to the joint component, with the first three corresponding to linear motion and the last three to angular motion.
   The row size should be the degrees of constraint.
   */
   virtual const EcReArray& jacobian
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& state
      ) const = 0;


   /// returns the jacobian time derivative of the function.
   /**
   The column size of the returned Jacobian time derivative should be the number of joints for fixed-based manipulators and the number of joints + 6
   for floating-based manipulators. For floating-base manipulators, the 6-element component that represents the mobile base
   should be appended to the joint component, with the first three corresponding to linear motion and the last three to angular motion.
   The row size should be the degrees of constraint.
   */
   virtual const EcReArray& jacobianDerivative
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& state,
      const EcVelocityState& velState
      ) const;

protected:
   mutable EcReArray       m_Jacobian;             ///< The Jacobian
   mutable EcReArray       m_JacobianDerivative;   ///< The Jacobian derivative

   // utility values for finite differencing to get the Jacobian derivative
   mutable EcPositionState m_UtilityState;         ///< Utility state
   mutable EcManipulatorActiveState  m_BaseActiveState;     ///< Base active state
   mutable EcManipulatorActiveState  m_OffsetActiveState;   ///< Offset active state

   // finite differencing parameters
   /// The maximum time increment used in finite differencing when calculating Jacobian derivative
   static const EcReal     m_theMaxTimeIncrementForFiniteDifferencing;

   /// The maximum joint increment used in finite differencing when calculating Jacobian derivative
   static const EcReal     m_theMaxJointIncrementForFiniteDifferencing;
};

#endif // EcBaseStateEqualityConstraint_H_
