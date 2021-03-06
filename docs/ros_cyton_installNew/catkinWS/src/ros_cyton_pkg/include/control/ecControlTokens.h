#ifndef ecControlTokens_H_
#define ecControlTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecControlTokens.h
/// @brief Holds tokens for the control project
/// @details namespace EcControl
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecToken.h>

/// Holds tokens for the control project
namespace EcControl
{
   ECTOKEN_DEFINITIONS(EC_ACTIN_CONTROL_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/ct#")

      // Elements
      (EcAccelerationThresholdToken,                 ns + "accelerationThreshold")
      (EcAccelerationOutputFilterToken,              ns + "accelerationOutputFilter")
      (EcAccContWeightToken,                         ns + "accContWeight")
      (EcActiveControlDescriptionIndicesToken,       ns + "activeControlDescriptionIndices")
      (EcActiveControlDescriptionToken,              ns + "activeControlDescription")
      (EcActiveControlMethodToken,                   ns + "activeControlMethod")
      (EcActiveEndEffectorSetToken,                  ns + "activeEndEffectorSet")
      (EcAndToken,                                   ns + "and")
      (EcAngularAccelerationThresholdToken,          ns + "angularAccelerationThreshold")
      (EcAngularDecelerationThresholdToken,          ns + "angularDecelerationThreshold")
      (EcAngularErrorWeightToken,                    ns + "angularErrorWeight")
      (EcAngularGainToken,                           ns + "angularGain")
      (EcAngularWeightToken,                         ns + "angularWeight")
      (EcAngularRateFactorToken,                     ns + "angularRateFactor")
      (EcAngularVelocityThresholdToken,              ns + "angularVelocityThreshold")
      (EcAntiCollisionEndEffectorSetToken,           ns + "antiCollisionEndEffectorSet")
      (EcAntiCollisionPositionControllerToken,       ns + "antiCollisionPositionController")
      (EcAntiCollisionPriorityListToken,             ns + "antiCollisionPriorityList")
      (EcAxisRotateEndEffectorToken,                 ns + "axisRotateEndEffector")
      (EcAvoidanceDistanceToken,                     ns + "avoidanceDistance")
      (EcAvoidanceZoneToken,                         ns + "avoidanceZone")
      (EcBaseComponentToken,                         ns + "baseComponent")
      (EcBaseFilterFrameInPrimaryToken,              ns + "baseFilterFrameInPrimary")
      (EcBoundaryValueToken,                         ns + "boundaryValue")
      (EcBvhPrecisionLevelToken,                     ns + "bvhPrecisionLevel")
      (EcCapsulesToken,                              ns + "capsules")
      (EcCenterOfMassEndEffectorToken,               ns + "centerOfMassEndEffector")
      (EcCheckEnvironmentCollisionToken,             ns + "checkEnvironmentCollision")
      (EcCheckSelfCollisionToken,                    ns + "checkSelfCollision")
      (EcCollisionAvoidanceAbToken,                  ns + "collisionAvoidanceAb")
      (EcCleverPositionControlMethodToken,           ns + "cleverPositionControlMethod")
      (EcCleverPositionControlSystemToken,           ns + "cleverPositionControlSystem")
      (EcCollisionAvoidanceModeToken,                ns + "collisionAvoidanceMode")
      (EcCollisionBreakdownThresholdToken,           ns + "collisionBreakdownThreshold")
      (EcCollisionStoppingThresholdToken,            ns + "collisionStoppingThreshold")
      (EcCollisionForceToSensorReadingConstantToken, ns + "collisionForceToSensorReadingConstant")
      (EcColumnPositionToken,                        ns + "columnPosition")
      (EcColumnSizeToken,                            ns + "columnSize")
      (EcColumnTableFunctionToken,                   ns + "columnTableFunction")
      (EcColumnToken,                                ns + "column")
      (EcControlCoreAbToken,                         ns + "controlCoreAb")
      (EcControlCoreToken,                           ns + "controlCore")
      (EcControlDescriptionsToken,                   ns + "controlDescriptions")
      (EcControlDescriptionVectorsToken,             ns + "controlDescriptionVector")
      (EcControlExpressionAbCoreToken,               ns + "controlExpressionAb")
      (EcControlExpressionContainerToken,            ns + "controlExpressionContainer")
      (EcControlExpressionConvergenceToolToken,      ns + "controlExpressionConvergenceTool")
      (EcControlExpressionCoreToken,                 ns + "controlExpression")
      (EcControlExpressionDescriptionToken,          ns + "controlExpresionDescription")
      (EcControlExpressionMatrixToAbToken,           ns + "controlExpressionMatrixToAb")
      (EcControlExpressionVectorToAbToken,           ns + "controlExpressionVectorToAb")
      (EcControlModeToken,                           ns + "controlMode")
      (EcCoordinatedJointEndEffectorToken,           ns + "coordinatedJointEndEffector")
      (EcCoordinatedJointPositionControlMethodToken, ns + "coordinatedJointPositionControlMethod")
      (EcCoordinatedJointPositionControlSystemToken, ns + "coordinatedJointPositionControlSystem")
      (EcCoreResultToken,                            ns + "coreResultToken")
      (EcCosineToken,                                ns + "cosine")
      (EcDecelerationThresholdToken,                 ns + "decelerationThreshold")
      (EcDefaultFeedbackAssimilationRateToken,       ns + "defaultFeedbackAssimilationRate")
      (EcDefaultMaxVelocityToken,                    ns + "defaultMaxVelocity")
      (EcDefaultProfileAccelerationToken,            ns + "defaultProfileAcceleration")
      (EcDefaultWeightToken,                         ns + "defaultWeight")
      (EcDesiredAngularMomentumToken,                ns + "desiredAngularMomentum")
      (EcDesiredLinearMomentumToken,                 ns + "desiredLinearMomentum")
      (EcDesiredVelocityBasedToken,                  ns + "desiredVelocityBased")
      (EcDiagonalMatrixToken,                        ns + "diagonalMatrix")
      (EcDiagonalToken,                              ns + "diagonal")
      (EcEditableValuesToken,                        ns + "editableValues")
      (EcEditingLabelsToken,                         ns + "editingLabels")
      (EcElbowLinkToken,                             ns + "elbowLink")
      (EcElbowPointToken,                            ns + "elbowPoint")
      (EcElementInverseToken,                        ns + "elementInverse")
      (EcElementLogNToken,                           ns + "elementLogN")
      (EcElementLogToken,                            ns + "elementLog")
      (EcElementPowToken,                            ns + "elementPow")
      (EcElementRootToken,                           ns + "elementRoot")
      (EcElementValueToken,                          ns + "elementValue")
      (EcEnabledManipulatorsToken,                   ns + "enabledManipulators")
      (EcEndEffectorErrorFilterToken,                ns + "endEffectorErrorFilter")
      (EcEndEffectorErrorWeightsToken,               ns + "endEffectorErrorWeights")
      (EcEndEffectorMetricMatrixToken,               ns + "endEffectorMetricMatrix")
      (EcEndEffectorMotionFilterToken,               ns + "endEffectorMotionFilter")
      (EcEndEffectorSetToken,                        ns + "endEffectorSet")
      (EcEndEffectorSetVectorToken,                  ns + "endEffectorSetVector")
      (EcEndEffectorsToken,                          ns + "endEffectors")
      (EcEndEffectorVectorToken,                     ns + "endEffectorVector")
      (EcEndEffectorWeightsToken,                    ns + "endEffectorWeights")
      (EcErrorReductionAMatrixToken,                 ns + "errorReductionConstantMatrix" )
      (EcErrorReductionCovarianceMatrixToken,        ns + "errorReductionCovarianceMatrix" )
      (EcErrorReductionToken,                        ns + "errorReduction")
      (EcErrorSensitivityToken,                      ns + "errorSensitivity")
      (EcErrorWeightToken,                           ns + "errorWeight")
      (EcExpressionContainerToken,                   ns + "expressionContainer")
      (EcExponentToken,                              ns + "exponent")
      (EcExternalOffsetIndexToken,                   ns + "externalOffsetIndex")
      (EcFilteringModeToken,                         ns + "filteringMode")
      (EcFiniteDifferenceToken,                      ns + "finiteDifferenceResult")
      (EcFocusDistanceToken,                         ns + "focusDistance")
      (EcFractionalToken,                            ns + "fractional")
      (EcFrameEndEffectorToken,                      ns + "frameEndEffector")
      (EcFrameToken,                                 ns + "frame")
      (EcFreeSpinInZEndEffectorToken,                ns + "freeSpinInZEndEffector")
      (EcGainToken,                                  ns + "gain")
      (EcGeneralColumnToken,                         ns + "generalColumn")
      (EcGeneralEndEffectorAccelerationsToken,       ns + "generalEndEffectorAccelerations")
      (EcGeneralEndEffectorForcesToken,              ns + "generalEndEffectorForces")
      (EcGeneralEndEffectorMotionFiltersToken,       ns + "generalEndEffectorMotionFilters")
      (EcGeneralEndEffectorVelocitiesToken,          ns + "generalEndEffectorVelocities")
      (EcGeneralForcesToken,                         ns + "generalForces")
      (EcGeneralMotionAccelerationFilterToken,       ns + "generalMotionAccelerationFilter")
      (EcGeneralMotionFilterToken,                   ns + "generalMotionFilter")
      (EcGeneralPlacementsToken,                     ns + "generalPlamements")
      (EcGeneralPrimaryToken,                        ns + "generalPrimary")
      (EcGeneralVelocitiesToken,                     ns + "generalVelocities")
      (EcGravitationalTorqueGradientToken,           ns + "gravitationalTorqueGradient")
      (EcGreaterThanOrEqualToToken,                  ns + "greaterThanOrEqualTo")
      (EcGreaterThanToken,                           ns + "greaterThan")
      (EcGuideFramePathToken,                        ns + "guideFramePath")
      (EcHandVelocityWeightsToken,                   ns + "handVelocityWeights")
      (EcIdentityMatrixToken,                        ns + "identityMatrix")
      (EcIgnoreTimeStepToken,                        ns + "ignoreTimeStep")
      (EcIncludeAngularToken,                        ns + "includeAngular")
      (EcInitializedToken,                           ns + "initialized")
      (EcInputValuesToken,                           ns + "inputValues")
      (EcInputWeightsToken,                          ns + "inputWeights")
      (EcIsAntiCollisionOnToken,                     ns + "isAntiCollisionOn")
      (EcIsFixedBaseToken,                           ns + "isFixedBase")
      (EcIsEditableToken,                            ns + "isEditable")
      (EcIsHardConstraintToken,                      ns + "isHardConstraint")
      (EcIsInteractiveToken,                         ns + "isInteractive")
      (EcIsOnToken,                                  ns + "isOn")
      (EcIsRelativeLinkToken,                        ns + "isRelativeLink")
      (EcJacobianTransposeConvergenceToolToken,      ns + "jacobianTransposeConvergenceTool")
      (EcJointAccelerationThresholdsToken,           ns + "jointAccelerationThresholds")
      (EcJointConstraintAvoidanceToken,              ns + "jointConstraintAvoidance")
      (EcJointControlEndEffectorSetToken,            ns + "jointControlEndEffectorSet")
      (EcJointIndexToken,                            ns + "jointIndex")
      (EcJointLimitAvoidanceToken,                   ns + "jointLimitAvoidance")
      (EcJointLimitFilterToken,                      ns + "jointLimitFilter")
      (EcJointMotionThresholdToken,                  ns + "jointMotionThreshold")
      (EcJointRateFilterToken,                       ns + "jointRateFilter")
      (EcJointRateWeightsToken,                      ns + "jointRateWeights")
      (EcJointSolutionConvergenceToolContainerToken, ns + "jointSolutionConvergenceToolContainer")
      (EcJointSolutionFinderContainerToken,          ns + "jointSolutionFinderContainer")
      (EcJointSolutionFinderMapToken,                ns + "jointSolutionFinderMap")
      (EcJointValueToken,                            ns + "jointValue")
      (EcKiToken,                                    ns + "ki")
      (EcKpToken,                                    ns + "kp")
      (EcLabelToken,                                 ns + "label")
      (EcLabelOneToken,                              ns + "labelOne")
      (EcLabelTwoToken,                              ns + "labelTwo")
      (EcLinearAccelerationThresholdToken,           ns + "linearAccelerationThreshold")
      (EcLinearConstraintEndEffectorToken,           ns + "linearConstraintEndEffector")
      (EcLinearDecelerationThresholdToken,           ns + "linearDecelerationThreshold")
      (EcLinearErrorWeightToken,                     ns + "linearErrorWeight")
      (EcLinearGainToken,                            ns + "linearGain")
      (EcLinearVelocityThresholdToken,               ns + "linearVelocityThreshold")
      (EcLinkIdentifierToken,                        ns + "linkIdentifier")
      (EcLinkLabelsToken,                            ns + "jointLabels")
      (EcLinkWeightsToken,                           ns + "jointWeights")
      (EcLogNToken,                                  ns + "logN")
      (EcLogToken,                                   ns + "log")
      (EcLookAtEndEffectorToken,                     ns + "lookAtEndEffector")
      (EcLessThanOrEqualToToken,                     ns + "lessThanOrEqualTo")
      (EcLessThanToken,                              ns + "lessThan")
      (EcManipulatorConstraintsToken,                ns + "manipulatorConstraints")
      (EcManipulatorConstraintToolToken,             ns + "manipulatorConstraintTool")
      (EcManipulatorControlParameterToken,           ns + "manipulatorControlParameter")
      (EcManipulatorEndEffectorAccelerationToken,    ns + "manipulatorEndEffectorAcceleration")
      (EcManipulatorEndEffectorForceToken,           ns + "manipulatorEndEffectorForce")
      (EcManipulatorEndEffectorPlacementToken,       ns + "manipulatorEndEffectorPlacement")
      (EcManipulatorEndEffectorPlacementPathToken,   ns + "manipulatorEndEffectorPlacementPath")
      (EcManipulatorEndEffectorPlacementVectorToken, ns + "manipulatorEndEffectorPlacementVector")
      (EcManipulatorEndEffectorVelocityToken,        ns + "manipulatorEndEffectorVelocityToken")
      (EcManipulatorFrameVectorVectorToken,          ns + "manipulatorFrameVectorVector")
      (EcManipulatorIndexToken,                      ns + "manipulatorIndex")
      (EcMassMatrixAbToken,                          ns + "massMatrixAb")
      (EcMassMatrixToken,                            ns + "massMatrix")
      (EcMatrixParameterToken,                       ns + "matrixParameter")
      (EcMatrixToken,                                ns + "matrix")
      (EcMaxIterationsToken,                         ns + "maxIterations")
      (EcMaxFinalPropagationSizeToken,               ns + "maxFinalPropagationSize")
      (EcMaxMultiplierToken,                         ns + "maxMultiplier")
      (EcMaxRatioToken,                              ns + "maxRatio")
      (EcMaxToken,                                   ns + "max")
      (EcMaxVelocitiesToken,                         ns + "maxVelocities")
      (EcMinSpeedFactorToken,                        ns + "minSpeedFactor")
      (EcMinusToken,                                 ns + "minus")
      (EcMotionFilterToken,                          ns + "motionFilter")
      (EcMotionFilterSetsToken,                      ns + "motionFilterSets")
      (EcMotionFilterSetToken,                       ns + "motionFilterSet")
      (EcNegativeToken,                              ns + "negative")
      (EcNullSpaceComponentToken,                    ns + "nullSpaceComponent")
      (EcObstacleAvoidanceAbToken,                   ns + "obstacleAvoidanceAb")
      (EcObstacleAvoidanceToken,                     ns + "obstacleAvoidance")
      (EcOffsetToken,                                ns + "offset")
      (EcOffsetTransformationsToken,                 ns + "offsetTransformations")
      (EcOffsetTransformationToken,                  ns + "offsetTransformation")
      (EcOrToken,                                    ns + "or")
      (EcOrientationToken,                           ns + "orientation")
      (EcOrientationEndEffectorToken,                ns + "orientationEndEffector")
      (EcOutputWeightsToken,                         ns + "outputWeights")
      (EcPlanarEndEffectorToken,                     ns + "planarEndEffector")
      (EcPlanarTracksFilterToken,                    ns + "planarTracksFilter")
      (EcPlusToken,                                  ns + "plus")
      (EcPointDistanceEndEffectorToken,              ns + "pointDistanceEndEffector")
      (EcPointEndEffectorToken,                      ns + "pointEndEffector")
      (EcPointMotionFilterToken,                     ns + "pointMotionFilter")
      (EcPointOfApplicationToken,                    ns + "pointOfApplication")
      (EcPointOneToken,                              ns + "pointOne")
      (EcPointToken,                                 ns + "point")
      (EcPointTwoToken,                              ns + "pointTwo")
      (EcPositionControllerToken,                    ns + "positionController")
      (EcPositionControllerVectorToken,              ns + "positionControllerVector")
      (EcPositionControlMethodToken,                 ns + "positionControlMethod")
      (EcPositionControlMethodVectorToken,           ns + "positionControlMethodVector")
      (EcPositionControlOutputFilterVectorToken,     ns + "positionControlOutputFilterVector")
      (EcPositionControlResultToken,                 ns + "positionControlResult")
      (EcPositionControlSystemToken,                 ns + "positionControlSystem")
      (EcPositionControlSystemWithSimulationToken,   ns + "positionControlSystemWithSimulation")
      (EcPositionControlSystemWithAccelerationToken, ns + "positionControlSystemWithAcceleration")
      (EcPositionControlToken,                       ns + "positionControl")
      (EcPositionStatePathToken,                     ns + "positionStatePath")
      (EcPositionToken,                              ns + "position")
      (EcPotentialEnergyGradientToken,               ns + "potentialEnergyGradient")
      (EcPrimaryDeterminantToken,                    ns + "primaryDeterminant")
      (EcProbabilityThresholdToken,                  ns + "probabilityThreshold")
      (EcProfileAccelerationsToken,                  ns + "profileAccelerations")
      (EcProjectAlongSystemVectorToken,              ns + "projectAlongSystemVector")
      (EcProjectedCenterOfMassEndEffectorToken,      ns + "projectedCenterOfMassEndEffector")
      (EcProportionalToken,                          ns + "proportional")
   )
   // Current limitation is 256 tokens per macro call.  Split to keep happy.
   ECTOKEN_DEFINITIONS(EC_ACTIN_CONTROL_DECL,
      (EcQueryDistancePrecisionLevelToken,           ns + "queryDistancePrecisionLevel")
      (EcRandomJointSolutionFinderToken,             ns + "randomJointSolutionFinder")
      (EcReferenceAxisToken,                         ns + "referenceAxis")
      (EcRelativeLinkDataToken,                      ns + "relativeLinkData")
      (EcRelativeLinkIdToken,                        ns + "relativeLinkId")
      (EcRelativeModeToken,                          ns + "relativeMode")
      (EcRelativeModeExternalToken,                  ns + "relativeModeExternal")
      (EcRelativeModeInternalToken,                  ns + "relativeModeInternal")
      (EcRelativeModeNoneToken,                      ns + "relativeModeNone")
      (EcRepeatIfFailedToken,                        ns + "repeatIfFailed")
      (EcRowPositionToken,                           ns + "rowPosition")
      (EcRowSizeToken,                               ns + "rowSize")
      (EcScalarConstantToken,                        ns + "scalarConstant")
      (EcScalarMotionFilterToken,                    ns + "scalarMotionFilter")
      (EcScalarParameterToken,                       ns + "scalarParameter")
      (EcScalarToken,                                ns + "scalar")
      (EcSewAngleEndEffectorToken,                   ns + "sewAngleEndEffector")
      (EcShoulderLinkToken,                          ns + "shoulderLink")
      (EcSineToken,                                  ns + "sine")
      (EcSimulationControlToken,                     ns + "simulationControl")
      (EcSimulationFilterToken,                      ns + "simulationFilter")
      (EcSimulationRunTimeScaleFactorToken,          ns + "simulationRunTimeScaleFactor")
      (EcSimulationRunTimeToken,                     ns + "simulationRunTime")
      (EcSimulationStepsToken,                       ns + "simulationSteps")
      (EcSimulationToleranceToken,                   ns + "simulationTolerance")
      (EcSingleElementColumnToken,                   ns + "singleElementColumn")
      (EcSingleElementMatrixToken,                   ns + "singleElementMatrix")
      (EcSingularityAvoidanceToken,                  ns + "singularityAvoidance")
      (EcSizeToken,                                  ns + "size")
      (EcSlideXSpinZEndEffectorToken,                ns + "slideXSpinZEndEffector")
      (EcSlidingEndEffectorToken,                    ns + "slidingEndEffector")
      (EcSoftConstraintDistanceToken,                ns + "softConstraintDistance")
      (EcSoftConstraintHandlerToken,                 ns + "softConstraintHandler")
      (EcSoftConstraintHandlerContainerToken,        ns + "softConstraintHandlerContainer")
      (EcSpatialMomentumEndEffectorToken,            ns + "spatialMomentumEndEffector")
      (EcStatePathToken,                             ns + "statePath")
      (EcStateVectorToken,                           ns + "stateVector")
      (EcStoppingCriteriaMapToken,                   ns + "stoppingCriteriaMap")
      (EcStopsAtCollisionsToken,                     ns + "stopsAtCollisions")
      (EcStopsAtLimitsToken,                         ns + "stopsAtLimits")
      (EcStrengthOptimizationForcesToken,            ns + "strengthOptimizationForces" )
      (EcStrengthOptimizationOrderToken,             ns + "strengthOptimizationOrder" )
      (EcStrengthOptimizationToken,                  ns + "strengthOptimization" )
      (EcSystemVectorToken,                          ns + "systemVector" )
      (EcTableFunctionToken,                         ns + "tableFunction")
      (EcThresholdOptionToken,                       ns + "thresholdOption")
      (EcThreeHalvesToken,                           ns + "threeHalves")
      (EcThresholdToken,                             ns + "threshold")
      (EcTimeStepToken,                              ns + "timeStep")
      (EcTimesToken,                                 ns + "times")
      (EcTimeVectorToken,                            ns + "timeVector")
      (EcToleranceToken,                             ns + "tolerance")
      (EcToolOffsetsToken,                           ns + "toolOffsets")
      (EcTransposeToken,                             ns + "transpose")
      (EcTransitionPeriodToken,                      ns + "transitionPeriod")
      (EcTypeToken,                                  ns + "type")
      (EcTrapezoidalToken,                           ns + "trapezoidal")
      (EcUnfilteredRatesToken,                       ns + "unfilteredRates")
      (EcUnfilteredRatesVectorToken,                 ns + "unfilteredRatesVector")
      (EcUnitaryMapContainerToken,                   ns + "unitaryMapContainer")
      (EcUseExternalOffsetToken,                     ns + "useExternalOffset")
      (EcUseInfinityNormToken,                       ns + "useInfinityNorm")
      (EcUseIntervalProcessingToken,                 ns + "useIntervalProcessing")
      (EcUseTwoPassesToken,                          ns + "useTwoPasses")
      (EcVectorParameterToken,                       ns + "vectorParameter")
      (EcVectorToken,                                ns + "vector")
      (EcVelocityControlDescriptionToken,            ns + "velocityControlDescription")
      (EcVelocityControllerToken,                    ns + "velocityController")
      (EcVelocityControllersToken,                   ns + "velocityControllers")
      (EcVelocityControlSystemToken,                 ns + "velocityControlSystem")
      (EcVelocityControlToken,                       ns + "velocityControl")
      (EcVelocityStateReturnModeToken,               ns + "velocityStateReturnMode")
      (EcWeightedSumToken,                           ns + "weightedSum")
      (EcWeightToken,                                ns + "weight")
      (EcWeightsToken,                               ns + "weights")
      (EcWlsSoftConstraintHandlerToken,              ns + "wlsSoftConstraintHandler")
      (EcWristLinkToken,                             ns + "wristLink")
      (EcWristPointToken,                            ns + "wristPoint")
      (EcXEndEffectorToken,                           ns + "xEndEffector")
      (EcXyEndEffectorToken,                         ns + "xyEndEffector")
      (EcXyOrientationToken,                         ns + "xyOrientation")
      (EcZeroToken,                                  ns + "zero")

      // Enumerations ... don't need namespace
      (EcInfinityNormToken,                          "infinityNorm")
      (EcManipulatorToken,                           "manipulator")
      (EcNoneToken,                                  "none")
      (EcOneNormToken,                               "oneNorm")
      (EcSystemToken,                                "system")
      (EcTwoNormToken,                               "twoNorm")
   )
}

#endif // ecControlTokens_H_
