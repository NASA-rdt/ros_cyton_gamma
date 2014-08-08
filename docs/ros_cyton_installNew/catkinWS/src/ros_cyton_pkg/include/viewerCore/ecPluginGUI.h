#ifndef ecPluginGUI_H_
#define ecPluginGUI_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginGUI.h
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>
#include <foundCore/ecPlugin.h>

#include <boost/any.hpp>
#include <boost/weak_ptr.hpp>
#include <QtGui/QWidget>

// Forward declarations
class EcBaseViewerMainWidget;
class EcSG3DInputData;
class simulationPlugin;
class QDockWidget;
class QMainWindow;
class QMenu;
class QToolBar;

namespace osg
{
   template <typename T> class ref_ptr;
   class Group;
   class Node;
   class Referenced;
}
namespace osgGA { class GUIEventHandler; }

namespace Ec
{
   enum GuiParamTypeEnum
   {
      StartOfGuiParams = 0x100,///< Specify a value beyond those in ecIOParams.h
      BackgroundColor,         ///< (SG, EcColor)
      Cursor,                  ///< (S , EcU32)
      DisplayMask,             ///< ( G, EcU32)
      FrameRate,               ///< (SG, EcU32)
      GuideFrame,              ///< (SG, EcCoordinateSystemTransformation)
      Height,                  ///< ( G, EcU32)
      PovParameters,           ///< (SG, EcPovParameters)
      SelectedArm,             ///< (SG, EcU32)
      SelectedEndEffector,     ///< (SG, EcU32)
      Signal,                  ///< (S , signal) Trigger various signals
      SystemReady,             ///< (SG, EcBoolean)
      ViewerAttribute,         ///< (SG, EcU32)
      VisualizationParameters, ///< (SG, EcVisualizationParameters)
      Width,                   ///< ( G, EcU32)

      // EcBaseViewerMainWidget
      SignalContextMenu,       ///< (QMenu*) Connect custom context menu
      SignalPreRender,         ///< () Before rendering starts
      SignalPostRender,        ///< () After rendering is complete
      SignalFrameDone,         ///< (double) Frame complete with timestamp
      SignalLoadScene,         ///< () File loaded
      SignalPlaybackCompleted, ///< () Playback file finished
      SignalSensorInput,       ///< (EcSG3DInputData*) slot connection
      SignalWindowResized,     ///< (EcInt32, EcInt32) new width, height

      // simulationPlugin
      SignalManipulatorAdded,  ///< (QString) When manipulator is added to the system
      SignalManipulatorDeleted,///< (EcU32) When manipulator is deleted from the system
      SignalPauseSimulation,   ///< () Simulation paused
      SignalReset,             ///< () Simulation reset
      SignalStartSimulation,   ///< () Simulation started
      SignalStopSimulation,    ///< () Simulation ended
      SignalSimulationEnabled, ///< (bool) Alternative to Signal{Start,Stop}Simulation
      SignalSimulationChanged, ///< (EcU32) Something has changed in simulation
      SignalSimulationTimeStep,///< (double) When timestep has been calculated
      SignalActiveManipulatorChanged, ///< (EcU32) When active manipulator is changed
      SignalActiveEndEffectorChanged, ///< (EcU32) When active EE is changed
      SignalControlDescriptionChanged,///< (EcU32,EcU32)
      SignalControlMethodChanged,     ///< (EcU32,EcU32)
      SignalControlSystemChanged,     ///< ()
      SignalEndEffectorSetChanged,    ///< (EcU32,EcU32)

      // EcBaseViewerMainWindow
      SignalActionsEnabled,    ///< (bool) Widgets enabled when file loaded
      SignalExit               ///< () Application exit
   };

/// Provides an abstract class to be used as a template for creating dynamically loaded functions.
class EC_GUICOMMON_VIEWERCORE_DECL PluginGUI : public QWidget, public Plugin
{
   Q_OBJECT

public:
   /// Provide a convenient way for plugins to get a shared handle.
   typedef boost::shared_ptr<EcBaseViewerMainWidget>       ViewerPtr;
   typedef boost::shared_ptr<const EcBaseViewerMainWidget> ConstViewerPtr;
   typedef boost::weak_ptr<EcBaseViewerMainWidget>         WeakViewerPtr;

