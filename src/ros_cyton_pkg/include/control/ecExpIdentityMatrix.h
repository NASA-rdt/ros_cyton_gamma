#ifndef ecExpIdentityMatrix_H_
#define ecExpIdentityMatrix_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpIdentityMatrix.h
/// @class EcExpressionIdentityMatrix
/// @brief An element of an expression tree.  Holds an nxn identity matrix.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds an nxn identity matrix.
class EC_ACTIN_CONTROL_DECL EcExpressionIdentityMatrix : public EcExpressionElement
{
public:
   /// default constructor
   EcExpressionIdentityMatrix
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionIdentityMatrix
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionIdentityMatrix
      (
      );

   /// copy constructor
   EcExpressionIdentityMatrix
      (
      const EcExpressionIdentityMatrix& orig
      );

   /// assignment operator
   EcExpressionIdentityMatrix& operator=
      (
      const EcExpressionIdentityMatrix& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionIdentityMatrix& orig
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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the size
   virtual const EcU32 size
      (
      ) const;

   /// sets the size
   virtual void setSize
      (
      const EcU32 size
      );

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
   static EcExpressionIdentityMatrix nullObject
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

protected:
   /// a pointer to the container
   EcXmlU32         m_Size;
};

#endif // ecExpIdentityMatrix_H_
