#ifndef ecImageRegion_H_
#define ecImageRegion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageRegion.h
/// @class EcImageRegion
/// @brief Holds a description of a rectangular region in an image.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImageRectangle.h"
#include <xml/ecXmlCompType.h>

/// Holds a description of a rectangular region in an image.
class EC_SENSOR_SENSCORE_DECL EcImageRegion : public EcXmlCompoundType
{
public:
   /// default constructor
   EcImageRegion
      (
      );

   /// destructor
   virtual ~EcImageRegion
      (
      );

   /// copy constructor
   EcImageRegion
      (
      const EcImageRegion& orig
      );

   /// assignment operator
   EcImageRegion& operator=
      (
      const EcImageRegion& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImageRegion& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// get bounding rectangle
   virtual const EcImageRectangle&  boundingRectangle
      (
      ) const;

   /// set bounding rectangle
   virtual void setBoundingRectangle
      (
      const EcImageRectangle&  boundingRectangle
      );

   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcImageRegion nullObject
      (
      );

protected:
   /// the two corners
   EcImageRectangle  m_BoundingRectangle;
};

#endif // ecImageRegion_H_
