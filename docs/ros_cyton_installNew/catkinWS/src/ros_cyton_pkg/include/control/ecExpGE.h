#ifndef ecExpGE_H_
#define ecExpGE_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpGE.h
/// @class EcExpressionGreaterThanOrEqualTo
/// @brief Performs a logical Greater Than or equal to (GE) operation
///        on the two child nodes.  Returns true for each element in
///        the LHS thats greater than the corresponding
///        element in the RHS.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a >= operator.
class EC_ACTIN_CONTROL_DECL EcExpressionGreaterThanOrEqualTo : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionGreaterThanOrEqualTo
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionGreaterThanOrEqualTo
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionGreaterThanOrEqualTo
      (
      );

   /// copy constructor
   EcExpressionGreaterThanOrEqualTo
      (
      const EcExpressionGreaterThanOrEqualTo& orig
      );

   /// assignment operator
   EcExpressionGreaterThanOrEqualTo& operator=
      (
      const EcExpressionGreaterThanOrEqualTo& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionGreaterThanOrEqualTo& orig
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
   static EcExpressionGreaterThanOrEqualTo nullObject
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

#endif // ecExpGE_H_
