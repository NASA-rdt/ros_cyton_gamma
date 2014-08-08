#ifndef ecManipulationDirectorState_H_
#define ecManipulationDirectorState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectorState.h
/// @class EcManipulationDirectorState
/// @brief Holds EcManipulationDirector state information
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationScriptState.h"

#include <manipulator/ecManipulatorAttachmentMap.h>
#include <manipulator/ecSystemCollisionExclusionMap.h>
#include <xml/ecXmlCompType.h>

// Forward declaration
class EcManipulationDirector;

/// Holds EcManipulationDirector state information
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationDirectorState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationDirectorState
      (
      );

   /// destructor
   virtual ~EcManipulationDirectorState
      (
      );

   /// copy constructor
   EcManipulationDirectorState
      (
      const EcManipulationDirectorState& orig
      );

   /// assignment operator
   EcManipulationDirectorState& operator=
      (
      const EcManipulationDirectorState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationDirectorState& orig
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

   /// get the script state
   virtual const EcManipulationScriptState& scriptState
      (
      ) const;

   /// get the flag indicating if the manipulator attachment map has changed
   EcBoolean manipulatorAttachmentChanged
      (
      ) const;

   /// set the flag indicating if the manipulator attachment map has changed
   void setManipulatorAttachmentChanged
      (
      EcBoolean changed
      );

   /// get the manipulator attachment map
   virtual const EcManipulatorAttachmentMap& manipulatorAttachmentMap
      (
      ) const;

   /// set the manipulator attachment map
   virtual void setManipulatorAttachmentMap
      (
      const EcManipulatorAttachmentMap& map
      );

   /// get the flag indicating if the system collision exclusion map has changed
   EcBoolean systemCollisionExclusionChanged
      (
      ) const;

   /// set the flag indicating if the system collision exclusion map has changed
   void setSystemCollisionExclusionChanged
      (
      EcBoolean changed
      );

   /// get the system collision exclusion map
   virtual const EcSystemCollisionExclusionMap& systemCollisionExclusionMap
      (
      ) const;

   /// Set the system collision exclusion map
   virtual void setSystemCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& map
      );

   /// get the map of roles to object roles
   virtual const EcXmlStringStringMap& roleObjectRoleMap
      (
      ) const;

   /// set the object role for a specified role
   virtual void setObjectRole
      (
      const EcString& role,
      const EcString& objectRole
      );

   /// get the object role for a specified role
   virtual const EcString* objectRole
      (
      const EcString& role
      ) const;


   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   friend class EcManipulationDirector;

   /// Manipulation script state
   EcManipulationScriptState  m_ScriptState;

   /// Map of object roles keyed by role
   EcXmlStringStringMap       m_RoleObjectRoleMap;

   // Non-XML calculated values

   EcU32Vector                   m_ActiveManipulators;

   EcBoolean                     m_SystemCollisionExclusionChanged;

   EcSystemCollisionExclusionMap m_SystemCollisionExclusionMap;

   EcBoolean                     m_ManipulatorAttachmentChanged;

   EcManipulatorAttachmentMap    m_ManipulatorAttachmentMap;
};

#endif // ecManipulationDirectorState_H_
