#ifndef render_config_H_
#define render_config_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file render_config.h
/// @brief Configuration header for the render hierarchy.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>

/// Specify an overall define to see if render is being built dynamically.
#if defined(EC_BUILD_SHARED_LIBS)
#  define EC_RENDER_CONVERT_DYNAMIC_LIBS
#  define EC_RENDER_GUICORE_DYNAMIC_LIBS
#  define EC_RENDER_IMAGESENSORDISPLAY_DYNAMIC_LIBS
#  define EC_RENDER_RENDERIMAGE_DYNAMIC_LIBS
#  define EC_RENDER_RENDCORE_DYNAMIC_LIBS
#endif // defined(EC_BUILD_SHARED_LIBS)

/// convert directory
#if defined(EC_RENDER_CONVERT_DYNAMIC_LIBS)
#  if defined(render_convert_EXPORTS)
#    define EC_RENDER_CONVERT_DECL               EC_DECL_EXPORTS
#  else
#    define EC_RENDER_CONVERT_DECL               EC_DECL_IMPORTS
#  endif
#else  // defined(EC_RENDER_CONVERT_DYNAMIC_LIBS)
#  define EC_RENDER_CONVERT_DECL
#endif // defined(EC_RENDER_CONVERT_DYNAMIC_LIBS)

/// guiCore directory
#if defined(EC_RENDER_GUICORE_DYNAMIC_LIBS)
#  if defined(render_guiCore_EXPORTS)
#    define EC_RENDER_GUICORE_DECL               EC_DECL_EXPORTS
#  else
#    define EC_RENDER_GUICORE_DECL               EC_DECL_IMPORTS
#  endif
#else  // defined(EC_RENDER_GUICORE_DYNAMIC_LIBS)
#  define EC_RENDER_GUICORE_DECL
#endif // defined(EC_RENDER_GUICORE_DYNAMIC_LIBS)

/// imageSensorDisplay directory
#if defined(EC_RENDER_IMAGESENSORDISPLAY_DYNAMIC_LIBS)
#  if defined(render_imageSensorDisplay_EXPORTS)
#    define EC_RENDER_IMAGESENSORDISPLAY_DECL    EC_DECL_EXPORTS
#  else
#    define EC_RENDER_IMAGESENSORDISPLAY_DECL    EC_DECL_IMPORTS
#  endif
#else  // defined(EC_RENDER_IMAGESENSORDISPLAY_DYNAMIC_LIBS)
#  define EC_RENDER_IMAGESENSORDISPLAY_DECL
#endif // defined(EC_RENDER_IMAGESENSORDISPLAY_DYNAMIC_LIBS)

/// renderImage directory
#if defined(EC_RENDER_RENDERIMAGE_DYNAMIC_LIBS)
#  if defined(render_renderImage_EXPORTS)
#    define EC_RENDER_RENDERIMAGE_DECL           EC_DECL_EXPORTS
#  else
#    define EC_RENDER_RENDERIMAGE_DECL           EC_DECL_IMPORTS
#  endif
#else  // defined(EC_RENDER_RENDERIMAGE_DYNAMIC_LIBS)
#  define EC_RENDER_RENDERIMAGE_DECL
#endif // defined(EC_RENDER_RENDERIMAGE_DYNAMIC_LIBS)

/// rendCore directory
#if defined(EC_RENDER_RENDCORE_DYNAMIC_LIBS)
#  if defined(render_rendCore_EXPORTS)
#    define EC_RENDER_RENDCORE_DECL              EC_DECL_EXPORTS
#  else
#    define EC_RENDER_RENDCORE_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_RENDER_RENDCORE_DYNAMIC_LIBS)
#  define EC_RENDER_RENDCORE_DECL
#endif // defined(EC_RENDER_RENDCORE_DYNAMIC_LIBS)

#endif // render_config_H_
