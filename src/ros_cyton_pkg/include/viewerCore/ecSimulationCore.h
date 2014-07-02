#ifndef ecSimulationCore_H_
#define ecSimulationCore_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationCore.h
/// @class EcSimulationCore
/// @brief A class to handle simulation in Viewer. It provides additional
///        GUI-based functionality to EcIODataBroker.
///        It contains an instance of EcSystemSimuation and a timer.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecConnectionManagerTypes.h>
#include <interface/ecIODataBroker.h>

#include <QtCore/QObject>

class simulationPlugin;

class EC_GUICOMMON_VIEWERCORE_DECL EcSimulationCore : public QObject, public EcIODataBroker
{
   Q_OBJECT

public:
   /// Constructor
   /// @param[in] plugin Handle to owning plugin
   explicit EcSimulationCore
      (
      simulationPlugin* plugin
      );

   /// @copydoc EcIODataBroker::loadFile(const EcString&)
   virtual EcBoolean loadFile
      (
      const EcString& fileName,
      bool loadPlugins
      );

   /// @copydoc EcIODataBroker::initState()
   virtual EcBoolean initState
      (
      );

   /// Saves the current simulation to a file.  The time is set to 0 instead
   /// of the current time.
   /// @param[in] fileName File to save as
   /// @param[in] savePluginConfigs Whether to save plugin settings as well
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean saveCurrentAs
      (
      const EcString& fileName,
      EcBoolean savePluginConfigs = EcFalse
      );

   /// Saves the system to a file.
   /// @param[in] fileName File to save as
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean saveSystemAs
      (
      const EcString& fileName
      );

public Q_SLOTS:
   void onFileLoadState();
   void onFileMerge();
   void onFileSaveState();
   void onFileSaveSystem();
   void onFileExchange();
   void onFileSaveSimplified();

protected:
   /// @copydoc EcIODataBroker::runSimulationCycle()
   virtual void runSimulationCycle
      (
      );

   /// Save a given simulation to file. This will change the visualization parameter in simulation to current view
   /// in the Viewer
   virtual EcBoolean saveSimulationToFile
      (
      const EcString& filename,
      EcSystemSimulation& simulation,
      EcBoolean savePluginConfigs = EcFalse
      );

   simulationPlugin* m_pPlugin; ///< Handle to simulation plugin API
};

#endif // ecSimulationCore_H_
