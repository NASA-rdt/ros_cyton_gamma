#ifndef ecManipulationSceneDirectorObject_H_
#define ecManipulationSceneDirectorObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirectorObject.h
/// @class EcManipulationSceneDirectorObject
/// @brief Concrete implementation of EcDirectorObject that holds an EcManipulationScene object.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectorObject.h"
#include "ecManipulationScene.h"

/// Concrete implementation of EcDirectorObject that holds an EcManipulationScene object.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirectorObject : public EcDirectorObject
{
public:
   /// default constructor
   EcManipulationSceneDirectorObject
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirectorObject
      (
      );

   /// copy constructor
   EcManipulationSceneDirectorObject
      (
      const EcManipulationSceneDirectorObject& orig
      );

   /// assignment operator
   EcManipulationSceneDirectorObject& operator=
      (
      const EcManipulationSceneDirectorObject& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirectorObject& orig
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

   /// get the manipulation scene
   virtual const EcManipulationScene& manipulationScene
      (
      ) const;

   /// set the manipulation scene
   virtual void setManipulationScene
      (
      const EcManipulationScene& scene
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
   /// the scene stored in this director object
   EcManipulationScene m_Scene;
};

#endif // ecManipulationSceneDirectorObject_H_
