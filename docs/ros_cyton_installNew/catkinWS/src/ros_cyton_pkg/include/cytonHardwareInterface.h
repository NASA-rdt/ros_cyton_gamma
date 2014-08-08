#ifndef cytonHardwareInterface_H_
#define cytonHardwareInterface_H_
//------------------------------------------------------------------------------
//     Copyright (c) 2008-2011 Energid Technologies. All rights reserved.
//
/// @file cytonHardwareInterface.h
//
/// @class cyton::hardwareInterface
//
/// @brief Hardware interface that provides control over Cyton hardware.
//
//------------------------------------------------------------------------------
#include <cytonTypes.h> // Pull in definitions of variable types.

#if defined(WIN32)
#  pragma warning(disable:4251) // exporting stl objects within a dll
#endif

namespace Ec { class Plugin; }  ///< Forward declaration of plugin class.    
class EcIODataBroker;

/// Namespace for all Cyton-specific code.
namespace cyton
{

class BaseIO;

enum InitAndShutdownModeEnum
{
   InitFromSimulation = 0x01, ///< Start in position from ecz file
   InitFromHardware   = 0x02, ///< Synch simulation to real hw position
   InitMask           = 0x0f,

   ShutdownToHome     = 0x10, ///< Move arm to init/start position
   TorqueDisable      = 0x40, ///< Disable torque on exit
   ShutdownMask       = 0xf0
};
typedef EcU32 InitAndShutdownMode; ///< Bitfields to hold parameters

class CYTON_DECL hardwareInterface
{
public:
   /// Constructor.  Does not initialize hardware.
   /// @param[in] pluginName Name of hardware plugin to utilize
   /// @param[in] configFile Optional hardware configuration file
   explicit hardwareInterface
      (
      const EcString& pluginName,
      const EcString& configFile = ""
      );

   /// Destructor.  Shuts down device driver if loaded.
   virtual ~hardwareInterface
      (
      );

   /// Specify a port to use for the connection to the hardware.
   /// @param[in] port String name of port to use.  Platform dependent
   virtual void setPort
      (
      const EcString& port
      );

   /// Examine current hardware configuration to list available ports.
   /// @return EcStringVector A vector of string representing the port names
   ///                        of the devices available.  Platform dependent.
   ///                        Empty list returned if not available, or plugin not loaded.
   virtual EcStringVector availablePorts
      (
      ) const;

   /// Override config defaults and specify a new set of init and shutdown
   /// options. Options are bit-ORed together.
   /// @param[in] mode Specified override parameters
   virtual void setInitAndShutdownMode
      (
      const InitAndShutdownMode mode
      );

   /// Accessor to retrieve state of init and shutdown parameters.
   /// @return InitAndShutdownMode ORed bitfields of modes
   virtual InitAndShutdownMode initAndShutdownMode
      (
      ) const;

   /// Initialize hardware, which includes reading in configuration file, opening
   /// the port and resetting hardware to a known good state.
   /// @return EcBoolean Success or failure of initialization
   virtual EcBoolean init
      (
      );

   /// Send a reset command to the hardware to move joints back to resting position.
   /// @return EcBoolean Success or failure of reset command
   virtual EcBoolean reset
      (
      );

   /// Unloads plugin device driver.  
   /// @return EcBoolean Success or failure of shutdown command
   virtual EcBoolean shutdown
      (
      );

   /// Controls overall torque control.  When disabled, servo motors will be
   /// free-spinning.  Use with caution as this may damage hardware if not
   /// supported.
   /// @param[in] enabled Desired torque state
   /// @return EcBoolean Success or failure of set command
   virtual EcBoolean setTorque
      (
      const EcBoolean enabled
      );

   /// This method is used to set a time difference that will be used when
   /// subsequent setJointCommands calls are made to calculate an appropriate
   /// set of joint velocities.  The time given also represents the amount of
   /// time (approximate) that the hardware will take to reach the desired
   /// joint state.
   /// @param[in] deltaT Time difference used to calculate joint rates
   virtual void setVelocityFromDeltaTime
      (
      const EcReal deltaT
      );

   /// Performs unit conversion from the specified type and returns the values
   /// in radians.
   /// @param[in] jointAngles Input angles to process
   /// @param[in] stateType Format that the input angles are in
   /// @return EcRealVector Vector of joint angles in radians
   EcRealVector convertUnits
      (
      const EcRealVector& jointAngles,
      StateType stateType
      ) const;

