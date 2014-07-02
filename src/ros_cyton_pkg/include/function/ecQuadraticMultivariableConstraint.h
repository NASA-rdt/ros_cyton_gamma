#ifndef ecQuadraticMultivariableConstraint_H_
#define ecQuadraticMultivariableConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecQuadraticMultivariableConstraint.h
/// @class EcQuadraticMultivariableConstraint
/// @brief A class for a quadratic constraint
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseMultivariableConstraint.h"

#include <xml/ecXmlPairType.h>

/**
This class represents a quadratic constraint in the form of

sum ( a  x x  ) + sum( b x  ) + c >= 0, where i<=j
 ij    ij i j           i i

For example,
   2
2*x - 1.3x x + 2.4x -1.2 >=0
   0      0 1      3
*/
class EC_FOUNDATION_FUNCTION_DECL EcQuadraticMultivariableConstraint : public EcBaseMultivariableConstraint
{
public:
   /// default constructor
   EcQuadraticMultivariableConstraint
      (
      );

   /// destructor
   virtual ~EcQuadraticMultivariableConstraint
      (
      );

   /// copy constructor
   EcQuadraticMultivariableConstraint
      (
      const EcQuadraticMultivariableConstraint& orig
      );

   /// assignment operator
   EcQuadraticMultivariableConstraint& operator=
      (
      const EcQuadraticMultivariableConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcQuadraticMultivariableConstraint& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   // No doxygen tags - will pull from base class.
   virtual EcReal evaluate
      (
      const EcRealVector& vDomainValue
      ) const;

   // No doxygen tags - will pull from base class.
   virtual const EcRealVector& gradient
      (
      const EcRealVector& vDomainValue
      ) const;

   /// gets the offset (c)
   virtual EcReal offset
      (
      ) const;

   /// sets the offset (c)
   virtual void setOffset
      (
      EcReal value
      );

   /// gets the first-order coefficient at index (b_i)
   virtual EcReal firstOrderCoefficient
      (
      EcU32 index
      ) const;

   /// sets the first-order coefficient at index (b_i)
   virtual void setFirstOrderCoefficient
      (
      EcU32 index,
      EcReal value
      );

   /// gets the second-order coefficient at index0 and index1 (a_ij). Note that secondOrderCoefficient(index0, index1) returns the same result as secondOrderCoefficient(index1, index0). For example, secondOrderCoefficient(3,1) will return the same value as secondOrderCoefficient(1,3).
   virtual EcReal secondOrderCoefficient
      (
      EcU32 index0,
      EcU32 index1
      ) const;

   /// sets the second-order coefficient at index0 and index1 (a_ij). Note that calling setSecondOrderCoefficient(index1,index0) has the same effect as calling setSecondOrderCoefficient(index0, index1). For example, calling setSecondOrderCoefficient(3,2) is the same as setSecondOrderCoefficient(2,3) and will override previous calls to setSecondOrderCoefficient(2,3)and vice versa because x_3*x_2 is the same as x_2*x_3.
   virtual void setSecondOrderCoefficient
      (
      EcU32 index0,
      EcU32 index1,
      EcReal value
      );

   /// gets the second-order coefficient at index0 and index0 (a_ii). Overloaded for convenience.
   virtual EcReal secondOrderCoefficient
      (
      EcU32 index0
      ) const;

   /// sets the second-order coefficient at index0 and index0 (a_ii). Overloaded for convenience.
   virtual void setSecondOrderCoefficient
      (
      EcU32 index0,
      EcReal value
      );

   /// get a null object
   static EcQuadraticMultivariableConstraint nullObject
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
   /// the offset value
   EcXmlReal            m_Offset;

   /// the vector for indices of first-order coefficients
   EcXmlU32Vector       m_FirstOrderIndices;

   /// the vector for first-order coefficients
   EcXmlRealVector      m_FirstOrderCooefficients;

   /// the vector for index pairs of second-order coefficients
   EcXmlU32U32PairVector   m_SecondOrderIndexPairs;

   /// the vector for second-order coefficients
   EcXmlRealVector         m_SecondOrderCooefficients;
};

#endif // ecQuadraticMultivariableConstraint_H_
