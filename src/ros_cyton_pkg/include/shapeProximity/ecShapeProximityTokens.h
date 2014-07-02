#ifndef ecShapeProximityTokens_H_
#define ecShapeProximityTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeProximityTokens.h
/// @brief Token definitions for the shapeProximity project
/// @details namespace EcShapeProx
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <xml/ecToken.h>

/// Token definitions for the geometry project
namespace EcShapeProx
{
   ECTOKEN_DEFINITIONS(EC_FOUNDATION_SHAPEPROXIMITY_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/mn#")
      (EcShapeProximityToolToken,                            ns + "shapeProximityTool")
   )
}

#endif // ecShapeProximityTokens_H_
