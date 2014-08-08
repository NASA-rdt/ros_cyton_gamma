#ifndef ecBaseMultivariableConstraint_H_
#define ecBaseMultivariableConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseMultivariableConstraint.h
/// @class EcBaseMultivariableConstraint
/// @brief Abstract base class for multivariable constraint
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecBaseExpTreeElement.h>

/**
An abstract base class representing a multivariable constraint in the form
f(x) >= 0, where x is a variable vector of size n.
*/
class EC_FOUNDATION_FUNCTION_DECL EcBaseMultivariableConstraint : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseMultivariableConstraint
      (
      );

   /// destructor
   virtual ~EcBaseMultivariableConstraint
      (
      );

   /// copy constructor
   EcBaseMultivariableConstraint
      (
      const EcBaseMultivariableConstraint& orig
      );

   /// assignment operator
   EcBaseMultivariableConstraint& operator=
      (
      const EcBaseMultivariableConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseMultivariableConstraint& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// evaluate the function (left hand side of the constraint f(x) >= 0)
   virtual EcReal evaluate
      (
      const EcRealVector& vDomainValue
      ) const = 0;

   /// returns the gradient of the function. Must be normalized.
   virtual const EcRealVector& gradient
      (
      const EcRealVector& vDomainValue
      ) const = 0;

   /// evaluate the function. Overloaded for convenience.
   virtual EcReal evaluate
      (
      const EcXmlRealVector& vDomainValue
      ) const;

   /// returns the gradient of the function. Overloaded for convenience.
   virtual const EcRealVector& gradient
      (
      const EcXmlRealVector& vDomainValue
      ) const;

protected:
   /// normalize the gradient
   virtual void normalizeGradient
      (
      ) const;

   /// copy an EcXmlRealVector instance to m_UtilityVector
   virtual void copyXmlRealVector
      (
      const EcXmlRealVector& vector
      ) const;
protected:
   mutable EcRealVector    m_Gradient;          ///< The gradient
   mutable EcRealVector    m_UtilityVector;     ///< A utility vector
};

#endif // ecBaseMultivariableConstraint_H_
