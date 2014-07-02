#ifndef ecIfGzStream_H_
#define ecIfGzStream_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecIfGzStream.h
/// @class EcIfGzStream
/// @brief Input file compressed stream class
/// @details This class acts just like an ifstream class with a compressed stream
///
/// Note: Streams don't have copy, assignment, or equality operators
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecGzStreamBuffer.h"
#include <istream>

class EC_STABLE_STREAM_DECL EcIfGzStream : public std::istream
{
public:
   /// Default constructor
   EcIfGzStream
      (
      );

   /// Default destructor
   virtual ~EcIfGzStream
      (
      );

   /// self test
   /**
      \return Boolean for pass/fail test
   */

   /// Constructor with file description
   /**
      \param file  Input file name
      \param mode  Input file mode (default "in")
      \param fd    File designator
   */
   EcIfGzStream
      (
      const char* file,
      EcInt32 mode = std::ios::in,
      EcInt32 fd = -1
      );

   /// Opens a file
   /**
      \param file  Input file name
      \param mode  Input file mode (default "in")
      \param fd    File designator
   */
   virtual void open
      (
      const char* file,
      EcInt32 mode = std::ios::in,
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

   /// Input stream
   EcGzStreamBuffer m_Buffer;
};

#endif // ecIfGzStream_H_
