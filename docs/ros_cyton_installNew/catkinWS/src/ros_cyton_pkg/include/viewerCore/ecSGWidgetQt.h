#ifndef ecSGWidgetQt_H_
#define ecSGWidgetQt_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecSGWidgetQt.h
/// @brief Customized version of a QGLWidget to provide some
///        base capability for rendering windows.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <render/ecWindowImplQt.h>
#include <foundCore/ecConstants.h>

// Forward declarations.
class EcSGWindow;

class EC_GUICOMMON_VIEWERCORE_DECL EcSGWidgetQt : public EcQGLWidget
{
   Q_OBJECT

public:
   /// Constructor
   /// \param[in] pWin   Owner/controller of this widget.
   /// \param[in] parent Parent widget - used for hierarchy cleanup.
   EcSGWidgetQt
      (
      EcSGWindow *pWin,
      QWidget *parent
      );

   /// Destructor
   virtual ~EcSGWidgetQt
      (
      );

   /// Performs one-time initialization of window.
   virtual void initializeGL
      (
      );

   /// Resizes window
   /// \param[in] width  New width.
   /// \param[in] height New height.
   virtual void resizeGL
      (
      int width,
      int height
      );

   /// Redraws window.
   virtual void paintGL
      (
      );

   /// Continually render and poll events until escape key is pressed.
   virtual void renderUntilEscaped
      (
      );

Q_SIGNALS:
   void signalContextMenu(const QPoint&); ///< Provide a signal to popup context menu
   void signalWindowResized(EcInt32, EcInt32);

protected:
   /// Capture results of user manually moving window.
   /// \param[in] event Move event specifics.
   virtual void moveEvent
      (
      QMoveEvent* event
      );

   /// Queue mouse button press for SG event handler.
   /// \param[in] event Button press event specifics.
   virtual void mousePressEvent
      (
      QMouseEvent* event
      );

   /// Queue mouse button release for SG event handler.
   /// \param[in] event Button release event specifics.
   virtual void mouseReleaseEvent
      (
      QMouseEvent* event
      );

   /// Queue mouse dragging for SG event handler.
   /// \param[in] event Mouse drag event specifics.
   virtual void mouseMoveEvent
      (
      QMouseEvent* event
      );

   /// Queue mouse scroll wheel for SG event handler.
   /// \param[in] event Scroll wheel event specifics.
   virtual void wheelEvent
      (
      QWheelEvent* event
      );

   /// Queue key press for SG event handler.
   /// \param[in] event Key press event specifics.
   virtual void keyPressEvent
      (
      QKeyEvent* event
      );

   /// Queue key release for SG event handler.
   /// \param[in] event Key release event specifics.
   virtual void keyReleaseEvent
      (
      QKeyEvent* event
      );

   EcSGWindow *m_pWindow;          ///< Handle to controlling window
   EcBoolean   m_ContinuousRender; ///< In continuous rendering mode
   QPoint      m_PrevPos;          ///< Previous location of button press
   EcInt32     m_ButtonState;      ///< Buttom press state
};

#endif // ecSGWidgetQt_H_