   using Plugin::init;
   /// Sets internal pointer for use later on.
   /// @return EcBoolean Success or failure of command
   EcBoolean init
      (
      QMainWindow* pWin,     ///< [in] Handle to window object
      simulationPlugin* pSim ///< [in] Handle to simulation
      );

   /// Provide safe access to the viewer handle.
   /// @return ViewerPtr Access to viewer handle or NULL if unavailable
   ViewerPtr viewerPtr
      (
      ) { return m_pViewer.lock(); }

   /// Provide safe access to the viewer handle.
   /// @return ConstViewerPtr Access to viewer handle or NULL if unavailable
   ConstViewerPtr viewerPtr
      (
      ) const { return m_pViewer.lock(); }

   /// @copydoc Ec::Plugin::update(const EcReal)
   /// Concrete implementation of plugin update method.
   virtual void update(const EcReal time) {}

   /// Retrieves a pointer to a main window object type.
   /// @return T* Pointer to a valid object or EcNULL on failure
   template <typename T>
   EC_GUICOMMON_VIEWERCORE_DECL T* getPtr
      (
      const QString& name = "" ///< [in] Name of the object to retrieve, if not unique
      );

   /// @copydoc EcRenderWindow::getNode()
   osg::ref_ptr<osg::Group> getNode
      (
      const EcU32 manIndex  = -1,     ///< [in] Manipulator link, -1 for root
      const EcU32 linkIndex = -1,     ///< [in] Link index, -1 for base
      const EcBoolean getDH = EcFalse ///< [in] Whether to get DH node or not
      );

   /// Connects a signal from the associated owner to this plugin.
   /// @tparam prm Signal parameter to connect to
   /// @return EcBoolean Success or failure of command
   template <GuiParamTypeEnum prm>
   EC_GUICOMMON_VIEWERCORE_DECL EcBoolean connectSignal
      (
      const char* value,    ///< [in] Signal owner
      QObject* owner = NULL ///< [in] Slot owner.  If NULL, uses 'this'
      );

   /// Disconnects a signal from the associated owner.
   /// @tparam prm Signal parameter to disconnect
   /// @return EcBoolean Success or failure of command
   template <GuiParamTypeEnum prm>
   EC_GUICOMMON_VIEWERCORE_DECL EcBoolean disconnectSignal
      (
      QObject* owner,   ///< [in] Signal owner
      const char* value ///< [in] Signal/slot to disconnect
      );

   /// Adds a connection to this object which sets the enabled state based
   /// on whether a file is loaded.
   /// @return EcBoolean Success or failure of command
   EcBoolean enableWithFile
      (
      QObject* obj ///< [in] QObject to set enabled connection
      );

   /// Adds a connection to this object which sets the disabled state based
   /// on when the simulation is running.
   /// @return EcBoolean Success or failure of command
   EcBoolean disableOnSimulation
      (
      QObject* obj ///< [in] QObject to set disabled connection
      );

   /// Replace the existing central widget with this one.  The previously-set
   /// one will be deleted.  This method tries to reparent the viewer widget
   /// beforehand.  Most layout or tabbed widget will need to manually add
   /// this, which is why it is returned as well.
   /// @return QWidget* Handle to central widget
   QWidget* setCentralWidget
      (
      QWidget* widget ///< [in] Central widget to swap in
      );

   /// Add the Qt-based object to the auto-cleanup list.  When the destructor
   /// gets called, anything in this list will be deleted.
   void addAutoCleanup
      (
      QObject* obj ///< [in] Qt object to destroy when plugin is unloaded
      );

