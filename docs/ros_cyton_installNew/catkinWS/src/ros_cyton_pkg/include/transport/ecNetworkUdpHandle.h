#ifndef ec_network_UdpHandle_H_
#define ec_network_UdpHandle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkUdpHandle.h
/// @class Ec::network::UdpHandle
/// @brief EcUdpSocket-based networking implementation.  It has a separate
///        thread to provide non-blocking behavior.
//
//------------------------------------------------------------------------------
#include "ecNetworkHandle.h"

namespace Ec { namespace network {

class EC_FOUNDATION_TRANSPORT_DECL UdpHandle : public Handle
{
public:
   /// @copydoc Ec::network::Handle::Handle(const Ec::network::NetworkMode)
   UdpHandle
      (
      const NetworkMode mode = LocalMode
      );

   /// Destructor
   virtual ~UdpHandle
      (
      );

   /// @copydoc Ec::network::Handle::listen()
   virtual EcBoolean listen
      (
      );

   /// @copydoc Ec::network::Handle::connectToHost()
   virtual EcBoolean connectToHost
      (
      );

   /// @copydoc Ec::network::Handle::disconnect()
   virtual void disconnect
      (
      );

   /// @copydoc Ec::network::Handle::isConnected()
   EcBoolean isConnected
      (
      ) const;

   /// @copydoc Ec::network::Handle::dataAvailable()
   virtual EcBoolean dataAvailable
      (
      ) const;

   /// @copydoc Ec::network::Handle::read(char*, const EcU32)
   virtual EcInt32 read
      (
      char* buf,
      const EcU32 size
      );

   /// @copydoc Ec::network::Handle::write(const char*, const EcU32)
   virtual EcInt32 write
      (
      const char* buf,
      const EcU32 size
      );

protected:
   void onActionNewConnection(); ///< Handles new server connection requests
   void onActionProcessRead();   ///< Reads from socket and invokes callback

   EcString m_ClientIPAddress;   ///< Return address to use when run as server
   EcU16 m_ClientPort;           ///< Return port to use when run as server
};

} } // namespace Ec::network

#endif // ec_network_UdpHandle_H_
