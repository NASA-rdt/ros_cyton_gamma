#ifndef ecExpElementLogN_H_
#define ecExpElementLogN_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpElementLogN.h
/// @class EcExpressionElementLogN
/// @brief An element of an expression tree.  Returns an array
///        of the same size as the left child containing the log (base N)
///        of each element. Where the base is contained
///        in the right child.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a logN operator.
/** Returns an array
    of the same size as the left child containing the log (base N)
    of each element. Where the base is contained
    in the right child.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionElementLogN : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionElementLogN
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionElementLogN
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionElementLogN
      (
      );

   /// copy constructor
   EcExpressionElementLogN
      (
      const EcExpressionElementLogN& orig
      );

   /// assignment operator
   EcExpressionElementLogN& operator=
      (
      const EcExpressionElementLogN& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionElementLogN& orig
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
   static EcExpressionElementLogN nullObject
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

#endif // ecExpElementLogN_H_
