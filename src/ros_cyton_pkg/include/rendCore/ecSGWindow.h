#ifndef ecSGWindow_H_
#define ecSGWindow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSGWindow.h
/// @class EcSGWindow
/// @brief SceneGraph-based 3D rendering window.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderHUD.h"
#include "ecRenderLight.h"
#include "ecRenderTypes.h"
#include "ecSGBaseInputHandler.h"
#include <render/ecWindow.h>
#include <visualization/ecVisualizationParameters.h>

#include <osg/Group>
#include <osgViewer/Viewer>
#include <osgShadow/ShadowedScene>
#include <osgShadow/ShadowTechnique>

// Forward class declarations.
namespace osg
{
   class Image;
   class LightSource;
   class Texture2D;
}
namespace osgText { class Text; }

/// SceneGraph-based 3D rendering window.
class EC_RENDER_RENDCORE_DECL EcSGWindow : public EcWindow
{
public:
   /// Class to specify custom drawing methods.  Capability exists to
   /// override rendering operation as well as pre- and post-rendering
   /// methods.  Subclass of osg::Referenced for reference counting.
   /// Note: Currently only a single custom DrawCallback class is
   ///       possible.  Default render() method simply calls viewer->frame().
   class EC_RENDER_RENDCORE_DECL DrawCallback : public osg::Referenced
   {
   public:
      /// Method that will be called before actual rendering.  Can be
      /// used to setup any variables or parameters needed for rendering.
      /// @param[in] viewer    Pointer to rendering viewer.
      /// @return    EcBoolean Success or failure of command.
      virtual EcBoolean preRender
         (
         osgViewer::Viewer *viewer
         ) { return EcTrue; }

      /// Base rendering method.  Default code calls:
      ///    preRender(viewer);
      ///    viewer->frame();
      ///    postRender(viewer);
      ///
      /// postRender(viewer) will only be called if a successful
      /// call to preRender(viewer) was made.
      ///
      /// @param[in] viewer    Pointer to rendering viewer.
      virtual void render
         (
         osgViewer::Viewer *viewer
         );

      /// Optional post-processing to be done after rendering.
      /// @param[in] viewer    Pointer to rendering viewer.
      /// @return    EcBoolean Success or failure of command.
      virtual EcBoolean postRender
         (
         osgViewer::Viewer *viewer
         ) { return EcTrue; }

   protected:
      /// Protected destructor to prohibit explicit deletion.  Reference
      /// counting will automatically clean up when no more references
      /// exist.
      virtual ~DrawCallback
         (
         );
   };

   /// Specific implementation of DrawCallback that can be used to perform
   /// screen captures.  It overrides pre- and post-rendering commands to
   /// initialize image memory and capture results.
   class EC_RENDER_RENDCORE_DECL ImageCaptureDrawCallback : public DrawCallback
   {
   public:
      /// Constructor.
      /// @param[in, out] image Image location to store results.
      /// @param[in]    mode  Orientation and type of image to capture.
      ImageCaptureDrawCallback
         (
         EcImage *image = EcNULL,
         const CaptureMode mode = CaptureFlippedColor
         );

      /// Specify a new image and mode to capture for existing callback.
      /// @param[in, out] image Image location to store results.
      /// @param[in]    mode  Orientation and type of image to capture.
      virtual void setCapture
         (
         EcImage *image,
         const CaptureMode mode = CaptureFlippedColor
         );

      /// Custom override to setup for proper rendering capture.
      /// @param[in] viewer    Pointer to rendering viewer.
      /// @return    EcBoolean Success or failure of command.
      virtual EcBoolean preRender
         (
         osgViewer::Viewer *viewer
         );

      /// Custom override to store results of rendering capture.
      /// @param[in] viewer    Pointer to rendering viewer.
      /// @return    EcBoolean Success or failure of command.
      virtual EcBoolean postRender
         (
         osgViewer::Viewer *viewer
         );

      /// Normalize depth buffer results to convert internal size to
      /// an 8-bit result.
      virtual void remapDepthBuffer
         (
         );

      /// convert depth buffer results to distances
      virtual void mapDepthBufferToDistance
         (
         EcReal dNear,
         EcReal dFar
         );

      /// Retrieve handle to unprocessed captured image.
      osg::ref_ptr<osg::Image> getCapturedImage
         (
         ) const;

   protected:
      /// Protected desctructor to prohibit explicit deletion.  Reference
      /// counting will automatically clean up when no more references
      /// exist.
      virtual ~ImageCaptureDrawCallback
         (
         );

