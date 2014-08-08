#ifndef ecAntiCollisionPositionController_H_
#define ecAntiCollisionPositionController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecAntiCollisionPositionController.h
/// @class EcAntiCollisionPositionController
/// @brief Holds a description of a position controller for one manipulator
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPositionController.h"
#include "ecAntiCollisionPriorityList.h"

#include <manipulator/ecManipulatorProximityTool.h>

/// Holds a description of a position controller with anti-collision for one manipulator.
/// Anti-collision uses priority to determine which manipulator should move away (i.e. deviate
/// from its desired position) in the event of an imminent collision.
class EC_ACTIN_CONTROL_DECL EcAntiCollisionPositionController : public EcPositionController
{
public:

   /// default constructor
   EcAntiCollisionPositionController
      (
      );

   /// destructor
   virtual ~EcAntiCollisionPositionController
      (
      );

   /// copy constructor
   EcAntiCollisionPositionController
      (
      const EcAntiCollisionPositionController& orig
      );

   /// copy constructor - cast from EcPositionController
   EcAntiCollisionPositionController
      (
      const EcPositionController& orig
      );

   /// assignment operator
   EcAntiCollisionPositionController& operator=
      (
      const EcAntiCollisionPositionController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAntiCollisionPositionController& orig
      ) const;

   /// @copydoc EcPositionController::equality()
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// @copydoc EcPositionController::newObject()
   virtual EcXmlObject* newObject
      (
      ) const;

   /// @copydoc EcPositionController::clone()
   virtual EcXmlObject* clone
      (
      ) const;

   /// @copydoc EcPositionController::registerComponents()
   virtual void registerComponents
      (
      );

   /// @copydoc EcPositionController::token()
   virtual const EcToken& token
      (
      ) const;

   /// get flag indicating whether anti-collision is on
   virtual EcBoolean isAntiCollisionOn
      (
      ) const;

   /// set flag indicating whether anti-collision is on
   virtual void setIsAntiCollisionOn
      (
      EcBoolean value
      );

   /// get index of end-effector set used for anti-collision
   virtual EcU32 antiCollisionEndEffectorSet
      (
      ) const;

   /// set index of end-effector set used for anti-collision
   virtual void setAntiCollisionEndEffectorSet
      (
      EcU32 value
      );

   /// get avoidance distance
   virtual EcReal avoidanceDistance
      (
      ) const;

   /// set avoidance distance
   virtual void setAvoidanceDistance
      (
      EcReal value
      );

   /// get the minimum value to which the speed factor can be reduced
   virtual EcReal minimumSpeedFactor
      (
      ) const;

   /// set the minimum value to which the speed factor can be reduced
   virtual void setMinimumSpeedFactor
      (
      EcReal value
      );

   /// set pointer to the priority list
   virtual void setPriorityListPointer
      (
      const EcAntiCollisionPriorityList* pList
      );

   /// token for this class
   /**
   \return token that describes the XML object
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return XML object created during XML loading
   */
   static EcXmlObject* creator
      (
      );

   /// @copydoc EcPositionController::connectComponents()
   virtual void connectComponents
      (
      );

   /// @copydoc EcPositionController::calculateGeneralMotion()
   virtual EcBoolean calculateGeneralMotion
      (
      );

   /// @copydoc EcPositionController::calculateVelocityState()
   virtual void calculateVelocityState
      (
      );

   /// @copydoc EcPositionController::preCalculateStateCondition()
   virtual void preCalculateStateCondition
      (
      );

protected:
   /// Determine whether anti-collision needs to be active and whether this
   /// manipulator needs to yield (move away)
   virtual void configure
      (
      );

   /// Apply the anti-collision strategy
   /// If the manipulator needs to yield, it will use the anti-collision EE set (with soft constraints)
   /// so it can move away to avoid collision. If the manipulator has higher priority, it
   /// will adjust the speed to slow down if necessary as to make sure other manipulators have time to
   /// move away.
   virtual void applyAntiCollision
      (
      );

   /// Flag indicating whether anti-collision is on
   EcXmlBoolean      m_IsAntiCollisionOn;

   /// EE set index used for anti-collision (i.e. containing soft-constraint EEs)
   EcXmlU32          m_AntiCollisionEeSetIndex;

   /// the avoidance distance
   EcXmlReal         m_AvoidanceDistance;

   /// the minimum value to which the speed factor can be reduced
   EcXmlReal         m_MinSpeedFactor;

   // nonXML data below
   /// the priority list
   const EcAntiCollisionPriorityList*  m_pPriorityList;

   /// the input desired end-effector placements
   EcManipulatorEndEffectorPlacement   m_ModifiedDesiredPlacement;

   /// Flag indicating if anti-collision is active (i.e. the distance is less than the avoidance distance)
   EcBoolean         m_IsActive;

   /// Flag indicating if the manipulator should yield (move away) when anti-collision is active
   EcBoolean         m_IsYielding;

   EcReal            m_PrevMinDistance;         ///< previous minimum distance
   EcReal            m_MinDistanceDerivative;   ///< estimate of derivative of minimum distance
   EcReal            m_SpeedFactor;             ///< the current speed factor

   /// manipulator proximity tool.  Used for computing distances
   EcManipulatorProximityTool       m_ManipulatorProximityTool;

   /// cache of EE set index (before switching to anti-collision)
   EcU32             m_CachedEeSetIndex;
};

#endif // ecAntiCollisionPositionController_H_
