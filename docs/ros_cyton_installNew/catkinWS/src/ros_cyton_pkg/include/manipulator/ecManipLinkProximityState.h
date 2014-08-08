#ifndef ecManipLinkProximityState_H_
#define ecManipLinkProximityState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipLinkProximityState.h
/// @class EcManipulatorLinkProximityState
/// @brief Holds state information related to the proximity of
///        links in a manipulator to those in others
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkProximityData.h"
#include <manipulator/ecManipActPosState.h>
#include <manipulator/ecSystemActiveBoundingBoxState.h>
#include <shapeProximity/ecProximityKey.h>

#include <boost/unordered_map.hpp>

// forward declarations

/** Holds a class to describe the system level proximity data
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorLinkProximityState
{
public:

   /// default constructor
   EcManipulatorLinkProximityState
      (
      );

   /// destructor
   virtual ~EcManipulatorLinkProximityState
      (
      );

   /// copy constructor
   EcManipulatorLinkProximityState
      (
      const EcManipulatorLinkProximityState& orig
      );

   /// assignment operator
   EcManipulatorLinkProximityState& operator=
      (
      const EcManipulatorLinkProximityState& orig
      );

   /// gets the system-level active AABB state  - const version
   virtual const EcSystemActiveBoundingBoxState& systemActiveBoundingBoxState
      (
      ) const;

   /// gets the system-level active AABB state - nonconst version
   virtual EcSystemActiveBoundingBoxState&
      systemActiveBoundingBoxState
      (
      );

   /// sets the system-level active AABB state
   virtual void setSystemActiveBoundingBoxState
      (
      const EcSystemActiveBoundingBoxState& value
      );

   /// get the link proximity data for the keys provided
   virtual const EcLinkProximityData* getData
      (
      const EcLinkKey& linkKey1,
      const EcLinkKey& linkKey2
      ) const;

   /// get the link proximity data for the keys provided
   virtual EcLinkProximityData* getData
      (
      const EcLinkKey& linkKey1,
      const EcLinkKey& linkKey2
      );

   /// set the distance for the shape pair key provided, this does not
   /// update the *valid* flag, only the *distance valid* flag
   virtual EcBoolean setDistance
      (
      const EcLinkKey& linkKey1,
      const EcLinkKey& linkKey2,
      EcReal dist
      );

   /// get the distance for the keys provided
   virtual EcReal getDistance
      (
      const EcLinkKey& linkKey1,
      const EcLinkKey& linkKey2
      ) const;

   /// invalidates the data in the cache by incrementing the freshness
   /// counter.
   virtual void invalidateAll
      (
      );

   /// invalidates the data in the cache by incrementing the freshness
   /// counter.
   virtual void invalidate
      (
      EcU32 manipIndex
      );

   /// check if the data for a shape combination is valid
   /// proximity data is invalidated whenever the state of the system
   /// changes
   virtual EcBoolean isValid
      (
      const EcLinkKey& linkKey1,
      const EcLinkKey& linkKey2
      ) const;

   /// for the data in the datum to be set to valid
   /// this is used when non-const modification of the
   /// data is required.  The onus is on the caller to set this
   virtual void setValid
      (
      const EcLinkKey& linkKey1,
      const EcLinkKey& linkKey2
      );

   /// initializes this state
   virtual EcBoolean initialize
      (
      EcU32 manipIndex,
      const EcManipulatorSystem& system
      );

   /// set the database initialization flag
   virtual void setIsInitialized
      (
      const EcBoolean& init
      );

   /// get the database initialization flag
   virtual EcBoolean isInitialized
      (
      )const;

protected:

   /// the link proximity data
   mutable boost::unordered_map<EcLinkProximityKey, EcLinkProximityData>   m_LinkProximityData;

   /// the bounding box state
   mutable EcSystemActiveBoundingBoxState    m_BoundingBoxState;

   /// the timer used for determining data freshness
   mutable EcU32Vector  m_vCurrentUpdateTimes;

   /// the flag indicating whether the state has been initialized
   EcBoolean m_IsInitialized;
};

/// type definition of vector of EcManipulatorLinkProximityState
typedef std::vector< EcManipulatorLinkProximityState >   EcManipulatorLinkProximityStateVector;

#endif // ecManipLinkProximityState_H_
