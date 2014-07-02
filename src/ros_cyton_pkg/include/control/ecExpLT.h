#ifndef ecExpLT_H_
#define ecExpLT_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpLT.h
/// @class EcExpressionLessThan
/// @brief Performs a logical Less Than (LT) operation on the
///        two child nodes.  Returns true for each element in
///        the LHS thats less than the corresponding
///        element in the RHS.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a less-than operator.
/** The value() method returns the result of the two children.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionLessThan : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionLessThan
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionLessThan
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionLessThan
      (
      );

   /// copy constructor
   EcExpressionLessThan
      (
      const EcExpressionLessThan& orig
      );

   /// assignment operator
   EcExpressionLessThan& operator=
      (
      const EcExpressionLessThan& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionLessThan& orig
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
   static EcExpressionLessThan nullObject
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

#endif // ecExpLT_H_
