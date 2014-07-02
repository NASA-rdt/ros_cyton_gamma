#ifndef ecMaterialProperties_H_
#define ecMaterialProperties_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecMaterialProperties.h
/// @class EcMaterialProperties
/// @brief Implementation of the EcMaterialProperties class. Describe the
///        surface properties of the object for rendering.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

#include <boost/scoped_ptr.hpp>
#include <osg/Vec4d>

// Forward declarations
namespace osg { class StateSet; }
class EcDataMap;
class EcDisplayOptions;
class EcSGTexture;

/** implementation of the EcMaterialProperties class. Describe the
    surface properties of the object for rendering.
*/
class EC_RENDER_RENDCORE_DECL EcMaterialProperties
{
public:
   /// constuctor
   EcMaterialProperties
      (
      );

   /// copy constuctor
   EcMaterialProperties
      (
      const EcMaterialProperties& orig
      );

   /// destructor
   virtual ~EcMaterialProperties
      (
      );

   /// assign
   EcMaterialProperties& operator=
      (
      const EcMaterialProperties& orig
      );

   /// equal
   EcBoolean operator==
      (
      const EcMaterialProperties& orig
      ) const;

   /// load material parameters from XML
   virtual void load
      (
      const EcDataMap& surface
      );

   /// set all the material parameters to the same r, g and b
   virtual void  set
      (
      EcReal r,
      EcReal g,
      EcReal b
      );

   /// get diffuse color
   virtual void getDiffuseColor
      (
      osg::Vec4f& diffColor
      ) const;

   /// get function for if Render Both Side
   virtual EcBoolean renderBothSides
      (
      ) const;

   //// set function for if Render Both Side
   virtual void setRenderBothSides
      (
      EcBoolean renderBothSides
      );

   virtual void setState
      (
      osg::StateSet* const stateSet
      ) const;

   EcBoolean hasNormalTexture
      (
      ) const;

protected:
   boost::scoped_ptr<EcSGTexture> m_pTexture;       ///< Base texture
   EcString m_TextureFileName;                      ///< Base texture filename
   boost::scoped_ptr<EcSGTexture> m_pNormalTexture; ///< Normal texture
   EcString m_NormalTextureFileName;                ///< Normal texture filename

   EcReal m_Shininess;          ///< Shininess component
   osg::Vec4d m_Ambient;        ///< Ambient color component
   osg::Vec4d m_Diffuse;        ///< Diffuse color component
   osg::Vec4d m_Specular;       /// Specular color component
   osg::Vec4d m_Emission;       /// Emissive color component
   EcBoolean m_RenderBothSides; ///< Whether to render both sides
   EcBoolean m_ColorModified;   ///< Whether to create OpenGL material
   osg::Vec4d m_DisplayColor;   ///< Temp variable
};

#endif // ecMaterialProperties_H_