      EcImage *m_pImage;                        //< Handle to result location.
      CaptureMode m_CaptureMode;                //< Orientation and type of capture.
      osg::ref_ptr<osg::Image> m_rCaptureImage; //< Internal data storage.
      EcU32 m_CaptureWidth;                     //< Captured image width.
      EcU32 m_CaptureHeight;                    //< Captured image height.
   };

   /// Constructor
   EcSGWindow
      (
      );

   /// Destructor
   virtual ~EcSGWindow
      (
      );

   ///////////////////////////////////////////////////////////////////////////
   /// Pre-init routines.  These methods are allowed before window          //
   /// initialization.                                                      //
   ///////////////////////////////////////////////////////////////////////////

   /// Load parameters related to scene rendering.
   /// @param[in] renderParameters Rendering information.
   void loadRenderParameters
      (
      const EcRenderParameters &renderParameters
      );

   /// Load lighting parameters from Xml.
   /// @param[in] lightParameter Lighting information.
   virtual void loadLight
      (
      const EcLightParameters &lightParameter
      );

   /// Resets internal vectors.  Currently lighting and model geometry.
   virtual void deleteContents
      (
      );

   /// Sets parameters for lighting, pov and rendering.
   /// @param[in] visualizationParameters  Visualization options.
   /// @return    EcBoolean                Success or failure of command.
   virtual EcBoolean setVisualizationParameters
      (
      const EcVisualizationParameters &visualizationParameters
      );

   /// Retrieve set of visualization parameters.
   /// @return const EcVisualizationParameters & Reference to internal parameters.
   virtual const EcVisualizationParameters &visualizationParameters
      (
      ) const;

   /// Specify camera/eyepoint information.
   /// @param[in] povParameters Viewpoint information.
   /// @return    EcBoolean     Success or failure of command.
   virtual EcBoolean setPovParameters
      (
      const EcPovParameters &povParameters
      );

   /// Retrieve camera/eyepoint information.
   /// @return const EcPovParameters & Viewpoint information.
   virtual const EcPovParameters &getPovParameters
      (
      ) const;

   /// Specify whether rendering should use on- or off-screen rendering.
   /// @param[in] isOffScreenRendering EcTrue or EcFalse
   /// @return    EcBoolean            Success or failure of command.
   virtual EcBoolean setOffScreenRendering
      (
      const EcBoolean isOffScreenRendering
      );

   /// Retrieve the state of off-screen rendering.
   /// @return EcBoolean EcTrue or EcFalse.
   virtual EcBoolean getOffScreenRendering
      (
      ) const;

   /// Turns viewer attribute[s] on or off for the scene.
   /// @param[in] attr    Attribute[s] to modify
   /// @param[in] enabled Whether to attribute should be enabled or disabled.
   virtual void setViewerAttribute
      (
      const EcRenderTypes::ViewerAttribute attr,
      const EcBoolean enabled
      );

   /// Retrieve state of viewer atrribute[s] in the scene.
   /// @return EcRenderTypes::ViewerAttribute Current attributes in use.
   virtual EcRenderTypes::ViewerAttribute viewerAttribute
      (
      ) const;

   /// Returns the entire collection of mask flags.
   virtual EcRenderTypes::DisplayMask displayMask
      (
      ) const;

   /// Returns whether or not a particular display mask has been set.
   virtual EcBoolean displayMask
      (
      const EcRenderTypes::DisplayMask mask
      ) const;

   /// Set display bit[s] on or off.
   /// @param[in] mask    Value to set or clear.
   /// @param[in] isOn    Whether to set or clear bit(s)
   /// @param[in] modMask Whether to modify the modmask or not.
   virtual void setDisplayMask
      (
      const EcRenderTypes::DisplayMask mask,
      const EcBoolean isOn,
      const EcBoolean modMask = EcFalse
      );

   /// Retrieve status on whether stereo is on or off.
   /// @return EcBoolean State of stereo mode.
   virtual EcBoolean stereoOn
      (
      ) const;

   /// Sets field of view aspect ratio (width / height).
   /// @param[in] ar        New aspect ratio to use.
   /// @return    EcBoolean Whether or not aspect ratio has changed.
   virtual EcBoolean setAspectRatio
      (
      const EcReal ar
      );

   /// Retrieves the currently set field of view aspect ratio.
   /// @return EcReal Current aspect ratio.
   virtual EcReal aspectRatio
      (
      ) const;

