#ifndef ecVectorSearch_H_
#define ecVectorSearch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecVectorSearch.h
/// @class EcVectorSearchEnums
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

/// Enumeration class to support EcVectorSearch
/**
   Enumerations are useful for providing the user with a friendly technique
   for configuring an object.  The problem is that enumerations in templates
   cannot be used outside the template (even if public).  This is a issue
   unique to templates.  To solve this problem, the enumerations available
   to the user are placed in a base class (non-template).
*/
class EC_FOUNDATION_FUNCTION_DECL EcVectorSearchEnums
{
public:
   /// Search option for limiting or extrapolating beyond array boundaries
   enum BOUNDARY_OPTION
   {
      LIMIT,                ///< Limit at boundaries (default)
      EXTRAPOLATE           ///< Extrapolate beyond boundaries
   };

   /// Search option for selecting search technique
   enum SEARCH_OPTION
   {
      LINEAR,               ///< Linear search (default)
      BISECTION,            ///< Search using method of bisection
      EQUAL_SPACED          ///< Fast technique if break points are equal spaced
   };
};

/// Independent Variable Search Class
/**
   This template class is useful for finding the indices and weights in an
   independent variable array.

   Data can be either strictly increasing or decreasing.

   Search options are defined in EcVectorSearchEnums.
*/
template<class TYPE>
class EcVectorSearch : public EcVectorSearchEnums
{
public:
   /// Flag for specifying a strictly increasing or decreasing array
   enum ARRAY_DIRECTION
      {
      DECREASING = -1,        ///< Strictly decreasing
      INCREASING =  1         ///< Strictly increasing
      };

   /// Default constructor
   EcVectorSearch
      (
      );

   /// Destructor
   virtual ~EcVectorSearch
      (
      );

   /// Copy constructor
   EcVectorSearch
      (
      const EcVectorSearch& orig
      );

   /// Assignment operator
   EcVectorSearch& operator=
      (
      const EcVectorSearch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVectorSearch& orig
      ) const;

   /// Clone -- virtual constructor
   virtual EcVectorSearch* clone
      (
      );

   /// Initialization method
   /**
       \param vInputData Vector of independent variable data
       \param lowerBoundaryOption Lower boundary search option
       \param upperBoundaryOption Upper boundary search option
       \param searchOption Search technique option
   */
   virtual void init
      (
      const std::vector<TYPE>& vInputData,
      BOUNDARY_OPTION lowerBoundaryOption = LIMIT,
      BOUNDARY_OPTION upperBoundaryOption = LIMIT,
      SEARCH_OPTION searchOption = LINEAR
      );

   /// Search array using input value (mutator)
   /**
       \param input Input search value
   */
   virtual void lookUp
      (
      TYPE input
      ) const;

   /// Get size (accessor)
   /**
      retval Size of array
   */
   virtual EcU32 size
      (
      ) const;

   /// Get indices (accessor)
   /**
       \param indexLower Lower bound index
       \param indexUpper Upper bound index
   */
   virtual void getIndex
      (
      EcU32& indexLower,
      EcU32& indexUpper
      ) const;

   /// Get weights (accessor)
   /**
       \param weightLower Lower bound weight
       \param weightUpper Upper bound weight
   */
   virtual void getWeight
      (
      TYPE& weightLower,
      TYPE& weightUpper
      ) const;

   /// Get bounds of independent data
   /**
       \param low Low boundary value
       \param high High boundary value
   */
   virtual void getBounds
      (
      EcReal& low,
      EcReal& high
      ) const;

   /// Get boundary methods for independent data
   /**
       Get method used to evaluate requests of out of bounds data
       \param low Low boundary value
       \param high High boundary value
   */
   virtual void getLimitOrExtrapolate
      (
      EcBoolean& low,
      EcBoolean& high
      ) const;

   /// Null object -- virtual constructor (uninitialized)
   static EcVectorSearch nullObject
      (
      );

protected:

   std::vector<TYPE> m_vData;         ///< Vector of independent data

   // EcInt32 used instead of EcU32 because negative index
   // signals initialization needed
   mutable EcInt32 m_Index[2];        ///< Bounding indices

   EcU32 m_MaxSearchIndex;            ///< Max search index (Vector Size - 2)

   mutable TYPE m_Weight[2];          ///< Bounding weights

   /** Options are strictly INCREASING or DECREASING */
   ARRAY_DIRECTION m_DataDirection;   ///< Independent variable array slope

   /** Options are LIMIT and EXTRAPOLATE */
   BOUNDARY_OPTION m_LowerBoundaryOption;  ///< Lower bound search option

   /** Options are LIMIT and EXTRAPOLATE */
   BOUNDARY_OPTION m_UpperBoundaryOption;  ///< Upper bound search option

   /** Search options include LINEAR, BISECTION, and EQUAL_SPACED */
   SEARCH_OPTION m_SearchOption;      ///< Search technique option

   /** Only used if search option is EQUAL_SPACED */
   TYPE m_IndexSpacing;               ///< Spacing between break points
};

#endif // ecVectorSearch_H_
