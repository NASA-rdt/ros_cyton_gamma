#ifndef ecCrbiAccelerationTool_H_
#define ecCrbiAccelerationTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCrbiAccelerationTool.h
/// @class EcCrbiAccelerationTool
/// @brief Provides a tool for gravitational torque/force and gradients.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include "ecManipActiveState.h"
#include "ecMassMatrixTool.h"
#include "ecMatrixDTool.h"

// forward declarations
class EcAccelerationState;
class EcIndividualManipulator;
class EcManipulatorTorque;
class EcStatedSystem;
class EcPositionState;
class EcVelocityState;

/** Provides a tool for calculating joint accelerations and/or torques using composite
rigid-body inertia.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcCrbiAccelerationTool
{
public:
   /// default constructor
   EcCrbiAccelerationTool
      (
      );

   /// destructor
   virtual ~EcCrbiAccelerationTool
      (
      );

   /// copy constructor
   EcCrbiAccelerationTool
      (
      const EcCrbiAccelerationTool& orig
      );

   /// assignment operator
   EcCrbiAccelerationTool& operator=
      (
      const EcCrbiAccelerationTool& orig
      );

   /// calculate accelerations, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.
   /**
    * @param[in] statedSystem The stated system containing the focus manipulator
    * @param[in] manipulator The focus manipulator
    * @param[in] positionState The position state of the manipulator (only used if activeState is not provided)
    * @param[in] velocityState The velocity state of the manipulator (only used if activeState is not provided)
    * @param[in] torque The control torques
    * @param[in] manipExtForce The external forces on the manipulator
    * @param[out] accelerationState The acceleration (joint and base) of the manipulator
    * @param[in,out] activeState A pointer to an active state, which may be NULL. If not NULL, its
    *             position and velocity states will be used. If NULL, an internal active state will
    *             be used with the provided positionState and velocityState.
    * @param[in] updateMassMatrix A flag indicating the need for a mass-matrix update. If true, the mass matrix
    *             will be computed which will provide better accuracy but is time-consuming.
    * @return True
    */
   virtual EcBoolean acceleration
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      const EcManipulatorTorque& torque,
      const EcManipulatorExternalForce& manipExtForce,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState*  activeState=0,
      EcBoolean updateMassMatrix = EcTrue
      );

   /// calculate accelerations, using (and setting) the
   /// active position state that is provided. Overloaded for convenience.
   /**
    * @param[in] statedSystem The stated system containing the focus manipulator
    * @param[in] manipulator The focus manipulator
    * @param[in] torque The control torques
    * @param[in] manipExtForce The external forces on the manipulator
    * @param[out] accelerationState The acceleration (joint and base) of the manipulator
    * @param[in,out] activeState The active state containt the current position and velocity states.
    * @param[in] updateMassMatrix A flag indicating the need for a mass-matrix update. If true, the mass matrix
    *             will be computed which will provide better accuracy but is time-consuming.
    * @return True
    */
   virtual EcBoolean acceleration
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcManipulatorTorque& torque,
      const EcManipulatorExternalForce& manipExtForce,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState&  activeState,
      EcBoolean updateMassMatrix = EcTrue
      );

   /// calculate accelerations and torques, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.  This is a hybrid calculation,
   /// calculating a mix of torque and acceleration, depending on which is
   /// specified.  The vector of flags indicating specification include
   /// six for force and torque components for floating-base mechanisms.
   /**
    * @param[in] statedSystem The stated system containing the focus manipulator
    * @param[in] manipulator The focus manipulator
    * @param[in] positionState The position state of the manipulator (only used if activeState is not provided)
    * @param[in] velocityState The velocity state of the manipulator (only used if activeState is not provided)
    * @param[in] manipExtForce The external forces on the manipulator
    * @param[in] torqueForceSpecified Flags indicating whether torque/force or acceleration is specified. If torque/force
    *                         is specified for the joint, then the flag is true. Otherwise, it is false. For floating-base
    *                         mechanisms, the six components for torque/force specification of the base must be appended after
    *                         the joint specifications.
    * @param[in,out] torque The known torques must be specified (the corresponding flag in torqueForceSpecified is true).
    *                    The method will compute the remaining (unknown) torques.
    * @param[in,out] accelerationState The known accelerations must be specified (the corresponding flag in
    *                    torqueForceSpecified is false). The method will compute the remaining (unknown) accelerations.
    * @param[in,out] activeState A pointer to an active state, which may be NULL. If not NULL, its
    *             position and velocity states will be used. If NULL, an internal active state will
    *             be used with the provided positionState and velocityState.
    * @param[in] updateMassMatrix A flag indicating the need for a mass-matrix update. If true, the mass matrix
    *             will be computed which will provide better accuracy but is time-consuming.
    * @return True
    */
   virtual EcBoolean hybridTorqueAcceleration
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      const EcManipulatorExternalForce& manipExtForce,
      const EcBooleanVector& torqueForceSpecified,
      EcManipulatorTorque& torque,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState*  activeState=0,
      EcBoolean updateMassMatrix = EcTrue
      );

   /// calculate accelerations and torques, using (and setting) the
   /// active position state that is provided.  The vector of flags
   /// indicating specification include six for force and torque
   /// components for floating-base mechanisms. Overloaded for convenience.
   /**
    * @param[in] statedSystem The stated system containing the focus manipulator
    * @param[in] manipulator The focus manipulator
    * @param[in] manipExtForce The external forces on the manipulator
    * @param[in] torqueForceSpecified Flags indicating whether torque/force or acceleration is specified. If torque/force
    *                         is specified for the joint, then the flag is true. Otherwise, it is false. For floating-base
    *                         mechanisms, the six components for torque/force specification of the base must be appended after
    *                         the joint specifications.
    * @param[in,out] torque The known torques must be specified (the corresponding flag in torqueForceSpecified is true).
    *                    The method will compute the remaining (unknown) torques.
    * @param[in,out] accelerationState The known accelerations must be specified (the corresponding flag in
    *                    torqueForceSpecified is false). The method will compute the remaining (unknown) accelerations.
    * @param[in,out] activeState The active state containt the current position and velocity states.
    * @param[in] updateMassMatrix A flag indicating the need for a mass-matrix update. If true, the mass matrix
    *             will be computed which will provide better accuracy but is time-consuming.
    * @return True
    */
   virtual EcBoolean hybridTorqueAcceleration
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcManipulatorExternalForce& manipExtForce,
      const EcBooleanVector& torqueForceSpecified,
      EcManipulatorTorque& torque,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState&  activeState,
      EcBoolean updateMassMatrix = EcTrue
      );

   /// get a null object
   static EcCrbiAccelerationTool nullObject
      (
      );

