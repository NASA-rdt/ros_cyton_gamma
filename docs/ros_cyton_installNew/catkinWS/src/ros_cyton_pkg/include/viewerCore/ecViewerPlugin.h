#ifndef ec_ViewerPlugin_H_
#define ec_ViewerPlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecViewerPlugin.h
/// @class Ec::ViewerPlugin
/// @brief Provide Viewer access to Plugin API.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <viewerCore/ecPluginGUI.h>

class EcBasePreferencePage;
class EcIODataBroker;

namespace Ec {

class EC_GUICOMMON_VIEWERCORE_DECL ViewerPlugin : public PluginGUI
{
   Q_OBJECT

public:
   /// Local instantiation of Main Viewer plugin.  It performs general capabilities
   /// to properly setup other GUI plugins.
   explicit ViewerPlugin
      (
      QMainWindow* pWindow ///< [in] Owning parent window
      );

   /// @copydoc Ec::PluginGUI::init()
   EcBoolean init
      (
      );

   void setMainWindow
      (
      QMainWindow* pWin
      );

   void setMaxRecentFiles(const EcInt32 maxRecentFiles);
   void setLinkLabelMouseOver(const EcBoolean enabled);
   EcBoolean linkLabelMouseOver() const;

public Q_SLOTS:
   EcBasePreferencePage* newPreferencePage(); ///< Creator method for general preference page
   void onActionExit();         ///< Routine to run before shutting down

protected:
   /// Disable stack allocation
   ~ViewerPlugin
      (
      );

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

   EcIODataBroker* m_pSim;           ///< Simulation handle
   EcBoolean m_LinkLabelMouseOver;   ///< Whether to show link text when hovering
};

} // namespace Ec

#endif // ec_ViewerPlugin_H_
