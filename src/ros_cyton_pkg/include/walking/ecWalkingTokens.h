#ifndef ecWalkingTokens_H_
#define ecWalkingTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecWalkingTokens.h
/// @brief Holds tokens for the walking project
/// @details namespace EcWalking
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecToken.h>

/// Holds tokens for the walking project
namespace EcWalking
{
   ECTOKEN_DEFINITIONS(EC_ACTIN_WALKING_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/ct#")

      // Elements
      (EcBaseEndEffectorPlacementConverterToken,    ns + "baseEndEffectorPlacementConverter")
      (EcCycloidTrajectoryGeneratorToken,           ns + "cycloidTrajectoryGenerator")
      (EcDirectionVectorToken,                      ns + "directionVector")
      (EcEndEffectorPlacementConverterVectorToken,  ns + "endEffectorPlacementConverterVector")
      (EcEndEffectorSetToken,                       ns + "endEffectorSet")
      (EcGenerateOrientationFlagToken,              ns + "generateOrientationFlag")
      (EcHexapodEndEffectorPlacementConverterToken, ns + "HexapodEndEffectorPlacementConverter")
      (EcLinearTrajectoryGeneratorToken,            ns + "linearTrajectoryGenerator")
      (EcManipulatorIndexToken,                     ns + "manipulatorIndex")
      (EcMaximumFootstepSizeToken,                  ns + "maximumFootstepSize")
      (EcMaximumSpeedToken,                         ns + "maximumSpeed")
      (EcPositionControlSystemWithConverterToken,   ns + "positionControlSystemWithConverter")
      (EcTrajectoryHeightToken,                     ns + "trajectoryHeight")
      (EcTrajectoryGeneratorVectorToken,            ns + "trajectoryGeneratorVector")
      (EcTrajectoryTimeStepToken,                   ns + "trajectoryTimeStep")
      (EcWalkingPlaneToken,                         ns + "walkingPlane")
   )
}

#endif // ecWalkingTokens_H_
