#ifndef ec_ConnectionManager_H_
#  error "This file should not be included directly.  Use 'ecConnectionManager.h'"
#endif
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecConnectionManager.ipp
//
//------------------------------------------------------------------------------

namespace Ec
{

//---
// ConnectionManager public method templates
//---

//------------------------------------------------------------------------------
template <typename T, typename C>
typename ConnectionManagerTypes::Signal<T,C>::PtrType ConnectionManager::registerSignal
   (
   const EcString& signalName,
   void* pProvider
   )
{
   typedef typename ConnectionManagerTypes::Signal<T,C>::Type    SignalType;
   typedef typename ConnectionManagerTypes::Signal<T,C>::PtrType SignalPtrType;

   if (!pProvider)
   {
      return SignalPtrType();
   }

   EcMutexScopedLock lock(m_Mutex);
   SignalType* pSignal = signal<T,C>(signalName, pProvider);
   if (!pSignal)
   {
      return SignalPtrType();
   }

   return SignalPtrType(pSignal, boost::bind(&ConnectionManager::unregisterSignal, this, signalName, pProvider));
}


//------------------------------------------------------------------------------
template <typename T>
typename ConnectionManagerTypes::Signal<T>::PtrType ConnectionManager::registerSignal
   (
   const EcString& signalName,
   void* pProvider
   )
{
   return registerSignal<T, boost::signals2::optional_last_value<typename boost::function_traits<T>::result_type> >(signalName, pProvider);
}

} // namespace Ec
