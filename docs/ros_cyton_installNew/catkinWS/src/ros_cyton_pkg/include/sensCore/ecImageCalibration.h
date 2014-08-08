#ifndef ecImageCalibration_H_
#define ecImageCalibration_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageCalibration.h
/// @class EcImageCalibration
/// @brief EcImage helper class for performing image calibration methods.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecImage.h"

#include <boost/array.hpp>

struct EcDetectedComponentVertex
{
   EcInt32 x;
   EcInt32 y;
};

typedef boost::array<EcDetectedComponentVertex, 4> EcDetectedComponentRegion;
typedef std::vector<EcDetectedComponentRegion>     EcDetectedComponentRegionVector;

struct EcDetectedComponent
{
   EcInt32 type;
   EcF32   confidence;
   EcF32   zRotation;
   EcDetectedComponentRegionVector regions;
};

typedef std::vector<EcDetectedComponent> EcDetectedComponentVector;

/// EcImage helper class for performing image calibration methods.
class EC_SENSOR_SENSCORE_DECL EcImageCalibration
{

   /// multiply rectangular subImages of foreground and background image.
   static EcF32 multiplySubImage
     (
      EcImage &image,
      EcU32 x1Bgnd, EcU32 y1Bgnd,
      EcU32 x1Fgnd, EcU32 y1Fgnd,
      EcU32 xlen, EcU32 ylen,
      unsigned char* fgndImgPtr,
      unsigned char* dstImgPtr
     );

   /// Scan a foreground window (ROI) across a background image.
   /// At each scan location, multiply the fgnd ROI against the
   /// bgnd ROI and normalize by the fgnd sum.
   static EcF32 scanMultiplyROI
     (
      EcImage &image,
      EcU32 x1Bgnd, EcU32 y1Bgnd,          // upper left crnr of bgnd ROI
      EcU32 x1Fgnd, EcU32 y1Fgnd,          // upper left crnr of fgnd ROI
      EcU32 xlenROI, EcU32 ylenROI,        // size of ROI
      EcU32 srchRangeX, EcU32 srchRangeY,  // search range to slide the fgnd ROI over bgnd
      EcU32 srchStepX,  EcU32 srchStepY,   // search step size between fgnd ROIs (in pixels)
      EcInt32 &matchPosX,  EcInt32 &matchPosY, // output: position of best match (on bgnd img)
      unsigned char* fgndImgPtr,
      unsigned char* dstImgPtr,
      const EcString& outputDirectory = ".",
      EcBoolean saveImages = EcFalse
     );

   /// Divide an image into blocks and count edges within each block.
   static EcBoolean prescanForEdges
     (
      EcImage &image,
      EcU32 blockSizeX,         // blockSize
      EcU32 blockSizeY,
      EcU32 edgeStrengthThrsh,  // threshold for pixel to be counted as an edge
      EcU32* edgeCntArray       // array holding edgeCnt values for each block
     );

   /// Overlay a foreground window (ROI) on a background image.
   static EcBoolean overlayROI
     (
      EcImage &image,
      unsigned char* fgndImgPtr,
      EcU32 x1Fgnd,  EcU32 y1Fgnd,         // upper left crnr of fgnd ROI
      EcU32 x1Bgnd,  EcU32 y1Bgnd,         // upper left crnr of bgnd ROI
      EcU32 xlenROI, EcU32 ylenROI,        // size of ROI
      EcU8 r,  EcU8 g,  EcU8 b,            // fgnd overlay color
      EcF32 alpha                          // alpha blend value
     );

   /// apply local low-pass filter to pixels significantly
   /// brighter than surrounding pixels.
   static EcBoolean brightSpeckleRemove
     (
      EcImage &image,
      EcF32 speckleCtrSrndRatioThrsh
     );

   /// mark spot on image with green square
   static EcBoolean markImage
     (
      EcImage &image,
      EcU32 x, EcU32 y,
      EcU32 markSize
     );

   /// mark spot on image with square of color (r,g,b)
   static EcBoolean markImage
     (
      EcImage &image,
      EcU32 x, EcU32 y,
      EcU32 markSize,
      EcU8 r, EcU8 g, EcU8 b
     );

   ///  apply high-pass filter to image, filter diagonally
   ///  return raw number of dots found.
   static EcU32 diagonalPointFilterDualImage
     (
      EcImage &image,
      unsigned char* dstImgPtr
     );


   ///  scale an ROI in an image.
   static EcBoolean scaleROI
     (
      EcImage &image,
      unsigned char* dstImgPtr,
      EcF32 scaleFactor,
      EcU32 x1Fgnd,
      EcU32 y1Fgnd,
      EcU32 xlenROI,
      EcU32 ylenROI
     );

   ///  scale an ROI in an image.
   ///    uses separate X & Y scale factors
   static EcBoolean scaleROI
     (
      EcImage &image,
      unsigned char* dstImgPtr,
      EcF32 scaleFactorX,
      EcF32 scaleFactorY,
      EcU32 x1Fgnd,
      EcU32 y1Fgnd,
      EcU32 xlenROI,
      EcU32 ylenROI
     );

   ///  rotate an ROI in an image.
   static EcBoolean rotateROI
     (
      EcImage &image,
      unsigned char* dstImgPtr,
      EcF32 thetaRot,
      EcU32 x1,
      EcU32 y1,
      EcU32 xlenROI,
      EcU32 ylenROI,
      EcU32 &x1dst,
      EcU32 &y1dst,
      EcU32 &xlenROIdst,
      EcU32 &ylenROIdst
     );


   /// rotate an image +/- 90-degrees
   static EcBoolean rotate90
     (
      EcImage &image,
      unsigned char* dstImgPtr,
      EcInt32 rotationDirection
     );


   /// transform point coordinates
   ///    (handles single target position)
   static EcBoolean transformDepthCoords
     (
      EcImage &image,
      EcReal targetRawPosXp, EcReal targetRawPosYp, EcReal targetRawPosZw,
      EcReal rx, EcReal ry, EcReal rz,
      EcReal focalLenPix,
      EcReal &targetLevelPosXw, EcReal &targetLevelPosYw, EcReal &targetLevelPosZw
     );

   /// transform point coordinates
   ///   (handles array of target positions)
   static EcBoolean transformDepthCoords
     (
      EcImage &image,
      EcU32 numBridgePositions,
      EcInt32 targetRawPosXp[], EcInt32 targetRawPosYp[], EcInt32 targetRawPosZw[],
      EcF32 rx[], EcF32 ry[], EcF32 rz[],
      EcF32 focalLenPix,
      EcF32 targetLevelPosXp[], EcF32 targetLevelPosYp[], EcF32 targetLevelPosZw[]
     );

   /// scan outward from image center, find dots.
   static EcBoolean findDots
     (
      EcImage &image,
      const EcU32 numDotsX,
      const EcU32 numDotsY
     );

   /// scan image, check for sufficient luminance.
   static EcBoolean checkLuminance
     (
      EcImage &image
     );

   /// scan image, check for sufficient structure.
   static EcBoolean checkStructure
     (
      EcImage &image
     );

   // calculate lens focal length from calibration target dot
   // locations and know distance to target.
   static EcF32 calibrateCameraLens
     (
      EcImage &image,
      const EcU32 numDotsX,
      const EcU32 numDotsY,
      const EcF32 dotSpacing,
      const EcF32 distanceToTarget
     );
};

#endif // ecImageCalibration_H_
