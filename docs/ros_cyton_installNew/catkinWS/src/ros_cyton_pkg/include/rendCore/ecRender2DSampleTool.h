#ifndef ecRender2DSampleTool_H_
#define ecRender2DSampleTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecRender2DSampleTool.h
/// @brief Generates a 2D height/depth map based on the EcStatedSystem
///        and the reference frame.  This method uses the graphics
///        to calculate and therefore is limited to the capabilities
///        of the card.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecConstants.h>

class EcStatedSystem;
class EcCoordinateSystemTransformation;

class EC_RENDER_RENDCORE_DECL EcRender2DSampleTool
{
public:
   /// With a given statedSystem and referenceFrame, generate a height map.
   /// \param[in]  statedSystem    Input simulation and state.
   /// \param[in]  referenceFrame  Reference for eyepoint.
   /// \param[in]  widthInSamples  Size of X array size.
   /// \param[in]  heightInSamples Size of Y array size.
   /// \param[in]  widthInMeters   Physical extent of X direction.
   /// \param[in]  heightInMeters  Physical extent of Y direction.
   /// \param[in]  maxDepth        Generate calculation based off this depth.
   /// \param[out] result          VectorVector of EcReals from 1 to maxDepth.
   /// \return     EcBoolean       Success or Failure of command.
   static EcBoolean get2DMap
      (
      const EcStatedSystem& statedSystem,
      const EcCoordinateSystemTransformation& referenceFrame,
      const EcU32 widthInSamples,
      const EcU32 heightInSamples,
      const EcReal widthInMeters,
      const EcReal heightInMeters,
      const EcReal maxDepth,
      EcRealVectorVector& result
      );
};

#endif // ecRender2DSampleTool_H_