   /// @copydoc EcWindow::setBackgroundColor(const EcColor&)
   void setBackgroundColor
      (
      const EcColor& color
      );

   /// Retrieves a pointer to the currently drawn root of the scene graph hierarchy.
   /// @return osg::ref_ptr<osg::Group> Group node of hierarchy.
   virtual osg::ref_ptr<osg::Group> getNode
      (
      ) const;

   /// Retrieves a pointer to the currently drawn shadowed scene node.
   /// All nodes to be shadowed should be children of this node
   /// @return osg::ref_ptr<osg::Group> osgShadow::ShadowedScene node.
   virtual osg::ref_ptr<osg::Group> getShadowedSceneNode
      (
      ) const;

   /// Retrieves a pointer to the node containing scene lights.
   /// All EcRenderLights not attached to link nodes should be placed in this group
   /// @return osg::ref_ptr<osg::Group> group node containing EcRenderLights.
   osg::ref_ptr<osg::Group> getRenderLightGroup
      (
      ) const;

   /// @copydoc EcWindow::setWindowSize(const EcU32, const EcU32)
   virtual EcBoolean setWindowSize
      (
      const EcU32 width,
      const EcU32 height
      );

   /// @copydoc EcWindow::setWindowSizeAndPos(const EcU32, const EcU32, const EcU32, const EcU32)
   virtual EcBoolean setWindowSizeAndPos
      (
      const EcU32 width,
      const EcU32 height,
      const EcU32 posX,
      const EcU32 posY
      );

   /// Specify a custom callback class to use.
   /// Note: Only a single callback class can be used at a time.
   /// @param[in] cb Pointer to callback instance to use.
   virtual void setDrawCallback
      (
      osg::ref_ptr<DrawCallback> cb
      );

   /// Retrieve the currently available DrawCallback.
   /// @return osg::ref_ptr<DrawCallback> Handle to current callback.
   virtual osg::ref_ptr<DrawCallback> getDrawCallback
      (
      ) const;

   /// Places 2D text using screen coordinates on top of the rendering window.
   /// @param[in] text     String to display.
   /// @param[in] x        Location from left of window to offset.
   /// @param[in] y        Location from top of window to offset.
   /// @param[in] color    Optional color to display text.  Default is white.
   /// @param[in] fontSize Optional font point size
   /// @return osgText::Text* Handle to newly-constructed text object.
   virtual osgText::Text* setOverlayText
      (
      const EcString &text,
      const EcU32 x,
      const EcU32 y,
      const EcColor& color = EcColor(1,1,1,1),
      const EcU32 fontSize = 30
      );

   /// Clears a given overlay text.
   /// @param[in] text The pointer to the overlay text (returned by setOverlayText) to be cleared.
   virtual void clearOverlayText
      (
      osgText::Text* text
      );

   /// Removes all existing overlay text.
   virtual void clearAllOverlayText
      (
      );

   /// Specify a custom handler class for processing user input.
   /// @param[in] pInputHandler Pointer to input handler to use.
   virtual void setInputHandler
      (
      osgGA::OrbitManipulator *pInputHandler
      );

   virtual osgGA::OrbitManipulator *getInputHandler
      (
      ) const;

   /// Accessor to internal viewer used to manage scene.
   /// @return osgViewer::Viewer Current pointer to viewer.
   virtual osgViewer::Viewer *getViewer
      (
      ) const;

   /// Get access to orthographic overlay camera to place objects in screen coordinates
   virtual osg::ref_ptr<osg::Camera> getOverlayCamera
      (
      );

   /// @copydoc EcWindow::closeWindow()
   virtual void closeWindow
      (
      );

   /// Updates scene information every frame.
   virtual void updateScene
      (
      );

   //------------------------------------------------------------------------
   // Init and post-init routines.  These methods either initialize
   // or force initialization when called.
   //------------------------------------------------------------------------

   /// @copydoc EcWindow::init()
   virtual EcBoolean init
      (
      );

   /// Reloads and initializes renderable geometry for scene graph.
   /// @return EcBoolean Success or failure.
   virtual EcBoolean loadScene
      (
      );

   /// @copydoc EcWindow::renderScene(const EcBoolean)
   virtual EcBoolean renderScene
      (
      const EcBoolean swap = EcTrue
      );

