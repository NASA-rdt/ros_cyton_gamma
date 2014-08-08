#ifndef ecMultidirectionalSearchOptimizer_H_
#define ecMultidirectionalSearchOptimizer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultidirectionalSearchOptimizer.h
/// @class EcMultidirectionalSearchOptimizer
/// @brief Holds a description of a modified Multidirectional Search
///        optimizer.  References:
///        1) V. Torczon, "On the Convergence of Pattern Search Algorithms,"
///        SIAM J. Optimization, v. 7, no. 1, pp 1-25, 1997.
///        2) V. Torczon, Multi-Directional Search: A Direct Search
///        Algorithm for Parallel Machines, Ph.D. Thesis, Rice University, 1989.
///        3) V. Torczon, "On the Convergence of Pattern Search Algorithms,"
///        SIAM J. Optimization, v. 7, no. 1, pp 1-25, 1997.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecScalarMultivariableOptimizer.h"
#include <xml/ecXmlVectorType.h>

class EcScalarMultivariableFunction;

/** Holds a description of a Multidirectional Search optimizier.
*/
class EC_FOUNDATION_FUNCTION_DECL EcMultidirectionalSearchOptimizer : public EcScalarMultivariableOptimizer
{
public:
   /// default constructor
   EcMultidirectionalSearchOptimizer
      (
      );

   /// destructor
   virtual ~EcMultidirectionalSearchOptimizer
      (
      );

   /// copy constructor
   EcMultidirectionalSearchOptimizer
      (
      const EcMultidirectionalSearchOptimizer& orig
      );

   /// assignment operator
   EcMultidirectionalSearchOptimizer& operator=
      (
      const EcMultidirectionalSearchOptimizer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultidirectionalSearchOptimizer& orig
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

   /// gets the alpha (reflection) parameter
   virtual EcReal alpha
      (
      ) const;

   /// sets the alpha (reflection) parameter
   virtual void setAlpha
      (
      EcReal alpha
      );

   /// gets the beta (expansion) parameter
   virtual EcReal beta
      (
      ) const;

   /// sets the beta (expansion) parameter
   virtual void setBeta
      (
      EcReal beta
      );

   /// gets the gamma (contraction) parameter
   virtual EcReal gamma
      (
      ) const;

   /// sets the gamma (contraction) parameter
   virtual void setGamma
      (
      EcReal gamma
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
   static EcMultidirectionalSearchOptimizer nullObject
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

   /// set the vertices and function values based on the result of
   /// an iteration
   virtual void setNewData
      (
      const EcReArray& vertices,
      const EcRealVector& functionValues
      ) const;

protected:

   // the core Multidirectional Search parameters
   EcXmlReal               m_Alpha;       ///< The alpha value
   EcXmlReal               m_Beta;        ///< The beta value
   EcXmlReal               m_Gamma;       ///< The gamma value

   // stopping parameters
   EcXmlReal               m_StoppingThreshold;          ///< The stopping threshold
   EcXmlU32                m_MaxFunctionEvaluations;     ///< The max number of function evaluations

   /// initial simplex edge lengths
   EcXmlRealVector         m_SimplexEdgeLengths;

   /// a default simplex edge length
   EcXmlReal               m_DefaultSimplexEdgeLength;

   // non-XML data below

   /// simplex vertices are the rows
   mutable EcReArray       m_Vertices;

   /// function values for the vertices
   mutable EcRealVector    m_vFunctionValues;

   /// reflected simplex vertices are the rows
   mutable EcReArray       m_ReflectedVertices;

   /// function values for the reflected vertices
   mutable EcRealVector    m_vReflectedFunctionValues;

   /// expanded simplex vertices are the rows
   mutable EcReArray       m_ExpandedVertices;

   /// function values for the expanded vertices
   mutable EcRealVector    m_vExpandedFunctionValues;

   /// contracted simplex vertices are the rows
   mutable EcReArray       m_ContractedVertices;

   /// function values for the contracted vertices
   mutable EcRealVector    m_vContractedFunctionValues;

   // utility values
   mutable EcU32           m_MinIndex;                ///< The minimum index
   mutable EcU32           m_MaxIndex;                ///< The maximum index

   /// a counter for the total number of function evaluations
   mutable EcU32           m_FunctionEvaluationCount;

   // the best function domain and value
   mutable EcReal          m_BestFunctionValue;       ///< The best function value
   mutable EcRealVector*   m_pBestDomainSet;          ///< The best domain set
};

#endif // ecMultidirectionalSearchOptimizer_H_
