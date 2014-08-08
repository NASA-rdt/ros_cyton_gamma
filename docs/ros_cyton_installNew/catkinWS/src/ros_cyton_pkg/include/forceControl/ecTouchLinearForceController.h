#ifndef ecTouchLinearForceController_H_
#define ecTouchLinearForceController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecTouchLinearForceController.h
/// @class EcTouchLinearForceController
/// @brief The class for force controller handling touch sensors and
///        linear-constraint end-effectors
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseForceController.h"

class EC_ACTIN_FORCECONTROL_DECL EcTouchLinearForceController : public EcBaseForceController
{
public:

   /// default constructor
   EcTouchLinearForceController
      (
      );

   /// destructor
   virtual ~EcTouchLinearForceController
      (
      );

   /// copy constructor
   EcTouchLinearForceController
      (
      const EcTouchLinearForceController& orig
      );

   /// assignment operator
   EcTouchLinearForceController& operator=
      (
      const EcTouchLinearForceController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTouchLinearForceController& orig
      ) const;

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

   /// token
   virtual const EcToken& token
      (
      ) const;

   /// initialize the force controller. Return false if EcBaseForceController::initialize() return false or if any force sensor is not a touch sensor or any end-effector is not a linear-constraint end-effector.
   virtual EcBoolean initialize
      (
      const EcForceSensorSet& forceSensorSet,
      const EcEndEffectorSet& endEffectorSet
      );

   /// \copydoc EcBaseForceController::adjustDesiredPlacement()
   virtual void adjustDesiredPlacement
      (
      EcReal deltaTime,
      EcU32 manipIndex,
      const EcManipulatorSensorForce& measuredForce,
      const EcManipulatorSensorForce& desiredForce,
      const EcPositionControlSystem& posContSys,
      const EcManipulatorEndEffectorPlacement& actualPlacement,
      EcManipulatorEndEffectorPlacement& desiredPlacement
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
};

#endif // ecTouchLinearForceController_H_
