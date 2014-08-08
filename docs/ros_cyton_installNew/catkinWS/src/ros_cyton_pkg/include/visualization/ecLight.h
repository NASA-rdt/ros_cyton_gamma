#ifndef ecLight_H_
#define ecLight_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLight.h
/// @class EcLight
/// @brief Holds a description of a light.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecColor.h>
#include <foundCommon/ecCoordSysXForm.h>

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlPairType.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecXmlVector.h>

/// Holds a description of a light.
class EC_FOUNDATION_VISUALIZATION_DECL EcLight : public EcXmlCompoundType
{
public:

   /// Macro to create all the necessary virtual methods for EcXmlObjects
   ECXMLOBJECT(EcLight);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the light name
   virtual const EcString& name
      (
      ) const;

   /// sets the light name
   virtual void setName
       (
       EcString name
       );

   /// gets the is-on flag
   virtual EcBoolean isOn
      (
      ) const;

   /// sets the is-on flag
   virtual void setIsOn
      (
      EcBoolean isOn=EcTrue
      );

   /// gets the light-at-eye flag
   virtual EcBoolean lightAtEye
      (
      ) const;

   /// sets the light-at-eye flag
   virtual void setLightAtEye
      (
      EcBoolean lightAtEye=EcTrue
      );

   /// gets the used for shadows flag
   virtual EcBoolean usedForShadows
      (
      ) const;

   /// sets the used for shadows flag
   virtual void setUsedForShadows
      (
      EcBoolean usedForShadows=EcFalse
      );

   /// gets ambient value
   virtual const EcColor& ambient
      (
      ) const;

   /// sets the ambient value
   virtual void setAmbient
      (
      const EcColor& ambient
      );

   /// gets diffuse value
   virtual const EcColor& diffuse
      (
      ) const;

   /// sets the diffuse value
   virtual void setDiffuse
      (
      const EcColor& diffuse
      );

   /// gets specular value
   virtual const EcColor& specular
      (
      ) const;

   /// sets the specular value
   virtual void setSpecular
      (
      const EcColor& specular
      );

   /// gets the position
   virtual const EcVector& position
      (
      ) const;

   /// sets the position
   virtual void setPosition
      (
      const EcVector& position
      );

   /// gets the coordinate system tranformation of the light
   virtual const EcCoordinateSystemTransformation& coordSysXform
      (
      ) const;

   /// sets the coordinate system tranformation of the light
   virtual void setCoordSysXform
      (
           const EcCoordinateSystemTransformation&
      );

   /// gets the is-positional flag
   virtual EcBoolean isPositional
      (
      ) const;

   /// sets the is-positional flag
   virtual void setIsPositional
      (
      EcBoolean isPositional=EcTrue
      );

   /// gets the manipulator and link attachment names
   virtual EcStringStringPair attachmentIdentifiers
      (
      ) const;

   /// sets the manipulator and link attachment names
   virtual void setAttachmentIdentifiers
      (
      const EcXmlStringStringPair& identifiers
      );

   /// gets the spot direction
   virtual const EcVector& spotDirection
      (
      ) const;

   /// sets the spot direction
   virtual void setSpotDirection
      (
      const EcVector& spotDirection
      );

   /// gets the spot exponent
   virtual EcReal spotExponent
      (
      ) const;

   /// sets the spot exponent
   virtual void setSpotExponent
      (
      EcReal spotExponent
      );

   /// gets the spot cutoff
   virtual EcReal spotCutoff
      (
      ) const;

   /// sets the spot cutoff
   virtual void setSpotCutoff
      (
      EcReal spotCutoff
      );

   /// gets the constant attenuation
   virtual EcReal constantAttenuation
      (
      ) const;

   /// sets the constant attenuation
   virtual void setConstantAttenuation
      (
      EcReal constantAttenuation
      );

   /// gets the linear attenuation
   virtual EcReal linearAttenuation
      (
      ) const;

   /// sets the linear attenuation
   virtual void setLinearAttenuation
      (
      EcReal linearAttenuation
      );

   /// gets the quadratic attenuation
   virtual EcReal quadraticAttenuation
      (
      ) const;

   /// sets the quadratic attenuation
   virtual void setQuadraticAttenuation
      (
      EcReal quadraticAttenuation
      );

   /// get a null object
   static EcLight nullObject
      (
      );

   /// create an object with default values
   static EcLight defaultObject
      (
      );

protected:
   /// the unique name of the light
   EcXmlString      m_Name;

   /// a flag indicating whether or not this light is on
   EcXmlBoolean     m_IsOn;

   /// a flag indicating if is this light is located at the eyepoint
   EcXmlBoolean     m_LightAtEye;

   /// a flag indicating if is this light is used to render shadows
   EcXmlBoolean     m_UsedForShadows;

   /// ambient intensities of the light
   EcColor          m_Ambient;

   /// diffuse intensities of the light
   EcColor          m_Diffuse;

   /// specular intensities of the light
   EcColor          m_Specular;

   /// position of the light (if not at eye)
   EcXmlVector      m_Position;

   /// the coordinate system transform of the light
   EcCoordinateSystemTransformation m_CoordSysXform;

   /// Manipulator and link attachment information
   EcXmlStringStringPair m_AttachmentIdentifiers;

   /// a flag indicating if the light is a point light
   /// (as opposed to directional)
   EcXmlBoolean     m_IsPositional;

   /// the direction of a spotlight (if directional)
   EcXmlVector      m_SpotDirection;

   /// the decay exponent on the spot
   EcXmlReal        m_SpotExponent;

   /// cutoff for the spot
   EcXmlReal        m_SpotCutoff;

   /// constant attenuation term
   EcXmlReal        m_ConstantAttenuation;

   /// linear attenuation term
   EcXmlReal        m_LinearAttenuation;

   /// quadratic attenuation term
   EcXmlReal        m_QuadraticAttenuation;
};

/// a vector of lights
typedef EcXmlVectorType<EcLight> EcLightVector;

#endif // ecLight_H_
