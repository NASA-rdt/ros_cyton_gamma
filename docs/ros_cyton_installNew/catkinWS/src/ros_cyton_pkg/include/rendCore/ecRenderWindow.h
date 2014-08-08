#ifndef ecRenderWindow_H_
#define ecRenderWindow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderWindow.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderLink.h"
#include "ecRenderTypes.h"
#include "ecSGWindow.h"

// Forward declarations.
class EcManipulatorSystemState;
class EcRenderManipulator;
class EcVisualizableStatedSystem;
class EcStatedSystem;

class EC_RENDER_RENDCORE_DECL EcRenderWindow : public EcSGWindow
{
public:
   typedef std::vector<EcRenderLink::RenderLinkVector> RenderLinkVectorVector;

   EcRenderWindow
      (
      );

   virtual ~EcRenderWindow
      (
      );

   ///////////////////////////////////////////////////////////////////////////
   /// Pre-init routines.  These methods are allowed before window          //
   /// initialization.                                                      //
   ///////////////////////////////////////////////////////////////////////////

   virtual void closeWindow
      (
      );

   /// Removes internal state information.
   virtual void deleteContents
      (
      );

   /// set the stated system and visualization parameters
   virtual EcBoolean setVisualizableStatedSystem
      (
      const EcVisualizableStatedSystem& visStatedSystem
      );

   /// set the stated system but keep the old visualization parameters
   virtual EcBoolean setStatedSystem
      (
      const EcStatedSystem& statedSystem
      );

   /// set the stated system and visualization parameters for rendering
   virtual EcBoolean setStatedSystem
      (
      const EcStatedSystem& statedSystem,
      const EcVisualizationParameters& visualizationParameters
      );

   /// get a pointer to the stated system
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// set the state for rendering
   virtual void setState
      (
      const EcManipulatorSystemState& state
      );

   /// get the state
   virtual const EcManipulatorSystemState* state
      (
      ) const;

   /// set the system ready flag
   virtual void setSystemReady
      (
      const EcBoolean systemReady
      );

   virtual EcBoolean systemReady
      (
      ) const;

   /// Retrieves a reference-counted pointer to an OSG node.
   /// @param manIndex Manipulator index.  Default is root node
   /// @param linkIndex Link index.  Default is to return base link
   /// @param getDH Optionally return DHFrame node
   /// @return ref_ptr<Group> Pointer to a valid object or empty on failure
   osg::ref_ptr<osg::Group> getNode
      (
      const EcU32 manIndex  = -1, // If -1, returns root node
      const EcU32 linkIndex = -1, // if -1, returns base man node
      const EcBoolean getDH = EcFalse
      ) const;

   ///////////////////////////////////////////////////////////////////////////
   /// Init and post-init routines.  These methods either initialize        //
   /// or force initialization when called.                                 //
   ///////////////////////////////////////////////////////////////////////////

   virtual EcBoolean init
      (
      );

   /// Reloads and initializes renderable geometry for scene graph.
   /// \return    EcBoolean Success or failure.
   virtual EcBoolean loadScene
      (
      );

   /// Updates object positions and state in scene.
   virtual void updateScene
      (
      );

protected:
   /// Document is loaded or not.
   EcBoolean m_SystemReady;
   /// manipulator state, not changing
   EcStatedSystem* m_pStatedSystem;
   /// vector storing all the models in this system
   std::vector<osg::ref_ptr<EcRenderManipulator> > m_vModels;
   /// state that changes with time
   EcManipulatorSystemState* m_pState;
   /// Mapping between joints and render links
   RenderLinkVectorVector m_vvRenderLinks;
   mutable EcMutex m_Mutex; ///< Provide thread-safe access to rendering
};

#endif // ecRenderWindow_H_
