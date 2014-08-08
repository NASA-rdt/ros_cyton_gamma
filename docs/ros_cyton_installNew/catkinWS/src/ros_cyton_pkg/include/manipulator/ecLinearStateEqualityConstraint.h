#ifndef EcLinearStateEqualityConstraint_H_
#define EcLinearStateEqualityConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinearStateEqualityConstraint.h
/// @class EcLinearStateEqualityConstraint
/// @brief A linear state constraint.
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStateEqualityConstraint.h"
#include <function/ecMultivariableConstraintContainer.h>

class EC_FOUNDATION_MANIPULATOR_DECL EcLinearStateEqualityConstraint : public EcBaseStateEqualityConstraint
{
public:
   /// default constructor
   EcLinearStateEqualityConstraint
      (
      );

   /// destructor
   virtual ~EcLinearStateEqualityConstraint
      (
      );

   /// copy constructor
   EcLinearStateEqualityConstraint
      (
      const EcLinearStateEqualityConstraint& orig
      );

   /// assignment operator
   EcLinearStateEqualityConstraint& operator=
      (
      const EcLinearStateEqualityConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinearStateEqualityConstraint& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get joint weights
   virtual const EcXmlRealVectorVector& jointWeights
      (
      ) const;

   /// set joint weights
   virtual void setJointWeights
      (
      const EcXmlRealVectorVector& jointWeights
      );

   /// get base weights
   virtual const EcXmlRealVectorVector& baseWeights
      (
      ) const;

   /// set base weights
   virtual void setBaseWeights
      (
      const EcXmlRealVectorVector& baseWeights
      );

   /// get weighted sums
   virtual const EcXmlRealVector& weightedSums
      (
      ) const;

   /// set weighted sums
   virtual void setWeightedSums
      (
      const EcXmlRealVector& weightedSums
      );

   /// return the degrees of constraint
   virtual EcU32 doc
      (
      ) const;

   /// restrain the position state
   virtual EcBoolean constrainPosition
      (
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState
      ) const;

   /// restrain the velocity state
   virtual EcBoolean constrainVelocity
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      EcVelocityState& velocityState
      ) const;

   /// restrain the velocity state
   virtual EcBoolean constrainAcceleration
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      EcAccelerationState& accelerationState
      ) const;

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
      ) const;

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

   /// get a null object
   static EcLinearStateEqualityConstraint nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
protected:
   // the linear constraint parameters
   EcXmlRealVectorVector               m_JointWeights;      ///< the joint weights
   EcXmlRealVectorVector               m_BaseWeights;       ///< the base weights
   EcXmlRealVector                     m_WeightedSums;      ///< the weighted sums
};

#endif // EcLinearStateEqualityConstraint_H_
