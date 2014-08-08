#ifndef ecPluginPreferencePage_H_
#define ecPluginPreferencePage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginPreferencePage.h
/// @class EcPluginPreferencePage
/// @brief Page for plugin preferences
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecBasePreferencePage.h"

namespace Ui { class ecPluginPreferencePage; }

/////////////////////////////////////////////////////////////////////////////
// EcPluginPreferencePage widget
class EC_GUICOMMON_VIEWERCORE_DECL EcPluginPreferencePage : public EcBasePreferencePage
{
   Q_OBJECT

public:
   /// constructor
   EcPluginPreferencePage
      (
      QWidget* parent
      );

   /// destructor
   virtual ~EcPluginPreferencePage
      (
      );

   /// initialize the page
   virtual void init
      (
      );

protected Q_SLOTS:
   void apply();
   void selectAll(bool select);

protected:
   /// the UI components from Qt Designer
   Ui::ecPluginPreferencePage* m_pUi;
};

#endif // ecPluginPreferencePage_H_
