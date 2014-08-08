#ifndef ecFoundCommonTokens_H_
#define ecFoundCommonTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecFoundCommonTokens.h
/// @brief Token definitions for the foundCommon project.
/// @details namespace EcFoundCommon
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <xml/ecToken.h>

/// Token definitions for the foundCommon project.
namespace EcFoundCommon
{
   ECTOKEN_DEFINITIONS(EC_FOUNDATION_FOUNDCOMMON_DECL,
      // The namespace is reused for subsequent tokens
      (ns, "http://www.energid.com/namespace/cr#")

      // Elements

      (Ec2DCircleToken,                     ns + "2DCircle")
      (Ec2DEllipseToken,                    ns + "2DEllipse")
      (Ec2DPolygon8Token,                   ns + "2DPolygon8")
      (Ec2DRectangle,                       ns + "2DRectangle")
      (Ec2DShape,                           ns + "2DShape")
      (Ec2DShapeNameToken,                  ns + "shapeName")
      (Ec2DShapeVectorToken,                ns + "2DShapeVector")
      (Ec2DPointVector,                     ns + "2DPointVector")
      (Ec2DPointToken,                      ns + "2DPoint")
      (Ec2DShapeContainerToken,             ns + "2DShapeContainter")
      (Ec2DShapeBitFlagToken,               ns + "2DShapeBitFlag")

      (EcAlphaToken,                        ns + "alpha")
      (EcAngularToken,                      ns + "angular")
      (EcBitFlags,                          ns + "bitflags")
      (EcBlueToken,                         ns + "blue")
      (EcCircleCenterXToken,                ns + "CircleCentreX")
      (EcCircleCenterYToken,                ns + "CircleCentreY")
      (EcCircleRadiusToken,                 ns + "CircleRadius")
      (EcCenterXToken,                      ns + "centerX")
      (EcCenterYToken,                      ns + "centerY")
      (EcColorToken,                        ns + "color")
      (EcCoordinateSystemTransformToken,    ns + "coordinateSystemTransform")
      (EcDataMapToken,                      ns + "dataMap")
      (EcDataMapMapToken,                   ns + "dataMapMap")
      (EcEndEffectorPlacementToken,         ns + "endEffectorPlacement")
      (EcEndEffectorPlacementDataToken,     ns + "endEffectorPlacementData")
      (EcGeneralForceToken,                 ns + "generalForce")
      (EcGeneralMotionToken,                ns + "generalMotion")
      (EcGeneralVelocityToken,              ns + "generalVelocity")
      (EcGreenToken,                        ns + "green")
      (EcIntegerMapToken,                   ns + "integerMap")
      (EcIntegerVectorMapToken,             ns + "integerVectorMap")
      (EcJxxToken,                          ns + "jXX")
      (EcJyyToken,                          ns + "jYY")
      (EcJzzToken,                          ns + "jZZ")
      (EcJxyToken,                          ns + "jXY")
      (EcJxzToken,                          ns + "jXZ")
      (EcJyzToken,                          ns + "jYZ")
      (EcLengthToken,                       ns + "length")
      (EcPlanarVectorToken,                 ns + "planarVector")
      (EcRealMapToken,                      ns + "realMap")
      (EcRealVectorMapToken,                ns + "realVectorMap")
      (EcRectangularDefectToken,            ns + "rectangularDefect")
      (EcRedToken,                          ns + "red")
      (EcRow0Token,                         ns + "row0")
      (EcRow1Token,                         ns + "row1")
      (EcRow2Token,                         ns + "row2")
      (EcRotationToken,                     ns + "rotation")
      (EcSecondMomentToken,                 ns + "secondMoment")
      (EcSpatialMatrixToken,                ns + "spatialMatrix")
      (EcStringMapToken,                    ns + "stringMap")
      (EcSupplementDataToken,               ns + "supplementData")
      (EcTranslationToken,                  ns + "translation")

      (EcWidthToken,                        ns + "width")
      (EcXCoordinateToken,                  ns + "xCoordinate")
      (EcYCoordinateToken,                  ns + "yCoordinate")


      // surface description keys ... not part of XML
      // prefixed with ec to separate the keys used internally
      (EcAmbientRedToken,                   "ecAmbientRed")
      (EcAmbientGreenToken,                 "ecAmbientGreen")
      (EcAmbientBlueToken,                  "ecAmbientBlue")
      (EcAmbientAlphaToken,                 "ecAmbientAlpha")

      (EcDiffuseRedToken,                   "ecDiffuseRed")
      (EcDiffuseGreenToken,                 "ecDiffuseGreen")
      (EcDiffuseBlueToken,                  "ecDiffuseBlue")
      (EcDiffuseAlphaToken,                 "ecDiffuseAlpha")

      (EcSpecularRedToken,                  "ecSpecularRed")
      (EcSpecularGreenToken,                "ecSpecularGreen")
      (EcSpecularBlueToken,                 "ecSpecularBlue")
      (EcSpecularAlphaToken,                "ecSpecularAlpha")

      (EcEmissionRedToken,                  "ecEmissionRed")
      (EcEmissionGreenToken,                "ecEmissionGreen")
      (EcEmissionBlueToken,                 "ecEmissionBlue")
      (EcEmissionAlphaToken,                "ecEmissionAlpha")

      (EcBlendTextureToken,                 "ecBlendTexture")
      (EcRenderBothSidesToken,              "ecRenderBothSides")

      (EcShininessToken,                    "ecShininess")
      (EcTextureFilenameToken,              "ecTextureFilename")
      (EcNormalTextureFilenameToken,        "ecNormalTextureFilename")

      (EcGLTextureMagFilterToken,           "ecTextureMagFilter")
      (EcGLTextureMinFilterToken,           "ecTextureMinFilter")
      (EcGLTextureEnvironmentModeToken,     "ecTextureEnvironmentMode")
      (EcSurfaceTensionSpringConstantToken, "ecSurfaceTensionSpringConstant")
      (EcSurfaceMaterialTypeToken,          "ecSurfaceMaterialType")
   )
}
#endif // ecFoundCommonTokens_H_
