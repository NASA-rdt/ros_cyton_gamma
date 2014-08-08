#ifndef ecBinaryDirectionCondition_H_
#define ecBinaryDirectionCondition_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBinaryDirectionCondition.h
/// @class EcBinaryDirectionCondition
/// @brief Abstract EcDirectionCondition for binary operations on two conditions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectionCondition.h"
#include "ecDirectionConditionContainer.h"

/// Abstract EcDirectionCondition for binary operations on two conditions.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcBinaryDirectionCondition : public EcDirectionCondition
{
public:
   /// default constructor
   EcBinaryDirectionCondition
      (
      );

   /// destructor
   virtual ~EcBinaryDirectionCondition
      (
      );

   /// copy constructor
   EcBinaryDirectionCondition
      (
      const EcBinaryDirectionCondition& orig
      );

   /// assignment operator
   EcBinaryDirectionCondition& operator=
      (
      const EcBinaryDirectionCondition& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBinaryDirectionCondition& orig
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

   /// get the LHS condition container
   virtual const EcDirectionConditionContainer& lhsConditionContainer
      (
      ) const;

   /// set the LHS condition container
   virtual void setLhsConditionContainer
      (
      const EcDirectionConditionContainer& container
      );

   /// set the LHS condition
   virtual void setLhsCondition
      (
      const EcDirectionCondition& condition
      );

   /// get the RHS condition container
   virtual const EcDirectionConditionContainer& rhsConditionContainer
      (
      ) const;

   /// set the RHS condition container
   virtual void setRhsConditionContainer
      (
      const EcDirectionConditionContainer& container
      );

   /// set the RHS condition
   virtual void setRhsCondition
      (
      const EcDirectionCondition& condition
      );

   /// get a vector of role names that are referenced within this action direction
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

protected:
   /// LHS (left-hand side) condition
   EcDirectionConditionContainer m_LhsConditionContainer;

   /// RHS (right-hand side) condition
   EcDirectionConditionContainer m_RhsConditionContainer;
};

#endif // ecBinaryDirectionCondition_H_
