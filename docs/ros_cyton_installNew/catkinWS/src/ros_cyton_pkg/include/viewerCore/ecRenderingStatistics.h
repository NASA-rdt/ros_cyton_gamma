#ifndef ec_RenderingStatistics_H_
#define ec_RenderingStatistics_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderingStatistics.h
/// @class Ec::RenderingStatistics
/// @brief Provide rendering statistics on the status bar.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTimer.h>

#include <QtGui/QWidget>

class QLabel;

namespace Ec {

class PluginGUI;

class EC_GUICOMMON_VIEWERCORE_DECL RenderingStatistics : public QWidget
{
   Q_OBJECT

public:
   RenderingStatistics
      (
      PluginGUI* plugin
      );

public Q_SLOTS:
   /// These slots get connected to the main rendering window to perform
   /// data collection and reporting of metrics.
   void startRenderTime(); ///< Start of rendering
   void stopRenderTime();  ///< End of rendering
   void frame();           ///< Frame timer slot

protected:
   void updateStatusBar();      ///< Update GUI statusbar with metrics

   PluginGUI* m_pPlugin;
   QLabel* m_FPSLabel;
   QLabel* m_TimeLabel;

   EcMicroTimer m_Timer;        ///< Internal timer
   EcReal m_RenderStartTime;    ///< Time that rendering started
   EcReal m_AccumBackEndTime;   ///< Total time for computation back-end
   EcReal m_AccumRenderTime;    ///< Total time for rendering
   EcU32  m_NumEvents;          ///< Event counter
   EcReal m_LastTime;           ///< Previous recorded timestamp
};

} // namespace Ec

#endif // ec_RenderingStatistics_H_
