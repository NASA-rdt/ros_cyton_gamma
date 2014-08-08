//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecVectorSearch.ipp
//
//------------------------------------------------------------------------------
#include "ecVectorSearch.h"

#include <foundCore/ecMacros.h>

/////////////////////////////////////////////////////////////////////////
// Functions:    Big four and other header functions
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// Default Constructor
template<class TYPE>
EcVectorSearch<TYPE>::EcVectorSearch
   (
   ):
m_vData(),
m_MaxSearchIndex(0),
m_DataDirection(INCREASING),
m_LowerBoundaryOption(LIMIT),
m_UpperBoundaryOption(LIMIT),
m_SearchOption(LINEAR),
m_IndexSpacing(0)
{
  m_Index[0]  = 0;
  m_Index[1]  = 0;
  m_Weight[0] = 0;
  m_Weight[1] = 0;
}

// Destructor
template<class TYPE>
EcVectorSearch<TYPE>::~EcVectorSearch
   (
   )
{
}

// Copy constructor
template<class TYPE>
EcVectorSearch<TYPE>::EcVectorSearch
   (
   const EcVectorSearch& orig
   ):
m_vData(orig.m_vData),
m_MaxSearchIndex(orig.m_MaxSearchIndex),
m_DataDirection(orig.m_DataDirection),
m_LowerBoundaryOption(orig.m_LowerBoundaryOption),
m_UpperBoundaryOption(orig.m_UpperBoundaryOption),
m_SearchOption(orig.m_SearchOption),
m_IndexSpacing(orig.m_IndexSpacing)
{
  m_Index[0]  = orig.m_Index[0];
  m_Index[1]  = orig.m_Index[1];
  m_Weight[0] = orig.m_Weight[0];
  m_Weight[1] = orig.m_Weight[1];
}

// Assignment operator
template<class TYPE>
EcVectorSearch<TYPE>& EcVectorSearch<TYPE>::operator=
   (
   const EcVectorSearch& orig
   )
{
   if( this != &orig )
   {
      m_vData = orig.m_vData;
      m_Index[0] = orig.m_Index[0];
      m_Index[1] = orig.m_Index[1];
      m_MaxSearchIndex = orig.m_MaxSearchIndex;
      m_Weight[0] = orig.m_Weight[0];
      m_Weight[1] = orig.m_Weight[1];
      m_DataDirection = orig.m_DataDirection;
      m_LowerBoundaryOption = orig.m_LowerBoundaryOption;
      m_UpperBoundaryOption = orig.m_UpperBoundaryOption;
      m_SearchOption = orig.m_SearchOption;
      m_IndexSpacing = orig.m_IndexSpacing;
   }

   return *this;
}

