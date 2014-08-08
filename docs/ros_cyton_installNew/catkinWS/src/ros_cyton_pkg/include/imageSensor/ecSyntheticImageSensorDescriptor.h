#ifndef ecSyntheticImageSensorDescriptor_H_
#define ecSyntheticImageSensorDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSyntheticImageSensorDescriptor.h
/// @class EcSyntheticImageSensorDescriptor
/// @brief A class describing the "synthetic" or "virtual" part of
///        an image sensor.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/**
\class EcSyntheticImageSensorDescriptor
\brief A class describing the "synthetic" or "virtual" part of an image sensor.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcSyntheticImageSensorDescriptor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSyntheticImageSensorDescriptor
      (
      );

   /// destructor
   virtual ~EcSyntheticImageSensorDescriptor
      (
      );

   /// copy constructor
   EcSyntheticImageSensorDescriptor
      (
      const EcSyntheticImageSensorDescriptor& orig
      );

   /// assignment operator
   EcSyntheticImageSensorDescriptor& operator=
      (
      const EcSyntheticImageSensorDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSyntheticImageSensorDescriptor& orig
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

   /// get the view distance
   virtual EcReal viewDistance
      (
      ) const;

   /// set the view distance
   virtual void setViewDistance
      (
      EcReal distance
      );

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// get a null object
   static EcSyntheticImageSensorDescriptor nullObject
      (
      );

   /// standard object
   static EcSyntheticImageSensorDescriptor defaultObject
      (
      );

protected:
   /// the view distance
   EcXmlReal      m_ViewDistance;
};

#endif // ecSyntheticImageSensorDescriptor_H_
