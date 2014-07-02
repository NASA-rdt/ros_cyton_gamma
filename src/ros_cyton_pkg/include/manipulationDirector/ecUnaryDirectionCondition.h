#ifndef ecUnaryDirectionCondition_H_
#define ecUnaryDirectionCondition_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecUnaryDirectionCondition.h
/// @class EcUnaryDirectionCondition
/// @brief Abstract EcDirectionCondition for unary operations on a wrapped condition.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectionCondition.h"
#include "ecDirectionConditionContainer.h"

/// Abstract EcDirectionCondition for unary operations on a wrapped condition.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcUnaryDirectionCondition : public EcDirectionCondition
{
public:
   /// default constructor
   EcUnaryDirectionCondition
      (
      );

   /// destructor
   virtual ~EcUnaryDirectionCondition
      (
      );

   /// copy constructor
   EcUnaryDirectionCondition
      (
      const EcUnaryDirectionCondition& orig
      );

   /// assignment operator
   EcUnaryDirectionCondition& operator=
      (
      const EcUnaryDirectionCondition& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcUnaryDirectionCondition& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// get the wrapped condition container
   virtual const EcDirectionConditionContainer& wrappedConditionContainer
      (
      ) const;

   /// set the wrapped condition container
   virtual void setWrappedConditionContainer
      (
      const EcDirectionConditionContainer& container
      );

   /// set the wrapped condition
   virtual void setWrappedCondition
      (
      const EcDirectionCondition& condition
      );

   /// get a vector of role names that are referenced within this action direction
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

protected:
   /// wrapped condition
   EcDirectionConditionContainer m_WrappedConditionContainer;
};

#endif // ecUnaryDirectionCondition_H_
