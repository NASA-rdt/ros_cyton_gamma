#ifndef ec_HardwarePlugin_H_
#define ec_HardwarePlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwarePlugin.h
/// @brief Provides an abstract class that provides base-level
///        capability for dealing with hardware-connected devices.
//
//------------------------------------------------------------------------------
#include "ecHardwarePluginDataElement.h"
#include "ecHardwarePluginTypes.h"
#include <foundCore/ecConnectionManagerTypes.h>
#include <foundCore/ecElapsedTime.h>
#include <foundCore/ecPlugin.h>

namespace Ec
{

/// Base Implementation class used to provide minimum capability for loading.
/// It holds a pointer to the loading helper class to provide access to the
/// plugin name as well as the ability to unload when finished.
class EC_ACTIN_HWPLUGIN_DECL HardwarePlugin : public Plugin
{
public:
   /// @copydoc Ec::Plugin::init
   /// Tries to load configuration file if it exists.
   EcBoolean init
      (
      );

   /// Available method to immediately notify simulation of hardware state.
   /// It is typically used as an emergency stop.
   virtual void setImmediateSimulationState
      (
      );

   /// This abstract method is used to initialize hardware.  It is called
   /// within init() after trying to load in a configuration file.  If this
   /// method returns successfully, then it will enable and set the
   /// state variables.
   /// @return HardwareStatus Success or failure of command
   virtual HardwareStatus initImplementation
      (
      ) = 0;

   /// This abstract method is used to process hardware-specific interfacing
   /// and read in associated state data to pass back to the simulation.  This
   /// is used during init when mode is InitFromHardware as well as for
   /// closed-loop feedback.
   /// @return HardwareStatus Success or failure of command
   virtual HardwareStatus getFromHardwareImplementation
      (
      ) = 0;

   /// This abstract method is used to take simulation data and send it to
   /// the hardware.  Used during initState when mode is InitFromSimulation
   /// and also called during update().
   /// @return HardwareStatus Success or failure of command
   virtual HardwareStatus setToHardwareImplementation
      (
      ) = 0;

   /// Returns the number of joints configured.
   EcU32 numJoints
      (
      ) const;

   /// Allows setting of configuration values
   /// @param[in] hwConfig Replacement config values
   void setHardwareConfig
      (
      const HardwareConfigBaseVector& hwConfig
      );

   /// Accessor to configuration values
   /// @return Ec::HardwareConfigVector& Config values
   const HardwareConfigBaseVector& hardwareConfig
      (
      ) const;

   /// return whether an error has occurred
   virtual EcBoolean errorOccurred
      (
      ) const;

   /// clear the errorOccurred flag
   virtual void clearError
      (
      );

   /// get the error messages from hardware
   EcStringVector errorMessages
      (
      ) const;

   /// Command the hardware to perform a coordinate joint move to the specified
   /// position.  NOTE: No constrained joints should be passed in.
   /// @param[in] jointAngles Desired set position
   /// @param[in] switchBackWhenFinished Put old control descriptor back after
   ///                                   the coordinated move finishes
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean setToCoordinatedJointPosition
      (
      const EcRealVector& jointAngles,
      const EcBoolean switchBackWhenFinished = EcFalse
      );

   /// Cancels the coordinated joint move in progress.
   /// @return EcBoolean EcTrue if it was able to cancel or if not in progress
   virtual EcBoolean cancelCoordinatedJointPosition
      (
      );

   /// Configure this plugin from a file.
   /// @return HardwareStatus Success or failure
   virtual HardwareStatus configureFromFile
      (
      );

   /// Create a configuration for this plugin.  Can be overridden by subclasses
   /// to automatically generate one if it doesn't exist.
   /// @return EcBoolean Success or failure of command
   virtual void createConfigFile() { }

   /// Store configuration parameters into file.
   /// @return HardwareStatus Success or failure
   virtual HardwareStatus saveConfigurationToFile
      (
      ) const;

   /// Specify a port to use for the connection to the hardware.
   void setPortName
      (
      const EcString& portName ///< [in] Platform-dependent name of port to use
      );

   /// Return the currently set port.  Platform dependent name.
   /// @return EcString Currently set port
   EcString portName
      (
      ) const;

   /// Return the currently set manipulator index.
   /// @return EcU32 Currently set manipulator index
   EcU32 manipIndex
      (
      ) const;

