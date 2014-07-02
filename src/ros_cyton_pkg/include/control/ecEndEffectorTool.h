#ifndef ecEndEffectorTool_H_
#define ecEndEffectorTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndEffectorTool.h
/// @class EcEndEffectorTool
/// @brief Provides a tool for calculating end effector placement
///        and motion.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <manipulator/ecManipActiveState.h>

// forward declarations
class EcEndEffectorSet;
class EcIndividualManipulator;
class EcManipulatorEndEffectorPlacement;
class EcManipulatorEndEffectorVelocity;

/// Provides a tool for calculating end effector placement and motion.
class EC_ACTIN_CONTROL_DECL EcEndEffectorTool
{
public:
   /// default constructor
   EcEndEffectorTool
      (
      );

   /// destructor
   virtual ~EcEndEffectorTool
      (
      );

   /// copy constructor
   EcEndEffectorTool
      (
      const EcEndEffectorTool& orig
      );

   /// assignment operator
   EcEndEffectorTool& operator=
      (
      const EcEndEffectorTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorTool& orig
      ) const;

   /// get end-effector set
   virtual const EcEndEffectorSet* endEffectorSet
      (
      ) const;

   /// set end-effector set
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet* endEffectorSet
      );

   /// get manipulator
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// set manipulator
   virtual void setManipulator
      (
      const EcIndividualManipulator* manipulator
      );

   /// get active position state
   virtual const EcManipulatorActivePositionState& activePositionState
      (
      ) const;

   /// set the position state
   virtual void setPositionState
      (
      const EcPositionState& positionState
      ) const;

   /// set the velocity state
   virtual void setVelocityState
      (
      const EcVelocityState& velocityState
      ) const;

   /// set the position and velocity state together
   /// This expands the velocity state if needed
   virtual void setPositionAndVelocityState
      (
      const EcPositionState& positionState,
      const EcVelocityState& velocityState
      ) const;

   /// get active state
   virtual const EcManipulatorActiveState& activeState
      (
      ) const;

   /// calculate the end-effector position for hard constraints
   virtual EcBoolean calcHardEndEffectorPlacement
      (
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector position for soft constraints
   virtual EcBoolean calcSoftEndEffectorPlacement
      (
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector position for all constraints
   virtual EcBoolean calcAllEndEffectorPlacement
      (
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector position
   virtual EcBoolean calcEndEffectorPlacement
      (
      const EcU32Vector& endEffectorIndices,
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector position for the hard constraints, using
   /// (and setting) the specified active position state.
   virtual EcBoolean calcHardEndEffectorPlacement
      (
      EcManipulatorActiveState&  activeState,
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector position for the soft constraints, using
   /// (and setting) the specified active position state.
   virtual EcBoolean calcSoftEndEffectorPlacement
      (
      EcManipulatorActiveState&  activeState,
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector position for all constraints, using
   /// (and setting) the specified active position state.
   virtual EcBoolean calcAllEndEffectorPlacement
      (
      EcManipulatorActiveState&  activeState,
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector position for the given indices,
   /// while using (and setting) the specified active position state.
   virtual EcBoolean calcEndEffectorPlacement
      (
      const EcU32Vector& endEffectorIndices,
      EcManipulatorActiveState&  activeState,
      EcManipulatorEndEffectorPlacement& placement
      ) const;

   /// calculate the end-effector velocity for the hard constraints.
   virtual EcBoolean calcHardEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// calculate the end-effector velocity for the soft constraints.
   virtual EcBoolean calcSoftEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// calculate the end-effector velocity for all constraints.
   virtual EcBoolean calcAllEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// calculate the end-effector velocity for the specified indices.
   virtual EcBoolean calcEndEffectorVelocity
      (
      const EcU32Vector& endEffectorIndices,
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// calculate the end-effector velocity for the specified indices
   /// while using (and setting) the specified active position state.
   virtual EcBoolean calcEndEffectorVelocity
      (
      const EcU32Vector& endEffectorIndices,
      EcManipulatorActiveState&  actState,
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// set a zero end-effector velocity for the hard constraints
   virtual EcBoolean setHardZeroEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// set a zero end-effector velocity for the soft constraints
   virtual EcBoolean setSoftZeroEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// set a zero end-effector velocity for all constraints
   virtual EcBoolean setAllZeroEndEffectorVelocity
      (
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// set a zero end-effector velocity for the specified indices
   virtual EcBoolean setZeroEndEffectorVelocity
      (
      const EcU32Vector& endEffectorIndices,
      EcManipulatorEndEffectorVelocity& velocity
      ) const;

   /// get a null object
   static EcEndEffectorTool nullObject
      (
      );

protected:
   const EcEndEffectorSet*           m_pEndEffectorSet;  ///< const pointer to the end-effector set
   const EcIndividualManipulator*    m_pManipulator;     ///< const pointer to the manipulator
   mutable EcManipulatorActiveState  m_ActiveState;      ///< the active state used in calculations

   /// utility objects
   mutable EcCoordinateSystemTransformation m_InboardDh;       ///< the inboard DH frame
   mutable EcCoordinateSystemTransformation m_OutboardPoint;   ///< the outboard point
   mutable EcCoordinateSystemTransformation m_OutboardFrame;   ///< the outboard frame
   mutable EcVelocityState                  m_UtilityVelocityState;  ///< the utility velocity state
};

/// a vector of end-effector tools
typedef std::vector<EcEndEffectorTool> EcEndEffectorToolVector;

#endif // ecEndEffectorTool_H_
