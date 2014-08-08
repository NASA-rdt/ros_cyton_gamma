#ifndef ecTimerUtil_H_
#define ecTimerUtil_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecTimerUtil.h
/// @class EcTimerUtil
/// @brief A utility class for timing
/// @details Holds a utility class for performing basic timing operations
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecElapsedTime.h"

class EC_STABLE_FOUNDCORE_DECL EcTimerUtil
{
public:
   /// default constructor
   EcTimerUtil
      (
      );

   /// constructor with max timers
   explicit EcTimerUtil
      (
      EcU32 maxTimers
      );

   /// destructor
   virtual ~EcTimerUtil
      (
      );

   /// copy constructor
   EcTimerUtil
      (
      const EcTimerUtil& orig
      );

   /// assignment operator
   EcTimerUtil& operator=
      (
      const EcTimerUtil& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTimerUtil& orig
      ) const;

   /// start a timer
   virtual void tic
      (
      EcString timer
      );

   /// stop a timer
   virtual EcBoolean toc
      (
      EcString timer
      );

   /// create a new timer
   virtual EcBoolean createTimer
      (
      const EcString& timerName
      );

   /// report timing results to stdout
   virtual void report
      (
      ) const;

   /// generates timing results and write it to a file
   /// @param[in] fname the name of the file to hold the report
   virtual void report
      (
      const EcString& fname
      ) const;

   /// returns the average time for the timer
   virtual EcReal averageTime
      (
      const EcString& timer
      ) const;

   /// returns the number of samples for the timer
   virtual EcU32 numSamples
      (
      const EcString& timer
      ) const;

protected:
   /// symbol map
   EcStringU32Map m_TimerLabel;

   /// list of timers
   std::vector<EcElapsedTime> m_vTimerList;

   /// list of accumulated time
   EcRealVector m_vAverageTime;

   /// list of max time between tic/toc for each timer
   EcRealVector m_vMaxTime;

   /// list of number of samples
   EcU32Vector m_vNumberOfSamples;

   /// the number of timers in the tool
   EcU32 m_NumTimers;

   /// the maximum number of timers allowed
   EcU32 m_MaxNumTimers;
};

#endif // ecTimerUtil_H_
