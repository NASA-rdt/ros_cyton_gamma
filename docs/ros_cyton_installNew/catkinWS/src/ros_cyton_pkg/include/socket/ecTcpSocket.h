#ifndef ecTcpSocket_H_
#define ecTcpSocket_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecTcpSocket.h
/// @class EcTcpSocket
/// @brief TCP socket class
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecSocketBase.h"
#include <foundCore/ecConstants.h>

class EC_STABLE_SOCKET_DECL EcTcpSocket : public EcSocketBase
{
public:
   /// constructor
   EcTcpSocket
      (
      );

   /// constructor which creates connects to peer address and port
   /**
       \param peerAddress peer address
       \param peerPort peer port
       \param ifConnect error status for connection
   */
   EcTcpSocket
      (
      const EcString &peerAddress,
      EcU16 peerPort,
      EcBoolean& ifConnect
      );

   /// constructor with a previously opened socket ID
   /**
       \param socketID previously opened socket ID
   */
   EcTcpSocket
      (
      EcInt32 socketID
      );

   /// destructor
   virtual ~EcTcpSocket
      (
      );

   /// copy constructor
   EcTcpSocket
      (
      const EcTcpSocket& rhs
      );

   /// assignment operator
   EcTcpSocket& operator=
      (
      const EcTcpSocket& rhs
      );

   /// Listen for incoming connection
   /**
       \param localPort local port to listen to
       \param queueLength max number of pending socket connections
       \retval error status
   */
   virtual EcBoolean listen
      (
      const EcU16 localPort,
      const EcInt32 queueLength = 1
      );

   /// listening until incoming connection established if blocking,
   /// & create a new socket if a connection is made. If not blocking,
   /// it will check if a connection is trying to be made, but will
   /// not wait for the connection.
   /**
       \param waitFlag wait until connection is completed before proceeding
       \retval TCP socket
   */
   virtual EcTcpSocket* accept
      (
      EcBoolean waitFlag = EcTrue
      );

   /// try to connect with the peer address and port
   /**
       \param peerAddress peer IP address
       \param peerPort peer port ID
       \retval error status
   */
   virtual EcBoolean connect
      (
      const EcString &peerAddress,
      const EcU16 peerPort
      );

   /// send message (header and data)
   /**
       \param sHeader header
       \param message message
       \retval error status
   */
   virtual EcInt32 send
      (
      const EcSocketHeader& sHeader,
      const EcInt8* message
      );

   /// send message (header or data)
   /**
       \param buffer data
       \param bufferSize data size
       \retval error status
   */
   virtual EcInt32 send
      (
      const EcInt8* buffer,
      const EcInt32 bufferSize
      );

   /// receive message (header and data)
   /// the return value is the size in bytes.  Negative for an error.
   /**
       \param sHeader header to help with communication
       \param message message
       \retval error status
   */
   virtual EcInt32 receive
      (
      EcSocketHeader& sHeader,
      EcInt8* &message
      );

   /// receive large data set from the peer
   /// loops over recv to get full message
   /**
       \param sHeader header to help with communication
       \param message data
       \param socketLimit packet size
       \retval error status
   */
   virtual EcInt32 receive
      (
      EcSocketHeader& sHeader,
      EcInt8* &message,
      const EcInt32 socketLimit
      );

   /// receive message (header or data)
   /// the return value is the size in bytes.  Negative for an error.
   /**
       \param buffer data
       \param bufferSize data size
       \param msgFlag receive message, generally zero
       \retval message size
   */
   virtual EcInt32 recv
      (
      EcInt8* buffer,
      EcInt32 bufferSize,
      const EcInt32 msgFlag=0    // set this flag to MSG_PEEK for variable
      );

   /// @copydoc EcSocketBase::shutdown()
   virtual EcBoolean shutdown
      (
      );
};

#endif // ecTcpSocket_H_
