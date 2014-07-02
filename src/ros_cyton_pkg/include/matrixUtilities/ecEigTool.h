#ifndef ecEigTool_H_
#define ecEigTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecEigTool.h
/// @class EcEigTool
/// @brief Provides a tool for calculating the the eigenvalues and
///        eigenvectors for a system of equations.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecConstants.h>

// forward declaration
class EcReArray;

class EC_STABLE_MATRIXUTILITIES_DECL EcEigTool
{
public:
   /// default constructor
   EcEigTool
      (
      );

   /// destructor
   virtual ~EcEigTool
      (
      );

   /// copy constructor
   EcEigTool
      (
      const EcEigTool& orig
      );

   /// assignment operator
   EcEigTool& operator=
      (
      const EcEigTool& orig
      );

   /// perform eigenvalue decomposition
   /**
   \param[in] input The matrix to be performed eigenvalue decomposition.
   \param[out] eigVectors The eigenvectors of input.
   \param[out] eigValues The eigenvalues of input.
   */
   virtual void eigenValueDecomposition
      (
      // input
      const EcReArray& input,
      // output
      EcReArray& eigVectors,
      EcComplexVector& eigValues
      ) const ;

   /// get a null object
   static EcEigTool nullObject
      (
      );
};

#endif // ecEigTool_H_
