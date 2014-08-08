#ifndef ecMultivariableConstraintContainer_H_
#define ecMultivariableConstraintContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultivariableConstraintContainer.h
/// @class EcMultivariableConstraintContainer
/// @brief The container of a multivariable constraint
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseMultivariableConstraint.h"
#include <xml/ecBaseExpTreeContainer.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of EcBaseExpressionTreeContainer<EcBaseMultivariableConstraint> to be used as a base class
typedef EcBaseExpressionTreeContainer<EcBaseMultivariableConstraint> EcBaseMultivariableConstraintContainer;

/// A conttainer of EcBaseMultivariableConstraint
class EC_FOUNDATION_FUNCTION_DECL EcMultivariableConstraintContainer :
   public EcBaseMultivariableConstraintContainer
{
public:
   /// default constructor
   EcMultivariableConstraintContainer
      (
      );

   /// destructor
   virtual ~EcMultivariableConstraintContainer
      (
      );

   /// copy constructor
   EcMultivariableConstraintContainer
      (
      const EcMultivariableConstraintContainer& orig
      );

   /// assignment operator
   EcMultivariableConstraintContainer& operator=
      (
      const EcMultivariableConstraintContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultivariableConstraintContainer& orig
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

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// @copydoc EcBaseMultivariableConstraint::evaluate(const EcRealVector&)
   virtual EcReal evaluate
      (
      const EcRealVector& vDomainValue
      ) const;

   /// @copydoc EcBaseMultivariableConstraint::evaluate(const EcXmlRealVector&)
   virtual EcReal evaluate
      (
      const EcXmlRealVector& vDomainValue
      ) const;

   /// @copydoc EcBaseMultivariableConstraint::gradient(const EcRealVector&)
   virtual const EcRealVector& gradient
      (
      const EcRealVector& vDomainValue
      ) const;

   /// @copydoc EcBaseMultivariableConstraint::gradient(const EcXmlRealVector&)
   virtual const EcRealVector& gradient
      (
      const EcXmlRealVector& vDomainValue
      ) const;

   /// get a null object
   static EcMultivariableConstraintContainer nullObject
      (
      );
protected:
   /// dummy gradient
   EcRealVector   m_Gradient;
};

#endif // ecMultivariableConstraintContainer_H_
