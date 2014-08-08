#ifndef ecExpDiagMatrix_H_
#define ecExpDiagMatrix_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpDiagMatrix.h
/// @class EcExpressionDiagonalMatrix
/// @brief An element of an expression tree.  Holds a general (mxn)
///        diagonal matrix.  All off-diagonal entries are zero.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include <xml/ecXmlVectorType.h>

class EcExpressionContainer;

/// An element of an expression tree.  Holds a general (mxn) diagonal matrix.
/** All off-diagonal entries are zero.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionDiagonalMatrix : public EcExpressionElement
{
public:
   /// default constructor
   EcExpressionDiagonalMatrix
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionDiagonalMatrix
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionDiagonalMatrix
      (
      );

   /// copy constructor
   EcExpressionDiagonalMatrix
      (
      const EcExpressionDiagonalMatrix& orig
      );

   /// assignment operator
   EcExpressionDiagonalMatrix& operator=
      (
      const EcExpressionDiagonalMatrix& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionDiagonalMatrix& orig
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

   /// return the value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// assign all diagonals to be one value
   virtual void assign
      (
      const EcU32 rowSize,
      const EcU32 columnSize,
      const EcReal& diagonalValue
      );

   /// gets the number of matrix rows
   virtual const EcU32 rowSize
      (
      ) const;

   /// sets the number of matrix rows
   virtual void setRowSize
      (
      const EcU32 rowSize
      );

   /// gets the number of matrix columns
   virtual const EcU32 columnSize
      (
      ) const;

   /// sets the number of matrix columns
   virtual void setColumnSize
      (
      const EcU32 columnSize
      );

   /// gets the vector of diagonal entries
   virtual const EcXmlRealVector& diagonal
      (
      ) const;

   /// sets the vector of diagonal entries
   virtual void setDiagonal
      (
      const EcXmlRealVector& diagonal
      );

   /// return a token
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

   /// get a null object
   static EcExpressionDiagonalMatrix nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   EcXmlU32         m_RowSize;      ///< the row size
   EcXmlU32         m_ColumnSize;   ///< the column size
   EcXmlRealVector  m_Diagonal;     ///< the diagonal elements
};

#endif // ecExpDiagMatrix_H_