   /// Set the status update interval.  A value of 0 means do not utilize
   /// a status interval.
   void setStatusUpdate
      (
      const EcU32 updateInMs ///< [in] Update interval to set
      );

   /// Return the status update interval in MS
   /// @return EcU32 Update interval
   EcU32 statusUpdate
      (
      ) const;

   /// Set the control descriptor for joint control.
   /// A joint control descriptor is required for homing.
   void setJointControlDescriptorID
      (
      const EcU32 controlDescriptorID ///< [in] Descriptor ID for homing
      );

   /// Return the control descriptor for joint control.
   /// A joint control descriptor is required for homing.
   /// @return EcU32 jointControlDescriptorID
   EcU32 jointControlDescriptorID
      (
      ) const;

   /// Set the initialization and shutdown values.
   void setInitAndShutdownMode
      (
      const InitAndShutdownMode mode ///< [in] Bit flags for configuration
      );

   /// Retrieve initialization and shutdown values.
   /// @return Ec::InitAndShutdownMode Bit flags for configuration
   InitAndShutdownMode initAndShutdownMode
      (
      ) const;

   /// Set the enabled state of the hardware.  When hardware goes from a
   /// disabled state to enabled, it must be done in a careful manner to
   /// make sure that it is able to reach the new state safely.  It only
   /// allows or prohibits state information to be passed to hardware, it
   /// doesn't perform any other consistency check or power management.
   /// @param[in] enabled Whether to enable or disable hardware
   void setEnabled
      (
      const EcBoolean enabled
      );

   /// Determines whether the hardware is actively sending and receiving
   /// simulation updates.
   /// @return EcBoolean Enabled state of hardware plugin
   EcBoolean enabled() const { return m_Enabled; }

   /// Sets internal configuration filename
   /// @param[in] filename File to use to load in configuration.
   void setConfigFilename(const EcString& filename) { m_ConfigFilename = filename; }

   /// Retrieve the configuration file name.
   const EcString& configFilename() const { return m_ConfigFilename; }

   /// This overridable method is used to perform conversion of Actin values
   /// before translation into hardware units when passing from Actin->HW.
   /// Translation to hardware units happens per-joint, where this method is
   /// intended to operate across more than one joint.
   /// @param[in,out] values Actin joint values to convert.
   virtual void convertFromActinValues(EcRealVector& values) const {}

   /// This overridable method is used to perform conversion of Actin values
   /// after translation from hardware units when passing from HW->Actin.
   /// Translation from hardware units happens per-joint, where this method is
   /// intended to operate across more than one joint.
   /// @param[in,out] values Actin joint values to convert.
   virtual void convertToActinValues(EcRealVector& values) const {}

   /// Provide capability to call code during periods when hardware is disabled.
   virtual void updateDisabledImplementation() {}

   /// Hook to provide simulation startup initialization.  This method is called
   /// at the beginning of initState().
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean initStateImplementation() { return EcTrue; }

   /// Device-specific code for properly powering off hardware.
   /// @return HardwareStatus Success or failure of command
   virtual HardwareStatus powerOffImplementation() { return HardwareStatusOk; }

   /// Device-specific code for customizing behavior when shutting down the
   /// hardware device.  This method is called at the beginning of a shutdown
   /// and it provides a way to perform any pre-shutdown operation or cancel
   /// the shutdown.  Standard shutdown operations will still be called, such
   /// as torque disable as well as power down, as specified in the config
   /// parameter InitAndShutdownMode.
   /// @return HardwareStatus Shutdown procedure will be canceled with a failure code
   virtual HardwareStatus shutdownImplementation() { return HardwareStatusOk; }

   /// Device-specific code for customizing behavior when hardware is enabled
   /// or disabled.  An unsuccessful return code indicates some failure and
   /// the internal state will be set to disabled.
   /// @param[in] enable State that hardware is transitioning into
   /// @return HardwareStatus Success or failure of command
   virtual HardwareStatus hardwareEnableImplementation(const EcBoolean enable) { return HardwareStatusOk; }

   /// Device-specific code for turning torque on and off in hardware.
   /// @param[in] enable Disable or enable torque on motors
   /// @return HardwareStatus Success or failure of command
   virtual HardwareStatus torqueEnableImplementation(const EcBoolean enable) { return HardwareStatusOk; }

   /// Device-specific code for issuing an immediate stop of hardware.
   /// @return HardwareStatus Success or failure of command
   virtual HardwareStatus emergencyStopImplementation() { return HardwareStatusOk; }

