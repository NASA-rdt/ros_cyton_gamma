#ifndef ecManipEndEffectorPlace_H_
#define ecManipEndEffectorPlace_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipEndEffectorPlace.h
/// @class EcManipulatorEndEffectorPlacement
/// @brief Holds a description of the placement of all end effectors
///        on a manipulator.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <foundCommon/ecEndEffectorPlacement.h>

// forward declarations
class EcEndEffectorSet;
class EcIndividualManipulator;
class EcManipulatorActivePositionState;
class EcManipulatorActiveState;

/// type definition of XML vector of EcIndividualManipulator
typedef EcXmlVectorType<EcIndividualManipulator> EcIndividualManipulatorVector;

/// type definition of XML vector of EcManipulatorActiveState
typedef EcXmlVectorType<EcManipulatorActiveState> EcManipulatorActiveStateVector;

/// Holds a description of the placement of all end effectors on a manipulator.
class EC_ACTIN_CONTROL_DECL EcManipulatorEndEffectorPlacement : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorEndEffectorPlacement
      (
      );

   /// destructor
   virtual ~EcManipulatorEndEffectorPlacement
      (
      );

   /// copy constructor
   EcManipulatorEndEffectorPlacement
      (
      const EcManipulatorEndEffectorPlacement& orig
      );

   /// assignment operator
   EcManipulatorEndEffectorPlacement& operator=
      (
      const EcManipulatorEndEffectorPlacement& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorEndEffectorPlacement& orig
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

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the size
   virtual EcU32 size
      (
      ) const;

   /// get transformation of offset to the primary frame of the relative link
   virtual const EcEndEffectorPlacementVector& offsetTransformations
      (
      )const;

   /// set transformation of offset to the primary frame of the relative link.
   /// this is the guide frame in the system coords when no relative link is used.
   virtual void setOffsetTransformations
      (
      const EcEndEffectorPlacementVector& offsetTransformations
      );

   /// add transformation of offset
   virtual void addOffsetTransformation
      (
      const EcEndEffectorPlacement& offsetTransformations
      );

   /// set the size of offset trans vector
   virtual void setOffsetTransformationSize
      (
      const EcU32 size
      );

   /// the number of end effectors
   virtual EcU32 numEndEffectors
      (
      ) const;

   /// set individual offset. The offset must be in the system coordinates. If the end-effector is non-relative, then this is the same as setOffsetInRelative.
   virtual EcBoolean setOffsetInSystem
      (
      EcU32 index,
      const EcEndEffectorPlacement& offset,
      const EcEndEffectorSet& endEffectorSet,
      const EcIndividualManipulator& manip,
      EcManipulatorActivePositionState& activePositionState
      );

   /// set individual offset. The offset must be in the system coordinates. If the end-effector is non-relative, then this is the same as setOffsetInRelative.
   virtual EcBoolean setOffsetInSystem
      (
      EcU32 endEffectorIndex,
      const EcEndEffectorPlacement& offset,
      const EcEndEffectorSet& endEffectorSet,
      EcU32 manipulatorIndex,
      const EcIndividualManipulatorVector& manipulators,
      EcManipulatorActiveStateVector& activeStates
      );

   /// set individual offset. The offset must be in the primary frame of the relative link. If the end-effector is non-relative, then this is the same as setOffsetInSystem.
   virtual EcBoolean setOffsetInRelative
      (
      EcU32 index,
      const EcEndEffectorPlacement& offset
      );

   /// get the location of a guide frame in system coordinates
   virtual EcEndEffectorPlacement guideFrameInSystem
      (
      EcU32 index,
      const EcEndEffectorSet& endEffectorSet,
      const EcIndividualManipulator& manip,
      EcManipulatorActivePositionState& activePositionState
      ) const;

   /// get the location of a guide frame in system coordinates
   virtual EcEndEffectorPlacement guideFrameInSystem
      (
      EcU32 endEffectorIndex,
      const EcEndEffectorSet& endEffectorSet,
      EcU32 manipulatorIndex,
      const EcIndividualManipulatorVector& manipulators,
      EcManipulatorActiveStateVector& activeStates
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

   /// get a null link
   static EcManipulatorEndEffectorPlacement nullObject
      (
      );

   /// linear interpolate two guide frames
   virtual EcBoolean linearInterpolation
      (
      const EcManipulatorEndEffectorPlacement& m_ManFrame1,
      const EcManipulatorEndEffectorPlacement& m_ManFrame2,
      const EcReal& factor
      );

   /// resize m_OffsetTransformations
   virtual void resize
      (
      const EcU32 newSize
      );

protected:
   /// an transformation of offset to the primary frame of the relative link.
   /// This offset is given in system coord, when not using relative link.
   EcEndEffectorPlacementVector  m_OffsetTransformations;
};

/// a vector of end-effector sets
typedef EcXmlVectorType<EcManipulatorEndEffectorPlacement>
   EcManipulatorEndEffectorPlacementVector;

/// a 2D vector of end-effector sets
typedef EcXmlVectorType<EcManipulatorEndEffectorPlacementVector>
   EcManipulatorEndEffectorPlacementVectorVector;

#endif // ecManipEndEffectorPlace_H_
