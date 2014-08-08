#ifndef ecManipulatorAttachmentMap_H_
#define ecManipulatorAttachmentMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorAttachmentMap.h
/// @class EcManipulatorAttachmentMap
/// @brief Holds a map describing attachment among manipulators
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipulatorAttachmentNode.h"
#include "ecManipulatorAttachmentChange.h"

// forward declarations
class EcOldManipulatorAttachmentMap;

/**
\class EcManipulatorAttachmentMap
\author Chalongrath Pholsiri
This class holds a map describing attachments among manipulators. For example, one can attach a hand manipulator onto an arm manipulator.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorAttachmentMap : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorAttachmentMap
      (
      );

   /// destructor
   virtual ~EcManipulatorAttachmentMap
      (
      );

   /// copy constructor
   EcManipulatorAttachmentMap
      (
      const EcManipulatorAttachmentMap& orig
      );

   /// assignment operator
   EcManipulatorAttachmentMap& operator=
      (
      const EcManipulatorAttachmentMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorAttachmentMap& orig
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

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// get the nodes for all base manipulators
   virtual const EcManipulatorAttachmentNodeVector& baseNodes
      (
      ) const;

   /// attach the base link of one manipulator onto a link of another manipulator
   /**
   This will instruct the control and simulation that the base link of a 'dependent' manipulator (identified by depManipIndex) is to be attached to a link (identified by baseLinkId) of a 'base' manipulator (identified by baseManipIndex) with an offset. Note that one base manipulator can support multiple dependent manipulators (for example, there can be two arm manipulators attached on a torso manipulator). However, one dependent manipulator CANNOT be attached to multiple base manipulators. If the dependent manipulator is already attached to anoter manipulator, calling attachManipulator will replace the attachment with the new one.
   \param[in] depManipIndex The index of the dependent manipulator.
   \param[in] baseManipIndex The index of the base manipulator.
   \param[in] baseLinkId The identifier of the base link.
   \param[in] offset The offset of the primary frame of depLinkId link relative to the primary frame of baseLinkIde link.
   \return True if successful or false otherwise. If it returns true, the attachmentChangeVector will be updated.
The failure can take place if
   (1) depManipIndex and baseManipIndex are the same,
   (2) Adding the attachment would create a circular chain. For example, manip 1 is attached to 0 that is attached to 2 that is attached back to 1.
   */
   virtual EcBoolean attachManipulator
      (
      EcU32 depManipIndex,
      EcU32 baseManipIndex,
      const EcString& baseLinkId,
      const EcCoordinateSystemTransformation& offset
      );

   /**
   Remove the manipulator attachment of the dependent manipulator identified by depManipIndex from the map.
   This, however, preserves attachment to the dependent manipulator, if any.
   \param[in] depManipIndex The index of the dependent manipulator.
   \return True if successful or false if depManipIndex doesn't exist in the map. If true, the attachmentChangeVector will be udpated.
   */
   virtual EcBoolean removeManipulatorAttachment
      (
      EcU32 depManipIndex
      );

   /// get recording of attachment changes from calls to attachManipulator and
   /// removeManipulatorAttachment.
   virtual const EcManipulatorAttachmentChangeVector& attachmentChangeVector
      (
      ) const;

   /// reset/clear the attachment changes
   virtual void resetAttachmentChangeVector
      (
      );

   /**
   Remove ALL references to manipIndex in the map. Do not use this to simply remove an attachment since this will not update the attachmentChangeVector.
Use removeManipulatorAttachment instead. Use this method, say, when a manipulator is deleted from the system.
   \param[in] manipIndex The index of the manipulator.
   \return True if successful or false if manipIndex doesn't exist in the map.
   */
   virtual EcBoolean removeManipulator
      (
      EcU32 manipIndex
      );

   /**
   Get the information on the dependent manipulator.
   \param[in] depManipIndex The index of the dependent manipulator in query.
   \param[out] baseManipIndex The index of the base manipulator.
   \param[out] baseLinkId The identifier of the base link.
   \param[out] offset The offset of the primary frame of depLinkId link relative to the primary frame of baseLinkIde link.
   \return True if the manipulator identified by manipIndex is dependent on another manipulator. False otherwise. Note that if this method returns false, then all the output parameters will not have been set.
   */
   virtual EcBoolean getDependentManipulatorInfo
      (
      EcU32 depManipIndex,
      EcU32& baseManipIndex,
      EcString& baseLinkId,
      EcCoordinateSystemTransformation& offset
      ) const;

   /**
   Returns the indices and offsets of all manipulators directly attached to a given link. That is, it doesn't include
   any attachment from below in the chain.
   \param[in] baseManipIndex The index of the manipulator of interest.
   \param[in] baseLinkId The label of the link of interest.
   \param[out] depManipIndices The indices of all manipulators attached to a given link.
   \param[out] offsets The attachment offsets. Same size as depManipIndices.
   \return True if there's at at least one manipulator attached to the link or false otherwise.
   */
   virtual EcBoolean getDependentManipulatorsAndOffsets
      (
      EcU32 baseManipIndex,
      const EcString& baseLinkId,
      EcU32Vector& depManipIndices,
      EcCoordinateSystemTransformationVector& offsets
      ) const;

   /**
   Returns the indices of all manipulators attached to a given base manipulator. This includes
   all the manipulators attached in the chain.
   \param[in] baseManipIndex The index of the base manipulator of interest.
   \return A vector of indices of all manipulators attached to the base manipulator. The returned vector is empty if there's no manipulator attached to the base manipulator.
   */
   virtual EcU32Vector dependentManipulators
      (
      EcU32 baseManipIndex
      ) const;

   /**
   Calculate the base locations of all the manipulators that are attachend to a given base manipulator. This includes
   all the manipulators attached in the chain.
   \param[in] baseManipIndex The index of the base manipulator of interest.
   \param[in] manips The vector of all manipulators in the system.
   \param[in,out] manipActiveStates The manipulator active states of all manipulators.
   \param[out] dependentManipIndices A vector of indices of all manipulators attached to the base manipulator. The returned vector is empty if there's no manipulator attached to the base manipulator.
   \param[out] baseLocations A vector of the base locations of all manipulators attached to the base manipulator.
   \return True if sucessful or false otherwise. Success if the base manipulator has at least one dependent manipulator, all indices of both base manipulator and dependent manipulators are valid (not exceed the size of manips), and all the base links are valid. If successful, the size of dependentManipIndices and baseLocations will be identical and they can be used to set the base locations in the position states.
   */
   virtual EcBoolean calculateBaseLocations
      (
      EcU32 baseManipIndex,
      const EcIndividualManipulatorVector& manips,
      EcManipulatorActiveStateVector& manipActiveStates,
      EcU32Vector& dependentManipIndices,
      EcCoordinateSystemTransformationVector& baseLocations
      ) const;

   /**
   Calculate the base locations of all the manipulators in the map.
   \param[in] manips The vector of all manipulators in the system.
   \param[in,out] manipActiveStates The manipulator active states of all manipulators.
   \param[out] dependentManipIndices A vector of indices of all manipulators in the map.
   \param[out] baseLocations A vector of the base locations of all manipulators in the map.
   \param[out] baseVelocities A vector of the base velocities of all manipulators in the map.
   */
   virtual EcBoolean calculateBaseLocationsAndVelocities
      (
      const EcIndividualManipulatorVector& manips,
      EcManipulatorActiveStateVector& manipActiveStates,
      EcU32Vector& dependentManipIndices,
      EcCoordinateSystemTransformationVector& baseLocations,
      EcGeneralVelocityVector& baseVelocities
      ) const;

   /// get the index of the base manipulator at the top of the chain. If the manipulator identified by
   /// depManipulatorIndex is not attached to any manipulator, then it returns the same index (depManipulatorIndex).
   virtual EcU32 baseManipulatorIndex
      (
      EcU32 depManipulatorIndex
      ) const;

   /// clear this map
   virtual void clear
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
      const EcManipulatorAttachmentMap& other
      );

   /// convert from EcOldManipulatorAttachmentMap for backward compatibility
   virtual void convertFromOldFormat
      (
      const EcOldManipulatorAttachmentMap& oldMap
      );

protected:
   /// returns a node with a given manipulator index or null if it doesn't exist -- non-const version
   virtual EcManipulatorAttachmentNode* findNode
      (
      EcU32 manipIndex
      );

   /// returns a node with a given manipulator index or null if it doesn't exist -- const version
   virtual const EcManipulatorAttachmentNode* findNode
      (
      EcU32 manipIndex
      ) const;

   /// the nodes for all base manipulators
   EcManipulatorAttachmentNodeVector   m_vBaseNodes;

   // non-XML
   /// recording of attachment changes from calls to attachManipulator and
   /// removeManipulatorAttachment
   EcManipulatorAttachmentChangeVector m_AttachmentChangeVector;
};

#endif // ecManipulatorAttachmentMap_H_
