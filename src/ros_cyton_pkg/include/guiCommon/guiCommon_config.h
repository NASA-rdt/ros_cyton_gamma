#ifndef guiCommon_config_H_
#define guiCommon_config_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file guiCommon_config.h
/// @brief Configuration header for the guiCommon hierarchy.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>

/// Specify an overall define to see if guiCommon is being built dynamically.
#if defined(EC_BUILD_SHARED_LIBS)
#  define EC_GUICOMMON_COMMON_CONTROLS_DYNAMIC_LIBS
#  define EC_GUICOMMON_ACTUATORDB_DYNAMIC_LIBS
#  define EC_GUICOMMON_DRAGGER_DYNAMIC_LIBS
#  define EC_GUICOMMON_LOADER_DYNAMIC_LIBS
#  define EC_GUICOMMON_SHAREDMEMORY_DYNAMIC_LIBS
#  define EC_GUICOMMON_SLOTMANAGER_DYNAMIC_LIBS
#  define EC_GUICOMMON_VIEWERCORE_DYNAMIC_LIBS
#endif // defined(EC_BUILD_SHARED_LIBS)

/// commonControls directory
#if defined(EC_GUICOMMON_COMMON_CONTROLS_DYNAMIC_LIBS)
#  if defined(guiCommon_commonControls_EXPORTS)
#    define EC_GUICOMMON_COMMON_CONTROLS_DECL              EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_COMMON_CONTROLS_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_COMMON_CONTROLS_DYNAMIC_LIBS)
#  define EC_GUICOMMON_COMMON_CONTROLS_DECL
#endif // defined(EC_GUICOMMON_COMMON_CONTROLS_DYNAMIC_LIBS)

/// Image segementation UI directory
#if defined(EC_GUICOMMON_IMAGE_SEGMENATION_DYNAMIC_LIBS)
#  if defined(guiCommon_Image_Segmentation_EXPORTS)
#    define EC_GUICOMMON_IMAGE_SEGMENATION_DECL              EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_IMAGE_SEGMENATION_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_IMAGE_SEGMENATION_DYNAMIC_LIBS)
#  define EC_GUICOMMON_IMAGE_SEGMENATION_DECL
#endif // defined(EC_GUICOMMON_IMAGE_SEGMENATION_DYNAMIC_LIBS)

/// automated inspection UI directory
#if defined(EC_GUICOMMON_AUTOMATED_INSPECTION_GUI_DYNAMIC_LIBS)
#  if defined(guiCommon_automatedInspectionGUI_EXPORTS)
#    define EC_GUICOMMON_AUTOMATED_INSPECTION_GUI_DECL              EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_AUTOMATED_INSPECTION_GUI_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_AUTOMATED_INSPECTION_GUI_DYNAMIC_LIBS)
#  define EC_GUICOMMON_AUTOMATED_INSPECTION_GUI_DECL
#endif // defined(EC_GUICOMMON_AUTOMATED_INSPECTION_GUI_DYNAMIC_LIBS)


EC_GUICOMMON_IMAGE_SEGMENATION_DECL

/// actuatorDatabase directory
#if defined(EC_GUICOMMON_ACTUATORDB_DYNAMIC_LIBS)
#  if defined(guiCommon_actuatorDatabase_EXPORTS)
#    define EC_GUICOMMON_ACTUATORDB_DECL              EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_ACTUATORDB_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_ACTUATORDB_DYNAMIC_LIBS)
#  define EC_GUICOMMON_ACTUATORDB_DECL
#endif // defined(EC_GUICOMMON_ACTUATORDB_DYNAMIC_LIBS)

/// dragger directory
#if defined(EC_GUICOMMON_DRAGGER_DYNAMIC_LIBS)
#  if defined(guiCommon_dragger_EXPORTS)
#    define EC_GUICOMMON_DRAGGER_DECL                 EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_DRAGGER_DECL                 EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_DRAGGER_DYNAMIC_LIBS)
#  define EC_GUICOMMON_DRAGGER_DECL
#endif // defined(EC_GUICOMMON_DRAGGER_DYNAMIC_LIBS)

/// loader directory
#if defined(EC_GUICOMMON_LOADER_DYNAMIC_LIBS)
#  if defined(guiCommon_loader_EXPORTS)
#    define EC_GUICOMMON_LOADER_DECL                  EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_LOADER_DECL                  EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_LOADER_DYNAMIC_LIBS)
#  define EC_GUICOMMON_LOADER_DECL
#endif // defined(EC_GUICOMMON_LOADER_DYNAMIC_LIBS)

/// sharedMemory directory
#if defined(EC_GUICOMMON_SHAREDMEMORY_DYNAMIC_LIBS)
#  if defined(guiCommon_sharedMemory_EXPORTS)
#    define EC_GUICOMMON_SHAREDMEMORY_DECL            EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_SHAREDMEMORY_DECL            EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_SHAREDMEMORY_DYNAMIC_LIBS)
#  define EC_GUICOMMON_SHAREDMEMORY_DECL
#endif // defined(EC_GUICOMMON_SHAREDMEMORY_DYNAMIC_LIBS)

/// slotManager directory
#if defined(EC_GUICOMMON_SLOTMANAGER_DYNAMIC_LIBS)
#  if defined(guiCommon_slotManager_EXPORTS)
#    define EC_GUICOMMON_SLOTMANAGER_DECL             EC_DECL_EXPORTS
#  else
#    define EC_GUICOMMON_SLOTMANAGER_DECL             EC_DECL_IMPORTS
#  endif
#else  // defined(EC_GUICOMMON_SLOTMANAGER_DYNAMIC_LIBS)
#  define EC_GUICOMMON_SLOTMANAGER_DECL
#endif // defined(EC_GUICOMMON_SLOTMANAGER_DYNAMIC_LIBS)

/// viewerCore directory
#if defined(EC_GUICOMMON_VIEWERCORE_DYNAMIC_LIBS)
#  if defined(guiCommon_viewerCore_EXPORTS)
#    define EC_GUICOMMON_VIEWERCORE_DECL              EC_DECL_EXPORTS
#    define EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL  extern
#  else
#    define EC_GUICOMMON_VIEWERCORE_DECL              EC_DECL_IMPORTS
#    define EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL
#  endif
#else  // defined(EC_GUICOMMON_VIEWERCORE_DYNAMIC_LIBS)
#  if defined(guiCommon_viewerCore_EXPORTS)
#    define EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL  extern
#  else
#    define EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL
#  endif
#  define EC_GUICOMMON_VIEWERCORE_DECL
#endif // defined(EC_GUICOMMON_VIEWERCORE_DYNAMIC_LIBS)

#endif // guiCommon_config_H_
