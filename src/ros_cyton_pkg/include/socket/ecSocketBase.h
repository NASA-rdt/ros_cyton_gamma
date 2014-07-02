#ifndef ecSocketBase_H_
#define ecSocketBase_H_
//------------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecSocketBase.h
/// @class EcSocketBase
/// @brief base class of sockets.
//
//------------------------------------------------------------------------------
#include <foundCore/ecMutex.h>
#include <foundCore/ecTypes.h>

// Forward declaration of socket structure
struct sockaddr_in;

/// Definition of socket message header
struct EC_STABLE_SOCKET_DECL EcSocketHeader
{
   EcInt32 size;          ///< total buffer size
   EcInt32 ID;            ///< ID for communication
};

/// Base class for TCP/UDP socket support
class EC_STABLE_SOCKET_DECL EcSocketBase
{
public:
   /// our socket error codes. We combine some lower
   /// level codes to simplify and abstract the
   /// details. We may need them at some point though.
   enum
   {
      ECSOCK_ERROR_NONE = 0,
      /// most likely an illegal param or calling funcs out of order
      ECSOCK_ERROR_GENERIC,
      /// trying to broadcast without enabling broadcasting
      ECSOCK_ERROR_NO_BROADCAST_ACCESS,
      /// socket is not currently connected
      ECSOCK_ERROR_NOT_CONN,
      /// operation would block, or it has timed out
      ECSOCK_ERROR_WOULD_BLOCK,
      /// can't communicate with the given remote
      ECSOCK_ERROR_HOST_UNREACHABLE,
      /// the connection has been lost
      ECSOCK_ERROR_CONN_LOST,
      /// network is down
      ECSOCK_ERROR_NETWORK_DOWN,
      /// the address is already in use
      ECSOCK_ERROR_ADDR_IN_USE
   };

   /// constructor from a type and protocol
   /**
       \param type use SOCK_STREAM for TCP and SOCK_DGRAM for UDP
       \param protocol use IPPROTO_TCP for TCP and IPPROTO_UDP for UDP
   */
   EcSocketBase
      (
      const EcInt32 type,
      const EcInt32 protocol
      );

   /// constructor from a socket description
   /**
       \param socketID previously opened socket ID
   */
   explicit EcSocketBase
      (
      const EcInt32 socketID
      );

   /// destructor
   virtual ~EcSocketBase
      (
      );

   /// copy constructor
   EcSocketBase
      (
      const EcSocketBase &rhs
      );

   /// assignment operator
   EcSocketBase& operator=
      (
      const EcSocketBase &rhs
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSocketBase& orig
      ) const;

   /// bind to local port
   /**
       \param localPort local port ID
       \retval error status
   */
   virtual EcBoolean bind
      (
      const EcU16 localPort
      );

   /// get the address of the peer (foreign)
   /**
       \retval IP address
   */
   virtual EcString peerAddress
      (
      );

   /// get the port of the peer (foreign)
   /**
       \retval port
   */
   virtual EcU16 peerPort
      (
      );

   /// get function for local address
   /**
       \retval local IP address
   */
   virtual EcString localAddress
      (
      );

   /// get function for local port
   /// returns zero on failure
   /**
       \retval local port ID
   */
   virtual EcU16 localPort
      (
      );

   /// get the socket ID
   /**
       \retval socket ID
   */
   virtual EcInt32 socketID
      (
      ) const;

   /// set the timeout for receive in msec.
   /**
       \param timeout time in msec
       \retval error status
   */
   virtual EcBoolean setRecvTimeout
      (
      const EcInt32 timeout
      );

   /// set the send time out in msec.
   /**
       \param timeout time in msec
       \retval error status
   */
   virtual EcBoolean setSendTimeout
      (
      const EcInt32 timeout
      );

   /// set the receive buffer size in bytes
   /// \param recvsize Buffer size
   /// \retval EcBoolean Success or failure of command
   virtual EcBoolean setRecvBufferSize
      (
      const EcInt32 recvsize
      );

   /// set socket operations to wait until operation is complete,
   /// or to just try the operation and move on.
   //  Currently used by server accept() method.
   /**
       \param wait block flag
       \retval error status
   */
   virtual EcBoolean setSocketToWait
      (
      const EcBoolean wait
      );

   /// Block until data is avaible on the socket to read.
   /// \return EcBoolean Returns EcTrue if data is ready, EcFalse if error
   virtual EcBoolean waitForReadyRead
      (
      );

   /// Return the # of pending bytes to read
   /**
       \retval number of pending bytes
   */
   virtual EcU32 getNumPendingBytes
      (
      );

   /// Return the last socket error that has occured, or 0 for no errors
   /**
       \retval error code
   */
   virtual EcU32 getLastError
      (
      ) const;

   /// Close down an open socket
   virtual void close
      (
      );

   /// Shut down socket send and receive operation.
   virtual EcBoolean shutdown
      (
      );

protected:
   /// called when an error occured to store the error code
   /// getLastError returns the code
   virtual void storeLastError
      (
      );

   /// set the address structure with an address and port
   /**
       \param address IP address
       \param port port
       \param addressStruct address structure filled with address and port
   */
   void setAddressAndPortStruct
      (
      const EcString &address,
      const EcU16 port,
      sockaddr_in& addressStruct
      ) const;

   static EcU32 m_theCounter; ///< Counter of active sockets
   EcInt32      m_SocketID;   ///< Socket identifier
   EcU32        m_LastError;  ///< Last stored error or 0 for no errors
   EcMutex      m_Mutex;      ///< Thread-safe access
};

#endif // ecSocketBase_H_
