#ifndef EcRandomTensorTool_H_
#define EcRandomTensorTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecRandomTensorTool.h
/// @class EcRandomTensorTool
/// @brief Holds a tool for creating random arrays and tensors.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCore/ecMacros.h>
#include <foundCore/ecMath.h>
#include <foundCore/ecRandom.h>
#include <matrixUtilities/ecReArray.h>
#include "ecRandomTensorTool.h"

class EcBaseScalarFunction;

/** Holds a description of a random tensor tool.
*/
class EC_FOUNDATION_FUNCTION_DECL EcRandomTensorTool
{
public:
   /// default constructor
   EcRandomTensorTool
      (
      );

   /// destructor
   virtual ~EcRandomTensorTool
      (
      );

   /// copy constructor
   EcRandomTensorTool
      (
      const EcRandomTensorTool& orig
      );

   /// assignment operator
   EcRandomTensorTool& operator=
      (
      const EcRandomTensorTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRandomTensorTool& orig
      ) const;

   /// sets the random number seed
   virtual void setRandomSeed
      (
      EcU32 seed
      );

   /// gets the number of random samples
   virtual EcU32 numRandomSamples
      (
      ) const;

   /// sets the number of random samples
   virtual void setNumRandomSamples
      (
      EcU32 numSamples
      );

   /// get a random array, with a Gaussian distribution
   virtual void getGaussianRandomArray
      (
      EcReArray& randomArray,
      EcU32 arrayWidth,
      EcU32 arrayHeight,
      EcBaseScalarFunction& autoCovariance,
      EcReal arrayUnitDiameter=1.0,
      EcReal mean=0.0
      ) const;

protected:
   /// the number of passes through the sequence
   EcU32                             m_NumRandomSamples;

   /// the random number generator used by this class
   EcRandom                          m_RandomNumberGenerator;
};

#endif // EcRandomTensorTool_H_
