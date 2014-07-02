#ifndef ecExpSine_H_
#define ecExpSine_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpSine.h
/// @class EcExpressionContainer
/// @brief An element of an expression tree.  Returns an array
///        of the same size as the child with all elements equal to the
///        sine of the same element in the child.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseUnary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a sine operator.
/** Returns an array
 of the same size as the child with all elements equal to the
 sine of the same element in the child.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionSine : public EcExpressionBaseUnary
{
public:
   /// default constructor - should not be used
   EcExpressionSine
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionSine
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionSine
      (
      );

   /// copy constructor
   EcExpressionSine
      (
      const EcExpressionSine& orig
      );

   /// assignment operator
   EcExpressionSine& operator=
      (
      const EcExpressionSine& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionSine& orig
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
   static EcExpressionSine nullObject
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

#endif // ecExpSine_H_
