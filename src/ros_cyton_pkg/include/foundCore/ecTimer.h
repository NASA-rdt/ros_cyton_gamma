#ifndef ecTimer_H_
#define ecTimer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecTimer.h
/// @class EcTimer
/// @brief Provides wall clock timing functionality.
/// @todo This is a simple timer.  In the current
///       version of Boost (1.33.1), boost::timer is based on
///       processor time, rather than wall clock time.  In future
///       versions of Boost, it is expected that boost::timer will
///       be based on wall clock time.  This class will not be
///       necessary when that happens.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecConstants.h"

#define BOOST_DATE_TIME_NO_LIB

#if defined(WIN32)
#pragma warning(push)
#pragma warning(disable:4244)
#pragma warning(disable:4996)
#endif

#include <boost/date_time/posix_time/posix_time.hpp>

#if defined(WIN32)
#pragma warning(pop)
#endif

template <class ClockType>

class EC_STABLE_FOUNDCORE_DECL EcTimer
{
public:

   /// Get current time.
   static boost::posix_time::ptime time
      (
      )
   {
      return ClockType::local_time();
   }

   EcTimer
      (
      ) :
      m_StartTime(initialTime()),
      m_Elapsed(initialDuration())
   {
   }

   /// Test for equality.
   /// @param[in] org EcTimer object to test
   EcBoolean operator==
      (
      const EcTimer& org
      ) const
   {
      if (!((m_StartTime == org.m_StartTime) && (m_Elapsed == org.m_Elapsed)))
      {
         return EcFalse;
      }

      return EcTrue;
   }

   /// Start the timer. This is similar to the initial click on a stopwatch.
   /// Starting a running timer has no effect.
   void start
      (
      )
   {
      if (m_StartTime.is_not_a_date_time())
      {
         m_StartTime = time();
      }
   }

   /// Stop the current timer and then restart it from this point in time.
   void restart
      (
      )
   {
      reset();
      start();
   }

   /// Calculate the time that has elapsed since starting the timer. This
   /// resets the start time to now.
   /// @return Elapsed time as posix time.
   boost::posix_time::time_duration elapsed
      (
      ) const
   {
      if (m_StartTime != initialTime())
      {
         boost::posix_time::ptime current = time();
         m_Elapsed   += (current - m_StartTime);
         m_StartTime  = current;
      }

      return m_Elapsed;
   }

   /// performs the same process as elapsed(), but returns a value for the
   /// elapsed time in seconds. Also restarts the timer.
   EcReal elapsedInSeconds
      (
      ) const
   {
      elapsed();
      return static_cast<EcReal>(m_Elapsed.total_milliseconds()) / 1000.0;
   }

   /// Suspends the tracking of time. Elapsed time is frozen until resume
   /// is called.
   void pause
      (
      )
   {
      boost::posix_time::ptime current = time();
      m_Elapsed += (current - m_StartTime);
      // not_a_date_time signals a not-running state
      m_StartTime = initialTime();
   }

   /// Resumes the tracking of time. If tracking is not paused, this does nothing.
   void resume
      (
      )
   {
      if (m_StartTime.is_not_a_date_time())
      {
         m_StartTime = time();
      }
   }

   /// Sets all the values to a blank start.
   void reset
      (
      )
   {
      m_Elapsed = initialDuration();
      if (!m_StartTime.is_not_a_date_time())
      {
         m_StartTime = initialTime();
      }
   }

private:

   /// sets the initial time to an invalid time to aid in tracking methods.
   static boost::posix_time::ptime initialTime
      (
      )
   {
      return boost::posix_time::ptime(boost::posix_time::not_a_date_time);
   }

   /// sets the initial duration to zero
   static boost::posix_time::time_duration initialDuration
      (
      )
   {
      return boost::posix_time::time_duration(0, 0, 0);
   }

   mutable boost::posix_time::ptime         m_StartTime;
   mutable boost::posix_time::time_duration m_Elapsed;
};

/// EcMicroTimer is a subsecond accuracy clock (not literally microseconds on all OSs)
typedef EcTimer<boost::posix_time::microsec_clock> EcMicroTimer;

/// EcSecondTimer is a clock that provides accuracy to the one-second level.
typedef EcTimer<boost::posix_time::second_clock>   EcSecondTimer;

#endif // ecTimer_H_
