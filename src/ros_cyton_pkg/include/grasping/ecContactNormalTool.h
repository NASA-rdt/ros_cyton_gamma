#ifndef ecContactNormalTool_H_
#define ecContactNormalTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContactNormalTool.h
/// @class EcContactNormalTool
/// @brief Tool to find contact normals on a shape
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

class EcCoordinateSystemTransformation;
class EcShape;
class EcVector;

/**
\class EcContactNormalTool

This class is a tool to help finding contact normals on a shape. It's needed for grasp contact locator.
It may be moved to geometry in the future.
*/
class EC_ACTIN_GRASPING_DECL EcContactNormalTool
{
public:
   /**
   Find the normal of the contact.
   \param[in] shape The shape of interest.
   \param[in] pointOnShape The contact point on the shape in the shape's local coordinates.
   \param[in] primaryInSystem The primary frame (in which the shape is defined) represented in the system frame.
   \param[in] otherShape The other shape of the contact.
   \param[in] pointOnOtherShape The contact point on the other shape in the other shape's local coordinates.
   \param[in] otherPrimaryInSystem The primary frame (in which the other shape is defined) represented in the system frame.
   \param[out] normal The normal in the shape's primary frame.
   \return True if normal is found successfully or false if normal isn't found or the shape types aren't supported.
   */
   static EcBoolean findNormal
      (
      const EcShape& shape,
      const EcVector& pointOnShape,
      const EcCoordinateSystemTransformation& primaryInSystem,
      const EcShape& otherShape,
      const EcVector& pointOnOtherShape,
      const EcCoordinateSystemTransformation& otherPrimaryInSystem,
      EcVector& normal
      );
};

#endif // ecContactNormalTool_H_
