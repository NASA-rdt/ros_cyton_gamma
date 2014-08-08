#ifndef ecWindowImplCocoa_H_
#define ecWindowImplCocoa_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecWindowImplCocoa.h
/// @class EcWindow::Impl::Cocoa
/// @brief Cocoa-based version of window implementation.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecWindowImpl.h"

// Forward declare properly based on who includes us
#ifdef __OBJC__
@class NSAutoreleasePool;
@class NSOpenGLContext;
@class NSOpenGLPixelFormat;
@class NSView;
@class NSWindow;
#else
class NSAutoreleasePool;
class NSOpenGLContext;
class NSOpenGLPixelFormat;
class NSView;
class NSWindow;
#endif

class EcWindow::Impl::Cocoa : public EcWindow::Impl
{
public:
   Cocoa
      (
      );

   virtual ~Cocoa
      (
      );

   //////////////////////////////////////////////////////////////////
   // Pre-init routines.  These methods are allowed before window  //
   // initialization.                                              //
   //////////////////////////////////////////////////////////////////

   /// Sets the title bar name for the window.
   virtual void setName
      (
      const EcString &name
      );

   /// Mutator methods for setting window parameters
   virtual void setWindowSize
      (
      const EcU32 width,
      const EcU32 height
      );

   virtual void setWindowPos
      (
      const EcU32 posX,
      const EcU32 posY
      );

   virtual void setWindowSizeAndPos
      (
      const EcU32 width,
      const EcU32 height,
      const EcU32 posX,
      const EcU32 posY
      );

   /// set window to stay top most
   virtual void setTopMost
      (
      const EcBoolean topmost
      );

   /// Controls whether the window has the visible attribute or not.
   virtual void setHideWindow
      (
      const EcBoolean isHiding
      );

   /// Controls whether the window is fullscreen or not.
   /// \param[in] isFull Whether or not to make fullscreen.
   virtual void setFullScreen
      (
      const EcBoolean isFull
      );

   /// Set the current context to write to this window
   virtual void makeCurrent
      (
      ) const;

   static SharedImpl newImpl
      (
      );

   /// swap buffer if double buffered.
   virtual void swapBuffers
      (
      ) const;

   ///////////////////////////////////////////////////////////////////
   // Init and post-init routines.  These methods either initialize //
   // or force initialization when called.                          //
   ///////////////////////////////////////////////////////////////////

   /// open window
   virtual EcBoolean openWindow
      (
      );

   /// close window and associated resources.
   virtual void closeWindow
      (
      );

   virtual void resizeGL
      (
      ) const;

   virtual void setView
      (
      NSView* pView
      );

protected:
   /// Find the best pixel format based on card capabilities.
   virtual NSOpenGLPixelFormat* chooseVisual
      (
      );

   NSWindow* m_Win;
   NSView* m_View;
   NSOpenGLContext* m_Context;
   NSAutoreleasePool* m_Pool;
};

#endif // ecWindowImplCocoa_H_
