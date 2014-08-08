#ifndef manipulationDirectorExecPlugin_H_
#define manipulationDirectorExecPlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file manipulationDirectorExecPlugin.h
/// @class manipulationDirectorExecPlugin
/// @brief Plugin for manipulation director execution
//
//------------------------------------------------------------------------------
#include <plugins/plugins_config.h>
#include <foundCommon/ecDataMap.h>
#include <foundCore/ecConnectionManagerTypes.h>
#include <foundCore/ecPlugin.h>
#include <manipulationDirector/ecManipulationSceneCue.h>
#include <manipulator/ecPropagationResultData.h>
#include <plugins/ecPluginSignals.h>

#include <boost/function.hpp>
#include <boost/logic/tribool_fwd.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/mutex.hpp>

// Forward declarations
class EcManipulationDirectorState;
class EcManipulationScene;
class EcManipulationSceneDirectionContainer;
class EcManipulationScript;

//---------------------------------------------------------------------------
class EC_PLUGINS_MANIPULATIONDIRECTOREXEC_DECL manipulationDirectorExecPlugin : public Ec::Plugin
{
public:
   /// Type of the completion callback: void (*callback)(EcBoolean success)
   typedef boost::function1<void, EcBoolean> CompletionCallbackType;

   /// Type of the failure callback: void (*callback)(const EcPropagationResultDataVector& results)
   typedef boost::function1<void, const EcPropagationResultDataVector&> FailureCallbackType;

   /// Type of the update callback: void (*callback)(EcReal simTime, EcManipulationStatus::Enum status, const EcManipulationDirector& director, const EcManipulationDirectorSimpleState& dstate)
   typedef boost::function4<void, EcReal, EcManipulationStatus::Enum, const EcManipulationDirector&, const EcManipulationDirectorSimpleState&> UpdateCallbackType;

   /// Constructor.
   manipulationDirectorExecPlugin
      (
      );

   /// Destructor.
   ~manipulationDirectorExecPlugin
      (
      );

   /// @copydoc Ec::Plugin::initState()
   virtual EcBoolean initState
      (
      );

   /// @copydoc Ec::Plugin::readConfigurationString(EcXmlReader&)
   EcBoolean readConfigurationString
      (
      EcXmlReader& stream
      );

   /// @copydoc Ec::Plugin::writeConfigurationString(EcXmlWriter&) const
   EcBoolean writeConfigurationString
      (
      EcXmlWriter& stream
      ) const;

   /// override Ec::Plugin::update()
   virtual void update
      (
      const EcReal time
      );

   EcBoolean setManipulationCompletionCallback
      (
      CompletionCallbackType callback
      );

   EcBoolean setManipulationFailureCallback
      (
      FailureCallbackType callback
      );

   EcManipulationDirector manipulationDirector
      (
      ) const;

   EcBoolean setManipulationDirector
      (
      const EcManipulationDirector& director
      );

   EcBoolean setManipulationUpdateCallback
      (
      UpdateCallbackType callback
      );

   EcBoolean setScript
      (
      const EcManipulationScript& script
      );

   EcBoolean setPoseSetPtr
      (
      const EcPoseSet *value
      );

   EcBoolean start
      (
      EcBoolean continueIsAllowed = EcFalse
      );

   void stop
      (
      );

   EcBoolean appendScene
      (
      const EcManipulationScene& scene
      );

   EcBoolean directionCuesChanged
      (
      EcU32                               sceneIndex,
      const EcString&                     role,
      EcU32                               directionIndex,
      const EcManipulationSceneCueVector& oldCues,
      const EcManipulationSceneCueVector& newCues
      );

   EcBoolean insertDirection
      (
      EcU32                                        sceneIndex,
      const EcString&                              role,
      const EcManipulationSceneDirectionContainer& directionContainer,
      EcU32                                        directionIndex
      );

   EcBoolean moveDirection
      (
      EcU32           sceneIndex,
      const EcString& role,
      EcU32           oldDirectionIndex,
      EcU32           newDirectionIndex
      );

   EcBoolean removeDirection
      (
      EcU32           sceneIndex,
      const EcString& role,
      EcU32           directionIndex
      );

protected:

   EcBoolean directorStart
      (
      );

   void directorStop
      (
      EcBoolean resetState
      );

   EcBoolean directorUpdate
      (
      const EcReal simTime
      );

   boost::logic::tribool networkCallback
      (
      const EcU32 msgType,
      const EcString& msg
      );

   void resetProfiledEeIndices
      (
      );

   void syncAttachments
      (
      );

   void syncCollisionExclusions
      (
      );

   void updateAttachments
      (
      );

   void updateCollisionExclusions
      (
      );

   EcBoolean updatePlacement
      (
      );

   mutable EcMutex                                      m_Mutex;
   EcManipulationStatus::Enum                           m_StatusAtLastUpdate;
   boost::scoped_ptr<EcManipulationDirector>            m_DirectorPtr;
   boost::scoped_ptr<EcManipulationDirectorSimpleState> m_DirectorSimpleStatePtr;
   boost::scoped_ptr<EcManipulationDirectorState>       m_DirectorStatePtr;
   CompletionCallbackType                               m_CompletionCallback;
   FailureCallbackType                                  m_FailureCallback;
   UpdateCallbackType                                   m_UpdateCallback;
   EcBoolean                                            m_AutoStart;
   EcBoolean                                            m_ManipulationSuccess;
   EcBoolean                                            m_ContinueIsAllowed;
   const EcPoseSet*                                     m_pPoseSet;
   EcU32VectorVector                                    m_ProfiledEeIndices;
   EcPropagationResultDataVector                        m_Results;

   Ec::ConnectionManagerTypes::Signal<Ec::SignalManipulationSequenceCompleteTraits::Type>::PtrType m_CompletionSignalPtr;
   Ec::ConnectionManagerTypes::Signal<Ec::SignalRemoteCommandResultTraits::Type>::PtrType m_RemoteCommandResultSignalPtr;
};

#endif // manipulationDirectorExecPlugin_H_
