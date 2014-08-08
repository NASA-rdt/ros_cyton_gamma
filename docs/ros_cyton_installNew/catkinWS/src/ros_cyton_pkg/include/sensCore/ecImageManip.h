#ifndef ecImageManip_H_
#define ecImageManip_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageManip.h
/// @class EcImageManip
/// @brief Assorted image manipulation routines.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImage.h"
#include <matrixUtilities/ecReArray.h>

/// Assorted image manipulation routines.
class EC_SENSOR_SENSCORE_DECL EcImageManip
{
public:
   /// inequality
   enum
   {
      SMALLER,
      SMALLER_EQUAL,
      EQUAL,
      GREATER_EQUAL,
      GREATER,
      NOT_EQUAL
   };

   /// Sums up all values including channels within the image
   static EcReal sum
      (
      const EcImage &image
      );

   /// finds the mean of all channels the image inside the block.
   /// Assumes the image blocks are inside the images.
   static EcReal blockMean
      (
      const EcImage &image,
      const EcImageBlock& block
      );

   /// finds the norm of the image inside the block.
   static EcReal blockNorm
      (
      const EcImage &image,
      const EcImageBlock& block
      );

   /// finds the mean of all channels the image inside the rectangle.
   /// Assumes the rectangle is fully inside the image.
   static EcReal rectangleMean
      (
      const EcImage &image,
      const EcImageRectangle& rectangle
      );

   /// finds the mean of all channels inside the pixel
   static EcReal pixelMean
      (
      const EcImage &image,
      const EcPixel& pixel
      );

   /// finds the number of pixels that are different from the values given
   static EcU32 nonmatchingPixelCount
      (
      const EcImage &image,
      const EcU32Vector& vValues
      );

   /// joins the provided image to this image on the right
   /// and returns the result.  Any unspecified values are
   /// set to zero.  Shorter images are joint flush to the
   /// top.
   static EcImage joinRight
      (
      const EcImage &image,
      const EcImage& otherImage
      );

   /// joins the provied image to this image on the bottom
   /// and returns the result.  Any unspecified values are
   /// set to zero.  Shorter images are joint flush to the
   /// left.
   static EcImage joinBottom
      (
      const EcImage &image,
      const EcImage& otherImage
      );

   // threshold this image and make a 0 or 255 image, save to a binary image.
   static EcBoolean threshold
      (
      const EcImage &image,
      const EcU8Vector& thresh,
      const EcU32  sign,
      EcImage& binImg
      );

   /// set image to 0 or 255 based on threshold and the flag ifUp
   static EcBoolean threshold
      (
      EcImage &image,
      const EcReal thresh,
      const EcBoolean ifUp
      );

   ///  calculate a gray scale image's histogram
   static EcBoolean histogram
      (
      const EcImage &image,
      EcU32Vector& vHistogram
      );

   static EcBoolean histogram
      (
      const EcImage &image,
      const EcU32&   loX,
      const EcU32&   hiX,
      const EcU32&   loY,
      const EcU32&   hiY,
      EcU32Vector& vHistogram   // histogram buffer
      );

   /// projection of 2D image onto a line
   static EcBoolean radon
      (
      const EcImage &image,
      const EcRealVector& vAngle,  // in radian
      EcReArray& rsltVec     // result
      );

   /// return 2-norm of this image
   static EcReal norm
      (
      const EcImage &image
      );

   /// flip the image vertically
   static void flipVertically
      (
      const EcImage& imageIn,
      EcImage& imageOut
      );

   /// flip the image horizontally
   static void flipHorizontally
      (
      const EcImage& imageIn,
      EcImage& imageOut
      );

};

#endif // ecImageManip_H_
