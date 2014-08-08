#ifndef ecHookeJeevesOptimizer_H_
#define ecHookeJeevesOptimizer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecHookeJeevesOptimizer.h
/// @class EcHookeJeevesOptimizer
/// @brief Holds a description of the Hooke-Jeeves optimization
///        algorithm, described in the paper by Robert Hooke and T. A. Jeeves,
///        "'Direct Search' Solution of Numerical and Statistical Problems",
///        Journal of the ACM, v. 8, pp. 212-229, April 1961.  Includes enhancements
///        based on Bell and Pike, "Remark on Algorithm 178" (Comm. ACM v.9, no. 9,
///        Sept 1966), Tomlin and Smith, "Remark on Algorithm 178"  (Comm. ACM v.12,
///        no. 11, Nov 1969), and Smith, "Remark on Algorithm 178," (Comm. ACM v. 12,
///        no. 11, 1969).  The Hooke-Jeeves algorithm is also discussed in Kaupe,
///        "Algorithm 178, Direct Search," (Comm. ACM v. 6, no. 6, 1963).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecScalarMultivariableOptimizer.h"
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlVectorType.h>

class EcScalarMultivariableFunction;

/** Holds a description of a modified Hooke-Jeeves optimizier.
*/
class EC_FOUNDATION_FUNCTION_DECL EcHookeJeevesOptimizer : public EcScalarMultivariableOptimizer
{
public:
   /// directions-mode enumeration
   enum {NODIRECTION, AXISALIGNED, RANDOM, ROTATED};

   /// default constructor
   EcHookeJeevesOptimizer
      (
      );

   /// destructor
   virtual ~EcHookeJeevesOptimizer
      (
      );

   /// copy constructor
   EcHookeJeevesOptimizer
      (
      const EcHookeJeevesOptimizer& orig
      );

   /// assignment operator
   EcHookeJeevesOptimizer& operator=
      (
      const EcHookeJeevesOptimizer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcHookeJeevesOptimizer& orig
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

   /// gets the reduction factor (applied for shrink steps)
   virtual EcReal reductionFactor
      (
      ) const;

   /// sets the reduction factor (applied for shrink steps)
   virtual void setReductionFactor
      (
      EcReal reductionFactor
      );

   /// gets the minimum total reduction (used for termination)
   virtual EcReal minTotalReduction
      (
      ) const;

   /// sets the minimum total reduction (used for termination)
   virtual void setMinTotalReduction
      (
      EcReal minTotalReduction
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

   /// gets the edge lengths
   virtual const EcXmlRealVector& edgeLengths
      (
      ) const;

   /// sets the edge lengths
   virtual void setEdgeLengths
      (
      const EcXmlRealVector& edgeLengths
      );

   /// gets the default edge length
   virtual EcReal defaultEdgeLength
      (
      ) const;

   /// sets the default edge length
   virtual void setDefaultEdgeLength
      (
      EcReal defaultEdgeLength
      );

   /// gets the directions mode
   virtual EcU32 directionsMode
      (
      ) const;

   /// sets the directions mode
   virtual void setDirectionsMode
      (
      EcU32 directionsMode
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
   static EcHookeJeevesOptimizer nullObject
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
      const EcReal scale = 1.0
      ) const;

   /// make an initial exploratory move with a new reduction size
   virtual void newExploratoryMove
      (
      ) const;

   /// make a transitional move
   virtual void transitionalMove
      (
      ) const;

   /// make a pattern contraction
   virtual void patternContraction
      (
      ) const;

   /// perform an exploratory step
   virtual EcBoolean explore
      (
      ) const;

   /// initialize the directions matrix
   virtual void initializeDirections
      (
      ) const;

   /// update the directions matrix
   virtual void updateDirections
      (
      ) const;

protected:
   // the core parameters
   EcXmlReal                  m_ReductionFactor;      ///< The reduction factor
   EcXmlReal                  m_MinTotalReduction;    ///< The minimum total reduction

   /// stopping parameters
   EcXmlU32                   m_MaxFunctionEvaluations;

   /// initial edge lengths
   EcXmlRealVector            m_EdgeLengths;

   /// a default edge length
   EcXmlReal                  m_DefaultEdgeLength;

   /// the mode for establishing directions
   EcXmlEnumU32               m_DirectionsMode;

   // non-XML data below

   // function evaluation points
   mutable EcRealVector       m_BasePoint;            ///< The base point
   mutable EcRealVector       m_MovePoint;            ///< The move point
   mutable EcRealVector       m_MovePointStart;       ///< The start of the move point
   mutable EcRealVector       m_MovePointLoopStart;   ///< The loop start of the move point
   mutable EcRealVector       m_PreviousBasePoint;    ///< The previous base point

   /// best directions for next step
   mutable EcRealVector       m_BestDirections;

   /// a counter for the total number of function evaluations
   mutable EcU32              m_FunctionEvaluationCount;

   // storage for the last maximum vertex value
   mutable EcReal             m_FunctionValueAtBasePoint;   ///< The function value at base point
   mutable EcReal             m_SmallestFunctionValue;      ///< The smallest function value

   /// a multiplier used to control the type of optimization
   /// (minimization versus maximization)
   mutable EcReal             m_Multiplier;

   /// a set of edge lengths as actually used
   mutable EcXmlRealVector    m_EffectiveEdgeLengths;

   /// the function to optimize
   mutable const EcScalarMultivariableFunction* m_pFunction;

   /// the total reduction factor
   mutable EcReal             m_TotalReduction;

   /// a flag signaling continuation or, if false, immediate return
   mutable EcBoolean          m_Continue;

   /// a set of directions (as columns)
   mutable EcRealVectorVector m_DirectionsMatrix;

   /// a count on the number of directions update since initialization
   mutable EcU32              m_DirectionsUpdateCount;
};

#endif // ecHookeJeevesOptimizer_H_
