#ifndef ecExpGenColumn_H_
#define ecExpGenColumn_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpGenColumn.h
/// @class EcExpressionGeneralColumn
/// @brief An expression element to represent a general
///        (nx1) column matrix.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include <xml/ecXmlVectorType.h>

class EcExpressionContainer;

/// An element of an expression tree.  A general (nx1) column matrix.
class EC_ACTIN_CONTROL_DECL EcExpressionGeneralColumn : public EcExpressionElement
{
public:
   /// default constructor
   EcExpressionGeneralColumn
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionGeneralColumn
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionGeneralColumn
      (
      );

   /// copy constructor
   EcExpressionGeneralColumn
      (
      const EcExpressionGeneralColumn& orig
      );

   /// assignment operator
   EcExpressionGeneralColumn& operator=
      (
      const EcExpressionGeneralColumn& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionGeneralColumn& orig
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

   /// assign column size and all values as specified
   virtual void assign
      (
      const EcU32 size,
      const EcReal& value
      );

   /// set a single value
   virtual EcBoolean setValue
      (
      const EcU32 row,
      const EcReal& value
      );

   /// gets the vector of entries
   virtual const EcXmlRealVector& column
      (
      ) const;

   /// sets the vector of entries
   virtual void setColumn
      (
      const EcXmlRealVector& column
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
   static EcExpressionGeneralColumn nullObject
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
   EcXmlRealVector  m_Column;
};

#endif // ecExpGenColumn_H_
