#ifndef ecMutex_H_
#define ecMutex_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecMutex.h
/// @brief Set of mutex abstraction definitions.  This allows the
///        implementation of mutex constructs to be defined in a
///        single location.
/// @details Currently supports the mutex itself along with a scoped locker.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"

#ifndef EC_NO_BOOST_MUTEX
#  include <boost/thread/locks.hpp>
#  include <boost/thread/mutex.hpp>
#  include <boost/thread/shared_mutex.hpp>
#  include <boost/thread/condition_variable.hpp>

   /// define EcMutex as the Boost mutex
   typedef boost::mutex                         EcMutex;

   /// define EcMutexScopedLock to be the Boost scoped lock
   typedef boost::mutex::scoped_lock            EcMutexScopedLock;

   /// define EcSharedMutex to be the Boost scoped lock
   typedef boost::shared_mutex                  EcSharedMutex;

   /// define EcSharedMutexSharedLock to be the Boost shared lock
   typedef boost::shared_lock<EcSharedMutex>    EcSharedMutexSharedLock;

   /// define EcSharedMutexLock to be the Boost mutex lock
   typedef boost::unique_lock<EcSharedMutex>    EcSharedMutexLock;

   /// define EcCondition to be the Boost condition variable
   typedef boost::condition_variable            EcCondition;
#else
#  define EcMutex                               int
#  define EcMutexScopedLock                     int
#  define EcSharedMutex                         int
#  define EcSharedMutexSharedLock               int
#  define EcSharedMutexLock                     int
#endif

#endif // ecMutex_H_
