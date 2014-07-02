#ifndef ecSimulationConversionTool_H_
#define ecSimulationConversionTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationConversionTool.h
/// @class EcSimulationConversionTool
/// @brief Provides a tool for coverting other formats to XML.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <simulation/ecJointControllerSystem.h>
#include <control/ecPosContSystem.h>
#include <manipulator/ecStatedSystem.h>
#include <simulation/ecSysSimulation.h>
#include <geometry/ecPolygonWithKey.h>

/// Provides a tool for coverting other formats to XML.
class EC_ACTIN_CONVERTSIMULATION_DECL EcSimulationConversionTool
{
public:
   /// default constructor
   EcSimulationConversionTool
      (
      );

   /// destructor
   virtual ~EcSimulationConversionTool
      (
      );

   /// copy constructor
   EcSimulationConversionTool
      (
      const EcSimulationConversionTool& orig
      );

   /// assignment operator
   EcSimulationConversionTool& operator=
      (
      const EcSimulationConversionTool& orig
      );

   /// write out the results after processing
   /**
   \retval error status
   */
   virtual EcBoolean writeResults
      (
      EcBoolean  statedSystemOnly
      );

   /// convert the files
   /**
   \retval error status
   */
   virtual EcBoolean convert
      (
      const EcStringVector& arguments
      );

   /// convert from a point-polygon format
   /**
   \param[in] arguments last string is a basename for a filename
   \retval error status
   */
   virtual EcBoolean convertPointPolygon
      (
      const EcStringVector& arguments
      );

   /// load and convert a point-polygon file from streams
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[in] ppStream stream for point polygons
   \param[out] simulation simulation
   \retval error status
   */
   virtual EcBoolean loadAndConvertPointPolygon
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  ppStream,
      EcSystemSimulation& simulation
      );

   /// load and convert a ase files from streams
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[in] paseStream stream for ASE file
   \param[in] txtrStream stream for texture file
   \param[in] path path to files
   \param[out] simulation simulation
   \retval error status
   */
   virtual EcBoolean loadAndConvertASE
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  paseStream,
      std::ifstream&  txtrStream,
      const EcString& path,
      EcSystemSimulation& simulation
      );

   /// load and convert a 3ds files from streams
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[in] p3dsStream stream for 3DS file
   \param[in] path path to files
   \param[out] simulation simulation
   \retval error status
   */
   virtual EcBoolean loadAndConvert3DS
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  p3dsStream,
      const EcString& path,
      EcSystemSimulation& simulation
      );

   /// convert from ASC format
   /**
   \param[in] arguments last string is a basename for a filename
   \retval error status
   */
   virtual EcBoolean convertASC
      (
      const EcStringVector& arguments
      );

   /// convert from ASE format
   /**
   \param[in] arguments last string is a basename for a filename
   \retval error status
   */
   virtual EcBoolean convertASE
      (
      const EcStringVector& arguments
      );

   /// get a null object
   /**
   \retval simulation conversion tool
   */
   static EcSimulationConversionTool nullObject
      (
      );

