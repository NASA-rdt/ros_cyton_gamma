#ifndef ecElapsedTime_H_
#define ecElapsedTime_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecElapsedTime.h
/// @class EcElapsedTime
/// @brief implementation of the EcElapsedTime class.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecTimer.h"

/// General class for capturing elapsed time
class EC_STABLE_FOUNDCORE_DECL EcElapsedTime
{
public:
   /// constructor
   EcElapsedTime
      (
      );

   /// destructor
   virtual ~EcElapsedTime
      (
      );

   /// copy constructor
   EcElapsedTime
      (
      const EcElapsedTime& orig
      );

   /// assign
   EcElapsedTime& operator=
      (
      const EcElapsedTime& orig
      );

   /// equal
   EcBoolean operator==
      (
      const EcElapsedTime& orig
      ) const;

   /// set the start_time to current_system_time
   virtual void reset
      (
      );

   /// return time since Reset, in seconds
   virtual EcReal elapsedTime
      (
      ) const;

   /// set the pause time to current_system_time - start_time;
   virtual void pause
      (
      );

   /// set the start_time to current_system_time
   virtual void restart
      (
      );

   /// alternating 0, 1 at a fixed frequency based on the input timesPerSec
   virtual EcBoolean trigger
      (
      const EcInt32 timesPerSec
      ) const;

   /// alternating 0, 1 at a fixed frequency based on the input
   virtual EcBoolean triggerInMs
      (
      const EcU32 intervalRateInMs
      ) const;

   /// control the delay between trigger based on the input frameRate
   virtual EcBoolean triggerAtFrameRate
      (
      const EcInt32 frameRate
      );

   /// See if timer is running
   virtual EcBoolean isRunning
      (
      ) const;

   /// if the timer started
   virtual EcBoolean isStarted
      (
      ) const;

   /// Trigger on a transition.  This differs from the trigger method
   /// in that it returns EcTrue on a transition whereas trigger
   /// alternates between EcTrue/EcFalse on the period determined
   /// by timesPerSec.  Think of this method as the delta function to
   /// triggers step function.
   virtual EcBoolean triggerOnTransition
   (
   const EcInt32 timesPerSec     // trigger frequency
   ) const;

   /// @copydoc triggerOnTransition(const EcInt32) const
   /// intervalRateInMs Interval rate in MS between trigger calls
   virtual EcBoolean triggerOnTransitionInMs
   (
   const EcU32 intervalRateInMs
   ) const;

protected:
   /// the timer
   EcMicroTimer m_Timer;

   /// the time pause started
   EcReal m_PauseStart;

   /// the last time triggered
   EcReal m_LastTrigger;

   /// Is the timer paused or not (not used for the Trigger funcs)
   EcBoolean m_IsPaused;

   /// if the timer started
   EcBoolean m_IsStarted;

   // mutable data
   /// The Boolean return value of the last call to trigger() or triggerInMs()
   mutable EcBoolean m_LastTriggerResult;
};

#endif // ecElapsedTime_H_
