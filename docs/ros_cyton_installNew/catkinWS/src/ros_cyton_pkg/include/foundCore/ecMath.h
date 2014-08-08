#ifndef ecMath_H_
#define ecMath_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecMath.h
/// @class EcMath
/// @brief Contains a variety of general math functions
/// @todo Move implementation of the long sorting/calculating routines to the cpp
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecMacros.h"
#include <list>

/// Contains general math functions

class EC_STABLE_FOUNDCORE_DECL EcMath
{
public:
   enum {FACTORIALTABLESIZE=50};

   /// calculate median of an array of data specified by a pointer and length
   /**
   \param[in] ptr A pointer to the first entry in the array of data.
   \param[in] length The length of the array of data.
   */
   template <class Type>
   static Type median
      (
      const Type* ptr,
      const int length
      )
   {
      std::list<Type> lst(length);
      typename std::list<Type>::iterator itr = lst.begin();

      // load the pointer to a list
      for( EcU32 ii = 0; ii<length; ++itr, ++ii )
      {
         *itr = ptr[ii];
      }

      // run the list median
      return median(lst);
   }

   /// calculate median of a vector
   /**
   \param[in] vecT The input data in the form of a standard vector.
   */
   template <class Type>
   static inline Type median
      (
      const std::vector<Type>& vecT
      )
   {
      EcU32 length = vecT.size();
      std::list<Type> lst(length);
      typename std::list<Type>::iterator itr = lst.begin();

      // load the vector to a list
      for( EcU32 ii = 0; ii<length; ++itr, ++ii )
      {
         *itr = vecT[ii];
      }

      // run the list median
      return median(lst);
   }

   /// calculate median of a list
   /**
   \param[in] lst The input data in the form of a standard list.
   */
   template <class Type>
   static inline Type median
      (
      const std::list<Type>& lst
      )
   {
      const EcU32 size = lst.size();
      if (size == 1)
      {
         return *lst.begin();
      }

      // sort
      typename std::list<Type> list2(lst);
      list2.sort();

      // median
      const EcU32 mdi = (size / 2);

      typename std::list<Type>::iterator itr = list2.begin();
      for( EcU32 ii=0; ii<mdi; ++ii, ++itr )
      {
      }

      Type med = *itr;

      if((size % 2) == 0) // take average
      {
         --itr;
         med += *itr;
         med /= 2.0;
      }

      return med;
   }

   /// standard deviation of a length n vector, normalized by (n-1)
   /**
   \param[in] vec The input data in the form of a standard vector.
   */
   template <class Type>
   static inline Type stdDev
      (
      const std::vector<Type>& vec // vector of data type
      )
   {
      EcU32 size = vec.size();
      if(size<=1)
      {
         return 0;
      }

      EcReal sqSum = 0.0;

      EcReal mn = mean(vec);

      for( EcU32 ii=0; ii<size; ++ii )
      {
         Type ubVc = vec[ii]-mn;
         sqSum += ubVc*ubVc;
      }

      return sqrt((sqSum)/(size-1.0));
   }

   /// calculate sum of a length n vector
   /**
   \param[in] vec The input data in the form of a standard vector.
   */
   template <class Type>
   static inline Type sum
      (
      const std::vector<Type>& vec // vector of data type
      )
   {
      Type sm = 0.0;

      EcU32 size = vec.size();
      for( EcU32 ii=0; ii< size; ++ii )
      {
         sm += vec[ii];
      }

      return sm;
   }

   /// calculate mean of a length n 
   /**
   \param[in] vec The input data in the form of a standard vector.
   */
   template <class Type>
   static inline Type mean
      (
      const std::vector<Type>& vec // vector of data type
      )
   {
      EcU32 size = vec.size();
      if( size==0 )
      {
         return 0;
      }

      Type sm = 0.0;
      for( EcU32 ii=0; ii< size; ++ii )
      {
         sm += vec[ii];
      }

      return sm/size;
   }

   /// calculate 2norm of a length n vector
   /**
   \param[in] vec The input data in the form of a standard vector.
   */
   template <class Type>
   static inline Type norm
      (
      const std::vector<Type>& vec // vector of data type
      )
   {
      EcU32 size = vec.size();
      if( size==0 )
      {
         return 0;
      }

      Type sm = 0.0;
      for( EcU32 ii=0; ii< size; ++ii )
      {
         sm += vec[ii]*vec[ii];
      }

      return EcMath::sqrt(sm);
   }

   /// finds the maximum between two values (the values must have > defined)
   /**
   \param[in] x The first of the two values.
   \param[in] y The first of the two values.
   */
   template <class Type>
   static inline const Type& maximum
      (
      const Type& x,
      const Type& y
      )
   {
      return x > y ? x : y;
   }

