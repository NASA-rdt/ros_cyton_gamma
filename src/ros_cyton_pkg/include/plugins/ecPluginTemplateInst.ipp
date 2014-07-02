//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginTemplateInst.ipp
/// @brief Template instantiation of setParam, getParam and param methods.
///        These items are the only valid combinations of CommandType and
///        variable type that we allow.  Performs compile-time checking
///        of parameters to ensure proper usage.  This file needs to be
///        included before template specialization definitions on windows
///        but after definitions on other platforms.
/// @details Plugin template instantiations of allowed types.
///
/// NOTE - The use of generic types that can be declared in other ways is
/// discouraged.  For example an EcU32 may be specified as an EcInt32 or
/// another compatible type.  This causes the user to explicitly cast it into
/// an EcU32 to resolve the symbol and might not necessarily be intuitive.
/// Forcing it to a typedef or other type is preferable to remove potential
/// confusion.
//
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Provide convenience macros to forward declare specific parameter types.
//------------------------------------------------------------------------------

/// setParam that takes 2 additional arguments
#define FWD_DECL_S2PARAM(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL EcBoolean \
   Plugin::setParam<T1,T2>(const EcU32, const EcU32, const T2&)
/// getParam that takes 2 additional arguments
#define FWD_DECL_G2PARAM(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL EcBoolean \
   Plugin::getParam<T1,T2>(const EcU32, const EcU32, T2&) const

/// setParam that takes 1 additional argument
#define FWD_DECL_S1PARAM(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL EcBoolean \
   Plugin::setParam<T1,T2>(const EcU32, const T2&)
/// getParam that takes 1 additional argument
#define FWD_DECL_G1PARAM(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL EcBoolean \
   Plugin::getParam<T1,T2>(const EcU32, T2&) const
#define FWD_DECL_G1PARAM_STRINGINPUT(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL EcBoolean \
   Plugin::getParam<T1,T2>(const EcString&, T2&) const

/// setParam that takes no additional arguments
#define FWD_DECL_S0PARAM(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL EcBoolean \
   Plugin::setParam<T1,T2>(const T2&)
/// getParam that takes no additional arguments
#define FWD_DECL_G0PARAM(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL EcBoolean \
   Plugin::getParam<T1,T2>(T2&) const

/// [get]param that retrieves a copy. No args or error checking.
#define FWD_DECL_PARAM(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL const T2 \
   Plugin::param<T1,T2>() const

/// [get]param that retrieves a const pointer. No args or error checking.
#define FWD_DECL_PARAMP(T1,T2) \
   EC_ACTIN_PLUGINS_PRETEMPLATE_DECL template EC_ACTIN_PLUGINS_DECL const T2* \
   Plugin::paramPtr<T1,T2>() const

#define CAST_DECL_S1PARAM(P,T1,T2) \
   template<> EC_ACTIN_PLUGINS_DECL EcBoolean Plugin::setParam<P,T2>(const EcU32, const T2&)

#define CAST_DECL_S0PARAM(P,T1,T2) \
   template<> EC_ACTIN_PLUGINS_DECL EcBoolean Plugin::setParam<P,T2>(const T2&)

/// Build up smaller macros into consolidated get/set ones.
#define FWD_DECL_SG2PARAM(T1,T2) FWD_DECL_S2PARAM(T1,T2);FWD_DECL_G2PARAM(T1,T2)
#define FWD_DECL_SG1PARAM(T1,T2) FWD_DECL_S1PARAM(T1,T2);FWD_DECL_G1PARAM(T1,T2)
#define FWD_DECL_SG0PARAM(T1,T2) FWD_DECL_S0PARAM(T1,T2);FWD_DECL_G0PARAM(T1,T2)


FWD_DECL_SG0PARAM(ActiveState,            EcManipulatorActiveStateVector);
FWD_DECL_PARAM   (ActiveState,            EcManipulatorActiveStateVector);
FWD_DECL_SG1PARAM(ActiveState,            EcManipulatorActiveState);

