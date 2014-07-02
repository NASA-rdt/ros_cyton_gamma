#ifndef ec_Viewer_H_
#define ec_Viewer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecViewer.h
/// @class Ec::Viewer
/// @brief Base class for integrated Qt QMainWindow and OpenSceneGraph's
///        osgViewer::CompositeViewer.  Provides a default capability for a
///        single view with easy expansion for additional shared windows.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

#include <osgViewer/CompositeViewer>
#include <QtCore/QTimer>
#include <QtGui/QMainWindow>

class EcColor;
class QMenu;

namespace Ec
{

class LightCallback;
class RenderHUD;
class ViewerContextMenu;
class ViewerPlugin;

class EC_GUICOMMON_VIEWERCORE_DECL Viewer : public QMainWindow, public osgViewer::CompositeViewer
{
   Q_OBJECT

public:
   /// Default constructor
   Viewer
      (
      );

   /// Initializes and configures viewer threads.  Sets up some basic
   /// ambient lighting plus a directional light at the eyepoint. It does
   /// not display the window.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean init
      (
      );

   /// Retrieve handle to root of scene graph.  It is not strictly the top
   /// node in the scene.  This handle is directly below the true root, but
   /// doesn't contain the standard lighting and other transient global nodes.
   /// You can obtain the true root by using the OSG-specific call, which is
   /// osgViewer::Viewer::getSceneData().
   /// @return osg::Group* Root node
   osg::Group* getRoot
      (
      );

   /// Set the desired framerate in Hertz for the viewer.  Actual framerate
   /// will be governed by how fast updates can be made.
   void setFrameRate
      (
      const EcU32 rate ///< [in] Rate in Hz
      );

   /// Retrieve rate of viewer.
   /// @return EcU32 Rate in Hz
   EcU32 frameRate
      (
      ) const;

   /// Specify a default background color and whether it should be applied
   /// to all existing windows.
   void setBackgroundColor
      (
      const EcColor& color,             ///< [in] Color to set
      const EcBoolean allViews = EcTrue ///< [in] Apply to all or not
      );

   /// Retrieve the default background color. The individual background color
   /// may be retrieved using an OSG-specific call. It is contained within the
   /// osg::Camera class and is referred to as the clearColor.
   /// @return EcColor Default background color
   EcColor backgroundColor
      (
      ) const;

   /// Specify the default display mask and whether it should be applied to all
   /// existing windows.  All scene nodes contain a mask and it is compared
   /// against this mask during drawing.  A non-zero value when performing a
   /// bit-wise OR of the two means the node should be drawn.
   void setDisplayMask
      (
      const EcU32 mask,                 ///< [in] Mask to set
      const EcBoolean allViews = EcTrue ///< [in] Apply to all or not
      );

   /// Retrieve the default display mask.  The individual window masks may
   /// be retrieved using an OSG-specific call.  It is contained within the
   /// osg::Camera class and is referred to as the cullMask.
   /// @return EcU32 Default display mask
   EcU32 displayMask
      (
      ) const;

   /// Retrieve a direct handle to the Heads Up camera.
   /// @return Ec::RenderHUD* Handle to HUD Camera
   RenderHUD* getHUD() { return m_pHUD; }

   /// Get the QDockWidget that is a window containing the camera view specified by index.
   /// @return QDockWidget Pointer to the window or null if the camera view specified by index does not exist.
   QDockWidget* getViewWindow
      (
      const EcU32 index
      );

public Q_SLOTS:
   /// Used to create additional camera windows.  The new window will
   /// be sized and placed according to the inputs (or defaults).  Cameras
   /// may be retrieved later with the OSG-specific call.  It is contained
   /// within the osgViewer::CompositeViewer class and is referred to a view.
   /// @return int Camera index
   virtual int addCamera(int width=256, int height=256, int x=0, int y=0);

   /// Customized event filter that is used in the central widget to process
   /// keyboard events through slotManager.
   /// @return bool Whether this method processed the event or not
   bool eventFilter
      (
      QObject* obj, ///< [in] Object receiving the event
      QEvent* event ///< [in] Event to be handled
      );

Q_SIGNALS:
   void signalContextMenu(QMenu*);      ///< When displaying context menu
   void signalPreRender();              ///< Before drawing starts
   void signalPostRender();             ///< After drawing is complete
   void signalWindowResized(int, int);  ///< When we are resized
   void signalExit();                   ///< Shutdown pending

protected:
   virtual ~Viewer();                   ///< Disable stack allocation
   void paintEvent(QPaintEvent*);       ///< Customize rendering
   void resizeEvent(QResizeEvent*);     ///< Customize resizing
   void closeEvent(QCloseEvent *event); ///< Customize app shutdown

   ViewerPlugin* m_pPlugin;             ///< Plugin API access
   QTimer m_Timer;                      ///< Rendering update timer
   EcU32 m_FrameRate;                   ///< Viewer refresh rate (Hz)
   osg::GraphicsContext* m_pBaseWindow; ///< Main context for rendering
   osg::Group* m_pRoot;                 ///< Base scene graph node
   ViewerContextMenu* m_pContextMenu;   ///< Context menu (right click)
   LightCallback* m_pLightCallback;     ///< Processes lighting position
   RenderHUD* m_pHUD;                   ///< 2D-Overlay HUD camera
   osg::Vec4d m_BackgroundColor;        ///< Default background color
   EcU32 m_DisplayMask;                 ///< Default view mask
};

} // namespace Ec

#endif // ec_Viewer_H_
