#ifndef ecExpElement_H_
#define ecExpElement_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpElement.h
/// @class EcExpressionElement
/// @brief Holds a description of a base class for expression elements.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeElement.h>
#include "ecVelContData.h"

class EcExpressionContainer;

/// Holds a description of a base class for expression elements.
class EC_ACTIN_CONTROL_DECL EcExpressionElement : public EcBaseExpressionTreeElement
{
public:
   /// default constructor - should not be used
   EcExpressionElement
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcExpressionElement
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcExpressionElement
      (
      );

   /// copy constructor
   EcExpressionElement
      (
      const EcExpressionElement& orig
      );

   /// assignment operator
   EcExpressionElement& operator=
      (
      const EcExpressionElement& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionElement& orig
      ) const;

   /// return a value
   virtual const EcVelocityControlData& value
      (
      ) const = 0;

protected:
   /// a real array to cache the returned value
   mutable EcVelocityControlData m_Array;
};

#endif // ecExpElement_H_
