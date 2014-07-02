#ifndef cyton_ViewerBase_H_
#define cyton_ViewerBase_H_
//     Copyright (c) 2008-2011 Energid Technologies. All rights reserved. ////
//
// Filename:    cytonAlphaViewerPlugin.h
//
// Description: GUI-based plugin that provides additional capability on top
//              of the base hardware cytonAlphaPlugin.  Adds UI components
//              to customize viewer.
//
// Contents:    cytonAlphaViewerPlugin class
//
/////////////////////////////////////////////////////////////////////////
#include <cytonTypes.h>
#include <hardwarePluginGUI/ecHardwarePluginGUI.h>

namespace cyton
{

class GripperHandler;

class CYTON_DECL ViewerBase : public Ec::HardwarePluginGUI
{
   Q_OBJECT

protected Q_SLOTS:
   void onActionConfig(); ///< Customization of config settings
   void onHelpAbout();    ///< Custom Help->About

protected:
   /// Constructor
   /// @param[in] pluginName Hardware plugin to connect to
   explicit ViewerBase
      (
      const EcString& pluginName
      );

   /// Destructor
   ~ViewerBase
      (
      );

   /// @copydoc Ec::HardwarePluginGUI::init()
   EcBoolean init
      (
      );

   /// @copydoc Ec::HardwarePluginGUI::initState()
   EcBoolean initState
      (
      );

   boost::scoped_ptr<GripperHandler> m_pGripperHandler;
};

} // namespace cyton

#endif // cyton_ViewerBase_H_
