#ifndef ecShapeFeatureHistogram_H_
#define ecShapeFeatureHistogram_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeFeatureHistogram.h
/// @class EcShapeFeatureHistogram
/// @brief A histogram produced from EcShapeFeatureSet.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// Forward declarations
class EcShapeFeatureSet;

/// A histogram produced from EcShapeFeatureSet.
class EC_ACTIN_GRASPING_DECL EcShapeFeatureHistogram : public EcXmlCompoundType
{
public:

   /// an enumeration of metric types for dissimilarity
   enum DissimilarityTypeEnum
   {
      SHAPE_DISSIMILARITY     = 0,
      DISTANCE_DISSIMILARITY  = 1,
      COMBINED_DISSIMILARITY  = 2
   };

   /// default constructor
   EcShapeFeatureHistogram
      (
      );

   /// destructor
   virtual ~EcShapeFeatureHistogram
      (
      );

   /// copy constructor
   EcShapeFeatureHistogram
      (
      const EcShapeFeatureHistogram& orig
      );

   /// assignment operator
   EcShapeFeatureHistogram& operator=
      (
      const EcShapeFeatureHistogram& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeFeatureHistogram& orig
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
   virtual const EcXmlU32VectorVector& histogramData
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
   virtual EcU32 maxValue
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

   /// clear the histogram
   virtual void clear
      (
      );

   /// dissimilarity between this histogram and another
   virtual EcBoolean dissimilarity
      (
      const EcShapeFeatureHistogram& otherHistogram,
      EcReal& dissimilarityValue,
      DissimilarityTypeEnum type = COMBINED_DISSIMILARITY
      ) const;

   /// default XML token
   virtual const EcToken& token
      (
      ) const;

protected:

   /// calculate histogram data
   virtual void populateHistogramData
      (
      const EcShapeFeatureSet& featureSet
      );

   /// the histogram data
   EcXmlU32VectorVector  m_HistogramData;

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
   EcXmlU32              m_MaxValue;

   /// the size of the source shape (maximum distance from source shape feature set)
   EcXmlReal             m_Size;
};

#endif // ecShapeFeatureHistogram_H_
