#ifndef ecDecisionTreeShapeMatchingBranch_H_
#define ecDecisionTreeShapeMatchingBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDecisionTreeShapeMatchingBranch.h
/// @class EcDecisionTreeShapeMatchingBranch
/// @brief This class tests an object for shape matching
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeBranch.h"
#include "ecShapeFeatureHistogram.h"

class EcStatedSystem;

/** This class tests an object using a shape matching algorithm. */
class EC_ACTIN_GRASPING_DECL EcDecisionTreeShapeMatchingBranch : public EcGraspingDecisionTreeBranch
{
public:
   /// default constructor
   EcDecisionTreeShapeMatchingBranch
      (
      );

   /// destructor
   virtual ~EcDecisionTreeShapeMatchingBranch
      (
      );

   /// copy constructor
   EcDecisionTreeShapeMatchingBranch
      (
      const EcDecisionTreeShapeMatchingBranch& orig
      );

   /// assignment operator
   EcDecisionTreeShapeMatchingBranch& operator=
      (
      const EcDecisionTreeShapeMatchingBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDecisionTreeShapeMatchingBranch& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// register XML member variables
   void registerComponents
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get a null object
   static EcDecisionTreeShapeMatchingBranch nullObject
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

   /// get the shape feature histogram for the comparison shape
   virtual const EcShapeFeatureHistogram& comparisonShapeFeatureHistogram
      (
      ) const;

   /// set the shape feature histogram for the comparison shape
   virtual void setComparisonShapeFeatureHistogram
      (
      const EcShapeFeatureHistogram& histogram
      );

   /// get the dissimilarity threshold value for the shape comparison
   virtual EcReal dissimilarityThresholdValue
      (
      ) const;

   /// set the dissimilarity threshold value for the shape comparison
   virtual void setDissimilarityThresholdValue
      (
      EcReal value
      );

   /// test the object for traversing the decision tree
   virtual EcReal test
      (
      const EcGraspInitParams& params
      ) const;

protected:
   /// the shape feature histogram for the comparison shape
   EcShapeFeatureHistogram m_ComparisonShapeFeatureHistogram;

   /// the dissimilarity threshold value for the shape comparison
   EcXmlReal m_DissimilarityThresholdValue;
};

#endif // ecDecisionTreeShapeMatchingBranch_H_
