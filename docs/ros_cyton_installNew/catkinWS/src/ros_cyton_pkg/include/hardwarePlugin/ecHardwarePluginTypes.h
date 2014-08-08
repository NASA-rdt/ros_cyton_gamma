#ifndef ec_HardwarePluginTypes_H_
#define ec_HardwarePluginTypes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwarePluginTypes.h
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>
#include <foundCore/ecTypes.h>

#include <boost/mpl/string.hpp>

namespace Ec
{

/// Enumerations for hardware paremeter type
enum HardwareParamTypeEnum
{
   HardwareUnits = 0x8000 ///< Specify that param given is in hw units
};

/// Enumerations for initialization and shutdown behavior
enum InitAndShutdownModeEnum
{
   InitFromSimulation = 0x01, ///< Set hardware to simulation position
   InitFromHardware   = 0x02, ///< Set simulation from hardware position
   InitDisabled       = 0x04, ///< Start up in a disabled state
   InitStateToHome    = 0x08, ///< Startup hardware value sets homing angles
   InitMask           = 0x0f,

   ShutdownToHome     = 0x10, ///< Move arm to home position on exit
   PowerOff           = 0x20, ///< Attempt to power off hardware on exit
   TorqueDisable      = 0x40, ///< Turn off torque on exit
   ShutdownMask       = 0xf0
};

/// type define of InitAndShutdownMode
typedef EcU32 InitAndShutdownMode;

/// Some basic enumerations of standard errors.  Users are free to expand the
/// usage as long as the values are beyond HardwareStatusEnd.
enum HardwareStatusEnum
{
   HardwareStatusOk            = 0,  ///< Successful
   HardwareStatusNoPort        = 1,  ///< Unable to connect to port
   HardwareStatusBadConfig     = 2,  ///< Configuration file error
   HardwareStatusIncompatState = 3,  ///< Incompatible simulation state
   HardwareStatusReadError     = 4,  ///< Error when reading from hardware
   HardwareStatusWriteError    = 5,  ///< Error when writing to hardware
   HardwareStatusWaitTimeout   = 6,  ///< Timed out waiting for hardware to complete move
   HardwareStatusHalted        = 7,  ///< Hardware is in a halted state
   HardwareStatusActinError    = 8,  ///< Error generated from simulation API
   HardwareStatusGeneralError  = 90, ///< Uncategorized error
   HardwareStatusEnd           = 99  ///< Custom values placed after this
};

/// type define of HardwareStatus
typedef EcU32 HardwareStatus;


#ifndef WIN32
// Avoid getting warnings from gcc related to the use of multichar below.
// FIXME: I would like to use "diagnostic ignored"; however, the pragma does not seem to work.
//        system_header is a bit heavy-handed here.
//#  pragma GCC diagnostic ignored "-Wmultichar"
#  pragma GCC system_header
#endif
// NOTE: Must split Name into groups of 4 (or fewer) characters.

//------------------------------------------------------------------------------
/// Signal for hardware enable/disable change
/// @param enabled
struct SignalHardwareEnableTraits
{
   /// type definition of Name
   typedef boost::mpl::string<'sign', 'alEn', 'able'> Name;
   /// type definition of (Type)(const EcBoolean enabled)
   typedef void (Type)(const EcBoolean enabled);
};

//------------------------------------------------------------------------------
/// Signal indicating that the hardware status has changed
/// @param status
struct SignalHardwareStatusTraits
{
   /// type definition of Name
   typedef boost::mpl::string<'sign', 'alSt', 'atus'> Name;
   /// type definition of (Type)(const HardwareStatus status)
   typedef void (Type)(const HardwareStatus status);
};

//------------------------------------------------------------------------------
/// Signal indicating Emergency Stop has been issued
struct SignalHardwareEStopTraits
{
   /// type definition of Name
   typedef boost::mpl::string<'sign', 'alES', 'top'> Name;
   /// type definition of (Type)()
   typedef void (Type)();
};

//------------------------------------------------------------------------------
/// Signal issued immediately before loading configuration from file
struct SignalHardwarePreConfigTraits
{
   /// type definition of Name
   typedef boost::mpl::string<'sign', 'alPr', 'eCon', 'fig'> Name;
   /// type definition of (Type)()
   typedef void (Type)();
};

//------------------------------------------------------------------------------
/// Signal issued immediately after loading configuration from file
struct SignalHardwarePostConfigTraits
{
   /// type definition of Name
   typedef boost::mpl::string<'sign', 'alPo', 'stCo', 'nfig'> Name;
   /// type definition of (Type)()
   typedef void (Type)();
};

} // namespace Ec

#endif // ec_HardwarePluginTypes_H_
