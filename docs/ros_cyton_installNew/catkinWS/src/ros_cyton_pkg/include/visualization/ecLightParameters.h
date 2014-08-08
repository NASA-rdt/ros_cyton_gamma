#ifndef ecLightParameters_H_
#define ecLightParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLightParameters.h
/// @class EcLightParameters
/// @brief Holds a description of light parameters for viewing the system.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLight.h"
#include <xml/ecXmlCompType.h>

/// Holds a description of light parameters for viewing the system.
class EC_FOUNDATION_VISUALIZATION_DECL EcLightParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLightParameters
      (
      );

   /// destructor
   virtual ~EcLightParameters
      (
      );

   /// copy constructor
   EcLightParameters
      (
      const EcLightParameters& orig
      );

   /// assignment operator
   EcLightParameters& operator=
      (
      const EcLightParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLightParameters& orig
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

   /// gets the lights
   virtual const EcLightVector& lights
      (
      ) const;

   /// sets the lights
   virtual void setLights
      (
      const EcLightVector& lights
      );

   /// gets the token
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
   static EcLightParameters nullObject
      (
      );

   /// create an object with default values
   static EcLightParameters defaultObject
      (
      );

protected:
   /// the control expression
   EcLightVector        m_Lights;
};

#endif // ecLightParameters_H_
