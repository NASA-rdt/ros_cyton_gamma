#ifndef ecRelativeEndEffectorTool_H_
#define ecRelativeEndEffectorTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecRelativeEndEffectorTool.h
/// @class EcRelativeEndEffectorTool
/// @brief Provides a tool for calculating relative end effector placement.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <manipulator/ecManipActiveState.h>

// forward declarations
class EcEndEffectorSet;
class EcIndividualManipulator;
class EcManipulatorEndEffectorPlacement;

/// type definition of XML vector of EcIndividualManipulator
typedef EcXmlVectorType<EcIndividualManipulator> EcIndividualManipulatorVector;

/// Provides tool to convert end-effector placement from system coordinates to
/// relative coordinates and vice versa
class EC_ACTIN_CONTROL_DECL EcRelativeEndEffectorTool
{
public:
   /// Converts the end-effector placement from system coordinates to
   /// relative coordinates at a given position state specified in the active states.
   /**
    * @param[in] endEffectorIndex The end-effector index
    * @param[in] systemPlacement The end-effector placement in system coordinates
    * @param[in] endEffectorSet The end-effector set
    * @param[in] manipulatorIndex The manipulator index
    * @param[in] manipulators The manipulators
    * @param[in, out] activeStates The active states
    * @param[out] relativePlacement The computed end-effector placement in relative coordinates.
    *       If the end-effector is not of link-relative type, then it's the same as systemPlacement.
    * @return True if successful (all indices are valid) or false otherwise.
    */
   static EcBoolean convertPlacementFromSystemToRelative
      (
      EcU32 endEffectorIndex,
      const EcCoordinateSystemTransformation& systemPlacement,
      const EcEndEffectorSet& endEffectorSet,
      EcU32 manipulatorIndex,
      const EcIndividualManipulatorVector& manipulators,
      EcManipulatorActiveStateVector& activeStates,
      EcCoordinateSystemTransformation& relativePlacement
      );

   /// Converts the end-effector placement from relative coordinates to
   /// system coordinates at a given position state specified in the active states.
   /**
    * @param[in] endEffectorIndex The end-effector index
    * @param[in] relativePlacement The end-effector placement in relative coordinates
    * @param[in] endEffectorSet The end-effector set
    * @param[in] manipulatorIndex The manipulator index
    * @param[in] manipulators The manipulators
    * @param[in, out] activeStates The active states
    * @param[out] systemPlacement The computed end-effector placement in system coordinates.
    *       If the end-effector is not of link-relative type, then it's the same as relativePlacement.
    * @return True if successful (all indices are valid) or false otherwise.
    */
   static EcBoolean convertPlacementFromRelativeToSystem
      (
      EcU32 endEffectorIndex,
      const EcCoordinateSystemTransformation& relativePlacement,
      const EcEndEffectorSet& endEffectorSet,
      EcU32 manipulatorIndex,
      const EcIndividualManipulatorVector& manipulators,
      EcManipulatorActiveStateVector& activeStates,
      EcCoordinateSystemTransformation& systemPlacement
      );
};

#endif // ecRelativeEndEffectorTool_H_
