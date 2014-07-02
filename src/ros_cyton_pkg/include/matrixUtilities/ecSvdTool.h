#ifndef ecSvdTool_H_
#define ecSvdTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSvdTool.h
/// @class EcSvdTool
/// @brief Provides a tool for calculating the singular value
///        decomposition.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecConstants.h>

/// ACML is supported on windows and linux, but not OSX or embedded systems.
#if defined(WIN32) || (!defined(__APPLE__) && !defined(EC_EMBEDDED))
#  define EC_HAVE_ACML 1
#else
#  define EC_HAVE_ACML 0
#endif

// forward declaration
class EcReArray;

class EC_STABLE_MATRIXUTILITIES_DECL EcSvdTool
{
public:
   /// default constructor
   EcSvdTool
      (
      );

   /// destructor
   virtual ~EcSvdTool
      (
      );

   /// copy constructor
   EcSvdTool
      (
      const EcSvdTool& orig
      );

   /// assignment operator
   EcSvdTool& operator=
      (
      const EcSvdTool& orig
      );


   /// Computes the singular value decomposition of the matrix a T
   ///           aa = U x W x V, where W = Diag(w1, w2, ... wN).
   ///           aa is mxn
   ///           U is mxn
   ///           V is nxn
   ///           wOut has length n
   ///          U is returned in aa and V (and NOT transpose(V)) is returned in vOut.
   ///          The vector of singular values, wOut, is returned as a EcRealVector.
   /**
   \param[in,out] aa The matrix to be performed singular value decomposition. Upon completion, U is returned here.
   \param[out] vWOut The vector W in aa = U x W x V^T.
   \param[out] vOut The matrix V in aa = U x W x V^T.
   \return True if SVD was completed
   */
   virtual EcBoolean singularValueDecomposition
      (
      EcReArray& aa,
      EcRealVector& vWOut,
      EcReArray& vOut
      )const;

   /**
   \brief Same as singularValueDecomposition, except U is returned in uOut and aIn is left unmodified.
   \param[in] aIn The matrix to be performed singular value decomposition.
   \param[out] uOut The matrix U in aa = U x W x V^T.
   \param[out] vWOut The vector W in aa = U x W x V^T.
   \param[out] vOut The matrix V in aa = U x W x V^T.
   \return True if SVD was completed
   */
   virtual EcBoolean singularValueDecompositionJAMA
      (
      const EcReArray& aIn,
      EcReArray& uOut,
      EcRealVector& vWOut,
      EcReArray& vOut
      )const;


   /**
   \brief   Calculates the SVD of mxn aIn as U.W.V^T.
            U is mxn, W is returned as an n-length vector, and V is nxn.
   \param[in] aIn The matrix to be performed singular value decomposition.
   \param[out] uOut The matrix U in aa = U x W x V^T.
   \param[out] wOut The vector W in aa = U x W x V^T.
   \param[out] vOut The matrix V in aa = U x W x V^T.
   \return True if SVD was completed
   */
   virtual EcBoolean singularValueDecomposition
      (
      const EcReArray& aIn,
      EcReArray& uOut,
      EcRealVector& wOut,
      EcReArray& vOut
      )const;

   /**
   \brief  Economy sized SVD, If aIn is m-by-n with m > n, then only the
           first n columns of U.
   \param[in]  aIn The matrix to be performed singular value decomposition.
   \param[in]  AtA Matrix A times its transpose.
   \param[out] uOut The matrix U in aa = U x W x V^T.
   \param[out] vWOut The vector W in aa = U x W x V^T.
   \param[out] vOut The matrix V in aa = U x W x V^T.
   \return True if SVD was completed
   */
   virtual EcBoolean ecomonySizedSingularValueDecomposition
      (
      const EcReArray& aIn,
      EcReArray& AtA,
      EcReArray& uOut,
      EcRealVector& vWOut,
      EcReArray& vOut
      ) const;


   /**
     @brief truncatedPseudoInverse Purpose:  Return a EcReArray that is the truncated pseudoinverse of a.
             Unlike the singular value decomposition, the array a is not
              modified. The parameter epsilon is used as a threshold on the singular
              values used in forming the pseudoinverse; if a singular value
              is less than epsilon multiplied by largest singular value,
              then the diagonal element of the matrix, W, containing the reciprocals of the singular values, is set to zero.
     @param a the matrix to be inverted
     @param epsilon the truncation tolerance
     @return EcReArray truncated pseudo inverse of a
    */
   virtual EcReArray truncatedPseudoInverse
      (
      const EcReArray& a,
      const EcReal epsilon = 1.0e-4
      );


   /**
     @brief dampedPseudoInverse Return a EcReArray that is the damped pseudoinverse of a.
            The array a is not modified.  The parameter alpha is added to each singular value before inversion.
     @param a the matrix to be inverted
     @param alpha added to each singular value before inversion
     @return EcReArray damped pseudoinverse of a
    */
   virtual EcReArray dampedPseudoInverse
      (
      const EcReArray& a,
      const EcReal alpha=EcNANO
      );

   /// get a null object
   static EcSvdTool nullObject
      (
      );

   private:

#if EC_HAVE_ACML

   virtual EcBoolean singularValueDecompositionACML
         (
         const EcReArray& aIn,
         EcReArray& uOut,
         EcRealVector& vWOut,
         EcReArray& vOut
         )const;

   mutable double*  m_pS;

   mutable EcU32    m_SLength;

   mutable double*  m_pU;

   mutable EcU32    m_ULength;

   mutable double*  m_pVT;

   mutable EcU32    m_VTLength;

   mutable double*  m_pA;

   mutable EcU32    m_ALength;

   mutable int*     m_pWork;

   mutable EcU32    m_WorkLength;

#endif

   /// mutable data used for speed
   mutable EcRealVector m_aVtmp;
};

#endif // ecSvdTool_H_
