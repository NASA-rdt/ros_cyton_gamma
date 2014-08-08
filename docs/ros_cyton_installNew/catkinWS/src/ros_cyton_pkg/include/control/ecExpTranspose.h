#ifndef ecExpTranspose_H_
#define ecExpTranspose_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpTranspose.h
/// @class EcExpressionTranspose
/// @brief An element of an expression tree.  Returns the matrix
///        transpose of the child.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseUnary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Returns the matrix transpose of the child.
class EC_ACTIN_CONTROL_DECL EcExpressionTranspose : public EcExpressionBaseUnary
{
public:
   /// default constructor - should not be used
   EcExpressionTranspose
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionTranspose
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionTranspose
      (
      );

   /// copy constructor
   EcExpressionTranspose
      (
      const EcExpressionTranspose& orig
      );

   /// assignment operator
   EcExpressionTranspose& operator=
      (
      const EcExpressionTranspose& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionTranspose& orig
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
   static EcExpressionTranspose nullObject
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
};

#endif // ecExpTranspose_H_
