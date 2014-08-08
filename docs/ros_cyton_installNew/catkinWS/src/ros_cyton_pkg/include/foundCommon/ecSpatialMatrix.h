#ifndef ecSpatialMatrix_H_
#define ecSpatialMatrix_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSpatialMatrix.h
/// @class EcSpatialMatrix
/// @brief Holds a 3x3 matrix as three row vectors.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

// forward declarations
class EcOrientation;
class EcReArray;
class EcVector;

/** Holds a 3x3 matrix as three row vectors.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcSpatialMatrix : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSpatialMatrix
      (
      );

   /// constructor with rows
   EcSpatialMatrix
      (
      const EcVector& row0,
      const EcVector& row1,
      const EcVector& row2
      );

   /// constructor with elements in row order
   EcSpatialMatrix
      (
      EcReal value00,
      EcReal value01,
      EcReal value02,
      EcReal value10,
      EcReal value11,
      EcReal value12,
      EcReal value20,
      EcReal value21,
      EcReal value22
      );

   /// destructor
   virtual ~EcSpatialMatrix
      (
      );

   /// copy constructor
   EcSpatialMatrix
      (
      const EcSpatialMatrix& orig
      );

   /// assignment operator
   EcSpatialMatrix& operator=
      (
      const EcSpatialMatrix& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSpatialMatrix& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// add another mass properties to this and set this to the result
   EcSpatialMatrix& operator+=
      (
      const EcSpatialMatrix& sm2
      );

   /// subtract another mass properties from this and set this to the result
   EcSpatialMatrix& operator-=
      (
      const EcSpatialMatrix& sm2
      );

   /// add another mass properties to this and return the result
   EcSpatialMatrix  operator+
      (
      const EcSpatialMatrix& sm2
      ) const;

   /// subtract another mass properties from this and return the result
   EcSpatialMatrix  operator-
      (
      const EcSpatialMatrix& sm2
      ) const;

   /// multiply another mass properties by this and return the result
   EcSpatialMatrix  operator*
      (
      const EcSpatialMatrix& sm2
      ) const;

   /// multiply this by another matrix
   EcSpatialMatrix& operator*=
      (
      const EcSpatialMatrix& sm2
      );

   /// multiply a vector by this and return the result
   EcVector  operator*
      (
      const EcVector& vec
      ) const;

   /// scale this
   EcSpatialMatrix& operator*=
      (
      EcReal scalar
      );

   /// multiply a vector by this transpose and return the result
   virtual EcVector  transposeTimes
      (
      const EcVector& vec
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the top row - const
   virtual const EcVector& row0
      (
      ) const;

   /// gets the top row - nonconst
   virtual EcVector& row0
      (
      );

   /// sets the top row
   virtual void setRow0
      (
      const EcVector& row0
      );

   /// gets the middle row - const
   virtual const EcVector& row1
      (
      ) const;

   /// gets the middle row - nonconst
   virtual EcVector& row1
      (
      );

   /// sets the middle row
   virtual void setRow1
      (
      const EcVector& row1
      );

   /// gets the bottom row - const
   virtual const EcVector& row2
      (
      ) const;

   /// gets the bottom row - nonconst
   virtual EcVector& row2
      (
      );

   /// sets the bottom row
   virtual void setRow2
      (
      const EcVector& row2
      );

   /// sets the three rows
   virtual void setRows
      (
      const EcVector& row0,
      const EcVector& row1,
      const EcVector& row2
      );

   /// sets the three columns
   virtual void setColumns
      (
      const EcVector& col0,
      const EcVector& col1,
      const EcVector& col2
      );

   /// sets the spatial matrix to all zeros
   virtual void setToZeros
      (
      );

   /// sets this to the direction cosine (rotation) matrix
   virtual void setToDcm
      (
      const EcOrientation& orientation
      );

   /// returns a row by index (0, 1, or 2) - const version.
   const EcVector& operator[]
      (
      EcU32 index
      ) const;

   /// returns a row by index (0, 1, or 2) - nonconst version.
   EcVector& operator[]
      (
      EcU32 index
      );

   /// return the transpose
   virtual EcSpatialMatrix transpose
      (
      ) const;

   /// set self to transpose
   virtual void setToTranspose
      (
      );

   /// set self to the cross-product matrix for a vector
   virtual void setToCrossProductMatrix
      (
      const EcVector& vec
      );

   /// multiply on the right by another spatial matrix
   virtual void multiplyOnRightBy
      (
      const EcSpatialMatrix sm2
      );

   /// multiply on the left by another spatial matrix
   virtual void multiplyOnLeftBy
      (
      const EcSpatialMatrix sm2
      );

   /// multiply on the left by a vector
   virtual void multiplyOnLeftBy
      (
      const EcVector& vec,
      EcVector& output
      )const;

   /// multiply on the right by the cross-product matrix for vec
   virtual void multiplyOnRightByCrossProductMatrix
      (
      const EcVector& vec
      );

   /// multiply on the left by the cross-product matrix for vec
   virtual void multiplyOnLeftByCrossProductMatrix
      (
      const EcVector& vec
      );

   /// add the self-outer product of a vector to the matrix
   /// i.e. J = J + v.v^T
   virtual void addSelfOuterProduct
      (
      const EcVector& v
      );

   /// add a weighted self-outer product of a vector to the matrix
   /// i.e. J = J + a*v.v^T
   virtual void addWeightedSelfOuterProduct
      (
      const EcVector& v,
      EcReal a
      );

   /// tranforms the spatial matrix into a new frame.  The result
   /// is J = R J R^T.
   virtual EcSpatialMatrix& transformBy
      (
      const EcOrientation& orientation
      );

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcSpatialMatrix& sm2,
      EcReal tol
      ) const;

   /// get the matrix as a real array
   virtual void getArray
      (
      EcReArray& array
      ) const;

   /// calculate the Cholesky Decomposition of a symmetric, positive
   /// definite matrix
   virtual EcBoolean choleskyDecomposition
      (
      EcSpatialMatrix& choleskyL
      ) const;

   /// calculate the inverse of a symmetric, positive
   /// definite matrix
   virtual EcBoolean getSymmetricPositiveDefiniteInverse
      (
      EcSpatialMatrix& inverse
      ) const;

   /// calculate the eigensystem of the symmetric matrix
   /// returns sorted eigenvalues (descending) and normalized
   /// eigenvectors.
   virtual EcBoolean getSymmetricEigensystem
      (
      EcVector& eigenvalues,
      EcVector& eigenvector0,
      EcVector& eigenvector1,
      EcVector& eigenvector2
      ) const;

   /// calculate the symmetric spatial matrix from its eigensystem.
   /// Only works for symmetric matrices.
   virtual void setFromSymmetricEigensystem
      (
      const EcVector& eigenvalues,
      const EcVector& eigenvector0,
      const EcVector& eigenvector1,
      const EcVector& eigenvector2
      );

   /// a (mostly string) token for this class
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get an identity matrix
   static EcSpatialMatrix identity
      (
      );

   /// get a diagonal matrix
   static EcSpatialMatrix diagonal
      (
      EcReal a00,
      EcReal a11,
      EcReal a22
      );

   /// get a zero matrix
   static EcSpatialMatrix nullObject
      (
      );

   /// make a cross-product matrix, i.e., M such that M*p = vector x p for all p
   static EcSpatialMatrix crossProductMatrix
      (
      const EcVector& vector
      );

protected:

   /// Row vector 0
   EcXmlVector      m_Row0;

   /// Row vector 1
   EcXmlVector      m_Row1;

   /// Row vector 2
   EcXmlVector      m_Row2;
};

/// an XML vector of matrices
typedef EcXmlVectorType<EcSpatialMatrix> EcSpatialMatrixVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// returns the negative of a spatial matrix
inline EC_FOUNDATION_FOUNDCOMMON_DECL EcSpatialMatrix operator -
   (
   const EcSpatialMatrix& orig
   )
{
   return EcSpatialMatrix(-orig.row0(),-orig.row1(),-orig.row2());
}

#endif // ecSpatialMatrix_H_
