#ifndef actin_config_H_
#define actin_config_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file actin_config.h
/// @brief Configuration header for the actin hierarchy.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>

/// Specify an overall define when actin is being built dynamically.
/// There are circular dependencies which limit the amount of shared
/// libraries that can be built.
#if defined(EC_BUILD_SHARED_LIBS)
#  define EC_ACTIN_CONTROL_DYNAMIC_LIBS
#  define EC_ACTIN_CONVERTSIMULATION_DYNAMIC_LIBS
#  define EC_ACTIN_FORCECONTROL_DYNAMIC_LIBS
#  define EC_ACTIN_GRASPING_DYNAMIC_LIBS
#  define EC_ACTIN_HWPLUGIN_DYNAMIC_LIBS
#  define EC_ACTIN_INTERFACE_DYNAMIC_LIBS
#  define EC_ACTIN_MANIPULATION_DYNAMIC_LIBS
#  define EC_ACTIN_MANIPULATIONDIRECTOR_DYNAMIC_LIBS
//#  define EC_ACTIN_MEASURE_DYNAMIC_LIBS
#  define EC_ACTIN_PLUGINS_DYNAMIC_LIBS
#  define EC_ACTIN_SIMULATION_DYNAMIC_LIBS
//#  define EC_ACTIN_SIMULATIONANALYSIS_DYNAMIC_LIBS
#  define EC_ACTIN_SIMULATIONSTUDY_DYNAMIC_LIBS
#  define EC_ACTIN_SOILMECHANICS_DYNAMIC_LIBS
//#  define EC_ACTIN_WALKING_DYNAMIC_LIBS
#endif // defined(EC_BUILD_SHARED_LIBS)

/// control directory
#if defined(EC_ACTIN_CONTROL_DYNAMIC_LIBS)
#  if defined(actin_control_EXPORTS)
#    define EC_ACTIN_CONTROL_DECL              EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_CONTROL_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_CONTROL_DYNAMIC_LIBS)
#  define EC_ACTIN_CONTROL_DECL
#endif // defined(EC_ACTIN_CONTROL_DYNAMIC_LIBS)

/// convertSimulation directory
#if defined(EC_ACTIN_CONVERTSIMULATION_DYNAMIC_LIBS)
#  if defined(actin_convertSimulation_EXPORTS)
#    define EC_ACTIN_CONVERTSIMULATION_DECL    EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_CONVERTSIMULATION_DECL    EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_CONVERTSIMULATION_DYNAMIC_LIBS)
#  define EC_ACTIN_CONVERTSIMULATION_DECL
#endif // defined(EC_ACTIN_CONVERTSIMULATION_DYNAMIC_LIBS)

/// forceControl directory
#if defined(EC_ACTIN_FORCECONTROL_DYNAMIC_LIBS)
#  if defined(actin_forceControl_EXPORTS)
#    define EC_ACTIN_FORCECONTROL_DECL         EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_FORCECONTROL_DECL         EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_FORCECONTROL_DYNAMIC_LIBS)
#  define EC_ACTIN_FORCECONTROL_DECL
#endif // defined(EC_ACTIN_FORCECONTROL_DYNAMIC_LIBS)

/// grasping directory
#if defined(EC_ACTIN_GRASPING_DYNAMIC_LIBS)
#  if defined(actin_grasping_EXPORTS)
#    define EC_ACTIN_GRASPING_DECL             EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_GRASPING_DECL             EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_GRASPING_DYNAMIC_LIBS)
#  define EC_ACTIN_GRASPING_DECL
#endif // defined(EC_ACTIN_GRASPING_DYNAMIC_LIBS)

/// hardwarePlugin directory
#if defined(EC_ACTIN_HWPLUGIN_DYNAMIC_LIBS)
#  if defined(actin_hardwarePlugin_EXPORTS)
#    define EC_ACTIN_HWPLUGIN_DECL             EC_DECL_EXPORTS
#    define EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL extern              ///< Actin hardware plugin pretemplate declaration
#  else
#    define EC_ACTIN_HWPLUGIN_DECL             EC_DECL_IMPORTS
#    define EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL                     ///< Actin hardware plugin pretemplate declaration
#  endif
#else  // defined(EC_ACTIN_HWPLUGIN_DYNAMIC_LIBS)
#  define EC_ACTIN_HWPLUGIN_DECL
#  define EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL                       ///< Actin hardware plugin pretemplate declaration
#endif // defined(EC_ACTIN_HWPLUGIN_DYNAMIC_LIBS)

/// interface directory
#if defined(EC_ACTIN_INTERFACE_DYNAMIC_LIBS)
#  if defined(actin_interface_EXPORTS)
#    define EC_ACTIN_INTERFACE_DECL            EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_INTERFACE_DECL            EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_INTERFACE_DYNAMIC_LIBS)
#  define EC_ACTIN_INTERFACE_DECL
#endif // defined(EC_ACTIN_INTERFACE_DYNAMIC_LIBS)

