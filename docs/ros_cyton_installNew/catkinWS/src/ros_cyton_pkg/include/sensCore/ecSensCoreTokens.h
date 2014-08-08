#ifndef ecSensCoreTokens_H_
#define ecSensCoreTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSensCoreTokens.h
/// @brief Defines tokens for Sensor Core.
/// @details namespace EcSensorCore
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>
#include <xml/ecToken.h>

/// Defines tokens for Sensor Core.
namespace EcSensorCore
{
   ECTOKEN_DEFINITIONS(EC_SENSOR_IMAGE_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/sn#")

      // Elements
      (EcBitsPerSubbyteValueToken,           ns + "bitsPerSubbyteValue")
      (EcBottomLeftTextPositionToken,        ns + "bottomLeftTextPosition")
      (EcBottomRightToken,                   ns + "bottomRight")
      (EcBoundingRectangleToken,             ns + "boundingRectangle")
      (EcCommentsToken,                      ns + "comments")
      (EcCompactTemplateToken,               ns + "compactTemplate")
      (EcDataToken,                          ns + "data")
      (EcEncodedImageData,                   ns + "encodedImageString")
      (EcEncodedImageToken,                  ns + "encodedImage")
      (EcFontIdToken,                        ns + "fontId")
      (EcFontCharWidthToken,                 ns + "fontCharWidth")
      (EcFontCharHeightToken,                ns + "fontCharHeight")
      (EcGridPointsToken,                    ns + "gridPoints")
      (EcImageBlockToken,                    ns + "imageBlock")
      (EcImageHeightToken,                   ns + "imageHeight")
      (EcImagePointToken,                    ns + "imagePoint")
      (EcImageRectangleToken,                ns + "imageRectangle")
      (EcImageRegionToken,                   ns + "imageRegion")
      (EcImageToken,                         ns + "image")
      (EcImageWidthToken,                    ns + "imageWidth")
      (EcLogarithmicMappingToken,            ns + "logarithmicMapping")
      (EcLowerBoundsToken,                   ns + "lowerBounds")
      (EcMultibyteArrayToken,                ns + "multibyteArray")
      (EcMultibytesPerValueToken,            ns + "multibytesPerValue")
      (EcNumChannelsToken,                   ns + "numChannels")
      (EcNumValuesToken,                     ns + "numValues")
      (EcPixelToken,                         ns + "pixel")
      (EcRealImageConversionParametersToken, ns + "realImageConversionParameters")
      (EcSensorDataToken,                    ns + "sensorData")
      (EcSpatialGridToken,                   ns + "spatialGrid")
      (EcSubbyteArrayToken,                  ns + "subbyteArray")
      (EcTextDescriptorToken,                ns + "textDescriptor")
      (EcTextRenderingModeToken,             ns + "textRenderingMode")
      (EcTextRenderingToolToken,             ns + "textRenderingTool")
      (EcTextStringToken,                    ns + "textString")
      (EcTopLeftToken,                       ns + "topLeft")
      (EcUpperBoundsToken,                   ns + "upperBounds")
      (EcValueGroupsToken,                   ns + "valueGroups")

      // Attributes ... namespace optional
      (EcImageFormat,                        "format")
      (EcXToken,                             "x")
      (EcYToken,                             "y")

      // Enumerations ... don't need namespace
      (EcBmp,                                "BMP")
      (EcJpegCompressed,                     "JPEG_COMP")
   )
}

#endif // ecSensCoreTokens_H_
