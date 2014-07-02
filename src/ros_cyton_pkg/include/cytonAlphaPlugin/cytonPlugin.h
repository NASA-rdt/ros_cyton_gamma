#ifndef cytonAlphaPlugin_H_
#define cytonAlphaPlugin_H_
//     Copyright (c) 2008-2011 Energid Technologies. All rights reserved. ////
//
// Filename:    cytonPlugin.h
//
// Description: Plugin device driver that controls Cyton arm.  Provides
//              methods to configure, set or query parameters from hardware.
//
// Contents:    cytonAlphaPlugin class
//
/////////////////////////////////////////////////////////////////////////
#include <base/cytonBaseIO.h>

class EC_PLUGIN_DECL cytonAlphaPlugin : public cyton::BaseIO
{
protected:
   /// Constructor.
   cytonAlphaPlugin
      (
      );

   /// @copydoc cyton::BaseIO::waitUntilCommandFinished()
   Ec::HardwareStatus waitUntilCommandFinished
      (
      const EcU32 timeout
      ) const;

   /// @copydoc cyton::BaseIO::getFromHardwareImplementation()
   Ec::HardwareStatus getFromHardwareImplementation
      (
      );

   /// @copydoc cyton::BaseIO::setToHardwareImplementation()
   Ec::HardwareStatus setToHardwareImplementation
      (
      );

   /// @copydoc cyton::BaseIO::powerOffImplementation()
   Ec::HardwareStatus powerOffImplementation
      (
      );

private:
   /// Sends a command to the hardware through the serial port.
   /// @param[in] rawCmd Low level command sent directly to hardware.
   /// @return    EcU8   Return response byte.
   EcU8 sendRawCommand
      (
      const EcString& rawCmd
      ) const;

   EcRealVector m_PreviousJointAngles;
};

#endif // cytonAlphaPlugin_H_
