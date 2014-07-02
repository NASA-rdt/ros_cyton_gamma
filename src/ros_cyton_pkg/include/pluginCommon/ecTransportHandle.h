#ifndef ec_network_TransportHandle_H_
#define ec_network_TransportHandle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecTransportHandle.h
/// @class Ec::network::TransportHandle
/// @brief Base level networking capability. Defines the types of messages that
///        can be sent and received as well as the manner in which that will happen.
//
//------------------------------------------------------------------------------
#include <control/ecCoordinatedJointEndEffectorTool.h>
#include <foundCore/ecConnectionManagerTypes.h>
#include <foundCore/ecMacros.h>
#include <plugins/ecPluginSignals.h>
#include <transport/ecNetworkParams.h>

#include <boost/shared_ptr.hpp>

#ifdef EC_BUILD_SHARED_LIBS
#  ifdef plugins_pluginCommon_EXPORTS
#    define EC_PLUGINS_PLUGINCOMMON_DECL EC_DECL_EXPORTS
#  else
#    define EC_PLUGINS_PLUGINCOMMON_DECL EC_DECL_IMPORTS
#  endif
#else
#  define EC_PLUGINS_PLUGINCOMMON_DECL
#endif

namespace Ec {

class Plugin;

namespace network {

class Handle;

class EC_PLUGINS_PLUGINCOMMON_DECL TransportHandle
{
public:
   /// Constructor.  The network handle passed in will be managed from
   /// the transport, so it will take care of cleaning up memory for it.
   TransportHandle
      (
      Ec::Plugin& plugin, ///< [in] Owning plugin
      Handle* pNetwork    ///< [in] Handle to network
      );

   /// Destructor
   virtual ~TransportHandle
      (
      );

   /// Specify a new network handle.  Replaces previous handle.
   void setNetwork
      (
      Handle* pNetwork ///< [in] Replacement network handle
      );

   /// disconnect from network
   void disconnect
      (
      );

   /// Determine connected state of transport
   EcBoolean isConnected
      (
      ) const;

   /// Message and message ID to send across the network.
   /// @return EcBoolean Success or failure of command
   EcBoolean sendToNetwork
      (
      const MessageType msgType,   ///< [in] Unique message identifier
      const EcString& message = "" ///< [in] Message to be sent
      );

   /// Parameterized method to properly serialize and push data out across the
   /// network.
   /// @return EcBoolean Success or failure of command
   template <typename T> EcBoolean sendToNetwork
      (
      const MessageType msgType, ///< [in] Unique message identifier
      const T& value             ///< [in] Data to be serialized
      );

   /// State initialization.  This method should be called when parameters
   /// have changed and renegotiation is required.
   /// @return EcBoolean Success or failure of command
   EcBoolean init
      (
      );

   /// This method should be called to perform regular updates based on the
   /// network state.
   void update
      (
      const EcReal time ///< [in] Current simulation timestep
      );

   /// Called within update method to synchronize client state with server side.
   /// @return EcBoolean Success or failure of command
   EcBoolean sendHandshake
      (
      );

   /// Sets flag to determine if updates should be done on an as-needed basis
   /// or always performed.
   void setForceUpdate
      (
       const EcBoolean forceUpdate ///< [in] Whether to force an update or not
       );

   /// Wait until last command was received by other end and acknowledgement
   /// received.  A timeout value of -1 indicated wait forever (default).
   /// @return EcBoolean Success or failure of wait
   EcBoolean waitForAck
      (
      const EcU32 timeout = -1 ///< [in] Duration in milliseconds to wait for ack
      );

   /// Send acknowledgement response from server to client if mode parameters
   /// are set accordingly.  Otherwise a no-op.
   /// @return EcBoolean Success or failure of command
   EcBoolean sendAck
      (
      const EcBoolean status = EcTrue ///< [in] Response value to send
      );

   /// Underlying network handle access.
   /// @return Handle* Handle to internal protocol
   Handle* handle
      (
      );

protected:
   /// Internal routine to process incoming network, place it in a receive string
   /// buffer and process.  If an unknown message comes through and a custom
   /// callback in registered via setCallback, then it will invoke the callback
   /// with the unprocessed EcString.
   void processFromNetwork
      (
      );

   /// Perform any manipulation of message before standard dispatch.
   /// This is a virtual method that does nothing by default.
   /// Example manipulation includes addition of latency
   /// \return false if message unavailable
   virtual EcBoolean manipulateFromNetwork
      (
      MessageHeader& hdr ///< [out] potentially modified message header
      );

   /// General parameterized method to unpack data from network.
   /// @return EcBoolean Whether command was successful or not
   template <typename T> EcBoolean deserialize
      (
      T& value ///< [out] Resultant object coming from network stream
      ) const;

   /// Internal method to handle standard incoming messages.
   template <EcU32 msgType> void process
      (
      );

   /// send attachment change to network
   void sendAttachmentChange
      (
      const EcManipulatorAttachmentChange& change
      );

   /// Forwarder signals
   void signalConnect(const EcU32 port, const EcString& ipAddress);
   void signalDisconnect(const EcU32 port, const EcString& ipAddress);

   Plugin& m_Plugin;                       ///< Owning plugin for API access
   boost::shared_ptr<Handle> m_pNetwork;   ///< Provide safe pointer handling
   EcBoolean m_HandshakeCompleted;         ///< Whether handshaking is good
   EcBoolean m_ForceUpdate;                ///< Used to trigger forced state updates
   EcCondition m_Condition;                ///< Blocking for ack messages
   EcMutex m_Mutex;                        ///< Mutex for ack messages
   EcMutex m_CallbackMutex;                ///< Mutex to safeguard callback
   EcMutex m_NetworkMutex;                 ///< Mutex for pNetwork

   /// To convert joint angles to controllable joint angles
   EcCoordinatedJointEndEffectorTool      m_JointEeTool;

   ConnectionManagerTypes::Signal<SignalNetworkMessageTraits::Type, SignalNetworkMessageTraits::Combiner>::PtrType m_NetworkMessageSignalPtr;
   ConnectionManagerTypes::Signal<SignalNetworkCustomMessageTraits::Type, SignalNetworkCustomMessageTraits::Combiner>::PtrType m_NetworkCustomMessageSignalPtr;
   ConnectionManagerTypes::Signal<SignalNetworkCustomMessageTraits::Type, SignalNetworkCustomMessageTraits::Combiner>::PtrType m_GlobalNetworkCustomMessageSignalPtr;
   ConnectionManagerTypes::Signal<SignalNetworkConnectTraits::Type>::PtrType m_NetworkConnectSignalPtr;
   ConnectionManagerTypes::Signal<SignalNetworkDisconnectTraits::Type>::PtrType m_NetworkDisconnectSignalPtr;
};

typedef boost::scoped_ptr<TransportHandle> ScopedTransport;

} } // namespace Ec::network

#endif // ec_network_TransportHandle_H_