protected:
   /// load a point-polygon file from a stream
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[in] ppStream stream for point polygon file
   \retval error status
   */
   virtual EcBoolean loadPointPolygon
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  ppStream
      );

   /// load an asc file from a stream
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[in] pascStream stream for ASC file
   \param[in] txtrStream stream for texture file
   \retval error status
   */
   virtual EcBoolean loadASC
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  pascStream,
      std::ifstream&  txtrStream
      );

   /// load an ase file from a stream
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[in] paseStream stream for ASE file
   \param[in] txtrStream stream for texture file
   \param[in] path path for files
   \retval error status
   */
   virtual EcBoolean loadASE
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  paseStream,
      std::ifstream&  txtrStream,
      const EcString& path
      );

   /// load an ase file from a stream
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[in] p3dsStream stream for 3DS file
   \param[in] path path for files
   \retval error status
   */
   virtual EcBoolean load3DS
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  p3dsStream,
      const EcString& path
      );

   /// recursively load 3DS files
   /**
   \param[in,out] fileDepth depth count on files
   \param[in] filename vector of filenames
   \param[in] parentFilename vector of parent filenames
   \param[in] path path to files
   \param[in] scale scale for model
   \param[in] massPropertiesVector mass properties vector
   \param[in] lkVector link kinematics vector
   \param[in] primaryFrameVector primary frame vector
   \param[in] jointActuatorVector joint actuator vector
   \param[out] manipulator manipulator
   \retval error status
   */
   virtual EcBoolean recursiveManipulatorLoader
      (
      EcU32& fileDepth,
      const EcStringVector& filename,
      const EcStringVector& parentFilename,
      const EcString& path,
      const EcRealVector& scale,
      const EcRigidBodyMassPropertiesVector& massPropertiesVector,
      const std::vector<EcLinkKinematicsContainer>& lkVector,
      const EcCoordinateSystemTransformationVector& primaryFrameVector,
      const EcJointActuatorVector& jointActuatorVector,
      EcIndividualManipulator&  manipulator
      );

   /// load system and state
   /**
   \param[in] sysStream stream for system
   \param[in] stateStream stream for state
   \param[out] dof number of dof
   \param[out] massPropertiesVector mass properties vector
   \param[out] lkVector link kinematics vector
   \param[out] coordinateSystemTransformationVector coordinate system transformation vector
   \param[out] jointActuatorVector joint actuator vector
   \param[out] upGravity up vector
   \param[out] jointPositions joint positions
   \param[out] jointVelocities joint velocities
   \retval error status
   */
   virtual EcBoolean loadSystemAndState
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      EcU32& dof,
      EcRigidBodyMassPropertiesVector& massPropertiesVector,
      std::vector<EcLinkKinematicsContainer>& lkVector,
      EcCoordinateSystemTransformationVector& coordinateSystemTransformationVector,
      EcJointActuatorVector& jointActuatorVector,
      EcVector& upGravity,
      EcRealVector& jointPositions,
      EcRealVector& jointVelocities
      );

   /// read in points and polygons from a point-polygon stream
   /**
   \param[in] pointPolyStream stream for point polygon file
   \param[out] pointCollection point collection
   \param[out] polygonCollection polygon vector
   \retval error status
   */
   virtual EcBoolean readPointsAndPolygons
      (
      std::ifstream&  pointPolyStream,
      EcXmlVectorVector& pointCollection,
      EcPolygonWithKeyVector& polygonCollection
      );

   /// read in points and polygons from an ASC stream
   /**
   \param[in] ascStream stream for ASC file
   \param[out] pointCollection point collection
   \param[out] planarPointCollection planar point collection
   \param[out] polygonCollection polygon vector
   \retval error status
   */
   virtual EcBoolean readASC
      (
      std::ifstream&  ascStream,
      EcXmlVectorVector& pointCollection,
      EcPlanarVectorVector& planarPointCollection,
      EcPolygonWithKeyVector& polygonCollection
      );

   /// read in points and polygons from an ASE stream
   /**
   \param[in] xyzScale xyz scale factor
   \param[in] aseStream stream for ASE file
   \param[out] pointCollection point collection
   \param[out] planarPointCollection planar point collection
   \param[out] polygonCollection polygon vector
   \retval error status
   */
   virtual EcBoolean readASE
      (
      const EcVector& xyzScale,
      std::ifstream&  aseStream,
      EcXmlVectorVector& pointCollection,
      EcPlanarVectorVector& planarPointCollection,
      EcPolygonWithKeyVector& polygonCollection
      );

   /// build a stated system
   /**
   \param[in] massPropertiesVector mass properties vector
   \param[in] lkVector link kinematics vector
   \param[in] primaryFrameVector primary frame vector
   \param[in] jointActuatorVector joint actuator vector
   \param[in] upGravity up vector
   \param[in] jointPositions joint positions
   \param[in] jointVelocities joint velocities
   \param[in] points point collection vector
   \param[in] planarPoints planar point collection vector
   \param[in] polygonsVec polygons vector
   \param[in] textureFilenames texture filename vector
   \retval error status
   */
   virtual EcBoolean buildStatedSystem
      (
      const EcRigidBodyMassPropertiesVector& massPropertiesVector,
      const std::vector<EcLinkKinematicsContainer>& lkVector,
      const EcCoordinateSystemTransformationVector& primaryFrameVector,
      const EcJointActuatorVector& jointActuatorVector,
      const EcVector& upGravity,
      const EcRealVector& jointPositions,
      const EcRealVector& jointVelocities,
      const EcXmlVectorVectorVector& points,
      const EcPlanarVector3D& planarPoints,
      const EcPolygonWithKeyVectorVector& polygonsVec,
      const EcStringVector& textureFilenames
      );

   /// build a system
   /**
   \param[in] massPropertiesVector mass properties vector
   \param[in] lkVector link kinematics vector
   \param[in] primaryFrameVector primary frame vector
   \param[in] jointActuatorVector joint actuator vector
   \param[in] upGravity up vector
   \param[in] points point collection vector
   \param[in] planarPoints planar point collection vector
   \param[in] polygonsVec polygons vector
   \param[in] textureFilenames texture filename vector
   \retval error status
   */
   virtual EcBoolean buildSystem
      (
      const EcRigidBodyMassPropertiesVector& massPropertiesVector,
      const std::vector<EcLinkKinematicsContainer>& lkVector,
      const EcCoordinateSystemTransformationVector& primaryFrameVector,
      const EcJointActuatorVector& jointActuatorVector,
      const EcVector& upGravity,
      const EcXmlVectorVectorVector& points,
      const EcPlanarVector3D& planarPoints,
      const EcPolygonWithKeyVectorVector& polygonsVec,
      const EcStringVector& textureFilenames
      );

   /// build a state
   /**
   \param[in] jointPositions vector of joint positions
   \param[in] jointVelocities vector of joint velocities
   \retval error status
   */
   virtual EcBoolean buildState
      (
      const EcRealVector& jointPositions,
      const EcRealVector& jointVelocities
      );

   /// build a single manipulator
   /**
   \param[in] massPropertiesVector mass properties vector
   \param[in] lkVector link kinematics vector
   \param[in] primaryFrameVector primary frame vector
   \param[in] jointActuatorVector joint actuator vector
   \param[in] points point collection vector
   \param[in] planarPoints planar point collection vector
   \param[in] polygonsVec polygons vector
   \param[in] textureFilenames texture filename vector
   \retval error status
   */
   virtual EcBoolean buildManipulator
      (
      const EcRigidBodyMassPropertiesVector& massPropertiesVector,
      const std::vector<EcLinkKinematicsContainer>& lkVector,
      const EcCoordinateSystemTransformationVector& primaryFrameVector,
      const EcJointActuatorVector& jointActuatorVector,
      const EcXmlVectorVectorVector& points,
      const EcPlanarVector3D& planarPoints,
      const EcPolygonWithKeyVectorVector& polygonsVec,
      const EcStringVector& textureFilenames
      );

   /// build a single link
   /**
   \param[in] massProperties mass properties
   \param[in] linkKinematics link kinematics
   \param[in] primaryFrame primary frame
   \param[in] jointActuator joint actuator
   \param[in] pointCollection point collection
   \param[in] planarPointCollection planar point collection
   \param[in] polygons polygons
   \param[in] textureFilename texture filename
   \param[in] index link index
   \retval manipulator link
   */
   virtual EcManipulatorLink buildLink
      (
      const EcRigidBodyMassProperties& massProperties,
      const EcLinkKinematicsContainer& linkKinematics,
      const EcCoordinateSystemTransformation& primaryFrame,
      const EcJointActuator& jointActuator,
      const EcXmlVectorVector& pointCollection,
      const EcPlanarVectorVector& planarPointCollection,
      const EcPolygonWithKeyVector& polygons,
      const EcString& textureFilename,
      EcU32 index
      );

   /// build a position control system
   /**
   \retval error status
   */
   virtual EcBoolean buildPositionControlSystem
      (
      );

   /// build a joint controller for the system
   /**
   \retval error status
   */
   virtual EcBoolean buildJointControllerSystem
      (
      );

   /// build a dynamic simulator system
   /**
   \retval error status
   */
   virtual EcBoolean buildDynamicSimulatorSystem
      (
      );

   /// build a simulation
   /**
   \retval error status
   */
   virtual EcBoolean buildSimulation
      (
      );

protected:
   EcStringVector             m_Arguments;               ///< last argument is a filename for conversion to XML
   EcRealVector               m_vJointRateLimits;        ///< vector of joint rate limits
   EcStatedSystem             m_StatedSystem;            ///< stated system
   EcManipulatorSystem        m_System;                  ///< manipulator system
   EcManipulatorSystemState   m_State;                   ///< manipulator state
   EcIndividualManipulator    m_IndividualManipulator;   ///< individulat manipulator
   EcPositionControlSystem    m_PositionControlSystem;   ///< position control system
   EcPositionControllerVector m_PositionControllers;     ///< vector of position controllers
   EcJointControllerSystem    m_JointControllerSystem;   ///< joint controller system
   EcDynamicSimulatorSystem   m_DynamicSimulatorSystem;  ///< dynamic simulator system
   EcSystemSimulation         m_Simulation;              ///< system simulation
   EcString                   m_BaseName;                ///< basename for filename
};

#endif // ecSimulationConversionTool_H_
