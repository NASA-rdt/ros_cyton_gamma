#ifndef ecStateConstraintContainer_H_
#define ecStateConstraintContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecStateConstraintContainer.h
/// @class EcStateConstraintContainer
/// @brief Container for a state constraint
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStateConstraint.h"
#include <xml/ecBaseExpTreeContainer.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of container of EcBaseStateConstraint to be used as a base class
typedef EcBaseExpressionTreeContainer<EcBaseStateConstraint> EcBaseStateConstraintContainer;

/// Container of EcBaseStateConstraint
class EC_FOUNDATION_MANIPULATOR_DECL EcStateConstraintContainer :
   public EcBaseStateConstraintContainer
{
public:
   /// default constructor
   EcStateConstraintContainer
      (
      );

   /// destructor
   virtual ~EcStateConstraintContainer
      (
      );

   /// copy constructor
   EcStateConstraintContainer
      (
      const EcStateConstraintContainer& orig
      );

   /// assignment operator
   EcStateConstraintContainer& operator=
      (
      const EcStateConstraintContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStateConstraintContainer& orig
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

   /// get a null object
   static EcStateConstraintContainer nullObject
      (
      );
};

#endif // ecStateConstraintContainer_H_
