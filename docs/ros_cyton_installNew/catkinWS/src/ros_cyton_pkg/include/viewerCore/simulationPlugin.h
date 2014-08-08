#ifndef simulationPlugin_H_
#define simulationPlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file simulationPlugin.h
/// @brief Plugin that encapsulates simulation capability.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <plugins/ecIOParams.h>
#include <viewerCore/ecPluginGUI.h>
#include <manipulator/ecManipulatorSystemConfiguration.h>

class EcBasePreferencePage;
class EcCoordinateSystemTransformation;
class EcSimulationCore;
namespace Ui { class simulationToolBar; }

class EC_GUICOMMON_VIEWERCORE_DECL simulationPlugin : public Ec::PluginGUI
{
   Q_OBJECT

public:
   simulationPlugin
      (
      );

   ~simulationPlugin
      (
      );

   EcBoolean init
      (
      );

   /// Loads the simulation from file. Returns true if successful.
   EcBoolean openFile
      (
      const EcString& fileName,
      bool loadPlugins
      );

   /// @copydoc EcSimulationCore::saveCurrentAs(const EcString&, EcBoolean)
   EcBoolean saveCurrentAs
      (
      const EcString& fileName,
      const EcBoolean savePluginConfigs = EcFalse
      );

   /// @copydoc EcIODataBroker::setRate(const EcReal)
   void setRate
      (
      const EcReal rate
      );

   /// Set manipulator to operator on.
   /// @param[in] sArm Manipulator to set
   void setSelectedArm
      (
      const EcU32 sArm
      );

   /// Retrieve the currently selected manipulator ID
   /// @return EcInt32 Current manipulator
   EcInt32 selectedArm
      (
      ) const;

   /// Set end-effector to operator on.
   /// @param[in] sEndID End-effector to set
   void setSelectedEndEffectorID
      (
      const EcU32 sEndID
      );

   /// Retrieve the currently selected end-effector ID
   /// @return EcInt32 Current end-effector
   EcInt32 selectedEndEffectorID
      (
      ) const;

   void setResetDesiredGuideFrames
      (
      const EcBoolean enabled
      );

   /// Update the guide frame of the selected end effector
   EcBoolean setSelectedGuideTrans
      (
      const EcCoordinateSystemTransformation& coord
      );

   /// return the guide frame of the selected end effector
   EcCoordinateSystemTransformation getSelectedGuideTrans
      (
      ) const;

   /// return the actual guide frame of the selected end effector
   EcCoordinateSystemTransformation getActualSelectedGuideTrans
      (
      ) const;

   /// Retrieve desired guide frames reset value
   EcBoolean resetDesiredGuideFrames
      (
      ) const;

   void setShowGuideAxis(const EcBoolean enabled);

   /// Load the scene.
   void loadScene
      (
      );

   /// Get the pointer to the simulation thread, allows realtime access control
   /// of the thread.
   Ec::AsyncThread * simulationThread
      (
      );

   /// Get the pointer to the simulation thread, allows realtime access control
   /// of the thread.
   Ec::AsyncThread * pluginThread
      (
      Ec::Plugin * plugin  ///< Plugin to find the thread of.
      );

Q_SIGNALS:
   void signalLoadScene();              ///< Issued when scene has been loaded (Ec::Plugin::initState)
   void signalSimulationChanged(EcU32); ///< Issued when simulation has been changed
   void signalSimulationEnabled(bool);  ///< Alternative to signal[Start,Stop]Simulation
   void signalPauseSimulation();        ///< Issued when simulation is paused
   void signalStartSimulation();        ///< Issued when simulation is started
   void signalStopSimulation();         ///< Issued when simulation is stopped
   void signalActiveManipulatorChanged(EcU32);
   void signalActiveEndEffectorChanged(EcU32);

   // These methods provide a bridge between base simulation signals and Qt-based signals.
   void connectSignalControlMethodChanged(EcU32, EcU32);
   void connectSignalControlDescriptionChanged(EcU32, EcU32);
   void connectSignalControlSystemChanged();
   void connectSignalEndEffectorSetChanged(EcU32, EcU32);
   void connectSignalManipulatorAdded(const QString&);
   void connectSignalManipulatorDeleted(EcU32);
   void connectSignalSimulationPause();
   void connectSignalSimulationStart();
   void connectSignalSimulationStop();
   void connectSignalSimulationTimeStep(double);
   void connectSignalSimulationStateChanged(EcU32);

public Q_SLOTS:
   void addManipulator(const EcString& label);
   void deleteManipulator(EcU32 manIndex);
   void reloadSimulation();             ///< Reload simulation, when changes have been made
   void startSimulation();              ///< Start the simulation
   void pauseSimulation();              ///< Pause the simulation
   void stopSimulation();               ///< Stop the simulation
   void stopAndResetSimulation();       ///< Stop the simulation and reset to home
   void deleteContents();               ///< Clean up when closing/reloading
   EcBasePreferencePage* newPreferencePage(); ///< Creator method for preferences

protected Q_SLOTS:
   void updateSimulationActions(EcU32 simRunState);

protected:
   Ui::simulationToolBar* m_pUi;                               ///< UI controls
   EcSimulationCore* m_pSim;                                   ///< Simulation handle
   EcU32 m_SelectedArm;                                        ///< Selected manipulator
   EcU32 m_SelectedEndEffectorID;                              ///< Selected EE index
   EcBoolean m_ResetDesiredGuideFrames;                        ///< Reset to actual when stopped
};

#endif // simulationPlugin_H_
