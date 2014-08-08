#ifndef ecReArray_H_
#define ecReArray_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecReArray.h
/// @class EcReArray
/// @brief Holds a class to describe real arrays.  Includes operations such
///        as addition, subtraction, and multiplication.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecVector.h>

class EC_STABLE_MATRIXUTILITIES_DECL EcReArray
{
public:
   /// default constructor
   EcReArray
      (
      );

   /// constructor with row and column sizes
   EcReArray
      (
      EcU32 rows,
      EcU32 columns
      );

   /// destructor
   virtual ~EcReArray
      (
      );

   /// copy constructor
   EcReArray
      (
      const EcReArray& orig
      );

   /// Pass-through method to treat EcReArray as an STL vector.
   EcRealVector& operator[]
      (
      EcRealVector::size_type index
      ) { return m_vvInternal[index]; }

   /// Pass-through method to treat EcReArray as an STL vector.
   const EcRealVector& operator[]
      (
      EcRealVector::size_type index
      ) const { return m_vvInternal[index]; }

   /// Pass-through method to treat EcReArray as an STL vector.
   void assign
      (
      EcRealVector::size_type size,
      const EcRealVector& v
      ) { m_vvInternal.assign(size, v); }

   /// Pass-through method to treat EcReArray as an STL vector.
   void clear
      (
      ) { m_vvInternal.clear(); }

   /// Pass-through method to treat EcReArray as an STL vector.
   void push_back
      (
      const EcRealVector& v
      ) { m_vvInternal.push_back(v); }

   /// Pass-through method to treat EcReArray as an STL vector.
   void reserve
      (
      EcRealVector::size_type size
      ) { m_vvInternal.reserve(size); }

   /// Pass-through method to treat EcReArray as an STL vector.
   void resize
      (
      EcRealVector::size_type newsize,
      EcRealVector v = EcRealVector()
      ) { m_vvInternal.resize(newsize, v); }

   /// Pass-through method to treat EcReArray as an STL vector.
   EcRealVector::size_type size
      (
      ) const { return m_vvInternal.size(); }

   /// Provide implicit type conversion to an EcRealVectorVector.
   operator EcRealVectorVector&() { return m_vvInternal; }

   /// assignment operator
   EcReArray& operator=
      (
      const EcReArray& orig
      );

   /// assignment from a vector representing a single column
   EcReArray& operator=
      (
      const EcRealVector& vOrig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcReArray& other
      ) const;

   /// Adds the minimum compatible subset of the two
   /// matrices.
   EcReArray operator+
      (
      const EcReArray& other
      ) const;

   /// Adds the minimum compatible subset of the two
   /// matrices and sets this to the result.
   EcReArray& operator+=
      (
      const EcReArray& other
      );

   /// Subtracts the minimum compatible subset of the two
   /// matrices.
   EcReArray operator-
      (
      const EcReArray& other
      ) const;

   /// Subtracts the minimum compatible subset of the two
   /// matrices and sets this to the result.
   EcReArray& operator-=
      (
      const EcReArray& other
      );

   /// Multiplies the minimum compatible subset of the two
   /// matrices.  (This is matrix multiplication, not element-
   /// by-element multiplication.)
   EcReArray operator*
      (
      const EcReArray& other
      ) const;

   /// Multiplies the minimum compatible subset of the matrix
   /// and the vector.
   EcRealVector operator*
      (
      const EcRealVector& vOther
      ) const;

   /// Multiplies a 3x3 array with a vector 3x1
   /**
   \param[in] vOther A 3x1 vector to be multiplied.
   \return The 3x1 vector after multiplication. If this matrix has fewer than 3 rows or 3 columns, then the return vector will contain all zeros.
   */
   EcVector operator*
      (
      const EcVector& vOther
      ) const;

   /// Multiplies every entry by the scalar.
   /**
   \param[in] scalar The scalar to be multiplied.
   \return This matrix after multiplication.
   */
   EcReArray& operator*=
      (
      EcReal scalar
      );

   /// Multiplies every entry by the scalar.
   /**
   \param[in] scalar The scalar to be multiplied.
   \return The result after multiplication.
   */
   EcReArray operator*
      (
      EcReal scalar
      )const;

   /// Returns the trace of a square matrix
   /// The trace is the sum of the diagonal
   /// terms.  If the matrix is not square,
   /// zero is returned.
   virtual EcReal trace
      (
      ) const ;

