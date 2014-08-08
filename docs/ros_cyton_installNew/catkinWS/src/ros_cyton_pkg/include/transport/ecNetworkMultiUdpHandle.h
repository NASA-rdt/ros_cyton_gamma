#ifndef ec_network_MultiUdpHandle_H_
#define ec_network_MultiUdpHandle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkMultiUdpHandle.h
/// @class Ec::network::MultiUdpHandle
/// @brief Pseudo multicast solution providing point-to-point sockets
///        from one server to multiple clients.
//
//------------------------------------------------------------------------------
#include "ecNetworkUdpHandle.h"

namespace Ec { namespace network {

class OpaqueMultiUdpHandle;

class EC_FOUNDATION_TRANSPORT_DECL MultiUdpHandle : public UdpHandle
{
public:
   /// @copydoc Ec::network::UdpHandle::UdpHandle(const Ec::network::NetworkMode)
   MultiUdpHandle
      (
      const NetworkMode mode = LocalMode
      );

   /// Destructor to properly handle virtual disconnect.
   ~MultiUdpHandle
      (
      );

   /// @copydoc Ec::network::UdpHandle::disconnect()
   void disconnect
      (
      );

   /// @copydoc Ec::network::UdpHandle::read(char*, const EcU32)
   EcInt32 read
      (
      char* buf,
      const EcU32 size
      );

   /// @copydoc Ec::network::UdpHandle::read(char*, const EcU32)
   /// Also returns address of incoming data.
   EcInt32 read
      (
      char* buf,        ///< [in] Allocated buffer to store data
      const EcU32 size, ///< [in] Size of requested read
      EcString& addr    ///< [in] IP Address of incoming data
      );

   using UdpHandle::write;
   /// @copydoc Ec::network::UdpHandle::write(const char*, const EcU32)
   /// Optional target IP address and port to send to a single destination.
   /// If port is not specified or set to 0, it will look at the existing
   /// connection list to determine the port.
   EcInt32 write
      (
      const char* buf,           ///< [in] Buffer to data to send
      const EcU32 size,          ///< [in] Size of requested write
      const EcString& addr = "", ///< [in] IP Address of target client
      EcU16 port = 0             ///< [in] Port of client to write to
      );

   /// Provides way to access single client information when using the stream
   /// operator for writing.  See usage below.
   /// @return    Opaque handle to object giving access to operator<<() call.
   OpaqueMultiUdpHandle& operator[]
      (
      const EcString& addr ///< [in] IP Address of connected client
      );

   /// @copydoc Ec::network::UdpHandle::operator<<(const EcString&)
   Handle& operator<<
      (
      const EcString& str
      );

   /// Retrieve the number of active connections.
   /// @return size_t Number of client connections
   size_t numConnections() const { return m_SocketMap.size(); }

   /// connection names
   EcStringVector connectionNames() const;

   /// Attempt to remove a client based upon its ipAddress
   void disconnect
      (
      const EcString& ipAddress
      );

protected:
   typedef std::map<EcString, EcU16> SocketMap;  ///< map template for sockets
   SocketMap m_SocketMap;              ///< Collection of connected clients
   OpaqueMultiUdpHandle* m_pOpaque;    ///< opaque handle
};

/// Provide convenience stream operator for a single client.  Uses the form:
///    handle["ipAddress"] << str;
/// where handle and str are:
///    Ec::network::MultiUdpHandle handle;
///    EcString str = "some string data";
EC_FOUNDATION_TRANSPORT_DECL void operator<<
   (
   OpaqueMultiUdpHandle& oh, ///< [in] Opaque handle provided from operator[] above
   const EcString& str       ///< [in] String object to be written to network.
   );

} } // namespace Ec::network

#endif // ec_network_MultiUdpHandle_H_
