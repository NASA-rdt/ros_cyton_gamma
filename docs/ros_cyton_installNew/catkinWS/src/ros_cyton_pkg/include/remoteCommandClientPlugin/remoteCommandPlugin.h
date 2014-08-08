#ifndef remoteCommandPlugin_H_
#define remoteCommandPlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file remoteCommandPlugin.h
/// @class remoteCommandPlugin
/// @brief A plugin to manage the underlying networking Transport of the remoteCommand
///        API.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConnectionManagerTypes.h>
#include <foundCore/ecPlugin.h>
#include <plugins/ecPluginSignals.h>
#include <control/ecManipEndEffectorPlace.h>

#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/logic/tribool_fwd.hpp>
#include <boost/thread/condition_variable.hpp>

#if defined(plugins_remoteCommandClientPlugin_EXPORTS)
#  define EC_REMOTECOMMANDPLUGIN_DECL EC_DECL_EXPORTS
#else
#  define EC_REMOTECOMMANDPLUGIN_DECL EC_DECL_IMPORTS
#endif

namespace Ec
{

namespace network { class Handle; class TransportHandle; }

/// Function signature for receiving manipulation completed messages.  The completion
/// value will be passed in as the argument.
typedef boost::function<void (EcBoolean, void*)> ManipulationCompleteCB;

}

class EcManipulationActionManager;
class EcManipulationDirector;
class EcManipulationScript;

class EC_REMOTECOMMANDPLUGIN_DECL remoteCommandPlugin : public Ec::Plugin
{
public:
   /// Optional callback registration to be notified when a manipulation action has
   /// finished.
   /// @param[in] cb Callback function to register
   /// @param[in] data Optional pointer to user data to pass along
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean setManipulationCompletedCallback(Ec::ManipulationCompleteCB cb, void* data = EcNULL);

   /// Specify a manipulation director to use.
   /// @param[in] director Director to use
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean setManipulationDirector(const EcManipulationDirector& director);

   /// Specify a manipulation script to use.
   /// @param[in] script Script to use
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean setManipulationScript(const EcManipulationScript& script);

   /// Specify a manipulation action manager to use.
   /// @param[in] manager Manipulation action manager to use
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean setManipulationActionManager(const EcManipulationActionManager& manager);

   /// Specify a name of manipulation action to execute. The action name must be in the action manager. Thus, this must
   /// be called AFTER a call to setManipulationActionManager.
   /// @param[in] actionName Name of manipulation action to execute.
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean setManipulationAction(const EcString& actionName);

   /// Specify a manipulation sequence to use.
   /// @param[in] seq String sequence to use
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean setManipulationSequence(const EcString& seq);

   /// Specify a manipulation path file to use.
   /// @param[in] filename Filename to of path file to load
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean setManipulationPathFile(const EcString& filename);

   /// Start a manipulation task specified previously with setManipulationScript(),
   /// setManipulationSequence(), or setManipulationPathFile().  No other
   /// manipulation commands are allowed to be issued once a sequence has started
   /// except stopManipulationSequence().  If a manipulation completion callback
   /// was registered, the completion status of the sequence will be sent when
   /// finished.
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean startManipulation();

   /// Stops a manipulation script that is in progress from
   /// startManipulationScript(). If a manipulation completion callback was
   /// registered, it will receive a hpcsm::StatusFailed message due to premature
   /// termination.
   /// @return EcBoolean Whether this command was successfully issued
   EcBoolean stopManipulation();

   template <typename T> EcBoolean sendToNetwork(const EcU32 msgType, const T& msg);
   EcBoolean sendToNetwork(const EcU32 msgType);

   remoteCommandPlugin();
   virtual ~remoteCommandPlugin();
   virtual EcBoolean init();
   boost::logic::tribool processRead(const EcU32 type, const EcString& msg);

   EcBoolean isConnected();
   EcBoolean connectNetwork(const EcString& ipAddress);
   void setNetworkModifiers(const EcU32 mode);

   void update(const EcReal time);
   EcBoolean waitForAck
   (
      const EcBoolean ack = EcFalse,
      const EcU32 timeout = 100  // ms
    );
   EcBoolean waitForValue();
   void terminate();

   void onSignalEndEffectorSet
      (
      const EcU32 manipIndex,
      const EcU32 eeSetIndex
      );

   void onSignalCollisionMap
      (
      );

   EcMutex m_Mutex;
   boost::condition_variable m_Condition;
   EcBoolean m_Status;
   EcBoolean m_ActionInProgress;
   Ec::ManipulationCompleteCB m_CB;
   void* m_CBData;
   boost::scoped_ptr<Ec::network::TransportHandle> m_TransportPtr;
   boost::any m_Value;

   Ec::ConnectionManagerTypes::Signal<Ec::SignalNetworkResultsTraits::Type>::PtrType m_NetworkResultsSignalPtr;

   typedef boost::shared_ptr<EcXmlObject> SharedObject;
   typedef std::map<EcU32,SharedObject> ValueMap;
   ValueMap m_vMap;
};

#endif // remoteCommandPlugin_H_
