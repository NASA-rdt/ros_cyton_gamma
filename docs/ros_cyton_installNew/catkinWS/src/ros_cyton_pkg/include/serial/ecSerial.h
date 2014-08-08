#ifndef ecSerial_H_
#define ecSerial_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSerial.h
/// @class EcSerial
/// @brief Serial port implementation.
/// @details Provides I/O capability for serial ports.
//
//------------------------------------------------------------------------------
#include "ecSerialBase.h"
#ifdef WIN32
#  include <windows.h>
#else // OSX and Linux
struct termios;
#endif

class EC_STABLE_SERIAL_DECL EcSerial : public EcSerialBase
{
public:
   /// @copydoc EcSerialBase::EcSerialBase(const IoType)
   EcSerial
      (
      const IoType iotype = Aio
      );

   /// Destructor.
   virtual ~EcSerial
      (
      );

   /// @copydoc EcSerialBase::open(const EcString&)
   virtual EcBoolean open
      (
      const EcString &device
      );

   /// @copydoc EcSerialBase::close()
   virtual EcBoolean close
      (
      );

   /// @copydoc EcSerialBase::setDeviceAttributes()
   virtual EcBoolean setDeviceAttributes
      (
      );

   /// @copydoc EcSerialBase::availableDevices()
   virtual const EcStringVector &availableDevices
      (
      ) const;

   /// @copydoc EcSerialBase::flush()
   virtual void flush
      (
      );

protected:
   /// @copydoc EcSerialBase::readRaw(void*, const EcInt32, const EcBoolean)
   virtual EcInt32 readRaw
      (
      void *buffer,
      const EcInt32 length,
      const EcBoolean exactCount
      );

   /// @copydoc EcSerialBase::readSelect(void*, const EcInt32, const EcBoolean)
   virtual EcInt32 readSelect
      (
      void *buffer,
      const EcInt32 length,
      const EcBoolean exactCount
      );

   /// @copydoc EcSerialBase::readAio(void*, const EcInt32, const EcBoolean)
   virtual EcInt32 readAio
      (
      void *buffer,
      const EcInt32 length,
      const EcBoolean exactCount
      );

   /// @copydoc EcSerialBase::writeRaw(const void*, const EcInt32)
   virtual EcInt32 writeRaw
      (
      const void *buffer,
      const EcInt32 length
      );

   /// @copydoc EcSerialBase::writeSelect(const void*, const EcInt32)
   virtual EcInt32 writeSelect
      (
      const void *buffer,
      const EcInt32 length
      );

   /// @copydoc EcSerialBase::writeAio(const void*, const EcInt32)
   virtual EcInt32 writeAio
      (
      const void *buffer,
      const EcInt32 length
      );

#ifdef WIN32
   HANDLE m_Handle;          ///< Handle to COM port
   DCB m_Dcb;                ///< Device Control Block
#else
   EcInt32 m_FD;             ///< File descriptor for this port
   struct termios *m_NewTIO; ///< New settings for this device
   struct termios *m_OldTIO; ///< Old settings for this device
#endif
};

#endif // ecSerial_H_
