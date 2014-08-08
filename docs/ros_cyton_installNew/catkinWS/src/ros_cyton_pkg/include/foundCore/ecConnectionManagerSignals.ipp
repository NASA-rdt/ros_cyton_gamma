//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecConnectionManagerSignals.ipp
/// details Template definitions for connectSlot and signal are placed here so
/// that by default they are not visible to plugins.  Explicit symbols are
/// generated within ecTemplateInstSignals.cpp for default signals.  Any custom
/// signal would include this file to define their own, with the caveat on
/// windows that the plugin would need to be set with the TraitPermanent
/// flag to defer unloading because of the way memory is allocated within dlls.
//
//------------------------------------------------------------------------------
#include "ecConnectionManager.h"

//------------------------------------------------------------------------------
// Convenience macro for instantiating symbols with the desired signature.
#define FWD_DECL_SIGNAL(traits) \
   template EC_DECL_EXPORTS \
   Ec::ConnectionManagerTypes::ConnectionType \
   Ec::ConnectionManager::connectSlot<traits::Type>( \
      void* const, \
      const EcString&, \
      boost::function<traits::Type>, \
      const SlotGroup); \
   \
   template EC_DECL_EXPORTS \
      Ec::ConnectionManagerTypes::Signal<traits::Type>::Type* \
      Ec::ConnectionManager::signal<traits::Type, boost::signals2::optional_last_value<boost::function_traits<traits::Type>::result_type> >(const EcString&, void*)

#define FWD_DECL_SIGNAL_R(traits) \
   template EC_DECL_EXPORTS \
   Ec::ConnectionManagerTypes::ConnectionType \
   Ec::ConnectionManager::connectSlot<traits::Type, traits::Combiner>( \
      void* const, \
      const EcString&, \
      boost::function<traits::Type>, \
      const SlotGroup); \
   \
   template EC_DECL_EXPORTS \
      Ec::ConnectionManagerTypes::Signal<traits::Type, traits::Combiner>::Type* \
      Ec::ConnectionManager::signal<traits::Type, traits::Combiner>(const EcString&, void*)

namespace Ec
{

//------------------------------------------------------------------------------
template <typename T, typename C>
void ConnectionManager::disconnect
   (
   const EcString& signalName,
   ConnectionManagerTypes::ConnectionType& conn
   )
{
   // Don't disconnect a signal that has been removed.
   SignalMapType::iterator ii = m_SignalMap.find(signalName);
   if(ii == m_SignalMap.end())
   {
      return;
   }

   typename ConnectionManagerTypes::Signal<T,C>::Type* pSig = signal<T,C>(signalName);

   if(pSig)
   {
      conn.disconnect();

      // When our slot count is at 0, remove the signal
      // FIXME: There seems to be some type of overlap when more than one
      // plugin has a connection to a signal that has no emitter.  When this
      // happens the first plugin loaded should have been the one to allocate
      // the memory for the signal, but a crash will happen without the second
      // check in the conditional below.  The real solution is to come up with
      // a way to have a signal factory method that lives in ecFoundCore so
      // that memory allocated for signals does not get attached to a plugin.
      if(!pSig->num_slots() || !ii->second.providers.size())
      {
         m_SignalMap.erase(ii);
      }
      else
      {
         // Invoke signal garbase collection.  This is to workaround memory
         // that is allocated by a plugin for connections that gets trashed
         // when the plugin is deleted.  We connect/disconnect a dummy and
         // that 'flushes' the signal.
         boost::function<T> dummy = NULL;
         boost::signals2::scoped_connection c(pSig->connect(dummy));
      }
   }
}


//------------------------------------------------------------------------------
template <typename T, typename C>
typename ConnectionManagerTypes::Signal<T,C>::Type* ConnectionManager::signal
   (
   const EcString& signalName,
   void* pProvider // = 0
   )
{
   typedef typename ConnectionManagerTypes::Signal<T,C>::Type    SignalType;
   typedef typename ConnectionManagerTypes::Signal<T,C>::PtrType SignalPtrType;

   SignalMapType::iterator ii = m_SignalMap.find(signalName);
   if (ii == m_SignalMap.end())
   {
      SignalPtrType signalPtr(new SignalType);

      SignalContainer sc;
      addProvider(sc, pProvider);
      sc.anySignalPtr = signalPtr;
      m_SignalMap[signalName] = sc;

      return signalPtr.get();
   }

   // Validate type match
   try
   {
      SignalContainer& sc = (*ii).second;
      SignalPtrType signalPtr = boost::any_cast<SignalPtrType>(sc.anySignalPtr);
      addProvider(sc, pProvider);
      return signalPtr.get();
   }
   catch(...)
   {
   }

   return 0;
}


//------------------------------------------------------------------------------
template <typename T>
typename ConnectionManagerTypes::Signal<T>::Type* ConnectionManager::signal
   (
   const EcString& signalName,
   void* pProvider // = 0
   )
{
   return signal<T, boost::signals2::optional_last_value<typename boost::function_traits<T>::result_type> >(signalName, pProvider);
}


//------------------------------------------------------------------------------
template <typename T, typename C>
ConnectionManagerTypes::ConnectionType ConnectionManager::connectSlot
   (
   void* const ptr,
   const EcString& signalName,
   typename boost::function<T> slot,
   const SlotGroup group // SlotGroupDefault
   )
{
   typedef typename ConnectionManagerTypes::Signal<T,C>::Type SignalType;

   EcMutexScopedLock lock(m_Mutex);
   SignalType* pSignal = signal<T,C>(signalName);

   if(!pSignal)
   {
      return ConnectionManagerTypes::ConnectionType();
   }

   // This vector holds a map based upon an owner and a connection list.  It
   // is normally used for plugins to clean up when they are unloaded, but it
   // is also used to hold connections for EcIODataBroker and for ourselves
   // as well.  This code will automatically invoke the deletion code for our
   // signals/connections when an element of m_PluginDataMap is removed.
   PluginDataMapType::iterator ii = m_PluginDataMap.find(ptr);
   if (ii == m_PluginDataMap.end())
   {
      // Create a new entry
      ii = m_PluginDataMap.insert(std::make_pair(ptr, DeleterVector())).first;
   }
   // Add with a custom shared_ptr deleter
   ConnectionManagerTypes::ConnectionType c = pSignal->connect(group, slot);
   ii->second.push_back(boost::any(boost::shared_ptr<ConnectionManager>(this, boost::bind(&ConnectionManager::disconnect<T,C>, _1, signalName, c))));

   return c;
}


//------------------------------------------------------------------------------
template <typename T>
ConnectionManagerTypes::ConnectionType ConnectionManager::connectSlot
   (
   void* const ptr,
   const EcString& signalName,
   typename boost::function<T> slot,
   const SlotGroup group // SlotGroupDefault
   )
{
   return connectSlot<T, boost::signals2::optional_last_value<typename boost::function_traits<T>::result_type> >(ptr, signalName, slot, group);
}

} // namespace Ec
