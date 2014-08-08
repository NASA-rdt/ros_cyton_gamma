#ifndef ecIsAttachedToCondition_H_
#define ecIsAttachedToCondition_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecIsAttachedToCondition.h
/// @class EcIsAttachedToCondition
/// @brief Concrete implementation of EcDirectionCondition for determining if the role is attached to another role.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectionCondition.h"
#include "ecDirectionConditionContainer.h"

/// Concrete implementation of EcDirectionCondition for determining if the role is attached to another role.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcIsAttachedToCondition : public EcDirectionCondition
{
public:
   /// default constructor
   EcIsAttachedToCondition
      (
      );

   /// destructor
   virtual ~EcIsAttachedToCondition
      (
      );

   /// copy constructor
   EcIsAttachedToCondition
      (
      const EcIsAttachedToCondition& orig
      );

   /// assignment operator
   EcIsAttachedToCondition& operator=
      (
      const EcIsAttachedToCondition& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIsAttachedToCondition& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the base role
   const EcString& baseRole
      (
      ) const;

   /// set the base role
   void setBaseRole
      (
      const EcString& baseRole
      );

   /// get the base link
   const EcString& baseLink
      (
      ) const;

   /// set the base link
   void setBaseLink
      (
      const EcString& baseLink
      );

   /// get a vector of role names that are referenced within this condition
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// test the condition
   virtual EcBoolean test
      (
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      const EcManipulationDirectorState&        dstate
      ) const;

   /// return a text description of the condition
   virtual EcString text
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the base role to attach to
   EcXmlString m_BaseRole;

   /// the link on the base role to attach to
   EcXmlString m_BaseLink;
};

#endif // ecIsAttachedToCondition_H_
