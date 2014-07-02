#ifndef ecReframingTool_H_
#define ecReframingTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecReframingTool.h
/// @class EcReframingTool
/// @brief Provides a tool for reframing a synthetic image by
///        croping and resampling.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

// forward declarations
class EcColor;
class EcImage;
class EcImageBlock;
class EcImagePoint;
class EcImageRegion;
class EcPixel;

/** Provides a tool for reframing a synthetic image by croping and resampling.
*/
class EC_SENSOR_SENSCORE_DECL EcReframingTool
{
public:
   /// default constructor
   EcReframingTool
      (
      );

   /// destructor
   virtual ~EcReframingTool
      (
      );

   /// copy constructor
   EcReframingTool
      (
      const EcReframingTool& orig
      );

   /// assignment operator
   EcReframingTool& operator=
      (
      const EcReframingTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcReframingTool& orig
      ) const;

   /// reframe a source to a destination
   virtual EcBoolean reframe
      (
      const EcImage& source,
      EcImage& dest,
      const EcU8Vector& vClearValues,
      const EcImage*    maskImgPtr,
      const EcColor&    bkgColor
      ) const;

   /// reframe a source to a destination and return the bounds an image block
   virtual EcBoolean reframeAndGetBounds
      (
      const EcImage& source,
      EcImage& dest,
      EcImageBlock& bounds,
      const EcU8Vector& vClearValues,
      const EcImage*    maskImgPtr,
      const EcColor&    bkgColor
      ) const;

   /// reframe a source to a destination and return the bounds as pixels
   virtual EcBoolean reframeAndGetBounds
      (
      const EcImage& source,
      EcImage& dest,
      EcPixel& topLeft,
      EcPixel& bottomRight,
      const EcU8Vector& vClearValues,
      const EcImage*    maskImgPtr,
      const EcColor&    bkgColor
      ) const;

   // resample the source at the specified pixel bounds
   virtual EcBoolean resample
      (
      const EcImage& source,
      EcImage& dest,
      const EcPixel& topLeft,
      const EcPixel& bottomRight,
      const EcImage*    maskImgPtr,
      const EcColor&    bkgColor
      ) const;

   // find bounds in a synthetic image
   virtual EcBoolean getBounds
      (
      const EcImage& source,
      EcPixel& topLeft,
      EcPixel& bottomRight,
      const EcU8Vector& vClearValues
      ) const;

   // find bounds on target pixels, given initial block.
   // assuming black background.
   virtual EcBoolean getBounds
      (
      const EcImage& source,
      EcPixel& topLeft,
      EcPixel& bottomRight
      ) const;

   // resample the source at the specified point bounds
   virtual EcBoolean resample
      (
      const EcImage& source,
      EcImage& dest,
      const EcImagePoint& topLeft,
      const EcImagePoint& bottomRight,
      const EcImage*    maskImgPtr,
      const EcColor&    bkgColor
      ) const;


   // resample the source at the specified point bounds
   virtual EcBoolean extractSubimage
      (
      const EcImage& source,
      EcImage& dest,
      const EcImageRegion& imageRegion
      ) const;

   //////////////////////////////////////////////////////////////////////////
   virtual EcBoolean masking
      (
      const EcImage& source,
      const EcImage* maskImgPtr,
      EcImage& dest
      )const;

   virtual EcBoolean edgeing
      (
      const EcImage& source
      )const;

   ////////////////////////////////////////
};

#endif // ecReframingTool_H_
