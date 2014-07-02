#ifndef ecRenderParameters_H_
#define ecRenderParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderParameters.h
/// @class EcRenderParameters
/// @brief Holds parameters used for rendering, including lighting,
///        point of view, and rendering technical settings.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <foundCommon/ecColor.h>

/// Holds parameters used for rendering, including lighting, point of view, and rendering technical settings.
class EC_FOUNDATION_VISUALIZATION_DECL EcRenderParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcRenderParameters
      (
      );

   /// destructor
   virtual ~EcRenderParameters
      (
      );

   /// copy constructor
   EcRenderParameters
      (
      const EcRenderParameters& orig
      );

   /// assignment operator
   EcRenderParameters& operator=
      (
      const EcRenderParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRenderParameters& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject *clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject *other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject *newObject
      (
      ) const;

   /// gets the defaults flag
   virtual EcBoolean useDefaults
      (
      ) const;

   /// sets the defaults flag
   virtual void setUseDefaults
      (
      const EcBoolean useDefaults
      );

   /// gets the near clipping distance
   virtual EcReal nearClippingDistance
      (
      ) const;

   /// sets the near clipping distance
   virtual void setNearClippingDistance
      (
      const EcReal nearClippingDistance
      );

   /// gets the far clipping distance
   virtual EcReal farClippingDistance
      (
      ) const;

   /// sets the far clipping distance
   virtual void setFarClippingDistance
      (
      const EcReal farClippingDistance
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
   static EcRenderParameters nullObject
      (
      );

   /// get function for background color
   virtual const EcColor& backgroundColor
      (
      ) const;

   /// set the background color
   virtual void setBackgroundColor
      (
      const EcColor &color
      );

   /// get function for ambient intensity
   virtual const EcColor& ambientIntensity
      (
      ) const;

   /// set the ambient intensity
   virtual void setAmbientIntensity
      (
      const EcColor &intensity
      );

   /// gets the zBuffer flag
   EcBoolean zBufferFlag
      (
      ) const;

   /// sets the zBuffer Flag
   void setZBufferFlag
      (
      const EcBoolean zBufferFlag
      );

protected:
   /// a flag indicating that defaults (calculated from the
   /// location of the center of interest) should be used
   EcXmlBoolean   m_UseDefaults;

   /// distance to the near clipping plane.  Used only if defaults
   /// are turned off.
   EcXmlReal      m_NearClippingDistance;

   /// distance to the far clipping plane.  Used only if defaults
   /// are turned off.
   EcXmlReal      m_FarClippingDistance;

   /// back ground color
   EcColor        m_BackgroundColor;

   /// Ambient lighting - default is (.5,.5,.5,.5)
   EcColor        m_AmbientIntensity;

   /// if get depth
   EcXmlBoolean   m_ZBufferFlag;
};

#endif // ecRenderParameters_H_
