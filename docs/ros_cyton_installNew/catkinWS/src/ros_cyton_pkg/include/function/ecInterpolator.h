#ifndef ecInterpolator_H_
#define ecInterpolator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecInterpolator.h
/// @class EcInterpolator
//
//------------------------------------------------------------------------------
#include <foundCore/ecTypes.h>
#include "ecVectorSearch.h"

/// Linear Interpolator Class
/**
   This template class is useful for performing linear interpolation on data
   sets.

   The independent data is manipulated through the EcVectorSearch class.
*/
template<class TYPE>
class EcInterpolator
{
public:
   /// Default constructor
   EcInterpolator
      (
      );

   /// Destructor
   virtual ~EcInterpolator
      (
      );

   /// Copy constructor
   EcInterpolator
      (
      const EcInterpolator& orig
      );

   /// Assignment operator
   EcInterpolator& operator=
      (
      const EcInterpolator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcInterpolator& orig
      ) const;

   /// Clone -- virtual constructor of EcInterpolator
   virtual EcInterpolator* clone
      (
      );

   /// Initialization method
   /**
       \param inputData  Pointer to dependent variable vector
       \param vIndependentVar  Vector containing independent array information
   */
   virtual void init
      (
      const EcRealVectorVector& inputData,
      const std::vector< EcVectorSearch<TYPE> > & vIndependentVar
      );

   /// Initialization method
   /**
       Used with addDimension and addInterpolator to fully initialize object
   */
   virtual void init
      (
      );

   /// Add dimension to interpolator
   /**
       Used with "init()"
       \param independentVar  Object containing independent array information
   */
   virtual void addDimension
      (
      const EcVectorSearch<TYPE> & independentVar
      );

   /// Add interpolator
   /**
       Used with "init()"
       \param vInputData  Vector containing dependent data
   */
   virtual void addInterpolator
      (
      const EcRealVector& vInputData
      );

   /// Performs linear interpolation
   /**
       Indices and weights were previously found by EcVectorSearch
       \retval Result of interpolation
   */
   virtual const std::vector<TYPE>& evaluate
      (
      ) const;

   /// Performs independent variable search and linear interpolation
   /**
       \param inputValue Independent variable
       \retval Result of interpolation
   */
   virtual const std::vector<TYPE>& evaluate
      (
      TYPE inputValue,
      ...
      ) const;

   /// Performs independent variable search and linear interpolation
   /**
       \param vInputValue Independent variable in vector form
       \retval Result of interpolation
   */
   virtual const std::vector<TYPE>& evaluate
      (
      const std::vector<TYPE>& vInputValue
      ) const;

   /// Initialize bounds of independent data
   /**
       \retval Vector of min/max dimension bounds
   */
   virtual const EcRealVectorVector& initBounds
      (
      );

   /// Initialize boundary methods for independent data
   /**
       Initialization method used to evaluate requests of out of bounds data
       \retval Vector of min/max boundary methods
   */
   virtual const EcBooleanVectorVector& initLimitOrExtrapolate
      (
      );

   /// Null Object -- virtual constructor of EcInterpolator (uninitialized)
   static EcInterpolator nullObject
      (
      );

protected:

   EcU32 m_NumOfDims;            ///< Number of dimensions for interpolator

   EcRealVectorVector m_Data;            ///< Vector containing interpolation data

   EcU32 m_NumOfInterps;         ///< Number of interpolators

   /// Vector of vectors of independent data
   std::vector< EcVectorSearch<TYPE> > m_vIndependentVar;

   /// Map from multidimensional array to 1-dimensional array
   EcU32Vector m_vCombinedSize;

   /// Vector containing combined indices that bound independent look up value
   mutable EcU32Vector m_vCombinedIndex;

   /// Vector containing combined weights that bound independent look up value
   mutable std::vector<TYPE> m_vCombinedWeight;

   mutable EcRealVector m_vResult;   ///< Evaluation output

   /// boundary data
   EcRealVectorVector m_Bounds;

   /// interpolation limits 0=limit, 1=extrapolate
   EcBooleanVectorVector m_LimitOrExtrapolate;
};

#endif // ecInterpolator_H_
