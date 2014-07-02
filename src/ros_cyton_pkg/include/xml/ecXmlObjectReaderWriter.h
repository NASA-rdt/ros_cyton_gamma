#ifndef ecXmlObjectReaderWriter_H_
#define ecXmlObjectReaderWriter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlObjectReaderWriter.h
/// @class EcXmlObjectReaderWriter
/// @brief Helper class to support reading and writing of an EcXmlObject
///        using several methods.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecXmlTokens.h"
#include <foundCore/ecMacros.h>
#include <iosfwd>

class EcTcpSocket;
class EcXmlReader;
class EcXmlSchema;
class EcXmlWriter;
class EcXmlObject;

class EcXmlObjectReaderWriter
{
public:

   /// The media dscription and attributes that can be added to the media type
   enum MediaTypeEnum
   {
      LocalFile  = 1,       ///< Flat file
      Url        = 2,       ///< web url
      StdStream  = 3,       ///< std::stream
      Buffer     = 4,       ///< EcString
      Socket     = 5,       ///< TCP socket

      Compressed = 0xe0     ///< Compressed data
   };
   typedef EcU16 MediaType; ///< Type to hold media description.

   /// Read object in from a generic type.
   /// it just calls obj.read(stream)
   /// @param  obj       Object to read into.
   /// @param  where     Location to read from.
   /// @param  type      Location type.
   /// @return EcBoolean Success or failure of command.
   template <typename T> static EcBoolean read
      (
      EcXmlObject& obj,
      T& where,
      const MediaType type
      );

   /// Write object out to a generic type.
   /// it just calls obj.write(stream)
   /// @param  obj       Object to write out.
   /// @param  where     Location to write to.
   /// @param  type      Location type.
   /// @return EcBoolean Success or failure of command.
   template <typename T> static EcBoolean write
      (
      const EcXmlObject& obj,
      const T& where,
      const MediaType type
      );

   /// test filename for Gzip status
   /// @param  filename   Input file name
   /// @return EcBoolean  Success or failure of command.
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL isGzip
      (
      const EcString& filename
      );

   /// Read object in from a std::istream.
   /// @param  obj        Object to read into.
   /// @param  stream     Stream to read from.
   /// @param  streamName Stream filename.
   /// @param  token      Optional object type
   /// @return EcBoolean  Success or failure of command.
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL readFromStream
      (
      EcXmlObject& obj,
      std::istream& stream,
      const EcString& streamName,
      const EcToken& token = EcXml::EcNullToken
      );

   /// Write object out to a std::ostream.
   /// @param  obj        Object to write out
   /// @param  stream     Stream to write to
   /// @param  streamName Stream filename
   /// @param  token      Base tag token to write out
   /// @return EcBoolean Success or failure of command
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL writeToStream
      (
      const EcXmlObject& obj,
      std::ostream& stream,
      const EcString& streamName,
      const EcToken& token = EcXml::EcNullToken
      );

   /// Read object in from a local file.
   /// @param  obj        Object to read into.
   /// @param  fileName   File to read from.
   /// @param  token      Optional object type
   /// @return EcBoolean  Success or failure of command.
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL readFromFile
      (
      EcXmlObject& obj,
      const EcString& fileName,
      const EcToken& token = EcXml::EcNullToken
      );

   /// Write object out to a local file.
   /// @param  obj        Object to write out.
   /// @param  fileName   File to write to.
   /// @param  token      Base tag token to write out
   /// @return EcBoolean  Success or failure of command.
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL writeToFile
      (
      const EcXmlObject& obj,
      const EcString& fileName,
      const EcToken& token = EcXml::EcNullToken
      );

   /// Write object out to a local file.
   /// @param  obj        Object to write out.
   /// @param  filename   File to write to.
   /// @param  gzipFlag   gzip flag
   /// @param  token      Base tag token to write out
   /// @return EcBoolean  Success or failure of command.
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL writeToGeneralFile
      (
      const EcXmlObject& obj,
      const EcString& filename,
      const EcBoolean gzipFlag,
      const EcToken& token // = EcXml::EcNullToken
      );

   /// read this object from URL
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL readFromUrl
      (
      EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );

   /// read this object from a buffer
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL readFromBuffer
      (
      EcXmlObject& obj,
      const EcString& buffer,
      const EcToken& token = EcXml::EcNullToken
      );

   /// write this object to a buffer
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL writeToBuffer
      (
      const EcXmlObject& obj,
      EcString& buffer,
      const EcToken& token = EcXml::EcNullToken
      );

   /// read this object from a compressed buffer
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL readFromCompressedBuffer
      (
      EcXmlObject& obj,
      const EcString& buffer,
      const EcToken& token = EcXml::EcNullToken
      );

   /// write this object to a compressed buffer
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL writeToCompressedBuffer
      (
      const EcXmlObject& obj,
      EcString& buffer,
      const EcToken& token = EcXml::EcNullToken
      );

   /// read this object from TCP socket
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL readFromTcpSocket
      (
      EcXmlObject& obj,
      const EcTcpSocket* clientSocket,
      const EcToken& token = EcXml::EcNullToken
      );

   /// write this object to TCP socket
   static EcBoolean EC_STABLE_XMLREADERWRITER_DECL writeToTcpSocket
      (
      const EcXmlObject& obj,
      const EcTcpSocket* clientSocket,
      const EcInt32 headerID = 0,
      const EcToken& token = EcXml::EcNullToken
      );

protected:
   /// read this object from an uncompressed file
   static EcBoolean readFromFilePlain
      (
      EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );

   /// write this object to an uncompressed file
   static EcBoolean writeToFilePlain
      (
      const EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );

   /// write this object to an uncompressed file
   static EcBoolean writeToFilePlainWithSchema
      (
      const EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );

   /// read this object from a compressed file
   static EcBoolean readFromFileWithCompression
      (
      EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );

   /// read this object from a compressed file using filteringStreams
   static EcBoolean readFromFileWithCompression2
      (
      EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );

   /// write this object to a compressed file
   static EcBoolean writeToFileWithCompression
      (
      const EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );

   /// write this object to a compressed file
   static EcBoolean writeToFileWithCompression2
      (
      const EcXmlObject& obj,
      const EcString& filename,
      const EcToken& token = EcXml::EcNullToken
      );
};

#endif // ecXmlObjectReaderWriter_H_