protected:

   /// calculate the joint torque array, using (and setting) the
   /// active state that is provided.
   virtual EcBoolean calculateJointTorqueArray
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorTorque& torque,
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate the mass matrix, including actuator inertia,
   /// using (and setting) the active state that is provided.
   virtual EcBoolean calculateMassMatrix
      (
      const EcIndividualManipulator& manipulator,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate the extended mass matrix, including actuator inertia,
   /// using (and setting) the active state that is provided.
   virtual EcBoolean calculateExtendedMassMatrixInBase
      (
      const EcIndividualManipulator& manipulator,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate hybrid control intermediates
   virtual void calculateHybridControlMassIntermediates
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorExternalForce& manipExtForce,
      const EcBooleanVector& torqueForceSpecified,
      const EcStatedSystemStruct& systemStruct,
      EcManipulatorTorque& torque,
      EcManipulatorActiveState&  activeState,
      EcAccelerationState& accelerationState,
      EcGeneralForce& fm
      );

   /// calculate hybrid control with no constraints
   virtual EcBoolean hybridTorqueAccelerationNoConstraints
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcManipulatorExternalForce& manipExtForce,
      const EcBooleanVector& torqueForceSpecified,
      EcManipulatorTorque& torque,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState&  activeState,
      EcBoolean updateMassMatrix = EcTrue
      );

   /// calculate hybrid control with constraints
   virtual EcBoolean hybridTorqueAccelerationWithConstraints
      (
      const EcStatedSystem& statedSystem,
      const EcIndividualManipulator& manipulator,
      const EcManipulatorExternalForce& manipExtForce,
      const EcBooleanVector& torqueForceSpecified,
      EcManipulatorTorque& torque,
      EcAccelerationState& accelerationState,
      EcManipulatorActiveState&  activeState,
      EcBoolean updateMassMatrix = EcTrue
      );

