#ifndef foundation_config_H_
#define foundation_config_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file foundation_config.h
/// @brief Configuration header for the foundation hierarchy.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>

/// Specify an overall define to see if foundation is being built dynamically.
#if defined(EC_BUILD_SHARED_LIBS)
#  define EC_FOUNDATION_CLUSTER_DYNAMIC_LIBS
#  define EC_FOUNDATION_CONVERTSYSTEM_DYNAMIC_LIBS
#  define EC_FOUNDATION_DDSAL_DYNAMIC_LIBS
#  define EC_FOUNDATION_DYNAMICSYSTEMS_DYNAMIC_LIBS
#  define EC_FOUNDATION_FOUNDCOMMON_DYNAMIC_LIBS
#  define EC_FOUNDATION_FUNCTION_DYNAMIC_LIBS
// Done in stable/ecConfig because of forward declaration of xml
//#  define EC_FOUNDATION_GEOMETRY_DYNAMIC_LIBS
#  define EC_FOUNDATION_HWINTERFACE_DYNAMIC_LIBS
#  define EC_FOUNDATION_IMAGESENSOR_DYNAMIC_LIBS
#  define EC_FOUNDATION_INPUTDEVICE_DYNAMIC_LIBS
#  define EC_FOUNDATION_MANIPULATOR_DYNAMIC_LIBS
#  define EC_FOUNDATION_PLANARGEOMETRY_DYNAMIC_LIBS
#  define EC_FOUNDATION_TRANSPORT_DYNAMIC_LIBS
#  define EC_FOUNDATION_VISUALIZATION_DYNAMIC_LIBS
#  define EC_FOUNDATION_VRML97_DYNAMIC_LIBS
#  define EC_FOUNDATION_SHAPEPROXIMITY_DYNAMIC_LIBS
#  define EC_FOUNDATION_MANIPULATORPROXIMITY_DYNAMIC_LIBS
#endif // defined(EC_BUILD_SHARED_LIBS)

/// cluster directory
#if defined(EC_FOUNDATION_CLUSTER_DYNAMIC_LIBS)
#  if defined(foundation_cluster_EXPORTS)
#    define EC_FOUNDATION_CLUSTER_DECL                 EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_CLUSTER_DECL                 EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_CLUSTER_DYNAMIC_LIBS)
#  define EC_FOUNDATION_CLUSTER_DECL
#endif // defined(EC_FOUNDATION_CLUSTER_DYNAMIC_LIBS)

/// convertSystem directory
#if defined(EC_FOUNDATION_CONVERTSYSTEM_DYNAMIC_LIBS)
#  if defined(foundation_convertSystem_EXPORTS)
#    define EC_FOUNDATION_CONVERTSYSTEM_DECL           EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_CONVERTSYSTEM_DECL           EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_CONVERTSYSTEM_DYNAMIC_LIBS)
#  define EC_FOUNDATION_CONVERTSYSTEM_DECL
#endif // defined(EC_FOUNDATION_CONVERTSYSTEM_DYNAMIC_LIBS)

/// ddsal directory
#if defined(EC_FOUNDATION_DDSAL_DYNAMIC_LIBS)
#  if defined(foundation_ddsalOdds_EXPORTS)
#    define EC_FOUNDATION_DDSAL_DECL                   EC_DECL_EXPORTS
/// DDSAL pre template declaration
#    define EC_FOUNDATION_DDSAL_PRETEMPLATE_DECL       extern
#  elif defined(foundation_ddsalOspl_EXPORTS)
#    define EC_FOUNDATION_DDSAL_DECL                   EC_DECL_EXPORTS
/// DDSAL pre template declaration
#    define EC_FOUNDATION_DDSAL_PRETEMPLATE_DECL       extern
#  elif defined(foundation_ddsalNdds_EXPORTS)
#    define EC_FOUNDATION_DDSAL_DECL                   EC_DECL_EXPORTS
/// DDSAL pre template declaration
#    define EC_FOUNDATION_DDSAL_PRETEMPLATE_DECL       extern
#  else
#    define EC_FOUNDATION_DDSAL_DECL                   EC_DECL_IMPORTS
#    define EC_FOUNDATION_DDSAL_PRETEMPLATE_DECL
#  endif
#else  // defined(EC_FOUNDATION_DDSAL_DYNAMIC_LIBS)
#  define EC_FOUNDATION_DDSAL_DECL
/// DDSAL pre template declaration
#  define EC_FOUNDATION_DDSAL_PRETEMPLATE_DECL         extern
#endif // defined(EC_FOUNDATION_DDSAL_DYNAMIC_LIBS)

