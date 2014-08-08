#ifndef ecGaussQuadrature_H_
#define ecGaussQuadrature_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGaussQuadrature.h
/// @class EcGaussQuadrature
/// @brief Implements Gauss Quadrature integration
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecUnaryFunctions.h"

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

//typedef EcReal (*EcRealRealUnaryFunction)(EcReal);

/**
\class EcGaussQuadrature
It implements the Guass quadrature numerical integration technique. The formulas used are called
Gauss-Legendre formulas. The high-precision values of abscissas and weights used in the formulas
are obtained from Pavel Holoborodko's Numerical Integration web site:
http://www.holoborodko.com/pavel/?page_id=679.

Gauss-Legendre n-points quadrature, exact for polynomial of degree <=2n-1

1. n - even:

int(f(t),t=a..b) = A*sum(w[i]*f(A*x[i]+B),i=0..n-1)
		 = A*sum(w[k]*[f(B+A*x[k])+f(B-A*x[k])],k=0..n/2-1)
	A = (b-a)/2,
	B = (a+b)/2


2. n - odd:

int(f(t),t=a..b) = A*sum(w[i]*f(A*x[i]+B),i=0..n-1)
		 = A*w[0]*f(B)+A*sum(w[k]*[f(B+A*x[k])+f(B-A*x[k])],k=1..(n-1)/2)
	A = (b-a)/2,
	B = (a+b)/2
*/

class EC_FOUNDATION_FUNCTION_DECL EcGaussQuadrature : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGaussQuadrature
      (
      );

   /// destructor
   virtual ~EcGaussQuadrature
      (
      );

   /// copy constructor
   EcGaussQuadrature
      (
      const EcGaussQuadrature& orig
      );

   /// assignment operator
   EcGaussQuadrature& operator=
      (
      const EcGaussQuadrature& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGaussQuadrature& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone
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

   /// get order
   virtual EcU32 order
      (
      ) const;

   /// set order
   virtual void setOrder
      (
      EcU32 value
      );

   /// integrate
   /**
   \param[in] f The integrand
   \param[in] a The lower value of the integration interval
   \param[in] b The upper value of the integration interval
   \return Computed integral value.
   */
   virtual EcReal integrate
      (
      const EcRealRealUnaryFunction& f,
      EcReal a,
      EcReal b
      ) const;

   /// token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// obtain the abscissas and weights for a given quadrature order
   /**
    * @param[in] order The quadrature order
    * @param[out] abscissas The abscissas for the given order
    * @param[out] weights The weigths for the given order
    */
   virtual void obtainAbscissasAndWeights
      (
      EcU32 order,
      const EcReal*& abscissas,
      const EcReal*& weights
      ) const;

protected:
   EcXmlU32          m_Order;       ///< the quadrature order

   // non-XML data
   const EcReal*   m_pAbscissas;    ///< Pointer to the abscissas
   const EcReal*   m_pWeights;      ///< Pointer to the weights
};

#endif // ecGaussQuadrature_H_
