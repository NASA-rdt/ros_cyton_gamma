#ifndef ec_RemoteCommand_H_
#define ec_RemoteCommand_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecRemoteCommand.h
/// @brief Set of remote commands to issue to Actin over a network.
//
//------------------------------------------------------------------------------
#include <foundCore/ecTypes.h>

#if !defined(EC_NO_ACTIN) && !defined(EC_NO_BOOST)
#  include <boost/function.hpp>
#endif

#if defined(plugins_remoteCommand_EXPORTS)
#  define EC_REMOTECOMMANDAPI_DECL EC_DECL_EXPORTS
#else
#  define EC_REMOTECOMMANDAPI_DECL EC_DECL_IMPORTS
#endif

class EcEndEffectorPlacement;
class EcManipulationActionManager;
class EcManipulationDirector;
class EcManipulationScript;
class EcManipulatorEndEffectorPlacement;

namespace Ec
{
/// This command is required before any of the other RemoteCommand.  It
/// initializes the connection between client and server (hardware) end.
/// @param[in] ipAddress Server address to connect to
/// @return EcBoolean Success or failure of initialization
EC_REMOTECOMMANDAPI_DECL EcBoolean init(const EcString& ipAddress = "127.0.0.1");

/// Cleans up memory associated with network connection.
EC_REMOTECOMMANDAPI_DECL void shutdown();

/// Send joint angles to the hardware.  By default it will send it to the
/// first manipulator.
/// @param[in] joints Vector of EcReal joint values in radians
/// @param[in] manipIndex Index of manipulator to set
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setJointValues(const EcRealVector& joints, const EcU32 manipIndex = 0);

/// Send joint angles to the hardware.  By default it will send it to the
/// first manipulator.
/// @param[in] joints Vector of EcReal joint values in radians
/// @param[in] amount of memory at joints (max) to fill).
/// @param[in] manipIndex Index of manipulator to set
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setJointValuesABI(EcReal *joints, EcU32 jointSize, const EcU32 manipIndex = 0);

/// Get the number of joints for a given manipulator index.
EC_REMOTECOMMANDAPI_DECL EcU32 getNumJoints(const EcU32 manipIndex = 0);

/// Retrieve joint angles from the server.  By default it will retrieve them
/// from the first manipulator.  Joint velocities can also be retrieved.
/// @param[out] joints Vector of EcReal joint values in radians
/// @param[in] manipIndex Index of manipulator to set
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean getJointValues(EcRealVector& joints, EcU32 manipIndex = 0);

/// Send joint angles to the hardware.  By default it will send it to the
/// first manipulator.
/// @param[in] joints Vector of EcReal joint values in radians
/// @param[in] amount of memory at joints (max) to fill).
/// @param[in] manipIndex Index of manipulator to set
/// @return size of the joints that were available to copy, can be bigger than jointSize or < 0 on failure.
EC_REMOTECOMMANDAPI_DECL EcInt32 getJointValuesABI(EcReal *joints, EcU32 jointSize, const EcU32 manipIndex = 0);

/// Specify a control descriptor to use for a particular manipulator.
/// @param[in] descriptor Descriptor index
/// @param[in] manipIndex Index of manipulator to set
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setControlDescriptor(const EcU32 descriptor, const EcU32 manipIndex = 0);

/// Specify the end-effector set to use for a particular manipulator.
/// @param[in] eeSet End-effector set index
/// @param[in] manipIndex Index of manipulator to set
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setEndEffectorSet(const EcU32 eeSet, const EcU32 manipIndex = 0);

/// Specify a manipulation path file to use.
/// @param[in] filename Filename to of path file to load
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setManipulationPathFile(const EcString& filename);

/// Start a manipulation task specified previously with setManipulationScript(),
/// setManipulationAction(), or setManipulationPathFile().  No other
/// manipulation commands are allowed to be issued once a sequence has started
/// except stopManipulation().  If a manipulation completion callback
/// was registered, the completion status of the sequence will be sent when
/// finished.
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean startManipulation();

/// Stops a manipulation script that is in progress from
/// startManipulation(). If a manipulation completion callback was
/// registered, it will receive a hpcsm::StatusFailed message due to premature
/// termination.
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean stopManipulation();

/// Set the hardware enabled state.
/// @param[in] enable State to set the hardware in
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setHardwareEnable(const EcBoolean enable);

#if !defined(EC_NO_ACTIN) && !defined(EC_NO_BOOST)
//-----------------------------------------------------------------------------
// The following commands require the Actin SDK.
//-----------------------------------------------------------------------------

/// Set the desired end-effector placement for a single end-effector of a manipulator.  The simulation will then generate
/// joint values (position and velocity) to move the EE from the current
/// placement to the desired one.
/// @param[in] placement Placement to set
/// @param[in] manipIndex Manipulator to target
/// @param[in] endIndex End-effector to target
EC_REMOTECOMMANDAPI_DECL EcBoolean setDesiredPlacement(const EcEndEffectorPlacement& placement, const EcU32 manipIndex = 0, const EcU32 endIndex = 0);

/// Set the desired end-effector placement for a manipulator (possibly several end-effectors).
/// The simulation will then generate joint values (position and velocity) to move the EE from the current
/// placement to the desired one.
/// @param[in] placement Placement to set
/// @param[in] manipIndex Manipulator to target
EC_REMOTECOMMANDAPI_DECL EcBoolean setDesiredPlacement(const EcManipulatorEndEffectorPlacement& placement, const EcU32 manipIndex = 0);

/// Retrieve the Desired end-effector placement.  This is computed from the
/// joint angles of the manipulator.
/// @param[in] placement Placement to retrieve
/// @param[in] manipIndex Manipulator to target
EC_REMOTECOMMANDAPI_DECL EcBoolean getDesiredPlacement(EcManipulatorEndEffectorPlacement& placement, const EcU32 manipIndex = 0);

/// Retrieve the actual end-effector placement.  This is computed from the
/// joint angles of the manipulator.
/// @param[in] placement Placement to retrieve
/// @param[in] manipIndex Manipulator to target
EC_REMOTECOMMANDAPI_DECL EcBoolean getActualPlacement(EcManipulatorEndEffectorPlacement& placement, const EcU32 manipIndex = 0);

/// Function signature for receiving manipulation completed messages.  The
/// completion value and a pointer to user data (specified at registration)
/// will be passed in as the arguments.
typedef boost::function<void (EcBoolean, void*)> ManipulationCompleteCB;

/// Specify a manipulation director to use.
/// @param[in] director Director to use
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setManipulationDirector(const EcManipulationDirector& director);

/// Specify a manipulation script to use.
/// @param[in] script Script to use
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setManipulationScript(const EcManipulationScript& script);

/// Specify a manipulation action manager to use.
/// @param[in] manager Manipulation action manager to use
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setManipulationActionManager(const EcManipulationActionManager& manager);

/// Specify a name of manipulation action to execute. The action name must be in the action manager. Thus, this must
/// be called AFTER a call to setManipulationActionManager.
/// @param[in] actionName Name of manipulation action to execute.
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setManipulationAction(const EcString& actionName);

/// Optional callback registration to be notified when a manipulation action
/// has finished.  The callback argument value will receive either EcTrue for a
/// successful completion, or EcFalse for prematurely-terminated or failure.
/// @param[in] cb Callback function to register
/// @param[in] data Optional pointer to user data to pass along
/// @return EcBoolean Whether this command was successfully issued
EC_REMOTECOMMANDAPI_DECL EcBoolean setManipulationCompletedCallback(ManipulationCompleteCB cb, void* data = NULL);

#endif

} // namespace rds

#endif // ec_RemoteCommand_H_
