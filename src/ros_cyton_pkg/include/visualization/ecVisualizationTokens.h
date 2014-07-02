#ifndef ecVisualizationTokens_H_
#define ecVisualizationTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecVisualizationTokens.h
/// @brief Defines tokens for the visualization project
/// @details namespace EcVis
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <xml/ecToken.h>

/// Token definitions for the visualization project

namespace EcVis
{
   ECTOKEN_DEFINITIONS(EC_FOUNDATION_VISUALIZATION_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/mn#")

      // Elements
      (EcAmbientToken,                            ns + "ambient")
      (EcAmbientIntensityToken,                   ns + "ambientIntensity")
      (EcAttachmentIdentifiersToken,              ns + "attachmentIdentifiers")
      (EcBackgroundColorToken,                    ns + "backgroundColor")
      (EcCenterOfInterestToken,                   ns + "centerOfInterest")
      (EcCOISphereRadiusToken,                    ns + "coiSphereRadius")
      (EcCollisionDisplayFlagVectorVectorToken,   ns + "collisionDisplayFlagVectorVector")
      (EcCollisionDisplayOptionParasToken,        ns + "collisionDisplayOptionParameters")
      (EcConstantAttenuationToken,                ns + "constantAttenuation")
      (EcDiffuseToken,                            ns + "diffuse")
      (EcDisplayOptionsParametersToken,           ns + "displayOptionsParameters")
      (EcDisplayOptionsToken,                     ns + "displayOptions")
      (EcEndDisplayFlagVectorVectorToken,         ns + "endDisplayFlagVectorVector")
      (EcEndEffectorDisplayOptionParametersToken, ns + "endEffectorDisplayOptionParameters")
      (EcEyePointToken,                           ns + "eyePoint")
      (EcFarClippingDistanceToken,                ns + "farClippingDistance")
      (EcFieldOfViewToken,                        ns + "fieldOfView")
      (EcFrequencyToken,                          ns + "frequency")
      (EcGuideFrameAxisLengthToken,               ns + "guideFrameAxisLength")
      (EcGuiObjectParametersToken,                ns + "guiObjectParameters")
      (EcIntegerColorToken,                       ns + "integerColor")
      (EcIsOnToken,                               ns + "isOn")
      (EcIsPositionalToken,                       ns + "isPositional")
      (EcJointLimitDisplayFlagVectorVectorToken,  ns + "jointLimitDisplayFlagVectorVector")
      (EcJointLimitDisplayOptionParasToken,       ns + "jointLimitDisplayOptionParameters")
      (EcLightAtEyeToken,                         ns + "lightAtEye")
      (EcLightParametersToken,                    ns + "lightParameters")
      (EcLightsToken,                             ns + "lights")
      (EcLightToken,                              ns + "light")
      (EcLightNameToken,                          ns + "lightName")
      (EcLightCoordSysXformToken,                 ns + "lightCoordSysXform")
      (EcLinearAttenuationToken,                  ns + "linearAttenuation")
      (EcNearClippingDistanceToken,               ns + "nearClippingDistance")
      (EcPositionToken,                           ns + "position")
      (EcPovParametersToken,                      ns + "povParameters")
      (EcPriorityToken,                           ns + "priority")
      (EcQuadraticAttenuationToken,               ns + "quadraticAttenuation")
      (EcRenderParametersToken,                   ns + "renderParameters")
      (EcShadowAmbientBiasToken,                  ns + "ambientBias")
      (EcShadowParametersToken,                   ns + "shadowParameters")
      (EcShadowSoftnessWidthToken,                ns + "softnessWidth")
      (EcShadowTechniqueToken,                    ns + "shadowTechnique")
      (EcShadowTextureSizeToken,                  ns + "shadowTextureSize")
      (EcSpecularToken,                           ns + "specular")
      (EcSpotCutoffToken,                         ns + "spotCutoff")
      (EcSpotDirectionToken,                      ns + "spotDirection")
      (EcSpotExponentToken,                       ns + "spotExponent")
      (EcToleranceToken,                          ns + "tolerance")
      (EcUpToken,                                 ns + "up")
      (EcUseDefaultsToken,                        ns + "useDefaults")
      (EcUsedForShadowsToken,                     ns + "usedForShadows")
      (EcUserColorToken,                          ns + "userColor")
      (EcUseUserColorToken,                       ns + "useUserColor")
      (EcVisualizationParametersToken,            ns + "visualizationParameters")
      (EcZBufferFlagToken,                        ns + "zBufferFlag")
   )
}

#endif // ecVisualizationTokens_H_
