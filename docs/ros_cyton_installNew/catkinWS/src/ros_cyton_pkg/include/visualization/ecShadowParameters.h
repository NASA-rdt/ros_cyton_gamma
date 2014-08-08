#ifndef ecShadowParameters_H_
#define ecShadowParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecShadowParameters.h
/// @class EcShadowParameters
/// @brief Holds a description of shadow parameters for viewing the system.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLight.h"
#include <xml/ecXmlCompType.h>

/// Enum holding the available shadow rendering techniques
namespace EcShadow
{
	/// the osg shadow technques available
   enum ShadowTechniqueType
   {
      ShadowMap,
      SoftShadowMap,
      LightSpacePerspectiveShadowMap,
      //..
      NoShadow
   };

   /// Method to return shadow technique name from enum value
   EC_FOUNDATION_VISUALIZATION_DECL EcString shadowTechniqueName(ShadowTechniqueType type);

}

/// Holds a description of shadow parameters for viewing the system.
class EC_FOUNDATION_VISUALIZATION_DECL EcShadowParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShadowParameters
      (
      );

   /// destructor
   virtual ~EcShadowParameters
      (
      );

   /// copy constructor
   EcShadowParameters
      (
      const EcShadowParameters& orig
      );

   /// assignment operator
   EcShadowParameters& operator=
      (
      const EcShadowParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShadowParameters& orig
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

   /// gets the available shadow techniques
   virtual const std::vector<EcShadow::ShadowTechniqueType>&  shadowTechniquesAvailable
      (
      ) const;

   /// gets the available shadow techniques
   virtual const std::vector<EcU32>&  shadowTextureSizesAvailable
      (
      ) const;

   /// gets the shadow technique enum value
   virtual EcU32 shadowTechnique
      (
      ) const;

   /// sets the shadow technique enum value
   /// returns true if set
   virtual EcBoolean setShadowTechnique
      (
      EcU32 shadowTechnique
      );

   /// gets the shadow texture size
   virtual EcU32 shadowTextureSize
      (
      ) const;

   /// sets the shadow texture size
   virtual EcBoolean setShadowTextureSize
      (
        EcU32 shadowTextureSize
      );

   /// sets the abient bias (only avialable on ShadowMap and SoftShadowMap)
   virtual void setAmbientBias
      (
      EcReal value
      );

   /// gets the abient bias (only avialable on ShadowMap and SoftShadowMap)
   virtual EcReal ambientBias
      (
      ) const;

   /// sets the softness width (only avialable on SoftShadowMap)
   virtual void setSoftnessWidth
      (
      EcReal width
      );

   /// gets the softness width (only avialable on SoftShadowMap)
   virtual EcReal softnessWidth
      (
      ) const;

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
   static EcShadowParameters nullObject
      (
      );

   /// create an object with default values
   static EcShadowParameters defaultObject
      (
      );

protected:
   /// Shadow Technique
   EcXmlU32             m_ShadowTechnique;

   /// Texture Size for Shadows
   EcXmlU32             m_ShadowTextureSize;

   /// AbientBias
   EcXmlReal            m_AmbientBias;

   /// Softness width
   EcXmlReal                   m_SoftnessWidth;

   /// Vector of available shadow techniques
   std::vector<EcShadow::ShadowTechniqueType>    m_ShadowTechniqueVec;
   
   /// Vector of available texture sizes
   std::vector<EcU32>    m_TextureSizeVec;
};

#endif // ecShadowParameters_H_
