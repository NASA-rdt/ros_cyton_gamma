#ifndef ecSimpleWindow_H_
#define ecSimpleWindow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimpleWindow.h
/// @class EcSimpleWindow
/// @brief EcSimpleWindow creates a window that can be used to display an
///        EcImage.
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecWindow.h"
#include <foundCore/ecMacros.h>
#include <boost/shared_ptr.hpp>

/// Forward declarations.
class EcImage;
class EcTexture;
typedef boost::shared_ptr<EcTexture> SharedTex;

class EC_SENSOR_RENDER_DECL EcSimpleWindow : public EcWindow
{
public:
   /// Constructor
   EcSimpleWindow
      (
      );

   /// Destructor
   virtual ~EcSimpleWindow
      (
      );

   ///////////////////////////////////////////////////////////////////////////
   /// Pre-init routines.  These methods are allowed before window          //
   /// initialization.                                                      //
   ///////////////////////////////////////////////////////////////////////////

   /// Sets inner window size, not including border.
   /// \param[in] width     Inner width of window.
   /// \param[in] height    Inner height of window.
   /// \return    EcBoolean Returns whether window parameters have changed.
   virtual EcBoolean setWindowSize
      (
      const EcU32 width,
      const EcU32 height
      );

   /// Clear rendering buffer.
   virtual void clear
      (
      ) const;

   /// Next best thing to a destructor.  Put to pre-init state.
   virtual void closeWindow
      (
      );

   ///////////////////////////////////////////////////////////////////////////
   /// Init and post-init routines.  These methods either initialize        //
   /// or force initialization when called.                                 //
   ///////////////////////////////////////////////////////////////////////////

   /// Initializes window and displays if necessary.
   /// \return EcBoolean Success or failure of initialization.
   virtual EcBoolean init
      (
      );

   /// Give the ability to create an image and relinquish control to user.
   /// \param[in] image     EcImage to display.
   /// \param[in] duration  Length of time to keep window up.  Default is 2 seconds.
   /// \param[in] title     EcString to put in titlebar.  Default is EcSimpleWindow.
   /// \param[in] posX      Location to place window in X.  Default is 0.
   /// \param[in] posY      Location to place window in Y.  Default is 0.
   /// \return    EcBoolean Success or failure of command.
   static EcBoolean displayImage
      (
      const EcImage &image,
      const EcReal duration = 2.0,
      const EcString& title = "EcSimpleWindow",
      const EcU32 posX = 0,
      const EcU32 posY = 0
      );

   /// Pass an image to the rendering window to display.
   /// \param[in] image     EcImage to display.
   /// \param[in] swap      Whether to refresh screen or not.
   /// \return    EcBoolean Success or failure of command.
   virtual EcBoolean setImageBuffer
      (
      const EcImage &image,
      const EcBoolean swap = EcTrue
      );

   /// Pass an image to the rendering window to display.
   /// \param[in] tex       EcTexture to display.
   /// \param[in] swap      Whether to refresh screen or not.
   /// \return    EcBoolean Success or failure of command.
   virtual EcBoolean setImageBuffer
      (
      SharedTex tex,
      const EcBoolean swap = EcTrue
      );

   /// Draw current data to the window.
   /// \param[in] swap      Whether to display results to screen after finished.
   /// \return    EcBoolean Success or failure of rendering.
   virtual EcBoolean renderScene
      (
      const EcBoolean swap = EcTrue
      );

   /// Draw the current scene and capture the results into an EcImage.
   /// Note: Currently only 8-bit RGB color or 8-bit depth supported.
   /// \param[in, out] image      Reference to location to store data.
   /// \param[in]    mode       Type and orientation of stored data.
   /// \param[in]    imageBlock Optional subset of screen area to capture.
   /// \return       EcBoolean  Success or failure of capture.
   virtual EcBoolean renderSceneAndCaptureImage
      (
      EcImage &image,
      const CaptureMode mode = CaptureFlippedColor,
      const EcImageBlock *const imageBlock = EcNULL
      );

protected:
   /// Setup orthographic projection viewing matrix.
   virtual void setGLOrtho
      (
      ) const;

   /// Used for 2D display of images.
   SharedTex m_pTex;
};

#endif // ecSimpleWindow_H_