FWD_DECL_G0PARAM (ActualEndEffector,      EcManipulatorEndEffectorPlacementVector);
FWD_DECL_PARAM   (ActualEndEffector,      EcManipulatorEndEffectorPlacementVector);
FWD_DECL_G1PARAM (ActualEndEffector,      EcManipulatorEndEffectorPlacement);
FWD_DECL_G2PARAM (ActualEndEffector,      EcCoordinateSystemTransformation);
FWD_DECL_G2PARAM (ActualEndEffector,      EcEndEffectorPlacement);
FWD_DECL_G2PARAM (ActualEndEffector,      EcVector);
FWD_DECL_G2PARAM (ActualEndEffector,      EcOrientation);
FWD_DECL_G2PARAM (ActualEndEffector,      EcRealVector);
FWD_DECL_G1PARAM (ActualEndEffector,      EcRealVector);
FWD_DECL_G2PARAM (ActualEndEffector,      EcReal);

FWD_DECL_SG1PARAM(AntiCollision,          EcBoolean);

FWD_DECL_SG0PARAM(AttachmentMap,          EcManipulatorAttachmentMap);
FWD_DECL_S0PARAM (AttachmentMap,          EcManipulatorAttachmentChange);

FWD_DECL_SG0PARAM(Base,                   EcCoordinateSystemTransformationVector);
FWD_DECL_SG1PARAM(Base,                   EcCoordinateSystemTransformation);
FWD_DECL_SG1PARAM(Base,                   EcVector);
FWD_DECL_SG1PARAM(Base,                   EcOrientation);

FWD_DECL_SG1PARAM(BaseVelocity,           EcGeneralMotion);

FWD_DECL_PARAM   (CalculationTime,        EcReal);

FWD_DECL_SG0PARAM(CollisionExclusionMap,  EcSystemCollisionExclusionMap);

FWD_DECL_SG0PARAM(CollisionPriority,      EcAntiCollisionPriorityList);

FWD_DECL_SG1PARAM(ControlDescriptor,      EcU32);
CAST_DECL_S1PARAM(ControlDescriptor,      EcU32, EcInt32); // support implicit cast

FWD_DECL_SG1PARAM(ControlMethod,          EcU32);
CAST_DECL_S1PARAM(ControlMethod,          EcU32, EcInt32); // support implicit cast

FWD_DECL_SG0PARAM(ControlSystem,          EcForceControlSystem);
FWD_DECL_PARAMP  (ControlSystem,          EcForceControlSystem);
FWD_DECL_SG0PARAM(ControlSystem,          EcSimulationPositionControlContainer);
FWD_DECL_PARAMP  (ControlSystem,          EcSimulationPositionControlContainer);
FWD_DECL_SG0PARAM(ControlSystem,          EcPositionControlSystem);
FWD_DECL_PARAMP  (ControlSystem,          EcPositionControlSystem);
FWD_DECL_SG0PARAM(ControlSystem,          EcBoolean);
FWD_DECL_PARAM   (ControlSystem,          EcBoolean);

//FWD_DECL_SG0PARAM(CoordinatedJointAngle,  EcRealVectorVector);
//FWD_DECL_SG1PARAM(CoordinatedJointAngle,  EcRealVector);
//FWD_DECL_SG2PARAM(CoordinatedJointAngle,  EcReal);
//FWD_DECL_PARAM   (CoordinatedJointAngle,  EcBoolean);

FWD_DECL_SG0PARAM(DataMap,                EcDataMap);

FWD_DECL_SG0PARAM(DesiredEndEffector,     EcManipulatorEndEffectorPlacementVector);
FWD_DECL_PARAM   (DesiredEndEffector,     EcManipulatorEndEffectorPlacementVector);
FWD_DECL_SG1PARAM(DesiredEndEffector,     EcManipulatorEndEffectorPlacement);
FWD_DECL_SG2PARAM(DesiredEndEffector,     EcCoordinateSystemTransformation);
FWD_DECL_SG2PARAM(DesiredEndEffector,     EcEndEffectorPlacement);
FWD_DECL_SG2PARAM(DesiredEndEffector,     EcVector);
FWD_DECL_SG2PARAM(DesiredEndEffector,     EcOrientation);
FWD_DECL_SG1PARAM(DesiredEndEffector,     EcRealVector);
FWD_DECL_S0PARAM (DesiredEndEffector,     ParamTypeEnum); // Set desired to actual

FWD_DECL_SG2PARAM(DesiredEndEffector,     EcReal);
FWD_DECL_SG0PARAM(DesiredForce,           EcManipulatorSensorForceVector);
FWD_DECL_PARAM   (DesiredForce,           EcManipulatorSensorForceVector);
FWD_DECL_SG1PARAM(DesiredForce,           EcManipulatorSensorForce);

