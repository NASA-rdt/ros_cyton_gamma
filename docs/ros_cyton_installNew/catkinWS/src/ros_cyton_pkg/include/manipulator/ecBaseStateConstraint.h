#ifndef ecBaseStateConstraint_H_
#define ecBaseStateConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseStateConstraint.h
/// @class EcBaseStateConstraint
/// @brief Abstract base class for position state constraint
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeElement.h>

class EcPositionState;

/**
An abstract base class representing a position state constraint in the form
f(x) >= 0, where x is a position state of a manipulator
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseStateConstraint : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseStateConstraint
      (
      );

   /// destructor
   virtual ~EcBaseStateConstraint
      (
      );

   /// copy constructor
   EcBaseStateConstraint
      (
      const EcBaseStateConstraint& orig
      );

   /// assignment operator
   EcBaseStateConstraint& operator=
      (
      const EcBaseStateConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseStateConstraint& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcPositionState& state
      ) const = 0;

   /// returns the gradient of the function. Must be normalized.
   /**
   The size of the returned gradient should be the number of joints for fixed-based manipulators and the number
   of joints + 6 for floating-based manipulators. For floating-base manipulators, the 6-element component that
   represents the mobile base should be appended to the joint component, with the first three corresponding to
   linear motion and the last three to angular motion.
   */
   virtual const EcRealVector& gradient
      (
      const EcPositionState& state,
      EcBoolean isFixedBase
      ) const = 0;

protected:
   /// normalize the gradient
   virtual void normalizeGradient
      (
      ) const;

protected:
   mutable EcRealVector    m_Gradient;    ///< The gradient
};

#endif // ecBaseStateConstraint_H_
