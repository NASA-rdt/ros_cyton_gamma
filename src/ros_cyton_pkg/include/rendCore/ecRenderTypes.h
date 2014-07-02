#ifndef ecRenderTypes_H_
#define ecRenderTypes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderTypes.h
/// @brief Commonly defined types for use within the rendering code.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecConstants.h>
#include <foundCore/ecVector.h>

#include <osg/Vec3>
#include <osg/Matrix>
#include <osg/Quat>

// Forward declarations.
class EcOrientation;
class EcCoordinateSystemTransformation;
class EcColor;

namespace EcRenderTypes
{
   /// All currently available masking options during rendering.  These
   /// segment the nodes in the scene graph so that these particular types
   /// may be enabled or disabled for rendering.
   enum DisplayAttributes
   {
      /// Global visibility
      Node             = 0x0001, ///< All generic geometry
      BoundingVolume   = 0x0002, ///< Bounding geometry for collision detection
      GuideFrame       = 0x0004, ///< Unit axis applied to joints
      MassProperties   = 0x0008, ///< Ellipsoids representing link mass properties
      ForceVectors     = 0x0010, ///< Force Vectors in dynamic simulation
      ObjectMarkers    = 0x0020, ///< Render Object geometry
      OverlayText      = 0x0040, ///< HUD text
      Visible          = 0x0080, ///< General visibility flag
      Highlight        = 0x0100, ///< Outline geometry
      AxisAlignedBB    = 0x0200, ///< Wireframe AABBs
      Dragger          = 0x0400, ///< Dragger
      CameraFrustum    = 0x0800, ///< Camera wireframe frustum
      GlobalMask       = 0x0fff, ///< Mask of all global visibility bits

      ///Other modifiers
      EmptyMask        = 0x0000, ///< No masking
      GuideAxis        = 0x1000, ///< Individual guide axis for EE placement
      CenterOfInterest = 0x2000, ///< COI of camera
      TranslateAttrib  = 0x4000, ///< Translation attribute
      RotateAttrib     = 0x8000, ///< Rotation attribute
      ModifierMask     = 0xf000, ///< Mask of all visibility modifier bits
      AllDisplayMask   = GlobalMask | ModifierMask, ///< All bits

      ColoredMode      = 0x10000, ///< Color the node through on material properties
      //Shadowing
      ShadowCaster     = 0x20000, ///< Denotes a node that can cast shadows
      ShadowReceiver   = 0x40000, ///< Denotes a node that can receive shadows
      LightMarker      = 0x80000, ///< Light marker geode visibility
      AxesOrientationHUD = 0x100000 ///< Coordinate system axes orientation heads up display
   };
   /// Type to hold bit collection of Masks.
   typedef EcU32 DisplayMask;

   /// Determines the characteristics of the matrix transform node in order
   /// to properly modify during an update.
   enum Transform
   {
      BASE,  ////< The base joint in the manipulator
      CHILD, ////< All other child links
      DH     ////< DH Frame transform
   };

   /// Attributes associated with an EcRenderShape indicating optional
   /// characteristics associated with rendering.
   enum Attributes
   {
      NOATTRIBUTES   = 0x0, ////< No attributes set
      DEFORMABLE     = 0x1, ////< Node geometry can deform
      SELECTED       = 0x2  ////< Node has been selected via UI
   };
   /// Type to hold bit collection of Attributes.
   typedef EcU32 TypeAttribute;

   /// Characteristics of the rendering window to represent scene.
   enum ViewerAttributes
   {
      AllDisabled     = 0x000, ///< No attributes enabled
      Lighting        = 0x001, ///< Lighting is enabled
      Stereo          = 0x002, ///< Stereo is enabled
      Texture         = 0x004, ///< Texturing is enabled
      WireFrame       = 0x008, ///< Wireframe is enabled
      SmoothShading   = 0x010, ///< Smooth shading is enabled
      BackFaceCulling = 0x020, ///< Back face culling of geomety is enabled
      OrthoProjection = 0x040, ///< Orthographic projection is on
      OffScreenRender = 0x080, ///< Offscreen rendering enabled (PBuffer or FBO)
      Displayed       = 0x100, ///< Whether the window is visible or not
      Shadows         = 0x200  ///< Shadows are enabled
   };
   /// Type to hold ViewerAttributes.
   typedef EcU32 ViewerAttribute;

   /// Flags indicating what has been modified in scene.
   enum ChangedAttributes
   {
      NoChange              = 0x00, ///< No Change
      GeometryChanged       = 0x01, ///< Physical geometry changed
      ViewChanged           = 0x02, ///< Camera view changed
      FrustumChanged        = 0x04, ///< Viewing frustum changed
      LightingChanged       = 0x08, ///< Lighting parameters changed
      BoundingVolumeChanged = 0x10, ///< Bounding Volume changed
      ViewParamsChanged     = 0x20, ///< Viewer parameters changed
      ViewerAttrChanged     = 0x40, ///< Viewer attributes changed
      ShadowingChanged      = 0x80, ///< Shadow settings changed
      AllChanged            = 0x7f  ///< Mask of all bits
   };
   /// Type to hold bitfields for ChangedAttributes.
   typedef EcU32 ChangedAttribute;


