#ifndef ecExpCosine_H_
#define ecExpCosine_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpCosine.h
/// @class EcExpressionCosine
/// @brief An element of an expression tree.  Returns an array
///        of the same size as the child with all elements equal to the
///        cosine of the same element in the child.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseUnary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Cosine operator
/** Returns an array  of the same size as the child with all elements equal to the
 cosine of the same element in the child.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionCosine : public EcExpressionBaseUnary
{
public:
   /// default constructor - should not be used
   EcExpressionCosine
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionCosine
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionCosine
      (
      );

   /// copy constructor
   EcExpressionCosine
      (
      const EcExpressionCosine& orig
      );

   /// assignment operator
   EcExpressionCosine& operator=
      (
      const EcExpressionCosine& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionCosine& orig
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
   static EcExpressionCosine nullObject
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

#endif // ecExpCosine_H_
