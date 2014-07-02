#ifndef ecRandom_H_
#define ecRandom_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRandom.h
/// @class EcRandom
/// @brief A utility class to generate random numbers.
/// @details Each random number generator is thread-specific, i.e. the sequence
///          of the generated random numbers is unique for each thread.
/// @todo Remove randomUnitVectors() and randomOrientations()
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecMacros.h"
#include "ecMath.h"
#include "ecOrientation.h"
#include "ecVector.h"

#include <boost/random.hpp>
#include <boost/thread/tss.hpp>

/// typedef the random number generator type to that described in "Mersenne Twister: A 
/// 623-dimensionally equidistributed uniform pseudo-random number generator", Makoto Matsumoto 
/// and Takuji Nishimura, ACM Transactions on Modeling and Computer Simulation: Special Issue 
/// on Uniform Random Number Generation, Vol. 8, No. 1, January 1998, pp. 3-30.
typedef boost::mt19937 EcRandomNumberGeneratorType;

class EC_STABLE_FOUNDCORE_DECL EcRandom
{
public:
   /// get the thread-local random number generator. Must be used with boost::thread, not with other third-library threads, to ensure thread safety
   static EcRandomNumberGeneratorType* randomNumberGenerator
      (
      );

   /// seed the thread-local random number generator.
   static void seed
      (
      EcU32 seedNumber=0
      );

   /// Convenience method to generate a uniformly-distributed random integer numbers between the lowerBound and upperBound, inclusive. Should not be called in a loop since there's overhead. Use uniformIntRandoms instead.
   /**
   \param[in] lowerBound The lower bound (inclusive) of the uniform distribution.
   \param[in] upperBound The upper bound (inclusive) of the uniform distribution.
   \return A random integer number.
   */
   static EcInt32 uniformIntRandom
      (
      EcInt32 lowerBound = 0,
      EcInt32 upperBound = 99
      );

   /// Convenience method to generate a number of uniformly-distributed random integers between the lowerBound and upperBound, inclusive.
   /**
   \param[in] lowerBound The lower bound (inclusive) of the uniform distribution.
   \param[in] upperBound The upper bound (inclusive) of the uniform distribution.
   \param[in] count The number of random integers to be generated.
   \return A vector of size count contain the random numbers.
   */
   static EcInt32Vector uniformIntRandoms
      (
      EcInt32 lowerBound,
      EcInt32 upperBound,
      EcU32 count
      );

   /// Convenience method to generate a uniformly-distributed random real numbers between the lowerBound inclusive and upperBound exclusive. Should not be called in a loop since there's overhead. Use uniformRealRandoms instead.
   /**
   \param[in] lowerBound The lower bound (inclusive) of the uniform distribution.
   \param[in] upperBound The upper bound (inclusive) of the uniform distribution.
   \return A random real number.
   */
   static EcReal uniformRealRandom
      (
      EcReal lowerBound = 0.0,
      EcReal upperBound = 1.0
      );

   /// Convenience method to generate a number of uniformly-distributed random reals between the lowerBound inclusive and upperBound exclusive.
   /**
   \param[in] lowerBound The lower bound (inclusive) of the uniform distribution.
   \param[in] upperBound The upper bound (inclusive) of the uniform distribution.
   \param[in] count The number of random numbers to be generated.
   \return A vector of size count contain the random numbers.
   */
   static EcRealVector uniformRealRandoms
      (
      EcReal lowerBound,
      EcReal upperBound,
      EcU32 count
      );

   /// Convenience method to generate a normally-distributed random numbers with the specified mean and sigma. Should not be called in a loop since there's overhead. Use EcNormalRandoms instead.
   /**
   \param[in] mean The mean of the normal distribution.
   \param[in] sigma The sigma of the normal distribution.
   \return A vector of size count contain the random numbers.
   */
   static EcReal normalRandom
      (
      EcReal mean = 0.0,
      EcReal sigma = 1.0
      );

   /// Convenience method to generate a number of normally-distributed random numbers with the specified mean and sigma.
   /**
   \param[in] mean The mean of the normal distribution.
   \param[in] sigma The sigma of the normal distribution.
   \param[in] count The number of random numbers to be generated.
   \return A vector of size count contain the random numbers.
   */
   static EcRealVector normalRandoms
      (
      EcReal mean,
      EcReal sigma,
      EcU32 count
      );

   /// Convenience method to generate a number of normally-distributed random numbers, each with a different mean and sigma.
   /**
   \param[in] means A vector of mean values.
   \param[in] sigmas A vector of sigma values. If the number of sigmas is less than the number of mean values, then defaultSigma is used as the default sigma for the remaining mean values.
   \param[out] results A vector of normally-distributed random numbers. Each element of this vector uses the corresponding mean and sigma from above.
   \param[in] defaultSigma The default sigma used when the size of sigmas is smaller than the size of means.
   */
   template <class VectorType>
   static void normalRandoms
      (
      const VectorType& means,
      const VectorType& sigmas,
      VectorType& results,
      EcReal defaultSigma=1.0
      )
   {
      EcU32 size=means.size();
      // resize if necessary
      results.resize(size);

      EcU32 loops=EcMath::minimum<EcU32>(size,sigmas.size());
      for(EcU32 ii=0; ii<loops; ++ii)
      {
         results[ii]=EcRandom::normalRandom(means[ii], sigmas[ii]);
      }

      // if we don't have enough one sigmas
      if(loops<size)
      {
         // use 1 as the default value
         for(EcU32 ii=loops; ii<size; ++ii)
         {
            results[ii]=EcRandom::normalRandom(means[ii], defaultSigma);
         }
      }
   }

   /// Convenience method to generate a random orientation.
   static EcOrientation randomOrientation
      (
      );

   /// Convenience method to generate a number of random orientations.
   /**
   \param[in] count The number of random orientations to be generated.
   \return A vector of size count contain the random orientations.
   */
   static std::vector< EcOrientation > randomOrientations
      (
      EcU32 count
      );

   /// Convenience method to generate a random 3D unit vector, i.e. a unit vector that points in a random direction in 3D space.
   static EcVector randomUnitVector
      (
      );

   /// Convenience method to generate a number of random 3D unit vectors.
   /**
   \param[in] count The number of random unit vectors to be generated.
   \return A vector of size count contain the random unit vectors.
   */
   static std::vector< EcVector > randomUnitVectors
      (
      EcU32 count
      );

protected:
   /// the underlying thread-local random number generator
   /// i.e. there's one per thread
   static boost::thread_specific_ptr<EcRandomNumberGeneratorType>  m_theRandomNumberGenerator;
};

#endif // ecRandom_H_
