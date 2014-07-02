#ifndef ecImageSensorTokens_H_
#define ecImageSensorTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageSensorTokens.h
/// @brief Token definitions for the image sensor project
/// @details namespace EcImgSensor
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <xml/ecToken.h>

/// Token definitions for the image sensor project

namespace EcImgSensor
{
   ECTOKEN_DEFINITIONS(EC_FOUNDATION_IMAGESENSOR_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/mn#")

      // Elements
      (EcColorImageSensorToken,               ns + "colorImageSensor")
      (EcColorImageSensorDescriptorToken,     ns + "colorImageSensorDescriptor")
      (EcDeadPixelLocationsToken,             ns + "deadPixelLocations")
      (EcDefectivePixelsNoiseToken,           ns + "defectivePixelsNoise")
      (EcDisplayTypeToken,                    ns + "displayType")
      (EcFarClipPlane,                        ns + "farClipPlane")
      (EcFieldOfViewToken,                    ns + "fieldOfView")
      (EcFixedPatternNoiseToken,              ns + "fixedPatternNoise")
      (EcFrameRateToken,                      ns + "frameRate")
      (EcGaussianBlurToken,                   ns + "gaussianBlur")
      (EcGaussianSigmaToken,                  ns + "gaussianSigma")
      (EcHeightToken,                         ns + "height")
      (EcHotPixelLocationsToken,              ns + "hotPixelLocations")
      (EcImageSensorVectorToken,              ns + "imageSensorVector")
      (EcIntensityMagnitudeToken,             ns + "intensityMagnitude")
      (EcLabelToken,                          ns + "label")
      (EcLinkAttachmentToken,                 ns + "linkAttachment")
      (EcNearClipPlane,                       ns + "nearClipPlane")
      (EcNumChannelsToken,                    ns + "numberOfChannels")
      (EcNumDeadPixelsToken,                  ns + "numberOfDeadPixels")
      (EcNumHotPixelsToken,                   ns + "numberOfHotPixels")
      (EcPixelIntensityVariationsToken,       ns + "pixelIntensityVariations")
      (EcProcessorTypeToken,                  ns + "processorType")
      (EcRandomNoiseToken,                    ns + "randomNoise")
      (EcSensorNoiseVectorToken,              ns + "sensorNoiseVector")
      (EcSyntheticColorImageSensorToken,      ns + "syntheticColorImageSensor")
      (EcSyntheticImageSensorDescriptorToken, ns + "syntheticImageSensorDescriptor")
      (EcViewDistanceToken,                   ns + "viewDistance")
      (EcWidthToken,                          ns + "width")
   )
}

#endif // ecImageSensorTokens_H_