   /// Set the matrix to a diagonal matrix with diagonal elements
   /// equal to the input and zeros elsewhere
   /**
   \param[in] vDiagTerms The vector used to set the diagonal terms of the matrix.
   */
   void setToDiagonal
      (
      const EcRealVector& vDiagTerms
      ) ;

   /// Multiplies the compatible subset of the first
   /// matrix to get the second.  (This is matrix multiplication,
   /// not element-by-element multiplication.)
   /**
   \param[in] from A matrix to be multiplied with this matrix.
   \param[out] to A matrix containing the result of the muliplication.
   */
   virtual void transform
      (
      const EcReArray& from,
      EcReArray& to
      ) const;

   /// Multiplies the compatible subset of the first
   /// vector to get the second.  (This is matrix multiplication,
   /// not element-by-element multiplication.)
   /**
   \param[in] vFrom A vector to be multiplied with this matrix.
   \param[out] vTo A vector containing the result of the muliplication.
   */
   virtual void transform
      (
      const EcRealVector& vFrom,
      EcRealVector& vTo
      ) const;

   /// Multiplies the compatible subset of the first
   /// vector to get the matrix.  (This is matrix multiplication,
   /// not element-by-element multiplication.)
   /// The vector is treated as a column vector.
   /**
   \param[in] vFrom A vector to be multiplied with this matrix.
   \param[out] to A matrix containing the result of the muliplication.
   */
   virtual void transform
      (
      const EcRealVector& vFrom,
      EcReArray& to
      ) const;

   /// Multiplies the compatible subset of the first
   /// vector by the transpose of this array to get the second.
   /// (This is matrix multiplication, not element-by-element
   /// multiplication.)
   /**
   \param[in] vFrom A vector to be multiplied with the transpose of this matrix.
   \param[out] vTo A vector containing the result of the muliplication.
   */
   virtual void transposeTransform
      (
      const EcRealVector& vFrom,
      EcRealVector& vTo
      ) const;

   /// Multiplies the minimum compatible subset of the transpose
   /// of the first matrix (this) by the second matrix (from)
   /// to get the the result matrix (to).
   /// (This is matrix multiplication, not element-by-element
   ///  multiplication.)
   /**
   \param[in] from A matrix to be multiplied with the transpose of this matrix.
   \param[out] to A matrix containing the result of the muliplication.
   */
   virtual void leftTransposeTransform
      (
      const EcReArray& from,
      EcReArray& to
      ) const;

   /// Multiplies the minimum compatible subset of the transpose
   /// of the first matrix (this) by the second vector (from)
   /// to get the the result matrix (to).
   /// (This is matrix multiplication, not element-by-element
   ///  multiplication.)
   /// The vector is treated as a column vector.
   /**
   \param[in] vFrom A vector to be multiplied with the transpose of this matrix.
   \param[out] to A matrix containing the result of the muliplication.
   */
   virtual void leftTransposeTransform
      (
      const EcRealVector& vFrom,
      EcReArray& to
      ) const;

   /// element-by-element inverse.
   /**
   \param[out] result The element-by-element inverse of this matrix.
   */
   virtual void elementInverse
      (
      EcReArray& result
      ) const;

   /// element-by-element cosine.
   /**
   \param[out] result The element-by-element cosine of this matrix.
   */
   virtual void elementCosine
      (
      EcReArray& result
      ) const;

   /// element-by-element sine.
   /**
   \param[out] result The element-by-element sine of this matrix.
   */
   virtual void elementSine
      (
      EcReArray& result
      ) const;

   /// Returns the log (base e) of this EcReArray
   /**
	\param[out] result The element-by-element log (base e) of this EcReArray.
   */
   virtual void elementLog
      (
      EcReArray& result
      )  const ;

   /// Retuns element-by-element log (base n) of this EcReArray
   /**
	\param[out] result The element-by-element log (base n) of this EcReArray.
	\param[in] base The base of log.
   */
   virtual void elementLogN
      (
      EcReArray& result,
      EcReal base
      ) const  ;

   /// element-by-element pow.
   /**
	\param[out] result The element-by-element pow of this matrix.
	\param[in] exp The exponential for pow.
   */
   virtual void elementPow
      (
      EcReArray& result,
      EcReal exp
      )  const ;

   /// Retuns transpose.  Returns by copy.
   virtual EcReArray transpose
      (
      ) const;

   /// matrix transpose
   /**
   \param[out] result The transpose of this matrix.
   */
   virtual void transpose
      (
      EcReArray& result
      ) const;

