#ifndef ecCollisionExclusionDirection_H_
#define ecCollisionExclusionDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCollisionExclusionDirection.h
/// @class EcCollisionExclusionDirection
/// @brief Concrete implementation of EcStageDirection for modifying the collision exclusion map.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecStageDirection.h"

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlVectorType.h>

/// Concrete implementation of EcStageDirection for modifying the collision exclusion map.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcCollisionExclusionDirection : public EcStageDirection
{
public:
   typedef EcXmlMapType<EcXmlString, EcXmlStringVector>     ExclusionRoleLinksMap;
   typedef EcXmlMapType<EcXmlString, ExclusionRoleLinksMap> LinkExclusionRoleLinksMap;

   enum Commands
   {
      ExcludeCommand,
      IncludeCommand
   };

   /// default constructor
   EcCollisionExclusionDirection
      (
      );

   /// destructor
   virtual ~EcCollisionExclusionDirection
      (
      );

   /// copy constructor
   EcCollisionExclusionDirection
      (
      const EcCollisionExclusionDirection& orig
      );

   /// assignment operator
   EcCollisionExclusionDirection& operator=
      (
      const EcCollisionExclusionDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCollisionExclusionDirection& orig
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

   /// get the command
   EcU32 command
      (
      ) const;

   /// set the command
   void setCommand
      (
      EcU32 command
      );

   /// get the exclusion map
   const LinkExclusionRoleLinksMap& exclusionMap
      (
      ) const;

   /// set the exclusion map
   void setExclusionMap
      (
      const LinkExclusionRoleLinksMap& map
      );

   /// get the descriptor for this direction
   virtual const EcString descriptor
      (
      ) const;

   /// get a vector of role names that are referenced within this direction
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// initialize the direction
   virtual EcBoolean init
      (
      const EcManipulationDirector&               director,
      const EcString&                             role,
      EcManipulationSceneDirectionStateContainer& dstateContainer
      ) const;

   /// apply the direction
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
   /// command indicating the operation to perform on the collision exclusion
   EcXmlEnumU32              m_Command;

   /// map containing the exclusion role and links keyed by the link
   LinkExclusionRoleLinksMap m_ExclusionMap;
};

#endif // ecCollisionExclusionDirection_H_
