#ifndef sensor_config_H_
#define sensor_config_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file sensor_config.h
/// @brief Configuration header for the sensor hierarchy.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>

/// Specify an overall define when sensor is being built dynamically.
/// There are circular dependencies which limit the amount of shared
/// libraries that can be built.
#if defined(EC_BUILD_SHARED_LIBS)
#  define EC_SENSOR_BLOBANALYSIS_DYNAMIC_LIBS
#  define EC_SENSOR_COLORDATAPLOT_DYNAMIC_LIBS
#  define EC_SENSOR_EDGEANALYSIS_DYNAMIC_LIBS
#  define EC_SENSOR_FEATUREANALYSIS_DYNAMIC_LIBS
#  define EC_SENSOR_IMAGE_DYNAMIC_LIBS
#  define EC_SENSOR_IMAGECAPTURE_DYNAMIC_LIBS
#  define EC_SENSOR_IMAGEFILTER_DYNAMIC_LIBS
#  define EC_SENSOR_IMAGEPIPELINE_DYNAMIC_LIBS
#  define EC_SENSOR_IMAGEPROCESSING_DYNAMIC_LIBS
#  define EC_SENSOR_IMAGETRANSFORM_DYNAMIC_LIBS
#  define EC_SENSOR_JPEGLIB_DYNAMIC_LIBS
#  define EC_SENSOR_RENDER_DYNAMIC_LIBS
#  define EC_SENSOR_SENSCORE_DYNAMIC_LIBS
#  define EC_SENSOR_SENSMEAS_DYNAMIC_LIBS
#  define EC_SENSOR_TEMPLATEMATCH_DYNAMIC_LIBS
#  define EC_SENSOR_OBJECTDETECTION_DYNAMIC_LIBS
#endif // defined(EC_BUILD_SHARED_LIBS)

/// blobAnalysis directory
#if defined(EC_SENSOR_BLOBANALYSIS_DYNAMIC_LIBS)
#  if defined(sensor_blobAnalysis_EXPORTS)
#    define EC_SENSOR_BLOBANALYSIS_DECL          EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_BLOBANALYSIS_DECL          EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_BLOBANALYSIS_DYNAMIC_LIBS)
#  define EC_SENSOR_BLOBANALYSIS_DECL
#endif // defined(EC_SENSOR_BLOBANALYSIS_DYNAMIC_LIBS)

/// edgeAnalysis directory
#if defined(EC_SENSOR_EDGEANALYSIS_DYNAMIC_LIBS)
#  if defined(sensor_edgeAnalysis_EXPORTS)
#    define EC_SENSOR_EDGEANALYSIS_DECL          EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_EDGEANALYSIS_DECL          EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_EDGEANALYSIS_DYNAMIC_LIBS)
#  define EC_SENSOR_EDGEANALYSIS_DECL
#endif // defined(EC_SENSOR_EDGEANALYSIS_DYNAMIC_LIBS)

/// featureAnalysis directory
#if defined(EC_SENSOR_FEATUREANALYSIS_DYNAMIC_LIBS)
#  if defined(sensor_featureAnalysis_EXPORTS)
#    define EC_SENSOR_FEATUREANALYSIS_DECL       EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_FEATUREANALYSIS_DECL       EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_FEATUREANALYSIS_DYNAMIC_LIBS)
#  define EC_SENSOR_FEATUREANALYSIS_DECL
#endif // defined(EC_SENSOR_FEATUREANALYSIS_DYNAMIC_LIBS)

/// image project within sensCore directory
#if defined(EC_SENSOR_IMAGE_DYNAMIC_LIBS)
#  if defined(sensor_image_EXPORTS)
#    define EC_SENSOR_IMAGE_DECL                 EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_IMAGE_DECL                 EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_IMAGE_DYNAMIC_LIBS)
#  define EC_SENSOR_IMAGE_DECL
#endif // defined(EC_SENSOR_IMAGE_DYNAMIC_LIBS)

/// imageCapture directory
#if defined(EC_SENSOR_IMAGECAPTURE_DYNAMIC_LIBS)
#  if defined(sensor_imageCapture_EXPORTS)
#    define EC_SENSOR_IMAGECAPTURE_DECL          EC_DECL_EXPORTS
#    define EC_SENSOR_IMAGECAPTURE_PRETEMPLATE_DECL  extern
#  else
#    define EC_SENSOR_IMAGECAPTURE_DECL          EC_DECL_IMPORTS
#    define EC_SENSOR_IMAGECAPTURE_PRETEMPLATE_DECL
#  endif
#else  // defined(EC_SENSOR_IMAGECAPTURE_DYNAMIC_LIBS)
#  define EC_SENSOR_IMAGECAPTURE_DECL
#  define EC_SENSOR_IMAGECAPTURE_PRETEMPLATE_DECL
#endif // defined(EC_SENSOR_IMAGECAPTURE_DYNAMIC_LIBS)

/// imageFilter directory
#if defined(EC_SENSOR_IMAGEFILTER_DYNAMIC_LIBS)
#  if defined(sensor_imageFilter_EXPORTS)
#    define EC_SENSOR_IMAGEFILTER_DECL           EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_IMAGEFILTER_DECL           EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_IMAGEFILTER_DYNAMIC_LIBS)
#  define EC_SENSOR_IMAGEFILTER_DECL
#endif // defined(EC_SENSOR_IMAGEFILTER_DYNAMIC_LIBS)

