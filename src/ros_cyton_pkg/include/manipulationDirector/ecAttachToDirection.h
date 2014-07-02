#ifndef ecAttachToDirection_H_
#define ecAttachToDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecAttachToDirection.h
/// @class EcAttachToDirection
/// @brief Concrete implementation of EcStageDirection for attaching the role to a specified link of another role in the scene.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecStageDirection.h"

#include <xml/ecXmlBasicType.h>

/// Concrete implementation of EcStageDirection for attaching the role to a specified link of another role in the scene.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcAttachToDirection : public EcStageDirection
{
public:
   /// default constructor
   EcAttachToDirection
      (
      );

   /// destructor
   virtual ~EcAttachToDirection
      (
      );

   /// copy constructor
   EcAttachToDirection
      (
      const EcAttachToDirection& orig
      );

   /// assignment operator
   EcAttachToDirection& operator=
      (
      const EcAttachToDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAttachToDirection& orig
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
   /// the base role to attach to
   EcXmlString m_BaseRole;

   /// the link on the base role to attach to
   EcXmlString m_BaseLink;
};

#endif // ecAttachToDirection_H_
