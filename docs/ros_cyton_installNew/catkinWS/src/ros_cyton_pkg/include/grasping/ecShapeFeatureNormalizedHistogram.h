#ifndef ecShapeFeatureNormalizedHistogram_H_
#define ecShapeFeatureNormalizedHistogram_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeFeatureNormalizedHistogram.h
/// @class EcShapeFeatureNormalizedHistogram
/// @brief A histogram produced from EcShapeFeatureSet.
/// @todo DissimilarityTypeEnum is also present for EcShapeFeatureHistogram
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// Forward declarations
class EcShapeFeatureHistogram;
class EcShapeFeatureSet;

/// A histogram produced from EcShapeFeatureSet.
class EC_ACTIN_GRASPING_DECL EcShapeFeatureNormalizedHistogram : public EcXmlCompoundType
{
public:

   /// a metric enumeration for dissimilarity
   enum DissimilarityTypeEnum
   {
      SHAPE_DISSIMILARITY     = 0,
      DISTANCE_DISSIMILARITY  = 1,
      COMBINED_DISSIMILARITY  = 2
   };

   /// default constructor
   EcShapeFeatureNormalizedHistogram
      (
      );

   /// destructor
   virtual ~EcShapeFeatureNormalizedHistogram
      (
      );

   /// copy constructor
   EcShapeFeatureNormalizedHistogram
      (
      const EcShapeFeatureNormalizedHistogram& orig
      );

   /// assignment operator
   EcShapeFeatureNormalizedHistogram& operator=
      (
      const EcShapeFeatureNormalizedHistogram& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeFeatureNormalizedHistogram& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the histogram data
   virtual const EcXmlRealVectorVector& histogramData
      (
      ) const;

   /// get the average distance data
   const EcXmlRealVectorVector& averageDistanceData
      (
      ) const;

   /// get the size of the source feature set
   virtual EcU32 featureSetSize
      (
      ) const;

   /// get the number of bins along the distance (horizontal) axis
   virtual EcU32 numDistanceBins
      (
      ) const;

   /// get the number of bins along the angle (vertical) axis
   virtual EcU32 numAngleBins
      (
      ) const;

   /// get the flag indicating if absolute angle method is being used
   virtual EcBoolean absoluteAngleFlag
      (
      ) const;

   /// get the max value
   virtual EcReal maxValue
      (
      ) const;

   /// get the size of the source shape (maximum distance from source shape feature set)
   virtual EcReal size
      (
      ) const;

   /// populate the histogram data from a shape feature set
   virtual void populateHistogram
      (
      const EcShapeFeatureSet& featureSet,
      EcU32 numDistanceBins = 10,
      EcU32 numAngleBins    = 10,
      EcBoolean absoluteAngleFlag = EcFalse
      );

   /// populate the normalized histogram data from a raw histogram
   virtual void populateHistogram
      (
      const EcShapeFeatureHistogram& rawHistogram
      );

   /// clear the histogram
   virtual void clear
      (
      );

   /// dissimilarity between this histogram and another
   virtual EcBoolean dissimilarity
      (
      const EcShapeFeatureNormalizedHistogram& otherHistogram,
      EcReal& dissimilarityValue,
      DissimilarityTypeEnum type = COMBINED_DISSIMILARITY
      ) const;

   /// default XML token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// the histogram data
   EcXmlRealVectorVector m_HistogramData;

   /// the average distance data
   EcXmlRealVectorVector m_AverageDistanceData;

   /// the size of the source feature set
   EcXmlU32              m_FeatureSetSize;

   /// number of bins along the distance (horizontal) axis
   EcXmlU32              m_NumDistanceBins;

   /// number of bins along the angle (vertical) axis
   EcXmlU32              m_NumAngleBins;

   /// flag indicating if absolute angle method is being used
   EcXmlBoolean          m_AbsoluteAngleFlag;

   /// maximum value
   EcXmlReal             m_MaxValue;

   /// the size of the source shape (maximum distance from source shape feature set)
   EcXmlReal             m_Size;
};

#endif // ecShapeFeatureNormalizedHistogram_H_
