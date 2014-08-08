#ifndef ecGeneralPreferencePage_H_
#define ecGeneralPreferencePage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecGeneralPreferencePage.h
/// @class EcGeneralPreferencePage
/// @brief Page for general preferences
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecBasePreferencePage.h"

namespace Ui { class ecGeneralPreferencePage; }
namespace Ec { class MainWidgetPlugin; }

/////////////////////////////////////////////////////////////////////////////
// EcGeneralPreferencePage widget
class EC_GUICOMMON_VIEWERCORE_DECL EcGeneralPreferencePage : public EcBasePreferencePage
{
   Q_OBJECT

public:
   /// constructor
   EcGeneralPreferencePage
      (
      Ec::MainWidgetPlugin* plugin
      );

   /// destructor
   virtual ~EcGeneralPreferencePage
      (
      );

   /// initialize the page
   virtual void init
      (
      );

protected Q_SLOTS:
   void apply();

protected:
   /// the UI components from Qt Designer
   Ui::ecGeneralPreferencePage* m_pUi;
   /// pointer to the main window
   Ec::MainWidgetPlugin*      m_pPlugin;
};

#endif // ecGeneralPreferencePage_H_
