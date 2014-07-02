#ifndef ecStatePath_H_
#define ecStatePath_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecStatePath.h
/// @class EcStatePath
/// @brief A time stepped sequence of manipulator states.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <function/ecUnitaryMapContainer.h>
#include <manipulator/ecManipSysState.h>

/** A time stepped sequence of manipulator states.
*/
class EC_ACTIN_CONTROL_DECL EcStatePath : public EcXmlCompoundType
{
public:
   /// Interpolation method
   enum EcInterpolationMethod
   {
      LINEAR_INTERPOLATION,         ///< linear (default)
      SPLINE                        ///< spline (not available)
   };

   /// playback Stage
   enum EcPlaybackStage
   {
      BEFORE_PLAYBACK,                 ///< before the animation start
      DURING_PLAYBACK,                 ///< during animation
      AFTER_PLAYBACK,                  ///< out of time frame
      NONE_PLAYBACK                    ///< not in playback mode
   };

   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcStatePath);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// reset the container to empty and the time index to 0
   virtual void reset
      (
      );

   /// add element to the back of the state path vector
   /**
       \param manipSysState next state
   */
   virtual void add
      (
      const EcManipulatorSystemState& manipSysState
      );

   /// get the min time between sample member variable
   /**
       \retval sample size
   */
   virtual EcReal minTimeBetweenSample
      (
      ) const;

   /// get the state path container
   virtual const EcManipulatorSystemStateVector& manipSysStateVec
      (
      )const;

   /// Set the min time between sample member variable
   /**
       \param minTime sample size
   */
   virtual void setMinTimeBetweenSample
      (
      const EcReal minTime
      );

   /// get m_ManipSysStateVec
   virtual const EcManipulatorSystemStateVector& manipSystemStateVector
      (
      ) const;

   /// given a time, calculate the state from the states in the container
   /**
       \param time input time for retrieving state
       \param state interpolated output state
       \param iMethod interpolation method (only linear)
       \retval error status
   */
   virtual EcBoolean getState
      (
      EcReal time,
      EcManipulatorSystemState& state,
      EcInterpolationMethod iMethod=LINEAR_INTERPOLATION
      ) const;

   /// get the size of the state container
   /**
       \retval size
   */
   virtual EcU32 getSize
      (
      ) const;

   /// get last time index
   virtual EcInt32 lastTimeIndex
      (
      ) const;

   /// clear the last time index (i.e. set it back to 0)
   virtual void clearLastTimeIndex
      (
      );

   /// get the transition period
   virtual EcReal transitionPeriod
      (
      ) const;

   /// set the transition period
   virtual void setTransitionPeriod
      (
      EcReal value
      );

   /// return whether or not to repeat the path when it's finished
   virtual EcBoolean repeatPath
      (
      ) const;

   /// set whether or not to repeat the path when it's finished
   virtual void setRepeatPath
      (
      EcBoolean value
      );

   /// get the unitary map container used for interpolation during the transition period
   virtual const EcUnitaryMapContainer& unitaryMapContainer
      (
      ) const;

   /// set the unitary map container used for interpolation during the transition period
   virtual void setUnitaryMapContainer
      (
      const EcUnitaryMapContainer& value
      );

   /// return whether or not playback is completed, this is set only once after
   /// the stage switch from during to after.
   virtual EcBoolean playbackCompleted
      (
      ) const;

   /// Attempts to remove redundant or extra elements.  When duplicates are
   /// found within the middle, it will keep the beginning and ending elements
   /// and remove the ones in between, preserving the interpolation behavior.
   /// It will also remove any redundant elements from the end, effectively
   /// shortening the end time.  startAtZero will also remove any time offset
   /// from the path file so that it starts at time = 0.0.
   void trim
      (
      const EcBoolean startAtZero = EcTrue ///< [in] Whether to adjust start time
      );

protected:
   /// compute velocity state by finite differencing two position states and a delta time
   virtual void computeVelocityState
      (
      EcReal deltaT,
      const EcPositionState& posState1,
      const EcPositionState& posState2,
      EcVelocityState& velState
      ) const;

protected:
   /// the state path container
   EcManipulatorSystemStateVector m_ManipSysStateVec;

   /// the period during which the path is transitioned (interpolated) from the end to the beginning to repeat the path
   EcXmlReal                      m_TransitionPeriod;

   /// the container for unitary map used for interpolation
   EcUnitaryMapContainer         m_UnitaryMapContainer;

   /// non-XML data
   /// the last saved or played time, used for record or play back
   mutable EcU32       m_LastTimeIndex;

   /// minimum time between sample:
   EcReal      m_MinTimeBetweenSample;

   /// the flag indicating whether to repeat the path
   EcBoolean   m_RepeatPath;

   mutable EcPlaybackStage      m_PlaybackStage;      ///< the current playback stage

   mutable EcBoolean            m_PlaybackCompleted;  ///< flag indicating whether playback has completed
};

#endif // ecStatePath_H_