   /// Pass an image to the rendering window to display.
   /// @param[in] image     EcImage to display.
   /// @param[in] swap      Whether to refresh screen or not.
   /// @return    EcBoolean Success or failure of command.
   virtual EcBoolean setImageBuffer
      (
      const EcImage &image,
      const EcBoolean swap = EcTrue
      );

   /// Draw the current scene and capture the results into an EcImage.
   /// Note: Currently only 8-bit RGB color or 8-bit depth supported.
   /// @param[in,out] image      Reference to location to store data.
   /// @param[in]     mode       Type and orientation of stored data.
   /// @return        EcBoolean  Success or failure of capture.
   virtual EcBoolean renderSceneAndCaptureImage
      (
      EcImage &image,
      const CaptureMode mode = CaptureFlippedColor
      );

   /// @copydoc EcWindow::renderSceneAndCaptureImage(EcImage&, const CaptureMode, const EcImageBlock* const)
   virtual EcBoolean renderSceneAndCaptureImage
      (
      EcImage &image,
      const CaptureMode mode,
      const EcImageBlock *const imageBlock
      );

   /// Updates guide frame pose
   /// @param[in] mat Position and orientation of guide frame.
   void setGuiMarkerMatrix
      (
      const osg::Matrix &mat
      );

   /// Specify the top-level node to use for the scene graph.
   /// @param[in] node      Pointer to root Group node for scene graph.
   /// @return    EcBoolean Success or failure of command.
   virtual EcBoolean setNode
      (
      osg::ref_ptr<osg::Group> node
      );

   /// set whether to always show guide axis
   virtual void setShowGuideAxis
      (
      EcBoolean show
      );
protected:
   /// Regenerates a new root node.  Used internally when clearing
   /// out old scene components.
   void newRoot
     (
     );

   /// [Re-]Initializes lights based on new EcLightParameters
   virtual void initLights
      (
      );

   /// Set the shadow rendering technique.
   /// @param[in] lightParameter containing shadow information.
   virtual void setShadowTechnique
      (
      const EcShadowParameters &shadowParameters
      );


   /// Set of parameters for controlling look and feel of visualization.
   EcVisualizationParameters m_VisParams;
   /// Screen aspect ratio.
   EcReal m_AR;
   /// Vector storing all the lights.
   EcRenderLightVector m_vLight;
   /// Adjust the amount of stereo, default at 1.0.
   EcReal m_StereoMagnitudeAdj;
   /// Adjust the Parallax, more:behind screen less: in front of screen
   EcReal m_ParallaxBalanceAdj;
   /// Transformation node holding the center of interest.
   osg::MatrixTransform *m_pCOI;
   /// Transfromation node holding the guide axis.
   osg::MatrixTransform *m_pAxis;
   /// Group node to hold geometry that is transient.
   osg::ref_ptr<osg::Group> m_rGroup;
   /// Determines what to display (node, BV, Guide, MassProp).
   EcRenderTypes::DisplayMask m_DisplayMask;
   /// Temporary addition to the display mask.
   EcRenderTypes::DisplayMask m_DisplayModMask;
   /// Bitfield indicating how the viewer is currently configured.
   EcRenderTypes::ViewerAttribute m_ViewerBits;
   /// Bitfield indicating what has changed this frame.
   EcRenderTypes::ChangedAttribute m_ChangedBits;
   /// Generic handle to input manipulators to change camera view.
   osg::ref_ptr<osgGA::OrbitManipulator> m_rInputHandler;

   /// Global root node
   osg::ref_ptr<osg::Group> m_rRoot;
   ///Lights group node
   osg::ref_ptr<osg::Group> m_rLightSourceGroup;
   /// Shadow scene group node
   osg::ref_ptr<osgShadow::ShadowedScene> m_rShadowedScene;
   /// Type of shadowing technque used
   osg::ref_ptr<osgShadow::ShadowTechnique> m_rShadowTechnique;

   /// Handle to OSG viewer that renders scene.
   osg::ref_ptr<osgViewer::Viewer> m_rViewer;
   /// Handle to window parameters - event queue, context, etc.
   osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> m_rGfxWindow;
   /// Handle to optional callback mechanism around rendering (for pre- and post-draw).
   osg::ref_ptr<DrawCallback> m_rDrawCallback;
   /// 2D Screen coordinate camera to provide overlay symbology and text.
   osg::ref_ptr<Ec::RenderHUD> m_HUDPtr;
   /// Flag indicating whether to always show guide axis
   EcBoolean   m_ShowGuideAxis;
};

#endif // ecSGWindow_H_
