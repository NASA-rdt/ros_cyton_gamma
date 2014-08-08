#ifndef ec_AsyncThread_H_
#define ec_AsyncThread_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecAsyncThread.h
/// @class Ec::AsyncThread
/// @brief Class to handle asynchronous threading in the simulation
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <boost/asio.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/thread.hpp>

// forward declarations.
class EcIODataBroker;
class EcRealTimeMemoryUsageImpl;

namespace boost { class thread; }

namespace Ec {

class EC_ACTIN_INTERFACE_DECL AsyncThread
{
public:
   /// constructor
   AsyncThread
      (
      const EcU32 updatePeriodInMs,
      EcIODataBroker* pBroker
      );

   /// destructor
   virtual ~AsyncThread
      (
      );

   /// start the thread
   virtual void start
      (
      );

   /// stop the thread
   virtual void stop
      (
      );

   //--------------------------------------------------------------------------
   // There are a few things that control real time for Actin:
   //   if (getenv("EC_REALTIME_PRIORITY") != EcNULL) 
   //      then ALL threads created as instanced of this class default to  
   //      run as the number in EC_REALTIME_PRIORITY, (0-99 normal bounds) 
   //      assuming it is within the specific bounds of this system (at  
   //      which case it goe to the bounded value).
   //
   // threadPriorityMin    Minimum value to set a thread priority.   
   // threadPriorityMax    Maximum value to set a thread priority.
   // threadPriority       Current thread priority.
   // setThreadPriority    Set (bounded to min/max) thread priority.
   //
   // threadingCPUs        Get number of CPUs software knows about, 
   //                         can return 1 when there is more than one on some
   //                         machines due to unsupported kernel functions.
   // threadAffinity       Get the threading CPU affinity.
   // setThreadAffinity    Set the threading CPU affinity.
   //--------------------------------------------------------------------------

   /// Minimum (lowest) thread priority on this system.
   /// Supported on Linux/OSX/Windows/VxWorks.
   /// Unsupported returns 0.
   virtual EcU32 threadPriorityMin
      (
      );

   /// Maximum (highest) thread priority on this system.
   /// Supported on Linux/OSX/Windows/VxWorks.
   /// Unsupported returns 0.
   virtual EcU32 threadPriorityMax
      (
      );

   /// Get current thread priority, clamped to within min/max.
   /// Supported on Linux/OSX/Windows/VxWorks.
   /// On windows, translates 0-99 to 1-31 base priorities.
   /// Unsupported returns 0.
   virtual EcU32 threadPriority
      (
      );

   /// Set current thread priority, clamped to within min/max.
   /// Supported on Linux/OSX/Windows/VxWorks.
   /// On windows, 1-31 base priorities to posix 0-99.
   virtual void setThreadPriority
      (
      EcU32 newValue                ///< New priority.
      );

   /// Get the number of virtual CPUs for which affinity 
   /// can be set.
   /// Supported on Linux/OSX/Windows, not VxWorks.
   /// If Unsupported, returns 1.
   virtual EcU32 threadingCPUs
      (
      );

   /// Get the threading affinity as a mask:
   ///   0x1      1st CPU
   ///   0x3      1st & 2nd CPU.
   /// Supported on Linux/Windows, not OSX or VxWorks.
   /// If Unsupported, returns 1.
   virtual EcU32 threadAffinity
      (
      );

   /// Set the thread affinity as a mask.
   ///   0x1      1st CPU
   ///   0x3      1st & 2nd CPU.
   /// Supported on Linux/Windows, not OSX or VxWorks.
   /// If Unsupported, returns 1.
   /// If the intersection of existing cores and the value
   /// is non, then affinity is set to none (that is what
   /// the caller requested) and the process probably doesn't run.
   virtual void setThreadAffinity
      (
      EcU32 newMaskValue               ///< New mask value.
      );

   /// Get is this task running "real-time".
   ///   This means it is running off of a pre-emptive, monotonic time.
   /// Supported on Linux only.
   virtual EcBoolean realTime
      (
      );

   /// Set is this task running in a real time loop?
   /// Supported on Linux only.
   virtual void setRealTime
      (
      EcBoolean newValue   ///< New value.
      );
  
   /// Update period in whole milliseconds.
   virtual EcU32 updatePeriodInMs
      (
      ) const;

   /// Set the update period in whole milliseconds.
   virtual void setUpdatePeriodInMs
      (
      EcU32 newValue       ///< New value.
      );
   
   /// The update fraction in Ns to support finer granularity when 
   /// in "real time" mode, m_UpdatePeriodInMs is whole milliseconds,
   /// this is the fraction of nano-seconds between milliseconds.
   /// Because "real time" is dynamic (to enter/exit) this can always
   /// be read/set, BUT only gets applied when in "real time" mode.
   virtual EcU32 updateFractionNs
      (
      ) const;

   /// The update fraction in Ns to support finer granularity when 
   /// in "real time" mode, m_UpdatePeriodInMs is whole milliseconds,
   /// this is the fraction of nano-seconds between milliseconds.
   /// Because "real time" is dynamic (to enter/exit) this can always
   /// be read/set, BUT only gets applied when in "real time" mode.
   virtual void setUpdateFractionNs
      (
      EcU32 newValue       ///< New value, 0 to 999,999 (clamped).
      );

