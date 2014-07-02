#ifndef ecExpLE_H_
#define ecExpLE_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpLE.h
/// @class EcExpressionLessThanOrEqualTo
/// @brief Performs a logical Less Than or Equal to (LE) operation on
///        the two child nodes.  Returns true for each element in
///        the LHS thats greater than or equal to the corresponding
///        element in the RHS.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a less-than-equal-to operator.
/** The value() method returns the result of the two children.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionLessThanOrEqualTo : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionLessThanOrEqualTo
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionLessThanOrEqualTo
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionLessThanOrEqualTo
      (
      );

   /// copy constructor
   EcExpressionLessThanOrEqualTo
      (
      const EcExpressionLessThanOrEqualTo& orig
      );

   /// assignment operator
   EcExpressionLessThanOrEqualTo& operator=
      (
      const EcExpressionLessThanOrEqualTo& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionLessThanOrEqualTo& orig
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
   static EcExpressionLessThanOrEqualTo nullObject
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

#endif // ecExpLE_H_
