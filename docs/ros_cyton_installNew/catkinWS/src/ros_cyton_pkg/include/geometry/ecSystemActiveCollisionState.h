#ifndef ecSystemActiveCollisionState_H_
#define ecSystemActiveCollisionState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemActiveCollisionState.h
/// @class EcSystemActiveCollisionState
/// @brief Class for holding the system wide active bounding box
///        state.  This maintains a sorted list of bounding boxes
///        for each link and base in the system that can be used
///        for fast intersection testing.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShapeCollisionEvent.h"
#include <xml/ecXmlCompType.h>

class EcShapeStateCacheKey;

/** Holds the system active collision state
*/
class EC_FOUNDATION_GEOMETRY_DECL EcSystemActiveCollisionState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSystemActiveCollisionState
      (
      );

   /// destructor
   virtual ~EcSystemActiveCollisionState
      (
      );

   /// copy constructor
   EcSystemActiveCollisionState
      (
      const EcSystemActiveCollisionState& orig
      );

   /// assignment operator
   EcSystemActiveCollisionState& operator=
      (
      const EcSystemActiveCollisionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemActiveCollisionState& orig
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

   /// get the active collision state vector
   virtual const EcActiveCollisionStateArray& activeCollisionStateArray
      (
      )const;

   /// set the active collision state vector
   virtual void setActiveCollisionStateArray
      (
      const EcActiveCollisionStateArray& colState
      );

   /// add a collision
   virtual EcBoolean insertCollision
      (
      const EcU32& manipID,
      const EcU32& linkID,
      const EcU32& shapeID,
      const EcShapeCollisionEvent& collision
      );

   /// get collisions for a given link
   virtual const EcActiveCollisionStateVector& collisions
      (
      const EcU32& manipID,
      const EcU32& linkID,
      const EcU32& shapeID
      )const;

   /// get collisions for a given link
   virtual const EcActiveCollisionStateVector& collisions
      (
      const EcShapeStateCacheKey& key
      )const;

   /// invalidates all of the state
   virtual void invalidateAll
      (
      );

   /// set that a manipulator collision occured
   virtual void setCollisionDetected
      (
      const EcU32& manipID
      );

   /// check if a manipulator collision occured
   virtual EcBoolean collisionDetected
      (
      const EcU32 manipID
      )const;

   /// check if a shape collision occured
   virtual EcBoolean shapeCollisionDetected
      (
      const EcShapeStateCacheKey& key
      )const;

   /// returns if the cache has been initialized
   virtual EcBoolean isInitialized
      (
      )const;

   /// sets if the cache has been initialized
   virtual void setIsInitialized
      (
      const EcBoolean& init
      );

   /// set the validity flag
   virtual const EcBoolean& isValid
      (
      )const;

   /// set the validity flag
   virtual void setIsValid
      (
      const EcBoolean isValid
      );

   /// resize the collision state cache to be compatible with the system
   virtual void resizeToSystem
      (
      const EcInt32Vector3D& systemNumShapes
      );

   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcSystemActiveCollisionState nullObject
      (
      );

protected:
   /// the collision data cache
   EcActiveCollisionStateArray m_ActiveCollisionDataCache;

   /// array of manipulator collision
   EcBooleanVector m_ManipulatorCollisionArray;

   /// flag indicating if the database has been initialized
   /// the cache should be reinitialized whenever the system is changed
   EcBoolean m_IsInitialized;

   /// flag indicating if the collision data is valid
   EcBoolean m_IsValid;

   /// the null collision data vector
   static const EcActiveCollisionStateVector m_theNullCollisionDataVector;
};

#endif // ecSystemActiveCollisionState_H_
