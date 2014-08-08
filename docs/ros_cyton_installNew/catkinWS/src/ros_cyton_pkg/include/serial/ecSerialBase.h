#ifndef ecSerialBase_H_
#define ecSerialBase_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSerialBase.h
/// @class EcSerialBase
/// @brief Abstract serial port base class.
/// @details Provides interface for all serial port devices.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

class EC_STABLE_SERIAL_DECL EcSerialBase
{
public:
   /// Specify the type of serial connection.
   enum IoType
   {
      Raw,    ///< Raw I/O
      Select, ///< Reads wait on select call for data or timeout
      Aio     ///< Asynchronous I/O
   };

   /// Specify serial connection parity.
   enum ParityType
   {
      ParityNone, ///< No parity
      ParityEven, ///< Even parity
      ParityOdd   ///< Odd parity
   };

   /// Constructor.
   EcSerialBase
      (
      const IoType iotype = Aio ///< [in] I/O style to use
      );

   /// Destructor.
   virtual ~EcSerialBase
      (
      );

   /// Opens the serial port with a previously set device name and also sets
   /// the device attributes.
   /// @return Success or failure of command
   virtual EcBoolean connect
      (
      );

   /// Interface for platform-specific port open command.
   /// @return Success or failure of command
   virtual EcBoolean open
      (
      const EcString& device ///< [in] Name of device to open
      ) = 0;

   /// Interface for platform-specific port close command.
   /// @return Success or failure of command
   virtual EcBoolean close
      (
      ) = 0;

   /// Sets internal attributes for this serial port.
   void storeDeviceAttributes
      (
      const EcU32 baud          = 38400UL,    ///< [in]
      const EcU32 minChars      = 0,          ///< [in]
      const EcBoolean canonical = EcFalse,    ///< [in]
      const EcBoolean blocking  = EcFalse,    ///< [in]
      const ParityType parity   = ParityNone, ///< [in]
      const EcU32 timeout       = 500000UL    ///< [in] In microseconds
      );

   /// Applies existing attributes to newly-opened connection.
   /// @return Success or failure of command
   virtual EcBoolean setDeviceAttributes
      (
      ) = 0;

   /// Performs read based upon IoType.
   /// @return Returns -1 on port error, or number of actual bytes read
   EcInt32 read
      (
      void* buffer,                        ///< [out] Buffer to store data
      const EcInt32 length,                ///< [in] Max amount to read
      const EcBoolean exactCount = EcFalse ///< [in] Force exact read size
      );

   /// Performs write based upon IoType.
   /// @return Returns -1 on port error, or number of actual bytes written
   EcInt32 write
      (
      const void* buffer,  ///< [in] Buffer of source data
      const EcInt32 length ///< [in] Size of buffer to write
      );

   /// Write a string to the serial port.  Uses the c_str() and length() and
   /// passes that into general write method.
   /// @return Success or failure of command
   EcBoolean write
      (
      const EcString& str ///< [in] String to write
      );

   /// Retrieves the baud rate set previously.
   /// @return Baud rate
   EcU32 getBaud
      (
      ) const;

   /// Specify the device name to use
   void setDeviceName
      (
      const EcString& deviceName ///< [in] Platform-specific name of port
      );

   /// Retrieve the device name for this port
   /// @return Device name
   const EcString& deviceName
      (
      ) const;

   /// Platform-specific list of available devices.
   /// @return String vector of available devices
   virtual const EcStringVector& availableDevices
      (
      ) const;

   /// Whether this port is currently open or not
   /// @return Success or failure of command
   EcBoolean opened
      (
      ) const;

   /// Provides detailed printout of port characteristics.
   void dump
      (
      ) const;

   /// Interface for flushing input and output buffers.
   virtual void flush
      (
      ) = 0;

protected:
   /// Interface for reading raw IoType.
   /// @copydoc read(void*, const EcInt32, const EcBoolean)
   virtual EcInt32 readRaw
      (
      void* buffer,
      const EcInt32 length,
      const EcBoolean exactCount
      ) = 0;

   /// Interface for reading select IoType.
   /// @copydoc read(void*, const EcInt32, const EcBoolean)
   virtual EcInt32 readSelect
      (
      void* buffer,
      const EcInt32 length,
      const EcBoolean exactCount
      ) = 0;

   /// Interface for reading asynchronous IoType.
   /// @copydoc read(void*, const EcInt32, const EcBoolean)
   virtual EcInt32 readAio
      (
      void* buffer,
      const EcInt32 length,
      const EcBoolean exactCount
      ) = 0;

   /// Interface for writing raw IoType.
   /// @copydoc write(const void*, const EcInt32)
   virtual EcInt32 writeRaw
      (
      const void* buffer,
      const EcInt32 length
      ) = 0;

   /// Interface for writing select IoType.
   /// @copydoc write(const void*, const EcInt32)
   virtual EcInt32 writeSelect
      (
      const void* buffer,
      const EcInt32 length
      ) = 0;

   /// Interface for writing asynchronous IoType.
   /// @copydoc write(const void*, const EcInt32)
   virtual EcInt32 writeAio
      (
      const void* buffer,
      const EcInt32 length
      ) = 0;

   EcString m_DeviceName;       ///< Platform-specific device name of port
   EcU32 m_Baud;                ///< Speed of serial port
   EcBoolean m_IsOpened;        ///< Whether port is opened or not
   IoType m_IoType;             ///< Type of I/O used for this port
   EcBoolean m_InCanonicalMode; ///< If we are in terminal mode
   EcBoolean m_Blocking;        ///< Whether we block on I/O or not
   EcInt32 m_MinChars;          ///< Number of required I/O before finished
   ParityType m_Parity;         ///< Parity checking type
   EcU32 m_Timeout;             ///< Timeout in us when waiting for I/O

   mutable EcStringVector m_AvailableDevices; ///< Cached values for devices
};

#endif // ecSerialBase_H_