protected:
   /// an active state, used if no external value is provided
   EcManipulatorActiveState          m_ActiveState;

   /// a tool to calculate the nxn mass matrix
   EcMassMatrixTool                  m_MassMatrixTool;

   /// a joint-torque tool
   EcTotalTorqueTool                 m_TotalTorqueTool;

   /// a matrix-D tool
   EcMatrixDTool                     m_MatrixDTool;

   /// the (jointDof x jointDof) basic mass matrix
   EcReArray                         m_MassMatrix;

   /// the (jointDof+6 x jointDof+6) extended mass matrix
   EcReArray                         m_ExtendedMassMatrix;

   /// the Cholesky Decomposition of the nxn basic mass matrix
   EcReArray                         m_CholeskyL;

   /// an array representation of torques
   EcReArray                         m_TorqueArray;

   /// joint accelerations
   EcReArray                         m_AccelerationArray;

   /// the Cholesky Decomposition of the extended mass matrix
   EcReArray                         m_ExtendedCholeskyL;

   /// an extended torque array.  The base force/moment are the
   /// first six elements, and the joint torques are the remaining
   /// elements.  Used for floating-base manipulators.
   EcReArray                         m_ExtendedTorqueArray;

   /// an extended acceleration array.  The base linear/angular
   /// acceleration are the first six elements, and the joint
   /// accelerations are the remaining elements.  Used for
   /// floating-base manipulators.
   EcReArray                         m_ExtendedAccelerationArray;

   /// the lower left-hand portion of the extended Cholesky
   EcReArray                         m_MatrixET;

   /// the underconstrained normal equations for matrix E
   EcReArray                         m_EET;

   /// flags specifying whether torque/force or acceleration is specified
   EcBooleanVector m_TorqueForceSpecified;

   // quantities for hybrid torque/acceleration determination (avoid reuse)
   EcReArray                         m_MatrixTk;      ///< Known torque matrix
   EcReArray                         m_MatrixTu;      ///< Unknown torque matrix
   EcReArray                         m_MatrixAk;      ///< Known acceleration matrix
   EcReArray                         m_MatrixAu;      ///< Unknown acceleration matrix
   EcReArray                         m_MatrixM11;     ///< Mass11 matrix
   EcReArray                         m_MatrixM12;     ///< Mass12 matrix
   EcReArray                         m_MatrixM12T;    ///< Transpose of Mass12 matrix
   EcReArray                         m_MatrixM22;     ///< Mass22 matrix
   EcReArray                         m_CholeskyM11L;  ///< Cholesky decomposition of Mass11 matrix

   /// the torque array when constraint forces are added.  It is
   /// the torque array plus the constraint torques/forces
   EcReArray                         m_ConstrainedTorqueArray;

   /// the nominal (unconstrained) acceleration when constraints are used.
   EcReArray                         m_UnconstrainedAccelerationArray;

   // other intermediate parameters for constrained acceleration calculation (avoid reuse)
   EcReArray                         m_MatrixZ;          ///< Matrix Z
   EcReArray                         m_MatrixMInvKTrans; ///< Mass matrix inverse times K transpose
   EcReArray                         m_MatrixU;          ///< Matrix U
   EcReArray                         m_CholeskyU;        ///< Cholesky decomposition of U
   EcReArray                         m_MatrixB;          ///< Matrix B
   EcReArray                         m_SubtractiveTorques;  ///< Subtractive torques

   // quantities for hybrid torque/acceleration with constraints (avoid reuse)
   EcReArray                         m_MatrixZ1;         ///< Matrix Z1
   EcReArray                         m_MatrixZ2;         ///< Matrix Z2
   EcReArray                         m_MatrixK1;         ///< Matrix K1
   EcReArray                         m_MatrixK2;         ///< Matrix K1
   EcReArray                         m_MatrixK2T;        ///< Transpose of Matrix K2
   EcReArray                         m_MatrixU1;         ///< Matrix U1
   EcReArray                         m_MatrixMInvZ1;     ///< Mass matrix inverse times Z1
};

#endif // ecCrbiAccelerationTool_H_