/// imagePipeline directory
#if defined(EC_SENSOR_IMAGEPIPELINE_DYNAMIC_LIBS)
#  if defined(sensor_imagePipeline_EXPORTS)
#    define EC_SENSOR_IMAGEPIPELINE_DECL         EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_IMAGEPIPELINE_DECL         EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_IMAGEPIPELINE_DYNAMIC_LIBS)
#  define EC_SENSOR_IMAGEPIPELINE_DECL
#endif // defined(EC_SENSOR_IMAGEPIPELINE_DYNAMIC_LIBS)

/// imageProcessing directories
#if defined(EC_SENSOR_IMAGEPROCESSING_DYNAMIC_LIBS)
#  if defined(sensor_imageProcessing_EXPORTS)
#    define EC_SENSOR_IMAGEPROCESSING_DECL       EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_IMAGEPROCESSING_DECL       EC_DECL_IMPORTS
#  endif
#else
#  define EC_SENSOR_IMAGEPROCESSING_DECL
#endif

/// imageTransform directory
#if defined(EC_SENSOR_IMAGETRANSFORM_DYNAMIC_LIBS)
#  if defined(sensor_imageTransform_EXPORTS)
#    define EC_SENSOR_IMAGETRANSFORM_DECL        EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_IMAGETRANSFORM_DECL        EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_IMAGETRANSFORM_DYNAMIC_LIBS)
#  define EC_SENSOR_IMAGETRANSFORM_DECL
#endif // defined(EC_SENSOR_IMAGETRANSFORM_DYNAMIC_LIBS)

/// jpegLib directory
#if defined(EC_SENSOR_JPEGLIB_DYNAMIC_LIBS)
#  if defined(sensor_jpegLib_EXPORTS)
#    define EC_SENSOR_JPEGLIB_DECL               EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_JPEGLIB_DECL               EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_JPEGLIB_DYNAMIC_LIBS)
#  define EC_SENSOR_JPEGLIB_DECL
#endif // defined(EC_SENSOR_JPEGLIB_DYNAMIC_LIBS)

/// render directory
#if defined(EC_SENSOR_RENDER_DYNAMIC_LIBS)
#  if defined(sensor_render_EXPORTS)
#    define EC_SENSOR_RENDER_DECL                EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_RENDER_DECL                EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_RENDER_DYNAMIC_LIBS)
#  define EC_SENSOR_RENDER_DECL
#endif // defined(EC_SENSOR_RENDER_DYNAMIC_LIBS)

/// sensCore directory
#if defined(EC_SENSOR_SENSCORE_DYNAMIC_LIBS)
#  if defined(sensor_sensCore_EXPORTS)
#    define EC_SENSOR_SENSCORE_DECL              EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_SENSCORE_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_SENSCORE_DYNAMIC_LIBS)
#  define EC_SENSOR_SENSCORE_DECL
#endif // defined(EC_SENSOR_SENSCORE_DYNAMIC_LIBS)

/// sensMeas directory
#if defined(EC_SENSOR_SENSMEAS_DYNAMIC_LIBS)
#  if defined(sensor_sensMeas_EXPORTS)
#    define EC_SENSOR_SENSMEAS_DECL              EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_SENSMEAS_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_SENSMEAS_DYNAMIC_LIBS)
#  define EC_SENSOR_SENSMEAS_DECL
#endif // defined(EC_SENSOR_SENSMEAS_DYNAMIC_LIBS)

/// colorDataPlot directory
#if defined(EC_SENSOR_COLORDATAPLOT_DYNAMIC_LIBS)
#  if defined(sensor_colorDataPlot_EXPORTS)
#    define EC_SENSOR_COLORDATAPLOT_DECL              EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_COLORDATAPLOT_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_COLORDATAPLOT_DYNAMIC_LIBS)
#  define EC_SENSOR_COLORDATAPLOT_DECL
#endif // defined(EC_SENSOR_COLORDATAPLOT_DYNAMIC_LIBS)

/// templateMatch directory
#if defined(EC_SENSOR_TEMPLATEMATCH_DYNAMIC_LIBS)
#  if defined(sensor_templateMatch_EXPORTS)
#    define EC_SENSOR_TEMPLATEMATCH_DECL              EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_TEMPLATEMATCH_DECL              EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_TEMPLATEMATCH_DYNAMIC_LIBS)
#  define EC_SENSOR_TEMPLATEMATCH_DECL
#endif // defined(EC_SENSOR_TEMPLATEMATCH_DYNAMIC_LIBS)

/// object detection directory
#if defined(EC_SENSOR_OBJECTDETECTION_DYNAMIC_LIBS)
#  if defined(sensor_objectDetection_EXPORTS)
#    define EC_SENSOR_OBJECTDETECTION_DECL          EC_DECL_EXPORTS
#  else
#    define EC_SENSOR_OBJECTDETECTION_DECL          EC_DECL_IMPORTS
#  endif
#else  // defined(EC_SENSOR_OBJECTDETECTION_DYNAMIC_LIBS)
#  define EC_SENSOR_OBJECTDETECTION_DECL
#endif // defined(EC_SENSOR_OBJECTDETECTION_DYNAMIC_LIBS)

#endif // sensor_config_H_
