#ifndef ecLeastSquareTool_H_
#define ecLeastSquareTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecLeastSquareTool.h
/// @class EcLeastSquareTool
/// @brief Provides a tool for calculating the least squares solution
///        for AX = b.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecConstants.h>
#include "ecReArray.h"

class EC_STABLE_MATRIXUTILITIES_DECL EcLeastSquareTool
{
public:
   /// default constructor
   EcLeastSquareTool
      (
      );

   /// destructor
   virtual ~EcLeastSquareTool
      (
      );

   /// copy constructor
   EcLeastSquareTool
      (
      const EcLeastSquareTool& orig
      );

   /// assignment operator
   EcLeastSquareTool& operator=
      (
      const EcLeastSquareTool& orig
      );

   /// perform eigenvalue decomposition
   /**
   \param[in]  A The matrix to be performed eigenvalue decomposition.
   \param[in]  b The eigenvectors of input.
   \param[out] x The eigenvalues of output.
   \param[out] pDet The determinant
   */
   virtual EcBoolean solve
      (
      // input
      const EcReArray& A,
      // input
      const EcRealVector& b,
      // output
      EcRealVector& x,
      EcReal* pDet=0             // optional determinant return
      );

   /// get a null object
   static EcLeastSquareTool nullObject
      (
      );


private:

   mutable  EcReArray      m_AT;   ///< matrix A transpose;
   mutable  EcReArray      m_ATA;  ///< matrix A transpose A inverse
   mutable  EcRealVector   m_ATb;  ///< matrix A transpose times vector b

};

#endif // ecLeastSquareTool_H_
