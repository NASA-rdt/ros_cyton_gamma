#ifndef ecImageFilter_H_
#define ecImageFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageFilter.h
/// @class EcImageFilter
/// @brief Assorted EcImage filtering algorithms.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImage.h"
#include "ecImageBlock.h"

// Forward declaration
class EcColor;
namespace cv { class Mat; }

/// Assorted EcImage filtering algorithms.
class EC_SENSOR_SENSCORE_DECL EcImageFilter
{
public:

   /// do Canny edge detection
   static EcBoolean cannyEdge
      (
      EcImage& image,
      EcImage& dst,
      const EcReal lowThreshold,
      const EcReal highThreshold
      );

   /// do Mean Shift Filtering
   static EcBoolean meanShiftFiltering
      (
      EcImage &image,
      EcImage &dst,
      const EcU32 spatialRadius,
      const EcU32 colorRadius,
      const EcU32 maxLevel
      );

   static EcBoolean fillBlocks
      (
      EcImage &image,
      const EcImageBlockVector& blocks,
      const EcColor&  color
      );

   ///  apply edge filter to image
   static EcU32 edgeFilter
      (
      EcImage &image,
      unsigned char* dstImgPtr
      );

   ///  dilate image edges
   static EcBoolean dilate
      (
      EcImage &image,
      EcU32 blockSizeX,         // blockSize
      EcU32 blockSizeY,
      unsigned char* dstImgPtr
      );

   ///  dilate image edges
   static EcBoolean dilate
      (
      EcImage &image,
      EcU32 blockSizeX,         // blockSize
      EcU32 blockSizeY,
      EcImage& dstImg
      );

   static EcBoolean dilateBinary
      (
      const EcImage &image,
      EcU32 blockSizeX,         // blockSize
      EcU32 blockSizeY,
      EcImage& dstImg
      );

   /// erode image
   static EcBoolean erode
      (
      const EcImage& image,
      EcU32 blockSizeX,         // blockSize
      EcU32 blockSizeY,
      EcImage& dstImg
      );

   /// erode image (binary)
   static EcBoolean erodeBinary
      (
      const EcImage& image,
      EcU32 blockSizeX,         // blockSize
      EcU32 blockSizeY,
      EcImage& dstImg
      );

   /// erode image
   static EcBoolean erode
      (
      const EcImage& image,
      EcU32 blockSizeX,         // blockSize
      EcU32 blockSizeY,
      unsigned char* dstImgPtr
      );

   /// a point is inside a polygon
   static EcBoolean insidePolygon
      (
      const EcPixelVector& pixels,
      const EcPixel& p,
      const EcBoolean& includeEdge
      );

   /// convert contours to blobs
   static EcBoolean fromContoursToBlobs
      (
      const EcPixelVectorVector& pixelsVec,
      const EcU32& width,
      const EcU32& height,
      EcImage& image
      );

   /// apply LPF and reduce image size by 2 in x and y.
   static EcBoolean reduce2
      (
      EcImage &image,
      EcU8* dstImgPtr
      );

   /// compute x-direction gradient for an image
   static EcU32 gradX
	  (
      const EcImage &image,
		EcF32* gradXbufPtr
	  );

   /// compute y-direction gradient for an image
   static EcU32 gradY
	  (
      const EcImage &image,
		EcF32* gradYbufPtr
	  );

   /// compute x-direction gradient for an image.
   ///  allow variable filter width.
   static EcU32 gradX
	  (
      const EcImage &image,
      EcF32* gradXbufPtr,
      EcInt32 pixelSpread
	  );

   /// compute y-direction gradient for an image.
   ///  allow variable filter width.
   static EcU32 gradY
	  (
      const EcImage &image,
      EcF32* gradYbufPtr,
      EcInt32 pixelSpread
	  );


   ///  apply sobel edge filter to image.
   ///  return number of strong edge points found
   static EcU32 sobelFilter
      (
      const EcImage &image,
      unsigned char* dstImgPtr
      );

   ///  apply sobel edge filter to image.
   ///   allow variable filter width.
   ///  return number of strong edge points found
   static EcU32 sobelFilter
      (
      const EcImage &image,
      unsigned char* dstImgPtr,
      EcU32 pixelSpread
      );

   /// sobel edge
   /// this version has memory allocation in it
   /// if need to run repeatatively, use the next one
   static EcBoolean sobelEdge
      (
      const EcImage &src,
      EcImage& dst,
      const EcU8&  threshold
      );

   /// this sobel edge has no memory allocation inside the method.
   static EcBoolean sobelEdge
      (
      const EcImage &image,
      EcImage& dst,               // the resulting edge image
      const EcU8& thresh,         // threshold
      cv::Mat&    gradx,          // avoiding memory allocation, passing from outside
      cv::Mat&    grady,
      cv::Mat&    grad
      );

   /// apply x-direction LPF to an image
   static EcBoolean lpfX
      (
      EcImage &image,
      EcU8* srcImgPtr,
      EcU8* dstImgPtr,
      EcU32 pixelSpread,
      EcU32 nTaps,
      EcU32 channelNum
      );

   /// apply y-direction LPF to an image
   static EcBoolean lpfY
      (
      EcImage &image,
      EcU8* srcImgPtr,
      EcU8* dstImgPtr,
      EcU32 pixelSpread,
      EcU32 nTaps,
      EcU32 channelNum
      );

   /// apply lowPassFilter to an image
   static EcBoolean lowPassFilter
      (
      EcImage &image,
      EcU32 pixelSpread,
      EcU32 nTapsX,
      EcU32 nTapsY,
      EcU32 channel
      );

   /// apply edge-preserving lowPassFilter to an image
   static EcBoolean edgePreservingLPF
      (
      EcImage &image,
      EcU32 pixelSpread,
      EcU32 nTapsX,
      EcU32 nTapsY,
      EcU32 channel
      );

   static EcBoolean adaptiveThresholding
   (
      const EcImage &image,
      EcImage &dst,
      const EcU32 method,
      const EcU32 type,
      const EcU32 blockSize,
      const EcU32 offset,
      const EcReal C=5
   );

   ///  apply high-pass filter to image, filter diagonally
   ///  return raw number of dots found.
   static EcU32 diagonalPointFilter
      (
      EcImage &image,
      const EcBoolean darkDot
      );

   ///  apply high-pass filter to image
   static EcBoolean pointFilter
      (
      EcImage &image,
      const EcBoolean darkDot
      );

   static EcBoolean addFrame
      (
      const EcImage &srcImage,
      EcImage& destImg,
      EcU32 frameSize
      );

   static EcBoolean deFrame
      (
      const EcImage &srcImage,
      EcImage& destImg,
      EcU32 frameSize
      );
};

#endif // ecImageFilter_H_
