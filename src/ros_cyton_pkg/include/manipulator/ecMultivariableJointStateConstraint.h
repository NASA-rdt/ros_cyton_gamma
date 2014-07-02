#ifndef ecMultivariableJointStateConstraint_H_
#define ecMultivariableJointStateConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultivariableJointStateConstraint.h
/// @class EcMultivariableJointStateConstraint
/// @brief A state constraint the uses a multivariable constraint for
///        joint state.
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStateConstraint.h"
#include <function/ecMultivariableConstraintContainer.h>

class EC_FOUNDATION_MANIPULATOR_DECL EcMultivariableJointStateConstraint : public EcBaseStateConstraint
{
public:
   /// default constructor
   EcMultivariableJointStateConstraint
      (
      );

   /// destructor
   virtual ~EcMultivariableJointStateConstraint
      (
      );

   /// copy constructor
   EcMultivariableJointStateConstraint
      (
      const EcMultivariableJointStateConstraint& orig
      );

   /// assignment operator
   EcMultivariableJointStateConstraint& operator=
      (
      const EcMultivariableJointStateConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultivariableJointStateConstraint& orig
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

   /// \copydoc EcBaseStateConstraint::evaluate()
   virtual EcReal evaluate
      (
      const EcPositionState& state
      ) const;

   /// \copydoc EcBaseStateConstraint::gradient()
   virtual const EcRealVector& gradient
      (
      const EcPositionState& state,
      EcBoolean isFixedBase
      ) const;

   /// gets the constraint
   virtual const EcBaseMultivariableConstraint* constraint
      (
      ) const;

   /// gets the constraint - non-const version
   virtual EcBaseMultivariableConstraint* constraint
      (
      );

   /// sets the constraint
   virtual void setConstraint
      (
      const EcBaseMultivariableConstraint& value
      );

   /// get a null object
   static EcMultivariableJointStateConstraint nullObject
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
   /// the multivariable constraint container
   EcMultivariableConstraintContainer  m_ConstraintContainer;
};

#endif // ecMultivariableJointStateConstraint_H_