   /// On Linux/OSX/VxWorks this value is a pthread_t.
   /// On windows a native handle.
   virtual boost::thread::native_handle_type getThreadID
      (
      );

   /// Platform independent millisecond sleep.
   /// Sleeps this thread AT LEAST the value in milliseconds, unless
   /// a signal wakes this thread.
   /// Performance varies by platform.
   virtual void sleepMS
      (
      EcU32 valueMilliseconds ///< Value in milli-seconds.
      );

   /// Platform independent micro second sleep.
   /// Sleeps this thread AT LEAST the value in microseconds, unless
   /// a signal wakes this thread.
   /// Performance varies by platform.
   virtual void sleepUS
      (
      EcU64 valueMicroseconds ///< Value in micro-seconds.
      );

   /// Platform independent nano second sleep.
   /// Sleeps this thread AT LEAST the value in nanoseconds, unless
   /// a signal wakes this thread.
   /// Performance varies by platform.
   virtual void sleepNS
      (
      EcU64 valueNanoseconds  ///< Value in nano-seconds.
      );

   /// Sleep a smart amount of time using the best of the above
   /// functions yielding best combination of process yield and 
   /// accuracy.
   virtual void sleepRealTime
      (
      EcTime   valueSeconds   ///< Value in seconds to sleep (floating point).
      );
   
   /// Get a monotonic number incrementing in nanoseconds.
   /// (Linux, MAC, Windows, not VxWorks), returns 0 on VxWorks.
   /// Not tied to calendar time.
   /// Output is a 64 bit float, EcTime = EcReal = EcF64 = double.
   /// 52 bit fraction = 45035996.27370496 seconds or 521 days  
   /// between loss of precision (time of things more than
   /// 521 days apart will be inexact in nanoseconds).
   virtual EcTime monotonicTimeNanoSeconds
      (
      );

   /// Get a monotonic number incrementing in nanoseconds.
   /// (Linux, MAC, Windows, not VxWorks), returns 0 on VxWorks.
   /// Not tied to calendar time.
   /// Output is a 64 bit float, EcTime = EcReal = EcF64 = double.
   /// 52 bit fraction = 45035996.27370496 seconds or 521 days  
   /// between loss of precision (time of things more than
   /// 521 days apart will be inexact in nanoseconds).
   static EcTime monotonicTimeNanoSecondsStatic
      (
      );

   /// Get the thread name / plugin name.
   virtual EcString threadName
      (
      ) const;

   /// Set the thread name / plugin name.
   virtual void setThreadName
      (
      const EcString &value
      );

protected:
   /// Generic method that gets called based on update rate.
   ///
   /// In non-realtime mode this function handles executing 
   /// processThread and controlling timing between execution.
   ///
   /// Requirements:
   /// 1) Monotonic - There isn't a monotonic clock tied to the timer, 
   ///    so it is possible the timer will fire early. It can also fire 
   ///    early from a user supplied signal, or from a OS signal  
   ///    interrupting the timer. To combat this, the timer always sleeps
   ///    relative to the current time. Expiry is adjusted if the clock
   ///    compared to the monotonic clock has changed.
   /// 2) Accuracy - Best possible accuracy of the OS without taking
   ///    any measures that might affect other threads or processes. 
   /// 3) Can be fired via an event if the timer is set to zero.
   void process
      (
      );

   /// Called by process() to do real time if m_IsRealTime is true.
   /// Otherwise process() handles timing itself.
   virtual void processRealTime
      (
      );

   /// Low-level implementation of thread start.  Sets one-time variables
   void startImplementation
      (
      );

   /// The process thread.
   virtual void processThread
      (
      ) = 0;

   EcString        m_ThreadName;             ///< Thread name.
   EcBoolean       m_Stopped;                ///< Status of thread
   EcBoolean       m_IsRealTime;             ///< Is this thread running real time.
   EcU32           m_UpdatePeriodInMs;       ///< Time between thread updates, 0 means event based.
   EcU32           m_UpdateFractionInNs;     ///< Update time if "real time" in usec, 0 means use Ms value.
   EcIODataBroker* m_pBroker;                ///< Pointer to a IO data broker
   boost::asio::io_service          m_IOService;   ///< IO service. Necessary for asynchronous timer
   boost::asio::deadline_timer      m_Timer;       ///< Timer for asynchronous events
   boost::scoped_ptr<boost::thread> m_ThreadPtr;   ///< Thread pointer.
   EcTime          m_NextRunTimeNs;          ///< Time of last run in nano seconds.
};

/// This class supports real time memory usage, and provides 
/// pre-allocated storage so it can be managed (prevent paging, enhance caching).
class EC_ACTIN_INTERFACE_DECL RealTimeMemoryUsage
{
public:
   /// Constructor.
   explicit RealTimeMemoryUsage
      (
      const EcU32 maxMemoryInGB     ///< Storage in Gigabytes.
      );

   /// Destructor.
   ~RealTimeMemoryUsage
      (
      );

private:
   boost::scoped_ptr<EcRealTimeMemoryUsageImpl>    m_ImplPtr;  ///< Memory pointer.
};

} // namespace Ec

#endif // ec_AsyncThread_H_
