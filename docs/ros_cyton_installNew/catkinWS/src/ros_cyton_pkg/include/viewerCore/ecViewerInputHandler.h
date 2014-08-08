#ifndef ec_ViewerInputHandler_H_
#define ec_ViewerInputHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecViewerInputHandler.h
/// @class Ec::ViewerInputHandler
/// @brief General mouse interaction capability for Ec::Viewer.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.

#include <osgGA/OrbitManipulator>
#include <QtCore/QObject>

namespace Ec
{

class EC_GUICOMMON_VIEWERCORE_DECL ViewerInputHandler : public QObject, public osgGA::OrbitManipulator
{
   typedef osgGA::OrbitManipulator inherited;

   Q_OBJECT

public:
   /// Default constructor.
   explicit ViewerInputHandler
      (
      osg::Object* view ///< [in] View to register update slots to
      );

   /// Called by rendering code to get latest position for camera
   /// @return osg::Matrixd Position for camera
   virtual osg::Matrixd getInverseMatrix
      (
      ) const;

public Q_SLOTS:
   /// Sets the Center of Interest to be the specified node, or detach if NULL.
   void setNode
      (
      osg::Node* node ///< [in] Node to set as COI or NULL to detach
      );

   /// Called to inject external pose onto camera.
   void incrementalUpdate
      (
      double x,  ///< [in] X relative offset
      double y,  ///< [in] Y relative offset
      double z,  ///< [in] Z relative offset
      double rx, ///< [in] X-axis relative rotation
      double ry, ///< [in] Y-axis relative rotation
      double rz  ///< [in] Z-axis relative rotation
      );

   void zoomIn();             ///< Performs a zoom in action
   void zoomOut();            ///< Performs a zoom out action
   void resetToHome();        ///< Resets pose to a designated home
   void setCOI();             ///< Sets selected node as new COI

protected:
   virtual ~ViewerInputHandler() {} ///< Disable stack allocation

   /// Performs a relative translation from current location.
   void panModel(const float dx, const float dy, const float dz = 0.f);
   /// Performs the internal zooming operation.
   void zoomModel(const float dy, bool pushForwardedIfNeeded);

   /// Low-level camera adjustment operation.  Typically called by higher-level
   /// methods.  It performs a rotation about a sphere given a starting and
   /// distance set of points and a relative scale factor.
   void rotateCamera
      (
      const float px0,        ///< Starting X location
      const float py0,        ///< Starting Y location
      const float px1,        ///< Ending X location
      const float py1,        ///< Ending Y location
      const double throwScale ///< How much to rotate eyepoint
      );

   /// Performs a calculation to keep the eyepoint camera from going too far
   /// away from the scene.
   /// @return Whether the new location is within bounds or not
   bool inBounds
      (
      const float distance,     ///< [in] Distance from center
      const osg::Quat& rotation ///< [in] Orientation of eyepoint
      ) const;

   osg::Vec3f m_Offset;                   ///< COI offset
};

} // namespace Ec

#endif // ec_ViewerInputHandler_H_
