#ifndef ecMultiRenderWindow_H_
#define ecMultiRenderWindow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultiRenderWindow.h
/// @brief This class creates multiple identically sized rendering
///        areas within a single large window.  The user is able
///        to specify individual orientations and positions to use
///        for each camera.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderWindow.h"

// Forward class declarations.
namespace osg
{
   class Camera;
}

class EC_RENDER_RENDCORE_DECL EcMultiRenderWindow : public EcRenderWindow
{
public:
   // Set a typical maximum dimension for use in width and height.  Corresponds
   // to the size of the framebuffer.  When used with off-screen rendering it also
   // applies to the largest texture dimension available.  Current realistic max
   // dimensions are 4k, but most cards support 2k.
   static const EcU32 WINDOW_MAX_DIMENSION = 2048;

   enum ViewMode
   {
      VIEW_NONE = 0,
      VIEW_OBJECT,
      VIEW_EYE_TO_COI,
      VIEW_EYE_ABSOLUTE,
      VIEW_POV_EXPLICIT
   };

   EcMultiRenderWindow
      (
      );

   virtual ~EcMultiRenderWindow
      (
      );

   EcMultiRenderWindow
      (
      const EcU32 width,
      const EcU32 height,
      const EcU32 numWindows
      );

   /// Sets the individual sample size as well as the number of samples.
   virtual void setWindowParams
      (
      const EcU32 width,
      const EcU32 height,
      EcU32 numWindows = 0
      );

   /// Gets the number of sample windows being rendered.
   virtual EcU32 getNumWindows
      (
      ) const;

   /// Gets the size of an individual sample.
   virtual void getSingleWindowSize
      (
      EcU32 &width,
      EcU32 &height
      ) const;

   /// Override to set individual sample size
   /// \param[in] width     Inner width of single sample.
   /// \param[in] height    Inner height of single sample.
   /// \return    EcBoolean Returns whether window parameters have changed.
   virtual EcBoolean setWindowSize
      (
      const EcU32 width,
      const EcU32 height
      );

   /// Override to set individual sample size and global position.
   /// \param[in] width     Inner width of single sample.
   /// \param[in] height    Inner height of single sample.
   /// \param[in] posX      Number of pixels from the side of screen.
   /// \param[in] posY      Number of pixels down from top of screen.
   /// \return    EcBoolean Returns whether window parameters have changed.
   virtual EcBoolean setWindowSizeAndPos
      (
      const EcU32 width,
      const EcU32 height,
      const EcU32 posX,
      const EcU32 posY
      );

   /// Hint for specifying number of samples to display along X axis.
   virtual void setNumColumnsHint
      (
      const EcU32 numCols
      );

   /// Sets camera position of all samples.
   virtual void setEyePoints
      (
      const EcVectorVector &eyepoints
      );

   /// Sets pov parameters for all samples.
   virtual void setPovParametersVector
      (
      const EcPovParametersVector& povParametersVector
      );

   /// Sets camera position of all samples derived from object orientation.
   virtual void setCoords
      (
      const EcCoordinateSystemTransformationVector &coords,
      const ViewMode mode = VIEW_OBJECT
      );

   /// Initializes window and displays if necessary.
   /// \return EcBoolean Success or failure of initialization.
   virtual EcBoolean init
      (
      );

   virtual void updateScene
      (
      );

protected:

   typedef std::vector<osg::ref_ptr<osg::Camera> > CameraVector;
   // Vector of cameras - one for each sample.  Index 0 is camera from Viewer.
   CameraVector m_rCameraVector;

   // Vector to hold intermediate value before transformation to eye point.
   EcCoordinateSystemTransformationVector m_CoordVector;
   // Vector to hold camera position information.
   EcVectorVector m_EyePointVector;

   // Vector to hold POV information
   EcPovParametersVector m_PovParametersVector;

   // Determines whether eyepoint was given as relative object coordinates.
   mutable ViewMode m_ViewMode;
   // Desired number of columns in display output.
   mutable EcU32    m_NumColumnsHint;
   // Number of rows in output.
   mutable EcU32    m_NumRows;
   // Number of columns in output.
   mutable EcU32    m_NumColumns;
   // Size of individual sample width.
   mutable EcU32    m_SingleWidth;
   // Size of individual sample height.
   mutable EcU32    m_SingleHeight;
};

#endif // ecMultiRenderWindow_H_
