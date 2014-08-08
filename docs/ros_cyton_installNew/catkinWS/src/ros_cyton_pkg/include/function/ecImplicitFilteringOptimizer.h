#ifndef ecImplicitFilteringOptimizer_H_
#define ecImplicitFilteringOptimizer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecImplicitFilteringOptimizer.h
/// @class EcImplicitFilteringOptimizer
/// @brief Holds a description of a modified Implicit Filtering
///        optimizier.  References:
///        1) P. Gilmore, C.T. Kelly, C.T. Miller, and G.A. Williams,
///        "Implicit Filtering and Optimal Design Problems", Progress
///        in Systems and Control Theory, vol. 19, Birkhauser, Boston,
///        pp. 159-176, 1995.
///        2) C.T. Kelly, "Iterative Methods for Optimization", SIAM, 1999.
///        The second reference above gives a summary of many different
///        optimization methods.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecScalarMultivariableOptimizer.h"
#include <xml/ecXmlVectorType.h>

class EcScalarMultivariableFunction;

/** Holds a description of a Multidirectional Search optimizier.
*/
class EC_FOUNDATION_FUNCTION_DECL EcImplicitFilteringOptimizer : public EcScalarMultivariableOptimizer
{
public:
   /// default constructor
   EcImplicitFilteringOptimizer
      (
      );

   /// destructor
   virtual ~EcImplicitFilteringOptimizer
      (
      );

   /// copy constructor
   EcImplicitFilteringOptimizer
      (
      const EcImplicitFilteringOptimizer& orig
      );

   /// assignment operator
   EcImplicitFilteringOptimizer& operator=
      (
      const EcImplicitFilteringOptimizer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImplicitFilteringOptimizer& orig
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

   /// gets the line-search alpha (sufficiency) parameter
   virtual EcReal lineSearchAlpha
      (
      ) const;

   /// gets the line-search alpha (sufficiency) parameter
   virtual void setLineSearchAlpha
      (
      EcReal lineSearchAlpha
      );

   /// gets the line-search beta (reduction) parameter
   virtual EcReal lineSearchBeta
      (
      ) const;

   /// sets the line-search beta (reduction) parameter
   virtual void setLineSearchBeta
      (
      EcReal lineSearchBeta
      );

   /// gets the maximum number of iterations to use for the line search
   virtual EcU32 lineSearchMaxIterations
      (
      ) const;

   /// sets the maximum number of iterations to use for the line search
   virtual void setLineSearchMaxIterations
      (
      EcU32 lineSearchMaxIterations
      );

   /// gets the stopping threshold
   virtual EcReal tau
      (
      ) const;

   /// sets the stopping threshold
   virtual void setTau
      (
      EcReal tau
      );

   /// gets the overall maximum number of function evaluations
   virtual EcU32 maxFunctionEvaluations
      (
      ) const;

   /// sets the overall maximum number of function evaluations
   virtual void setMaxFunctionEvaluations
      (
      EcU32 maxFunctionEvaluations
      );

   /// gets the simplex edge lengths
   virtual const EcXmlRealVector& simplexEdgeLengths
      (
      ) const;

   /// sets the simplex edge lengths
   virtual void setSimplexEdgeLengths
      (
      const EcXmlRealVector& simplexEdgeLengths
      );

   /// gets the default simplex edge length
   virtual EcReal defaultSimplexEdgeLength
      (
      ) const;

   /// sets the default simplex edge length
   virtual void setDefaultSimplexEdgeLength
      (
      EcReal defaultSimplexEdgeLength
      );

   /// gets the simplex scale factor
   virtual EcReal simplexScaleFactor
      (
      ) const;

   /// sets the simplex scale factor
   virtual void setSimplexScaleFactor
      (
      EcReal simplexScaleFactor
      );

   /// gets the initial lambda multiplier
   /// lambda starts with a value proportional to this multiplier
   virtual EcReal lineSearchInitialLambdaMultiplier
      (
      ) const;

   /// sets the initial value for lambda
   /// lambda starts with a value proportional to this multiplier
   virtual void setLineSearchInitialLambdaMultiplier
      (
      EcReal lineSearchInitialLambdaMultiplier
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
   static EcImplicitFilteringOptimizer nullObject
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
   /// initialize the simplex and array sizes
   /**
    * @param[in] multiplier
    * @param[in] function
    * @param[in] vInputValues
    * @param[in] scale
    */
   virtual void initialize
      (
      EcReal multiplier,
      const EcScalarMultivariableFunction& function,
      const EcRealVector& vInputValues,
      const EcReal scale=1.0
      ) const;

   /// process a single step of Multidirectional Search
   /// multiply the function by the multiplier
   virtual EcReal singleStep
      (
      EcReal multiplier,
      const EcScalarMultivariableFunction& function,
      EcBoolean& finish
      ) const;

   /// finds the indices giving the max and min function values
   virtual void findMaxAndMin
      (
      ) const;

   /// finds the index giving the minimum
   virtual EcU32 findMinIndex
      (
      const EcRealVector& values
      ) const;

protected:
   // the core Multidirectional Search parameters
   EcXmlReal               m_LineSearchAlpha;               ///< The alpha of line search
   EcXmlReal               m_LineSearchBeta;                ///< The beta of line search
   EcXmlU32                m_LineSearchMaxIterations;       ///< The max iterations of line search
   EcXmlReal               m_LineSearchInitialLambdaMultiplier;   ///< The initial lambda multiplier of line searh

   // stopping parameters
   EcXmlReal               m_Tau;                           ///< The tau parameter for stopping optimization
   EcXmlU32                m_MaxFunctionEvaluations;        ///< The max number of function evaluations

   /// initial simplex edge lengths
   EcXmlRealVector         m_SimplexEdgeLengths;

   /// a default simplex edge length
   EcXmlReal               m_DefaultSimplexEdgeLength;

   /// a simplex scale factor for size reduction
   EcXmlReal               m_SimplexScaleFactor;

   // non-XML data below

   /// simplex vertices are the rows
   mutable EcReArray       m_Vertices;

   /// function values for the vertices
   mutable EcRealVector    m_vFunctionValues;

   /// central difference simplex gradient
   mutable EcRealVector    m_vCentralDifferenceGradient;

   /// domain point for line search
   mutable EcRealVector    m_LineSearchDomainData;

   /// domain differences used for gradient evaluation
   mutable EcRealVector    m_vDomainDifferences;

   // utility values
   mutable EcU32           m_MinIndex;                ///< The minimum index
   mutable EcU32           m_MaxIndex;                ///< The maximum index

   /// a counter for the total number of function evaluations
   mutable EcU32           m_FunctionEvaluationCount;

   // the best function domain and value
   mutable EcReal          m_BestFunctionValue;       ///< The best function value
   mutable EcRealVector*   m_pBestDomainSet;          ///< The best domain set
};

#endif // ecImplicitFilteringOptimizer_H_
