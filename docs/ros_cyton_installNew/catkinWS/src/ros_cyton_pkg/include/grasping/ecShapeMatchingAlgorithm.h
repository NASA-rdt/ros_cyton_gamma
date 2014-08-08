#ifndef ecShapeMatchingAlgorithm_H_
#define ecShapeMatchingAlgorithm_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeMatchingAlgorithm.h
/// @class EcShapeMatchingAlgorithm
/// @brief Algorithms used for shape matching.
/// @todo EcVectorVector is already defined elsewhere, and should just be included.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// Forward declarations
class EcManipulatorLink;
class EcShape;
class EcShapeFeatureHistogram;
class EcShapeFeatureSet;
class EcVector;

/// a standard-library vector of EcVector objects
typedef std::vector<EcVector> EcVectorVector;

/// Algorithms used for shape matching.
class EC_ACTIN_GRASPING_DECL EcShapeMatchingAlgorithm : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShapeMatchingAlgorithm
      (
      );

   /// destructor
   virtual ~EcShapeMatchingAlgorithm
      (
      );

   /// copy constructor
   EcShapeMatchingAlgorithm
      (
      const EcShapeMatchingAlgorithm& orig
      );

   /// assignment operator
   EcShapeMatchingAlgorithm& operator=
      (
      const EcShapeMatchingAlgorithm& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeMatchingAlgorithm& orig
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

   /// get the number of bins along the angle (vertical) axis for histogram creation
   virtual EcU32 numAngleBins
      (
      ) const;

   /// set the number of bins along the angle (vertical) axis for histogram creation
   virtual void setNumAngleBins
      (
      EcU32 num
      );

   /// get the number of bins along the distance (horizontal) axis for histogram creation
   virtual EcU32 numDistanceBins
      (
      ) const;

   /// set the number of bins along the distance (horizontal) axis for histogram creation
   virtual void setNumDistanceBins
      (
      EcU32 num
      );

   /// get the flag indicating if absolute angle method is being used for histogram creation
   virtual EcBoolean absoluteAngleFlag
      (
      ) const;

   /// set the flag indicating if absolute angle method is being used for histogram creation
   virtual void setAbsoluteAngleFlag
      (
      EcBoolean flag
      );

   /// get the number of points used for feature set extraction
   virtual EcU32 numPoints
      (
      ) const;

   /// set the number of points used for feature set extraction
   virtual void setNumPoints
      (
      EcU32 num
      );

   /// default XML token
   virtual const EcToken& token
      (
      ) const;

   /// extract a feature histogram from a link
   virtual EcBoolean linkToFeatureHistogram
      (
      const EcManipulatorLink& link,
      EcShapeFeatureHistogram& featureHistogram
      ) const;

   /// extract a feature set from a link
   virtual EcBoolean linkToFeatureSet
      (
      const EcManipulatorLink& link,
      EcShapeFeatureSet& featureSet
      ) const;

   /// extract a feature histogram from a shape
   virtual EcBoolean shapeToFeatureHistogram
      (
      const EcShape& shape,
      EcShapeFeatureHistogram& featureHistogram
      ) const;

   /// extract a feature set from a shape
   virtual EcBoolean shapeToFeatureSet
      (
      const EcShape& shape,
      EcShapeFeatureSet& featureSet
      ) const;

protected:

   /// calculates the surface area of the shape
   virtual EcReal calculateSurfaceArea
      (
      const EcShape& shape
      ) const;

   /// calculate points and normals over the surface
   /// @return the number of points
   virtual EcU32 determinePointDistribution
      (
      const EcShape&  shape,
      EcVectorVector& pointVector,
      EcVectorVector& normalVector
      ) const;

   /// the number of bins along the angle (vertical) axis for histogram creation
   EcXmlU32     m_NumAngleBins;

   /// the number of bins along the distance (horizontal) axis for histogram creation
   EcXmlU32     m_NumDistanceBins;

   /// flag indicating if absolute angle method is being used for histogram creation
   EcXmlBoolean m_AbsoluteAngleFlag;

   /// the number of points used for feature set extraction
   EcXmlU32     m_NumPoints;
};

#endif // ecShapeMatchingAlgorithm_H_
