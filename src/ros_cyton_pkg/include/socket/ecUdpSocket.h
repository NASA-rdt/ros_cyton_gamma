#ifndef ecUdpSocket_H_
#define ecUdpSocket_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecUdpSocket.h
/// @class EcUdpSocket
/// @brief UDP socket class
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecSocketBase.h"

class EC_STABLE_SOCKET_DECL EcUdpSocket : public EcSocketBase
{
public:
   /// constructor
   EcUdpSocket
      (
      );

   /// constructor given local port
   /// create a client socket, and bind to local port
   explicit EcUdpSocket
      (
      EcU16 localPort
      );

   /// destructor
   virtual ~EcUdpSocket
      (
      );

   /// copy constructor
   EcUdpSocket
      (
      const EcUdpSocket& rhs
      );

   /// assignment operator
   EcUdpSocket& operator=
      (
      const EcUdpSocket& rhs
      );


   /// set this to be a broadcast socket
   virtual void setToBroadcast
      (
      );

   /// send message (header and data)
   /**
       \param sHeader message header
       \param message message
       \param peerAddress recipient address
       \param peerPort recipient port
       \retval error status
   */
   virtual EcInt32 send
      (
      const EcSocketHeader sHeader,
      const EcU8* message,
      const EcString &peerAddress,
      const EcU16 peerPort
      );

   /// send message (header or data)
   /**
       \param buffer message
       \param bufferSize message size in bytes
       \param peerAddress recipient address
       \param peerPort recipient port
       \retval error status
   */
   virtual EcInt32 sendTo
      (
      const EcU8* buffer,
      const EcU32 bufferSize,
      const EcString &peerAddress,
      const EcU16 peerPort
      );

   /// receive message (header and data)
   /// Function can handle larger (>64k) data
   /**
       \param sHeader header describes the buffer size and content type (output)
       \param message message (output)
       \param peerAddress recipient address (output)
       \param peerPort recipient port (output)
       \retval error status
   */
   virtual EcInt32 receive
      (
      EcSocketHeader& sHeader,
      EcU8* &message,
      EcString &peerAddress,
      EcU16 &peerPort
      );

   /// receive message (header or data
   /**
       \param buffer message (output)
       \param bufferSize message size in bytes (output)
       \param peerAddress recipient address (output)
       \param peerPort recipient port (output)
       \param msgFlag receive message, generally zero
       \retval data size
   */
   virtual EcInt32 recvFrom
      (
      EcU8 *buffer,
      EcU32 bufferSize,
      EcString &peerAddress,
      EcU16 &peerPort,
      const EcInt32 msgFlag=0
      );
};

#endif // ecUdpSocket_H_