FWD_DECL_SG0PARAM(DesiredVelocity,        EcManipulatorEndEffectorVelocityVector);
FWD_DECL_PARAM   (DesiredVelocity,        EcManipulatorEndEffectorVelocityVector);
FWD_DECL_SG1PARAM(DesiredVelocity,        EcManipulatorEndEffectorVelocity);
FWD_DECL_SG2PARAM(DesiredVelocity,        EcRealVector);

FWD_DECL_G2PARAM (DhFrame,                EcCoordinateSystemTransformation);

FWD_DECL_SG0PARAM(DisplaySystemDataCapture,EcDisplaySystemDataCaptureVector);

FWD_DECL_SG0PARAM(DynamicSimulation,      EcDynamicSimulatorSystem);
FWD_DECL_PARAMP  (DynamicSimulation,      EcDynamicSimulatorSystem);
FWD_DECL_SG0PARAM(DynamicSimulation,      EcBoolean);
FWD_DECL_PARAM   (DynamicSimulation,      EcBoolean);
FWD_DECL_SG1PARAM(DynamicSimulation,      EcBoolean);


FWD_DECL_SG0PARAM(EndEffectorSet,         EcEndEffectorSetVector);
FWD_DECL_PARAM   (EndEffectorSet,         EcEndEffectorSetVector);
FWD_DECL_SG1PARAM(EndEffectorSet,         EcEndEffectorSet);
FWD_DECL_SG1PARAM(EndEffectorSet,         EcU32);

FWD_DECL_S0PARAM (ExternalControl,        EcManipulatorTorqueVector);
FWD_DECL_PARAM   (ExternalControl,        EcBoolean);
FWD_DECL_S0PARAM (ExternalControl,        EcBoolean);
CAST_DECL_S0PARAM(ExternalControl,        EcBoolean, EcU32);   // support implicit cast
CAST_DECL_S0PARAM(ExternalControl,        EcBoolean, EcInt32); // support implicit cast

FWD_DECL_SG0PARAM(ForceControlOn,         EcBoolean);
CAST_DECL_S0PARAM(ForceControlOn,         EcBoolean, EcU32);   // support implicit cast
CAST_DECL_S0PARAM(ForceControlOn,         EcBoolean, EcInt32); // support implicit cast

FWD_DECL_SG1PARAM(ForceControlDescriptor, EcU32);
CAST_DECL_S1PARAM(ForceControlDescriptor, EcU32, EcInt32); // support implicit cast

FWD_DECL_SG0PARAM(ForceControlSystem,     EcForceControlSystem);
FWD_DECL_PARAMP  (ForceControlSystem,     EcForceControlSystem);

FWD_DECL_SG0PARAM(ImageSensor,            EcImageSensorVector);
FWD_DECL_G1PARAM (ImageSensor,            EcImageSensor);

FWD_DECL_SG1PARAM(InitJointAngle,         EcRealVector);

FWD_DECL_SG0PARAM(JointAngle,             EcRealVectorVector);
FWD_DECL_SG1PARAM(JointAngle,             EcRealVector);
FWD_DECL_SG2PARAM(JointAngle,             EcReal);

FWD_DECL_SG0PARAM(JointController,        EcJointControllerSystemContainer);
FWD_DECL_PARAMP  (JointController,        EcJointControllerSystemContainer);

FWD_DECL_SG0PARAM(JointVelocity,          EcRealVectorVector);
FWD_DECL_SG1PARAM(JointVelocity,          EcRealVector);
FWD_DECL_SG2PARAM(JointVelocity,          EcReal);

FWD_DECL_PARAMP  (Manipulator,            EcIndividualManipulatorVector);
FWD_DECL_S0PARAM (Manipulator,            EcIndividualManipulator); // Add manip
FWD_DECL_G1PARAM (Manipulator,            EcIndividualManipulator);
FWD_DECL_G1PARAM_STRINGINPUT(Manipulator, EcIndividualManipulator);
FWD_DECL_G2PARAM (Manipulator,            EcManipulatorLink);
FWD_DECL_G0PARAM (Manipulator,            EcStringVector);          // Manip labels
FWD_DECL_G1PARAM (Manipulator,            EcStringVector);          // Link labels for a manip
FWD_DECL_G1PARAM (Manipulator,            EcString);                // Manip label
FWD_DECL_G2PARAM (Manipulator,            EcString);                // Link label
FWD_DECL_S0PARAM (Manipulator,            EcU32);                   // Delete manip
FWD_DECL_PARAM   (Manipulator,            EcU32);                   // Num manip
FWD_DECL_SG0PARAM(ManipulatorSystemConfiguration,            EcManipulatorSystemConfiguration);  // system configuration

