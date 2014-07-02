#ifndef ecJacobianTool_H_
#define ecJacobianTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecJacobianTool.h
/// @class EcJacobianTool
/// @brief Provides a tool for calculating manipulator Jacobians.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <manipulator/ecManipActiveState.h>

// forward declarations
class EcControlExpressionContainer;
class EcEndEffectorSet;
class EcIndividualManipulator;
class EcManipulatorEndEffectorVelocity;

/** Provides a tool for calculating manipulator Jacobians.
*/
class EC_ACTIN_CONTROL_DECL EcJacobianTool
{
public:
   /// default constructor
   EcJacobianTool
      (
      );

   /// destructor
   virtual ~EcJacobianTool
      (
      );

   /// copy constructor
   EcJacobianTool
      (
      const EcJacobianTool& orig
      );

   /// assignment operator
   EcJacobianTool& operator=
      (
      const EcJacobianTool& orig
      );

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

   /// set the position state.  This is only used if no external active
   /// state is provided when calculating the Jacobian
   virtual void setPositionState
      (
      const EcPositionState& positionState
      );

   /// get the floating-base flag
   virtual EcBoolean isFixedBase
      (
      ) const;

   /// set the floating-base flag
   virtual void setIsFixedBase
      (
      EcBoolean isFixedBase
      );

   /// get the number of Jacobian columns
   virtual EcU32 numJacobianColumns
      (
      ) const;

   /// get the number of rows in the hard Jacobian
   virtual EcU32 numHardJacobianRows
      (
      ) const;

   /// get the number of rows in the soft Jacobian
   virtual EcU32 numSoftJacobianRows
      (
      ) const;

   /// get the number of rows in the complete Jacobian
   virtual EcU32 numAllJacobianRows
      (
      ) const;

   /// get the number of rows based on the given indices
   virtual EcU32 numJacobianRows
      (
      const EcU32Vector& endEffectorIndices
      ) const;

   /// calculate manipulator Jacobian for indices.  The Jacobian
   /// is made by stacking the individual end-effector jacobians,
   /// with the point end effectors in order on top, followed by
   /// the frame end effectors in order.  The Jacobian corresponds
   /// to end-effector motion represented in the system frame.
   virtual EcBoolean getJacobian
      (
      const EcU32Vector& endEffectorIndices,
      const EcControlExpressionContainer* container,
      EcManipulatorJacobian& jacobian
      );

   /// calculate manipulator Jacobian for hard constraints.  It
   /// is made by stacking the individual end-effector jacobians,
   /// with the point end effectors in order on top, followed by
   /// the frame end effectors in order.  The Jacobian corresponds
   /// to end-effector motion represented in the system frame.
   virtual EcBoolean getHardJacobian
      (
      EcManipulatorJacobian& jacobian
      ) const;

   /// calculate manipulator Jacobian for soft constraints.  It
   /// is made by stacking the individual end-effector jacobians,
   /// with the point end effectors in order on top, followed by
   /// the frame end effectors in order.  The Jacobian corresponds
   /// to end-effector motion represented in the system frame.
   virtual EcBoolean getSoftJacobian
      (
      EcManipulatorJacobian& jacobian
      ) const;

   /// calculate manipulator Jacobian for all constraints.  It
   /// is made by stacking the individual end-effector jacobians,
   /// with the point end effectors in order on top, followed by
   /// the frame end effectors in order.  The Jacobian corresponds
   /// to end-effector motion represented in the system frame.
   virtual EcBoolean getAllJacobian
      (
      EcManipulatorJacobian& jacobian
      ) const;

   /// calculate manipulator Jacobian for indices.  The Jacobian
   /// is made by stacking the individual end-effector jacobians,
   /// with the point end effectors in order on top, followed by
   /// the frame end effectors in order.  The Jacobian corresponds
   /// to end-effector motion represented in the system frame.
   virtual EcBoolean getJacobian
      (
      const EcU32Vector& endEffectorIndices,
      EcManipulatorJacobian& jacobian
      ) const;

   /// calculate sparsity matrix for the hard-constraint jacobian.  If given a container,
   /// initialize the jacobian parameters.
   virtual void hardSparsityAnalysis
      (
      const EcControlExpressionContainer* pContainer,
      EcU32Vector& sparsityIndices,
      EcU32Vector& zeroStartIndices,
      EcBoolean& isSparse
      );

   /// calculate sparsity matrix for the soft-constraint jacobian.  If given a container,
   /// initialize the jacobian parameters.
   virtual void softSparsityAnalysis
      (
      const EcControlExpressionContainer* pContainer,
      EcU32Vector& sparsityIndices,
      EcU32Vector& zeroStartIndices,
      EcBoolean& isSparse
      );

   /// calculate sparsity matrix for all constraints.  If given a container,
   /// initialize the jacobian parameters.
   virtual void allSparsityAnalysis
      (
      const EcControlExpressionContainer* pContainer,
      EcU32Vector& sparsityIndices,
      EcU32Vector& zeroStartIndices,
      EcBoolean& isSparse
      );

   /// calculate sparsity matrix for the given indices.  If given a container,
   /// initialize the jacobian parameters.
   virtual void sparsityAnalysis
      (
      const EcU32Vector& endEffectorIndices,
      const EcControlExpressionContainer* pContainer,
      EcU32Vector& sparsityIndices,
      EcU32Vector& zeroStartIndices,
      EcBoolean& isSparse
      );

   /// get a null object
   static EcJacobianTool nullObject
      (
      );

protected:

   /// calculate sparsity matrix.
   virtual void sparsityAnalysis
      (
      const EcU32Vector& endEffectorIndices,
      EcU32Vector& sparsityIndices,
      EcU32Vector& zeroStartIndices,
      EcBoolean& isSparse
      );

   /// a pointer to the control expression
   const EcControlExpressionContainer*          m_pControlDescriptions;

   /// a pointer to the manipulator
   const EcIndividualManipulator*               m_pManipulator;

   /// a pointer to the position state
   EcManipulatorActiveState*                    m_pActState;

   /// the end-effector description
   const EcEndEffectorSet*                      m_pEndEffectorSet;

   /// flag indicating if the base is fixed or floating
   EcBoolean                                    m_IsFixedBase;

   /// position state (needed if above pointer initialized to zero)
   EcManipulatorActiveState                     m_ActiveState;

   /// sparsity matrix (in class just for memory allocation efficiency)
   mutable EcBooleanVectorVector                m_SparsityArray;
};

#endif // ecJacobianTool_H_
