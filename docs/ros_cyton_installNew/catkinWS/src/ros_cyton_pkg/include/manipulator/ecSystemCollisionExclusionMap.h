#ifndef ecSystemCollisionExclusionMap_H_
#define ecSystemCollisionExclusionMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemCollisionExclusionMap.h
/// @class EcSystemCollisionExclusionMap
/// @brief Holds a map describing which collision pairs should
///        be excluded.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecIndManipulator.h"
#include "ecManipulatorLinkIdentifier.h"
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlSetType.h>

// forward declarations
class EcManipulatorSystem;

/// type definition of XML map of EcXmlU32 and EcXmlU32Set
typedef EcXmlMapType< EcXmlU32, EcXmlU32Set > EcXmlU32U32SetMap;

/// type definition of XML map of EcManipulatorLinkIdentifier and EcXmlU32Set
typedef EcXmlMapType<EcManipulatorLinkIdentifier,EcXmlU32Set>    EcXmlManipLinkidU32SetMap;

/// type definition of XML map of EcManipulatorLinkIdentifier and XML set of EcManipulatorLinkIdentifier
typedef EcXmlMapType<EcManipulatorLinkIdentifier,EcXmlSetType< EcManipulatorLinkIdentifier > >    EcXmlManipLinkidManipLinkIdSetMap;

/**
\class EcSystemCollisionExclusionMap
\author Chalongrath Pholsiri
\brief Holds a map describing which collision pairs between links of different manipulators should be excluded.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcSystemCollisionExclusionMap : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSystemCollisionExclusionMap
      (
      );

   /// destructor
   virtual ~EcSystemCollisionExclusionMap
      (
      );

   /// copy constructor
   EcSystemCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& orig
      );

   /// assignment operator
   EcSystemCollisionExclusionMap& operator=
      (
      const EcSystemCollisionExclusionMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemCollisionExclusionMap& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
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

   /// exclude collision between two links of two different manipulators
   /**
    * @param manip1Index The index of manipulator of link 1
    * @param link1Id The identifier of link 1
    * @param manip2Index The index of manipulator of link 2
    * @param link2Id The identifier of link 2
    * @return False if manip1Index and manip2Index are identical or true otherwise.
    */
   virtual EcBoolean excludeLinkCollisionCandidate
      (
      EcU32 manip1Index,
      const EcString& link1Id,
      EcU32 manip2Index,
      const EcString& link2Id
      );

   /// exclude collisions between a link of one manipulator to all links of another manipulator
   /**
    * @param manip1Index The index of manipulator of link 1
    * @param link1Id The identifier of link 1
    * @param manip2Index The index of manipulator 2
    * @return False if manip1Index and manip2Index are identical or true otherwise.
    */
   virtual EcBoolean excludeLinkCollisionCandidates
      (
      EcU32 manip1Index,
      const EcString& link1Id,
      EcU32 manip2Index
      );

   /// exclude collisions among all links of two manipulators
   /**
    * @param manip1Index The index of manipulator 2
    * @param manip2Index The index of manipulator 2
    * @return False if manip1Index and manip2Index are identical or true otherwise.
    */
   virtual EcBoolean excludeManipulatorCollisionCandidates
      (
      EcU32 manip1Index,
      EcU32 manip2Index
      );

   /// remove collision exclusion between two links of two different manipulators
   /**
    * @param manip1Index The index of manipulator of link 1
    * @param link1Id The identifier of link 1
    * @param manip2Index The index of manipulator of link 2
    * @param link2Id The identifier of link 2
    * @return False if manip1Index and manip2Index are identical or if the exclusion doesn't exist. Otherwise, true.
    */
   virtual EcBoolean removeLinkCollisionExclusionCandidate
      (
      EcU32 manip1Index,
      const EcString& link1Id,
      EcU32 manip2Index,
      const EcString& link2Id
      );

   /// remove collision exclusions between a link of one manipulator to all links of another manipulator
   /**
    * @param manip1Index The index of manipulator of link 1
    * @param link1Id The identifier of link 1
    * @param manip2Index The index of manipulator 2
    * @return False if manip1Index and manip2Index are identical or if the exclusion doesn't exist. Otherwise, true.
    */
   virtual EcBoolean removeLinkCollisionExclusionCandidates
      (
      EcU32 manip1Index,
      const EcString& link1Id,
      EcU32 manip2Index
      );

   /// remove collision exclusions among all links of two manipulators
   /**
    * @param manip1Index The index of manipulator 2
    * @param manip2Index The index of manipulator 2
    * @return False if manip1Index and manip2Index are identical or if the exclusion doesn't exist. Otherwise, true.
    */
   virtual EcBoolean removeManipulatorCollisionExclusionCandidates
      (
      EcU32 manip1Index,
      EcU32 manip2Index
      );

   /// build the internal data structure from the system. Must be called after calling excludeXXX() methods and before isLinkCollisionCandidateExcluded()
   virtual EcBoolean buildMapFromSystem
      (
      const EcManipulatorSystem& system
      );

   /// query whether or not the collision between two links is excluded by link identifiers.
   /**
    * @param manip1Index The index of manipulator of link 1
    * @param link1Id The identifier of link 1
    * @param manip2Index The index of manipulator of link 2
    * @param link2Id The identifier of link 2
    * @return True if the collision between the two links is excluded.
    */
   virtual EcBoolean isLinkCollisionCandidateExcluded
      (
      EcU32 manip1Index,
      const EcString& link1Id,
      EcU32 manip2Index,
      const EcString& link2Id
      ) const;

   /// query whether or not the collision between two links is excluded by indices. Only valid after buildMapFromSystem has been called.
   /**
    * @param manip1Index The index of manipulator of link 1
    * @param link1Index The index of link 1
    * @param manip2Index The index of manipulator of link 2
    * @param link2Index The index of link 2
    * @return True if the collision between the two links is excluded.
    */
   virtual EcBoolean isLinkCollisionCandidateExcluded
      (
      EcU32 manip1Index,
      EcU32 link1Index,
      EcU32 manip2Index,
      EcU32 link2Index
      ) const;

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
   static EcSystemCollisionExclusionMap nullObject
      (
      );

   /// query whether or not the collision between two manipulators is excluded.
   virtual EcBoolean isManipulatorCollisionExcluded
      (
      EcU32 manip1Index,
      EcU32 manip2Index
      ) const;

   /// query whether or not the collision between two manipulators is excluded.
   virtual EcBoolean isLinktoManipulatorCollisionExcluded
      (
      EcU32 manip1Index,
      const EcString& link1Id,
      EcU32 manip2Index
      );

   /// returns true if the given link has any other collision exclusion mapping set
   virtual EcBoolean linkHasExclusionCandidate
      (
      EcU32 manip1Index,
      const EcString& link1Id
      );

   /// returns true if the given manipulator has any other collision exclusion mapping set
   virtual EcBoolean manipulatorHasExclusionCandidate
      (
      EcU32 manip1Index
      );

   /// removes all the exclusion candidates set
   virtual void removeAllExclusionCandidates
      (
      );

   /// shift all the manipulator indices in the map by a given value. Used when merging two systems
   virtual void shiftManipulatorIndices
      (
      EcU32 shiftValue
      );

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcSystemCollisionExclusionMap& other
      );

