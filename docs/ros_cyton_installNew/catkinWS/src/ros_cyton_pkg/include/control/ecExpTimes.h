#ifndef ecExpTimes_H_
#define ecExpTimes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpTimes.h
/// @class EcExpressionTimes
/// @brief An element of an expression tree.  Holds a product operator.
///        The value() method returns the matrix product of the two children unless
///        one of the two children is a 1x1 matrix, in which case scalar
///        multiplication is used.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a product operator.
/** The value() method returns the product between the two children.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionTimes : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionTimes
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionTimes
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionTimes
      (
      );

   /// copy constructor
   EcExpressionTimes
      (
      const EcExpressionTimes& orig
      );

   /// assignment operator
   EcExpressionTimes& operator=
      (
      const EcExpressionTimes& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionTimes& orig
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
   static EcExpressionTimes nullObject
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

#endif // ecExpTimes_H_
