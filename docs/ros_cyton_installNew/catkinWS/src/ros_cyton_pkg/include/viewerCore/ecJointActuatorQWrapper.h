#ifndef EcJointActuatorQWrapper_H_
#define EcJointActuatorQWrapper_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointActuatorQWrapper.h
/// @brief Wrappers for EcJointActuator used for GUI
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <manipulator/ecJointActuator.h>
#include <QtCore/QObject>
#include <QtGui/QVector3D>

// macros for convenience
#undef EC_PROPERTY_DEC
#undef EC_PROPERTY_DEF
#undef EC_PROPERTY_DEF1
#undef EC_DERIVED_PROPERTY_DEF

#define EC_PROPERTY_DEC(type, readMethod, writeMethod) \
   type readMethod() const; \
   void writeMethod(const type& value);

/// Wrapper for EcShape
class EC_GUICOMMON_VIEWERCORE_DECL EcJointActuatorQWrapper : public QObject
{
   Q_OBJECT
   Q_PROPERTY(double frictionCoefficient READ frictionCoefficient WRITE setFrictionCoefficient)
   Q_PROPERTY(double gearRatio READ gearRatio WRITE setGearRatio)
   Q_PROPERTY(double inertia READ inertia WRITE setInertia)
   Q_PROPERTY(bool isRigid READ isRigid WRITE setIsRigid)
   Q_PROPERTY(double jointLowerLimit READ jointLowerLimit WRITE setJointLowerLimit)
   Q_PROPERTY(double jointUpperLimit READ jointUpperLimit WRITE setJointUpperLimit)
   Q_PROPERTY(double maxOutputRate READ maxOutputRate WRITE setMaxOutputRate)
   Q_PROPERTY(double maxTorque READ maxTorque WRITE setMaxTorque)
   Q_PROPERTY(double minTorque READ minTorque WRITE setMinTorque)
   Q_PROPERTY(double stopperSpringCoefficient READ stopperSpringCoefficient WRITE setStopperSpringCoefficient)
   Q_PROPERTY(double stopperDampingCoefficient READ stopperDampingCoefficient WRITE setStopperDampingCoefficient)
   Q_PROPERTY(double stopperZone READ stopperZone WRITE setStopperZone)
   Q_PROPERTY(double staticCoulombFriction READ staticCoulombFriction WRITE setStaticCoulombFriction)
   Q_PROPERTY(double kineticCoulombFrictionPercentage READ kineticCoulombFrictionPercentage WRITE setKineticCoulombFrictionPercentage)
   Q_PROPERTY(double staticCoulombSpringCoefficient READ staticCoulombSpringCoefficient WRITE setStaticCoulombSpringCoefficient)
   Q_PROPERTY(double staticCoulombDamperCoefficient READ staticCoulombDamperCoefficient WRITE setStaticCoulombDamperCoefficient)
   Q_PROPERTY(double limitingVelocityStickRegion READ limitingVelocityStickRegion WRITE setLimitingVelocityStickRegion)
   Q_PROPERTY(double jointFlexibilityStiffness READ jointFlexibilityStiffness WRITE setJointFlexibilityStiffness)
   Q_PROPERTY(double jointFlexibilityDamping READ jointFlexibilityDamping WRITE setJointFlexibilityDamping)
   Q_PROPERTY(double backlash READ backlash WRITE setBacklash)
   Q_PROPERTY(double maxEfficiency READ maxEfficiency WRITE setMaxEfficiency)

public:
   EcJointActuatorQWrapper
      (
      QObject* parent=0
      );

   virtual ~EcJointActuatorQWrapper() {}

   void setJointActuator
      (
      const EcJointActuator& jointActuator
      )
   {
      m_JointActuator = jointActuator;
   }

   const EcJointActuator& jointActuator()
   {
      return m_JointActuator;
   }

   EC_PROPERTY_DEC(double, frictionCoefficient, setFrictionCoefficient)
   EC_PROPERTY_DEC(double, gearRatio, setGearRatio)
   EC_PROPERTY_DEC(double, inertia, setInertia)
   EC_PROPERTY_DEC(bool, isRigid, setIsRigid)
   EC_PROPERTY_DEC(double, jointLowerLimit, setJointLowerLimit)
   EC_PROPERTY_DEC(double, jointUpperLimit, setJointUpperLimit)
   EC_PROPERTY_DEC(double, maxOutputRate, setMaxOutputRate)
   EC_PROPERTY_DEC(double, maxTorque, setMaxTorque)
   EC_PROPERTY_DEC(double, minTorque, setMinTorque)
   EC_PROPERTY_DEC(double, stopperSpringCoefficient, setStopperSpringCoefficient)
   EC_PROPERTY_DEC(double, stopperDampingCoefficient, setStopperDampingCoefficient)
   EC_PROPERTY_DEC(double, stopperZone, setStopperZone)
   EC_PROPERTY_DEC(double, staticCoulombFriction, setStaticCoulombFriction)
   EC_PROPERTY_DEC(double, kineticCoulombFrictionPercentage, setKineticCoulombFrictionPercentage)
   EC_PROPERTY_DEC(double, staticCoulombSpringCoefficient, setStaticCoulombSpringCoefficient)
   EC_PROPERTY_DEC(double, staticCoulombDamperCoefficient, setStaticCoulombDamperCoefficient)
   EC_PROPERTY_DEC(double, limitingVelocityStickRegion, setLimitingVelocityStickRegion)
   EC_PROPERTY_DEC(double, jointFlexibilityStiffness, setJointFlexibilityStiffness)
   EC_PROPERTY_DEC(double, jointFlexibilityDamping, setJointFlexibilityDamping)
   EC_PROPERTY_DEC(double, backlash, setBacklash)
   EC_PROPERTY_DEC(double, maxEfficiency, setMaxEfficiency)


protected:
   EcJointActuator m_JointActuator;
};

#undef EC_PROPERTY_DEC

#endif // EcJointActuatorQWrapper_H_
