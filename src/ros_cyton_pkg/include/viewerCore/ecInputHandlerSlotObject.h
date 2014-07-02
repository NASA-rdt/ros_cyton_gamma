#ifndef ec_InputHandlerSlotObject_H_
#define ec_InputHandlerSlotObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecInputHandlerSlotObject.h
/// @class Ec::InputHandlerSlotObject
/// @brief Populates slotManager with slots of EcDefaultInputHandler
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.

#include <QtCore/QObject>

class EcDefaultInputHandler;
class QLabel;
class QMenu;

namespace Ec
{

class PluginGUI;

class InputHandlerSlotObject : public QObject
{
   Q_OBJECT

public:
   InputHandlerSlotObject
      (
      Ec::PluginGUI* plugin,
      EcDefaultInputHandler* pInputHandler,
      bool tcpModeSlot = true,
      const QString& slotName = ""
      );

public Q_SLOTS:
   void incrementalUpdate(double x, double y, double z,
                          double rx, double ry, double rz);
   void resetToHome();
   void populateMenu(QMenu*);
   void setCOIOfLink();
   void setCOIOfManipulator();
   void toggleTCPMode();

protected:
   EcDefaultInputHandler* m_pInputHandler;
   QLabel* m_pTcpWidget;
};

} // namespace Ec

#endif // ec_InputHandlerSlotObject_H_
