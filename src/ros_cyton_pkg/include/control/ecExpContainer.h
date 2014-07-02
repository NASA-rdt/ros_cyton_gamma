#ifndef ecExpContainer_H_
#define ecExpContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecExpContainer.h
/// @class EcExpressionContainer
/// @brief Holds a manipulator-based mathematical expression.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <manipulator/ecStatedSystem.h>
#include "ecVelContData.h"
#include <matrixUtilities/ecReArray.h>
#include <xml/ecBaseExpTreeContainer.h>

#include "ecExpElement.h"

/// Holds a manipulator-based mathematical expression.
class EC_ACTIN_CONTROL_DECL EcExpressionContainer : public EcBaseExpressionTreeContainer<EcExpressionElement>
{
public:
   /// default constructor
   EcExpressionContainer
      (
      );

   /// destructor
   virtual ~EcExpressionContainer
      (
      );

   /// copy constructor
   EcExpressionContainer
      (
      const EcExpressionContainer& orig
      );

   /// assignment operator
   EcExpressionContainer& operator=
      (
      const EcExpressionContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExpressionContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// sets the container for the tree below to an alternate
   /// value.
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// return the calculated value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// get a null object
   static EcExpressionContainer nullObject
      (
      );

protected:
   /// set the container pointer for the top element to this
   virtual void setTopElementContainerToThis
      (
      );

   /// a static dummy array for error recovery
   static const EcVelocityControlData m_theDummy;
};

#endif // ecExpContainer_H_