   /// add the self-outer product of a vector to the matrix
   /// i.e. J = J + v.v^T, where J is this matrix.
   /**
   \param[in] v The vector v in J = J + v.v^T.
   */
   virtual void addSelfOuterProduct
      (
      const EcRealVector& v
      );

   /// add a weighted self-outer product of a vector to the matrix
   /// i.e. J = J + a*v.v^T, where J is this matrix.
   /**
   \param[in] v The vector v in J = J + a*v.v^T.
   \param[in] a The weight a in J = J + a*v.v^T.
   */
   virtual void addWeightedSelfOuterProduct
      (
      const EcRealVector& v,
      EcReal a
      );

   /// calculate the Cholesky decomposition of a symmetric, positive definite matrix
   virtual EcBoolean choleskyDecomposition
      (
      EcReArray& choleskyL
      ) const;

   /// Perform a forward substitution with L, followed by a back substitution
   /// with L^T.  If L is calculated using choleskyDecomposition() on matrix M, this
   /// finds x = M^-1 y.
   virtual EcBoolean choleskyBackSubstitution
      (
      const EcReArray& input,
      EcReArray& result
      ) const;

   /// Perform a forward substitution with L, followed by a back substitution
   /// with L^T on the transpose of the input.  If L is calculated using
   /// choleskyDecomposition() on matrix M, this finds x = M^-1 y^T.
   virtual EcBoolean choleskyBackSubstitutionOnTranspose
      (
      const EcReArray& input,
      EcReArray& result
      ) const;

   /// Perform a forward substitution with L.  This finds
   /// finds x = L^-1 y for lower-triangular L.
   virtual EcBoolean lowerTriangularForwardSubstitution
      (
      const EcReArray& input,
      EcReArray& result
      ) const;

   /// Perform a forward substitution with L.  This finds
   /// finds x = L^-1 y^T for lower-triangular L.
   virtual EcBoolean lowerTriangularForwardSubstitutionOnTranspose
      (
      const EcReArray& input,
      EcReArray& result
      ) const;

   /// Finds the under-constrained normal equations.  For input J, this gives
   /// J*J^T.
   /**
   \param[out] squareResult The matrix J*J^T, where J is this matrix.
   */
   virtual EcBoolean underconstrainedNormal
      (
      EcReArray& squareResult
      ) const;

   /// Finds the over-constrained normal equations.  For input J, this gives
   /// J^T*J.
   /**
   \param[out] squareResult The matrix J^T*J, where J is this matrix.
   */
   virtual EcBoolean overconstrainedNormal
      (
      EcReArray& squareResult
      ) const;

   /// tests that each element of this is within a tolerance of another
   /**
   \param[in] other The other matrix to test against.
   \param[in] tol The specified tolerance.
   \return True if this matrix is within a tolerance of other. False if the sizes of the two matrices don't match or if this at least one element of this matrix is not within a tolerance of other.
   */
   virtual EcBoolean approxEq
      (
      const EcReArray& other,
      EcReal tol
      ) const;

   /// calculates the maximum absolute row sum (or infinity norm)
   virtual EcReal infinityNorm
      (
      ) const;

   /// gets the number of rows
   virtual EcU32 rows
      (
      ) const;

   /// gets the number of columns
   virtual EcU32 columns
      (
      ) const;

   /// set to an array of zeros
   virtual void setToZeros
      (
      EcU32 rows,
      EcU32 columns
      );

   /// set to an array of the given value
   virtual void setToValue
      (
      EcU32 rows,
      EcU32 columns,
      EcReal value
      );

   /// set to all zeros with ones on the diagonal
   virtual void setToIdentity
      (
      EcU32 rows,
      EcU32 columns
      );

   /// resize array
   virtual void resizeArray
      (
      EcU32 rows,
      EcU32 columns
      );

   /// copy the entries of another to within the current array
   virtual void copyEntriesOf
      (
      const EcReArray& other
      );

   /// assign the specified column to a real vector
   /**
   \param[in] column The column to be assigned.
   \param[out] vector The vector containing the elements in the specified column.
   */
   virtual void assignColumnTo
      (
      EcU32 column,
      EcRealVector& vector
      ) const;

   /// assign the specified row to a real vector
   /**
   \param[in] row The row to be assigned.
   \param[out] vector The vector containing the elements in the specified row.
   */
   virtual void assignRowTo
      (
      EcU32 row,
      EcRealVector& vector
      ) const;

   /// get an identity transformation
   static EcReArray nullObject
      (
      );

