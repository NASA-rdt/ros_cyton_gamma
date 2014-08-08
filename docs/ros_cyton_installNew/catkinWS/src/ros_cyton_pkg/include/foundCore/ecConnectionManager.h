#ifndef ec_ConnectionManager_H_
#define ec_ConnectionManager_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecConnectionManager.h
/// @class Ec::ConnectionManager
/// @brief Provides signal mechanism for plugins and simulation components.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecConnectionManagerTypes.h"
#include "ecMutex.h"
#include "ecTypes.h"

#include <boost/any.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

namespace Ec
{

class Application;
class Plugin;

//------------------------------------------------------------------------------
class EC_STABLE_FOUNDCORE_DECL ConnectionManager : private boost::noncopyable
{
public:
   /// Enumerations for relative ordering when calling slots.  Lower values
   /// take precedent over higher values.
   enum SlotGroupEnum
   {
      SlotGroupFirst   = 0,
      SlotGroupDefault = 1,
      SlotGroupLast    = 2
   };
   typedef EcInt32 SlotGroup; ///< Type for our slot group priority

   /// Add a new signal to be managed.  It will either create a new signal
   /// if new, or re-use the existing signal.
   /// This method is thread-safe.
   /// @return ConnectionManagerTypes::Signal<T>::PtrType Shared handle to signal
   template <typename T>
   typename ConnectionManagerTypes::Signal<T>::PtrType registerSignal
      (
      const EcString& signalName, ///< [in] Unique name identifier
      void* pProvider             ///< [in] Handle to signal invoker
      );


   /// Add a new signal to be managed.  It will either create a new signal
   /// if new, or re-use the existing signal.
   /// @return ConnectionManagerTypes::Signal<T,C>::PtrType Shared handle to signal
   template <typename T, typename C>
   typename ConnectionManagerTypes::Signal<T,C>::PtrType registerSignal
      (
      const EcString& signalName, ///< [in] Unique name identifier
      void* pProvider             ///< [in] Handle to signal invoker
      );

    /// Add a consumer/receiver for a particular signal.  The slot will be
    /// invoked when the signal is emitted.
    /// This method is thread-safe.
    /// @return ConnectionManagerTypes::ConnectionType Connection handle
   template <typename T>
   ConnectionManagerTypes::ConnectionType connectSlot
      (
      void* const ptr,                         ///< [in] Pointer to attach slot to
      const EcString& signalName,              ///< [in] Unique name identifier
      typename boost::function<T> slot,        ///< [in] Slot to call
      const SlotGroup group = SlotGroupDefault ///< [in] Relative ordering
      );

    /// Add a consumer/receiver for a particular signal.  The slot will be
    /// invoked when the signal is emitted.
    /// @return ConnectionManagerTypes::ConnectionType Connection handle
   template <typename T, typename C>
   ConnectionManagerTypes::ConnectionType connectSlot
      (
      void* const ptr,                         ///< [in] Pointer to attach slot to
      const EcString& signalName,              ///< [in] Unique name identifier
      typename boost::function<T> slot,        ///< [in] Slot to call
      const SlotGroup group = SlotGroupDefault ///< [in] Relative ordering
      );

   /// Currently boost::signals2 defers deletion of connections until another
   /// operation is performed on the signal.  This method will force that
   /// deletion by creating an removing a dummy connection from all signals
   /// used by this plugin.
   void unloadPlugin
      (
      Plugin* plugin ///< [in] Plugin pointer to operate on
      );

   /// Generates a named signalName that can be used to lookup a signal
   /// @return EcString Unique id attached only to this emitter
   static EcString namedSignal
      (
      const EcString& signalName, ///< [in] Unique name identifier
      void* const src             ///< [in] Emitter of signal
      );

private:
   friend class Application;
   typedef std::vector<void*> ProviderVector;

   /// @copydoc Ec::Application::init()
   void init
      (
      );

   /// Container to hold signal signature and list of providers of the signal
   struct SignalContainer
   {
      ProviderVector providers;
      boost::any     anySignalPtr;
   };

   /// Add new signal provider for the given signal.
   /// Not thread-safe (mutex must be locked before calling)
   void addProvider
      (
      SignalContainer& sc, ///< [in] Container object to apply provider to
      void* pProvider      ///< [in] Handle to object to be added to signal
      );

   /// Remove signal provider for the given signal.
   /// Not thread-safe (mutex must be locked before calling)
   void removeProvider
      (
      SignalContainer& sc, ///< [in] Container object to remove provider from
      void* pProvider      ///< [in] Handle to object to be removed from signal
      );

   /// Provide lookup mechanism based upon unique name
   /// Not thread-safe (mutex must be locked before calling)
   /// @return ConnectionManagerTypes::Signal<T>::Type Handle to signal or EcNULL if doesn't exist
   template <typename T>
   typename ConnectionManagerTypes::Signal<T>::Type* signal
      (
      const EcString& signalName, ///< [in] Unique name identifier
      void* pProvider = 0         ///< [in] Optional handle to provider to append to
      );

   template <typename T, typename C>
   typename ConnectionManagerTypes::Signal<T,C>::Type* signal
      (
      const EcString& signalName, ///< [in] Unique name identifier
      void* pProvider = 0         ///< [in] Optional handle to provider to append to
      );

   /// Remove the provider signal.
   /// This method is thread-safe.
   void unregisterSignal
      (
      const EcString& signalName, ///< [in] Unique name identifier
      void* pProvider             ///< [in] Handle to object that is unregistering signal
      );

   /// Removes the connection when the slot owner is removed.
   template <typename T, typename C>
   void disconnect
      (
      const EcString& signalName,                  ///< [in] Unique name identifier
      ConnectionManagerTypes::ConnectionType& conn ///< [in] Connection to remove
      );

   typedef std::vector<boost::any> DeleterVector;
   typedef std::map<void*, DeleterVector> PluginDataMapType;
   typedef std::map<EcString, SignalContainer> SignalMapType;

   EcMutex           m_Mutex;
   SignalMapType     m_SignalMap;     ///< Signals map
   PluginDataMapType m_PluginDataMap; ///< Connection owner map (plugins)
};

} // namespace Ec

// Add template instantiation definitions
#include "ecConnectionManager.ipp"

#endif // ec_ConnectionManager_H_
