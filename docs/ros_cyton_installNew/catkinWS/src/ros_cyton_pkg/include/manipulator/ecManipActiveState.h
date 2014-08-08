#ifndef ecManipActiveState_H_
#define ecManipActiveState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipActiveState.h
/// @class EcManipulatorActiveState
/// @brief This class is a container for domain-specific active states.
///        These are used for dynamic programming in manipulator control.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecActuatorState.h"
#include "ecManipActAccState.h"
#include "ecManipActArtState.h"
#include "ecManipActForceState.h"
#include "ecManipActMassState.h"
#include "ecManipActPosState.h"
#include "ecManipActVelState.h"
#include <xml/ecXmlCompType.h>

/// This class is a container for domain-specific active states.
/** These are used for dynamic programming in manipulator control.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorActiveState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorActiveState
      (
      );

   /// destructor
   virtual ~EcManipulatorActiveState
      (
      );

   /// copy constructor
   EcManipulatorActiveState
      (
      const EcManipulatorActiveState& orig
      );

   /// assignment operator
   EcManipulatorActiveState& operator=
      (
      const EcManipulatorActiveState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorActiveState& orig
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

   /// gets the nonredundant position state
   virtual const EcPositionState& positionState
      (
      ) const;

   /// sets the nonredundant position state
   /// returns True if there was a change, False if the
   /// old state equals the new value
   virtual EcBoolean setPositionState
      (
      const EcPositionState& positionState
      );

   /// gets the nonredundant velocity state
   virtual const EcVelocityState& velocityState
      (
      ) const;

   /// sets the nonredundant velocity state
   /// returns True if there was a change, False if the
   /// old state equals the new value
   virtual EcBoolean setVelocityState
      (
      const EcVelocityState& velocityState
      );

   /// gets the nonredundant acceleration state
   virtual const EcAccelerationState& accelerationState
      (
      ) const;

   /// sets the nonredundant acceleration state
   virtual void setAccelerationState
      (
      const EcAccelerationState& accelerationState
      );

   /// gets the active position state - const version
   virtual const EcManipulatorActivePositionState& activePositionState
      (
      ) const;

   /// gets the active position state - nonconst version
   virtual EcManipulatorActivePositionState& activePositionState
      (
      );

   /// sets the active position state
   virtual void setActivePositionState
      (
      const EcManipulatorActivePositionState& activePositionState
      );

   /// gets the active velocity state - const version
   virtual const EcManipulatorActiveVelocityState& activeVelocityState
      (
      ) const;

   /// gets the active velocity state - nonconst version
   virtual EcManipulatorActiveVelocityState& activeVelocityState
      (
      );

   /// sets the active velocity state
   virtual void setActiveVelocityState
      (
      const EcManipulatorActiveVelocityState& activeVelocityState
      );

   /// gets the active acceleration state - const version
   virtual const EcManipulatorActiveAccelerationState&
      activeAccelerationState
      (
      ) const;

   /// gets the active acceleration state - nonconst version
   virtual EcManipulatorActiveAccelerationState& activeAccelerationState
      (
      );

   /// sets the active acceleration state
   virtual void setActiveAccelerationState
      (
      const EcManipulatorActiveAccelerationState& activeAccelerationState
      );

   /// gets the active force state - const version
   virtual const EcManipulatorActiveForceState& activeForceState
      (
      ) const;

   /// gets the active force state - nonconst version
   virtual EcManipulatorActiveForceState& activeForceState
      (
      );

   /// sets the active force state
   virtual void setActiveForceState
      (
      const EcManipulatorActiveForceState& activeForceState
      );

   /// gets the active mass state - const version
   virtual const EcManipulatorActiveMassState& activeMassState
      (
      ) const;

   /// gets the active mass state - nonconst version
   virtual EcManipulatorActiveMassState& activeMassState
      (
      );

   /// sets the active mass state
   virtual void setActiveMassState
      (
      const EcManipulatorActiveMassState& activeMassState
      );

   /// gets the active articulation state - const version
   virtual const EcManipulatorActiveArticulationState&
      activeArticulationState
      (
      ) const;

   /// gets the active articulation state - nonconst version
   virtual EcManipulatorActiveArticulationState& activeArticulationState
      (
      );

   /// sets the active articulation state
   virtual void setActiveArticulationState
      (
      const EcManipulatorActiveArticulationState& activeArticulationState
      );

   /// gets the actuator states - const version
   virtual const EcActuatorState& actuatorState
      (
      ) const;

   /// gets the actuator states - nonconst version
   virtual EcActuatorState& actuatorState
      (
      );

   /// sets the actuator states
   virtual void setActuatorState
      (
      const EcActuatorState& actuatorState
      );

   /// invalidates all components
   virtual void invalidateAll
      (
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
   static EcManipulatorActiveState nullObject
      (
      );

protected:

   /// the position state
   EcManipulatorActivePositionState     m_ActivePositionState;

   /// the velocity state
   EcManipulatorActiveVelocityState     m_ActiveVelocityState;

   /// the acceleration state
   EcManipulatorActiveAccelerationState m_ActiveAccelerationState;

   /// the force state
   EcManipulatorActiveForceState        m_ActiveForceState;

   /// the mass state
   EcManipulatorActiveMassState         m_ActiveMassState;

   /// the articulation state
   EcManipulatorActiveArticulationState m_ActiveArticulationState;

   /// the actuator state
   EcActuatorState                      m_ActuatorState;

   // non-XML data below
   /// The flag indicating whether all active acceleration state is invalid
   EcBoolean                            m_ActiveAccelerationStateAllInvalid;

   /// The flag indicating whether all active force state is invalid
   EcBoolean                            m_ActiveForceStateAllInvalid;
};

/// a vector of active states
typedef EcXmlVectorType<EcManipulatorActiveState>
   EcManipulatorActiveStateVector;

#endif // ecManipActiveState_H_
