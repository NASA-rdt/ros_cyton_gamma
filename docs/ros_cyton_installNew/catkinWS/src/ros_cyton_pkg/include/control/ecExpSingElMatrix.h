#ifndef ecExpSingElMatrix_H_
#define ecExpSingElMatrix_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpSingElMatrix.h
/// @class EcExpressionSingleElementMatrix
/// @brief An element of an expression tree.  Holds a general (mxn) matrix
///        with all zeros and but a single nonzero (or zero) element as specified
///        at the specified location.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a general (mxn) matrix operator
/** Holds a general (mxn) matrix
 with all zeros and but a single nonzero (or zero) element as specified
 at the specified location.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionSingleElementMatrix : public EcExpressionElement
{
public:
   /// default constructor
   EcExpressionSingleElementMatrix
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionSingleElementMatrix
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionSingleElementMatrix
      (
      );

   /// copy constructor
   EcExpressionSingleElementMatrix
      (
      const EcExpressionSingleElementMatrix& orig
      );

   /// assignment operator
   EcExpressionSingleElementMatrix& operator=
      (
      const EcExpressionSingleElementMatrix& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionSingleElementMatrix& orig
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

   /// gets the element row position
   virtual const EcU32 rowPosition
      (
      ) const;

   /// sets the element row position
   virtual void setRowPosition
      (
      const EcU32 rowPosition
      );

   /// gets the element column position
   virtual const EcU32 columnPosition
      (
      ) const;

   /// sets the element column position
   virtual void setColumnPosition
      (
      const EcU32 columnPosition
      );

   /// gets the elementValue
   virtual const EcReal elementValue
      (
      ) const;

   /// sets the element value
   virtual void setElementValue
      (
      const EcReal elementValue
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
   static EcExpressionSingleElementMatrix nullObject
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
   /// a pointer to the container
   EcXmlReal        m_ElementValue;    ///< the single element value
   EcXmlU32         m_RowSize;         ///< the row size
   EcXmlU32         m_ColumnSize;      ///< the column size
   EcXmlU32         m_RowPosition;     ///< the row position at which the element is located
   EcXmlU32         m_ColumnPosition;  ///< the column position at which the element is located
};

#endif // ecExpSingElMatrix_H_
