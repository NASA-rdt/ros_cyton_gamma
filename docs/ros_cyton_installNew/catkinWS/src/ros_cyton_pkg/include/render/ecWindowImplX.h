#ifndef ecWindowImplX_H_
#define ecWindowImplX_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecWindowImplX.h
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecWindowImpl.h"
#include "ecGL.h"

class EC_SENSOR_RENDER_DECL EcWindow::Impl::X11 : public EcWindow::Impl
{
public:
   X11
      (
      );

   virtual ~X11
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

protected:

   /// set pixel format, important for OpenGL initialization.
   virtual EcBoolean chooseVisual
      (
      );

   /// Callback to ensure window is available before proceeding.
   static Bool waitForMapNotifyX
      (
       Display *d,
       XEvent *e,
       char *arg
       );

   /// Callback to ensure window is destroyed before proceeding.
   static Bool waitForUnmapNotifyX
      (
       Display *d,
       XEvent *e,
       char *arg
       );

   Display     *m_pDisplay;
   XVisualInfo *m_pVisual;
   GLXContext   m_XContext;
   Window       m_Win;
};

#endif // ecWindowImplX_H_
