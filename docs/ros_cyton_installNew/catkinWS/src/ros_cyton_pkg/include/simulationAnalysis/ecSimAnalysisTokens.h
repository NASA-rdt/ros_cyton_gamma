#ifndef ecSimAnalysisTokens_H_
#define ecSimAnalysisTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimAnalysisTokens.h
/// @brief Holds simulation analysis tokens.
/// @details namespace EcSimAnalysis
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecToken.h>

/// Holds simulation analysis tokens.
namespace EcSimAnalysis
{
   ECTOKEN_DEFINITIONS(EC_ACTIN_SIMULATIONANALYSIS_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/sm#")

      // Elements

      /// To plot captured data in a bar chart
      (EcBarChartToken,                               ns + "barChart")
      /// To capture the base acceleration of a manipulator.
      (EcBaseAccelerationDataCaptureTypeToken,        ns + "baseAccelerationDataCaptureType")
      /// To capture the base position of a manipulator.
      (EcBasePositionDataCaptureTypeToken,            ns + "basePositionDataCaptureType")
      /// To capture the base velocity of a manipulator.
      (EcBaseVelocityDataCaptureTypeToken,            ns + "baseVelocityDataCaptureType")
      /// To capture the center of mass of a manipulator.
      (EcCenterOfMassDataCaptureTypeToken,            ns + "centerOfMassDataCaptureType")
      /// To capture the control input to a joint.
      (EcControlInputDataCaptureTypeToken,            ns + "controlInputDataCaptureType")
      /// To capture a joint velocity that is  computed by finite differencing the
      /// control output joint position.
      (EcControlOutputActualJointVelocityDataCaptureTypeToken,    ns + "controlOutputActualJointVelocityDataCaptureType")
      /// To capture a joint position that is an output from the control system.
      (EcControlOutputJointPositionDataCaptureTypeToken,          ns + "controlOutputJointPositionDataCaptureType")
      /// To capture a joint velocity that is an output from the control system.
      (EcControlOutputJointVelocityDataCaptureTypeToken,          ns + "controlOutputJointVelocityDataCaptureType")
      /// To capture the control torque to a joint.
      (EcControlTorqueDataCaptureTypeToken,           ns + "controlTorqueDataCaptureType")
      /// A vector of data capture types.
      (EcDataCaptureTypeVectorToken,                  ns + "dataCaptureTypeVector")
      /// The descriptions of the elements of the data capture type.
      (EcDataLabelsToken,                             ns + "dataLabels")
      /// To disable capturing of some data elements in a data capture type. For example, if we want to capture only the X position of the base, then we must disable the Y and Z positions as well as all of the orientation elements.
      (EcDisableFlagsToken,                           ns + "disableFlags")
      /// The data capture for an entire manipulator for displaying (plotting) purposes.
      (EcDisplaySystemDataCaptureToken,               ns + "displaySystemDataCapture")
      /// To capture the acceleration of an end-effector.
      (EcEndEffectorAccelerationDataCaptureTypeToken, ns + "endEffectorAccelerationDataCaptureType")
      /// The end effector-level data in storage.
      (EcEndEffectorDataToken,                        ns + "endEffectorData")
      /// The data capture for an end-effector.
      (EcEndEffectorDataCaptureToken,                 ns + "endEffectorDataCapture")
      /// A vector of data captures for end-effectors.
      (EcEndEffectorDataCaptureVectorToken,           ns + "endEffectorDataCaptureVector")
      /// The index of an end-effector.
      (EcEndEffectorIndexToken,                       ns + "endEffectorIndex")
      /// To capture the placement of an end-effector.
      (EcEndEffectorPlacementDataCaptureTypeToken,    ns + "endEffectorPlacementDataCaptureType")
      /// To capture the velocity of an end-effector.
      (EcEndEffectorVelocityDataCaptureTypeToken,     ns + "endEffectorVelocityDataCaptureType")
      /// To capture the spatial force (force and moment) applied to a link by an external source.
      (EcExternalForceDataCaptureTypeToken,           ns + "externalForceDataCaptureType")
      /// To capture the acceleration of a joint.
      (EcJointAccelerationDataCaptureTypeToken,       ns + "jointAccelerationDataCaptureType")
      /// To capture the position of a joint.
      (EcJointPositionDataCaptureTypeToken,           ns + "jointPositionDataCaptureType")
      /// To capture the torque of a joint. This is the output torque from the actuator that is applied to the manipulator link.
      (EcJointTorqueDataCaptureTypeToken,             ns + "jointTorqueDataCaptureType")
      /// To capture the velocity of a joint.
      (EcJointVelocityDataCaptureTypeToken,           ns + "jointVelocityDataCaptureType")
      /// To signify that this data component is a data capture.
      (EcGeneralCaptureToken,                         ns + "generalCapture")
      /// To signify that this data component is a data storage.
      (EcGeneralStorageToken,                         ns + "generalStorage")
      /// The data capture for the left Y-axis of a plot.
      (EcLeftSystemDataCaptureToken,                  ns + "leftSystemDataCapture")
      /// The data capture for a link.
      (EcLinkDataCaptureToken,                        ns + "linkDataCapture")
      /// A vector of data captures for links.
      (EcLinkDataCaptureVectorToken,                  ns + "linkDataCaptureVector")
      /// The label to identify a link.
      (EcLinkIdentificationToken,                     ns + "linkIdentification")
      /// The link-level data in storage.
      (EcLinkLevelDataToken,                          ns + "linkLevelData")
      /// The data capture for a manipulator.
      (EcManipulatorDataCaptureToken,                 ns + "manipulatorDataCapture")
      /// A vector of data captures for manipulators.
      (EcManipulatorDataCaptureVectorToken,           ns + "manipulatorDataCaptureVector")
      /// The data storage for an entire manipulator, including manipulator-level, link-level, and end effector-level data.
      (EcManipulatorDataStorageToken,                 ns + "manipulatorDataStorage")
      /// A vector of manipulator data storages.
      (EcManipulatorDataVectorToken,                  ns + "manipulatorDataVector")
      /// The index of an manipulator.
      (EcManipulatorIndexToken,                       ns + "manipulatorIndex")
      /// The manipulator-level data in storage.
      (EcManipulatorLevelDataToken,                   ns + "manipulatorLevelData")
      /// To capture the manipulator power.
      (EcManipulatorPowerDataCaptureTypeToken,        ns + "manipulatorPowerDataCaptureType")
      /// To write the captured data (output) in the MATLAB format.
      (EcMatlabOutputWriterToken,                     ns + "matlabOutputWriter")
      /// To write the captured data (output) in the Mathematica format.
      (EcMathematicaOutputWriterToken,                ns + "mathematicaOutputWriter")
      /// To capture the motor power to a joint.
      (EcMotorPowerDataCaptureTypeToken,              ns + "motorPowerDataCaptureType")
      /// To write the captured data (output) in the MRD format.
      (EcMrdOutputWriterToken,                        ns + "mrdOutputWriter")
      /// The orientation tolerance within which the target is considered reached by an end-effector.
      (EcOrientationToleranceToken,                   ns + "orientationTolerance")
      /// The vector of all output writers.
      (EcOutputWriterVectorToken,                     ns + "outputWriterVector")
      /// The index of the point in a path.
      (EcPathPointIndexToken,                         ns + "pathPointIndex")
      /// The type of plot used to display the captured data
      (EcPlotTypeToken,                               ns + "plotType")
      /// To capture whether an end-effector successfully reaches the desired location.
      (EcReachTargetDataCaptureTypeToken,             ns + "reachTargetDataCaptureType")
      /// The data capture for the right Y-axis of a plot.
      (EcRightSystemDataCaptureToken,                 ns + "rightSystemDataCapture")
      /// To plot captured data as scrolling curves
      (EcScrollingCruveToken,                         ns + "scrollingCurve")
      /// To capture the spatial force (force and moment) at a link required to support the outboard portion of a manipulator.
      (EcStructuralForceDataCaptureTypeToken,         ns + "structuralForceDataCaptureType")
      /// The data capture for an entire system.
      (EcSystemDataCaptureToken,                      ns + "systemDataCapture")
      /// The label of a system data capture.
      (EcSystemDataCaptureLabelToken,                 ns + "systemDataCaptureLabel")
      /// A vector of various types of system data components.
      (EcSystemDataVectorToken,                       ns + "systemDataVector")
      /// The data storage of an entire system.
      (EcSystemDataStorageToken,                      ns + "systemDataStorage")
      /// To write the captured data (output) in the comma-separated format.
      (EcTextOutputWriterToken,                       ns + "textOutputWriter")
      /// The time stamp of a set of captured data.
      (EcTimeToken,                                   ns + "time")
      /// The title of a plot.
      (EcTitleToken,                                  ns + "title")
      /// To write the captured data (output) in the XML format.
      (EcTranslationToleranceToken,                   ns + "translationTolerance")
      /// To write the captured data (output) in the XML format.
      (EcXmlOutputWriterToken,                        ns + "xmlOutputWriter")
   )
}

#endif // ecSimAnalysisTokens_H_
