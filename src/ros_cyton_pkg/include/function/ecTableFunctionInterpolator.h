#ifndef ecTableFunctionInterpolator_H_
#define ecTableFunctionInterpolator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecTableFunctionInterpolator.h
/// @class EcTableFunctionInterpolator
/// @brief Linear interpolator for table functions
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecCompositeFunctionElement.h"
#include "ecTableFunctionVectorSearch.h"
#include "ecInterpolator.h"

class EcCompositeFunctionContainer;

/// Interpolator class for table functions
/**
   Holds a description of an interpolator with read/write XML access
*/
class EC_FOUNDATION_FUNCTION_DECL EcTableFunctionInterpolator : public EcCompositeFunctionElement
{
public:
   /// default constructor
   EcTableFunctionInterpolator
      (
      );

   /// constructor with container pointer
   explicit EcTableFunctionInterpolator
      (
      const EcCompositeFunctionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcTableFunctionInterpolator
      (
      );

   /// copy constructor
   EcTableFunctionInterpolator
      (
      const EcTableFunctionInterpolator& orig
      );

   /// assignment operator
   EcTableFunctionInterpolator& operator=
      (
      const EcTableFunctionInterpolator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTableFunctionInterpolator& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// init object
   virtual EcBoolean init
      (
      );

   /// perform an interpolation
   /**
       Get interpolated value from table function
       \param vInput Independent data state
       \param status Was evaluation performed?
       \return Result of evaluation
   */
   virtual const EcRealVector& evaluate
      (
      const EcRealVector& vInput,
      EcBoolean& status
      ) const;

   /// set the dependent data vector
   virtual void dependentDataPushBack
      (
      const EcRealVector& vInterpolationVector
      );

   /// set the independent data vector
   virtual void independentDataPushBack
      (
      const EcTableFunctionVectorSearch& independentData
      );

   /// Initialize bounds of independent data
   /**
       \return Vector of min/max dimension bounds
   */
   virtual const EcRealVectorVector& initBounds
      (
      );

   /// Initialize boundary methods for independent data
   /**
       Initialization method used to evaluate requests of out of bounds data
       \return Vector of min/max boundary methods
   */
   virtual const EcBooleanVectorVector& initLimitOrExtrapolate
      (
      );

   /// get a null object
   static EcTableFunctionInterpolator nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// XML vector holding independent dimension data
   EcXmlVectorType<EcTableFunctionVectorSearch> m_IndependentData;

   /// XML vector holding interpolator data
   EcXmlRealVectorVector m_DependentData;

   /// interpolator
   EcInterpolator<EcReal> m_Interpolator;
};

#endif // ecTableFunctionInterpolator_H_
