#ifndef ecHasAttachmentCondition_H_
#define ecHasAttachmentCondition_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecHasAttachmentCondition.h
/// @class EcHasAttachmentCondition
/// @brief Concrete implementation of EcDirectionCondition for determining if the current role has an attachment.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectionCondition.h"
#include "ecDirectionConditionContainer.h"

/// Concrete implementation of EcDirectionCondition for determining if the current role has an attachment.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcHasAttachmentCondition : public EcDirectionCondition
{
public:
   /// default constructor
   EcHasAttachmentCondition
      (
      );

   /// destructor
   virtual ~EcHasAttachmentCondition
      (
      );

   /// copy constructor
   EcHasAttachmentCondition
      (
      const EcHasAttachmentCondition& orig
      );

   /// assignment operator
   EcHasAttachmentCondition& operator=
      (
      const EcHasAttachmentCondition& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcHasAttachmentCondition& orig
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

   /// get the attached role
   const EcString& attachedRole
      (
      ) const;

   /// set the attached role
   void setAttachedRole
      (
      const EcString& attachedRole
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
   /// the attached role
   EcXmlString m_AttachedRole;

   /// the link that the attached role is attached to
   EcXmlString m_BaseLink;
};

#endif // ecHasAttachmentCondition_H_
