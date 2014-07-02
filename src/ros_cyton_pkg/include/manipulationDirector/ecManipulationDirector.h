#ifndef ecManipulationDirector_H_
#define ecManipulationDirector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirector.h
/// @class EcManipulationDirector
/// @brief Directs a cast to run a manipulation script
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDirectorObjectDirectory.h"
#include "ecManipulationScript.h"

#include <manipulation/ecManipulationActionDirectory.h>
#include <manipulation/ecManipulationAction.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcManipulationDirectorSimpleState;
class EcManipulationDirectorState;
class EcManipulationDirectorUpdateParams;

/// Directs a cast to run a manipulation script
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationDirector : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationDirector
      (
      );

   /// destructor
   virtual ~EcManipulationDirector
      (
      );

   /// copy constructor
   EcManipulationDirector
      (
      const EcManipulationDirector& orig
      );

   /// assignment operator
   EcManipulationDirector& operator=
      (
      const EcManipulationDirector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationDirector& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// read object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

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

   /// get the script
   virtual const EcManipulationScript& script
      (
      ) const;

   /// set the script
   virtual void setScript
      (
      const EcManipulationScript& script
      );

   /// get the cast (map of role name to manipulator id)
   virtual const EcXmlStringU32Map& cast
      (
      ) const;

   /// set the cast (map of role name to manipulator id)
   virtual void setCast
      (
      const EcXmlStringU32Map& cast
      );

   /// get the object directory
   virtual const EcDirectorObjectDirectory& objectDirectory
      (
      ) const;

   /// set the object directory
   virtual void setObjectDirectory
      (
      const EcDirectorObjectDirectory& objectDirectory
      );

   /// Determine the manipulator index for a given role
   EcBoolean indexFromRole
      (
      const EcString& role,
      EcU32& index
      ) const;

   /// Determine the role for a given manipulator index
   EcBoolean roleFromIndex
      (
      EcU32 index,
      EcString& role
      ) const;

   /// get a vector of primary role names that are referenced within this director
   virtual EcStringVector primaryRoleNames
      (
      ) const;

   /// get a vector of role names that are referenced within this director
   virtual EcStringVector roleNames
      (
      ) const;

   /// initialize the manipulation director
   virtual EcBoolean init
      (
      EcManipulationDirectorState& dstate
      ) const;

   /// update the manipulation director
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationDirectorUpdateParams& params,
      EcManipulationDirectorState& dstate
      ) const;

   /// convert the manipulation director state
   virtual void convert
      (
      const EcManipulationDirectorState& dstate,
      EcManipulationDirectorSimpleState& sdstate
      ) const;

   /// get the currently-active manipulators
   virtual const EcU32Vector& activeManipulators
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the currently-active roles
   virtual const EcStringVector& activeRoles
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the active control description index to be used for each active manipulator
   virtual const EcU32Vector& activeControlDescriptions
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the active control method index to be used for each active manipulator
   virtual const EcU32Vector& activeControlMethods
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the active end-effector set index to be used for each active manipulator
   virtual const EcU32Vector& activeEndEffectorSets
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the data map from each active manipulator
   virtual const std::vector<const EcDataMap*>& dataMaps
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the end-effector placement to be used for each active manipulator
   virtual const std::vector<const EcManipulatorEndEffectorPlacement*>& endEffectorPlacements
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the profiled position EE indices to be used for each active manipulator
   virtual const EcU32VectorVector& profiledPositionEndEffectorIndices
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// get the overall progress of the manipulation director
   virtual EcReal progress
      (
      const EcManipulationDirectorState& dstate
      ) const;

   /// determine the status string from each active manipulator
   virtual EcStringVector statusStrings
      (
      const EcManipulationDirectorState& dstate,
      const EcString& separator
      ) const;

   /// Accept a visitor
   virtual void acceptDirectorVisitor
      (
      EcManipulationDirectorVisitor& visitor,
      EcManipulationDirectorState*   pState = 0
      );

   /// Traverse through sub objects with visitor
   virtual void traverseDirectorVisitor
      (
      EcManipulationDirectorVisitor& visitor,
      EcManipulationDirectorState*   pState = 0
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   EcBoolean addManipulationAction
      (
      const EcString&             aname,
      const EcManipulationAction& action
      );

   EcBoolean removeManipulationAction
      (
      const EcString& name
      );

   EcBoolean addDirectorObject
      (
      const EcString&         oname,
      const EcDirectorObject& object
      );

   EcBoolean removeDirectorObject
      (
      const EcString& name
      );

protected:
   /// Manipulation script
   EcManipulationScript          m_Script;

   /// Map of role name to manipulator id
   EcXmlStringU32Map             m_Cast;

   /// Library of objects used within the manipulation script
   EcDirectorObjectDirectory     m_ObjectDirectory;

   // non-XML data

   /// DEPRECATED used for reading old file formats
   EcManipulationActionDirectory m_DeprecatedActionDirectory;
};

#endif // ecManipulationDirector_H_
