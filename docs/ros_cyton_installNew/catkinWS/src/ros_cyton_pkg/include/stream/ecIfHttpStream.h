#ifndef ecIfHttpStream_H_
#define ecIfHttpStream_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecIfHttpStream.h
/// @class EcIfHttpStream
/// @brief Input file HTTP stream class
/// @details This class acts just like an ifstream class with a HTTP stream
///
/// Note: Streams don't have copy, assignment, or equality operators
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecHttpStreamBuffer.h"

class EC_STABLE_STREAM_DECL EcIfHttpStream : public std::istream
{
public:
   /// Default constructor
   EcIfHttpStream
      (
      );

   /// Default destructor
   virtual ~EcIfHttpStream
      (
      );

   /// self test
   /**
      \return Boolean for pass/fail test
   */

   /// Constructor with file description
   /**
      \param Url  URL to file
      \param mode  Input file mode (default "in")
   */
   EcIfHttpStream
      (
      const char* Url,
      EcInt32 mode = std::ios::in
      );

   /// Opens a file
   /**
      \param Url  URL to file
      \param mode  Input file mode (default "in")
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

   /// Get pointer to buffer
   /**
      \return Pointer to stream buffer
   */
   virtual EcHttpStreamBuffer* rdbuf
      (
      );

protected:

   /// Input stream
   EcHttpStreamBuffer m_Buffer;
};

#endif // ecIfHttpStream_H_
