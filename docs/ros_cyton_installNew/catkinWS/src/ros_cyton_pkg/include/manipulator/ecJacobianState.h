#ifndef ecJacobianState_H_
#define ecJacobianState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecJacobianState.h
/// @class EcJacobianState
/// @brief Holds the Jacobian state of a manipulator.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <matrixUtilities/ecReArray.h>

/// Holds the Jacobian state of a manipulator. The Jacobian state include the (hard)
/// Jacobian, the soft Jacobian, the null space, and other Jacobian-related entities.
class EC_FOUNDATION_MANIPULATOR_DECL EcJacobianState
{
public:
   /// default constructor
   EcJacobianState
      (
      );

   /// destructor
   virtual ~EcJacobianState
      (
      );

   /// copy constructor
   EcJacobianState
      (
      const EcJacobianState& orig
      );

   /// assignment operator
   EcJacobianState& operator=
      (
      const EcJacobianState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJacobianState& orig
      ) const;

   /// invalidates all of the state
   virtual void invalidateAll
      (
      );

   /// gets the hard jacobian
   virtual const EcReArray& jacobian
      (
      ) const;

   /// get and set the jacobian using a non-const reference
   virtual EcReArray& jacobianReferenceToSet
      (
      );

   /// sets the hard jacobian
   virtual void setJacobian
      (
      const EcReArray& jacobian
      );

   /// flag indicating whether or not the hard Jacobian is valid
   virtual EcBoolean jacobianValid
      (
      ) const;

   /// gets the soft jacobian
   virtual const EcReArray& softJacobian
      (
      ) const;

   /// get and set the soft jacobian using a non-const reference
   virtual EcReArray& softJacobianReferenceToSet
      (
      );

   /// sets the soft jacobian
   virtual void setSoftJacobian
      (
      const EcReArray& softJacobian
      );

   /// flag indicating whether or not the soft Jacobian is valid
   virtual EcBoolean softJacobianValid
      (
      ) const;

   /// gets the null space
   virtual const EcReArray& nullSpace
      (
      );

   /// sets the null space
   virtual void setNullSpace
      (
      const EcReArray& nullSpace
      );

   /// gets the validity of the null space
   virtual EcBoolean nullSpaceValid
      (
      ) const;

   /// calculate the null space and LU decomposition
   virtual void calculateNullSpaceAndJacobianLU
      (
      );

   /// gets the sparsity Indices - const
   virtual const EcU32Vector& sparsityIndices
      (
      ) const;

   /// gets the sparsity Indices - nonconst
   virtual EcU32Vector& sparsityIndices
      (
      );

   /// gets the zero starting column in each row in Jacobian matrix
   /// after column swapping for sparsity
   virtual EcU32Vector& zeroStart
      (
      );

   /// gets the validity of the sparsity properties
   virtual EcBoolean sparsityValid
      (
      ) const;

   /// sets the validity flag
   virtual void setSparsityValid
      (
      EcBoolean sValid
      );

   /// true if the matrix is sparse
   virtual EcBoolean isSparse
      (
      ) const;

   /// sets the sparsity flag
   virtual void setIsSparse
      (
      EcBoolean isSparse
      );

   /// gets the LU decomposition of Jacobian
   virtual const EcReArray& jacobianLU
      (
      );

   /// gets the LU decomposition of Jacobian
   virtual EcU32Vector& indices
      (
      );

protected:

   /// the hard jacobian (mm by nn)
   EcReArray m_Jacobian;

   /// the soft jacobian (mm by nn)
   EcReArray m_SoftJacobian;

   /// the null space (nn by pp)
   EcReArray m_NullSpace;

   /// the LU decomposition of Jacobian (nn by nn with first mm rows filled)
   EcReArray m_JacobianLU;

   /// holds the pivots column indices of the LU decomposition
   EcU32Vector m_vIndices;

   /// Jacobian validity flag
   EcBoolean m_JacobianValid;

   /// soft Jacobian validity flag
   EcBoolean m_SoftJacobianValid;

   /// Null Space validity flag
   EcBoolean m_NullSpaceValid;

   /// Jacobian LU decomposition validity flag (also used for indicating validity of
   /// m_Indices)
   EcBoolean m_JacobianLUValid;

   /// sparsity Indices: column swap the Jacobian matrix to have zero top right
   EcU32Vector m_vSparsityIndices;

   /// record the beginning of all zeros in each row:
   EcU32Vector m_vZeroStart;

   /// the sparsity of the Jacobian matrix has been examed and the indices and zeros
   /// location has been identified.
   EcBoolean m_SparsityValid;

   /// flag indicating if the jacobian matrix is sparse
   EcBoolean m_IsSparse;
};

#endif // ecJacobianState_H_
