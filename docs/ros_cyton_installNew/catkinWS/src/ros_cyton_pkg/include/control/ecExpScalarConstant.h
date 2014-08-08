#ifndef ecExpScalarConstant_H_
#define ecExpScalarConstant_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpScalarConstant.h
/// @class EcExpressionScalarConstant
/// @brief An element of an expression tree.
///        Holds a description of a scalar constant.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a description of a scalar constant.
class EC_ACTIN_CONTROL_DECL EcExpressionScalarConstant : public EcExpressionElement
{
public:
   /// default constructor
   EcExpressionScalarConstant
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionScalarConstant
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionScalarConstant
      (
      );

   /// copy constructor
   EcExpressionScalarConstant
      (
      const EcExpressionScalarConstant& orig
      );

   /// assignment operator
   EcExpressionScalarConstant& operator=
      (
      const EcExpressionScalarConstant& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionScalarConstant& orig
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

   /// return a value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the scalar
   virtual const EcReal scalar
      (
      ) const;

   /// sets the scalar
   virtual void setScalar
      (
      const EcReal scalar
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

   /// write this object to an XML stream
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// override to suppress the line break to the xml stream.
   virtual EcBoolean writeSuppressableLineBreak
      (
      std::ostream& stream
      ) const;

   /// get a null object
   static EcExpressionScalarConstant nullObject
      (
      );

   /// get an object with a given value
   static EcExpressionScalarConstant objectWithValue
      (
      EcReal value
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
   EcXmlReal        m_Scalar;
};

#endif // ecExpScalarConstant_H_