   /// calculate the LU decomposition of the first mm rows and return the
   /// result into the original matrix
   /**
   \param[in] nRows The number of rows to work on (the first nRows rows). If 0, then all rows will be used.
   \param[out] vIndices The pivot column index vector.
   */
   virtual EcBoolean LUDecomposition
      (
      EcU32 nRows,                     // works on the first n rows (do all if no input)
      EcU32Vector& vIndices            // pivot column index vector
      );

   /// Perform forward and back substitution after  a LU decomposition
   /// to solve Ax=b, where A=L*U.
   /**
   \param[in] indices The index vector produced by pivoting from LUDecomposition.
   \param[in] b The vector b in Ax=b.
   \param[out] x The solution vector in Ax=b.
   \param[out] det The determinant of A.
   */
   virtual EcBoolean forwardAndBackSub
      (
      const EcU32Vector&   indices,    // indices produced by pivoting from LUDecomposition
      const EcRealVector&    b,          // b
      EcRealVector&          x,          // x
      EcReal& det                      // determinant of A
      ) const;

   /// Solving the linear system Ax=b, content of A will be altered
   /**
   \param[in] b The vector b in Ax=b.
   \param[out] x The solution vector x in Ax=b.
   \param[out] pDet Optionally, the determinant of A.
   */
   virtual EcBoolean solve
      (
      const EcRealVector& b,    // b in Ax=b
      EcRealVector& x,          // x in Ax=b
      EcReal* pDet=0            // optional determinant return
      );

   /// invert the matrix
   virtual EcBoolean invertSquareMatrix
      (
      );

   /// calculate the LU decomposition of the first n rows and return the
   /// result into the original sparse matrix
   /**
   \param[in] nRows The number of rows to work on (the first nRows rows). If 0, then all rows will be used.
   \param[out] vIndices The pivot column index vector.
   \param[in] vSparseInd The sparse column index vector.
   \param[in] vZeroStart The zero start column index vector.
   */
   virtual EcBoolean LUDecompositionSparse
      (
      EcU32 nRows,                             // works on the first n rows (do all if no input)
      EcU32Vector& vIndices,                   // pivot column index vector
      const EcU32Vector& vSparseInd,           // sparse column index vector
      const EcU32Vector& vZeroStart            // zero start column index vector
      );

   /// calculate determinant of a square matrix by performing the LU decomposition of
   /// and return the product of the pivots (sign change by indices)
   /**
   \warning Calculating the determinant changes this matrix.
   */
   virtual EcReal determinant
      (
      );

   /// calculate the null space.
   /**
   \warning After this calculation, the entries of this matrix will be changed to its LU decomposition.
   \param[out] nSpace The matrix containing the null space output.
   \param[in] nRows The number of rows to work on (the first nRows rows). If 0, then all rows will be used.
   \param[out] vIndices The pivot column index vector.
   */
   virtual EcBoolean nullSpace
      (
      EcReArray& nSpace,                 // the null space output
      EcU32 nRows,                       // the rows in this array that are used
      EcU32Vector& vIndices              // pivot Column index vector (default to nullobject)
	  );

   /// calculate the null space.
   /**
   \warning After this calculation, the entries of this matrix will be changed to its LU decomposition.
   \param[out] nSpace The matrix containing the null space output.
   \param[in] nRows The number of rows to work on (the first nRows rows). If 0, then all rows will be used.
   \param[out] vIndices The pivot column index vector.
   \param[in] vSparseInd The sparse column index vector.
   \param[in] vZeroStart The zero start column index vector.
   */
   virtual EcBoolean nullSpaceSparse
      (
      EcReArray& nSpace,                         // the null space output
      EcU32 nRows,                               // the rows in this array that are used
      EcU32Vector& vIndices,                     // pivot Column index vector
      const EcU32Vector& vSparseInd,             // sparse column index vector
      const EcU32Vector& vZeroStart              // zero start column index vector
      );

   /// calculate a set of zero-start indices for this matrix, unpivoted
   /// these are the starting locations of terminal zeros on each row, with
   /// the constraint that they are nondecreasing.
   /**
   \param[out] vZeroStartIndices A set of zero-start indices for this matrix.
   */
   virtual EcBoolean calculateZeroStartIndices
      (
      EcU32Vector& vZeroStartIndices
      ) const;

   /// dump the data into a file for debug purpose, with Matlab style matrix definition.
   /**
   \param[in] fileName The name of the file to dump the data to.
   \return True if succeeded or false otherwise.
   */
   virtual EcBoolean dump
	  (
	  const char* fileName
  	  ) const;

