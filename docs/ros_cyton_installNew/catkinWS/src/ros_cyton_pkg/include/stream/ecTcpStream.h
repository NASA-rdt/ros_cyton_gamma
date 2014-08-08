#ifndef ecTcpStream_H_
#define ecTcpStream_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecTcpStream.h
/// @class EcTcpStream
/// @brief Output TCP stream class
/// @details This class acts just like an ofstream class with a TCP socket
///
/// Note: Streams don't have copy, assignment, or equality operators
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecGzStringStream.h"
#include <socket/ecTcpSocket.h>

class EC_STABLE_STREAM_DECL EcTcpStream : public EcGzStringStream
{
public:
   /// Default constructor
   EcTcpStream
      (
      );

   /// Default destructor
   virtual ~EcTcpStream
      (
      );

   /// Constructor with IP description
   /**
      \param peerAddress  IP number
      \param peerPort  Port number
   */
   EcTcpStream
      (
      const char* peerAddress,
      EcU16 peerPort
      );

   /// Constructor with socket description
   /**
      \param pSocket  Socket pointer
   */
   explicit EcTcpStream
      (
      const EcTcpSocket* pSocket
      );

   /// Opens a socket
   /**
      \param peerAddress  IP number
      \param peerPort  Port number
   */
   virtual void open
      (
      const char * peerAddress,
      EcU16 peerPort
      );

   /// Put string to socket
   /**
      \param input fill buffer with string
      \param headerID optional header message
      \return error status
   */
   virtual EcBoolean strTcpSend
      (
      const EcString& input,
      const EcInt32  headerID=0
      );

   /// Put string
   /**
      \param headerID optional header message
      \return error status
   */
   virtual EcBoolean strTcpSend
      (
      const EcInt32  headerID=0
      );

   /// Get string from socket
   /**
      \return error status
   */
   virtual EcBoolean strTcpReceive
      (
      );

   /// Get string from socket
   /**
      \return string
   */
   virtual EcString strTcpReceiveReturnString
      (
      );

   /// Get socket header
   /**
      \return socket header
   */
   virtual const EcSocketHeader& socketHeader
      (
      ) const;

   /// Get empty buffer flag
   /**
      \return empty buffer flag
   */
   virtual EcBoolean emptyBufferFlag
      (
      ) const;

protected:

   /// TCP Socket
   EcTcpSocket* m_pSocket;

   /// New socket flag
   EcBoolean m_NewSocket;

   /// Header message
   mutable EcSocketHeader m_SocketHeader;

   /// Empty buffer flag
   mutable EcBoolean m_EmptyBuffer;
};

#endif // ecTcpStream_H_
