#ifndef EcStateEqualityConstraintVector_H_
#define EcStateEqualityConstraintVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecStateEqualityConstraintVector.h
/// @class EcStateEqualityConstraintVector
/// @brief Vector of state restrictions
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStateEqualityConstraint.h"
#include <xml/ecXmlVarVectType.h>

/// type definition of XML variable vector of EcBaseStateEqualityConstraint to be used as a base class
typedef EcXmlVariableVectorType<EcBaseStateEqualityConstraint> EcBaseStateEqualityConstraintVector;

class EcPositionState;
class EcVelocityState;
class EcIndividualManipulator;

/// Vector of EcBaseStateEqualityConstraint
class EC_FOUNDATION_MANIPULATOR_DECL EcStateEqualityConstraintVector :  public EcBaseStateEqualityConstraintVector
{
public:
   /// default constructor
   EcStateEqualityConstraintVector
      (
      );

   /// destructor
   virtual ~EcStateEqualityConstraintVector
      (
      );

   /// copy constructor
   EcStateEqualityConstraintVector
      (
      const EcStateEqualityConstraintVector& orig
      );

   /// assignment operator
   EcStateEqualityConstraintVector& operator=
      (
      const EcStateEqualityConstraintVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStateEqualityConstraintVector& orig
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

   /// return a string token
   virtual const EcToken& token
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

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcStateEqualityConstraintVector nullObject
      (
      );

   /// return the total degrees of constraint
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

   /// returns the jacobian of the function for dynamics applications.
   /**
   The column size of the returned Jacobian should be the number of joints for fixed-based manipulators and the number of joints + 6
   for floating-based manipulators. For floating-base manipulators, the 6-element component that represents the mobile base
   should be prepended to the joint component, with the first three corresponding to linear motion and the last three to angular motion.
   The row size should be the degrees of constraint.
   */
   virtual const EcReArray& jacobian
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& state
      ) const;

   /// returns the jacobian derivative of the function for dynamics applications.
   /**
   The column size of the returned Jacobian derivative should be the number of joints for fixed-based manipulators and the number of joints + 6
   for floating-based manipulators. For floating-base manipulators, the 6-element component that represents the mobile base
   should be prepended to the joint component, with the first three corresponding to linear motion and the last three to angular motion.
   The row size should be the degrees of constraint.
   */
   virtual const EcReArray& jacobianDerivative
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& posState,
      const EcVelocityState& velState
      ) const;

protected:
   mutable EcReArray    m_Jacobian;             ///< The Jacobian
   mutable EcReArray    m_JacobianDerivative;   ///< The Jacobian derivative

};

#endif // EcStateEqualityConstraintVector_H_
