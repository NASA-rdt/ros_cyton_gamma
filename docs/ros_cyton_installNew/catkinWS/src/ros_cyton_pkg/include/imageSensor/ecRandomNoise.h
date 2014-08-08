#ifndef ecRandomNoise_H_
#define ecRandomNoise_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRandomNoise.h
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecSensorNoise.h"

/**
\class EcRandomNoise
\brief A class representing fixed pattern noise in an image sensor.

Fixed pattern noise is characterized by having additive or subractive effects on the intensity of each channel.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcRandomNoise : public EcSensorNoise
{
public:
   /// default constructor
   EcRandomNoise
      (
      );

   /// destructor
   virtual ~EcRandomNoise
      (
      );

   /// copy constructor
   EcRandomNoise
      (
      const EcRandomNoise& orig
      );

   /// assignment operator
   EcRandomNoise& operator=
      (
      const EcRandomNoise& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRandomNoise& orig
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

   /// initialize the noise's internal properties. Should be called after all parameters have been set.
   virtual void init
      (
      const EcImageSensor& imageSensor
      );

   /// get the intensity magnitude of this noise. For each channel of each effected pixel, its intensity will be between the nominal intensity +/- this intensity magnitude.
   virtual EcU8 intensityMagnitude
      (
      ) const;

   /// set the intensity magnitude of this noise.
   virtual void setIntensityMagnitude
      (
      EcU8 intensityMagnitude
      );

   /// get a null object
   static EcRandomNoise nullObject
      (
      );

   /// standard object
   static EcRandomNoise defaultObject
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
   /// The magnitude of intensity that could be added to or subtracted from the intensity of each channel of each effected pixel
   EcXmlU8           m_IntensityMagnitude;
};

#endif // ecRandomNoise_H_
