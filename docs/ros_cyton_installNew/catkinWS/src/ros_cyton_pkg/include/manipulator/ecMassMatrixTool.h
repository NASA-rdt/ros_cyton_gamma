#ifndef ecMassMatrixTool_H_
#define ecMassMatrixTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecMassMatrixTool.h
/// @class EcMassMatrixTool
/// @brief Provides a tool for calculating manipulator mass matrices.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecTotalTorqueTool.h"
#include "ecMatrixDTool.h"
#include "ecManipExternalForce.h"

class EcStatedSystemStruct;

/// Provides a tool for calculating manipulator mass matrices.
class EC_FOUNDATION_MANIPULATOR_DECL EcMassMatrixTool
{
public:
   /// default constructor
   EcMassMatrixTool
      (
      );

   /// destructor
   virtual ~EcMassMatrixTool
      (
      );

   /// copy constructor
   EcMassMatrixTool
      (
      const EcMassMatrixTool& orig
      );

   /// assignment operator
   EcMassMatrixTool& operator=
      (
      const EcMassMatrixTool& orig
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

   /// set the position state.  This is only used if no external active
   /// state is provided when calculating the mass matrix
   virtual void setPositionState
      (
      const EcPositionState& positionState
      );

   /// calculate mass matrix, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& massMatrix
      (
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate mass matrix, using (and setting) the
   /// active position state that is provided.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& massMatrix
      (
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate extended mass matrix, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.  Extended portion in
   /// base coordinates, at base point of application.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& extendedMassMatrixInBase
      (
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate extended mass matrix, using (and setting) the
   /// active position state that is provided.  Extende portion in
   /// base coordinates, at base point of application.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& extendedMassMatrixInBase
      (
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate extended mass matrix, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.  Extended portion in
   /// system coordinates, at base point of application.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& extendedMassMatrixInSystem
      (
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate extended mass matrix, using (and setting) the
   /// active position state that is provided.  Extende portion in
   /// system coordinates, at base point of application.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& extendedMassMatrixInSystem
      (
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );


   /// get is-fixed-base flag
   virtual EcBoolean isFixedBase
      (
      ) const;

   /// set is-fixed-base flag
   virtual void setIsFixedBase
      (
      EcBoolean isFixedBase
      );

   /// get degrees of constraint
   virtual EcU32 degreesOfConstraint
      (
      ) const;

   /// set degrees of constraint
   virtual void setDegreesOfConstraint
      (
      EcU32 degreesOfConstraint
      );

   /// calculate the torque needed in each joints if the null space
   /// vectors are the desired joint acceleration.
   virtual const EcReArray& nullSpaceTorque
      (
      EcManipulatorActiveState*  activeStateOrg,
      const EcReArray& nullSpace
      );

   /// calculate the torque needed in each joints if the null space
   /// vectors are the desired joint acceleration.
   virtual const EcReArray& nullSpaceTorque
      (
      EcManipulatorActiveState&  activeStateOrg,
      const EcReArray& nullSpace
      );

   /// get a null object
   static EcMassMatrixTool nullObject
      (
      );

protected:

   /// resize member variables
   virtual void resize
      (
      );

   /// a pointer to the focus manipulator
   const EcIndividualManipulator*   m_pManipulator;

   /// an active state that is used if no external value is provided
   EcManipulatorActiveState         m_ActiveState;

   /// the mass matrix.  Returned by const reference.
   EcReArray                        m_MassMatrix;

   /// the extended mass matrix (including base motion).  Returned by const reference.
   EcReArray                        m_ExtendedMassMatrix;

   /// a flag indicating that the system is fixed base
   EcBoolean                        m_IsFixedBase;

   /// the system degrees of constraint
   EcU32                            m_Doc;

   // utility values below (avoid reuse in derived classes)
   EcVelocityState                  m_ZeroVelocityState;          ///< the velocity state whose elements are all zeros
   EcReArray                        m_NullSpaceTorque;            ///< the null-space torque
   EcManipulatorExternalForce       m_UtilityManipExternalForce;  ///< the utility manipulator's external force

   mutable EcXmlRealVector          m_UtilityTorques;             ///< the utility joint torques
   mutable EcAccelerationState      m_UtilityAccelerationState;   ///< the utility acceleration state
   mutable EcTotalTorqueTool        m_UtilityTotalTorqueTool;     ///< the total torque tool
   mutable EcMatrixDTool            m_MatrixDTool;                ///< the matrix D tool
   EcReArray                        m_UtilityNullspace;           ///< the utility null space
   mutable EcReArray                m_UtilityRigidBodyInertia;    ///< the utility rigid body inertia
   mutable EcReArray                m_UtilityMatrixD;             ///< the utility matrix D
   EcRigidBodyMassProperties        m_UtilityCrbi;                ///< the utility rigid body mass properties
};

#endif // ecMassMatrixTool_H_
