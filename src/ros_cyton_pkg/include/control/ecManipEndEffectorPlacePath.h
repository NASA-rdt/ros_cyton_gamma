#ifndef ecManipEndEffectorPlacePath_H_
#define ecManipEndEffectorPlacePath_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipEndEffectorPlacePath.h
/// @class EcManipulatorEndEffectorPlacementPath
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
class EC_ACTIN_CONTROL_DECL EcManipulatorEndEffectorPlacementPath : public EcXmlCompoundType
{
public:
   /// Interpolation method
   enum EcInterpolationMethod
   {
      LINEAR_INTERPOLATION,         ///< linear (default)
      NEAREST_POINT,                ///< nearest point
   };

   /// default constructor
   EcManipulatorEndEffectorPlacementPath
      (
      );

   /// destructor
   virtual ~EcManipulatorEndEffectorPlacementPath
      (
      );

   /// copy constructor
   EcManipulatorEndEffectorPlacementPath
      (
      const EcManipulatorEndEffectorPlacementPath& orig
      );

   /// assignment operator
   EcManipulatorEndEffectorPlacementPath& operator=
      (
      const EcManipulatorEndEffectorPlacementPath& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorEndEffectorPlacementPath& orig
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
       \param time time stamp
       \param placement next end effector placement
   */
   virtual void add
      (
      const EcReal time,
      const EcManipulatorEndEffectorPlacement& placement
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
   virtual const EcXmlRealVector& timeVec
      (
      ) const;

   /// set time vector
   virtual void setTimeVec
      (
      const EcXmlRealVector& value
      );

   /// get the placement vector
   virtual const EcManipulatorEndEffectorPlacementVector& placementVec
      (
      ) const;

   /// set the placement vector
   virtual void setPlacementVec
      (
      const EcManipulatorEndEffectorPlacementVector& value
      );

   /// get the frames at a given time as a linear combination of the frames
   /// in the data
   /**
       \param time input time for retrieving placement
       \param placement manipulator end effector placement
       \param iMethod interpolation method (only linear)
       \retval error status
   */
   virtual EcBoolean getPlacement
      (
      EcReal time,
      EcManipulatorEndEffectorPlacement& placement,
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

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

protected:
   /// the EE placement path
   EcManipulatorEndEffectorPlacementVector m_PlacementVec;

   /// time stamp for each set of data
   EcXmlRealVector               m_TimeVec;

   /// the container for unitary map used for interpolation
   EcUnitaryMapContainer         m_UnitaryMapContainer;

   /// non-XML data
   /// the last saved or played time, used for record or play back
   mutable EcInt32     m_LastTimeIndex;

   /// minimum time between sample:
   EcReal      m_MinTimeBetweenSample;
};

// typedef EcXmlVectorType<EcManipulatorEndEffectorPlacementPath> EcManipulatorEndEffectorPlacementPathVector;

#endif // ecManipEndEffectorPlacePath_H_
