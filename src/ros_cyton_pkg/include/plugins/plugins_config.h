#ifndef plugins_config_H_
#define plugins_config_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file plugins_config.h
/// @brief Configuration header for the plugins hierarchy.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>

/// dataPlotPlugin directory
#if defined(plugins_dataPlotPlugin_EXPORTS)
#  define EC_PLUGINS_DATAPLOT_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_DATAPLOT_DECL EC_DECL_IMPORTS
#endif

#if defined(WIN32) && defined(plugins_ddsCommonOddsPlugin_EXPORTS)
#  define EC_PLUGINS_DDSCOMMONPLUGIN_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_DDSCOMMONPLUGIN_DECL EC_DECL_IMPORTS
#endif

#if defined(WIN32) && defined(plugins_ddsPubSubOddsPlugin_EXPORTS)
#  define EC_PLUGINS_DDSPUBSUBPLUGIN_DECL EC_DECL_EXPORTS
#elif defined(WIN32) && defined(plugins_ddsPubSubOsplPlugin_EXPORTS)
#  define EC_PLUGINS_DDSPUBSUBPLUGIN_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_DDSPUBSUBPLUGIN_DECL EC_DECL_IMPORTS
#endif

/// endEffectorControlPlugin directory
#if defined(plugins_endEffectorControlPlugin_EXPORTS)
#  define EC_PLUGINS_ENDEFFECTORCONTROL_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_ENDEFFECTORCONTROL_DECL EC_DECL_IMPORTS
#endif

/// graspEvalulationPlugin directory
#if defined(plugins_graspEvaluationPlugin_EXPORTS)
#  define EC_PLUGINS_GRASPEVALUATION_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_GRASPEVALUATION_DECL EC_DECL_IMPORTS
#endif

/// graspSequenceExecPlugin directory
#if defined(plugins_graspSequenceExecPlugin_EXPORTS)
#  define EC_PLUGINS_GRASPSEQUENCEEXEC_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_GRASPSEQUENCEEXEC_DECL EC_DECL_IMPORTS
#endif

/// joystickPlugin directory
#if defined(plugins_joystickPlugin_EXPORTS)
#  define EC_PLUGINS_JOYSTICK_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_JOYSTICK_DECL EC_DECL_IMPORTS
#endif

/// linkStatePlugin directory
#if defined(plugins_linkStatePlugin_EXPORTS)
#  define EC_PLUGINS_LINKSTATE_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_LINKSTATE_DECL EC_DECL_IMPORTS
#endif

/// logPlugin directory
#if defined(plugins_logPlugin_EXPORTS)
#  define EC_PLUGINS_LOG_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_LOG_DECL EC_DECL_IMPORTS
#endif

/// manipulatorConfigPlugin directory
#if defined(plugins_manipulatorConfigPlugin_EXPORTS)
#  define EC_PLUGINS_MANIPULATORCONFIG_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_MANIPULATORCONFIG_DECL EC_DECL_IMPORTS
#endif

/// manipulationDirectorExecPlugin directory
#if defined(plugins_manipulationDirectorExecPlugin_EXPORTS)
#  define EC_PLUGINS_MANIPULATIONDIRECTOREXEC_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_MANIPULATIONDIRECTOREXEC_DECL EC_DECL_IMPORTS
#endif

/// manipulationSequenceExecPlugin directory
#if defined(plugins_manipulationSequenceExecPlugin_EXPORTS)
#  define EC_PLUGINS_MANIPULATIONSEQUENCEEXEC_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_MANIPULATIONSEQUENCEEXEC_DECL EC_DECL_IMPORTS
#endif

/// massPropertiesPlugin directory
#if defined(plugins_massPropertiesPlugin_EXPORTS)
#  define EC_PLUGINS_MASSPROPERTIES_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_MASSPROPERTIES_DECL EC_DECL_IMPORTS
#endif

/// shapePrimitivePlugin directory
#if defined(plugins_shapePrimitivePlugin_EXPORTS)
#  define EC_PLUGINS_SHAPEPRIMITIVE_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_SHAPEPRIMITIVE_DECL EC_DECL_IMPORTS
#endif

/// xmlTreePlugin directory
#if defined(plugins_xmlTreePlugin_EXPORTS)
#  define EC_PLUGINS_XMLTREE_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_XMLTREE_DECL EC_DECL_IMPORTS
#endif

#endif // plugins_config_H_
