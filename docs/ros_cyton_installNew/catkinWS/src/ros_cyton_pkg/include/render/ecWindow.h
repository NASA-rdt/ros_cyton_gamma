#ifndef ecWindow_H_
#define ecWindow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecWindow.h
/// @class EcWindow
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <foundCommon/ecColor.h>
#include <boost/weak_ptr.hpp>

// Forward declarations
class EcImage;
class EcImageBlock;

class EC_SENSOR_RENDER_DECL EcWindow
{
public:
   /// Bit fields used to determine image capture type and orientation
   enum CaptureTypeEnum
   {
      //----------------------------------------------------------------------
      CaptureImageColor      = 0x1, ///< Capture EcU8 RGB color values
      CaptureImageDepth      = 0x2, ///< Capture EcU8 normalized depth values
      //----------------------------------------------------------------------
      CaptureTopToBottom     = 0x4, ///< Capture with origin at top-left
      CaptureBottomToTop     = 0x8, ///< Capture with origin at bottom-left
      CaptureImageDepthDistance = 0x16, ///< Capture depth convert to distance
      //----------------------------------------------------------------------
      /// Convenience enums.
      CaptureImageTypeMask   = CaptureImageColor  | CaptureImageDepth,
      CaptureFlippedTypeMask = CaptureTopToBottom | CaptureBottomToTop,
      CaptureFlippedDepth    = CaptureImageDepth  | CaptureBottomToTop,
      CaptureFlippedDepthDistance = CaptureImageDepthDistance  | CaptureBottomToTop,
      CaptureFlippedColor    = CaptureImageColor  | CaptureBottomToTop,
      /// OpenGL orientation is considered flipped compared to EcImage.
      CaptureFlipped         = CaptureBottomToTop,
   };
   typedef EcU32 CaptureMode; ///< Image capture bit fields.

   /// Enumeration of classes available.
   enum ImplType
   {
      ImplCocoa,              ///< OSX Cocoa implementation
      ImplQt,                 ///< Nokia Qt implementation
      ImplWin32,              ///< Win32 standard implementation
      ImplX11,                ///< X11 implementation
      ImplDefault             ///< Platform default (native)
   };

   class Impl;                ///< Forward declaration of implementation class.
   typedef boost::shared_ptr<Impl> SharedImpl;
   typedef boost::weak_ptr<Impl>   WeakImpl;

   /// Constructor
   EcWindow
      (
      );

   /// Destructor
   virtual ~EcWindow
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

   /// Gets inner window size, not including border.
   /// \param[out] width  Inner width of window.
   /// \param[out] height Inner height of window.
   void getWindowSize
      (
      EcU32& width,
      EcU32& height
      ) const;

   /// Sets window position of top-left corner.
   /// \param[in] posX      Number of pixels from the side of screen.
   /// \param[in] posY      Number of pixels down from top of screen.
   /// \param[in] render    Whether to redraw the scene.
   /// \return    EcBoolean Returns whether window parameters have changed.
   virtual EcBoolean setWindowPos
      (
      const EcU32 posX,
      const EcU32 posY,
      const EcBoolean render = EcTrue
      );

   /// Gets window position of top-left corner.
   /// \param[out] posX Number of pixels from the side of screen.
   /// \param[out] posY Number of pixels down from top of screen.
   void getWindowPos
      (
      EcU32& posX,
      EcU32& posY
      ) const;

   /// Sets both inner window size and top-left position.
   /// \param[in] width     Inner width of window.
   /// \param[in] height    Inner height of window.
   /// \param[in] posX      Number of pixels from the side of screen.
   /// \param[in] posY      Number of pixels down from top of screen.
   /// \return    EcBoolean Returns whether window parameters have changed.
   virtual EcBoolean setWindowSizeAndPos
      (
      const EcU32 width,
      const EcU32 height,
      const EcU32 posX,
      const EcU32 posY
      );

   /// Gets inner window size and top-left position.
   /// \param[out] width  Inner width of window.
   /// \param[out] height Inner height of window.
   /// \param[out] posX   Number of pixels from the side of screen.
   /// \param[out] posY   Number of pixels down from top of screen.
   void getWindowSizeAndPos
      (
      EcU32& width,
      EcU32& height,
      EcU32& posX,
      EcU32& posY
      ) const;

   /// Sets the title bar name for the window.
   /// \param[in] name String to place on titlebar.
   virtual void setName
      (
      const EcString& name
      );

   /// Retrieves the name of the window.
   /// \return const EcString String name from titlebar.
   virtual const EcString& getName
      (
      ) const;

   /// Sets background color for this window.
   /// \param[in] color EcColor to set the background to.
   void setBackgroundColor
      (
      const EcColor& color
      );

   /// Retrieves the currently set background color.
   /// \return const EcColor& Reference to current background color.
   const EcColor& backgroundColor
      (
      ) const;

   /// Set window to stay on top of all other windows at all times.
   /// \param[in] isTopMost Whether this window is setup to be topmost.
   virtual void setTopMost
      (
      const EcBoolean isTopMost
      );

   /// Retrieve window attribute determining if this window is topmost.
   /// \return EcBoolean EcTrue or EcFalse.
   virtual EcBoolean getTopMost
      (
      ) const;

