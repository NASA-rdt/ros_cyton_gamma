#ifndef ecCoreVelContTool_H_
#define ecCoreVelContTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCoreVelContTool.h
/// @class EcCoreVelocityControlTool
/// @brief Provides a core tool for manipulator velocity control.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <matrixUtilities/ecReArray.h>

class EcJacobianState;

/// Provides a tool for velocity control.
class EC_ACTIN_CONTROL_DECL EcCoreVelocityControlTool
{
public:
   /// default constructor
   EcCoreVelocityControlTool
      (
      );

   /// destructor
   virtual ~EcCoreVelocityControlTool
      (
      );

   /// copy constructor
   EcCoreVelocityControlTool
      (
      const EcCoreVelocityControlTool& orig
      );

   /// assignment operator
   EcCoreVelocityControlTool& operator=
      (
      const EcCoreVelocityControlTool& orig
      );

   /// get primary matrix
   virtual const EcReArray& primaryMatrix
      (
      ) const;

   /// set primary matrix
   virtual void setPrimaryMatrix
      (
      const EcReArray& primaryMatrix
      );

   /// get null space
   virtual const EcReArray& nullSpace
      (
      ) const;

   /// get weighted null space
   virtual const EcReArray& weightedNullSpace
      (
      ) const;

   /// get weight flag
   virtual EcBoolean weightFlag
      (
      ) const;

   /// set weight flag
   virtual void setWeightFlag
      (
      EcBoolean weightFlag
      );

   /// get indices
   virtual const EcU32Vector& indices
      (
      ) const;

   /// set indices
   virtual void setIndices
      (
      const EcU32Vector& indices
      );

   /// Calculates joint rates given a jacobian, a weighting
   /// matrix ww, a function gradient ff, a scalar weighting
   /// term ss, and a desired end effector motion handMotion.
   /// Output: jointRates and the null-space component of those
   /// rates.
   virtual EcBoolean calcJointRates
      (
      EcJacobianState*             pJacobianState,
      const EcManipulatorJacobian& jacobian,
      const EcReArray&             w,
      const EcRealVector&          f,
      const EcReal&                s,
      const EcRealVector&          handMotion,
      EcU32                        dof,         // total degrees of freedom
      EcRealVector&                jointRates,
      EcRealVector&                nullSpaceComponent,
      EcReal&                      det
      );

   /// Calculates joint rates given LU of J, weighted Null space (A=Nj^T W)
   /// Nj^T times a function gradient ff (B=Nj^T F), a scalar weighting
   /// term ss, and a desired end effector motion handMotion.
   /// Output: jointRates.
   virtual EcBoolean calcJointRatesAB
      (
      EcJacobianState*             pJacobianState,  // acc to J Nj LU & indices
      const EcReArray&             A,			   // Nj^T W  (weighted null space)
      const EcRealVector&          B,           // Nj^T F
      const EcReal&                ss,          // alpha
      const EcRealVector&          handMotion,  // V
      EcU32                        dof,         // total degrees of freedom
      EcRealVector&                jointRates,  // q-dot
      EcRealVector&                nullSpaceComponent,  // of q-dot
      EcReal&                      det
      );

   /// get a null object
   static EcCoreVelocityControlTool nullObject
      (
      );

   /// resize member variables
   virtual void resize
      (
      );

protected:

   /// this calculates the LU decomosition of the matrix formed
   /// by appending nJ^T.M to the Jacobian, where nJ is a set
   /// of columns spanning the null space of J and M is the
   /// weighting matrix.  It also returns nj=nJ and Mnj=M.nJ.
   /// Matrix J is m x n. m<n.  mii=1 if M is used to weight the
   /// joint rates and mii=0 if no weighting is used.  Column
   /// pivoting is performed in the calculation, and indices
   /// holds the pivot column indices.

   virtual EcBoolean prep
      (
      EcJacobianState* pJacobianState,
      EcReArray& primaryMatrix,
      EcU32Vector& indices,
      EcU32 mm,
      EcU32 mii,
      const EcReArray& M,
      EcReArray& nj,
      EcReArray& Mnj
      );

   /// this calculates the LU decomosition of the matrix formed
   /// by appending nJ^T.M to the Jacobian, where nJ is a set
   /// of columns spanning the null space of J and M is the
   /// weighting matrix. Matrix J is m x n. m<n. Column pivoting is performed.
   virtual EcBoolean prep
      (
      EcReArray& primaryMatrix,
      EcU32Vector& indices,
      EcU32 mm,
      EcU32 nn,
      const EcReArray& A   // Nj^T W (weighted null space)^T
      );

   /// this performs the backsubstitution after prep is run
   virtual EcBoolean calc
      (
      const EcReArray& lu,
      const EcU32Vector& indices,
      const EcRealVector& rightHandSide,
      EcRealVector& jointRates,
      EcReal& det
      );

protected:
   /// the primary array.  Initially holds the Jacobian in
   /// the upper mxn portion.  After running prep, it holds
   /// the LU decomposition of J appended to nJ^T.M.
   EcReArray                         m_PrimaryMatrix;

   /// holds concatenated null-space vectors
   EcReArray                         m_NullSpace;

   /// holds concatenated weighted null-space vectors
   EcReArray                         m_WeightedNullSpace;

   /// holds a flag indicating whether or not weighting is used
   EcBoolean                         m_WeightFlag;

   /// holds the pivot column indices
   EcU32Vector                       m_Indices;

   /// holds the degrees of freedom in the manipulator
   EcU32                             m_N;

   /// holds the degrees of constraint
   EcU32                             m_M;

   /// holds the degrees of redundancy
   EcU32                             m_P;

   /// a utility data structure
   mutable EcRealVector m_RightHandSide;

   // temperary parameter as member variables for speed
   mutable EcU32Vector m_Ind1;         ///< set 1 of indices

   mutable EcU32Vector m_Ind2;         ///< set 2 of indices
};

#endif // ecCoreVelContTool_H_
