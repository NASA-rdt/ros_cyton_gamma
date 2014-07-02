#ifndef ecImageReaderWriter_H_
#define ecImageReaderWriter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageReaderWriter.h
/// @class EcImageReaderWriter
/// @brief Provides mechanism to read and write different image file formats.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImage.h"

// XXX FIXME:
namespace Ec { namespace test { class EcImageReaderWriterTester; } }

/// Provides mechanism to read and write different image file formats.
class EC_SENSOR_IMAGE_DECL EcImageReaderWriter
{
public:
   enum FileType
   {
      UNKNOWN = 0,
      BIN,
      BMP,
      IMG,
      JPG,
      MAP,
      PGM,
      TIF,
      RAW,
      PTS
   };

   /// The default quality for compression.
   static const EcU32 DEFAULT_JPEG_QUALITY = 75;

   /// internal buffer size used by JPEG compressor/inflator
   enum
   {
      JPEG_BOOKKEEPING_SIZE = 1024
   };

   static EcImage *read
      (
      const EcString &fileName
      );

   static EcBoolean read
      (
      EcImage &image,
      const EcString &fileName
      );

   static EcBoolean write
      (
      const EcImage &image,
      const EcString &fileName
      );

   static FileType getFileType
      (
      const EcString &fileName
      );

   static void setJpegQuality
      (
      const EcU32 quality
      );


   static EcU32 compressJPEG
      (
      const EcImage &image,
      const EcU32 quality,
      EcU8 *memoryBuffer,
      const EcU32 bufsize
      );

   static EcBoolean inflateJPEG
      (
      EcImage &image,
      EcU8 *input_buffer,
      const EcU32 buffer_size
      );

   static EcBoolean readPTSColor
      (
      EcImage &image,
      const EcString &fileName
      );

protected:
   // XXX FIXME:
   friend class Ec::test::EcImageReaderWriterTester;
   friend class EcEncodedImage;

   static EcBoolean readBmp
      (
      EcImage &image,
      const EcString &fileName
      );

   static EcBoolean writeBmp
      (
      const EcImage &image,
      const EcString &fileName
      );

   static EcBoolean readImg
      (
      EcImage &image,
      const EcString &fileName,
      const EcU32 rows = 256,
      const EcU32 cols = 256,
      const EcU32 numChannels = 1,
      const EcBoolean autoThreshold = EcFalse,
      EcReal upperThreshold = 20.0,
      EcReal lowerThreshold = 0.0
      );

   /// read in the image multibytes as MAP
   static EcBoolean readMap
      (
      EcImage &image,
      const EcString &fileName
      );

   /// read in the image multibytes as JPG
   static EcBoolean readJpeg
      (
      EcImage &image,
      const EcString &fileName
      );

   /// write out the image multibytes as a JPG
   static EcBoolean writeJpeg
      (
      const EcImage &image,
      const EcString &fileName,
      const EcU32 quality = DEFAULT_JPEG_QUALITY
      );

   static EcBoolean readPgm
      (
      EcImage &image,
      const EcString &fileName
      );

   static EcBoolean readPTS
      (
      EcImage &image,
      const EcString &fileName
      );

   static EcBoolean writePgm
      (
      const EcImage &image,
      const EcString &fileName
      );

   static void tiffErrorHandler
      (
      const char *module,
      const char *format,
      va_list args
      );

   static EcBoolean readTif
      (
      EcImage &image,
      const EcString &fileName
      );

   static EcBoolean writeTif
      (
      const EcImage &image,
      const EcString &fileName
      );

   static EcBoolean writeRaw
      (
      const EcImage &image,
      const EcString &fileName
      );

   /// write out binary integer data
   static void binaryWrite
      (
      std::ostream &stream,
      const EcU32 data,
      const EcU32 bytes
      );

   static EcU32 m_JpegQuality;
};

#endif // ecImageReaderWriter_H_