   /// dump the data into a file for debug purpose, with Mathematica style matrix definition.
   /**
   \param[in] fileName The name of the file to dump the data to.
   \return True if succeeded or false otherwise.
   */
   virtual EcBoolean dumpMath
	  (
	  const char* fileName
  	  ) const;

   /// combine swapping indices
   virtual EcBoolean combineIndices
      (
      const EcU32Vector& vInd1,
      const EcU32Vector& vInd2,
      EcU32Vector& vIndResult
      ) const;

   /// calculate inverse of a 2x2 in closed form
   virtual EcBoolean inv2
      (
      EcReArray& M2     // result matrix
      ) const;

   /// calculate inverse of a 3x3 in closed form
   virtual EcBoolean inv3
      (
      EcReArray& M2     // result matrix
      ) const;

   /// write out the data in binary format
   /**
   \param[in] fname The name of the file to write the data to.
   \return True if succeeded or false otherwise.
   */
   virtual EcBoolean writeBin
      (
      const EcString& fname
      )const;

   /// read in data in binary format.  Set to this
   /**
   \param[in] fname The name of the file to read the data from.
   \return True if succeeded or false otherwise.
   */
   virtual EcBoolean readBin
      (
      const EcString& fname
      );


   /// return a column of this array
   virtual void getColumn
      (
      EcRealVector& vCol,     // destination
      const EcU32   col       // column number
      ) const;

private:
   /// utility indices for calculating the determinant
   mutable EcU32Vector m_vIndices;    

   // temporary parameters as member variables for speed
   mutable EcU32Vector m_vColOrder1;    ///< temporary vector for column order 1
   mutable EcU32Vector m_vColOrder2;    ///< temporary vector for column order 1
   mutable EcU32Vector m_vColOrder3;    ///< temporary vector for column order 1

   EcRealVector m_vTempVec;             ///< temporary real vector 1
   EcRealVector m_vTempVec2;            ///< temporary real vector 2

   EcRealVectorVector m_TempArray;      ///< temp array 1
   EcRealVectorVector m_vvInternal;     ///< temp array 2
};

/// convenience type for the jacobian
typedef EcReArray EcManipulatorJacobian;

/// convenience type for a vector of jacobians using std::vector
typedef std::vector<EcManipulatorJacobian> EcManipulatorJacobianVector;

/// Vector of EcReArray using std::vector
typedef std::vector<EcReArray>             EcReArrayVector;

/// A 2D vector of arrays using std::vector
typedef std::vector<EcReArrayVector>       EcReArrayVectorVector;

// -----------------------------------------------
// read in and write out below
// -----------------------------------------------

/// reads the array from a stream
/// @todo move implementation to cpp file
inline EC_STABLE_MATRIXUTILITIES_DECL std::ostream& operator<<
   (
   std::ostream& stream,
   const EcReArray& val
   )
{
   stream << val.rows() << std::endl;
   const EcU32 size = val.rows();
   for(EcU32 ii=0; ii<size; ++ii)
   {
      // write the row size
      stream << val[ii].size() << " ";

      const EcU32 sizeCol = static_cast<EcU32>(val[ii].size());
      for(EcU32 jj=0; jj<sizeCol; ++jj)
      {
         stream << val[ii][jj] << " ";
      }

      stream << std::endl;
   }

   return stream;
}


/// writes the array to a stream
/// @todo move implementation to cpp file
inline EC_STABLE_MATRIXUTILITIES_DECL std::istream& operator>>
   (
   std::istream& stream,
   EcReArray& val
   )
{
   EcU32  rows;
   EcU32  size;
   EcReal value;


   stream >> rows;
   val.reserve(rows);

   for(EcU32 ii=0; ii<rows; ++ii)
   {
      stream >> size;
      EcRealVector vec;
      vec.clear();
      vec.reserve(size);

      for(EcU32 jj=0; jj<size; ++jj)
      {
         stream >> value;
         vec.push_back(value);
      }

      val.push_back(vec);
   }

   return stream;
}


// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// returns the negative of an EcReArray
EC_STABLE_MATRIXUTILITIES_DECL EcReArray operator -
   (
   const EcReArray& a1
   );

/// returns the negative of an EcReArray
EC_STABLE_MATRIXUTILITIES_DECL EcRealVector operator *
   (
   const EcRealVector& vec
   );

#endif // ecReArray_H_
