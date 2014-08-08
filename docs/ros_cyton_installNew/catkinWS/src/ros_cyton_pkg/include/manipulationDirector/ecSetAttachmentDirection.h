#ifndef ecSetAttachmentDirection_H_
#define ecSetAttachmentDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSetAttachmentDirection.h
/// @class EcSetAttachmentDirection
/// @brief Concrete implementation of EcStageDirection for attaching another role to the specified link of this role in the scene.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecStageDirection.h"

#include <xml/ecXmlBasicType.h>

/// Concrete implementation of EcStageDirection for attaching another role to the specified link of this role in the scene.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcSetAttachmentDirection : public EcStageDirection
{
public:
   /// default constructor
   EcSetAttachmentDirection
      (
      );

   /// destructor
   virtual ~EcSetAttachmentDirection
      (
      );

   /// copy constructor
   EcSetAttachmentDirection
      (
      const EcSetAttachmentDirection& orig
      );

   /// assignment operator
   EcSetAttachmentDirection& operator=
      (
      const EcSetAttachmentDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSetAttachmentDirection& orig
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

   /// get the descriptor for this direction
   virtual const EcString descriptor
      (
      ) const;

   /// get a vector of role names that are referenced within this attachment direction
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// initialize the attachment direction
   virtual EcBoolean init
      (
      const EcManipulationDirector&               director,
      const EcString&                             role,
      EcManipulationSceneDirectionStateContainer& dstateContainer
      ) const;

   /// apply the attachment direction
   virtual EcBoolean apply
      (
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      EcManipulationDirectorState&              dstate
      ) const;

   /// convert the direction state
   virtual void convert
      (
      const EcManipulationSceneDirectionStateContainer& dstateContainer,
      EcManipulationSceneDirectionSimpleStateContainer& sdstateContainer
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
   /// the role to attach to this role
   EcXmlString m_AttachedRole;

   /// the link on the base role to attach to
   EcXmlString m_BaseLink;
};

#endif // ecSetAttachmentDirection_H_
