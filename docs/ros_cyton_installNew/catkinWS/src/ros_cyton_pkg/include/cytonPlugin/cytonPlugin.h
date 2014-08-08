#ifndef cytonPlugin_H_
#define cytonPlugin_H_
//     Copyright (c) 2008-2010 Energid Technologies. All rights reserved. ////
//
// Filename:    cytonPlugin.h
//
// Description: Plugin device driver that controls cyton arm.  Provides
//              methods to configure, set or query parameters from hardware.
//
// Contents:    cytonPlugin class
//
/////////////////////////////////////////////////////////////////////////
#include <base/cytonBaseIO.h>

class EC_PLUGIN_DECL cytonPlugin : public cyton::BaseIO
{
public:
   EcU32Vector checkServoTorques
      (
      const EcU32 transitionTemperature
      );

   EcU8Vector checkServoErrors
      (
      );

   void setGripperPosition
      (
      const EcU32 servoIndex,
      const EcReal value
      );

protected:
   /// Constructor.
   cytonPlugin
      (
      );

   virtual Ec::HardwareStatus startupCheck
      (
      );

   /// Called to shut down the hardware.  sets low torque mode
   /// values to pass back to simulation.
   /// @return EcBoolean Success or failure of command
   virtual Ec::HardwareStatus shutdownImplementation
      (
      );
   /// Called to power down the hardware.  sets low torque mode
   /// values to pass back to simulation.
   /// @return EcBoolean Success or failure of command
   virtual Ec::HardwareStatus powerOffImplementation
      (
      );
   /// Called to sync simulation with hardware.  Retrieves hardware joint
   /// values to pass back to simulation.
   /// @return EcBoolean Success or failure of get command
   Ec::HardwareStatus getFromHardwareImplementation
      (
      );

   /// Called to sync hardware with simulation.  Sends commands to move joints
   /// to a specified location.
   /// @return EcBoolean Success or failure of set command
   Ec::HardwareStatus setToHardwareImplementation
      (
      );

   /// Initialize hardware, which includes reading in configuration file, opening
   /// serial port and resetting hardware to a known good state.
   /// \return EcBoolean Success or failure of initialization.
   virtual Ec::HardwareStatus initImplementation
      (
      );

   /// This method will poll the servos until the last issued command
   /// has finished.  The timeout value is the maximum wait time before failing.
   /// \param[in] msTimeout   Maximum time to wait(ms) before declaring failure.
   /// \return    EcBoolean Success or failure of wait command.
   virtual Ec::HardwareStatus waitUntilCommandFinished
      (
      const EcU32 msTimeout
      ) const;

   /// @copydoc Ec::HardwarePlugin::torqueEnableImplementation()
   Ec::HardwareStatus torqueEnableImplementation
      (
      const EcBoolean enable
      );
  
   /// @copydoc Ec::HardwarePlugin::readHardwareStatus()
   /// Used in cytonPlugin to provide temp-torque-voltage control
   /// and error reporting
   virtual Ec::HardwareStatus readHardwareStatus() const;

   /// @copydoc Ec::Plugin::threadingStarted(EcIODataBroker * dataBroker)
   /// Used in cytonPlugin to set the real time threading mode and rate
   virtual void threadingStarted(EcIODataBroker * dataBroker);

   EcRealVector m_JointCommands;
   EcRealVector m_JointVelocities;
   EcBoolean m_TorqueEnabled;
   EcBoolean m_InAssistiveMode;
   mutable EcU32Vector  m_ServoTorqueData;
   mutable EcU8Vector   m_ServoErrorData;
   EcU32 m_TransitionTemperature;
   EcU32 m_PowerOffTorque;
};

#endif // cytonPlugin_H_
