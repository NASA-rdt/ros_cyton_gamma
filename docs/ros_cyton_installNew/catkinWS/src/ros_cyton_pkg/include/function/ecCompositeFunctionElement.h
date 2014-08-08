#ifndef ecCompositeFunctionElement_H_
#define ecCompositeFunctionElement_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecCompositeFunctionElement.h
/// @class EcCompositeFunctionElement
/// @brief Base class for table function module
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeElement.h>

/// Table Function Base Class
/**
   Abstract base class for table function interpolator and branch.
*/
class EC_FOUNDATION_FUNCTION_DECL EcCompositeFunctionElement : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcCompositeFunctionElement
      (
      );

   /// constructor given container pointer
   explicit EcCompositeFunctionElement
      (
      const EcXmlBaseVariableCompoundType*  containerPointer
      );

   /// destructor
   virtual ~EcCompositeFunctionElement
      (
      );

   /// copy constructor
   EcCompositeFunctionElement
      (
      const EcCompositeFunctionElement& orig
      );

   /// assignment operator
   EcCompositeFunctionElement& operator=
      (
      const EcCompositeFunctionElement& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCompositeFunctionElement& orig
      ) const;

   /// Evaluate function table
   virtual const EcRealVector& evaluate
      (
      const EcRealVector& vInput,
      EcBoolean& status
      ) const=0;

   /// Get bounds of independent data
   virtual const EcRealVectorVector& bounds
      (
      ) const;

   /// Get boundary methods
   virtual const EcBooleanVectorVector& limitOrExtrapolate
      (
      ) const;

   /// Initialize bounds of independent data
   virtual const EcRealVectorVector& initBounds
      (
      )=0;

   /// Initialize boundary methods
   virtual const EcBooleanVectorVector& initLimitOrExtrapolate
      (
      )=0;

   /// Test bounds
   /**
       Test for look up data being in bounds
       \param vInput Data to test against
       \retval Boolean results of bounds test
   */
   virtual EcBoolean isInBounds
      (
      const EcRealVector& vInput
      ) const;

   /// Test extrapolation
   /**
       Test for look up data being in bounds
       \param vInput Data to test against
       \retval Boolean results of bounds test
   */
   virtual EcBoolean ableToExtrap
      (
      const EcRealVector& vInput
      ) const;

protected:
   /// interpolation boundaries
   EcRealVectorVector m_Bounds;

   /// interpolation limits
   EcBooleanVectorVector m_LimitOrExtrapolate;
};

#endif // ecCompositeFunctionElement_H_
