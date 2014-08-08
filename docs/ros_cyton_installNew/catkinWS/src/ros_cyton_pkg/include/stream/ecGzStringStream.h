#ifndef ecGzStringStream_H_
#define ecGzStringStream_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecGzStringStream.h
/// @class EcGzStringStream
/// @brief An input file compressed stream class
/// @details EcGzStringStream acts just like a string stream class
///          with compression.  Use strCompressed() to get the resulting
///          compressed string.
///
///          Note: Streams don't have copy, assignment, or equality operators
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

// sstream standard header
#include <string>

class EC_STABLE_STREAM_DECL EcGzStringStream : public std::stringstream
{
public:
   /// Default constructor
   EcGzStringStream
      (
      );

   /// Default destructor
   virtual ~EcGzStringStream
      (
      );

   /// Constructor with string input
   /**
      \param input input string
      \param compression if zero, input string is uncompressed,
                         otherwise compressed
   */
   EcGzStringStream
      (
      const EcString& input,
      EcU16 compression = 0
      );

   /// Get compressed string
   /**
      Use STL str() to get uncompressed string.
      \return compressed string
   */
   virtual const EcString& strCompressed
      (
      ) const;

   /// Put compressed string
   /**
      Use STL str(input) to put uncompressed string.
      \param input compressed string
      \param compression scale factor for uncompressed buffer size (default 30:1)
   */
   virtual void strCompressed
      (
      const EcString& input,
      EcU16 compression = 30
      );

   /// Put compressed string
   /**
      Use STL str(input) to put uncompressed string.
      \param input compressed string
      \param inputSize compressed string size
      \param compression scale factor for uncompressed buffer size (default 30:1)
   */
   virtual void strCompressed
      (
      const char* input,
      EcU32 inputSize,
      EcU16 compression = 30
      );

   /// Erase the compressed buffer
   virtual void eraseCompressed
      (
      );

protected:

   /// the output buffer
   mutable EcString m_Buffer;
};

#endif // ecGzStringStream_H_
