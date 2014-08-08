#ifndef ecWait_H_
#define ecWait_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecWait.h
/// @class EcWait
/// @brief Collection of waiting methods
/// @details A collection of methods for dealing with waiting and alarms.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecMacros.h"

#include <math.h>
#include <boost/thread/thread.hpp>

#include <boost/date_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>


class EC_STABLE_FOUNDCORE_DECL EcWait
{
   public:
   /// curTime
   /*
   Return the current time in a boost::xtime structure
   */
   static inline const boost::posix_time::ptime curTime
      (
      )
   {
      return boost::posix_time::microsec_clock::local_time();
   }

   /// isTimeElapsed
   /**
   Return true of the alarm time is passed, false otherwise

   @param[in] alarmTime an absolute time (in UTC) for the alarm
   @return EcBoolean return true if current time is newer than alarm time
   */
   static inline const EcBoolean isTimeElapsed
      (
      const boost::posix_time::ptime alarmTime
      )
   {
      return ( boost::posix_time::microsec_clock::local_time() >= alarmTime);
   }

   /// addMilliseconds
   /**
   Add a time offset to some absolutte UTC time, creating a new absolute time in the future.
   Handle overflow from milliseconds to seconds.
   Negative offset is treated as an infinite wait, implemented using 24 hour heuristic.

   @param[in,out] _theTime      the boost time structure holding some absolute time (in UTC) as input, new future time on output
   @param[in]     _milliSeconds the number of milliseconds into the future for the alarm
   */
   static inline void addMilliseconds
      (
      boost::posix_time::ptime& _theTime,
      const EcInt64 _milliSeconds
      )
   {
      _theTime += boost::posix_time::milliseconds(_milliSeconds);
   }

   /// calcAlarmTime
   /**
   Create an alarm by getting the current time and adding an offset

   @param[out] _theTime      a time structure that will be initialized with the alarm time
   @param[in]  _milliSeconds the number of milliseconds into the future for the alarm
   */
   static inline void calcAlarmTime
      (
      boost::posix_time::ptime& _theTime,
      EcInt64 _milliSeconds
      )
   {
      _theTime = boost::posix_time::microsec_clock::local_time() + boost::posix_time::milliseconds(_milliSeconds);
   }

   /// ecSleep
   /**
   Pause the current thread of execution for the specified duration.
   If duration is zero, then attempt to yield the thread's timeslice back to the OS

   @param[in] _milliSeconds milliseconds to sleep
   */
   static inline void ecSleep
      (
      const EcInt64 _milliSeconds = 0
      )
   {
      if ( 0 == _milliSeconds )
      {
         /// for a zero wait, give the timeslice back to the os
         boost::thread::yield();
      }
      else
      {
         boost::this_thread::sleep(boost::posix_time::milliseconds(_milliSeconds));
      }
   }

   /// subTime
   /*
   Produce the result t0 - t1

   @param[in] _t0 first time
   @param[in] _t1 second time
   @return boost:xtime the result _t0 - _t1
   */
   static inline const boost::posix_time::ptime subTime
      (
      const boost::posix_time::ptime& _t0,
      const boost::posix_time::ptime& _t1
      )
   {
      return _t0 - (_t0 - _t1);
   }

   /// toMilliseconds
   /*
   Convert from boost::xtime to milliseconds since the epoch

   @param[in] _t0 time to be converted
   @return EcInt64 the result
   */
   static inline const EcInt64 toMilliseconds
      (
      const boost::posix_time::ptime& _t0
      )
   {
      static const boost::posix_time::ptime _epoch(boost::gregorian::date(1970,1,1));
      return EcInt64( ( _t0 - _epoch ).total_milliseconds() );
   }


   /// waitHertz
   /*
   Sleep the amount of time to meet the specified Hz.

   @param[in] _t0       the initial timestamp
   @param[in] _t1       the final timestamp
   @param[in] _Hz       the desired cycle rate
   @return EcBoolean    true if sleep occurred, false otherwise
   */
   static EcBoolean waitHertz
      (
      const boost::posix_time::ptime& _t0,
      const boost::posix_time::ptime& _t1,
      const EcF64 _Hz
      )
   {
      // calculate how many milliseconds to sleep to meet the specified cycles per second
      if ( _Hz > 0.0 )
      {
         const EcInt64 milliSecondsToSleep=static_cast<EcInt64>( (EcF64(1000.0)/_Hz ) - EcF64( (_t1 - _t0).total_milliseconds()));
         if ( milliSecondsToSleep > 0 )
         {
            //EcINFO("Will sleep for %d ms\n",milliSecondsToSleep);
            ecSleep(milliSecondsToSleep);
            return EcTrue;
         }
      }
      return EcFalse;
   }
};

#endif // ecWait_H_
