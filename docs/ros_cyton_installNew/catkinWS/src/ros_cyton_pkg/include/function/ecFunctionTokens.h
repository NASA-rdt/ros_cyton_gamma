#ifndef ecFunctionTokens_H_
#define ecFunctionTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecFunctionTokens.h
/// @brief Token definitions for the function project.
/// @details namespace EcFunction
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <xml/ecToken.h>

/// Token definitions for the function project
namespace EcFunction
{
   ECTOKEN_DEFINITIONS(EC_FOUNDATION_FUNCTION_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/cr#")

      // Elements
      (EcAlphaToken,                              ns + "alpha")
      (EcAxisAlignedToken,                        ns + "axisAligned")
      (EcBetaToken,                               ns + "beta")
      (EcCenterToken,                             ns + "center")
      (EcCenterSlopeToken,                        ns + "centerSlope")
      (EcCompositeFunctionBranchToken,            ns + "compositeFunctionBranch")
      (EcCompositeFunctionContainerToken,         ns + "compositeFunctionContainer")
      (EcDefaultEdgeLengthToken,                  ns + "defaultEdgeLength")
      (EcDefaultSimplexEdgeLengthToken,           ns + "defaultSimplexEdgeLength")
      (EcDependentDataToken,                      ns + "dependentData")
      (EcDirectionsModeToken,                     ns + "directionsMode")
      (EcDomainValuesToken,                       ns + "domainValues")
      (EcEdgeLengthsToken,                        ns + "edgeLengths")
      (EcEndValueToken,                           ns + "endValue")
      (EcEtaToken,                                ns + "eta")
      (EcExecuteInParallelToken,                  ns + "executeInParallel")
      (EcExponentToken,                           ns + "exponent")
      (EcFinalSlopeToken,                         ns + "finalSlope")
      (EcFirstOrderCoefficientsToken,             ns + "firstOrderCoefficients")
      (EcFirstOrderIndicesToken,                  ns + "firstOrderIndices")
      (EcGammaToken,                              ns + "gamma")
      (EcGaussQuadratureToken,                    ns + "gaussQuadrature")
      (EcHookeJeevesToken,                        ns + "hookeJeeves")
      (EcImplicitFilteringToken,                  ns + "implicitFiltering")
      (EcIndependentDataToken,                    ns + "independentData")
      (EcIndVectorToken,                          ns + "independentVector")
      (EcLineSearchInitialLambdaMultiplierToken,  ns + "lineSearchInitialLambdaMultiplier")
      (EcInitialSlopeToken,                       ns + "initialSlope")
      (EcLinearScalarFunctionToken,               ns + "linearScalarFunction")
      (EcLinearMultivariableConstraintToken,      ns + "linearMultivariableConstraint")
      (EcLineSearchAlphaToken,                    ns + "lineSearchAlpha")
      (EcLineSearchBetaToken,                     ns + "lineSearchBeta")
      (EcLineSearchMaxIterationsToken,            ns + "lineSearchMaxIterations")
      (EcMultipointScalarFunctionToken,           ns + "multipointScalarFunction")
      (EcMaxExpansionStepsToken,                  ns + "maxExpansionSteps")
      (EcMaxTotalStepsToken,                      ns + "maxTotalSteps")
      (EcMaxFunctionEvaluationsToken,             ns + "maxFunctionEvaluations")
      (EcMinTotalReductionToken,                  ns + "minTotalReduction")
      (EcMultidirectionalSearchToken,             ns + "multidirectionalSearch")
      (EcMultivariableConstraintContainerToken,   ns + "multivariableConstraintContainer")
      (EcMultivariableConstraintVectorToken,      ns + "multivariableConstraintVector")
      (EcNelderMeadToken,                         ns + "nelderMead")
      (EcNoneToken,                               ns + "none")
      (EcNumberPassesToken,                       ns + "numberPasses")
      (EcOffsetToken,                             ns + "offset")
      (EcOptimizerContainerToken,                 ns + "optimizerContainer")
      (EcOptimizerSequenceToken,                  ns + "optimizerSequence")
      (EcOrderToken,                                  ns + "order")
      (EcPowerUnitaryMapToken,                    ns + "powerUnitaryMap")
      (EcQuadraticMultivariableConstraintToken,   ns + "quadraticMultivariableConstraint")
      (EcRandomToken,                             ns + "random")
      (EcRangeValuesToken,                        ns + "rangeValues")
      (EcReductionFactorToken,                    ns + "reductionFactor")
      (EcRestartCheckPeriodToken,                 ns + "restartCheckPeriod")
      (EcRotatedToken,                            ns + "rotated")
      (EcScalarFunctionContainerToken,            ns + "scalarFunctionContainer")
      (EcScalarMultivariableOptimizerVectorToken, ns + "scalarMultivariableOptimizerVector")
      (EcSecondOrderCoefficientsToken,            ns + "secondOrderCoefficients")
      (EcSecondOrderIndexPairsToken,              ns + "secondOrderIndexPairs")
      (EcSequenceOptimizerToken,                  ns + "sequenceOptimizer")
      (EcSCurveUnitaryMapToken,                   ns + "sCurveUnitaryMap")
      (EcSigmaToken,                              ns + "sigma")
      (EcSimplexEdgeLengthsToken,                 ns + "simplexEdgeLengths")
      (EcSimplexScaleFactorToken,                 ns + "simplexScaleFactor")
      (EcStartValueToken,                         ns + "startValue")
      (EcStoppingThresholdToken,                  ns + "stoppingThreshold")
      (EcTableFunctionInterpolatorToken,          ns + "tableFunctionInterpolator")
      (EcTableFunctionVectorSearchToken,          ns + "tableFunctionVectorSearch")
      (EcTauToken,                                ns + "tau")
      (EcUnitaryMapContainerToken,                ns + "unitaryMapContainer")

      // Attributes ... namespace optional
      (EcIndLowerBoundaryToken,                   "lowerBoundaryOption")
      (EcIndSearchToken,                          "searchOption")
      (EcIndUpperBoundaryToken,                   "upperBoundaryOption")

      // Enumerations ... don't need namespace
      (EcBoundaryExtrapolateToken,                "extrapolate")
      (EcBoundaryLimitToken,                      "limit")
      (EcSearchBisectionToken,                    "bisection")
      (EcSearchEqualToken,                        "equal_spaced")
      (EcSearchLinearToken,                       "linear")
   )
}

#endif // ecFunctionTokens_H_
