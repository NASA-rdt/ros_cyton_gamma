#ifndef ecGzStreamBuffer_H_
#define ecGzStreamBuffer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecGzStreamBuffer.h
/// @class EcGzStreamBuffer
/// @brief Add compression capability to stream buffer
/// @details This class acts just like a file buffer class with compression.
///          Code follows Nicolai Josuttis "The Standard C++ Library" p668-681
///
/// Note: Streams don't have copy, assignment, or equality operators
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <streambuf>

class EC_STABLE_STREAM_DECL EcGzStreamBuffer : public std::streambuf
{
public:
   /// Default constructor
   EcGzStreamBuffer
      (
      );

   /// Default destructor
   virtual ~EcGzStreamBuffer
      (
      );

   /// Opens a file
   /**
      \param file  File name
      \param mode  File mode
      \param fd    File designator
   */
   virtual void open
      (
      const char* file,
      EcInt32 mode,
      EcInt32 fd = -1
      );

   /// Closes a file
   virtual void close
      (
      );

protected:

   /// Flush the characters in the buffer to output file
   /**
      \return Error code
   */
   virtual EcInt32 flushBuffer
      (
      );

   /// Writes to output file
   /**
   Overrides stream buffer version
      \param c Character
      \return Error code
   */
   virtual int_type overflow
      (
      int_type c
      );

   /// Reads from input file
   /**
   Overrides stream buffer version
      \return Error code
   */
   virtual int_type underflow
      (
      );

   /// Synchronize data with file/destination
   /**
   Overrides stream buffer version
      \return Error code
   */
   virtual int sync
      (
      );

   /// Size of data buffer
   enum
   {
      BUFFER_SIZE = 100,   /**< Stream buffer size*/
      PUTBACK_SIZE = 5     /**< Putback buffer size*/
   };

   /// Data buffer
   char m_Buffer[BUFFER_SIZE];

   /// File handle for compressed file
   void* m_File;

   /// I/O mode
   EcInt32 m_Mode;
};

#endif // ecGzStreamBuffer_H_
