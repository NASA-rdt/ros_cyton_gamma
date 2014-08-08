#ifndef ecImageDrawing_H_
#define ecImageDrawing_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageDrawing.h
/// @class EcImageDrawing
/// @brief Provides mechanism for drawing geometry onto an EcImage.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

// Forward declarations
class EcImage;
class EcPlanarVector;
template <typename T> class EcXmlVectorType;

/// A vector of planar vectors
typedef EcXmlVectorType<EcPlanarVector> EcPlanarVectorVector;

/// Provides mechanism for drawing geometry onto an EcImage.
class EC_SENSOR_SENSCORE_DECL EcImageDrawing
{
public:
   /// draw a line in the image.
   static EcBoolean drawLine
      (
      EcImage &image,
      const EcReal dist,
      const EcReal angle,
      const EcU8   red   = 200,
      const EcU8   green = 0,
      const EcU8   blue  = 0,
      const EcU8   alpha = 255
      );

   /// draw a line in the image.
   static EcBoolean drawLine
	   (
	   EcImage &image,
	   const EcReal px,
	   const EcReal py,
	   const EcReal angle,
	   const EcU8   red   = 200,
	   const EcU8   green = 0,
	   const EcU8   blue  = 0,
	   const EcU8   alpha = 255
	   );

   /// draw a line in the image.
   static EcBoolean drawLine
      (
      EcImage &image,
      const EcReal sx,
      const EcReal sy,
      const EcReal ex,
      const EcReal ey,
      const EcU8   red,
      const EcU8   green,
      const EcU8   blue,
      const EcU8   alpha
      );


   // draw a circle in the image.
   static EcBoolean drawCircle
      (
      EcImage &image,
      const EcReal cx,
      const EcReal cy,
      const EcReal radius,
      const EcReal thickness,
      const EcU8   red,
      const EcU8   green,
      const EcU8   blue,
      const EcU8   alpha = 255
      );

   // draw an ellipse onto the imagery
   static EcBoolean drawEllipse
      (
      EcImage &image,
      const EcReal cx,
      const EcReal cy,
      const EcReal majorRadius,
      const EcReal minorRadius,
      const EcReal clockwiseRotationFromHorizontal,
      const EcReal thickness,
      const EcU8   red,
      const EcU8   green,
      const EcU8   blue,
      const EcU8   alpha = 255
      );

   // draw a general polygon onto the image
   static EcBoolean drawPolygon
      (
      EcImage &image,
      const EcPlanarVectorVector& points,
      const EcReal thickness,
      const EcBoolean fill,
      const EcU8Vector& channelValues
      );

      /// draw a rectangle in the image.
   static EcBoolean drawRect
      (
      EcImage &image,
      const EcInt32  sx,
      const EcInt32  sy,
      const EcInt32  ex,
      const EcInt32  ey,
      const EcU32    lineWidth,
      const EcU8     red,
      const EcU8     green,
      const EcU8     blue,
      const EcU8     alpha
      );

   static EcBoolean drawOrientedRect
      (
      EcImage &image,
      const EcU32&  cx,          // center x
      const EcU32&  cy,          // center y
      const EcU32&  length,      // length along the orientation
      const EcU32&  width,       // 90 degree from the orientation
      const EcReal& orientation, // in radians
      const EcU8   red,          // red scale
      const EcU8   green,        // green scale
      const EcU8   blue,         // blue scale
      const EcU8   alpha         // alpha channel
      );

};

#endif // ecImageDrawing_H_
