#ifndef manipulationActionExecPlugin_H_
#define manipulationActionExecPlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file manipulationActionExecPlugin.h
/// @class manipulationActionExecPlugin
/// @brief Plugin for waypoint sequence execution
//
//------------------------------------------------------------------------------
#include <plugins/plugins_config.h>
#include <foundCommon/ecDataMap.h>
#include <foundCore/ecConnectionManagerTypes.h>
#include <foundCore/ecPlugin.h>
#include <manipulation/ecManipulationStatus.h>
#include <plugins/ecPluginSignals.h>

#include <fstream>
#include <boost/function.hpp>
#include <boost/logic/tribool_fwd.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/mutex.hpp>

// Forward declarations
class EcPoseSet;
class EcManipulationAction;
class EcManipulationActionContainer;
class EcManipulationActionManager;
class EcManipulationActionState;
class EcManipulationActionStateContainer;

/// manipulationActionExecPlugin directory
#if defined(plugins_manipulationActionExecPlugin_EXPORTS)
#  define EC_PLUGINS_MANIPULATIONACTIONEXEC_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_MANIPULATIONACTIONEXEC_DECL EC_DECL_IMPORTS
#endif

//---------------------------------------------------------------------------
class EC_PLUGINS_MANIPULATIONACTIONEXEC_DECL manipulationActionExecPlugin : public Ec::Plugin
{
public:
   /// Type of the completion callback: void (*callback)(EcBoolean success)
   typedef boost::function1<void, EcBoolean> CompletionCallbackType;

   /// Type of the update callback: void (*callback)(EcReal simTime, EcManipulationStatus::Enum status, const EcManipulationAction& director, const EcManipulationActionState& dstate)
   typedef boost::function4<void, EcReal, EcManipulationStatus::Enum, const EcManipulationAction&, const EcManipulationActionState&> UpdateCallbackType;

   /// Constructor.
   manipulationActionExecPlugin
      (
      );

   /// Destructor.
   ~manipulationActionExecPlugin
      (
      );

   /// @copydoc Ec::Plugin::initState()
   virtual EcBoolean initState
      (
      );

   /// @copydoc Ec::Plugin::reset();
   virtual EcBoolean reset
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

   const EcManipulationActionContainer& manipulationAction
      (
      ) const;

   EcBoolean setManipulationAction
      (
      const EcManipulationAction& action
      );

   EcBoolean setManipulationActionManager
      (
      const EcManipulationActionManager& actionManager
      );

   EcBoolean setManipulationAction
      (
      const EcString& actionName
      );

   EcBoolean setManipulationUpdateCallback
      (
      UpdateCallbackType callback
      );

   EcU32 manipIndex
      (
      ) const;

   EcBoolean setManipIndex
      (
      EcU32 index
      );

   EcU32 objectIndex
      (
      ) const;

   EcBoolean setObjectIndex
      (
      EcU32 index
      );

   EcBoolean setPoseSetPtr
      (
      const EcPoseSet *value
      );

   EcBoolean start
      (
      );

   void stop
      (
      );

protected:

   EcBoolean actionStart
      (
      );

   void actionStop
      (
      );

   EcBoolean actionUpdate
      (
      const EcReal simTime
      );

   boost::logic::tribool networkCallback
      (
      const EcU32 msgType,
      const EcString& msg
      );

   mutable EcMutex                                m_Mutex;
   boost::scoped_ptr<EcManipulationActionContainer>          m_ActionContainerPtr;
   boost::scoped_ptr<EcManipulationActionStateContainer>     m_ActionStateContainerPtr;
   CompletionCallbackType                         m_CompletionCallback;
   UpdateCallbackType                             m_UpdateCallback;
   EcBoolean                                      m_AutoStart;
   EcBoolean                                      m_ManipulationSuccess;
   EcU32                                          m_ManipIndex;
   EcU32                                          m_ObjectIndex;
   const EcPoseSet*                               m_pPoseSet;
   std::ofstream                                  m_Out;
   EcU32Vector                                    m_ProfiledEeIndices;
   boost::scoped_ptr<EcManipulationActionManager>        m_ActionManagerPtr;
   Ec::ConnectionManagerTypes::Signal<Ec::SignalRemoteCommandResultTraits::Type>::PtrType m_RemoteCommandResultSignalPtr;

};

#endif // manipulationActionExecPlugin_H_
