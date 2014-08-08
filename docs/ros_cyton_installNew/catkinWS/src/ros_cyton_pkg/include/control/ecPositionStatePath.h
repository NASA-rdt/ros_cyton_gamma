#ifndef ecPositionStatePath_H_
#define ecPositionStatePath_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionStatePath.h
/// @class EcPositionStatePath
/// @brief A time stepped sequence of position states.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <function/ecUnitaryMapContainer.h>
#include <manipulator/ecPositionState.h>

// forward declarations
class EcVelocityState;

/** A time stepped sequence of position states of a manipulator
*/
class EC_ACTIN_CONTROL_DECL EcPositionStatePath : public EcXmlCompoundType
{
public:
   /// Interpolation method
   enum EcInterpolationMethod
   {
      LINEAR_INTERPOLATION,         ///< linear (default)
      NEAREST_POINT,                ///< nearest point
   };

   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcPositionStatePath);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// reset the container to empty and the time index to 0
   virtual void reset
      (
      );

   /// add element to the back of the state path vector
   virtual void add
      (
      const EcReal time,
      const EcPositionState& posState
      );

   /// get the min time between sample member variable
   virtual EcReal minTimeBetweenSample
      (
      ) const;

   /// get time vector
   virtual const EcXmlRealVector& timeVec
      (
      ) const;

   /// set time vector
   virtual void setTimeVec
      (
      const EcXmlRealVector& value
      );

   /// get the position state vector
   virtual const EcPositionStateVector& positionStateVec
      (
      )const;

   /// set the position state vector
   virtual void setPositionStateVec
      (
      const EcPositionStateVector& value
      );

   /// Set the min time between sample member variable
   /**
       \param minTime sample size
   */
   virtual void setMinTimeBetweenSample
      (
      const EcReal minTime
      );

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
      EcPositionState& state,
      EcInterpolationMethod iMethod=LINEAR_INTERPOLATION
      ) const;

   /// get last time index
   virtual EcInt32 lastTimeIndex
      (
      ) const;

   /// clear the last time index (i.e. set it back to 0)
   virtual void clearLastTimeIndex
      (
      ) const;

   /// get the unitary map container used for interpolation during the transition period
   virtual const EcUnitaryMapContainer& unitaryMapContainer
      (
      ) const;

   /// set the unitary map container used for interpolation during the transition period
   virtual void setUnitaryMapContainer
      (
      const EcUnitaryMapContainer& value
      );

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
   /// the state path container
   EcPositionStateVector   m_PositionStateVec;

   /// time stamp for each set of data
   EcXmlRealVector               m_TimeVec;

   /// the container for unitary map used for interpolation
   EcUnitaryMapContainer         m_UnitaryMapContainer;

   /// non-XML data
   /// the last saved or played time, used for record or play back
   mutable EcU32       m_LastTimeIndex;

   /// minimum time between sample:
   EcReal      m_MinTimeBetweenSample;
};

#endif // ecPositionStatePath_H_
