#ifndef ec_MainWidgetPlugin_H_
#define ec_MainWidgetPlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecMainWidgetPlugin.h
/// @class Ec::MainWidgetPlugin
/// @brief Provide an interface layer for allowing a viewer to interface
///        with a simulation.  Since it is an integral part of the viewer
///        it is not loaded separately (as an .ecp).  Bypass standard
///        creation macros.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <viewerCore/ecPluginGUI.h>

class EcBasePreferencePage;
class simulationPlugin;
namespace Ui { class mouseModeToolBar; }
class QTimer;

namespace Ec {

class EC_GUICOMMON_VIEWERCORE_DECL MainWidgetPlugin : public PluginGUI
{
   Q_OBJECT

public:
   MainWidgetPlugin
      (
      );

   ~MainWidgetPlugin
      (
      );

   EcBoolean init
      (
      );

   /// Frame rate in Hz for rendering (and for now the simulation thread)
   void setFrameRate
      (
      const EcReal rate
      );

   /// get frame rate
   EcReal frameRate
      (
      ) const;

   void setMainWindow
      (
      QMainWindow* pWin
      );

   /// Loads the simulation from file. Returns true if successful.
   EcBoolean openFile
      (
      const EcString& fileName,
      bool loadPlugins
      );

   /// Saves the current simulation to a file, with the time is set to 0
   /// instead of the current time.
   /// Returns true if successful.
   EcBoolean saveCurrentAs
      (
      const EcString& fileName,
      EcBoolean savePluginConfigs = EcFalse
      );

   /// Temporary accommodation until fully contained here.
   void setMaxRecentFiles(const EcInt32 maxRecentFiles);
   void setLinkLabelMouseOver(const EcBoolean enabled);
   EcBoolean linkLabelMouseOver() const;

public Q_SLOTS:
   void frame(EcBoolean forceUpdate = EcFalse); ///< Frame timer slot
   void onActionLoadScene();    ///< Connected to simulation loading
   void onActionGuideMode();
   void onActionCOIMode();
   void onActionViewMode();
   void onActionExit();         ///< Routine to run before shutting down
   EcBasePreferencePage* newPreferencePage(); ///< Creator method for general preference page

protected:
   /// @copydoc EcIODataBroker::initPlugin(Ec::Plugin*)
   EcBoolean initPlugin
      (
      Ec::Plugin* plugin
      );

   /// @copydoc EcIODataBroker::unloadPlugin(Ec::Plugin*)
   EcBoolean unloadPlugin
      (
      Ec::Plugin* plugin
      );

   QTimer* m_pFrameTimer;            ///< Timing mechanism to control framerate
   Ui::mouseModeToolBar* m_pMouseUi; ///< Interaction modes toolbar
   simulationPlugin* m_pSim;         ///< Simulation handle
   EcBoolean m_LinkLabelMouseOver;   ///< Whether to show link text when hovering
};

} // namespace Ec

#endif // ec_MainWidgetPlugin_H_