   /// finds the minimum between two values (the values must have > defined)
   /**
   \param[in] x The first of the two values.
   \param[in] y The first of the two values.
   */
   template<class Type>
   static inline const Type& minimum
      (
      const Type& x,
      const Type& y
      )
   {
      return x < y ? x : y;
   }

   ///  calculate maximum of a length n vector
   /**
   \param[in] vec The input data in the form of a standard vector.
   */
   template <class Type>
   static inline Type maximum
      (
      const std::vector<Type>& vec // vector of data type
      )
   {
      EcU32 size = vec.size();
      if( size==0 )
      {
         return 0;
      }

      //return *max_element(vec.begin(), vec.end());

      Type mx = vec[0];

      for( EcU32 ii=1; ii< size; ++ii )
      {
         mx = maximum(mx,vec[ii]);
      }

      return mx;
   }

   /// calculate minimum of a length n vector
   /**
   \param[in] vec The input data in the form of a standard vector.
   */
   template <class Type>
   static inline Type minimum
      (
      const std::vector<Type>& vec // vector of data type
      )
   {
      EcU32 size = vec.size();
      if( size==0 )
      {
         return 0;
      }

      //return *min_element(vec.begin(), vec.end());

      Type mn = vec[0];

      for( EcU32 ii=1; ii< size; ++ii )
      {
         mn = minimum(mn,vec[ii]);
      }

      return mn;
   }

   /// this sorts, taking input in the form of a list and outputting a vector
   /**
   \param[in] lst The unsorted input data in the form of a standard list.
   \param[out] order The sorted output in the form of a vector
   */
   template <class Type>
   static inline void sort
      (
      std::list<Type>& lst,
      EcU32Vector& order
      )
   {
      EcU32 size = lst.size();
      EcU32 size2 = order.size();
      if(size2!=size)
      {
         order.resize(size);
      }
      std::list<Type> original = lst;
      EcInt32Vector used(size);

      // sort list first
      lst.sort();

      EcU32 ii,jj;

      // init used to -1
      for(ii=0;ii<size;++ii)
      {
         used[ii]=-1;
      }

      // find order
      // go through new list
      typename std::list<Type>::iterator itr1, itr2;
      for(ii=0, itr1 = lst.begin(); ii<size; ++itr1,++ii )
      {
         // origional order
         for(jj=0,itr2 = original.begin(); jj<size; ++itr2,++jj )
         {
            if(*itr1==*itr2 && used[jj]==-1)
            {
               order[ii] = jj;
               used[jj] = 1;
               break;
            }
         }
      }
   }

   /// return the square of a value.
   template<class Type>
   static inline const Type square
      (
      Type x
      )
   {
     return x * x;
   }

   /// return the cube of a value.
   template<class Type>
   static inline const Type cube
      (
      Type x
      )
   {
     return x * x * x;
   }

   /// checks to see if two values (x and y) are within a tolerance (e) of each other
   /**
   \param[in] x The first of two values to compare.
   \param[in] y The second of two values to compare.
   \param[in] e The tolerance used to compare the two values.
   */
   template <class Type>
   static inline EcBoolean approxEq
      (
      const Type& x,
      const Type& y,
      const Type& e
      )
   {
      return (x>y) ?
         ( (x>y+e)? EcFalse: EcTrue ):
         ( (y>x+e)? EcFalse: EcTrue );
   }

   /// finds the sign.  Returns -1,0,1 for negative, zero, or positive arguments
   template <class Type>
   static inline EcInt16 sign
      (
      Type x
      )
   {
      return (x>0) ? 1 : ((x==0) ? 0 : -1);
   }

   /// swaps two integer values 
   template<class Type>
   static inline void swapInt
      (
      Type& x,
      Type& y
      )
   {
      // Note no third variable needed.

      x=x^y;
      y=x^y;
      x=x^y;
   }

   /// sorts two numbers in descending order
   /**
   \param[in] x The first of two values to sort.
   \param[in] y The second of two values to sort.
   */
   template <class Type>
   static inline void sortDescending
      (
      Type& x,
      Type& y
      )
   {
      if(y>x)
      {
         EcSWAP(x,y);
      }
   }

   /// sorts three numbers in descending order
   /**
   \param[in] x The first of two values to sort.
   \param[in] y The second of two values to sort.
   \param[in] z The third of two values to sort.
   */
   template <class Type>
   static inline void sortDescending
      (
      Type& x,
      Type& y,
      Type& z
      )
   {
      if(y>x)
      {
         EcSWAP(x,y);
      }
      if(z>x)
      {
         EcSWAP(x,z);
      }
      if(z>y)
      {
         EcSWAP(y,z);
      }
   }

