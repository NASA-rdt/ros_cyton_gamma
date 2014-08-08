#ifndef ecFixedPatternNoise_H_
#define ecFixedPatternNoise_H_

//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecFixedPatternNoise.h
/// @class EcFixedPatternNoise
/// @brief A class representing fixed pattern noise in an image sensor.
/// @details Fixed pattern noise is characterized by having additive or subtractive effects on the intensity of each channel.
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecSensorNoise.h"

#include <xml/ecXmlPairType.h>
#include <xml/ecXmlVectorType.h>

/// a 2D XML vector of Int16 
typedef EcXmlVectorType< EcXmlInt16Vector > EcXmlInt16VectorVector;


class EC_FOUNDATION_IMAGESENSOR_DECL EcFixedPatternNoise : public EcSensorNoise
{
public:
   /// default constructor
   EcFixedPatternNoise
      (
      );

   /// destructor
   virtual ~EcFixedPatternNoise
      (
      );

   /// copy constructor
   EcFixedPatternNoise
      (
      const EcFixedPatternNoise& orig
      );

   /// assignment operator
   EcFixedPatternNoise& operator=
      (
      const EcFixedPatternNoise& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFixedPatternNoise& orig
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

   /// get the intensity magnitude of this noise. This is used to randomly generate the intensity variations. For each channel of each effected pixel, its intensity will be between the nominal intensity +/- this intensity magnitude. If the intensity variations are manually set, then this is not used.
   virtual EcU8 intensityMagnitude
      (
      ) const;

   /// set the intensity magnitude of this noise.
   virtual void setIntensityMagnitude
      (
      EcU8 intensityMagnitude
      );

   /// get the variations in the intensities of all channels of all effected pixels. The vector is of size numEffectedPixels() X EcImageSensor::numChannels(). These variations are generated when init() is called. Each of its elements is randomly generated between -intensityMagnitude() and +intensityMagnitude().
   virtual const EcXmlInt16VectorVector& intensityVariations
      (
      ) const;

   /// manually set the intensity variations.
   virtual void setIntensityVariations
      (
      const EcXmlInt16VectorVector& value
      );

   /// get a null object
   static EcFixedPatternNoise nullObject
      (
      );

   /// default object
   static EcFixedPatternNoise defaultObject
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

   /// The variations from the normal intensities of the effected pixels. This vector is of size m_NumEffectedPixels X EcImageSensor::numChannels()
   EcXmlInt16VectorVector     m_vvPixelIntensityVariations;
};

#endif // ecFixedPatternNoise_H_
