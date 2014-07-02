#ifndef ecManipulatorAttachmentNode_H_
#define ecManipulatorAttachmentNode_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorAttachmentNode.h
/// @class EcManipulatorAttachmentNode
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecIndManipulator.h"
#include "ecManipActiveState.h"

#include <xml/ecXmlVectorType.h>

// forward declarations

/// The class defining a manipulator attachment node.
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorAttachmentNode : public EcXmlCompoundType
{
public:
   enum
   {
      INVALID_INDEX = -1      ///< Invalid manipulator index
   };

   /// default constructor
   EcManipulatorAttachmentNode
      (
      );

   /// destructor
   virtual ~EcManipulatorAttachmentNode
      (
      );

   /// copy constructor
   EcManipulatorAttachmentNode
      (
      const EcManipulatorAttachmentNode& orig
      );

   /// assignment operator
   EcManipulatorAttachmentNode& operator=
      (
      const EcManipulatorAttachmentNode& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorAttachmentNode& orig
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

   /// get the link label
   virtual const EcString& baseLinkLabel
      (
      ) const;

   /// set the link label
   virtual void setBaseLinkLabel
      (
      const EcString& value
      );

   /// get the manipulator index
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// set the manipulator index
   virtual void setManipulatorIndex
      (
      EcU32 value
      );

   /// get the offset
   virtual const EcCoordinateSystemTransformation& offset
      (
      ) const;

   /// set the offset
   virtual void setOffset
      (
      const EcCoordinateSystemTransformation& value
      );

   /// get the child nodes
   virtual const EcXmlVectorType<EcManipulatorAttachmentNode>& childNodes
      (
      ) const;

   /// set the child nodes
   virtual void setChildNodes
      (
      const EcXmlVectorType<EcManipulatorAttachmentNode>& value
      );

   /// get the parent node or null if no parent
   virtual const EcManipulatorAttachmentNode* parentNode
      (
      ) const;

   /// set the parent node
   virtual void setParentNode
      (
      const EcManipulatorAttachmentNode* value
      );

   /// check whether a node can be added
   virtual EcBoolean checkAddNode
      (
      const EcManipulatorAttachmentNode& node
      ) const;

   /// add a node
   virtual EcBoolean addNode
      (
      const EcManipulatorAttachmentNode& node,
      EcBoolean check=EcTrue
      );

   /// remove a node
   virtual EcBoolean removeNode
      (
      EcU32 manipIndex
      );

   /// remove a node and return the removed node if it has children
   virtual EcBoolean removeNode
      (
      EcU32 manipIndex,
      EcManipulatorAttachmentNode& node
      );

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

   /// recursively add the indices of manipulators attached to (dependent on) this node
   virtual void getDependentManipulators
      (
      EcU32Vector& dependentManipIndices
      ) const;

   /// recursively calculate the base locations of manipulators attached to this node
   /**
    * @param manips manips The vector of all manipulators in the system.
    * @param manipActiveStates The manipulator active states of all manipulators.
    * @param[out] dependentManipIndices A vector of indices of all manipulators attached to the base manipulator.
    *          The returned vector is empty if there's no manipulator attached to the base manipulator.
    * @param[out] baseLocations A vector of the base locations of all manipulators attached to the base manipulator.
    * @return True if sucessful or false otherwise. Success if the base manipulator has at least one dependent manipulator,
    *          all indices of both base manipulator and dependent manipulators are valid (not exceed the size of manips),
    *          and all the base links are valid.
    */
   virtual EcBoolean calculateBaseLocations
      (
      const EcIndividualManipulatorVector& manips,
      EcManipulatorActiveStateVector& manipActiveStates,
      EcU32Vector& dependentManipIndices,
      EcCoordinateSystemTransformationVector& baseLocations
      ) const;

   /// recursively calculate the base locations and velocities of manipulators attached to this node
   /**
    * @param manips manips The vector of all manipulators in the system.
    * @param manipActiveStates The manipulator active states of all manipulators.
    * @param[out] dependentManipIndices A vector of indices of all manipulators attached to the base manipulator.
    *          The returned vector is empty if there's no manipulator attached to the base manipulator.
    * @param[out] baseLocations A vector of the base locations of all manipulators attached to the base manipulator.
    * @param[out] baseVelocities A vector of the base velocities of all manipulators attached to the base manipulator.
    * @return True if sucessful or false otherwise. Success if the base manipulator has at least one dependent manipulator,
    *          all indices of both base manipulator and dependent manipulators are valid (not exceed the size of manips),
    *          and all the base links are valid.
    */
   virtual EcBoolean calculateBaseLocationsAndVelocities
      (
      const EcIndividualManipulatorVector& manips,
      EcManipulatorActiveStateVector& manipActiveStates,
      EcU32Vector& dependentManipIndices,
      EcCoordinateSystemTransformationVector& baseLocations,
      EcGeneralVelocityVector& baseVelocities
      ) const;

   /// shift the manipulator indices in all nodes by a given value. Used when merging two systems
   virtual void shiftManipulatorIndices
      (
      EcU32 shiftValue
      );

protected:
   EcXmlString    m_BaseLinkLabel;        ///< The label of the base link (the link to which this node is attached)
   EcXmlU32       m_ManipIndex;           ///< The index of the attached manipulator

   /// The attachment offset from the primary frame of the base link to the primary frame of
   /// the manipulator link
   EcCoordinateSystemTransformation    m_Offset;

   /// The child nodes that are attached to this manipulator
   EcXmlVectorType<EcManipulatorAttachmentNode>    m_vChildNodes;

   // non-XML
   const EcManipulatorAttachmentNode* m_pParentNode;  ///< Pointer to the parent node
};

/// type definition of XML vector of attachment nodes
typedef EcXmlVectorType<EcManipulatorAttachmentNode> EcManipulatorAttachmentNodeVector;

#endif // ecManipulatorAttachmentNode_H_
