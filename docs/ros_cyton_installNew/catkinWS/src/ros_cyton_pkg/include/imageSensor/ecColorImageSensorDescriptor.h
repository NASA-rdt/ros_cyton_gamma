#ifndef ecColorImageSensorDescriptor_H_
#define ecColorImageSensorDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecColorImageSensorDescriptor.h
/// @class EcColorImageSensorDescriptor
/// @brief A class describing the color part of an image sensor.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/**
\class EcColorImageSensorDescriptor
\brief A class describing the color part of an image sensor.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcColorImageSensorDescriptor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcColorImageSensorDescriptor
      (
      );

   /// destructor
   virtual ~EcColorImageSensorDescriptor
      (
      );

   /// copy constructor
   EcColorImageSensorDescriptor
      (
      const EcColorImageSensorDescriptor& orig
      );

   /// assignment operator
   EcColorImageSensorDescriptor& operator=
      (
      const EcColorImageSensorDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcColorImageSensorDescriptor& orig
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
   static EcColorImageSensorDescriptor nullObject
      (
      );

protected:
   /// the view distance
   EcXmlReal m_ViewDistance;
};

#endif // ecColorImageSensorDescriptor_H_
