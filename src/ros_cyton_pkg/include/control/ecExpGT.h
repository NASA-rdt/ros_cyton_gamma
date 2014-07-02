#ifndef ecExpGT_H_
#define ecExpGT_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpGT.h
/// @class EcExpressionGreaterThan
/// @brief Performs a logical Greater Than (GT) operation on the
///        two child nodes.  Returns true for each element in
///        the LHS thats greater than the corresponding
///        element in the RHS.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a greater-than operator.
/** The value() method returns the result of the two children.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionGreaterThan : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionGreaterThan
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionGreaterThan
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionGreaterThan
      (
      );

   /// copy constructor
   EcExpressionGreaterThan
      (
      const EcExpressionGreaterThan& orig
      );

   /// assignment operator
   EcExpressionGreaterThan& operator=
      (
      const EcExpressionGreaterThan& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionGreaterThan& orig
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
   static EcExpressionGreaterThan nullObject
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

#endif // ecExpGT_H_