// Equality operator
template<class TYPE>
EcBoolean EcVectorSearch<TYPE>::operator==
   (
      const EcVectorSearch& orig
   ) const
{
   EcBoolean retVal=EcTrue;

   // test equality of object contents
   // Note: don't care if m_Index and m_Weight are the same

   if( !(m_vData == orig.m_vData) )
   {
      retVal = EcFalse;
   }

   if( !(m_MaxSearchIndex == orig.m_MaxSearchIndex) )
   {
      retVal = EcFalse;
   }

   if( !(m_DataDirection == orig.m_DataDirection) )
   {
      retVal = EcFalse;
   }

   if( !(m_LowerBoundaryOption == orig.m_LowerBoundaryOption) )
   {
      retVal = EcFalse;
   }

   if( !(m_UpperBoundaryOption == orig.m_UpperBoundaryOption) )
   {
      retVal = EcFalse;
   }

   if( !(m_SearchOption == orig.m_SearchOption) )
   {
      retVal = EcFalse;
   }

   if( !(m_IndexSpacing == orig.m_IndexSpacing) )
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
EcVectorSearch<TYPE>* EcVectorSearch<TYPE>::clone
   (
   )
{
   return new EcVectorSearch(*this);
}

/////////////////////////////////////////////////////////////////////////
// Function:     init()
// Description:  Initialization Method
// I/O:          Input independent data, boundary, and search options
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcVectorSearch<TYPE>::init
   (
   const std::vector<TYPE>& vInputData,
   BOUNDARY_OPTION inputLowerBoundary,
   BOUNDARY_OPTION inputUpperBoundary,
   SEARCH_OPTION inputSearch
   )
{
   m_vData         = vInputData;
   m_LowerBoundaryOption = inputLowerBoundary;
   m_UpperBoundaryOption = inputUpperBoundary;
   m_SearchOption   = inputSearch;

   // Initialize to some unrealistic value
   // This promotes first lookup by method of BISECTION
   m_Index[0]       = -1;

   m_MaxSearchIndex = EcU32(m_vData.size())-2;

   // Test for strictly increasing or decreasing array
   if( m_vData[1] > m_vData[0] )
   {
      m_DataDirection = INCREASING;
   }
   else
   {
      m_DataDirection = DECREASING;
   }

   // Find breakpoint spacing.  Only useful for EQUAL_SPACED search option.
   m_IndexSpacing = m_vData[1] - m_vData[0];
}

/////////////////////////////////////////////////////////////////////////
// Function:     lookUp()
// Description:  Look up indices and weights
// I/O:          Input state
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcVectorSearch<TYPE>::lookUp
   (
   TYPE inputValue
   ) const
{

   TYPE lookUpValue = m_DataDirection*inputValue;
   EcBoolean limitsExceeded = false;

   if( lookUpValue <= m_DataDirection*m_vData[0])
   {
      // Test for value less than lower bound
      m_Index[0]  = 0;
      m_Index[1]  = 1;

      if( m_LowerBoundaryOption == LIMIT )
      {
         m_Weight[0] = TYPE(1);
         m_Weight[1] = TYPE(0);
         return;
      }

      limitsExceeded = true;
   }
   else if(lookUpValue >= m_DataDirection*m_vData[m_vData.size()-1])
   {
      // Test for value greater than upper bound
      m_Index[0]  = m_MaxSearchIndex;
      m_Index[1]  = m_MaxSearchIndex+1;

      if( m_UpperBoundaryOption == LIMIT )
      {
         m_Weight[0] = TYPE(0);
         m_Weight[1] = TYPE(1);
         return;
      }

      limitsExceeded = true;
   }

   // If limits exceeded, no need to search
   if( limitsExceeded == false )
   {
      // Select search technique
      switch(m_SearchOption)
      {
         case LINEAR:
         {
            // If starting index is out of bounds, jump to BISECTION method
            if( ( m_Index[0] > 0 ) &&
                ( m_Index[0] < static_cast<EcInt32>(m_MaxSearchIndex) ) )
            {
               // Search down first
               while( ( lookUpValue < m_DataDirection*m_vData[m_Index[0]] ) &&
                      ( m_Index[0] > 0 )
                  )
               {
                  --m_Index[0];
               }
               // Then search up
               while( ( lookUpValue > m_DataDirection*m_vData[m_Index[0]]+1 ) &&
                      ( m_Index[0] < static_cast<EcInt32>(m_MaxSearchIndex) ) )
               {
                  ++m_Index[0];
               }
               break;
            }
            // NO BREAK if initial index is out of bounds.
            // Use bisection method instead.
         }
         case BISECTION:
         {
            EcU32 middleIndex, deltaIndex;

            EcU32 highIndex = m_MaxSearchIndex+1;
            m_Index[0] = 0;

            // Perform method of bisection
            while( ( deltaIndex = (highIndex - m_Index[0]) ) > 1 )
            {
               // deltaIndex>>1 is faster than deltaIndex/2
               middleIndex = (deltaIndex>>1) + m_Index[0];
               if( lookUpValue < m_DataDirection*m_vData[middleIndex] )
               {
                  highIndex = middleIndex;
               }
               else
               {
                  m_Index[0] = middleIndex;
               }
            }
            break;
         }
         case EQUAL_SPACED:
         {
            // Perform equal spaced method (fast)
            m_Index[0] = EcU32((inputValue - m_vData[0])/m_IndexSpacing);
            break;
         }
         default:
         {
            EcWARN("EcVectorSearch Error -- Search option not defined:  %d",m_SearchOption);
         }
      }
   }

   // Set upper bound index
   m_Index[1] = m_Index[0] + 1;

   // Calculate weights
   // Note that this calculate is also good for extrapolation
   m_Weight[1] =
      (inputValue - m_vData[m_Index[0]])
      / (m_vData[m_Index[1]] - m_vData[m_Index[0]]);
   m_Weight[0] = TYPE(1) - m_Weight[1];

}

/////////////////////////////////////////////////////////////////////////
// Function:     getSize()
// Description:  Get array size
// I/O:          Return search vector size
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
EcU32 EcVectorSearch<TYPE>::size
   (
   ) const
{
   return EcU32(m_vData.size());
}

/////////////////////////////////////////////////////////////////////////
// Function:     getIndex()
// Description:  Get indices
// I/O:          Return indices
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcVectorSearch<TYPE>::getIndex
   (
   EcU32& indexLower,
   EcU32& indexUpper
   ) const
{
   indexLower = m_Index[0];
   indexUpper = m_Index[1];
}

/////////////////////////////////////////////////////////////////////////
// Function:     getWeight()
// Description:  Get weights
// I/O:          Return weight
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcVectorSearch<TYPE>::getWeight
   (
   TYPE& weightLower,
   TYPE& weightUpper
   ) const
{
   weightLower = m_Weight[0];
   weightUpper = m_Weight[1];
}

/////////////////////////////////////////////////////////////////////////
// Function:     bounds
// Description:  Get the bounds of independent data
// I/O:          Return boundary data
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcVectorSearch<TYPE>::getBounds
   (
   EcReal& low,
   EcReal& high
   ) const
{
   EcReal temp = m_vData[0];
   high = m_vData[m_vData.size()-1];
   if(high < temp)
   {
      low = high;
      high = temp;
   }
   else
   {
      low = temp;
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     limitOrExtrapolate
// Description:  Get method used to evaluate requests of out of bounds data
// I/O:          Return boundary option (limit or extrap)
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
void EcVectorSearch<TYPE>::getLimitOrExtrapolate
   (
   EcBoolean& low,
   EcBoolean& high
   ) const
{
   EcBoolean temp;
   if(m_LowerBoundaryOption == LIMIT)
   {
      temp = 0;
   }
   else
   {
      temp = 1;
   }

   if(m_UpperBoundaryOption == LIMIT)
   {
      high = 0;
   }
   else
   {
      high = 1;
   }

   if(m_DataDirection == DECREASING)
   {
      low = high;
      high = temp;
   }
   else
   {
      low = temp;
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     nullObject
// Description:  Return empty object
// I/O:          Return empty independent table function vector
/////////////////////////////////////////////////////////////////////////
template<class TYPE>
EcVectorSearch<TYPE> EcVectorSearch<TYPE>::nullObject
   (
   )
{
   return EcVectorSearch();
}