/// dynamicSystems directory
#if defined(EC_FOUNDATION_DYNAMICSYSTEMS_DYNAMIC_LIBS)
#  if defined(foundation_dynamicSystems_EXPORTS)
#    define EC_FOUNDATION_DYNAMICSYSTEMS_DECL          EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_DYNAMICSYSTEMS_DECL          EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_DYNAMICSYSTEMS_DYNAMIC_LIBS)
#  define EC_FOUNDATION_DYNAMICSYSTEMS_DECL
#endif // defined(EC_FOUNDATION_DYNAMICSYSTEMS_DYNAMIC_LIBS)

/// foundCommon directory
#if defined(EC_FOUNDATION_FOUNDCOMMON_DYNAMIC_LIBS)
#  if defined(foundation_foundCommon_EXPORTS)
#    define EC_FOUNDATION_FOUNDCOMMON_DECL             EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_FOUNDCOMMON_DECL             EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_FOUNDCOMMON_DYNAMIC_LIBS)
#  define EC_FOUNDATION_FOUNDCOMMON_DECL
#endif // defined(EC_FOUNDATION_FOUNDCOMMON_DYNAMIC_LIBS)

/// function directory
#if defined(EC_FOUNDATION_FUNCTION_DYNAMIC_LIBS)
#  if defined(foundation_function_EXPORTS)
#    define EC_FOUNDATION_FUNCTION_DECL                EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_FUNCTION_DECL                EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_FUNCTION_DYNAMIC_LIBS)
#  define EC_FOUNDATION_FUNCTION_DECL
#endif // defined(EC_FOUNDATION_FUNCTION_DYNAMIC_LIBS)

/// geometry directory
//#if defined(EC_FOUNDATION_GEOMETRY_DYNAMIC_LIBS)
//#  if defined(foundation_geometry_EXPORTS)
//#    define EC_FOUNDATION_GEOMETRY_DECL              EC_DECL_EXPORTS
//#  else
//#    define EC_FOUNDATION_GEOMETRY_DECL              EC_DECL_IMPORTS
//#  endif
//#else  // defined(EC_FOUNDATION_GEOMETRY_DYNAMIC_LIBS)
//#  define EC_FOUNDATION_GEOMETRY_DECL
//#endif // defined(EC_FOUNDATION_GEOMETRY_DYNAMIC_LIBS)

/// hardwareInterface directory
#if defined(EC_FOUNDATION_HWINTERFACE_DYNAMIC_LIBS)
#  if defined(foundation_hardwareInterface_EXPORTS)
#    define EC_FOUNDATION_HWINTERFACE_DECL             EC_DECL_EXPORTS
/// Foundation hardware interface pre template declaration
#    define EC_FOUNDATION_HWINTERFACE_PRETEMPLATE_DECL extern
#  else
#    define EC_FOUNDATION_HWINTERFACE_DECL             EC_DECL_IMPORTS
/// Foundation hardware interface pre template declaration
#    define EC_FOUNDATION_HWINTERFACE_PRETEMPLATE_DECL
#  endif
#else  // defined(EC_FOUNDATION_HWINTERFACE_DYNAMIC_LIBS)
#  define EC_FOUNDATION_HWINTERFACE_DECL
/// Foundation hardware interface pre template declaration
#  define EC_FOUNDATION_HWINTERFACE_PRETEMPLATE_DECL   extern
#endif // defined(EC_FOUNDATION_HWINTERFACE_DYNAMIC_LIBS)

/// imageSensor directory
#if defined(EC_FOUNDATION_IMAGESENSOR_DYNAMIC_LIBS)
#  if defined(foundation_imageSensor_EXPORTS)
#    define EC_FOUNDATION_IMAGESENSOR_DECL             EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_IMAGESENSOR_DECL             EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_IMAGESENSOR_DYNAMIC_LIBS)
#  define EC_FOUNDATION_IMAGESENSOR_DECL
#endif // defined(EC_FOUNDATION_IMAGESENSOR_DYNAMIC_LIBS)

