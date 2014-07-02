#ifndef ecConvertSystemTokens_H_
#define ecConvertSystemTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecConvertSystemTokens.h
/// @brief Defines tokens for the convert project
/// @details Convert Tokens
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <xml/ecToken.h>

/// Holds tokens for the convert project
namespace EcConvertSystem
{
   ECTOKEN_DEFINITIONS(EC_FOUNDATION_CONVERTSYSTEM_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/sm#")

      // Elements
      (EcEnvelopToken,                    ns + "envelop")
      (EcLoadAsPolygonToken,              ns + "loadAsPolygon")
      (EcLoadHeadToken,                   ns + "loadHead")
      (EcLoadLeftArmToken,                ns + "loadLeftArm")
      (EcLoadLeftFingersToken,            ns + "loadLeftFingers")
      (EcLoadRightArmToken,               ns + "loadRightArm")
      (EcLoadRightFingersToken,           ns + "loadRightFingers")
      (EcLoadRightHandOnlyToken,          ns + "loadRightHandOnly")
      (EcPhysicalSystemExpanderToken,     ns + "physicalSystemExpander")
      (EcScaleFactorToken,                ns + "scaleFactor")
      (EcStatedSystemToken,               ns + "statedSystem")
      (EcSystem3dsLoaderToken,            ns + "system3dsLoader")
      (EcSystemAllLoaderToken,            ns + "systemAllLoader")
      (EcSystemAseLoaderToken,            ns + "systemAseLoader")
      (EcSystemCfgLoaderToken,            ns + "systemCfgLoader")
      (EcSystemPntpLoaderToken,           ns + "systemPntpLoader")
      (EcSystemS3dsLoaderToken,           ns + "systemS3dsLoader")
      (EcSystemSaseLoaderToken,           ns + "systemSaseLoader")
      (EcSystemTecplotLoaderToken,        ns + "systemTecplotLoader")
      (EcSystemVecLoaderToken,            ns + "systemVecLoader")
      (EcSystemVrml97LoaderToken,         ns + "systemVrml97Loader")
      (EcVecPhysicalExtentConverterToken, ns + "vecPhysicalExtentConverter")
      (EcVisualizableStatedSystemToken,   ns + "visualizableStatedSystem")
      (EcWeightingFactorPairVec2DToken,   ns + "weightingFactorPairVec2D")
   )
}

#endif // ecConvertSystemTokens_H_