/// manipulation directory
#if defined(EC_ACTIN_MANIPULATION_DYNAMIC_LIBS)
#  if defined(actin_manipulation_EXPORTS)
#    define EC_ACTIN_MANIPULATION_DECL         EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_MANIPULATION_DECL         EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_MANIPULATION_DYNAMIC_LIBS)
#  define EC_ACTIN_MANIPULATION_DECL
#endif // defined(EC_ACTIN_MANIPULATION_DYNAMIC_LIBS)

/// manipulationDirector directory
#if defined(EC_ACTIN_MANIPULATIONDIRECTOR_DYNAMIC_LIBS)
#  if defined(actin_manipulationDirector_EXPORTS)
#    define EC_ACTIN_MANIPULATIONDIRECTOR_DECL EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_MANIPULATIONDIRECTOR_DECL EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_MANIPULATIONDIRECTOR_DYNAMIC_LIBS)
#  define EC_ACTIN_MANIPULATIONDIRECTOR_DECL
#endif // defined(EC_ACTIN_MANIPULATIONDIRECTOR_DYNAMIC_LIBS)

/// measure directory
#if defined(EC_ACTIN_MEASURE_DYNAMIC_LIBS)
#  if defined(actin_measure_EXPORTS)
#    define EC_ACTIN_MEASURE_DECL              EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_MEASURE_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_MEASURE_DYNAMIC_LIBS)
#  define EC_ACTIN_MEASURE_DECL
#endif // defined(EC_ACTIN_MEASURE_DYNAMIC_LIBS)

/// plugins directory
#if defined(EC_ACTIN_PLUGINS_DYNAMIC_LIBS)
#  if defined(actin_plugins_EXPORTS)
#    define EC_ACTIN_PLUGINS_DECL              EC_DECL_EXPORTS
#    define EC_ACTIN_PLUGINS_PRETEMPLATE_DECL  extern
#  else
#    define EC_ACTIN_PLUGINS_DECL              EC_DECL_IMPORTS
#    define EC_ACTIN_PLUGINS_PRETEMPLATE_DECL
#  endif
#else  // defined(EC_ACTIN_PLUGINS_DYNAMIC_LIBS)
#  define EC_ACTIN_PLUGINS_DECL
#  define EC_ACTIN_PLUGINS_PRETEMPLATE_DECL
#endif // defined(EC_ACTIN_PLUGINS_DYNAMIC_LIBS)

/// simulation directory
#if defined(EC_ACTIN_SIMULATION_DYNAMIC_LIBS)
#  if defined(actin_simulation_EXPORTS)
#    define EC_ACTIN_SIMULATION_DECL           EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_SIMULATION_DECL           EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_SIMULATION_DYNAMIC_LIBS)
#  define EC_ACTIN_SIMULATION_DECL
#endif // defined(EC_ACTIN_SIMULATION_DYNAMIC_LIBS)

/// simulationAnalysis directory
#if defined(EC_ACTIN_SIMULATIONANALYSIS_DYNAMIC_LIBS)
#  if defined(actin_simulationAnalysis_EXPORTS)
#    define EC_ACTIN_SIMULATIONANALYSIS_DECL   EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_SIMULATIONANALYSIS_DECL   EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_SIMULATIONANALYSIS_DYNAMIC_LIBS)
#  define EC_ACTIN_SIMULATIONANALYSIS_DECL
#endif // defined(EC_ACTIN_SIMULATIONANALYSIS_DYNAMIC_LIBS)

/// simulationStudy directory
#if defined(EC_ACTIN_SIMULATIONSTUDY_DYNAMIC_LIBS)
#  if defined(actin_simulationStudy_EXPORTS)
#    define EC_ACTIN_SIMULATIONSTUDY_DECL      EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_SIMULATIONSTUDY_DECL      EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_SIMULATIONSTUDY_DYNAMIC_LIBS)
#  define EC_ACTIN_SIMULATIONSTUDY_DECL
#endif // defined(EC_ACTIN_SIMULATIONSTUDY_DYNAMIC_LIBS)

/// soilMechanics directory
#if defined(EC_ACTIN_SOILMECHANICS_DYNAMIC_LIBS)
#  if defined(actin_soilMechanics_EXPORTS)
#    define EC_ACTIN_SOILMECHANICS_DECL        EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_SOILMECHANICS_DECL        EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_SOILMECHANICS_DYNAMIC_LIBS)
#  define EC_ACTIN_SOILMECHANICS_DECL
#endif // defined(EC_ACTIN_SOILMECHANICS_DYNAMIC_LIBS)

/// walking directory
#if defined(EC_ACTIN_WALKING_DYNAMIC_LIBS)
#  if defined(actin_walking_EXPORTS)
#    define EC_ACTIN_WALKING_DECL              EC_DECL_EXPORTS
#  else
#    define EC_ACTIN_WALKING_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_ACTIN_WALKING_DYNAMIC_LIBS)
#  define EC_ACTIN_WALKING_DECL
#endif // defined(EC_ACTIN_WALKING_DYNAMIC_LIBS)

#endif // actin_config_H