   /// Clears one or more bitfields.
   /// \param[in,out] var      Variable to apply operation onto
   /// \param[in]     bitfield Bitmask of fields to clear
   /// \return        T        Result of operation
   template <typename T, typename E> static T clearBit
      (
      T &var,
      const E bitfield
      )
   {
      return (var &= ~bitfield);
   }

   /// Sets one or more bitfields.
   /// \param[in,out] var      Variable to apply operation onto.
   /// \param[in]     bitfield Bitmask of fields to have set(or cleared)
   /// \param[in]     isSet    EcBoolean indicating to set or clear
   /// \return        T        Result of operation.
   template <typename T, typename E> static T setBit
      (
      T &var,
      const E bitfield,
      const EcBoolean isSet = EcTrue
      )
   {
      return isSet ? (var |= bitfield) : clearBit(var, bitfield);
   }

   /// Checs one or more bitfields to see if they are set.
   /// \param[in] var       Variable to perform test on
   /// \param[in] bitfield  Bitmask of fields to have set(or cleared)
   /// \return    EcBoolean Result of operation
   template <typename T, typename E> static EcBoolean checkBit
      (
      const T &var,
      const E bitfield
      )
   {
      return (var & bitfield ? EcTrue : EcFalse);
   }


   //-----------------------------------------------------------------------------
   // Helper functions to convert from Ec variables to OSG and vice versa.
   //-----------------------------------------------------------------------------

   /// Inline conversion of a 3 component vector.
   /// \param[in] ec Vector to convert from
   /// \return osg::Vec3d Vector to convert to
   extern EC_RENDER_RENDCORE_DECL osg::Vec3d ec2osg
      (
      const EcVector &ec
      );

   /// Conversion of a 3 component vector with no memory allocation.
   /// \param[in] ec Source vector
   /// \param[out] os Destination vector
   extern EC_RENDER_RENDCORE_DECL void ec2osg
      (
      const EcVector &ec,
      osg::Vec3d &os
      );

   /// Inline conversion of a 4 component vector.
   /// \param[in] ec Vector to convert from
   /// \return osg::Vec4 Vector to convert to
   extern EC_RENDER_RENDCORE_DECL osg::Vec4d ec2osg
      (
      const EcColor &ec
      );

   /// Inline conversion of a Quaterion.
   /// \param[in] ec Quaterion to convert from
   /// \return osg::Quat Quaternion to convert to
   extern EC_RENDER_RENDCORE_DECL osg::Quat ec2osg
      (
      const EcOrientation &ec
      );

   /// Inline conversion to a 4x4 transformation matrix.
   /// \param[in] ec coordinates to convert from
   /// \return osg::Matrixd 4x4 matrix to convert to
   extern EC_RENDER_RENDCORE_DECL osg::Matrixd ec2osg
      (
      const EcCoordinateSystemTransformation &ec
      );

   /// Inline conversion of a 3 component vector.
   /// \param[in] os Vector to convert from
   /// \return EcVector Vector to convert to
   extern EC_RENDER_RENDCORE_DECL EcVector osg2ec
      (
      const osg::Vec3d &os
      );

   /// Conversion of a 3 component vector with no memory allocation.
   /// \param[in] os Source vector
   /// \param[out] ec Destination vector
   extern EC_RENDER_RENDCORE_DECL void osg2ec
      (
      const osg::Vec3d &os,
      EcVector &ec
      );

   /// Inline Conversion of a 4 component color vector.
   /// \param[in] os Source vector
   /// \return EcColor Destination color vector
   extern EC_RENDER_RENDCORE_DECL EcColor osg2ec
      (
      const osg::Vec4d &os
      );

   /// Conversion of a quaternion with no memory allocation.
   /// \param[in] os Source quaternion
   /// \param[out] ec Destination quaternion
   extern EC_RENDER_RENDCORE_DECL void osg2ec
      (
      const osg::Quat &os,
      EcOrientation &ec
      );

   /// Conversion to a coordinate system with no memory allocation.
   /// \param[in] os Source 4x4 matrix
   /// \param[out] ec Destination coordinate system
   extern EC_RENDER_RENDCORE_DECL void osg2ec
      (
      const osg::Matrixd &os,
      EcCoordinateSystemTransformation &ec
      );

} // namespace EcRender

/// Output stream operators.
EC_RENDER_RENDCORE_DECL std::ostream&
operator<<
   (
   std::ostream& os,
   const osg::Vec3& vec
   );

EC_RENDER_RENDCORE_DECL std::ostream&
operator<<
   (
   std::ostream& os,
   const osg::Quat& quat
   );

EC_RENDER_RENDCORE_DECL std::ostream&
operator<<
   (
   std::ostream& os,
   const osg::Matrix& mat
   );

#endif // ecRenderTypes_H_
