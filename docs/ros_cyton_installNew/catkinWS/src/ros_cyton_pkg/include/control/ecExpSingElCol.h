#ifndef ecExpSingElCol_H_
#define ecExpSingElCol_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpSingElCol.h
/// @class EcExpressionSingleElementColumn
/// @brief An element of an expression tree.  Holds a column vector
///        with a single nonzero element.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a column vector with a single nonzero element.
class EC_ACTIN_CONTROL_DECL EcExpressionSingleElementColumn : public EcExpressionElement
{
public:
   /// default constructor
   EcExpressionSingleElementColumn
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionSingleElementColumn
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionSingleElementColumn
      (
      );

   /// copy constructor
   EcExpressionSingleElementColumn
      (
      const EcExpressionSingleElementColumn& orig
      );

   /// assignment operator
   EcExpressionSingleElementColumn& operator=
      (
      const EcExpressionSingleElementColumn& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionSingleElementColumn& orig
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

   /// gets the column size
   virtual const EcU32 size
      (
      ) const;

   /// sets the column size
   virtual void setSize
      (
      const EcU32 size
      );

   /// gets the element position
   virtual const EcU32 position
      (
      ) const;

   /// sets the element position
   virtual void setPosition
      (
      const EcU32 position
      );

   /// gets the elementValue
   virtual const EcReal elementValue
      (
      ) const;

   /// sets the element value
   virtual void setElementValue
      (
      const EcReal elementValue
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
   static EcExpressionSingleElementColumn nullObject
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
   EcXmlReal        m_ElementValue;    ///< the single element value
   EcXmlU32         m_Size;            ///< the size of the column vector
   EcXmlU32         m_Position;        ///< the position in the column vector at which the element is located
};

#endif // ecExpSingElCol_H_
