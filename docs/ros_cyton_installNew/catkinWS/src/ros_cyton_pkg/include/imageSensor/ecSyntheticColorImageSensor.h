#ifndef ecSyntheticColorImageSensor_H_
#define ecSyntheticColorImageSensor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSyntheticColorImageSensor.h
/// @class EcSyntheticColorImageSensor
/// @brief A concrete class describing a "synthetic" or "virtual"
///        color image sensor.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecColorImageSensor.h"
#include "ecSyntheticImageSensorDescriptor.h"

/**
\class EcSyntheticColorImageSensor
\brief A concrete class describing a "synthetic" or "virtual" color image sensor.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcSyntheticColorImageSensor : public EcColorImageSensor
{
public:
   /// default constructor
   EcSyntheticColorImageSensor
      (
      );

   /// constructor with values
   EcSyntheticColorImageSensor
      (
      EcU32 pixelWidth,
      EcU32 pixelHeight,
      EcReal frameRate
      );

   /// destructor
   virtual ~EcSyntheticColorImageSensor
      (
      );

   /// copy constructor
   EcSyntheticColorImageSensor
      (
      const EcSyntheticColorImageSensor& orig
      );

   /// assignment operator
   EcSyntheticColorImageSensor& operator=
      (
      const EcSyntheticColorImageSensor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSyntheticColorImageSensor& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// returns the token for this class
   virtual const EcToken& token
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

   /// get the "synthetic" part of the image sensor
   virtual const EcSyntheticImageSensorDescriptor& syntheticDescriptor
      (
      ) const;

   /// set the "synthetic" part of the image sensor
   virtual void setSyntheticDescriptor
      (
      const EcSyntheticImageSensorDescriptor& descriptor
      );

   /// return true since noise is applicable for this type of image sensor
   virtual EcBoolean isNoiseApplicable
      (
      ) const;

   /// get a null object
   static EcSyntheticColorImageSensor nullObject
      (
      );

   /// standard object
   static EcSyntheticColorImageSensor defaultObject
      (
      );

   /// token for this class
   /**
   \return a unique string token.
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return a pointer to a new'ed object.
   */
   static EcXmlObject* creator
      (
      );
protected:
   /// a synthetic image sensor descriptor
   EcSyntheticImageSensorDescriptor    m_SyntheticDescriptor;
};

#endif // ecSyntheticColorImageSensor_H_
