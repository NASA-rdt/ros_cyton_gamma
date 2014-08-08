#ifndef ecSystemActiveState_H_
#define ecSystemActiveState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemActiveState.h
/// @class EcSystemActiveState
/// @brief This class is a container for all active states in a system.
///        These are used for dynamic programming in manipulator control and simulation.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipActiveState.h"

#include "ecManipExternalForce.h"
#include "ecSystemActiveBoundingBoxState.h"
#include "ecManipLinkProximityState.h"
#include <geometry/ecShapeStateCacheKey.h>
#include <shapeProximity/ecSystemShapeCollisionCache.h>
#include <xml/ecXmlCompType.h>

class EcManipulatorSystemState;

/** This class is a container for all active states in a system.
These are used for dynamic programming in manipulator control and simulation.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcSystemActiveState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSystemActiveState
      (
      );

   /// destructor
   virtual ~EcSystemActiveState
      (
      );

   /// copy constructor
   EcSystemActiveState
      (
      const EcSystemActiveState& orig
      );

   /// assignment operator
   EcSystemActiveState& operator=
      (
      const EcSystemActiveState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemActiveState& orig
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

   /// gets the manipulator active state vector - const version
   virtual const EcManipulatorActiveStateVector&
      manipulatorActiveStateVector
      (
      ) const;

   /// gets the manipulator active state vector - nonconst version
   virtual EcManipulatorActiveStateVector&
      manipulatorActiveStateVector
      (
      );

   /// gets the system-level active AABB state  - const version
   virtual const EcSystemActiveBoundingBoxState&
      systemActiveBoundingBoxState
      (
      ) const;

   /// gets the system-level active AABB state - nonconst version
   virtual EcSystemActiveBoundingBoxState&
      systemActiveBoundingBoxState
      (
      );

   /// sets the manipulator active state vector
   virtual void setManipulatorActiveStateVector
      (
      const EcManipulatorActiveStateVector& manipulatorActiveStateVector
      );

   /// sets the system-level active AABB state
   virtual void setSystemActiveBoundingBoxState
      (
      const EcSystemActiveBoundingBoxState& systemActiveBoundingBoxState
      );

   /// allocate memory for the specified number of manipulators
   virtual void setNumManipulators
      (
      const EcU32 numManipulators
      );

   /// set the nonredundant state.  This invalidates components
   virtual void setNonredundantState
      (
      const EcManipulatorSystemState& state
      );

   /// set a manipulator nonredundant state using an active state
   virtual void setManipulatorNonredundantState
      (
      const EcManipulatorActiveState& state,
      const EcU32 manipulatorIndex
      );

   /// set a manipulator nonredundant position state
   virtual void setManipulatorNonredundantPositionState
      (
      const EcPositionState& posState,
      const EcU32 manipulatorIndex
      );

   /// sets the manipulator active state vector
   void setNonredundantStateFromActiveStateVector
      (
      const EcManipulatorActiveStateVector& manipulatorActiveStateVector
      );

	/// invalidates all components.  Should be used when the state changes.
   virtual void invalidateAll
      (
      );

	/// resets all components.  Should be used when the system changes.
   virtual void resetForSystemChange
      (
      );

   /// get the general force vector (const)
   virtual const EcManipulatorExternalForceVector& generalForceVector
      (
      )const ;

   /// get the general force vector (non-const)
   virtual EcManipulatorExternalForceVector& generalForceVector
      (
      );

   /// set the general force vector
   virtual void setGeneralForceVector
      (
      const EcManipulatorExternalForceVector& forceVec
      );

   /// returns valid flag for force
   virtual const EcBoolean& generalForceValid
      (
      )const;

   /// sets valid flag for force
   virtual void setGeneralForceValid
      (
       const EcBoolean& valid
      );

   /// invalidates just system-level components
   virtual void invalidateSystemLevel
      (
      );

	/// invalidates just modified shape key
	virtual void invalidateModifiedShapeKey
		(
		);

   /// get the manipulator link proximity state vector
   virtual EcManipulatorLinkProximityStateVector& manipulatorLinkProximityStateVector
      (
      );

   /// set the manipulator link proximity state vector
   virtual void setManipulatorLinkProximityStateVector
      (
      const EcManipulatorLinkProximityStateVector& value
      );

   /// get the cache containing shape collision data
   virtual EcSystemShapeCollisionCache& systemShapeCollisionCache
      (
      );

   /// set the cache containing shape collision data
   virtual void setSystemShapeCollisionCache
      (
      const EcSystemShapeCollisionCache& value
      );

	/// gets the vector of the modified shape key
	virtual const EcShapeStateCacheKeyVector& modifiedShapeKeyVec
		(
		)const;

	/// gets the vector of the modified shape key (non const version)
	virtual EcShapeStateCacheKeyVector& modifiedShapeKeyVec
		(
		);

	/// sets the vector of modified shape index
	virtual void setModifiedShapeKeyVec
		(
		const EcShapeStateCacheKeyVector& modifiedShapeKeyVec
		);

	/// gets the modified shape key
	virtual const EcShapeStateCacheKey& modifiedShapeKey
		(
		)const;

	/// gets the modified shape key (non const version)
	virtual EcShapeStateCacheKey& modifiedShapeKey
		(
		);

	/// sets the modified shape index
	virtual void setModifiedShapeKey
		(
		const EcShapeStateCacheKey& modifiedShapeKey
		);

   /// @copydoc EcXmlObject::token()
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
   static EcSystemActiveState nullObject
      (
      );

protected:

   /// active state vector
   EcManipulatorActiveStateVector     m_ManipulatorActiveStateVector;

   /// processor that computes interval overlaps for collision detection
   EcSystemActiveBoundingBoxState     m_SystemActiveAABBState;

   /// cache of general forces
   EcManipulatorExternalForceVector   m_ManipExtForceVec;

   /// cache containing link proximity state
   EcManipulatorLinkProximityStateVector  m_ManipulatorLinkProximityStateVector;

   /// cache containing shape collision data
   EcSystemShapeCollisionCache        m_SystemShapeCollisionCache;

   /// flag indicating if the general force vector is valid
   EcBoolean                          m_IsGeneralForceVectorValid;

	/// vector to store the modified shapes by key
	EcShapeStateCacheKeyVector         m_ModifiedShapeKeyVec;

	/// the modified shapes by key
	EcShapeStateCacheKey               m_ModifiedShapeKey;
};

#endif // ecSystemActiveState_H_
