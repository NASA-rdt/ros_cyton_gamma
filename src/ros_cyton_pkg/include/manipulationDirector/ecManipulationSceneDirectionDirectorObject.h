#ifndef ecManipulationSceneDirectionDirectorObject_H_
#define ecManipulationSceneDirectionDirectorObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirectionDirectorObject.h
/// @class EcManipulationSceneDirectionDirectorObject
/// @brief Concrete implementation of EcDirectorObject that holds an EcManipulationSceneDirection object.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectorObject.h"
#include "ecManipulationSceneDirectionContainer.h"

/// Concrete implementation of EcDirectorObject that holds an EcManipulationSceneDirection object.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirectionDirectorObject : public EcDirectorObject
{
public:
   /// default constructor
   EcManipulationSceneDirectionDirectorObject
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirectionDirectorObject
      (
      );

   /// copy constructor
   EcManipulationSceneDirectionDirectorObject
      (
      const EcManipulationSceneDirectionDirectorObject& orig
      );

   /// assignment operator
   EcManipulationSceneDirectionDirectorObject& operator=
      (
      const EcManipulationSceneDirectionDirectorObject& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirectionDirectorObject& orig
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

   /// get the manipulation scene direction container
   virtual const EcManipulationSceneDirectionContainer& manipulationSceneDirectionContainer
      (
      ) const;

   /// set the manipulation scene direction container
   virtual void setManipulationSceneDirectionContainer
      (
      const EcManipulationSceneDirectionContainer& directionContainer
      );

   /// set the manipulation scene direction
   virtual void setManipulationSceneDirection
      (
      const EcManipulationSceneDirection& direction
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
   /// the direction stored in this director object
   EcManipulationSceneDirectionContainer m_DirectionContainer;
};

#endif // ecManipulationSceneDirectionDirectorObject_H_
