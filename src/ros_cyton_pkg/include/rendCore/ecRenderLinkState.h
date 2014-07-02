#ifndef ec_RenderLinkState_H_
#define ec_RenderLinkState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderLinkState.h
/// @class Ec::RenderLinkState
/// @brief Provides ability to adjust link-level state attributes such
///        as bounding volumes, visibility, and guide frames.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>
#include <foundCore/ecConstants.h>
#include <osg/Material>
#include <osg/Vec4>

namespace osg { class Node; }

namespace Ec
{

/// Provide specific options for setting state
enum StateChange
{
   kRenderStateOff,
   kRenderStateOn,
   kRenderStateToggle
};

class EC_RENDER_RENDCORE_DECL RenderLinkState
{
public:
   /// Set rendering state, with optional on,off or toggle value
   /// @param[in,out] node       Node (and children) to set
   /// @param[in]     state      Parameter to work on
   /// @param[in]     stateValue Optional set state.  Toggles value by default
   static void setState
      (
      osg::Node* node,
      const EcU32 state,
      const StateChange stateValue = kRenderStateToggle
      );

   /// Retrieves the current values of state attributes.
   /// @param[in] node  Object to query
   /// @return    EcU32 Bitfields corresponding to current state of node
   static EcU32 getState
      (
      osg::Node* node
      );

   /// Adjusts the opacity (1-transparency) of the node
   /// @param[in] node    Object to modify
   /// @param[in] opacity Value to set to in units of percentage [1,100]
   static void setOpacityState
      (
      osg::Node* node,
      const EcU32 opacity
      );

   /// Retrieves the current opacity value of the node
   /// @param[in] node  Object to query
   /// @return    EcU32 Opacity in units of percentage
   static EcU32 getOpacityState
      (
      osg::Node* node
      );

   /// Sets the color of the node and its children. The history of colors can be kept. If it's kept, then when the new color
   /// is turned off, the last color in the history will then be applied to the node.
   /// @param[in, out] node  Object to modify
   /// @param[in] color Color channel values RGBA each channel ranges from 0.0 to 1.0
   /// @param[in] stateValue Optional set state.  Toggles value by default
   /// @param[in] nodeOnly Optional flag. If true, only the node will change color. If false, the node and all
   ///            its children will change color.
   /// @param[in] keepHistory Optional flag. If true, the color being set (on of toggle) will be kept in the history
   ///            of the node.
   /// @return EcBoolean true if color was set, false otherwise
   static EcBoolean setColorState
      (
      osg::Node* node,
      const osg::Vec4& color,
      const StateChange stateValue = kRenderStateToggle,
      EcBoolean nodeOnly = EcFalse,
      EcBoolean keepHistory = EcTrue
      );

   /// Retrieves the current color of the node and its children
   /// @param[in] node  Object to query
   /// @param[in,out] color Color channel values RGBA, each channel ranges from 0.0 to 1.0
   /// @return EcBoolean true if node has a material property set and color is returned, false otherwise
   static EcBoolean getColorState
      (
      osg::Node* node,
      osg::Vec4& color
      );

   /// Sets the osg material of the node and its children
   /// @param[in, out] node    Object to modify
   /// @param[in] material ref pointer to osg::Material to be applied to the node and its children
   /// @param[in] stateValue Optional set state.  Toggles value by default
   /// @return   EcBoolean true if material was set, false otherwise
   static EcBoolean setMaterialState
      (
      osg::Node* node,
      osg::ref_ptr<osg::Material> material,
      const StateChange stateValue = kRenderStateToggle
     );

   /// Retrieves the current osg material of the node and its children
   /// @param[in] node  Object to query
   /// @param[in,out] material ref pointer to the osg::Material applied to the node
   /// @return EcBoolean true if node has a material property set and material is returned, false otherwise
   static EcBoolean getMaterialState
      (
      osg::Node* node,
      osg::ref_ptr<osg::Material>& material
      );

};

} // namespace Ec

#endif // ec_RenderLinkState_H_
