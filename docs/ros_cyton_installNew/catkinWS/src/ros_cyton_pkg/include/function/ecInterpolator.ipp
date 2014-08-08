//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecInterpolator.ipp
//
//------------------------------------------------------------------------------
#include "ecInterpolator.h"

#include <stdarg.h>

#include <foundCore/ecConstants.h>

/////////////////////////////////////////////////////////////////////////
// Functions:    Big four and other header functions
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// Default constructor
template<class TYPE>
EcInterpolator<TYPE>::EcInterpolator
   (
   ):
m_NumOfDims(0),
m_Data(),
m_NumOfInterps(0),
m_vIndependentVar(),
m_vCombinedSize(),
m_vCombinedIndex(),
m_vCombinedWeight(),
m_vResult(),
m_Bounds(),
m_LimitOrExtrapolate()
{
}

// Destructor
template<class TYPE>
EcInterpolator<TYPE>::~EcInterpolator
   (
   )
{
}

// Copy constructor
template<class TYPE>
EcInterpolator<TYPE>::EcInterpolator
   (
   const EcInterpolator& orig
   ):
m_NumOfDims(orig.m_NumOfDims),
m_Data(orig.m_Data),
m_NumOfInterps(orig.m_NumOfInterps),
m_vIndependentVar(orig.m_vIndependentVar),
m_vCombinedSize(orig.m_vCombinedSize),
m_vCombinedIndex(orig.m_vCombinedIndex),
m_vCombinedWeight(orig.m_vCombinedWeight),
m_vResult(orig.m_vResult),
m_Bounds(orig.m_Bounds),
m_LimitOrExtrapolate(orig.m_LimitOrExtrapolate)
{
}

// Assignment operator
template<class TYPE>
EcInterpolator<TYPE>& EcInterpolator<TYPE>::operator=
   (
   const EcInterpolator& orig
   )
{
   if( this != &orig )
   {
      m_NumOfDims = orig.m_NumOfDims;
      m_Data = orig.m_Data;
      m_NumOfInterps = orig.m_NumOfInterps;
      m_vIndependentVar = orig.m_vIndependentVar;
      m_vCombinedSize = orig.m_vCombinedSize;
      m_vCombinedIndex = orig.m_vCombinedIndex;
      m_vCombinedWeight = orig.m_vCombinedWeight;
      m_vResult = orig.m_vResult;
      m_Bounds = orig.m_Bounds;
      m_LimitOrExtrapolate = orig.m_LimitOrExtrapolate;
   }

   return *this;
}

