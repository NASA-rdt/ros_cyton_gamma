#ifndef ecWindowImplWin_H_
#define ecWindowImplWin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecWindowImplWin.h
/// @brief Windows based implementation of windowing methods.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecWindowImpl.h"
#include <windows.h>

class EC_SENSOR_RENDER_DECL EcWindow::Impl::Win : public EcWindow::Impl
{
public:
   /// Translates WIN32 handle to EcWindow for use in message handler thread.
   typedef std::map<HWND, const EcWindow *> WinMap;

   Win
      (
      );

   virtual ~Win
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
      );

   /// Accessor and Mutator methods for window parameters
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

   /// change the current context to write to this window
   virtual void makeCurrent
      (
      ) const;

   static SharedImpl newImpl
      (
      );

   /// Allow one window to shader GL components with another.
   virtual EcBoolean share
      (
      const SharedImpl win
      ) const;

   /// swap buffer if double buffered
   virtual void swapBuffers
      (
      ) const;

   ///////////////////////////////////////////////////////////////////
   // Init and post-init routines.  These methods either initialize //
   // or force initialization when called.                          //
   ///////////////////////////////////////////////////////////////////

   virtual EcBoolean init
      (
      EcWindow *win
      );

   /// open window
   virtual EcBoolean openWindow
      (
      );

   /// WIN32-specific version to be able to pass extra parameters.
   /// @param[in] windowStyle It is used to pass control to spawned windows.
   virtual EcBoolean openWindow
      (
      const DWORD windowStyle
      );

   virtual void closeWindow
      (
      );

   HWND nativeHandle() { return m_HWnd; }

   /// Specify characteristics of this window
   /// @param[in] basicWin If true, will not setup OpenGL support
   void setBasicWindow
      (
      const EcBoolean basicWin
      );

protected:

   /// set pixel format, important for OpenGL initialization.
   virtual EcU32 chooseVisual
      (
      );

   /// Thread of execution that polls for windows messages.
   static DWORD WINAPI MessageHandlingThreadProc
      (
      LPVOID param
      );

   /// Message handling method
   static LRESULT CALLBACK mainWindowWndProc
      (
      HWND hWnd,
      UINT uMsg,
      WPARAM wParam,
      LPARAM lParam
      );

   HDC   m_HGLDC;             ///< Handle to device context for framebuffer
   HGLRC m_HGLRC;             ///< Handle to OpenGL rendering context
   HWND  m_HWnd;              ///< Handle to window
   EcBoolean m_BasicWin;      ///< Whether this is a basic win or not
   static WinMap m_WindowMap; ///< List of current windows for msg handler
};

#endif // ecWindowImplWin_H_
