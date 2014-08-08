#ifndef ecCoordinatedJointEndEffectorTool_H_
#define ecCoordinatedJointEndEffectorTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCoordinatedJointEndEffectorTool.h
/// @class EcCoordinatedJointEndEffectorTool
/// @brief Provides a tool for setting EE placement for EcCoordinatedJointEndEffector.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcEndEffectorPlacement;
class EcEndEffectorSet;
class EcIndividualManipulator;
class EcPositionControllerVector;

/// type definition of XML vector of EcIndividualManipulator
typedef EcXmlVectorType<EcIndividualManipulator>   EcIndividualManipulatorVector;

/// This is a utility class for correctly setting the end-effector placement
/// to be used with EcCoordinatedJointEndEffector. Due to the fact that some joints
/// can be constrained joints (i.e. not used for control), therefore we can't simply
/// pass the joint positions directly as the desired joint positions when we want to
/// control the robot in joint control mode.
class EC_ACTIN_CONTROL_DECL EcCoordinatedJointEndEffectorTool
{
public:
   /// configure the tool for multiple manipulators.
   /// @param manips The manipulators in the system
   /// @param controllers The position controllers for the manipulators. This method will use the coordinated joint EE in
   ///      the joint control EE set to configure the tool.
   EcBoolean configure
      (
      const EcIndividualManipulatorVector& manips,
      const EcPositionControllerVector& controllers
      );

   /// configure the tool for a single manipulator. When configured this way, use 0 as manipIndex in all other methods.
   /// @param manip The manipulator
   /// @param eeSet The end-effector set used to configure the tool. Must have a coordinated joint EE as the first EE.
   EcBoolean configure
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorSet& eeSet
      );

   /**
    * @brief setControllableJointPositions resize contJointPositions and set the values with controllable joint values
    * @param manipIndex The manipulator index
    * @param jointPositions The positions of all joints
    * @param contJointPositions The positions of controllable joints
    * @return True
    */
   EcBoolean setControllableJointPositions
      (
      EcU32 manipIndex,
      const EcXmlRealVector& jointPositions,
      EcXmlRealVector& contJointPositions
      ) const;

   /// same as above but with EcRealVector instead of EcXmlRealVector
   EcBoolean setControllableJointPositions
      (
      EcU32 manipIndex,
      const EcXmlRealVector& jointPositions,
      EcRealVector& contJointPositions
      ) const;

   /// set the joint (data) part of the end-effector placement with controllable joint values
   EcBoolean setEndEffectorPlacement
      (
      EcU32 manipIndex,
      const EcXmlRealVector& jointPositions,
      EcEndEffectorPlacement& placement
      ) const;

   /// get the number of controllable joints for a given manipulator
   EcBoolean getNumControllableJoints
      (
      EcU32 manipIndex,
      EcU32 &numControllableJoints
      ) const;

   /// get the indices of controllable joints for a given manipulator
   EcBoolean getControllableJointIndices
      (
      EcU32 manipIndex,
      EcU32Vector &controllableJointIndices
      ) const;

   /// get the unit types of controllable joints for a given manipulator
   /// A joint unit type is either EcLinkKinematics::{LINEAR, ANGULAR, OTHER}
   EcBoolean getControllableJointUnitTypes
      (
      EcU32 manipIndex,
      EcU32Vector &controllableJointUnitTypes
      ) const;
protected:

   /// configure individual manipulator
   EcBoolean configureIndividual
      (
      EcU32 index,
      const EcIndividualManipulator& manip,
      const EcEndEffectorSet& eeSet
      );

   EcU32Vector          m_NumControllableJoints;         ///< number of controllable joints
   EcU32VectorVector    m_ControllableJointIndices;      ///< controllable joint indices
   EcU32VectorVector    m_ControllableJointUnitTypes;    ///< controllable joint unit types
};

#endif // ecCoordinatedJointEndEffectorTool_H_