   /// sorts four numbers in descending order
   /**
   \param[in] w The first of two values to sort.
   \param[in] x The second of two values to sort.
   \param[in] y The third of two values to sort.
   \param[in] z The fourth of two values to sort.
   */
   template <class Type>
   static inline void sortDescending
      (
      Type& w,
      Type& x,
      Type& y,
      Type& z
      )
   {
      sortDescending(x,y,z);
      if(x>w)
      {
         EcSWAP(x,w);

         if(y>x)
         {
            EcSWAP(y,x);

            if(z>y)
            {
               EcSWAP(z,y);
            }
         }
      }
   }

   /// check for not a number.  Returns true if the number is
   /// a quiet NAN, signaling NAN, positive infinity, or negative
   /// infinity.
   static EcBoolean isNanOrInf
      (
      const EcReal& value
      );

   /// finds a safe square root.  If the number is zero, it returns zero.
   static EcReal sqrt
      (
      EcReal x
      );

   /// finds the cube root.
   static EcReal cubrt
      (
      EcReal x
      );

   /// finds a safe arc cosine.  If the number is >1, it returns 0, <-1, Pi.
   static EcReal acos
      (
      EcReal x
      );

   /// finds a safe arc sine.  If the number is >1, it returns Pi/2, <-1, -Pi/2.
   static EcReal asin
      (
      EcReal x
      );

   /// finds a safe arc tangent.  If both entries are zero, returns zero.
   static EcReal atan2
      (
      EcReal y,
      EcReal x
      );

   /// returns EcTRUE if the EcU32 passed in is ODD
   static EcBoolean isOdd
      (
      EcU32 num
      );

   /// defines a uniform random number between zero and one
   static EcReal unifRand
      (
      );

   /// defines a 0 mean 1 sigma normal random number
   static EcReal normRand
      (
      );

   /// returns a value that equals the argument unless it is zero, in which
   /// case it returns a small postitive number
   static EcReal nonZeroPos
      (
      const EcReal& x
      );

   /// returns a value that equals the argument unless it is zero, in which
   /// case it returns a small negative number
   static EcReal nonZeroNeg
      (
      const EcReal& x
      );

   /// get the roots of a cubic polynomial
   /// x^3 + a x^2 + b x + c = 0.  Returns true if
   /// all three roots are real.
   static EcBoolean cubicRoots
      (
      const EcReal& a,
      const EcReal& b,
      const EcReal& c,
      EcReal& root0Real,
      EcReal& root1Real,
      EcReal& root2Real,
      EcReal& root1Imag,
      EcReal& root2Imag
      );

   /// get the roots of a quartic polynomial
   /// x^4 + a x^3 + b x^2 + c x + d = 0.  Returns the
   /// number of real roots (0-4).  Additional return
   /// values should be ignored.
   static EcU32 quarticRealRoots
      (
      const EcReal& a,
      const EcReal& b,
      const EcReal& c,
      const EcReal& d,
      EcReal& root0Real,
      EcReal& root1Real,
      EcReal& root2Real,
      EcReal& root3Real
      );

   /// computes the factorial of an integer
   static EcReal factorial
      (
      EcU32 num
      );

   /// Smooth a vector by averging neighboring elements.
   static void smooth
      (
      const EcRealVector& srcVec,
      const EcU32&        halfWin,
      EcRealVector&       dstVec
      );

   /// Smooth slop.
   static void smoothSlop
      (
      const EcRealVector& srcVec,
      const EcU32&        halfWin,
      EcRealVector&       dstVec
      );

   /// dump real vector to matlab
   static EcBoolean dump
      (
      const EcRealVector& vec,
      const char* fileName
      );

   /// dump the data into a file for debuging purpose
   static EcBoolean dump
      (
      const EcRealVectorVector& array,
      const char* fileName
      );

   /// Find the zero crossing in the range of the input vector
   /// from the specified sign to the opposite sign
   static EcReal zeroCrossing
      (
      const EcRealVector& srcVec,
      const EcU32&        lo,
      const EcU32&        hi,
      const EcInt32&      sgn
      );

   /// a table built statically to store the values for the first
   /// FACTORIALTABLESIZE factorial values. This allows instant return
   /// for most inputs and fast calculation by building on the last
   /// value for larger inputs.
   static const EcReal m_theFactorialTable[FACTORIALTABLESIZE];
};

#endif // ecMath_H_
