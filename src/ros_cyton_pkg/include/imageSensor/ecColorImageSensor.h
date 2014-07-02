#ifndef ecColorImageSensor_H_
#define ecColorImageSensor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecColorImageSensor.h
/// @class EcColorImageSensor
/// @brief A concrete class describing a color image sensor.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecImageSensor.h"
#include "ecColorImageSensorDescriptor.h"

/**
\class EcColorImageSensor
\brief A concrete class describing a color image sensor.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcColorImageSensor : public EcImageSensor
{
public:
   /// default constructor
   EcColorImageSensor
      (
      );

   /// constructor with values
   EcColorImageSensor
      (
      EcU32 pixelWidth,
      EcU32 pixelHeight,
      EcReal frameRate
      );

   /// destructor
   virtual ~EcColorImageSensor
      (
      );

   /// copy constructor
   EcColorImageSensor
      (
      const EcColorImageSensor& orig
      );

   /// assignment operator
   EcColorImageSensor& operator=
      (
      const EcColorImageSensor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcColorImageSensor& orig
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

   /// get the descriptor for the image sensor
   virtual const EcColorImageSensorDescriptor& descriptor
      (
      ) const;

   /// set the descriptor for the image sensor
   virtual void setDescriptor
      (
      const EcColorImageSensorDescriptor& descriptor
      );

   /// return false since noise is not applicable for this type of image sensor
   virtual EcBoolean isNoiseApplicable
      (
      ) const;

   /// get a null object
   static EcColorImageSensor nullObject
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

   /// color image descriptor
   EcColorImageSensorDescriptor m_Descriptor;
};

#endif // ecColorImageSensor_H_
