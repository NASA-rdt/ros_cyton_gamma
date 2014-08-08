#ifndef ecSequenceOptimizer_H_
#define ecSequenceOptimizer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSequenceOptimizer.h
/// @class EcSequenceOptimizer
/// @brief Holds an optimizer that itself contains a sequence of
///        other optimizers.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecScalarMultivariableOptimizer.h"
#include "ecScalarMultivariableOptimizerVector.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcScalarMultivariableFunction;

/** Holds a description of a Multidirectional Search optimizier.
*/
class EC_FOUNDATION_FUNCTION_DECL EcSequenceOptimizer : public EcScalarMultivariableOptimizer
{
public:
   /// default constructor
   EcSequenceOptimizer
      (
      );

   /// destructor
   virtual ~EcSequenceOptimizer
      (
      );

   /// copy constructor
   EcSequenceOptimizer
      (
      const EcSequenceOptimizer& orig
      );

   /// assignment operator
   EcSequenceOptimizer& operator=
      (
      const EcSequenceOptimizer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSequenceOptimizer& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// gets the number of passes through the sequence
   virtual EcU32 numberPasses
      (
      ) const;

   /// sets the maximum number of iterations to use for the line search
   virtual void setNumberPasses
      (
      EcU32 numberPasses
      );

   /// gets the optimizer sequence
   virtual const EcScalarMultivariableOptimizerVector& optimizerSequence
      (
      ) const;

   /// sets the optimizer sequence
   virtual void setOptimizerSequence
      (
      const EcScalarMultivariableOptimizerVector& optimizerSequence
      );

   /// gets the execute-in-parallel flag
   virtual EcBoolean executeInParallel
      (
      ) const;

   /// gets the execute-in-parallel flag
   virtual void setExecuteInParallel
      (
      EcBoolean executeInParallel
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// find the function minimum
   virtual EcReal findMinimum
      (
      const EcScalarMultivariableFunction& function,
      const EcRealVector& vInputValues,
      EcRealVector& vValuesAtMinimum
      ) const;

   /// find the function maximum
   virtual EcReal findMaximum
      (
      const EcScalarMultivariableFunction& function,
      const EcRealVector& vInputValues,
      EcRealVector& vValuesAtMaximum
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

   /// get a null object
   static EcSequenceOptimizer nullObject
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
   /// the number of passes through the sequence
   EcXmlU32                             m_NumberPasses;

   /// the sequence
   EcScalarMultivariableOptimizerVector m_OptimizerSequence;

   /// a flag indicating that all optimizers in the vector should
   /// be executed in parallel
   EcXmlBoolean                         m_ExecuteInParallel;

   // non-XML data below
   mutable EcRealVector                 m_vInitialValues;      ///< the vector of initial values
   mutable EcRealVector                 m_vCandidateValuesAtOptimum; ///< the vector of candidate values at optimum
};

#endif // ecSequenceOptimizer_H_
