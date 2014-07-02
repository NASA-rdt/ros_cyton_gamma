#ifndef ecDefaultInputHandler_H_
#define ecDefaultInputHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecDefaultInputHandler.h
/// @brief Provides default handling of input events to update the
///        camera position based in mouse events.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecConstants.h>
#include <rendCore/ecSGBaseInputHandler.h>

namespace Ec { class InputHandlerSlotObject; class PluginGUI; }

class EC_GUICOMMON_VIEWERCORE_DECL EcDefaultInputHandler : public EcSGBaseInputHandler
{
   typedef EcSGBaseInputHandler inherited;

public:
   /// Constructor
   /// @param[in] plugin Owning plugin to supply simulation access
   /// @param[in] pWin Optional non-default window to apply handler to
   /// @param[in] tcpModeSlot
   explicit EcDefaultInputHandler
      (
      Ec::PluginGUI *plugin,
      EcSGWindow* pWin = EcNULL,
      EcBoolean tcpModeSlot = EcTrue
      );

   /// Adjust the amount of rotation scaling.
   /// @param[in] scale Scale factor to multiply the mouse movement by. 2.0 is the default.
   void setRotationScaling
      (
      const EcF32 scale
      );

   /// Retrieve the current size of the rotation scale factor.
   /// @return EcF32 Rotation scale factor.
   EcF32 rotationScaling
      (
      ) const;

   /// Adjust the amount of translation scaling.
   /// @param[in] scale Translation factor to multiply the mouse movement by. 2.0 is the default.
   void setTranslationScaling
      (
      const EcF32 scale
      );

   /// Retrieve the current size of the translation scale factor.
   /// @return EcF32 Translation scale factor.
   EcF32 translationScaling
      (
      ) const;

   /// Uses joystick's input to adjust view point or move selected end-effector.
   /// @param[in] pos Translation vector
   /// @param[in] rot Rotation vector
   virtual void incrementalUpdate
      (
      const osg::Vec3d& pos,
      const osg::Vec3d& rot
      );

   /// Toggle Tool Center Point (TCP) mode on/off
   /// @return Passes back new TCP mode value
   virtual EcBoolean toggleTCPMode
      (
      );

   /// disable/enable the inputs for end-effector (GuideAxis mode). View change is still enabled
   virtual void setGuideDisabled
      (
      EcBoolean disabled
      );

protected:

   /// Disallow explicit destruction.  osg::Referenced will delete when all references gone.
   virtual ~EcDefaultInputHandler
      (
      );

   virtual bool handleKeyDown
      (
      const osgGA::GUIEventAdapter& ea,
      osgGA::GUIActionAdapter& us
      );

   virtual bool handleKeyUp
      (
      const osgGA::GUIEventAdapter& ea,
      osgGA::GUIActionAdapter& us
      );

   virtual bool performMovement
      (
      );

   virtual EcU32 setCurrentMode
      (
      );

   /// Creates a quaternion based upon user input movements.
   /// @param[in] pos       X and Y offset position
   /// return     osg::Quat Caclucation rotation
   virtual osg::Quat getRotation
      (
      const osg::Vec3d& pos
      );

   virtual void zoomModel
      (
      const EcF32 dy,
      EcBoolean pushForwardedIfNeeded
      );

   /// Workhorse method to perform all underlying updates
   /// @param[in] mode Indicates whether it is a rotation or a translation
   ///                 along with what is being modified (eye,coi,guide)
   /// @param[in] vec  Vector with movement information
   virtual void move
      (
      const EcU32 mode,
      const osg::Vec3& vec
      );

   EcF32 m_RotationScaling;    ///< Scale factor for x,y rotation
   EcF32 m_TranslationScaling; ///< Scale factor for translations
   EcU32 m_CurrentMode;        ///< Current manipulation mode
   Ec::PluginGUI* m_pPlugin;   ///< Owning plugin
   Ec::InputHandlerSlotObject* m_pSlotObject; ///< Handle slotManager slots
   EcBoolean   m_TCPMode;     ///< Flag indicating whether TCP (Tool Center Point) mode is on/off
   EcBoolean   m_GuideDisabled; ///< Flag indicating whether the GuideAxis mode is disabled
};

#endif // ecDefaultInputHandler_H_
