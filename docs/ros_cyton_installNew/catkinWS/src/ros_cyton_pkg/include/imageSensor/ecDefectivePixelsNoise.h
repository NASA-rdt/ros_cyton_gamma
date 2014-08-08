#ifndef ecDefectivePixelsNoise_H_
#define ecDefectivePixelsNoise_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecDefectivePixelsNoise.h
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecSensorNoise.h"

#include <xml/ecXmlPairType.h>
#include <xml/ecXmlVectorType.h>

/**
\class EcDefectivePixelsNoise
\brief A class describing the effect of defective pixels on an image sensor.

Defective pixels include "dead" pixels and "hot" pixels. Dead pixels have intensity of zero and appear black. Hot pixels have full intensity (for 8-bit, it's 255) and appear white.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcDefectivePixelsNoise : public EcSensorNoise
{
public:
   /// default constructor
   EcDefectivePixelsNoise
      (
      );

   /// destructor
   virtual ~EcDefectivePixelsNoise
      (
      );

   /// copy constructor
   EcDefectivePixelsNoise
      (
      const EcDefectivePixelsNoise& orig
      );

   /// assignment operator
   EcDefectivePixelsNoise& operator=
      (
      const EcDefectivePixelsNoise& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDefectivePixelsNoise& orig
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
      const EcImageSensor& image
      );

   /// get the number of dead pixels
   virtual EcU32 numDeadPixels
      (
      ) const;

   /// set the number of dead pixels
   virtual void setNumDeadPixels
      (
      EcU32 numDeadPixels
      );

   /// get the number of hot pixels
   virtual EcU32 numHotPixels
      (
      ) const;

   /// set the number of hot pixels
   virtual void setNumHotPixels
      (
      EcU32 numHotPixels
      );

   /// get the locations of the dead pixels. Each location is described in a pair of X-Y coordinates with the origin at the top-left corner.
   virtual const EcXmlVectorType< EcXmlU32U32Pair >& deadPixelLocations
      (
      ) const;

   /// set the locations of the dead pixels. If these are not set, then they will be randomly generated when init() is called.
   virtual void setDeadPixelLocations
      (
      const EcXmlVectorType< EcXmlU32U32Pair >& locations
      );

   /// get the locations of the hot pixels. Each location is described in a pair of X-Y coordinates with the origin at the top-left corner.
   virtual const EcXmlVectorType< EcXmlU32U32Pair >& hotPixelLocations
      (
      ) const;

   /// set the locations of the hot pixels. If these are not set, then they will be randomly generated when init() is called.
   virtual void setHotPixelLocations
      (
      const EcXmlVectorType< EcXmlU32U32Pair >& locations
      );

   /// get a null object
   static EcDefectivePixelsNoise nullObject
      (
      );

   /// standard object
   static EcDefectivePixelsNoise defaultObject
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
   /// The number of dead pixels
   EcXmlU32          m_NumDeadPixels;

   /// The number of hot pixels
   EcXmlU32          m_NumHotPixels;

   /// The locations of the dead pixels
   EcXmlVectorType< EcXmlU32U32Pair >   m_vDeadPixelLocations;

   /// The locations of the hot pixels
   EcXmlVectorType< EcXmlU32U32Pair >   m_vHotPixelLocations;
};

#endif // ecDefectivePixelsNoise_H_