   /// Controls whether the window has the visible attribute or not.
   /// \param[in] isHiding Whether this window is visible or not.
   virtual void setHideWindow
      (
      const EcBoolean isHiding
      );

   /// Retrieve window attribute determining if this window is visible.
   /// \return EcBoolean EcTrue or EcFalse.
   virtual EcBoolean getHideWindow
      (
      ) const;

   /// Controls whether the window is shown as fullscreen with no border.
   /// \param[in] isFull Whether this window is fullscreen or not
   virtual void setFullScreen
      (
      const EcBoolean isFull
      );

   /// Set window attribute determining stereo-capable support.
   virtual void setStereoSupported
      (
      ) const;

   /// Retrieve window attribute determining if this window is stereo-capable.
   /// \return EcBoolean EcTrue or EcFalse.
   virtual EcBoolean getStereoSupported
      (
      ) const;

   /// Allow one window to shader GL components with another.
   /// \param[in] win Window to pull(share) GL data with.
   /// \return EcBoolean Success or failure of sharing.
   virtual EcBoolean share
      (
      const EcWindow* win
      ) const;

   /// Returns the implementation of the window sharing OpenGL components.
   /// Only useful to check after initialization.
   /// \return SharedImpl Shared implementation or EcNULL if not sharing.
   virtual SharedImpl getShare
      (
      ) const;

   /// Returns the window that we are sharing OpenGL context with (if any).
   /// Only useful to check after initialization.
   /// \return EcWindow* Pointer to the shared window or EcNULL if not sharing.
   virtual const EcWindow* getShareWindow
      (
      ) const;

   /// Swaps front and back buffers if double buffered. No-op otherwise.
   virtual void swapBuffers
      (
      ) const;

   /// Make graphics commands operate on this window.
   virtual void makeCurrent
      (
      ) const;

   /// Next best thing to a destructor.  Put to pre-init state.
   virtual void closeWindow
      (
      );

   /// Sets the default implementation type to use.
   /// \param[in] type Platform-dependent implementation to use.
   static void setImplType
      (
      const ImplType type
      );

   /// Gets the default implementation type in use.
   /// \return ImplType Platform-dependent implementation in use.
   static ImplType getImplType
      (
      );

   /// Sets the lower level platform-dependent implementation type.
   /// Used to specifically set the type used.
   /// \param[in] impl Shared pointer to implementation.
   virtual void setImpl
      (
      SharedImpl impl
      );

   /// Retrieves the lower level platform-dependent implementation type.
   /// \return SharedImpl Pointer to implementation used.
   virtual SharedImpl getImpl
      (
      ) const;

   /// Retrieves currently active window.
   /// \return const EcWindow* Pointer to currently active window.
   static const EcWindow* getWindow
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

   /// Draw current data to the window.
   /// \param[in] swap      Whether to display results to screen after finished.
   /// \return    EcBoolean Success or failure of rendering.
   virtual EcBoolean renderScene
      (
      const EcBoolean swap = EcTrue
      ) = 0;

   /// Pass an image to the rendering window to display.
   /// \param[in] image     EcImage to display.
   /// \param[in] swap      Whether to refresh screen or not.
   /// \return    EcBoolean Success or failure of command.
   virtual EcBoolean setImageBuffer
      (
      const EcImage& image,
      const EcBoolean swap = EcTrue
      ) = 0;

   /// Draw the current scene and capture the results into an EcImage.
   /// Note: Currently only 8-bit RGB color or 8-bit depth supported.
   /// \param[in, out] image      Reference to location to store data.
   /// \param[in]    mode       Type and orientation of stored data.
   /// \param[in]    imageBlock Optional subset of screen area to capture.
   /// \return       EcBoolean  Success or failure of capture.
   virtual EcBoolean renderSceneAndCaptureImage
      (
      EcImage& image,
      const CaptureMode mode = CaptureFlippedColor,
      const EcImageBlock* const imageBlock = EcNULL
      ) = 0;

protected:
   EcColor   m_BackgroundColor; ///< Background color to paint window.
   EcBoolean m_TopMost;         ///< Attribute defining if set as topmost window.
   EcBoolean m_HideWindow;      ///< Attribute defining if window is visible.
   EcInt32   m_PosX;            ///< Location to place on screen from left.
   EcInt32   m_PosY;            ///< Location to place on screen from top.
   EcU32     m_Width;           ///< Actual rendering width of window (no border).
   EcU32     m_Height;          ///< Actual rendering hight of window (no border).
   EcString  m_Name;            ///< Name used to place on titlebar of window.
   EcBoolean m_Initialized;     ///< Attribute defining initialization status of window.

   /// Internal window implementation class.
   SharedImpl m_pImpl;
   /// Handle to another window to share context information.
   mutable WeakImpl m_pShareImpl;
   /// Flag indicating whether a stereo visual was selected.
   mutable EcBoolean m_IsStereoSupported;
   /// Handle to last window operated on.
   static const EcWindow* m_pCurrentWindow;
   /// Default implementation type to use.
   static ImplType s_ImplType;
};

#endif // ecWindow_H_