FWD_DECL_SG0PARAM(ManipulatorGraspingModule,EcManipulatorGraspingModuleVector);
FWD_DECL_PARAMP  (ManipulatorGraspingModule,EcManipulatorGraspingModuleVector);

FWD_DECL_S2PARAM (ManipulatorLinkProps,   EcManipulatorLink);

FWD_DECL_SG1PARAM(MeasuredForce,          EcManipulatorSensorForce);

FWD_DECL_SG0PARAM(OutputWriterVector,     EcOutputWriterVector);

FWD_DECL_SG0PARAM(PositionControlSystem,  EcSimulationPositionControlContainer);
FWD_DECL_PARAMP  (PositionControlSystem,  EcSimulationPositionControlContainer);
FWD_DECL_SG0PARAM(PositionControlSystem,  EcPositionControlSystem);
FWD_DECL_PARAMP  (PositionControlSystem,  EcPositionControlSystem);

FWD_DECL_G2PARAM (PrimaryFrame,           EcCoordinateSystemTransformation);

FWD_DECL_S1PARAM (ProfiledEndEffectors,   EcU32Vector);

FWD_DECL_G0PARAM (PropagationResults,     EcPropagationResultDataVector);
FWD_DECL_G1PARAM (PropagationResults,     EcPropagationResultData);


FWD_DECL_PARAM   (SimRunState,            SimulationRunState);
FWD_DECL_SG0PARAM(SimRunState,            SimulationRunState);

FWD_DECL_G0PARAM (SimulationMutex,        EcSharedMutexLock);
FWD_DECL_G0PARAM (SimulationMutex,        EcSharedMutexSharedLock);

FWD_DECL_S0PARAM (SimulationReset,        EcBoolean);

FWD_DECL_G0PARAM (SimulationTime,         EcTime);

FWD_DECL_SG1PARAM(SpeedFactor,            EcReal);

FWD_DECL_SG0PARAM(State,                  EcManipulatorSystemState);
FWD_DECL_PARAM   (State,                  EcManipulatorSystemState);
FWD_DECL_SG1PARAM(State,                  EcPositionState);
FWD_DECL_SG1PARAM(State,                  EcVelocityState);

FWD_DECL_S0PARAM (StatedSystem,           EcStatedSystem);
FWD_DECL_PARAMP  (StatedSystem,           EcStatedSystem);

FWD_DECL_SG0PARAM(StaticCollisionExclusionMap,  EcSystemCollisionExclusionMap);

FWD_DECL_S1PARAM (StopMotion,             EcBoolean);

FWD_DECL_SG0PARAM(SystemDataCapture,      EcSystemDataCapture);

FWD_DECL_SG0PARAM(SystemEnvironment,      EcSystemEnvironment);

FWD_DECL_SG0PARAM(SystemSimulation,       EcSystemSimulation);
FWD_DECL_PARAMP  (SystemSimulation,       EcSystemSimulation);

FWD_DECL_SG2PARAM(ToolOffset,             EcCoordinateSystemTransformation);

FWD_DECL_SG0PARAM(ViewerParameters,       EcViewerParameters);
FWD_DECL_PARAM   (ViewerParameters,       EcViewerParameters);

FWD_DECL_PARAM   (WhatChanged,            EcU32);

#undef CAST_DECL_S1PARAM
#undef CAST_DECL_S0PARAM
#undef FWD_DECL_SG2PARAM
#undef FWD_DECL_SG1PARAM
#undef FWD_DECL_SG0PARAM
#undef FWD_DECL_S2PARAM
#undef FWD_DECL_S1PARAM
#undef FWD_DECL_S0PARAM
#undef FWD_DECL_G2PARAM
#undef FWD_DECL_G1PARAM
#undef FWD_DECL_G0PARAM
#undef FWD_DECL_PARAMP
#undef FWD_DECL_PARAM
#undef FWD_DECL_XMLVECTOR
