#ifndef ec_network_Params_H_
#define ec_network_Params_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkParams.h
/// @class Ec::network::Handle
/// @brief Base level networking capability.  Defines the types of
///        messages that can be sent and received as well as the
///        general methods in use for all protocols.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <foundCore/ecTypes.h>

namespace Ec { namespace network {

/// Default port to use for protocols that require it.
static const EcU16 Port     = 7654;
/// Default preamble to use for protocols that require it.
static const EcU32 Preamble = 0xec7654ec;

/// Unique message identifier.  Gives indication on what to do with data.
typedef EcU32 MessageType; ///< Provide specific size for msg type
typedef EcU32 NetworkMode; ///< Provide specific size for network mode

/// 16-byte header indicating the network message
struct EC_FOUNDATION_TRANSPORT_DECL MessageHeader
{
   const EcU32 preamble;   ///< header signature
   MessageType msgType;    ///< Type of message
   NetworkMode mode;       ///< Current network mode
   EcU32 size;             ///< Assume <2GB payload

   /// default constructor
   MessageHeader
      (
      );

   /// constructor
   MessageHeader
      (
      const MessageType _msgType,
      const EcU32 _size,
      const NetworkMode _mode = 0
      );
};

/// Different networking modes available
enum NetworkModeEnum
{
   LocalMode      = 0x000, ///< Networking turned off
   ClientMode     = 0x001, ///< Send data, get state if needed
   ServerMode     = 0x002, ///< Receive data, set state, return if requested
   ModeMask       = 0x007, ///< Mask of network configuration

   /// Modifiers
   NeedAck        = 0x008, ///< Client wants acknowledgement of messages
   NeedInitState  = 0x010, ///< Server sends initialization state upon connection
   NeedState      = 0x020, ///< Server needs to return state data
   SendState      = 0x040, ///< Client sends state data instead of EE
   SendView       = 0x080, ///< Client sends eyepoint data
   SendSimData    = 0x100, ///< Client sends xml simulation data
   SendSimFile    = 0x200, ///< Client sends simulation filename
   ModifierMask   = 0x2f8, ///< Mask to retrieve modifiers

   /// Convenience enumerations
   ThinClientMode = ClientMode|NeedState|NeedInitState,     ///< No processing on client, gets state
   MasterMode     = ServerMode|SendState|SendView, ///< Broadcasts state to clones
   NetworkMask    = ModifierMask|ModeMask,         ///< Mask of lower bits
   /// Network ID, if used is located in the upper 16 bits of the network mode
   NetworkIDMask  = 0xffff0000
};

/// network state
enum NetworkState
{
   NetworkDisconnected,  ///< Not connected
   NetworkDisconnecting, ///< In process of shutting down
   NetworkListening,     ///< Actively listening on a socket
   NetworkAccepting,     ///< Processing connecting
   NetworkConnected      ///< Currently connected
};

/// Current set of in-use protocols.
enum NetworkProtocol
{
   UdpProtocol,  ///< Connection-less protocol
   TcpProtocol,  ///< Connection-oriented protocol
   SkypeProtocol ///< Connection-oriented protocol
};

} } // namespace Ec::network

#endif // ec_network_Params_H_
