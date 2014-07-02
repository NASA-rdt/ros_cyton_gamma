#ifndef ecOfGzStream_H_
#define ecOfGzStream_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecOfGzStream.h
/// @class EcOfGzStream
/// @brief Output file compressed stream class
/// @details This class acts just like an ofstream class with a compressed stream
///
/// Note: Streams don't have copy, assignment, or equality operators
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecGzStreamBuffer.h"
#include <ostream>

class EC_STABLE_STREAM_DECL EcOfGzStream : public std::ostream
{
public:
   /// Default constructor
   EcOfGzStream
      (
      );

   /// Default destructor
   virtual ~EcOfGzStream
      (
      );

   /// self test
   /**
      \return Boolean for pass/fail test
   */

   /// Constructor with file description
   /**
      \param file  Output file name
      \param mode  Output file mode (default "out")
      \param fd    File designator
   */
   EcOfGzStream
      (
      const char* file,
      EcInt32 mode = std::ios::out,
      EcInt32 fd = -1
      );

   /// Opens a file
   /**
      \param file  Output file name
      \param mode  Output file mode (default "out")
      \param fd    File designator
   */
   virtual void open
      (
      const char* file,
      EcInt32 mode  = std::ios::out,
      EcInt32 fd = -1
      );

   /// Closes a file
   virtual void close
      (
      );

   /// Get pointer to buffer
   /**
      \return Pointer to stream buffer
   */
   virtual EcGzStreamBuffer* rdbuf
      (
      );

protected:

   /// Output stream
   EcGzStreamBuffer m_Buffer;
};

#endif // ecOfGzStream_H_
