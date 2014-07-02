#ifndef ecOsgConversionTool_H_
#define ecOsgConversionTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecOsgConversionTool.h
/// @class EcOsgConversionTool
/// @brief Provides a tool for coverting other formats to XML.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <convertSystem/ecVisualizableStatedSystem.h>
#include <convertSystem/ecConversionTool.h>


/** Provides a tool for coverting other formats to XML.
*/
class EC_RENDER_CONVERT_DECL EcOsgConversionTool : public EcConversionTool
{
public:
   /// default constructor
   EcOsgConversionTool
      (
      );

   /// destructor
   virtual ~EcOsgConversionTool
      (
      );

   /// copy constructor
   EcOsgConversionTool
      (
      const EcOsgConversionTool& orig
      );

   /// assignment operator
   EcOsgConversionTool& operator=
      (
      const EcOsgConversionTool& orig
      );

   /// get a null object
   static EcOsgConversionTool nullObject
      (
      );

protected:
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
};

#endif // ecOsgConversionTool_H_
