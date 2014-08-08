#ifndef ecViewerParameters_H_
#define ecViewerParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecViewerParameters.h
/// @class EcViewerParameters
/// @brief Holds a description of paramters to control the GUI viewer.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDataPlotParameters.h"
#include "ecPluginConfigPair.h"
#include <geometry/ecPlane.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>


/// Holds a description of parameters to control the GUI viewer.
class EC_ACTIN_SIMULATION_DECL EcViewerParameters : public EcXmlCompoundType
{
public:
   /// control mode enumeration
   enum {EYEPOINT, ENDEFFECTOR, CENTEROFINTEREST};
   /// xml object methods
   ECXMLOBJECT(EcViewerParameters);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the frame rate
   virtual EcU32 frameRate
      (
      ) const;

   /// sets the frame rate
   virtual void setFrameRate
      (
      EcU32 frameRate
      );

   /// gets the run-on-load flag
   virtual EcBoolean runOnLoad
      (
      ) const;

   /// sets the run-on-load flag
   virtual void setRunOnLoad
      (
      EcBoolean runOnLoad
      );

   /// get initial control mode
   virtual EcU32 initialControlMode
      (
      ) const;

   /// set initial control mode
   virtual void setInitialControlMode
      (
      EcU32 initialControlMode
      );

   /// gets the initially controlled arm (used in end-effector control mode)
   virtual EcU32 initiallyControlledManipulator
      (
      ) const;

   /// sets the initially controlled arm (used in end-effector control mode)
   virtual void setInitiallyControlledManipulator
      (
      EcU32 initiallyControlledManipulator
      );

   /// gets the time scale factor.  When this is 2, for example, the simulation
   /// runs at 2x wall-clock time.
   virtual EcReal timeScaleFactor
      (
      ) const;

   /// sets the time scale factor.
   virtual void setTimeScaleFactor
      (
      EcReal timeScaleFactor
      );

   /// the level in the Bounding Volume Hierarchy (BVH) to render
   /// when bounding volumes are being displayed
   virtual const EcU32& renderableBoundingVolumeLevel
      (
      )const;

   /// the level in the Bounding Volume Hierarchy (BVH) to render
   /// when bounding volumes are being displayed
   virtual void setRenderableBoundingVolumeLevel
      (
      const EcU32& val
      );

   /// gets the data plot parameters
   virtual const EcDataPlotParameters& dataPlotParameters
      (
      ) const;

   /// sets the data plot parameters
   virtual void setDataPlotParameters
      (
      const EcDataPlotParameters& dataPlotParameters
      );

   /// return the directory in which the simulation output files will reside
   virtual const EcString& outputDirectory
      (
      ) const;

   /// set the directory in which the simulation output files will reside
   virtual void setOutputDirectory
      (
      const EcString& dir
      );

   /// return the simulation output files' name without the file extension
   /// the file extension will be automatically added depending on the file formats
   virtual const EcString& outputFileName
      (
      ) const;

   /// set the simulation output files' name without the file extension
   virtual void setOutputFileName
      (
      const EcString& fileName
      );

   /// gets the plane for ZMP calculations
   virtual const EcPlane& zmpPlane
      (
      ) const;

   /// sets the plane for ZMP calculations
   virtual void setZmpPlane
      (
      const EcPlane& plane
      );

   /// Determine whether the plugin list is exclusive or not.  An exclusive
   /// list means that ONLY the entries in the list will be active.
   /// @return EcBoolean Exclusive state of plugin list
   virtual EcBoolean pluginExclusiveFlag
      (
      ) const;

   /// Store the set of plugins and their associated configs
   /// @param[in] vPluginConfigs Vector of name-config pairs
   virtual void setPluginConfigVector
      (
      const std::vector<EcStringStringPair>& vPluginConfigs
      );

   /// Retrieve the complete set of plugins and their configs
   /// @param[out] vPluginConfigs Vector of name-config pairs
   virtual void getPluginConfigVector
      (
      std::vector<EcStringStringPair>& vPluginConfigs
      ) const;

   /// Retrieve the configuration string for this plugin.
   /// @param[in] pluginName Name of plugin to get config from
   /// @return const EcString& Config data or empty string if not found
   EcString pluginConfigString
      (
      const EcString& pluginName
      ) const;

protected:
   /// the visualization frame rate
   EcXmlU32             m_FrameRate;

   /// a flag indicating whether or not to run the simulation on load
   EcXmlBoolean         m_RunOnLoad;

   /// the control mode on start (eyepoint, end-effector, etc.)
   EcXmlEnumU32         m_InitialControlMode;

   /// the initial manipulator to control (used when starting in end-effector mode)
   EcXmlU32             m_InitiallyControlledManipulator;

   /// a scale factor for time.  When this is 2, for example, the simulation runs 2x faster
   /// that wall-clock time.
   EcXmlReal            m_TimeScaleFactor;

   /// the level in the bounding volume hierarchy (BVH) to be rendered
   EcXmlU32             m_RenderableBvLevel;

   /// data plot parameters
   EcDataPlotParameters m_DataPlotParameters;

   /// the directory in which the output files will reside
   EcXmlString          m_OutputDirectory;

   /// the output files' name without the extension
   EcXmlString          m_OutputFileName;

   /// the plane used in ZMP calculations. Must match the surface of the ground plane in the model.
   EcPlane              m_ZmpPlane;

   /// When true, only keeps the plugins in the plugin list loaded
   EcXmlBoolean         m_PluginListExclusive;

   /// Vector of string pairs.  Plugin name and configuration string.
   EcXmlVectorType<EcPluginConfigPair> m_vPluginConfigs;
};

#endif // ecViewerParameters_H_
