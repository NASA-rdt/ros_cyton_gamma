#ifndef ecAssignObjectRoleDirection_H_
#define ecAssignObjectRoleDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecAssignObjectRoleDirection.h
/// @class EcAssignObjectRoleDirection
/// @brief Concrete implementation of EcStageDirection for selecting the role to use as the object in object-relative actions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecStageDirection.h"

#include <xml/ecXmlBasicType.h>

/// Concrete implementation of EcStageDirection for selecting the role to use as the object in object-relative actions.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcAssignObjectRoleDirection : public EcStageDirection
{
public:
   /// default constructor
   EcAssignObjectRoleDirection
      (
      );

   /// destructor
   virtual ~EcAssignObjectRoleDirection
      (
      );

   /// copy constructor
   EcAssignObjectRoleDirection
      (
      const EcAssignObjectRoleDirection& orig
      );

   /// assignment operator
   EcAssignObjectRoleDirection& operator=
      (
      const EcAssignObjectRoleDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAssignObjectRoleDirection& orig
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

   /// get the object role
   const EcString& objectRole
      (
      ) const;

   /// set the object role
   void setObjectRole
      (
      const EcString& objectRole
      );

   /// get the descriptor for this direction
   virtual const EcString descriptor
      (
      ) const;

   /// get a vector of role names that are referenced within this assign object role direction
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// initialize the assign object role direction
   virtual EcBoolean init
      (
      const EcManipulationDirector&               director,
      const EcString&                             role,
      EcManipulationSceneDirectionStateContainer& dstateContainer
      ) const;

   /// apply the assign object role direction
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
   EcXmlString m_ObjectRole;
};

#endif // ecAssignObjectRoleDirection_H_
