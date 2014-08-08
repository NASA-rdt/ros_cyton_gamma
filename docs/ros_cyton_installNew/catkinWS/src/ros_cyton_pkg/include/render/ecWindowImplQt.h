#ifndef ecWindowImplQt_H_
#define ecWindowImplQt_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecWindowImplQt.h
/// @brief Qt-based implementation of windowing methods.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include "ecWindowImpl.h"
#include <QtOpenGL/QGLWidget>


class EC_SENSOR_RENDER_DECL EcQGLWidget : public QGLWidget
{
   Q_OBJECT

public:
   explicit EcQGLWidget(EcWindow* pWin);
   EcQGLWidget(EcWindow* pWin, QGLFormat fmt, QWidget* parent, QGLWidget* share);
   EcQGLWidget(EcWindow* pWin, QWidget* parent, QGLWidget* share, Qt::WindowFlags flags = 0);
   virtual ~EcQGLWidget();

Q_SIGNALS:
   void signalWindowClose();
   void signalWindowResize(int,int);
   void signalWindowHide(bool);

protected:
   virtual void closeEvent(QCloseEvent* event);
   virtual void resizeEvent(QResizeEvent* event);
   virtual void showEvent(QShowEvent* event);
   virtual void resizeGL(int width, int height);
   virtual void paintGL();

   EcWindow* m_pWindow;
};

class EC_SENSOR_RENDER_DECL EcWindow::Impl::Qt : public EcWindow::Impl
{
public:
   Qt
      (
      );

   virtual ~Qt
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

   /// Indiate whether to make this window stay above all others.
   /// \param[in] topmost Wheter or not to make it a topmost window.
   virtual void setTopMost
      (
      const EcBoolean topmost
      );

   /// Controls whether the window has the visible attribute or not.
   /// \param[in] isHiding Whether or not to hide the window.
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

   /// Factory method for instantiating a pointer to a Qt-type.
   /// \return SharedImpl Handle to generic implementation.
   static SharedImpl newImpl
      (
      );

   /// swap buffer if double buffered
   virtual void swapBuffers
      (
      ) const;

   /// Set a default OpenGL format for subsequent window creation.
   /// \param[in] _fmt Pointer to format structure.
   static void setDefaultFormat
      (
      const QGLFormat *_fmt = EcNULL
      );

   /// Specify a custom set of flags for the window.
   /// \param[in] flags Qt-based widget creation flags
   void setWindowFlags
      (
       const ::Qt::WindowFlags flags
      );

    /// Return the currnet set of flags for the window.
   /// \return Qt-based widget creation flags
   const ::Qt::WindowFlags windowFlags
      (
      ) const;

   ///////////////////////////////////////////////////////////////////
   // Init and post-init routines.  These methods either initialize //
   // or force initialization when called.                          //
   ///////////////////////////////////////////////////////////////////

   /// initializes a window.
   virtual EcBoolean openWindow
      (
      );

   /// Next best thing to a destructor.
   virtual void closeWindow
      (
      );

   /// Sets the internal widget used for rendering.  Typically used to reparent to use a custom
   /// widget over the default QGLWidget.
   /// \param[in] widget Pointer to widget to use as renderer.
   /// \param[in] handleDeletion Specify who is responsible for widget cleanup.  A value of EcTrue
   ///                           means that this class will cleanup. The default is EcFalse.
   virtual void setWidget
      (
      EcQGLWidget *widget,
      const EcBoolean handleDeletion = EcFalse
      );

   /// Obtains a handle to the internal rendering widget.
   /// \return QGLWidget* Pointer to internal renderer.
   virtual EcQGLWidget *getWidget
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
   EcBoolean         m_WidgetOwner; ///< Whether we should handle cleanup
   EcQGLWidget*      m_pWidget;     ///< Handle to internal renderer
   ::Qt::WindowFlags m_WindowFlags; ///< Optional window creation flags
};

#endif // ecWindowImplQt_H_