   /// Sends commands to Cyton hardware to move joints to a specified location.
   /// If the joint velocities are not specified, then the velocity values will
   /// be calculated based upon the previous call to setVelocityFromDeltaTime().
   /// All input values are in radians (and radians-per-degree).
   /// In the case where the delta time has never been explicitly set, the
   /// value of 20 seconds will be used.
   /// @param[in] jointCommands Vector of joint angles to move servos to
   /// @param[in] jointVelocities (Optional) Vector of joint velocities
   /// @return EcBoolean Success or failure of set command
   virtual EcBoolean setJointCommands
      (
      const EcRealVector& jointCommands,
      const EcRealVector& jointVelocities = EcRealVector()
      );

   /// DEPRECATED
   /// This command has been replaced with the following commands:
   /// setVelocityFromDeltaTime(time)
   /// convertUnits(jointCommands, stateType) - Optional
   /// setJointCommands(jointCommands, jointVelocities)
   /// The time difference calculation for joint rates is now explicitly
   /// done in a separate call.  Also there is a separate convenience command
   /// for performing units conversion.
   ///
   /// Sends commands to Cyton hardware to move joints to a specified location.
   /// A time difference is calculated from the previous command to determine
   /// the rate at which to move the joints.
   /// @param[in] timeNow Current time
   /// @param[in] jointCommands Vector of joint angles to move servos to
   /// @param[in] stateType Optional unit conversion for input jointCommands
   /// @return EcBoolean Success or failure of set command
   virtual EcBoolean setJointCommands
      (
      const EcReal timeNow,
      const EcRealVector& jointCommands,
      const StateType stateType = JointAngleInRadians
      );

   /// Retrieve servo information.  Depending on the stateType parameter
   /// it will return the last commanded position (default) or any of the
   /// configuration parameters for the servos (joint bias, min angle,
   /// max angle, reset angle, max joint rate, joint scale).
   /// @param[out] jointStates Vector of returned values
   /// @param[in]  stateType Type and unit of requested values
   /// @return EcBoolean Success or failure of query command
   virtual EcBoolean getJointStates
      (
      EcRealVector& jointStates,
      const StateType stateType = JointAngleInRadians
      ) const;

   /// Wait for the last command to finish, up to a specified maximum
   /// time in milliseconds.
   /// @param[in] timeoutInMS Maximum time to wait in milliseconds before failing
   /// @return EcBoolean Success or failure of wait command
   virtual EcBoolean waitUntilCommandFinished
      (
      const EcU32 timeoutInMS
      ) const;

   /// Retrieve the number of joints currently configured.
   /// @return EcU32 Number of joints in the loaded system
   virtual EcU32 numJoints
      (
      ) const;

   explicit hardwareInterface
      (
      Ec::Plugin* plugin
      );

   /// Retrieve a handle to the loaded plugin.
   /// @return Ec::Plugin* The loaded plugin
   Ec::Plugin* plugin
      (
      );

private:
   /// Bitfield options that hold whether or not to override parameters
   /// within the configuration file when initializing hardware.  Currently
   /// the only override parameters are the port device and resetOnShutdown flag.
   enum OverrideEnum
   {
      OverrideNone = 0x0, ///< Pull everything from config file
      OverridePort = 0x1, ///< User specified port
      OverrideMode = 0x2, ///< User specified init and shutdown mode
   };
   typedef EcU32 OverrideType; ///< Variable type to hold override options.
   
   /// Load the internal plugin to interface with the Cyton hardware.
   /// @return EcBoolean Success or failure of load command
   EcBoolean loadPlugin
      (
      ) const;

   /// Mechanism to configure newly-loaded plugins.
   void preConfigureCB
      (
      );

   /// Enable settings after reading config file.
   void postConfigureCB
      (
      );

   EcBoolean m_Initialized;         ///< Whether the plugin loaded successfully.
   EcString m_PortName;             ///< Platform-dependent description of port device
   EcString m_PluginName;           ///< Name of plugin to use
   EcString m_ConfigFile;           ///< Configuration file for system
   InitAndShutdownMode m_OverrideMode; ///< Initialization and shutdown mode
   OverrideType m_OverrideConfig;   ///< If port or reset specified, override config file
   EcReal m_DeltaTime;              ///< Used to calculate joint rates
   EcU32 m_NumSimJoints;            ///< Number of simulation joints
   EcRealVector m_vPrevJoints;      ///< Previous joint angles
   EcIODataBroker* m_pBroker;
   mutable BaseIO* m_pPlugin;       ///< Handle to base device driver to process commands
};

} // namespace cyton

#endif // cytonHardwareInterface_H_