   /// Add the OSG-based object to the auto-cleanup list.  When the destructor
   /// gets called, it will be properly removed depending on its type.  Nodes
   /// will be detached from all of its parents, and update operations will be
   /// removed from their views - effectively reducing the ref count to zero.
   void addAutoCleanup
      (
      osg::Referenced* ref ///< [in] OSG handle to clean when plugin is unloaded
      );

   /// Add the OSG-based object to the auto-cleanup list.  When the destructor
   /// gets called, the event handler will be properly removed from the view.
   void addAutoCleanup
      (
      osgGA::GUIEventHandler* handler ///< [in] Event handler to cleanup
      );

   /// Returns the center of the screen on which the plugin (i.e. Viewer) is displayed
   const QRect screenGeometry
      (
      ) const;

   /// FIXME: Meant to be called only when a plugin is unloaded.  It will
   /// clean up the OSG-based objects in the cleanup list.  It decrements
   /// the reference count and then inserts an Update Operation to remove
   /// the plugin after the scene has been culled of the used geometry.
   void cleanupOsgObjects
      (
      );

public Q_SLOTS:
   void setSimulationModified(EcBoolean modified); ///< Enables confirm on close
   void onSensorInput(EcSG3DInputData*);           ///< Input device data

protected:
   /// @copydoc Ec::Plugin::Plugin()
   PluginGUI
      (
      );

   /// @copydoc Ec::Plugin::~Plugin()
   virtual ~PluginGUI
      (
      );

   /// Convenience method to add a new dockWidget to the viewer.  Ownership
   /// is transferred for cleanup.
   /// @return EcBoolean Returns success or failure of command
   EcBoolean addDockWidget
      (
      Qt::DockWidgetArea area, ///< [in] Location to add it to
      QDockWidget* pWidget     ///< [in] QDockWidget to add
      );

   /// Convenience method to add a new toolbar to the viewer and insert
   /// it into the toolbar menu.  Owership is transferred for cleanup.
   /// @return EcBoolean Returns success or failure of command.
   EcBoolean addToolBar
      (
      QToolBar* toolbar,           ///< [in] Toolbar to add
      const QString& beforeTB = "" ///< [in] Name of toolbar to insert before.
      );

   /// Adds an action to the specified toolbar.
   EcBoolean addToToolBar
      (
      QAction* action, ///< [in] Action to add to toolbar
      const QString& toolbar = "miscellaneousToolBar" ///< [in] ToolBar to add to
      );

   /// Adds a widget to the QMainWindow statusBar.  Ownership is transerrred
   /// for cleanup.
   EcBoolean addToStatusBar
      (
      QWidget* widget,                      ///< [in] Widget to add to statusBar
      const EcBoolean isPermanent = EcFalse ///< [in] Make permanent or not
      );

   /// Convenience method to add a plugin widget to the viewer as a tabbed widget
   /// Owership is transferred for cleanup.
   /// @return EcBoolean Returns success or failure of command.
   EcBoolean addTab
      (
      QWidget* pWidget,           ///< [in] Widget to be tabbed
      const QString& displayName, ///< [in] Display name of tab
      const QString& before = ""  ///< [in] Optional name of tab to insert in front of
      );

   /// Convenience method to add a menu to the main menubar or retrieve
   /// @return QMenu* Handle to menu created or reused if already present
   QMenu* getOrAddMenu
      (
      const QString& name,           ///< [in] Display name of menu
      const QString& beforeName = "" ///< [in] Optional name of menu to insert in front of
      );

private:
   friend class Plugin; ///< Allow upclassing from template methods

   QMainWindow* m_pMainWindow;        ///< Handle to main window
   WeakViewerPtr m_pViewer;           ///< Weak handle to rendering widget
   simulationPlugin* m_pSimulation;   ///< Handle to simulation in use

   typedef std::vector<boost::any> CleanupVector;
   CleanupVector m_vpCleanupObjects;  ///< Generalized auto-cleanup list
};

} // namespace Ec

#endif // ecPluginGUI_H_
