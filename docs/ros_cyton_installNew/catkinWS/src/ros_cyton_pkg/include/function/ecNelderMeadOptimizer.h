#ifndef ecNelderMeadOptimizer_H_
#define ecNelderMeadOptimizer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecNelderMeadOptimizer.h
/// @class EcNelderMeadOptimizer
/// @brief Holds a description of a modified Nelder-Mead optimizier.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecScalarMultivariableOptimizer.h"
#include <xml/ecXmlVectorType.h>

class EcScalarMultivariableFunction;

/** Holds a description of a modified Nelder-Mead optimizier.
*/
class EC_FOUNDATION_FUNCTION_DECL EcNelderMeadOptimizer : public EcScalarMultivariableOptimizer
{
public:
   /// default constructor
   EcNelderMeadOptimizer
      (
      );

   /// destructor
   virtual ~EcNelderMeadOptimizer
      (
      );

   /// copy constructor
   EcNelderMeadOptimizer
      (
      const EcNelderMeadOptimizer& orig
      );

   /// assignment operator
   EcNelderMeadOptimizer& operator=
      (
      const EcNelderMeadOptimizer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcNelderMeadOptimizer& orig
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

   /// gets the Nelder-Mead alpha parameter
   virtual EcReal alpha
      (
      ) const;

   /// sets the Nelder-Mead alpha parameter
   virtual void setAlpha
      (
      EcReal alpha
      );

   /// gets the Nelder-Mead beta parameter
   virtual EcReal beta
      (
      ) const;

   /// sets the Nelder-Mead beta parameter
   virtual void setBeta
      (
      EcReal beta
      );

   /// gets the Nelder-Mead gamma parameter
   virtual EcReal gamma
      (
      ) const;

   /// sets the Nelder-Mead gamma parameter
   virtual void setGamma
      (
      EcReal gamma
      );

   /// gets the Nelder-Mead sigma parameter
   virtual EcReal sigma
      (
      ) const;

   /// sets the Nelder-Mead sigma parameter
   virtual void setSigma
      (
      EcReal sigma
      );

   /// gets the stopping threshold
   virtual EcReal stoppingThreshold
      (
      ) const;

   /// sets the stopping threshold
   virtual void setStoppingThreshold
      (
      EcReal stoppingThreshold
      );

   /// gets the overall maximum number of steps
   virtual EcU32 maxTotalSteps
      (
      ) const;

   /// sets the overall maximum number of steps
   virtual void setMaxTotalSteps
      (
      EcU32 maxTotalSteps
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

   /// gets the restart period (in terms of function evaluations)
   virtual EcU32 restartCheckPeriod
      (
      ) const;

   /// sets the restart period (in terms of function evaluations)
   virtual void setRestartCheckPeriod
      (
      EcU32 restartCheckPeriod
      );

   /// gets the margin used to asses a restart
   virtual EcReal eta
      (
      ) const;

   /// sets the margin used to asses a restart
   virtual void setEta
      (
      EcReal eta
      );

   /// gets the maximum expansion steps
   virtual EcU32 maxExpansionSteps
      (
      ) const;

   /// sets the maximum expansion steps
   virtual void setMaxExpansionSteps
      (
      EcU32 maxExpansionSteps
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
   static EcNelderMeadOptimizer nullObject
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

   /// process a single step of Nelder-Mead
   /// multiply the function by the multiplier
   virtual EcReal singleStep
      (
      EcReal multiplier,
      const EcScalarMultivariableFunction& function,
      EcBoolean& finish
      ) const;

   /// exchange the high vertex with the vertex provided.
   /// The function value at the new vertex is also provided
   virtual void exchangeHighVertex
      (
      EcU32 domainSize,
      const EcRealVector& vNewVertex,
      EcReal functionValueAtNewVertex
      ) const;

   /// exchange the high vertex with the vertex provided and
   /// contract the simplex toward the low point.
   /// The function value at the new vertex is also provided
   virtual void exchangeHighVertexAndContract
      (
      EcReal multiplier,
      const EcScalarMultivariableFunction& function,
      EcU32 domainSize,
      const EcRealVector& vNewVertex,
      EcReal functionValueAtNewVertex
      ) const;

   /// finds the indices giving the max and min function values
   virtual void findMaxAndMin
      (
      ) const;

   /// calculate the mean of all vertices except the max point
   virtual void calculateVertexMeanExcludingMaxPoint
      (
      ) const;

   /// restart if the restart conditions are satisfied
   virtual void restartIfNeeded
      (
      const EcReal& multiplier,
      const EcScalarMultivariableFunction& function
      ) const;

protected:
   /// the core Nelder-Mead parameters
   EcXmlReal               m_Alpha;       ///< The alpha value
   EcXmlReal               m_Beta;        ///< The beta value
   EcXmlReal               m_Gamma;       ///< The gamma value
   EcXmlReal               m_Sigma;       ///< The sigma value

   /// stopping parameters
   EcXmlReal               m_StoppingThreshold;       ///< The stopping threshold
   EcXmlU32                m_MaxTotalSteps;           ///< The max number of total steps
   EcXmlU32                m_MaxFunctionEvaluations;  ///< The max number of function evaluations

   /// restart parameters
   EcXmlU32                m_RestartCheckPeriod;      ///< The check period for restarting
   EcXmlReal               m_Eta;                     ///< The eta value

   /// additional parameter
   EcXmlU32                m_MaxExpansionSteps;

   /// initial simplex edge lengths
   EcXmlRealVector         m_SimplexEdgeLengths;

   /// a default simplex edge length
   EcXmlReal               m_DefaultSimplexEdgeLength;

   // non-XML data below

   /// simplex vertices are the rows
   mutable EcReArray       m_Vertices;

   /// vector of function values
   mutable EcRealVector    m_vFunctionValues;
   /// vector of means of vertices excluding the one giving the maximum function value
   mutable EcRealVector    m_vVertexMeanExcludingMax;

   /// four extra vertices are the rows
   mutable EcReArray       m_UtilityVertices;

   // utility values
   mutable EcU32           m_MinIndex;             ///< The mininum index
   mutable EcU32           m_MaxIndex;             ///< The mininum index
   mutable EcU32           m_NumExpansionStepsSoFar;  ///< The number of expansion steps

   /// a counter for the total number of function evaluations
   mutable EcU32           m_FunctionEvaluationCount;

   /// a counter for the number of function evaluations since the
   /// last restart
   mutable EcU32           m_FunctionEvaluationCountSinceLastRestart;

   /// storage for the last maximum vertex value
   mutable EcReal          m_LastMaximum;

   /// storage for a restart vertex
   mutable EcRealVector    m_RestartVertex;
};

#endif // ecNelderMeadOptimizer_H_
