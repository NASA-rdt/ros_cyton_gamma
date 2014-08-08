#ifndef ecLinearMultivariableConstraint_H_
#define ecLinearMultivariableConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinearMultivariableConstraint.h
/// @class EcLinearMultivariableConstraint
/// @brief A class for a linear constraint
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseMultivariableConstraint.h"

/**
This class represents a linear constraint in the form of

sum ( a x  ) + b >= 0
 i     i i

*/
class EC_FOUNDATION_FUNCTION_DECL EcLinearMultivariableConstraint : public EcBaseMultivariableConstraint
{
public:
   /// default constructor
   EcLinearMultivariableConstraint
      (
      );

   /// destructor
   virtual ~EcLinearMultivariableConstraint
      (
      );

   /// copy constructor
   EcLinearMultivariableConstraint
      (
      const EcLinearMultivariableConstraint& orig
      );

   /// assignment operator
   EcLinearMultivariableConstraint& operator=
      (
      const EcLinearMultivariableConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinearMultivariableConstraint& orig
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

   // No doxygen tags will make it pull from base class
   virtual EcReal evaluate
      (
      const EcRealVector& vDomainValue
      ) const;

   // No doxygen tags will make it pull from base class
   virtual const EcRealVector& gradient
      (
      const EcRealVector& vDomainValue
      ) const;

   /// gets the offset (b)
   virtual EcReal offset
      (
      ) const;

   /// sets the offset (b)
   virtual void setOffset
      (
      EcReal value
      );

   /// gets the coefficient at index
   virtual EcReal coefficient
      (
      EcU32 index
      ) const;

   /// sets the coefficient at index
   virtual void setCoefficient
      (
      EcU32 index,
      EcReal value
      );

   /// get a null object
   static EcLinearMultivariableConstraint nullObject
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
   /// the offset value (b)
   EcXmlReal            m_Offset;

   /// the vector for indices
   EcXmlU32Vector       m_Indices;

   /// the vector for coefficients
   EcXmlRealVector      m_Cooefficients;
};

#endif // ecLinearMultivariableConstraint_H_
