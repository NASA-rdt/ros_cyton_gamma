#ifndef ecShapeFeatureSet_H_
#define ecShapeFeatureSet_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeFeatureSet.h
/// @class EcShapeFeatureSet
/// @brief A set of features that define a shape for shape matching.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// A set of features that define a shape for shape matching.
class EC_ACTIN_GRASPING_DECL EcShapeFeatureSet : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShapeFeatureSet
      (
      );

   /// destructor
   virtual ~EcShapeFeatureSet
      (
      );

   /// copy constructor
   EcShapeFeatureSet
      (
      const EcShapeFeatureSet& orig
      );

   /// assignment operator
   EcShapeFeatureSet& operator=
      (
      const EcShapeFeatureSet& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeFeatureSet& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// read object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

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

   /// get the distance values of the feature set
   virtual const EcXmlRealVector& distanceValues
      (
      ) const;

   /// set the distance values of the feature set
   virtual void setDistanceValues
      (
      const EcXmlRealVector& values
      );

   /// get the angle values of the feature set
   virtual const EcXmlRealVector& angleValues
      (
      ) const;

   /// set the angle values of the feature set
   virtual void setAngleValues
      (
      const EcXmlRealVector& values
      );

   /// get the scale of the feature set (not equal to 1.0 when the data is normalized)
   virtual EcReal scale
      (
      ) const;

   /// get the flag indicating if the feature set is normalized
   virtual EcBoolean isNormalized
      (
      ) const;

   /// get the maximum distance from the non-normalized feature set
   virtual EcReal maxDistance
      (
      ) const;

   /// add a feature to the feature set
   virtual void addFeature
      (
      EcReal distance,
      EcReal angle
      );

   /// normalize the features
   virtual void normalize
      (
      );

   /// size of the feature set
   virtual EcU32 size
      (
      ) const;

   /// clear the feature set
   virtual void clear
      (
      );

   /// default XML token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// the distance values of the feature set (must be non-negative real number)
   EcXmlRealVector m_DistanceValues;

   /// the angle values of the feature set (must be in range -1.0 to 1.0)
   EcXmlRealVector m_AngleValues;

   /// the scale of the feature set (not equal to 1.0 when the data is normalized)
   EcXmlReal       m_Scale;

   /// flag indicating if the feature set is normalized
   EcXmlBoolean    m_IsNormalized;

   // non-XML data

   /// maximum distance from the non-normalized feature set
   EcReal          m_MaxDistance;
};

#endif // ecShapeFeatureSet_H_
