#ifndef ecSystemShapeCollisionCache_H_
#define ecSystemShapeCollisionCache_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemShapeCollisionCache.h
/// @class EcSystemShapeCollisionCache
/// @brief Holds state information related to the proximity of
///        shapes in the system
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShapeCollisionData.h"
#include "ecProximityKey.h"

/** Holds a class to describe the system-level shape collision data
*/
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcSystemShapeCollisionCache
{
public:
   /// default constructor
   EcSystemShapeCollisionCache
      (
      );

   /// destructor
   ~EcSystemShapeCollisionCache
      (
      );

   /// get the datum for the keys provided
   const EcShapeCollisionData* getCollisionData
      (
      const EcShapeKey& shape1,
      const EcShapeKey& shape2
      ) const;

   /// get the proximity data (non-const) NOTE: Use with Caution!
   EcShapeCollisionData* getCollisionData
      (
      const EcShapeKey& shape1,
      const EcShapeKey& shape2
      );

   /// add the datum for the shape pair key provided
   EcBoolean addCollisionData
      (
      const EcShapeKey& shape1,
      const EcShapeKey& shape2,
      const EcShapeCollisionData& datum
      );

   /// delete the datum for the shape pair key provided
   EcBoolean deleteCollisionData
      (
      const EcShapeKey& shape1,
      const EcShapeKey& shape2
      );

   /// set the state update time
   void setUpdateTime
      (
      const EcU64& uTime
      );

   /// return the state update time
   const EcU64& updateTime
      (
      )const;

   /// check if the data for a shape combination is valid
   /// proximity data is invalidated whenever the state of the system
   /// changes
   EcBoolean isValid
      (
      const EcShapeCollisionData* data
      ) const;

   /// for the data in the datum to be set to valid
   /// this is used when non-const modification of the
   /// data is required.  The onus is on the caller to set this
   void setValid
      (
      EcShapeCollisionData* data
      );

   /// invalidates the data in the cache by incrementing the freshness
   /// counter.
   void invalidateAll
      (
      );

   /// number of active collisions
   EcU32 numCollisions
      (
      ) const;

   /// reset nextCollisionData to the beginning of the active collision list. Must be called before the first call to nextCollisionData()
   void resetNextCollisionData
      (
      );

   /// get the next collision data. Used to iterate over all the active collisions. Returns null at the end.
   EcShapeCollisionData* nextCollisionData
      (
      );

   /// caler all the collision cache data
   void clear
      (
      );

protected:
   /// grow the vector
   void grow();

   /// map from EcShapeProximityKey to EcU32
   typedef std::map<EcShapeProximityKey, EcU32> EcShapeProximityKeyIndexMap;
   /// key index map
   mutable EcShapeProximityKeyIndexMap          m_KeyIndexMap;
   /// available indices
   mutable std::list<EcU32>                     m_AvailableIndices;
   /// collision data cache
   mutable std::vector<EcShapeCollisionData>    m_vCollisionDataCache;
   /// iterator of next collision data
   EcShapeProximityKeyIndexMap::iterator        m_NextCollisionDataIter;

   /// the timer used for determining data freshness
   mutable EcU64 m_CurrentUpdateTime;
};

#endif // ecSystemShapeCollisionCache_H_
