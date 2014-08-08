#ifndef ecExpOr_H_
#define ecExpOr_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpOr.h
/// @class EcExpressionOr
/// @brief Performs a logical OR operation on two children
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds an OR operator.
/** The value() method returns the result of the two children.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionOr : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionOr
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionOr
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionOr
      (
      );

   /// copy constructor
   EcExpressionOr
      (
      const EcExpressionOr& orig
      );

   /// assignment operator
   EcExpressionOr& operator=
      (
      const EcExpressionOr& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionOr& orig
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
   static EcExpressionOr nullObject
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

#endif // ecExpOr_H_
