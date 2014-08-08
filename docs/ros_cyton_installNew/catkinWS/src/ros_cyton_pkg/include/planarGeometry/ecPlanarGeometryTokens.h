#ifndef ecPlanarGeometryTokens_H_
#define ecPlanarGeometryTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarGeometryTokens.h
/// @brief Token definitions for the planarGeometry project
/// @details namespace EcPlanarGeometry
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <xml/ecToken.h>

/// Token definitions for the planarGeometry project
namespace EcPlanarGeometry
{
   ECTOKEN_DEFINITIONS(EC_FOUNDATION_PLANARGEOMETRY_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/mn#")

      (EcCenterToken,                ns + "center")
      (EcEndpoint0Token,             ns + "endpoint0")
      (EcEndpoint1Token,             ns + "endpoint1")
      (EcExtentsToken,               ns + "extents")
      (EcPlanarAxisAlignedBoxToken,  ns + "planarAxisAlignedBox")
      (EcPlanarCircleToken,          ns + "planarCircle")
      (EcPlanarPolygonToken,         ns + "planarPolygon")
      (EcPlanarShapeContainerToken,  ns + "planarShapeContainer")
      (EcPlanarShapeLayersToken,     ns + "planarShapeLayers")
      (EcPlanarShapeUnionToken,      ns + "planarShapeUnion")
      (EcPlanarShapeVectorToken,     ns + "planarShapeVector")
      (EcPointsToken,                ns + "points")
      (EcRadiusToken,                ns + "radius")
      (EcShapeIdentifierToken,       ns + "shapeIdentifier")
      (EcShapeSurfaceProperyToken,   ns + "shapeSurfaceProperty")
   )
}

#endif // ecPlanarGeometryTokens_H_
