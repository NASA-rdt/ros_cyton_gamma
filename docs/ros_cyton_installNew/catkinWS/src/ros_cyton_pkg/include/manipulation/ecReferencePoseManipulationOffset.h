#ifndef ecReferencePoseManipulationOffset_H_
#define ecReferencePoseManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecReferencePoseManipulationOffset.h
/// @class EcReferencePoseManipulationOffset
/// @brief This class provides a manipulation offset that is a reference
///        from a pose set
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffset.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a manipulation offset that remains constant.
class EC_ACTIN_MANIPULATION_DECL EcReferencePoseManipulationOffset : public EcManipulationOffset
{
public:
   /// default constructor
   EcReferencePoseManipulationOffset
      (
      );

   /// destructor
   virtual ~EcReferencePoseManipulationOffset
      (
      );

   /// copy constructor
   EcReferencePoseManipulationOffset
      (
      const EcReferencePoseManipulationOffset& orig
      );

   /// assignment operator
   EcReferencePoseManipulationOffset& operator=
      (
      const EcReferencePoseManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcReferencePoseManipulationOffset& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get the pose name
   virtual const EcString& poseName
      (
      ) const;

   /// set the pose name
   virtual void setPoseName
      (
      const EcString& value
      );

   /// get the role name to be used to set the manipulator when using relative pose
   virtual const EcString& roleName
      (
      ) const;

   /// set the role name
   virtual void setRoleName
      (
      const EcString& value
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// calculate the end state
   virtual EcManipulationOffsetStateContainer calculateEndState
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex
      ) const;

   /// initialize the transition event
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetStateContainer& ostateContainer
      ) const;

   /// update the trasition event
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetState& ostate
      ) const;

   /// calculate the offset transformation in the system frame
   virtual EcEndEffectorPlacement calculateOffsetTransformationInSystemFrame
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      const EcManipulationOffsetState& ostate
      ) const;

   /// set the offset transformation from an offset defined in the system frame
   virtual void setFromOffsetTransformationInSystemFrame
      (
      const EcEndEffectorPlacement& offset,
      const EcManipulationUpdateParams& params,
      const EcManipulationSequence& sequence,
      const EcManipulationSequenceState& sstate,
      EcU32 frameIndex,
      EcU32 endEffectorIndex,
      EcManipulationOffsetState& ostate
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
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
   EcXmlString    m_PoseName;    ///< pose name
   EcXmlString    m_RoleName;    ///< role name
};

#endif // ecReferencePoseManipulationOffset_H_
