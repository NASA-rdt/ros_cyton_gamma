#ifndef ec_network_MultiTcpHandle_H_
#define ec_network_MultiTcpHandle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkMultiTcpHandle.h
/// @class Ec::network::MultiTcpHandle
/// @brief Pseudo multicast solution providing point-to-point sockets
///        from one server to multiple clients.
//
//------------------------------------------------------------------------------
#include "ecNetworkTcpHandle.h"

#include <boost/enable_shared_from_this.hpp>

namespace Ec { namespace network {

class EC_FOUNDATION_TRANSPORT_DECL MultiTcpHandle : public TcpHandle, public boost::enable_shared_from_this<MultiTcpHandle>
{
public:
   /// Multi-connected function.  The argument is the child handle that is
   /// receiving the data.
   typedef boost::function< void (TcpHandle*) > MultiNetworkCallback;
   /// Register a function to be called when a child is disconnected.
   typedef boost::function< void (const EcU32, const EcString&) > ChildDisconnectCallback;
   /// boost shared pointer template for TCP handle
   typedef boost::shared_ptr<TcpHandle> SharedHandle;

   /// @copydoc Ec::network::TcpHandle::TcpHandle(const Ec::network::NetworkMode)
   MultiTcpHandle
      (
      const NetworkMode mode = LocalMode
      );

   /// Destructor to properly handle virtual disconnect.
   ~MultiTcpHandle
      (
      );

   /// @copydoc Ec::network::TcpHandle::disconnect()
   void disconnect
      (
      );

   /// @copydoc Ec::network::TcpHandle::isConnected() const
   EcBoolean isConnected
      (
      ) const;

   /// @copydoc Ec::network::Handle::write(const char*, const EcU32)
   /// Writes same data out to all connections.
   EcInt32 write
      (
      const char* buf,
      const EcU32 size
      );

   /// write to shared handle
   /**
   \param[in] id shared handle
   \param[in] buf buffer to data to send
   \param[in] size size of requested write
   \return error status
   */
   EcInt32 write
      (
      const EcString& id,
      const char* buf,
      const EcU32 size
      );

   // Include base class method as well.
   using TcpHandle::sendBuffer;
   using Handle::sendXmlObject;

   /// @copydoc Ec::network::Handle::sendBuffer(const Ec::network::MessageType, const EcString&)
   EcBoolean sendBuffer
      (
      const EcString& id,     ///< [in] ID of connection to target
      const MessageType type, ///< [in] Enumeration of payload type
      const EcString& message ///< [in] Payload data
      );

   /// @copydoc Ec::network::Handle::sendXmlObject(const Ec::network::MessageType, const EcXmlObject&)
   EcBoolean sendXmlObject
      (
      const EcString& id,     ///< [in] ID of connection to target
      const MessageType type, ///< [in] Enumeration of payload type
      const EcXmlObject& obj  ///< [in] Payload data
      );

   /// @copydoc Ec::network::TcpHandle::setCallback(NetworkCallback)
   void setCallback
      (
      MultiNetworkCallback fun
      );

   /// Automatically registers a signal for the child handle to notify when
   /// it gets disconnected.
   void setChildDisconnectCallback
      (
      ChildDisconnectCallback fun
      );

   /// Retrieve the number of active connections.
   /// @return size_t Number of client connections
   size_t numConnections() const { return m_SocketMap.size(); }

   /// connection names
   EcStringVector connectionNames() const;

   /// Generate an ID based upon the IP address and port
   EcString makeId
      (
      const EcU32 port,
      const EcString& ipAddress
      ) const;

   /// Retrieve a handle to the child socket associated with this id.
   /// @return SharedHandle Shared handle to socket
   SharedHandle childSocket
      (
      const EcString& id
      );

protected:
   /// constructor
   MultiTcpHandle
      (
      EcTcpSocket* sock,
      MultiNetworkCallback fun
      );

   /// Handles new server connection requests
   void onActionNewConnection
      (
      );

   /// Reads from socket and invokes callback
   void onActionChildProcessRead();

   /// Handles child socket disconnections. Cleans up SocketMap.
   void onActionDisconnected
      (
      const EcU32 port,         ///< [in] Port of disconnected handle
      const EcString& ipAddress ///< [in] Address of disconnected handle
      );

   /// map template for sockets
   typedef std::map<EcString, SharedHandle> SocketMap;

   SocketMap m_SocketMap;                ///< Collection of connected clients
   MultiNetworkCallback m_MultiCallback; ///< Registered callback method
   ChildDisconnectCallback m_ChildDisconnectCallback; ///< call back for child disconnect
};

} } // namespace Ec::network

#endif // ec_network_MultiTcpHandle_H_