protected:
   /// convert an EcManipulatorLinkIdentifier object to an EcManipulatorLinkIndex object.
   /**
   \return True if successful or false if the manipulator index or link string identifier is invalid.
   */
   EcBoolean convertToManipulatorLinkIndex
      (
      const EcIndividualManipulatorVector& manips,
      const EcManipulatorLinkIdentifier& manipLinkId,
      EcManipulatorLinkIndex& manipLinkIndex
      ) const;

   /// given a manipulator index, obtain a vector of EcManipulatorLinkIndex objects representing all the links in that manipulator
   /**
   \return True if successful or false if the manipulator index is invalid
   */
   EcBoolean obtainManipulatorLinkIndices
      (
      const EcIndividualManipulatorVector& manips,
      EcU32 manipIndex,
      std::vector<EcManipulatorLinkIndex>& manipLinkIndices
      ) const;


protected:
   /// map for excluding collision between all links of manipulators
   EcXmlU32U32SetMap          m_XmlManipExclusionMap;

   /// map for excluding collision between a link of one manipulator and all links of another
   EcXmlManipLinkidU32SetMap  m_XmlLinkManipExclusionMap;

   /// map for excluding collision between two links of two different manipulators
   EcXmlManipLinkidManipLinkIdSetMap  m_XmlLinkLinkExclusionMap;

   /// non-xml
   /// map for excluding collision between a link (using index) of one manipulator and alllinks of another
   std::map< EcManipulatorLinkIndex, std::set< EcU32 > >          m_LinkManipExclusionMap;
   /// map for excluding collision between two links (using indices) of two different manipulators
   std::map< EcManipulatorLinkIndex, std::set< EcManipulatorLinkIndex > >   m_LinkLinkExclusionMap;
};

#endif // ecSystemCollisionExclusionMap_H_
