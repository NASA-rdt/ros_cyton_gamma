#ifndef ecManipulationActionDirectorObject_H_
#define ecManipulationActionDirectorObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationActionDirectorObject.h
/// @class EcManipulationActionDirectorObject
/// @brief Concrete implementation of EcDirectorObject that holds an EcManipulationAction object.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectorObject.h"
#include <manipulation/ecManipulationActionContainer.h>

/// Concrete implementation of EcDirectorObject that holds an EcManipulationAction object.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationActionDirectorObject : public EcDirectorObject
{
public:
   /// default constructor
   EcManipulationActionDirectorObject
      (
      );

   /// destructor
   virtual ~EcManipulationActionDirectorObject
      (
      );

   /// copy constructor
   EcManipulationActionDirectorObject
      (
      const EcManipulationActionDirectorObject& orig
      );

   /// assignment operator
   EcManipulationActionDirectorObject& operator=
      (
      const EcManipulationActionDirectorObject& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationActionDirectorObject& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the manipulation action container
   virtual const EcManipulationActionContainer& manipulationActionContainer
      (
      ) const;

   /// set the manipulation action container
   virtual void setManipulationActionContainer
      (
      const EcManipulationActionContainer& actionContainer
      );

   /// set the manipulation action
   virtual void setManipulationAction
      (
      const EcManipulationAction& action
      );

   /// get the token
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

   //---
   // Implementation of EcDirectorObject interface
   //---

   virtual const EcManipulationAction* action
      (
      ) const;

   virtual const EcManipulationSceneDirection* direction
      (
      ) const;

   virtual const EcManipulationScene* scene
      (
      ) const;

protected:
   /// the action stored in this director object
   EcManipulationActionContainer m_ActionContainer;
};

#endif // ecManipulationActionDirectorObject_H_
