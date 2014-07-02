#ifndef ec_RenderHUD_H_
#define ec_RenderHUD_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderHUD.h
/// @class Ec::RenderHUD
/// @brief Utility to manage a 2D orthographic Heads-Up Display for
///        overlay text and symbology
//
//------------------------------------------------------------------------------
#include <render/render_config.h>
#include <foundCore/ecTypes.h>

#include <osg/Camera>

namespace osgText { class Font; class Text; }

namespace Ec
{

class EC_RENDER_RENDCORE_DECL RenderHUD : public osg::Camera
{
public:
   RenderHUD
      (
      const EcU32 width,
      const EcU32 height
      );

   osgText::Text* setOverlayText
      (
      const EcString& str, ///< [in] String to display
      const EcU32 x,       ///< [in] Screen X coordinate from left
      const EcU32 y,       ///< [in] Screen Y coordinate from bottom
      const EcU32 size        = 30, ///< [in] Pixel size of text
      const osg::Vec4f& color = osg::Vec4f(1,1,1,1) ///< [in] Color of text
      );

   void clearOverlayText
      (
      osgText::Text* text
      );

   void clearAllOverlayText
      (
      );

   void resize
      (
      const EcU32 width,
      const EcU32 height
      );

protected:
   // Safeguard against stack allocation
   ~RenderHUD
      (
      );

   EcU32 m_Height;
   osgText::Font* m_pFont;
};

} // namespace Ec

#endif // ec_RenderHUD_H_
