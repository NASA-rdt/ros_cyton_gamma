#ifndef ecWindowImpl_H_
#define ecWindowImpl_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecWindowImpl.h
/// @brief Abstract class which provides consistent API across all window
///        implementations.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <boost/shared_ptr.hpp>

#include "ecWindow.h"

/// Abstract Implementation class to support a variety of windowing systems.
class EC_SENSOR_RENDER_DECL EcWindow::Impl
{
public:
   /// Forward declaration for the classes available.
   class Cocoa;
   class Qt;
   class Win;
   class X11;

   /// Constructor
   Impl
   (
   );

   /// Destructor
   virtual ~Impl
      (
      );

   //////////////////////////////////////////////////////////////////
   // Pre-init routines.  These methods are allowed before window  //
   // initialization.                                              //
   //////////////////////////////////////////////////////////////////

   /// Sets title bar for window
   virtual void setName
      (
      const EcString &name
      ) = 0;

   /// Accessor and Mutator methods for window parameters
   virtual void setWindowSize
      (
      const EcU32 width,
      const EcU32 height
      ) = 0;

   virtual void setWindowPos
      (
      const EcU32 posX,
      const EcU32 posY
      ) = 0;

   virtual void setWindowSizeAndPos
      (
      const EcU32 width,
      const EcU32 height,
      const EcU32 posX,
      const EcU32 posY
      ) = 0;

   /// set window to stay top most
   virtual void setTopMost
      (
      const EcBoolean topmost
      ) = 0;

   /// Controls whether the window has the visible attribute or not.
   virtual void setHideWindow
      (
      const EcBoolean isHiding
      ) = 0;

   /// Controls whether the window is fullscreen or not.
   virtual void setFullScreen
      (
      const EcBoolean isFull
      ) = 0;

   /// change the current context to write to this window
   virtual void makeCurrent
      (
      ) const = 0;

   static SharedImpl newImpl
      (
      );

   /// Allow one window to shader GL components with another.
   virtual EcBoolean share
      (
      const WeakImpl win
      ) const;

   virtual const SharedImpl getShare
      (
      ) const;

   /// swap buffer if double buffered
   virtual void swapBuffers
      (
      ) const = 0;

   ///////////////////////////////////////////////////////////////////
   // Init and post-init routines.  These methods either initialize //
   // or force initialization when called.                          //
   ///////////////////////////////////////////////////////////////////

   /// initializes a window.
   virtual EcBoolean init
      (
      EcWindow* win
      );

   virtual EcBoolean openWindow
      (
      ) = 0;

   virtual void closeWindow
      (
      ) = 0;

   const EcWindow* getWindow
      (
      ) const;

   virtual void resizeGL
      (
      ) const;

    /// This checks to see if the window is currently
    /// fully constructed / visible so that problems
    /// won't occur when problems occur when causing actions
    /// to the low lying implimentation.
    ///
    /// It's required because QT on OSX appears to have this
    /// problem where renderers don't check if the window fully
    /// exists, and downcasting on OSX doesn't always work
    /// (apple gcc bug).
    /// See:
    /// http://boost.2283326.n4.nabble.com/dynamic-pointer-cast-doesn-t-work-as-expected-td2571773.html
    /// http://article.gmane.org/gmane.comp.graphics.openscenegraph.cvs/8806/match=race+condition
    ///
    /// In short there isn't a last moment check to see if the thing is ready to go in OSG.
    virtual EcBoolean isWindowVisible
       (
       ) const;

protected:
   /// Handle to window using this impl.
   EcWindow* m_pWin;
   /// Handle to the window we are sharing context with (if any).
   mutable WeakImpl m_pShareWindow;
};

#endif // ecWindowImpl_H_
