#ifndef ecImageColorConversion_H_
#define ecImageColorConversion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageColorConversion.h
/// @class EcImageColorConversion
/// @brief Provides mechanism for performing color space conversions.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImage.h"

/// Provides mechanism for performing color space conversions.
class EC_SENSOR_IMAGE_DECL EcImageColorConversion
{
public:
   /// Convert an incoming image from a FOURCC format into an RGB8 image.
   /// The FOURCC format is specified in the image comments.
   /// @param[in]  src       Incoming image
   /// @param[out] dst       Output image
   /// @return     EcBoolean Success or failure of command
   static EcBoolean convertToRGB
      (
      const EcImage& src,
      EcImage& dst
      );

   /// convert the RGGB data (packed into Y800 image)
   ///   into three-channel RGB
   static EcBoolean unpackRGGB
      (
      const EcImage &image,
      EcU8* dstImgPtr
      );

   /// convert the RGGB data (packed into Y800 image)
   ///   into three-channel RGB
   static EcBoolean unpackRGGB
      (
      const EcU32 wSrc,
      const EcU32 hSrc,
      const EcU8* pSrc,
      EcImage &image
      );

   /// Performs pixel swizzling to repackage into proper byte order.
   /// @param[in]  src Source image
   /// @param[out] dst Output image.
   static void BGRAtoRGBA
      (
      const EcImage& src,
      EcImage& dst
      );

   /// convert image array to GBR format suitable for video display
   static EcU8* displayBuffer
      (
      EcImage &image
      );

   /// convert an RGB 24 bits images to HSV
   static EcBoolean rgbToHsv
      (
      const EcImage &image,
      // std::vector<EcImage>& vHsvImg
	  EcImageVector& vHsvImg
      );

   /// convert an RGB 24 bits images to HSV (Matlab algorithm)
   static EcBoolean rgb2Hsv
      (
      const EcImage &image,
      EcImageVector& vHsvImg
      );

   /// convert an RGB 24 bits images to Gray 8 bits
   /// Same as RGB to HSV but taking only the V part.
   static EcBoolean RGBToGray
      (
      const EcImage &image,
      EcImage& grayImg
      );

   /// convert an XYZ 32x3 bits images to Gray 8 bits
   static EcBoolean xyz96Toz8
      (
      const EcImage &image,
      EcImage& grayImg
      );

   /// convert three bytes of RGB to YUV (luminance, chrominance)
   static void rgbToYuv
      (
      const EcU8* rgb,
      EcU8* yuv
      );

   /// copy one channel of a multiple channel image into a gray scale image buffer
   static void copyChannel
      (
      const EcImage &image,
      const EcU32&  channel,
      EcImage& grayImg
      );

   /// invert the gray scale image
   static void invert
      (
      const EcImage& image,
      EcImage&       grayImg
      );

   // convert three bytes of YUV (luminance, chrominance) to RGB
   static void yuvToRgb
      (
      const EcU8* yuv,
      EcU8* rgb
      );

   /// sample four image regions, gather color and luminance stats
   static EcBoolean spotSampleImg
      (
      EcImage &image,
      EcF32 &avgLuminance,
      EcF32 &avgRGratio,
      EcF32 &avgBGratio
      );

   /// scale image bgnd color ratios and luminance to match a reference
   static EcBoolean colorCorrectRGB
      (
      EcImage &image
      );

   /// Used by image capture code to try and convert incoming data to a usable
   /// type.
   static void resampleImage
      (
      const EcU32 wSrc,   // Source width
      const EcU32 hSrc,   // Source height
      const EcU8  bpvSrc, // Source bytes per value
      const EcU8  bppSrc, // Source bits per pixel
      const EcU8* pSrc,   // Pointer to source data
      EcImage& output
      );

protected:
   /// Internal method to process Y800(RGGB) to RGB8.
   static void unpackRGGB
      (
      const EcU32 wSrc,
      const EcU32 hSrc,
      const EcU8* pSrc,
      EcU8* pDst
      );
};

#endif // ecImageColorConversion_H_
