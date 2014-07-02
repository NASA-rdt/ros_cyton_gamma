#ifndef ecManipSelfCollisionLinkMap_H_
#define ecManipSelfCollisionLinkMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipSelfCollisionLinkMap.h
/// @class EcManipulatorSelfCollisionLinkMap
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>
#include "ecLabelAssociatedMap.h"

// forward declarations
class EcIndividualManipulator;

/// Holds the class describing self-collisions among links in the same manipulator. It can be thought of as a
/// table with link names as the headers of both columns and rows that are filled with boolean. If the boolean is true,
/// it means the two links (given by names) can collide.
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorSelfCollisionLinkMap : public EcXmlStringStringBooleanMap
{
public:
   /// default constructor
   EcManipulatorSelfCollisionLinkMap
      (
      );

   /// destructor
   virtual ~EcManipulatorSelfCollisionLinkMap
      (
      );

   /// copy constructor
   EcManipulatorSelfCollisionLinkMap
      (
      const EcManipulatorSelfCollisionLinkMap& orig
      );

   /// assignment operator
   EcManipulatorSelfCollisionLinkMap& operator=
      (
      const EcManipulatorSelfCollisionLinkMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorSelfCollisionLinkMap& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// build the link collision mapping from a system
   virtual EcBoolean buildMapFromSystem
      (
      const EcIndividualManipulator& system
      );

   /// set whether the two links identified by link1 and link2 can collide
   /**
    * @param link1 The identifier of link 1
    * @param link2 The identifier of link 2
    * @param val True if the two links can collide or false otherwise
    * @return True
    */
   virtual EcBoolean setLinkCollisionCanditateByIdentifier
      (
      const EcString& link1,
      const EcString& link2,
      const EcBoolean val
      );

   /// get whether the two links identified by link1 and link2 can collide
   /**
    * @param link1 The identifier of link 1
    * @param link2 The identifier of link 2
    * @param[out] value True if the two links can collide or false otherwise
    * @return True if both link1 and link2 exist in the map or false otherwise
    */
   virtual EcBoolean linkCollisionCanditateByIdentifier
      (
      const EcString& link1,
      const EcString& link2,
      EcBoolean& value
      )const;

   /// returns true if the given link has any other collision exclusion mapping set
   EcBoolean linkHasExclusionCandidate
      (
      const EcString& link1Id
      );

   /// set all as collision candidate
   virtual void setAllAsCollisionCandidates
      (
      );

   /// unset all as collision candidate
   virtual void unsetAllAsCollisionCandidates
      (
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcManipulatorSelfCollisionLinkMap nullObject
      (
      );
};

#endif // ecManipSelfCollisionLinkMap_H_
