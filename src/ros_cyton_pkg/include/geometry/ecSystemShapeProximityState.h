#ifndef ecSystemShapeProximityState_H_
#define ecSystemShapeProximityState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemShapeProximityState.h
/// @class EcSystemShapeProximityState
/// @brief Holds state information related to the proximity of
///        shapes in the system
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShapeProximityData.h"
#include <foundCore/ecVector.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include "ecBaseShapeDataCache.h"

/** Holds a class to describe the system level proximity data
*/
class EC_FOUNDATION_GEOMETRY_DECL EcSystemShapeProximityState : public EcBaseShapeDataCache<EcShapeProximityData>
{
public:
   /// default constructor
   EcSystemShapeProximityState
      (
      );

   /// destructor
   virtual ~EcSystemShapeProximityState
      (
      );

   /// copy constructor
   EcSystemShapeProximityState
      (
      const EcSystemShapeProximityState& orig
      );

   /// assignment operator
   EcSystemShapeProximityState& operator=
      (
      const EcSystemShapeProximityState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemShapeProximityState& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
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

   /// reads this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// writes this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// gets a null link
   static EcSystemShapeProximityState nullObject
      (
      );

   /// This method sets the data in the data structure,
   /// allocating as required.
   virtual EcBoolean allocateAndSetProximityVector
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes,
      const EcVector& proxVec
      ) ;

   /// This method gets the data in the data structure,
   /// allocating as required. If the data is unavailable, the space
   /// is allocated and a default datum is returned
   virtual const EcVector& allocateAndGetProximityVector
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes
      ) const;

   /// set the datum for the shape pair key provided
   virtual EcBoolean setProximityVector
      (
      const EcShapeStateCacheKey& shapeIndex1,
      const EcShapeStateCacheKey& shapeIndex2,
      const EcVector& proxVec
      ) ;

   /// get the datum for the keys provided
   virtual const EcVector& getProximityVector
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      ) const;


   /// set the distance for the shape pair key provided, this does not
   /// update the *valid* flag, only the *distance valid* flag
   virtual EcBoolean setDistance
      (
      const EcShapeStateCacheKey& shapeIndex1,
      const EcShapeStateCacheKey& shapeIndex2,
      const EcReal& dist
      ) ;

   /// get the distance for the keys provided
   virtual const EcReal& getDistance
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      ) const;

   /// This method sets the distance in the data structure,
   /// allocating as required.
   virtual EcBoolean allocateAndSetProximityDistance
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes,
      const EcReal& dist
      ) ;

   /// This method gets the distance in the data structure,
   /// allocating as required. If the data is unavailable, the space
   /// is allocated and a default datum is returned
   virtual const EcReal& allocateAndGetProximityDistance
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes
      ) const;

   /// invalidates the data in the cache by incrementing the freshness
   /// counter.
   virtual void invalidateAll
      (
      );

   /// check if the data for a shape combination is valid
   /// proximity data is invalidated whenever the state of the system
   /// changes
   virtual EcBoolean isValid
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      )const;

   /// check if the distance for a shape combination is valid
   /// proximity data is invalidated whenever the state of the system
   /// changes
   virtual EcBoolean isDistanceValid
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      )const;

   /// set the state update time
   virtual void setUpdateTime
      (
      const EcU64& uTime
      );

   /// return the state update time
   virtual const EcU64& updateTime
      (
      )const;

   /// for the data in the datum to be set to valid
   /// this is used when non-const modification of the
   /// data is required.  The onus is on the caller to set this
   virtual void setValid
      (
       const EcShapeStateCacheKey& shape1,
       const EcShapeStateCacheKey& shape2
      );

   /// This method sets the data in the data structure,
   /// allocating as required.
   virtual EcBoolean allocateAndSetProximityData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes,
      const EcShapeProximityData& datum
      );

   /// This method gets the data in the data structure,
   /// allocating as required. If the data is unavailable, the space
   /// is allocated and a default datum is returned
   virtual const EcShapeProximityData* allocateAndGetProximityData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes
      ) const;

   /// set the datum for the shape pair key provided
   virtual EcBoolean setProximityData
      (
      const EcShapeStateCacheKey& shapeIndex1,
      const EcShapeStateCacheKey& shapeIndex2,
      const EcShapeProximityData& datum
      );

   /// get the datum for the keys provided
   virtual const EcShapeProximityData* getProximityData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      ) const;

   /// get the proximity data (non-const) NOTE: Use with Caution!
   virtual EcShapeProximityData* getProximityData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      ) ;

   /// insert penetration point to buffer of shape 1
   virtual EcBoolean insertPenetrationPointShape1Primary
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcVector& point
      );

   /// insert penetration point to buffer of shape 2
   virtual EcBoolean insertPenetrationPointShape2Primary
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcVector& point
      );

   /// set the friction mode
   virtual EcBoolean setFrictionMode
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcShapeProximityData::EcFrictionMode& mode
      );

   /// get the collision occurred flag
   virtual EcBoolean collisionOccured
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      )const;

   /// set the collision occurred flag
   virtual void setCollisionOccured
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcBoolean flag
      );

   /// reset the penetration point buffers
   virtual EcBoolean resetPenetrationPointBuffers
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
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


   /// resize the database to the number of shapes in each link of each manipulator in the system
   virtual EcBoolean resizeDatabaseToSystem
      (
      const EcInt32Vector3D& systemNumShapes
      );

   /// set the witness points for the shape pair key provided
   virtual EcBoolean setWitnessPoints
      (
      const EcShapeStateCacheKey& shapeIndex1,
      const EcShapeStateCacheKey& shapeIndex2,
      const EcVector& witnessPointA,
      const EcVector& witnessPointB
      );

   /// get the witness points for the keys provided
   virtual EcBoolean getWitnessPoints
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      EcVector& witnessPointA,
      EcVector& witnessPointB
      ) const;

   /// check if the witness points for a shape combination are valid
   /// proximity data is invalidated whenever the state of the system
   /// changes
   virtual EcBoolean areWitnessPointsValid
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      ) const;

   virtual const EcToken& token
      (
      ) const;

protected:
   /// mutable data for speed
   mutable EcShapeProximityData m_ShapeData;

   /// the timer used for determining data freshness
   mutable EcU64 m_CurrentUpdateTime;

   /// const data

   /// the null shape data member
   static const EcShapeProximityData m_theNullShapeData;

   /// is initialized
   EcBoolean m_IsInitialized;
};

#endif // ecSystemShapeProximityState_H_
