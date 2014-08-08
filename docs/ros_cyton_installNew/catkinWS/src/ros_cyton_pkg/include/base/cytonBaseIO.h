#ifndef cyton_BaseIO_H_
#define cyton_BaseIO_H_
//------------------------------------------------------------------------------
//     Copyright (c) 2009-2011 Energid Technologies. All rights reserved.
//
/// @file cytonBaseIO.cpp
//
/// @class cyton::BaseIO
//
/// @brief cyton::BaseIO device driver that controls Cyton arm.  Provides
//         methods to configure, set or query parameters from hardware.
//
//------------------------------------------------------------------------------
#include <hardwarePlugin/ecHardwarePlugin.h>
#include <cytonTypes.h>

namespace cyton
{

class BaseIO : public Ec::HardwarePlugin
{
public:
   /// Constructor
   BaseIO
      (
      );

   /// @copydoc Ec::HardwarePlugin::initState()
   virtual EcBoolean initState
      (
      );

   /// @copydoc Ec::HardwarePlugin::initImplementation()
   virtual Ec::HardwareStatus initImplementation
      (
      );

   /// Set the serial baud rate.
   void setBaudRate
      (
      const EcU32 baudRate ///< [in] Baud rate to set in bps
      );

   /// Return the current serial baud rate.
   /// @return EcU32 Baud rate in bps
   EcU32 baudRate
      (
      ) const;

   /// Retrieve a list of available serial ports.
   /// @return EcStringVector Vector of serial ports on this system.  Platform dependent.
   const EcStringVector& deviceList
      (
      ) const;

   /// Mechanism by which gripper joint information can be retrieved to
   /// properly account for 2 moving joints within manipConfigPlugin.
   std::set<EcU8> getGripperJoints
      (
      ) const;

   /// Virtual method so that it is available to subclasses.  Used during
   /// zero-torque (assistive) mode to set gripper values while the rest
   /// of the arm is managed by user.
   virtual void setGripperPosition
      (
      const EcU32 linkIndex, ///< [in] Link that is attached to gripper
      const EcReal value     ///< [in] Value to set gripper to
      ) {}

protected:
   /// @copydoc Ec::HardwarePlugin::removeConstrainedJoints(const EcRealVector&)
   EcRealVector removeConstrainedJoints
      (
      const EcRealVector& jointAngles
      ) const;

   mutable EcStringVector m_DeviceList; ///< List of available ports
};

} // namespace cyton

#endif // cyton_BaseIO_H_