   /// This method will poll until the last issued command has finished.
   /// The timeout value is the maximum wait time before failing.
   /// @param[in] timeout   Maximum time to wait(ms) before declaring failure.
   /// @return    EcBoolean Success or failure of wait command.
   virtual HardwareStatus waitUntilCommandFinished(const EcU32 timeout) const { return HardwareStatusOk; }

   /// virtual method to read the hardware status.  It is called
   /// by hardwareStatus method and should be implemented in machine specific
   /// subclasses of this plugin
   /// @return EcBoolean Whether hardware failed and should be disabled
   virtual HardwareStatus readHardwareStatus() const { return m_HardwareStatus; }

protected:
   /// @copydoc Ec::Plugin::Plugin()
   HardwarePlugin
      (
      );

   /// @copydoc Ec::Plugin::initState()
   /// Non-virtual initState method that provides specific implementation.  It
   /// It first calls initStateImplementation() and if that succeeds proceeds
   /// to set simulation and/or hardware values based on the InitStateAndMode
   /// value.  torqueEnableImplementation(EcTrue) is also called here.
   /// DO NOT REPLACE!
   EcBoolean initState
      (
      );

   /// @copydoc Ec::Plugin::update(const EcReal)
   /// Non-virtual update method that provides specific implementation.  It
   /// calls setToHardwareImplementation() and will also call
   /// getFromHardwareImplementation() at specified intervals to pass feedback
   /// state to simulation.
   /// DO NOT REPLACE!
   void update
      (
      const EcReal time
      );

   /// @copydoc Ec::Plugin::shutdown()
   /// Non-virtual shutdown method that provides specific implemention.  It
   /// performs shutdown procedure for hardware device based upon the
   /// parameters set. Calls powerOffImplementation().
   /// DO NOT REPLACE!
   EcBoolean shutdown
      (
      );

   /// Temporary virtual method to remove any constrained joints before being
   /// passed to the coordinated joint movement routine.
   /// @return EcRealVector Reduced vector of joint angles
   virtual EcRealVector removeConstrainedJoints
      (
      const EcRealVector& jointAngles ///< [in] Incoming joints
      ) const { return jointAngles; }

   /// Stores hardware messages
   /// @return EcBoolean Whether current status is OK
   EcBoolean setHardwareStatus
      (
      const HardwareStatus status ///< [in] Status to set
      ) const;

   /// Method to check the hardware status.  This is essentially a test
   /// of the health of the hardware. It is called at the
   /// statusUpdatefrequency. Client and h/w specific code in readHardwareStatus.
   HardwareStatus hardwareStatus
      (
      ) const;

   /// halt control from Actin
   virtual void haltControl
      (
      );

   EcBoolean m_Enabled;                     ///< if plugin is enabled
   EcBoolean m_JustEnabled;                 ///< if is just enabled
   EcReal m_CurrentTime;                    ///< Current time
   EcString m_ConfigFilename;               ///< File to use when loading data
   mutable EcMutex m_Mutex;                 ///< Thread-safe access to set/get
   mutable EcU32 m_NumJoints;               ///< Number of Actin joints configured
   EcElapsedTime m_Timer;                   ///< Timer for accessing status
   EcBoolean m_ErrorOccurred;               ///< Flag indicating an error has occured
   Ec::HardwarePluginDataElement m_Data;    ///< Data container for servos
   EcU32 m_ControlDescription;              ///< Cache of the control description
   mutable HardwareStatus m_HardwareStatus; ///< Last hardware status flag

   // List of signals that this class currently emits
   /// hardware enable signal
   ConnectionManagerTypes::Signal<SignalHardwareEnableTraits::Type>::PtrType m_SignalEnablePtr;
   /// hardware preconfig signal
   ConnectionManagerTypes::Signal<SignalHardwarePreConfigTraits::Type>::PtrType m_SignalPreConfigPtr;
   /// hardware postconfig signal
   ConnectionManagerTypes::Signal<SignalHardwarePostConfigTraits::Type>::PtrType m_SignalPostConfigPtr;
   /// hardware status signal
   ConnectionManagerTypes::Signal<SignalHardwareStatusTraits::Type>::PtrType m_SignalStatusPtr;
   /// hardware emergency stop signal
   ConnectionManagerTypes::Signal<SignalHardwareEStopTraits::Type>::PtrType m_SignalEStopPtr;
};

} // namespace Ec

#endif // ec_HardwarePlugin_H_
