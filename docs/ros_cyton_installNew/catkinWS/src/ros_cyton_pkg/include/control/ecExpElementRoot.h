#ifndef ecExpElementRoot_H_
#define ecExpElementRoot_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpElementRoot.h
/// @class EcExpressionElementRoot
/// @brief Returns the Nth root of the LHS child.  The RHS child
///        contains the value to use for N.  If the RHS child does
///        not exist, the square root is returned.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpBaseBinary.h"

class EcExpressionContainer;

/// An element of an expression tree.  Returns the Nth root of the LHS child.
/** The RHS child
    contains the value to use for N.  If the RHS child does
    not exist, the square root is returned.
*/
class EC_ACTIN_CONTROL_DECL EcExpressionElementRoot : public EcExpressionBaseBinary
{
public:
   /// default constructor - should not be used
   EcExpressionElementRoot
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionElementRoot
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionElementRoot
      (
      );

   /// copy constructor
   EcExpressionElementRoot
      (
      const EcExpressionElementRoot& orig
      );

   /// assignment operator
   EcExpressionElementRoot& operator=
      (
      const EcExpressionElementRoot& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionElementRoot& orig
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
   static EcExpressionElementRoot nullObject
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

#endif // ecExpElementRoot_H_