/// inputDevice directory
#if defined(EC_FOUNDATION_INPUTDEVICE_DYNAMIC_LIBS)
#  if defined(foundation_inputDevice_EXPORTS)
#    define EC_FOUNDATION_INPUTDEVICE_DECL             EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_INPUTDEVICE_DECL             EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_INPUTDEVICE_DYNAMIC_LIBS)
#  define EC_FOUNDATION_INPUTDEVICE_DECL
#endif // defined(EC_FOUNDATION_INPUTDEVICE_DYNAMIC_LIBS)

/// manipulator directory
#if defined(EC_FOUNDATION_MANIPULATOR_DYNAMIC_LIBS)
#  if defined(foundation_manipulator_EXPORTS)
#    define EC_FOUNDATION_MANIPULATOR_DECL             EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_MANIPULATOR_DECL             EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_MANIPULATOR_DYNAMIC_LIBS)
#  define EC_FOUNDATION_MANIPULATOR_DECL
#endif // defined(EC_FOUNDATION_MANIPULATOR_DYNAMIC_LIBS)

/// planarGeometry directory
#if defined(EC_FOUNDATION_PLANARGEOMETRY_DYNAMIC_LIBS)
#  if defined(foundation_planarGeometry_EXPORTS)
#    define EC_FOUNDATION_PLANARGEOMETRY_DECL          EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_PLANARGEOMETRY_DECL          EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_PLANARGEOMETRY_DYNAMIC_LIBS)
#  define EC_FOUNDATION_PLANARGEOMETRY_DECL
#endif // defined(EC_FOUNDATION_PLANARGEOMETRY_DYNAMIC_LIBS)

/// transport directory
#if defined(EC_FOUNDATION_TRANSPORT_DYNAMIC_LIBS)
#  if defined(foundation_transport_EXPORTS)
#    define EC_FOUNDATION_TRANSPORT_DECL               EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_TRANSPORT_DECL               EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_TRANSPORT_DYNAMIC_LIBS)
#  define EC_FOUNDATION_TRANSPORT_DECL
#endif // defined(EC_FOUNDATION_TRANSPORT_DYNAMIC_LIBS)

/// visualization directory
#if defined(EC_FOUNDATION_VISUALIZATION_DYNAMIC_LIBS)
#  if defined(foundation_visualization_EXPORTS)
#    define EC_FOUNDATION_VISUALIZATION_DECL           EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_VISUALIZATION_DECL           EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_VISUALIZATION_DYNAMIC_LIBS)
#  define EC_FOUNDATION_VISUALIZATION_DECL
#endif // defined(EC_FOUNDATION_VISUALIZATION_DYNAMIC_LIBS)

/// vrlm97 directory
#if defined(EC_FOUNDATION_VRML97_DYNAMIC_LIBS)
#  if defined(foundation_vrml97_EXPORTS)
#    define EC_FOUNDATION_VRML97_DECL                  EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_VRML97_DECL                  EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_VRML97_DYNAMIC_LIBS)
#  define EC_FOUNDATION_VRML97_DECL
#endif // defined(EC_FOUNDATION_VRML97_DYNAMIC_LIBS)

/// shape proximity directory
#if defined(EC_FOUNDATION_SHAPEPROXIMITY_DYNAMIC_LIBS)
#  if defined(foundation_shapeProximity_EXPORTS)
#    define EC_FOUNDATION_SHAPEPROXIMITY_DECL             EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_SHAPEPROXIMITY_DECL             EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_SHAPEPROXIMITY_DYNAMIC_LIBS)
#  define EC_FOUNDATION_SHAPEPROXIMITY_DECL
#endif // defined(EC_FOUNDATION_SHAPEPROXIMITY_DYNAMIC_LIBS)

/// manipulator proximity directory
#if defined(EC_FOUNDATION_MANIPULATORPROXIMITY_DYNAMIC_LIBS)
#  if defined(foundation_manipulatorProximity_EXPORTS)
#    define EC_FOUNDATION_MANIPULATORPROXIMITY_DECL   EC_DECL_EXPORTS
#  else
#    define EC_FOUNDATION_MANIPULATORPROXIMITY_DECL   EC_DECL_IMPORTS
#  endif
#else  // defined(EC_FOUNDATION_SHAPE_PROXIMITY_DYNAMIC_LIBS)
#  define EC_FOUNDATION_MANIPULATORPROXIMITY_DECL
#endif // defined(EC_FOUNDATION_SHAPE_PROXIMITY_DYNAMIC_LIBS)

#endif // foundation_config_H_
