#ifndef ecExpElementPow_H_
#define ecExpElementPow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpElementPow.h
/// @class EcExpressionElementPow
/// @brief An element of an expression tree.  Returns an array
///        of the same size as the left child with all elements raised to the
///        the power N defined by the right child.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a pow operator.
/** Returns an array
    of the same size as the left child with all elements raised to the
    the power N defined by the right child.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionElementPow : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionElementPow
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionElementPow
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionElementPow
      (
      );

   /// copy constructor
   EcExpressionElementPow
      (
      const EcExpressionElementPow& orig
      );

   /// assignment operator
   EcExpressionElementPow& operator=
      (
      const EcExpressionElementPow& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionElementPow& orig
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
   static EcExpressionElementPow nullObject
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

#endif // ecExpElementPow_H_
