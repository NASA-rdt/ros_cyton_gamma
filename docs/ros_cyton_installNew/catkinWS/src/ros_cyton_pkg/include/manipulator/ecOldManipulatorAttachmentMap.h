#ifndef ecOldManipulatorAttachmentMap_H_
#define ecOldManipulatorAttachmentMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecOldManipulatorAttachmentMap.h
/// @class EcOldManipulatorAttachmentMap
/// @brief Holds a map describing attachment among manipulators (deprecated)
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecIndManipulator.h"
#include "ecManipulatorLinkIdentifier.h"
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlPairType.h>

// forward declarations

/// type definition of XML pair of EcManipulatorLinkIdentifier and EcCoordinateSystemTransformation
typedef EcXmlPairType< EcManipulatorLinkIdentifier, EcCoordinateSystemTransformation > EcXmlManipLinkIdOffsetPair;

/// type definition of XML map of EcXmlU32 and EcXmlManipLinkIdOffsetPair
typedef EcXmlMapType< EcXmlU32, EcXmlManipLinkIdOffsetPair >   EcXmlU32ManipLinkIdOffsetPairMap;

/**
\class EcOldManipulatorAttachmentMap
\author Chalongrath Pholsiri
This class holds a map describing attachments among manipulators. For example, one can attach a hand manipulator onto an arm manipulator. This class is deprecated but retained for backward compatibility. Use EcManipulatorAttachmentMap instead.
\deprecated
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcOldManipulatorAttachmentMap : public EcXmlU32ManipLinkIdOffsetPairMap
{
public:
   /// type definition of map of EcXmlU32 and EcXmlManipLinkIdOffsetPair
   typedef std::map< EcXmlU32, EcXmlManipLinkIdOffsetPair >    MapContainer;

   /// default constructor
   EcOldManipulatorAttachmentMap
      (
      );

   /// destructor
   virtual ~EcOldManipulatorAttachmentMap
      (
      );

   /// copy constructor
   EcOldManipulatorAttachmentMap
      (
      const EcOldManipulatorAttachmentMap& orig
      );

   /// assignment operator
   EcOldManipulatorAttachmentMap& operator=
      (
      const EcOldManipulatorAttachmentMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcOldManipulatorAttachmentMap& orig
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

   /// the token
   virtual const EcToken& token
      (
      ) const;

   /// attach the base link of one manipulator onto a link of another manipulator
   /**
   This will instruct the control and simulation that the base link of a 'dependent' manipulator (identified by depManipIndex) is to be attached to a link (identified by baseLinkId) of a 'base' manipulator (identified by baseManipIndex) with an offset. Note that one base manipulator can support multiple dependent manipulators (for example, there can be two arm manipulators attached on a torso manipulator). However, one dependent manipulator CANNOT be attached to multiple base manipulators. If the dependent manipulator is already attached to anoter manipulator, calling attachManipulator will replace the attachment with the new one.
   \param[in] depManipIndex The index of the dependent manipulator.
   \param[in] baseManipIndex The index of the base manipulator.
   \param[in] baseLinkId The identifier of the base link.
   \param[in] offset The offset of the primary frame of depLinkId link relative to the primary frame of baseLinkIde link.
   \return True if successful or false otherwise. The failure can take place if
   (1) depManipIndex and baseManipIndex are the same,
   (2) The base manipulator identified by baseManipIndex is attached to another manipulator, thereby creating a chain of dependent manipulators.
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
   \param[in] depManipIndex The index of the dependent manipulator.
   \return True if successful or false if depManipIndex doesn't exist in the map.
  */
   virtual EcBoolean removeManipulatorAttachment
      (
      EcU32 depManipIndex
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
   Returns the indices of all manipulators attached to a given base manipulator.
   \param[in] baseManipIndex The index of the base manipulator of interest.
   \return A vector of indices of all manipulators attached to the base manipulator. The returned vector is empty if there's no manipulator attached to the base manipulator.
   */
   virtual EcU32Vector dependentManipulators
      (
      EcU32 baseManipIndex
      ) const;

   /**
   Returns the indices and offsets of all manipulators attached to a given link.
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
   Calculate the base locations of all the manipulators that are attachend to a given base manipulator.
   \param[in] baseManipIndex The index of the base manipulator of interest.
   \param[in] manips The vector of all manipulators in the system.
   \param[in,out] baseManipActivePosState The manipulator active position state of the base manipulator.
   \param[out] dependentManipIndices A vector of indices of all manipulators attached to the base manipulator. The returned vector is empty if there's no manipulator attached to the base manipulator.
   \param[out] baseLocations A vector of the base locations of all manipulators attached to the base manipulator.
   \return True if sucessful or false otherwise. Success if the base manipulator has at least one dependent manipulator, all indices of both base manipulator and dependent manipulators are valid (not exceed the size of manips), and all the base links are valid. If successful, the size of dependentManipIndices and baseLocations will be identical and they can be used to set the base locations in the position states.
   */
   virtual EcBoolean calculateBaseLocations
      (
      EcU32 baseManipIndex,
      const EcIndividualManipulatorVector& manips,
      EcManipulatorActivePositionState& baseManipActivePosState,
      EcU32Vector& dependentManipIndices,
      EcCoordinateSystemTransformationVector& baseLocations
      ) const;
};

#endif // ecOldManipulatorAttachmentMap_H_
