#ifndef ec_network_TcpHandle_H_
#define ec_network_TcpHandle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkTcpHandle.h
/// @class Ec::network::TcpHandle
/// @brief EcTcpSocket-based networking implementation.  It has a separate
///        thread to provide non-blocking behavior.
//
//------------------------------------------------------------------------------
#include "ecNetworkHandle.h"
#include <foundCore/ecConnectionManagerTypes.h>
#include <foundCore/ecFoundCoreSignals.h>

class EcTcpSocket;

namespace Ec { namespace network {

class EC_FOUNDATION_TRANSPORT_DECL TcpHandle : public Handle
{
public:
   /// @copydoc Ec::network::Handle::Handle(const Ec::network::NetworkMode)
   TcpHandle
      (
      const NetworkMode mode = LocalMode
      );

   /// Destructor
   virtual ~TcpHandle
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
   /// Handles new server connection requests
   virtual void onActionNewConnection
      (
      );

   /// Reads from socket and invokes callback
   void onActionProcessRead();

   EcTcpSocket* m_pTcpServer;    ///< Server listening handle

   /// connect signal pointer
   ConnectionManagerTypes::Signal<SignalNetworkConnectTraits::Type>::PtrType m_NetworkConnectSignalPtr;
   /// disconnect signal pointer
   ConnectionManagerTypes::Signal<SignalNetworkDisconnectTraits::Type>::PtrType m_NetworkDisconnectSignalPtr;
};

} } // namespace Ec::network

#endif // ec_network_TcpHandle_H_
