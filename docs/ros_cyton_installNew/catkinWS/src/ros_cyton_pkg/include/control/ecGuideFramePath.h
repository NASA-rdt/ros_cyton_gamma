#ifndef ecGuideFramePath_H_
#define ecGuideFramePath_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGuideFramePath.h
/// @class EcGuideFramePath
/// @brief A series of time-parameterized sets of guide frames.
///        This represents the desired end-effector placements of
///        a single manipulator over time.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipEndEffectorPlace.h"

#include <function/ecUnitaryMapContainer.h>

/// A series of time-parameterized sets of guide frames.
/**    This represents the desired end-effector placements of
    a single manipulator over time.
*/
class EC_ACTIN_CONTROL_DECL EcGuideFramePath : public EcXmlCompoundType
{
public:
   /// Interpolation method
   enum EcInterpolationMethod
   {
      LINEAR_INTERPOLATION,         ///< linear (default)
      NEAREST_POINT,                ///< nearest point
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


   /// default constructor
   EcGuideFramePath
      (
      );

   /// destructor
   virtual ~EcGuideFramePath
      (
      );

   /// copy constructor
   EcGuideFramePath
      (
      const EcGuideFramePath& orig
      );

   /// assignment operator
   EcGuideFramePath& operator=
      (
      const EcGuideFramePath& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGuideFramePath& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \retval cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// reset the vectors to zero length and set the last time index to 0.
   virtual void reset
      (
      );

   /// add element to the back of the Guide Frame path vec
   /**
       \param manFrameVec next end effector placement
       \param time time stamp
   */
   virtual void add
      (
      const EcManipulatorEndEffectorPlacementVector& manFrameVec,
      const EcReal time
      );

   /// get minimum time between samples
   /**
       \retval sample size
   */
   virtual EcReal minTimeBetweenSample
      (
      );

   /// set minimum time between samples
   /**
       \param minTime sample size
   */
   virtual void setMinTimeBetweenSample
      (
      EcReal minTime
      );

   /// get time vector
   /**
       \retval time vector
   */
   virtual const EcXmlRealVector& timeVec
      (
      ) const;

   /// set time vector
   /**
       \param timeVec time vector
   */
   virtual void setTimeVec
      (
      const EcXmlRealVector& timeVec
      );

   /// get m_ManFrameVec2D
   /**
       \retval the state path container
   */
   virtual const EcManipulatorEndEffectorPlacementVectorVector& manFrameVec2D
      (
      ) const;

   /// set m_ManFrameVec2D
   /**
       \param manFrameVec2D the state path container
   */
   virtual void setManFrameVec2D
      (
      const EcManipulatorEndEffectorPlacementVectorVector& manFrameVec2D
      );

   /// get the frames at a given time as a linear combination of the frames
   /// in the data
   /**
       \param time input time for retrieving state
       \param manFrameVec manipulator end effector placements
       \param iMethod interpolation method (only linear)
       \retval error status
   */
   virtual EcBoolean getFrameVec
      (
      EcReal time,
      EcManipulatorEndEffectorPlacementVector& manFrameVec,
      EcInterpolationMethod iMethod=LINEAR_INTERPOLATION
      ) const;

   /// get the size of the data
   /**
       \retval state path container size
   */
   virtual EcU32 getSize
      (
      ) const;

   /// self test
   /**
       \retval self test results
   */

   virtual const EcToken& token
      (
      ) const;

   /// create a test object
   /**
       \retval test object
   */

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

protected:
   /// the state path container
   EcManipulatorEndEffectorPlacementVectorVector m_ManFrameVec2D;

   /// time stamp for each set of data
   EcXmlRealVector               m_TimeVec;

   /// the period during which the path is transitioned (interpolated) from the end to the beginning to repeat the path
   EcXmlReal                     m_TransitionPeriod;

   /// the container for unitary map used for interpolation
   EcUnitaryMapContainer         m_UnitaryMapContainer;

   /// non-XML data
   /// the last saved or played time, used for record or play back
   mutable EcInt32     m_LastTimeIndex;

   /// minimum time between sample:
   EcReal      m_MinTimeBetweenSample;

   /// the flag indicating whether to repeat the path
   EcBoolean   m_RepeatPath;

   mutable EcPlaybackStage      m_PlaybackStage;      ///< the current playback stage

   mutable EcBoolean            m_PlaybackCompleted;  ///< flag indicating whether playback has completed

};

// typedef EcXmlVectorType<EcGuideFramePath> EcGuideFramePathVector;

#endif // ecGuideFramePath_H_
