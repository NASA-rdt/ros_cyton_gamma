#ifndef ecSmartMutex_H_
#define ecSmartMutex_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecSmartMutex.h
/// @class EcSmartMutex
/// @brief A smart mutex is one that combines the characteristics of
///        both a shared mutex (one writer/multiple readers) with that
///        of a recursive mutex (multi-locking within same thread).
///        This implementation builds upon a shared mutex and provides
///        checking against the currently running thread to remove the
///        occurrance of deadlocks.
//
//------------------------------------------------------------------------------
#include "ecMutex.h"

class EcSmartMutex : boost::noncopyable
{
public:
   EcSmartMutex
      (
      );

   ~EcSmartMutex
      (
      );

   /// First checks to see if it has already been locked by the current thread.
   /// If so, it is a no-op.  Otherwise it acquires the lock as normal.
   void lock
      (
      );

   /// Lowers reference count and unlocks mutex when counter is 0.
   void unlock
      (
      );

   /// First attempts to see if passthrough because of multi-locking, otherwise
   /// performs standard locking.
   bool try_lock
      (
      );

   // Shared mutex pass-through methods.

   /// pass-through method to Boost shared mutex lock_shared()
   void lock_shared() { m_Mutex.lock_shared(); }

   /// pass-through method to Boost shared mutex unlock_shared()
   void unlock_shared() { m_Mutex.unlock_shared(); }

   /// pass-through method to Boost shared mutex try_lock_shared()
   bool try_lock_shared() { return m_Mutex.try_lock_shared(); }

   /// pass-through method to Boost shared mutex lock_upgrade()
   void lock_upgrade() { m_Mutex.lock_upgrade(); }

   /// pass-through method to Boost shared mutex unlock_upgrade()
   void unlock_upgrade() { m_Mutex.unlock_upgrade(); }

   /// pass-through method to Boost shared mutex try_lock_upgrade()
   bool try_lock_upgrade() { return m_Mutex.try_lock_upgrade(); }

   /// pass-through method to Boost shared mutex unlock_upgrade_and_lock()
   void unlock_upgrade_and_lock() { m_Mutex.unlock_upgrade_and_lock(); }

   /// pass-through method to Boost shared mutex unlock_and_lock_upgrade()
   void unlock_and_lock_upgrade() { m_Mutex.unlock_and_lock_upgrade(); }

   /// pass-through method to Boost shared mutex unlock_and_lock_shared()
   void unlock_and_lock_shared() { m_Mutex.unlock_and_lock_shared(); }

   /// pass-through method to Boost shared unlock_upgrade_and_lock_shared()
   void unlock_upgrade_and_lock_shared() { m_Mutex.unlock_upgrade_and_lock_shared(); }

private:

#if WIN32
   typedef long      EcThreadID;
#else
   typedef pthread_t EcThreadID;
   EcMutex m_ThreadMutex;       ///< Mutex for atomic operations
#endif

   bool try_smart_lock
      (
      const EcThreadID threadId
      );

   bool try_basic_lock
      (
      const EcThreadID threadId
      );

   boost::shared_mutex m_Mutex; ///< Underlying mutex to lock
   EcThreadID m_ThreadId;       ///< Unique per-thread identifier
   int m_LockCount;             ///< Reference count of locks
};

/// typedef EcSmartMutexSharedLock to the Boost smart mutex shared lock
typedef boost::shared_lock<EcSmartMutex> EcSmartMutexSharedLock;

/// typedef EcSmartMutexLock to the Boost smart mutex lock
typedef boost::unique_lock<EcSmartMutex> EcSmartMutexLock;

#endif // ecSmartMutex_H_