// Equality operator
template<class TYPE>
EcBoolean EcInterpolator<TYPE>::operator==
   (
   const EcInterpolator& orig
   ) const
{
   EcBoolean retVal=EcTrue;

   // test equality of object contents
   // Note: don't care if m_vCombinedIndex and m_vCombinedWeight are the same

   if( !(m_NumOfDims == orig.m_NumOfDims) )
   {
      retVal = EcFalse;
   }

   if( !(m_Data == orig.m_Data) )
   {
      retVal = EcFalse;
   }

   if( !(m_NumOfInterps == orig.m_NumOfInterps) )
   {
      retVal = EcFalse;
   }

   if( !(m_vIndependentVar == orig.m_vIndependentVar) )
   {
      retVal = EcFalse;
   }

   if( !(m_vCombinedSize == orig.m_vCombinedSize) )
   {
      retVal = EcFalse;
   }

   if( !(m_vResult == orig.m_vResult) )
   {
      retVal = EcFalse;
   }

   if( !(m_Bounds == orig.m_Bounds) )
   {
      retVal = EcFalse;
   }

   if( !(m_LimitOrExtrapolate == orig.m_LimitOrExtrapolate) )
   {
      retVal = EcFalse;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
//End of function block :
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     clone
// Description:  A virtual constructor that returns an EcXmlObject.
// I/O:          Return XML object
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
EcInterpolator<TYPE>* EcInterpolator<TYPE>::clone
   (
   )
{
   return new EcInterpolator(*this);
}

/////////////////////////////////////////////////////////////////////////
// Function:     init()
// Description:  Initialization method
// I/O:          Inputs are:
//               dependent data array and
//               list of independent data arrays
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcInterpolator<TYPE>::init
   (
   const EcRealVectorVector& inputData,
   const std::vector< EcVectorSearch<TYPE> > & vIndependentVar
   )
{
   init();

   m_NumOfDims = EcU32(vIndependentVar.size());
   m_vCombinedIndex.resize(1<<m_NumOfDims);
   m_vCombinedWeight.resize(1<<m_NumOfDims);

   for(size_t ii=0,size=inputData.size(); ii<size; ++ii)
   {
     addInterpolator(inputData[ii]);
   }

   m_vIndependentVar = vIndependentVar;

   // test vector sizes
   size_t compareSize = m_vIndependentVar[0].size();
   for(size_t jj=1; jj<m_NumOfDims; ++jj)
   {
      compareSize *= m_vIndependentVar[jj].size();

      m_vCombinedSize.push_back(
         m_vIndependentVar[jj-1].size() * m_vCombinedSize[jj-1]);
   }

   // Test for data size being equivalent to the multiplication of independent
   // array sizes
   if( m_Data[0].size() != compareSize )
   {
      EcERROR
         ("EcInterpolator Error:\n   Vector size, %d, not compatible with independent variable sizes, %d\n",m_Data[0].size(),compareSize);
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     init()
// Description:  Initialization method
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcInterpolator<TYPE>::init
   (
   )
{
   m_Data.clear();
   m_vIndependentVar.clear();
   m_vCombinedSize.clear();
   m_vCombinedIndex.clear();
   m_vCombinedWeight.clear();

   m_vCombinedSize.push_back(1);
   m_NumOfDims = 0;
   m_NumOfInterps = 0;
}

/////////////////////////////////////////////////////////////////////////
// Function:     addDimension()
// Description:  Initialization method
// I/O:          Inputs are:
//               independent data vector
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcInterpolator<TYPE>::addDimension
   (
   const EcVectorSearch<TYPE> & independentVar
   )
{
   ++m_NumOfDims;
   m_vIndependentVar.push_back(independentVar);
   if(m_NumOfDims > 1) {
      m_vCombinedSize.push_back(
         m_vIndependentVar[m_NumOfDims-2].size()
         * m_vCombinedSize[m_NumOfDims-2]);
   }

   m_vCombinedIndex.resize(1<<m_NumOfDims);
   m_vCombinedWeight.resize(1<<m_NumOfDims);
}

/////////////////////////////////////////////////////////////////////////
// Function:     addInterpolator()
// Description:  Initialization method
// I/O:          Inputs are:
//               dependent data vector
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcInterpolator<TYPE>::addInterpolator
   (
   const EcRealVector& vInputData
   )
{
   ++m_NumOfInterps;
   m_Data.push_back(vInputData);
}

/////////////////////////////////////////////////////////////////////////
// Function:     evaluate()
// Description:  Primary evaluation method
// I/O:          Output is result of interpolation
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
const std::vector<TYPE>& EcInterpolator<TYPE>::evaluate
   (
   ) const
{
   EcU32 index[2];
   TYPE weight[2];

   // Initialize evaluation
   m_vCombinedIndex[0]  = 0;
   m_vCombinedWeight[0] = TYPE(1);

   // Loop through n-dimensions
   for(EcU32  ii=0; ii<m_NumOfDims; ++ii )
   {
      // Get independent variable indices and weights
      m_vIndependentVar[ii].getIndex(index[0], index[1]);
      m_vIndependentVar[ii].getWeight(weight[0], weight[1]);

      // Map to 1-dimensional space
      index[0]*=m_vCombinedSize[ii];
      index[1]*=m_vCombinedSize[ii];

      // Loop through binary tree for current dimension
      for(EcU32 jj=2<<ii; jj--; )
      {
         // jj&1 is fast method for getting a 1 or 0 (1 for odd and 0 for even)
         // jj>>1 is faster than jj/2

         // Compute index map for bounding indices
         m_vCombinedIndex[jj]  = index[jj&1]  + m_vCombinedIndex[jj>>1];

         // Compute the combined weights for the bounding indices
         m_vCombinedWeight[jj] = weight[jj&1] * m_vCombinedWeight[jj>>1];
      }
   }

   m_vResult.clear();
   m_vResult.resize(m_NumOfInterps,0);

   for(EcU32 jj = 0; jj<m_NumOfInterps; ++jj)
   {
      // Sum the weighted bounding break points
      const EcU32 size = 1<<m_NumOfDims;
      for(EcU32 ii = 0; ii<size; ++ii )
      {
         m_vResult[jj] += m_vCombinedWeight[ii] * m_Data[jj][m_vCombinedIndex[ii]];
      }
   }

   return m_vResult;
}

/////////////////////////////////////////////////////////////////////////
// Function:     evaluate()
// Description:  Evaluation method (perform independent array look-ups)
// I/O:          Inputs are the independent data
//               Output is result of interpolation
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
const std::vector<TYPE>& EcInterpolator<TYPE>::evaluate
   (
   TYPE inputValue,
   ...
   ) const
{
   va_list valueList;
   va_start(valueList, inputValue);

   // Perform look up for first dimension
   m_vIndependentVar[0].lookUp(inputValue);

   // Perform independent array look-ups (2-N Dimensions)
   for( EcU32 ii=1; ii<m_NumOfDims; ++ii )
   {
      // Note: va_arg only takes "double" regardless of whether
      // inputValue is double or float
      m_vIndependentVar[ii].lookUp( TYPE(va_arg(valueList, EcReal)));
   }

   va_end(valueList);

   // Perform interpolation
   return evaluate();
}

/////////////////////////////////////////////////////////////////////////
// Function:     evaluate()
// Description:  Evaluation method (perform independent array look-ups)
// I/O:          Input is independent data
//               Output is result of interpolation
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
const std::vector<TYPE>& EcInterpolator<TYPE>::evaluate
   (
   const std::vector<TYPE>& vInputValue
   ) const
{
   // Perform look up for first dimension
   m_vIndependentVar[0].lookUp(vInputValue[0]);

   // Perform independent array look-ups (2-N Dimensions)
   for( EcU32 ii=1; ii<m_NumOfDims; ++ii )
   {
      // Note: va_arg only takes "double" regardless of whether
      // vInputValue is double or float
      m_vIndependentVar[ii].lookUp( vInputValue[ii] );
   }

   // Perform interpolation
   return evaluate();
}

/////////////////////////////////////////////////////////////////////////
// Function:     initBounds
// Description:  Initialize the bounds of independent data
// I/O:          Output boundary data
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
const EcRealVectorVector& EcInterpolator<TYPE>::initBounds
   (
   )
{
   const size_t size = m_vIndependentVar.size();
   m_Bounds.resize(size);

   for(size_t ii=0; ii<size; ++ii)
   {
      m_Bounds[ii].resize(2);
      m_vIndependentVar[ii].getBounds(m_Bounds[ii][0],m_Bounds[ii][1]);
   }

   return m_Bounds;
}

/////////////////////////////////////////////////////////////////////////
// Function:     initLimitOrExtrapolate
// Description:  Initialization method used to evaluate requests of out of bounds data
// I/O:          Output boundary test result (limit or extrap)
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
const EcBooleanVectorVector& EcInterpolator<TYPE>::initLimitOrExtrapolate
   (
   )
{
   const size_t size = m_vIndependentVar.size();
   m_LimitOrExtrapolate.resize(size);

   EcBoolean high, low;
   for(size_t ii=0; ii<size; ++ii)
   {
      m_LimitOrExtrapolate[ii].resize(2);
      m_vIndependentVar[ii].getLimitOrExtrapolate(low, high);
      m_LimitOrExtrapolate[ii][0] = low;
      m_LimitOrExtrapolate[ii][1] = high;
   }

   return m_LimitOrExtrapolate;
}


/////////////////////////////////////////////////////////////////////////
// Function:     nullObject
// Description:  Creates an empty object.
// I/O:          Returns empty object
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
EcInterpolator<TYPE> EcInterpolator<TYPE>::nullObject
   (
   )
{
   return EcInterpolator();
}
