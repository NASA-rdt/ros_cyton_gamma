#ifndef ecJointFrameSequence_H_
#define ecJointFrameSequence_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointFrameSequence.h
/// @class EcJointFrameSequence
/// @brief This represents a sequence of joint frames.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecJointFrame.h"
#include "ecManipulationAction.h"

#include <control/ecEndEffectorSet.h>
#include <foundCommon/ecDataMap.h>

// Forward declarations

/// A joint sequence.
class EC_ACTIN_MANIPULATION_DECL EcJointFrameSequence : public EcManipulationAction
{
public:
   /// default constructor
   EcJointFrameSequence
      (
      );

   /// destructor
   virtual ~EcJointFrameSequence
      (
      );

   /// copy constructor
   EcJointFrameSequence
      (
      const EcJointFrameSequence& orig
      );

   /// assignment operator
   EcJointFrameSequence& operator=
      (
      const EcJointFrameSequence& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointFrameSequence& orig
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

   /// add a joint frame to the back of the vector
   virtual void add
      (
      const EcJointFrame& jointFrame
      );

   /// insert a joint frame at the index. If index is greater than or equal to the vector size,
   /// then this is equivalent to add
   virtual void insert
      (
      EcU32 index,
      const EcJointFrame& jointFrame
      );

   /// remove the specified joint frame
   virtual EcBoolean deleteJointFrame
      (
      EcU32 index
      );

   /// swap the two joint frames at index1 and index2
   virtual EcBoolean swap
      (
      EcU32 index1,
      EcU32 index2
      );

   /// get the joint frames
   virtual const EcJointFrameVector& jointFrames
      (
      ) const;

   /// get the joint frames -- nonconst
   virtual EcJointFrameVector& jointFrames
      (
      );

   /// set the joint frames
   virtual void setJointFrames
      (
      const EcJointFrameVector& value
      );

   /// get the control description index
   virtual EcU32 controlDescriptionIndex
      (
      ) const;

   /// set the control description index
   virtual void setControlDescriptionIndex
      (
      EcU32 value
      );

   /// get the control method index
   virtual EcU32 controlMethodIndex
      (
      ) const;

   /// set the control method index
   virtual void setControlMethodIndex
      (
      EcU32 value
      );

   /// get current joint frame
   virtual const EcJointFrame* currentJointFrame
      (
      const EcManipulationActionState& astate
      ) const;

   /// get current joint frame
   virtual EcJointFrame* currentJointFrame
      (
      const EcManipulationActionState& astate
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
   // Implementation of EcManipulationAction interface
   //---

   /// initialize the manipulation sequence
   virtual EcBoolean init
      (
      EcManipulationActionStateContainer& astateContainer
      ) const;

   /// update the manipulation sequence
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationActionState& astate
      ) const;

   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationActionState&  astate
      ) const;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the overall progress of this action
   virtual EcReal progress
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationActionState& astate,
      const EcString& separator
      ) const;

   /// @copydoc EcManipulationAction::profiledPositionEndEffectorIndices()
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationActionState& astate
      ) const;

   /// @copydoc
   virtual EcU32 currentItemAtPlay
      (
      const EcManipulationActionState& astate
      ) const;
   

protected:
   // XML data
   EcJointFrameVector      m_vJointFrames;               ///< joint frames in the sequence
   EcXmlU32                m_ControlDescriptionIndex;    ///< control description index used in the sequence
   EcXmlU32                m_ControlMethodIndex;         ///< control method index used in the sequence

   // static utility data
   static const EcDataMap                 m_theNullDataMap;    ///< the null data map
   static const EcU32Vector               m_theNullU32Vector;  ///< the null U32 vector
};

#include <xml/ecXmlVectorType.h>
/// type definition of EcJointFrameSequenceVector
typedef EcXmlVectorType<EcJointFrameSequence> EcJointFrameSequenceVector;

#endif // ecJointFrameSequence_H_
