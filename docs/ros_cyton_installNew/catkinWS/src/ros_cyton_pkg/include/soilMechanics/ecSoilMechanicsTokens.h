#ifndef ecSoilMechanicsTokens_H_
#define ecSoilMechanicsTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSoilMechanicsTokens.h
/// @brief Token declarations for the soilMechanics project
/// @details namespace EcSoilMechanics
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecToken.h>

/// Token definitions for the soilMechanics project
namespace EcSoilMechanics
{
   ECTOKEN_DEFINITIONS(EC_ACTIN_SOILMECHANICS_DECL,
      // The namespace is reused for subsequent tokens
      (ns, "http://www.energid.com/namespace/sm#")

      // Elements
      (EcBalovnevBucketExcavationInteractionToken,    ns + "balovnevBucketExcavationInteraction")
      (EcBalovnevExcavationInteractionToken,          ns + "balovnevExcavationInteraction")
      (EcExcavationForceProcessorToken,               ns + "excavationForceProcessor")
      (EcExcavationInteractionContainerToken,         ns + "excavationInteractionContainer")
      (EcDefaultWheelOffsetToken,                     ns + "defaultWheelOffset")
      (EcDefaultWheelRadiusToken,                     ns + "defaultWheelRadius")
      (EcDefaultWheelWidthToken,                      ns + "defaultWheelWidth")
      (EcExcavationToolPropertiesToken,               ns + "excavationToolProperties")
      (EcExcavationToolPropertiesContainerToken,      ns + "excavationToolPropertiesContainer")
      (EcMcKyesExcavationInteractionToken,            ns + "mcKyesExcavationInteraction")
      (EcParkExcavationInteractionToken,              ns + "parkExcavationInteraction")
      (EcPerumpralExcavationInteractionToken,         ns + "perumpralExcavationInteraction")
      (EcQinsenExcavationInteractionToken,            ns + "qinsenExcavationInteraction")
      (EcRigidWheelSoilForceProcessorToken,           ns + "rigidWheelSoilForceProcessor")
      (EcRigidWheelSoilInteractionContainerToken,     ns + "rigidWheelSoilInteractionContainer")
      (EcRigidWheelSoilInteractionToken,              ns + "rigidWheelSoilInteraction")
      (EcSoilPropertiesToken,                         ns + "soilProperties")
      (EcWheelOffsetMapToken,                         ns + "wheelOffsetMap")
      (EcWheelRadiusMapToken,                         ns + "wheelRadiusMap")
      (EcWheelWidthMapToken,                          ns + "wheelWidthMap")

      // soil property keys ... not part of XML
      // prefixed with ec to separate the keys used internally
      (EcAngleToken,                            "ecAngle")
      (EcBluntEdgeAngleToken,                   "ecBluntEdgeAngle")
      (EcBluntEdgeThicknessToken,               "ecBluntEdgeThickness")
      (EcCutSoilAccumulationAngleToken,         "ecCutSoilAccumulationAngle")
      (EcCutSoilCohesionToken,                  "ecCutSoilCohesion")
      (EcCutSoilSpecificMassToken,              "ecCutSoilSpecificMass")
      (EcHeightToken,                           "ecHeight")
      (EcRadiusToken,                           "ecRadius")
      (EcSideLengthToken,                       "ecSideLength")
      (EcSideThicknessToken,                    "ecSideThickness")
      (EcSoilCohesionToken,                     "ecSoilCohesion")
      (EcSoilCohesiveModulusToken,              "ecSoilCohesiveModulus")
      (EcSoilExternalFrictionAngleToken,        "ecSoilExternalFrictionAngle")
      (EcSoilFrictionalModulusToken,            "ecSoilFrictionalModulus")
      (EcSoilInternalFrictionAngleToken,        "ecSoilInternalFrictionAngle")
      (EcSoilShearDeformationModulusToken,      "ecSoilShearDeformationModulus")
      (EcSoilShearPlaneFailureAngleToken,       "ecSoilShearPlaneFailureAngle")
      (EcSoilSinkageExponentToken,              "ecSoilSinkageExponent")
      (EcSoilSinkageRatioToken,                 "ecSoilSinkageRatio")
      (EcSoilSpecificMassToken,                 "ecSoilSpecificMass")
      (EcSoilToolAdhesionToken,                 "ecSoilToolAdhesion")
      (EcWidthToken,                            "ecWidth")
   )
}

#endif // ecSoilMechanicsTokens_H_
