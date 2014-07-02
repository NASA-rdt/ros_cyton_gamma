#ifndef ecSimulationPreferencePage_H_
#define ecSimulationPreferencePage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationPreferencePage.h
/// @class EcSimulationPreferencePage
/// @brief Page for Simulation preferences
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecBasePreferencePage.h"

namespace Ui { class ecSimulationPreferencePage; }
class simulationPlugin;

/////////////////////////////////////////////////////////////////////////////
// EcSimulationPreferencePage widget
class EC_GUICOMMON_VIEWERCORE_DECL EcSimulationPreferencePage : public EcBasePreferencePage
{
   Q_OBJECT

public:
   /// constructor
   EcSimulationPreferencePage
      (
      simulationPlugin* plugin
      );

   /// destructor
   virtual ~EcSimulationPreferencePage
      (
      );

   /// initialize the page
   virtual void init
      (
      );

protected Q_SLOTS:
   void apply();

protected:
   Ui::ecSimulationPreferencePage* m_pUi;     ///< UI controls
   simulationPlugin*               m_pPlugin; ///< Handle to owning plugin
};

#endif // ecSimulationPreferencePage_H_
