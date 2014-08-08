#ifndef ecHttpStreamBuffer_H_
#define ecHttpStreamBuffer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecHttpStreamBuffer.h
/// @class EcHttpStreamBuffer
/// @brief Add HTTP capability to stream buffer
/// @details This class acts just like a file buffer class with HTTP capability
///          Code follows Nicolai Josuttis "The Standard C++ Library" p668-681
///
/// Note: Streams don't have copy, assignment, or equality operators
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <streambuf>

class EC_STABLE_STREAM_DECL EcHttpStreamBuffer : public std::streambuf
{
public:
   /// Default constructor
   EcHttpStreamBuffer
      (
      );

   /// Default destructor
   virtual ~EcHttpStreamBuffer
      (
      );

   /// Opens a file
   /**
      \param Url  URL to file
      \param mode  File mode
   */
   virtual void open
      (
      const char* Url,
      EcInt32 mode = std::ios::in
      );

   /// Closes a file
   virtual void close
      (
      );

protected:

   /// Reads from input file
   /**
   Overrides stream buffer version
      \return Error code
   */
   virtual int_type underflow
      (
      );

   /// Size of data buffer
   enum
   {
      BUFFER_SIZE = 1000,  /**< Stream buffer size*/
      PUTBACK_SIZE = 5     /**< Putback buffer size*/
   };

   /// Data buffer
   char m_Buffer[BUFFER_SIZE];

   /// File buffer
   EcString m_FileBuffer;

   /// Buffer index
   EcU32 m_Index;
};

#endif // ecHttpStreamBuffer_H_
