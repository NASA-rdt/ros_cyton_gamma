#ifndef ecForceControlTokens_H_
#define ecForceControlTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceControlTokens.h
/// @brief Holds tokens for the forceControl project
/// @details namespace EcForceControl
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecToken.h>

/// Holds tokens for the force control project
namespace EcForceControl
{
   ECTOKEN_DEFINITIONS(EC_ACTIN_FORCECONTROL_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/ct#")

      // Elements
      (EcBToken,                                     ns + "B")
      (EcDefaultForceControllerToken,                ns + "defaultForceController")
      (EcDefaultKpToken,                             ns + "defaultKp")
      (EcDefaultKiToken,                             ns + "defaultKi")
      (EcDToken,                                     ns + "D")
      (EcEndEffectorIdentifiersToken,                ns + "endEffectorIdentifiers")
      (EcForceControlDescriptionToken,               ns + "forceControlDescription")
      (EcForceControlFunctionContainerToken,         ns + "forceControlFunctionContainer")
      (EcForceControlSystemToken,                    ns + "forceControlSystem")
      (EcForceControllerVectorToken,                 ns + "forceControllerVector")
      (EcForceSensorIdentifiersToken,                ns + "forceSensorIdentifiers")
      (EcForceSensorSetToken,                        ns + "forceSensorSet")
      (EcForceSensorSetVectorToken,                  ns + "forceSensorSetVector")
      (EcForceSensorVectorToken,                     ns + "forceSensorVector")
      (EcImpedanceControlFunctionToken,              ns + "impedanceControlFunction")
      (EcKToken,                                     ns + "K")
      (EcKiToken,                                    ns + "ki")
      (EcKpToken,                                    ns + "kp")
      (EcMToken,                                     ns + "M")
      (EcPiForceControlFunctionToken,                ns + "piForceControlFunction")
      (EcSensorDirectionToken,                       ns + "sensorDirection")
      (EcSensorFrameToken,                           ns + "sensorFrame")
      (EcSensorLocationToken,                        ns + "sensorLocation")
      (EcSensorMapVectorToken,                       ns + "sensorMapVector")
      (EcSensorNameToken,                            ns + "sensorName")
      (EcSensorShapeNameToken,                       ns + "sensorShapeName")
      (EcSixAxisFTSensorToken,                       ns + "sixAxisFTSensor")
      (EcTorqueSensorToken,                          ns + "torqueSensor")
      (EcTouchLinearForceControllerToken,            ns + "touchLinearForceController")
      (EcTouchSensorToken,                           ns + "touchSensor")

      // Enumerations ... don't need namespace
      (EcControllerTypeFullDimensionToken,           "controllerTypeFullDimension")
      (EcControllerTypeLinearOnlyToken,              "controllerTypeLinearOnly")
      (EcControllerTypeZDirectionToken,              "controllerTypeZDirection")
   )
}

#endif // ecForceControlTokens_H_
