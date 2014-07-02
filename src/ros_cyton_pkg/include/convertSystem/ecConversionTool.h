#ifndef ecConversionTool_H_
#define ecConversionTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecConversionTool.h
/// @class EcConversionTool
/// @brief Provides a tool for coverting other formats to XML
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <manipulator/ecStatedSystem.h>
#include <geometry/ecPolygonWithKey.h>
#include "ecVisualizableStatedSystem.h"

/// Provides a tool for coverting other formats to XML
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcConversionTool
{
public:
   /// default constructor
   EcConversionTool
      (
      );

   /// destructor
   virtual ~EcConversionTool
      (
      );

   /// copy constructor
   EcConversionTool
      (
      const EcConversionTool& orig
      );

   /// assignment operator
   EcConversionTool& operator=
      (
      const EcConversionTool& orig
      );

   /*
   /// write out the results after processing
   virtual EcBoolean writeResults
      (
      EcBoolean  statedSystemOnly
      ); */

   /// convert the files
   virtual EcBoolean convert
      (
      const EcStringVector& arguments
      );

   /// convert from a point-polygon format
   virtual EcBoolean convertPointPolygon
      (
      const EcStringVector& arguments
      );

   /// load and convert a point-polygon file from streams
   virtual EcBoolean loadAndConvertPointPolygon
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  ppStream,
      EcVisualizableStatedSystem& visSystem
      );

   /// load and convert a ase files from streams
   virtual EcBoolean loadAndConvertASE
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  paseStream,
      std::ifstream&  txtrStream,
      const EcString& path,
      EcVisualizableStatedSystem& visSystem
      );

   /// load and convert a 3ds files from streams
   virtual EcBoolean loadAndConvert3DS
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  paseStream,
      const EcString& path,
      EcVisualizableStatedSystem& visSystem
      );

   /// convert from ASC format
   virtual EcBoolean convertASC
      (
      const EcStringVector& arguments
      );

   /// convert from ASE format
   virtual EcBoolean convertASE
      (
      const EcStringVector& arguments
      );

   /// get a null object
   static EcConversionTool nullObject
      (
      );

protected:

   /// load a point-polygon file from a stream
   virtual EcBoolean loadPointPolygon
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  ppStream
      );

   /// load an asc file from a stream
   virtual EcBoolean loadASC
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  pascStream,
      std::ifstream&  txtrStream
      );

   /// load an ase file from a stream
   virtual EcBoolean loadASE
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  paseStream,
      std::ifstream&  txtrStream,
      const EcString& path
      );

   /// load an ase file from a stream
   virtual EcBoolean load3DS
      (
      std::ifstream&  sysStream,
      std::ifstream&  stateStream,
      std::ifstream&  p3dsStream,
      const EcString& path
      );

   /// recursively load 3DS files
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
   virtual EcBoolean readPointsAndPolygons
      (
      std::ifstream&  pointPolyStream,
      EcXmlVectorVector& pointCollection,
      EcPolygonWithKeyVector& polygonVec
      );

   /// read in points and polygons from an ASC stream
   virtual EcBoolean readASC
      (
      std::ifstream&  ascStream,
      EcXmlVectorVector& pointCollection,
      EcPlanarVectorVector& planarPointCollection,
      EcPolygonWithKeyVector& polygonCollection
      );

   /// read in points and polygons from an ASE stream
   virtual EcBoolean readASE
      (
      const EcVector& xyzScale,
      std::ifstream&  aseStream,
      EcXmlVectorVector& pointCollection,
      EcPlanarVectorVector& planarPointCollection,
      EcPolygonWithKeyVector& polygonCollection
      );

   /// build a stated system
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

   /*
   /// build a system
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
    */

   /// build a state
   virtual EcBoolean buildState
      (
      const EcRealVector& jointPositions,
      const EcRealVector& jointVelocities
      );

   /// build a single manipulator
   virtual EcBoolean buildManipulator
      (
      const EcRigidBodyMassPropertiesVector& massPropertiesVector,
      const std::vector<EcLinkKinematicsContainer>& lkVector,
      const EcCoordinateSystemTransformationVector& primaryFrameVector,
      const EcJointActuatorVector& jointActuatorVector,
      const EcXmlVectorVectorVector& points,
      const EcPlanarVector3D& planarPoints,
      const EcPolygonWithKeyVectorVector& polygonsVec,
      const EcStringVector& textureFilenames,
      EcIndividualManipulator& manipulator
      );

   /// build a single link
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

   /// Description:  Builds a visualizable stated system.
   virtual EcBoolean buildVisualizableStatedSystem
      (
      );

protected:

   EcStringVector             m_Arguments;               ///< last argument is a filename for conversion to XML
   EcRealVector               m_vJointRateLimits;        ///< vector of joint rate limits
   EcVisualizableStatedSystem m_VisStatedSystem;         ///< visualizable stated system
   EcStatedSystem             m_StatedSystem;            ///< stated system
   EcManipulatorSystem        m_System;                  ///< manipulator system
   EcManipulatorSystemState   m_State;                   ///< manipulator state
   EcIndividualManipulator    m_IndividualManipulator;   ///< individulat manipulator
   EcString                   m_BaseName;                ///< basename for filename
};

#endif // ecConversionTool_H_
