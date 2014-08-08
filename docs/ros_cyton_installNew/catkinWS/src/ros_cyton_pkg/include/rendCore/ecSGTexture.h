#ifndef ecSGTexture_H_
#define ecSGTexture_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSGTexture.h
/// @brief This class adds to the base EcTexture class to support
///        rendering using OpenSceneGraph.  It is mainly used to get
///        a handle to the texture data to populate the OSG structure
///        before being sent to the GPU.  It also sets texture state
///        information necessary for proper rendering.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <render/ecTexture.h>
#include <osg/ref_ptr>

// Forward declarations
class EcWindow;
namespace osg
{
   class StateSet;
   class Texture;
   class Image;
}

class EC_RENDER_RENDCORE_DECL EcSGTexture : public EcTexture
{
public:
   EcSGTexture
      (
      );

   EcSGTexture
      (
      const EcSGTexture &orig
      );

   virtual ~EcSGTexture
      (
      );

   virtual EcSGTexture &operator=
      (
      const EcSGTexture &orig
      );

   virtual EcBoolean operator==
      (
      const EcSGTexture &orig
      ) const;

   /// Default data orientation for files is TopToBottom
   virtual EcBoolean loadFromFile
      (
      const EcString &fileName,
      const EcTextureParameters &params = EcTextureParameters(),
      const EcImage::Orientation orient = EcImage::TopToBottom
      );

   virtual void setWidth
      (
      const EcU32 width
      );

   virtual void setHeight
      (
      const EcU32 height
      );

   virtual osg::StateSet *getState
      (
      ) const;

   virtual osg::Texture *getTexture
      (
      ) const;

   /// Should be called on window closure to free up texture entries.
   static void removeTexturesFromContext
      (
      const EcWindow *win
      );

protected:
   /// Determines whether the image is a POT or we can support in hardware.
   virtual EcBoolean calculatePOT
      (
      const EcU32 width,
      const EcU32 height
      );

   /// Internal routine for loading data onto the GPU
   virtual EcBoolean load
      (
      const EcU8 *data = EcNULL,
      const EcU32 sizeOfData = 0
      );

   /// Handle to OSG node that encompasses texture and state.
   osg::ref_ptr<osg::StateSet> m_rStateSet;

   /// Handle to internal texture object.
   osg::ref_ptr<osg::Texture> m_rTexture;

   /// This pairing will uniquely identify a texture filename per-context.
   typedef std::pair<const EcWindow *, EcString> ContextTextureFilename;
   /// This map will hold all of the textures loaded for each pair.
   typedef std::map<ContextTextureFilename, osg::ref_ptr<osg::Texture> > TextureMap;
   /// Global list of loaded textures.
   static TextureMap s_LoadedTextures;
};

#endif // ecSGTexture_H_
