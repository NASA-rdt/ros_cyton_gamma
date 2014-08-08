#ifndef ecSensorNoise_H_
#define ecSensorNoise_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecSensorNoise.h
/// @class EcSensorNoise
/// @brief Base Class of image sensor noise.
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

class EcImageSensor;

class EC_FOUNDATION_IMAGESENSOR_DECL EcSensorNoise : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSensorNoise
      (
      );

   /// destructor
   virtual ~EcSensorNoise
      (
      );

   /// copy constructor
   EcSensorNoise
      (
      const EcSensorNoise& orig
      );

   /// assignment operator
   EcSensorNoise& operator=
      (
      const EcSensorNoise& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSensorNoise& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const=0;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const=0;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const=0;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const=0;

   /// get the string label for the type of noise processor
   virtual const EcString& processorType
      (
      ) const;

   /// initialize the noise's internal properties. Should be called after all parameters have been set.
   virtual void init
      (
      const EcImageSensor& imageSensor
      )=0;

protected:
   /// the type of the processor associated with this sensor noise
   EcXmlString       m_ProcessorType;
};

#endif // ecSensorNoise_H_
