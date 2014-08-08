#ifndef ecSGBaseInputHandler_H_
#define ecSGBaseInputHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecSGBaseInputHandler.h
/// @class EcSGBaseInputHandler
/// @brief Manipulation class that provides basic support for updating
///        the eyepoint (camera) for the rendering window.  The only
///        form of manipulation is by directly setting using
///        setPovParameters(pov) or setBy[Inverse]Matrix(mat).
///        This class forms the basis for more sophisticated methods of
///        changing the view.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecConstants.h>

#include <osgGA/OrbitManipulator>

// Forward declarations.
class EcSGWindow;
class EcVector;

class EC_RENDER_RENDCORE_DECL EcSGBaseInputHandler : public osgGA::OrbitManipulator
{
   typedef osgGA::OrbitManipulator inherited;

public:
   enum AxisEnum
   {
      kAxisNone = 0x0,
      kAxisX    = 0x1,
      kAxisY    = 0x2,
      kAxisZ    = 0x4
   };

   explicit EcSGBaseInputHandler
      (
      EcSGWindow *pWin
      );

   /// Called by rendering code to get latest manipulator position for camera
   virtual osg::Matrixd getInverseMatrix
      (
      ) const;

   virtual void setDominantAxis
      (
      const EcU8 axis,
      const EcBoolean augment = EcTrue
      );

   virtual EcU8 dominantAxis
      (
      ) const;

   /// Set precision mode on (movement slowed by a factor of 10)
   /// @param[in] p Whether to set or unset
   void setPrecisionMode
	  (
	  const EcBoolean p
	  );

   /// Gets if precision mode is on
   /// @return EcBoolean whether or not precision mode is true
   EcBoolean precisionMode
      (
      ) const;

   virtual void setNode
      (
      osg::Node* node
      );

   virtual bool handleKeyUp
      (
      const osgGA::GUIEventAdapter& ea,
      osgGA::GUIActionAdapter& us
      );

   virtual bool handleKeyDown
      (
      const osgGA::GUIEventAdapter& ea,
      osgGA::GUIActionAdapter& us
      );

   virtual void home
      (
      const osgGA::GUIEventAdapter& ea,
      osgGA::GUIActionAdapter& us
      );

   virtual void home
      (
      EcReal time
      );

protected:
   virtual ~EcSGBaseInputHandler
      (
      );

   virtual EcBoolean performMovement
      (
      );

   virtual EcBoolean performMovementLeftMouseButton
      (
      const EcReal eventTimeDelta,
      const EcReal dx,
      const EcReal dy
      );

   virtual EcBoolean performMovementMiddleMouseButton
      (
      const EcReal eventTimeDelta,
      const EcReal dx,
      const EcReal dy
      );

   virtual EcBoolean performMovementRightMouseButton
      (
      const EcReal eventTimeDelta,
      const EcReal dx,
      const EcReal dy
      );

   virtual EcBoolean handleMouseWheel
      (
      const osgGA::GUIEventAdapter& ea,
      osgGA::GUIActionAdapter& us
      );

   /// Recalculates the eye point based on COI, distance and rotation.
   /// @return EcVector Passes back new eyepoint vector
   EcVector calculateEyepoint
      (
      ) const;

   osg::Vec3 filterVec
      (
      osg::Vec3 vec
      );

   /// Handle to window to control.  Get/Set config parameters like mouse mode and POV.
   EcSGWindow *m_pWin;
   EcBoolean m_Precise;			 ///< When the user wants Precise motion(slowed down)
   osg::Vec3 m_Offset;
   EcU8 m_DominantAxis;
};

#endif // ecSGBaseInputHandler_H_
