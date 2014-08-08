#ifndef ecUnaryFunctions_H_
#define ecUnaryFunctions_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecUnaryFunctions.h
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <functional>

/// A unary function object that takes EcReal as an argument and returns EcReal.
class EC_FOUNDATION_FUNCTION_DECL EcRealRealUnaryFunction : public std::unary_function<EcReal, EcReal>
{
public:
   virtual ~EcRealRealUnaryFunction
      (
      )
   {}

   /// Overloaded operator() that takes EcReal as an argument and returns EcReal. Derived class must
   /// implement this
   /**
    * @param x A real number
    * @return A real number
    */
   virtual EcReal operator()
      (
      EcReal x
      )const =0;
};

#endif // ecUnaryFunctions_H_
