#ifndef ecExpMinus_H_
#define ecExpMinus_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpMinus.h
/// @class EcExpressionMinus
/// @brief An element of an expression tree.  Holds a difference operator.
///        The value() method returns the difference between the two children.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a difference operator.
/** The value() method returns the difference between the two children.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionMinus : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionMinus
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionMinus
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionMinus
      (
      );

   /// copy constructor
   EcExpressionMinus
      (
      const EcExpressionMinus& orig
      );

   /// assignment operator
   EcExpressionMinus& operator=
      (
      const EcExpressionMinus& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionMinus& orig
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
   static EcExpressionMinus nullObject
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

#endif // ecExpMinus_H_
