#ifndef ec_network_Handle_H_
#define ec_network_Handle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkHandle.h
/// @class Ec::network::Handle
/// @brief Base level networking capability. Defines the types of messages that
///        can be sent and received as well as general methods.
//
//------------------------------------------------------------------------------
#include "ecNetworkParams.h"
#include <foundCore/ecMutex.h>

#include <boost/function.hpp>

class EcSocketBase;
class EcXmlObject;
namespace boost { class thread; }

namespace Ec { namespace network {

class EC_FOUNDATION_TRANSPORT_DECL Handle
{
public:
   /// Current max buffer size for inbound packets.
   const static size_t MAX_MSG_SIZE = 65536;

   /// Nullary function to specify callback for network messages.
   typedef boost::function< void () > NetworkCallback;

   /// Constructor
   /// @param[in] mode Optional mode to start in
   Handle
      (
      const NetworkMode mode = LocalMode
      );

   /// Destructor
   virtual ~Handle
      (
      );

   /// Retrieves the current network mode.  The network mode is not explicitly
   /// set.  It is set internally based on the methods being used.  LocalMode
   /// is the default state until a listen (server) or connetToHost (client)
   /// method has been called.
   /// @return NetworkMode Currently set network mode.
   NetworkMode networkMode
      (
      ) const;

   /// Sets network ID for this network handle.
   void setNetworkID
      (
      const EcU16 id ///< [in] Unique ID for this handle
      );

   /// Retrieves the current network ID.  It is properly retrieved from the mode
   /// variable and formatted appropriately.  When in use, it serves as a unique
   /// identifier when connecting a client and server together.  The server will
   /// only accept network traffic from clients using the same ID.
   /// @return EcU16 Currently set network ID.
   EcU16 networkID
      (
      ) const;

   /// Sets modifiers to the current network mode.
   void setNetworkModifiers
      (
      const NetworkMode mode ///< [in] Optional modifiers to set
      );

   /// Set the IP address
   void setNetworkAddress
      (
      const EcString& address ///< [in] Address to assign
      );

   /// Get the IP address
   /// @return EcString& String representation of address
   const EcString& networkAddress
      (
      ) const;

   /// Set the port number
   /// @param[in] port Port to assign
   void setPort
      (
      const EcU16 port
      );

   /// Get the port number in use
   EcU16 port
      (
      ) const;

   /// Retrieve current state of the network
   /// @return NetworkState Enumerated state of the network handle
   NetworkState networkState
      (
      ) const;

   /// Set a callback method to be called when data is available on the
   /// network connection.
   void setCallback
      (
      NetworkCallback fun ///< [in] Callback invoked when data comes in
      );

   /// Set a callback method to be called when the connection terminates.
   /// This is only called when the handle is in server mode.
   void setDisconnectCallback
      (
      NetworkCallback fun ///< [in] Callback invoked when connection is terminated
      );

   /// Server-side method that will listen for incoming connections.
   /// If a callback handler was registered, then it will spawn
   /// a separate thread to handle the connection.  Otherwise it will
   /// block until an incoming request is made.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean listen
      (
      ) = 0;

   /// Client-side connection-oriented method that attempts to connect
   /// to a server using previously-supplied or default values.
   /// If a callback handler was registered, then on
   /// success it will spawn a separate thread to handle return messages.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean connectToHost
      (
      ) = 0;

   /// Close down and terminate the existing connection (if any).
   /// Cleans up any memory or resources related to the connection.
   virtual void disconnect
      (
      ) = 0;

   /// For connection-oriented protocols, checks to make sure that the
   /// connection is still up and valid.  For connection-less protocols,
   /// it should simply return EcTrue.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean isConnected
      (
      ) const = 0;

   /// Lets the caller know if there is data available for reading
   /// @return EcBoolean EcTrue if data is available to read
   virtual EcBoolean dataAvailable
      (
      ) const = 0;

   /// Generic read operation from the network connection.
   /// @return EcInt32 -1 on failure or the number of bytes actually read
   virtual EcInt32 read
      (
      char* buf,       ///< [in] Allocated buffer to store data
      const EcU32 size ///< [in] Size of requested read

      ) = 0;

   /// Method to process incoming data into fully-formed packets.  This
   /// will store the completed packet into m_InputString.
   /// @return EcInt32 Number of bytes left to read, or -1 on error
   EcInt32 readIntoBuffer
      (
      MessageHeader& hdr ///< [out] Header information
      );

   /// Method to package a message up including header information.
   /// @return EcBoolean Success or failure of command
   EcBoolean sendBuffer
      (
      const MessageType type,              ///< [in] Enumeration of payload type
      const EcString& message = EcString() ///< [in] Payload data
      );

   /// Method to package an EcXmlObject including header information.
   /// @return EcBoolean Success or failure of command
   EcBoolean sendXmlObject
      (
      const MessageType type, ///< [in] Enumeration of payload type
      const EcXmlObject& obj  ///< [in] Payload data
      );

   /// Get handle to input data stream.
   EcString& inputString() const;

   /// Set handle to input data stream.
   void setInputString(const EcString& input);

   /// Get handle to output data stream.
   EcString& outputString();

   /// Generic write operation to the network.  For client connection-oriented
   /// protocols, the connect() method must have already been issued.
   /// For server side, the listen() method must have been issued.
   /// @return EcInt32 -1 on failure or the number of bytes actually written
   virtual EcInt32 write
      (
      const char* buf, ///< [in] Buffer to data to send
      const EcU32 size ///< [in] Size of requested write
      ) = 0;

   /// Convenience write operator for an EcString.
   /// @return    Handle& Network resource to write to
   virtual Handle& operator<<
      (
      const EcString& str ///< [in] String to write to network
      );

   /// Convenience write operator for an EcString.
   /// @return     Handle& Network resource to read from
   Handle& operator>>
      (
      EcString& str ///< [out] String to read into from network
      );

   /// Returns the concatenation of the client ipaddress and port in the
   /// form: xxx.xxx.xxx.xxx:port.
   /// @return EcString unique socket identifier
   EcString socketID
      (
      ) const;

protected:
   /// Thread-safe invocation of callback
   void invokeCallback
      (
      );

   /// Indicate whether a valid callback was registered.
   /// @return EcBoolean Whether a valid callback is available
   EcBoolean callbackValid
      (
      ) const;

   NetworkMode m_NetworkMode;       ///< Whether functioning as a client or server
   NetworkState m_NetworkState;     ///< State of the network handle
   NetworkCallback m_TerminateCB;   ///< Registered terminate callback method
   EcString m_IPAddress;            ///< IP Address to use
   EcU16 m_Port;                    ///< Port to use
   boost::thread* m_pThread;        ///< Background thread for network processing
   EcSocketBase* m_pSock;           ///< Handle to underlying socket connection
   mutable EcMutex m_CallbackMutex; ///< Safeguard around callback invocation
   mutable EcString m_InputString;  ///< Holds deserialized data
   mutable EcString m_OutputString; ///< Holds serialized data
   mutable EcInt32 m_ReadBufferIndex;  ///< read buffer index
   mutable EcInt32 m_ReadBufferSize;   ///< read buffer size
   mutable EcInt8 m_ReadBuffer[MAX_MSG_SIZE]; ///< Temp buffer to read data into
   EcInt8 m_SendBuffer[MAX_MSG_SIZE]; ///< Temp location for sending data

   EcMutex m_SendBufferMutex;       ///< Mutex to protect m_SendBuffer

private:
   NetworkCallback m_Callback;      ///< Registered callback method
};

} } // namespace Ec::network

#endif // ec_network_Handle_H_
