#ifndef ecJointFrame_H_
#define ecJointFrame_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointFrame.h
/// @class EcJointFrame
/// @brief A single frame of a joint sequence
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationStatus.h"
#include "ecManipulationUpdateParams.h"

#include <control/ecManipEndEffectorPlace.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlVectorType.h>

// Forward declarations
class EcJointFrameSequence;

/// A single frame of a frame sequence.
class EC_ACTIN_MANIPULATION_DECL EcJointFrame : public EcXmlCompoundType
{
public:
   /// default constructor
   EcJointFrame
      (
      );

   /// destructor
   virtual ~EcJointFrame
      (
      );

   /// copy constructor
   EcJointFrame
      (
      const EcJointFrame& orig
      );

   /// assignment operator
   EcJointFrame& operator=
      (
      const EcJointFrame& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointFrame& orig
      ) const;

   /// Clone -- virtual constructor of EcBezierInterpolator
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// creates new object - a virtual new to an EcXmlObject pointer
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the xml token used for writing out.
   virtual const EcToken& token
      (
      ) const;

   /// Get label used for referencing this frame
   virtual const EcXmlString& label
      (
      ) const;

   /// Set label used for referencing this frame
   virtual void setLabel
      (
      const EcXmlString& value
      );

   /// gets the goal of this frame
   virtual const EcEndEffectorPlacement& goal
      (
      ) const;

   /// sets the goal of this frame
   virtual void setGoal
      (
      const EcEndEffectorPlacement& value
      );


   /// get the tolerance. This is used to determine whether the goal is reached.
   virtual EcReal tolerance
      (
      ) const;

   /// set the tolerance
   virtual void setTolerance
      (
      EcReal value
      );

   /// initialize the manipulation frame
   virtual EcBoolean init
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcJointFrameSequence& sequence
      ) const;

   /// update the manipulation frame
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      const EcJointFrameSequence& sequence
      ) const;

   /// get the desired end effector placement
   virtual const EcManipulatorEndEffectorPlacement& desiredEndEffectorPlacement
      (
      ) const;

   /// get the progress of this frame
   virtual EcReal progress
      (
      ) const;

protected:

   /// returns the current difference to the goal
   virtual EcReal calculateGoalDifference
      (
      const EcManipulationUpdateParams& params
      ) const;

   // XML data
   EcXmlString    m_Label;             ///< Identifier
   EcEndEffectorPlacement   m_Goal;    ///< The joint position goal
   EcXmlReal      m_Tolerance;         ///< The tolerance

   // non-XML data
   mutable EcU32     m_EndEffectorIndex;        ///< EE index of joint control EE
   mutable EcManipulatorEndEffectorPlacement    m_DesiredPlacement;  ///< desired placement

   mutable EcReal    m_Progress;                      ///< progress
   mutable EcReal    m_InitialGoalDifference;         ///< initial goal difference
   mutable EcBoolean m_InitialGoalDifferenceIsSet;    ///< if the initial goal difference is set
};

/// type definition of EcJointFrameVector
typedef EcXmlVectorType<EcJointFrame>  EcJointFrameVector;

#endif // ecJointFrame_H_
