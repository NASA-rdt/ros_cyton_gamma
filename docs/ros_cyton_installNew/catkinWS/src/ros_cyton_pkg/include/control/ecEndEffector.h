#ifndef ecEndEffector_H_
#define ecEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndEffector.h
/// @class EcEndEffector
/// @brief A base class for an end-effector component
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffectorRelativeLinkData.h"
#include <foundCommon/ecGeneralMotion.h>
#include <matrixUtilities/ecReArray.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcIndividualManipulator;
class EcManipulatorActivePositionState;
class EcManipulatorActiveState;
class EcEndEffectorPlacement;
class EcEndEffectorRelativeLinkData;
class EcManipulatorLink;
class EcManipulatorActiveState;

/// Holds a base class for single end-effector components.
/** This class is responsible for the label identifier of the link to which the
 end effector is attached.
*/
class EC_ACTIN_CONTROL_DECL EcEndEffector : public EcXmlCompoundType
{
public:
   /// default constructor
   EcEndEffector
      (
      );

   /// destructor
   virtual ~EcEndEffector
      (
      );

   /// copy constructor
   EcEndEffector
      (
      const EcEndEffector& orig
      );

   /// assignment operator
   EcEndEffector& operator=
      (
      const EcEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffector& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const = 0;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the link identifier. This is the link to which the end-effector is attached.
   virtual const EcString& linkIdentifier
      (
      ) const;

   /// sets the link identifier. This is the link to which the end-effector is attached.
   virtual void setLinkIdentifier
      (
      const EcString& linkIdentifier
      );

   /// gets the end-effector placement
   virtual const EcEndEffectorRelativeLinkData& relativeLinkData
      (
      ) const;

   /// sets the end-effector placement
   virtual void setRelativeLinkData
      (
      const EcEndEffectorRelativeLinkData& relativeLinkData
      );

   /// gets the is-hard-constraint flag
   virtual const EcBoolean& isHardConstraint
      (
      ) const;

   /// sets the is-hard-constraint flag
   virtual void setIsHardConstraint
      (
      const EcBoolean& isHardConstraint
      );

   /// gets the is-editable flag
   virtual const EcBoolean& isEditable
      (
      ) const;

   /// sets the is-editable flag
   virtual void setIsEditable
      (
      const EcBoolean& isEditable
      );

   /// make sure the Jacobian is the right size for this end
   /// effector starting at the startRow position.
   virtual void rightSizeJacobian
      (
      EcU32 startRow,
      EcU32 dof,
      EcManipulatorJacobian& jacobian
      ) const;

   /// make sure the sparsity description matrix is the right size
   /// for this end effector starting at the startRow position.
   virtual void rightSizeSparsityDescriptionMatrix
      (
      EcU32 startRow,
      EcU32 dof,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const;

   /// get the number of degrees of constraint for this end effector
   virtual EcU32 doc
      (
      ) const = 0;

   /// build a strip of a Jacobian that corresponds to this end effector.
   /**
    * @param manip The manipulator for this end effector
    * @param startRow The row index to start inserting the Jacobian component from this end effector
    * @param relativeLinkData Relative link data
    * @param isFixedBase A flag indicating whether or not the base is fixed
    * @param[in,out] activeState The manipulator active state
    * @param[out] jacobian The Jacobian with a strip for this end effector
    */
   virtual void insertJacobianComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcManipulatorActiveState&  activeState,
      EcManipulatorJacobian& jacobian
      ) const = 0;

   /// build a strip of a sparsity description matrix
   /// (with true where there may be nonzero values and false
   /// where there cannot be nonzero values)
   /**
    * @param manip The manipulator for this end effector
    * @param startRow The row index to start inserting the sparsity component from this end effector
    * @param relativeLinkData Relative link data
    * @param isFixedBase A flag indicating whether or not the base is fixed
    * @param sparsityDescriptionMatrix The matrix with a sparsity strip for this end effector
    */
   virtual void insertSparsityComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const = 0;

   /// build a segment of an end-effector error weight starting at
   /// the start-row index.
   /**
    * @param startRow The start row for this end effector
    * @param weights The weight vector with a segment for this end effector
    */
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const = 0;

   /// @brief Calculate a placement value for the end effector in the system coordinates.
   /// The placement is described through an EcEndEffectorPlacement, which may have different
   /// meanings for different end effector types.
   /// @param manip The manipulator for this end effector
   /// @param activeState The manipulator active state
   /// @param[out] placement The placement of the end effector
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const = 0;

   /// Calculate a placement value for the end effector in the primary frame of the relative link.
   /**
   The default implementation just calls calculatePlacement and transforms the placement from the system frame to the primary frame of the relative link. The derived class may want to have its own, more efficient implementation.
   */
   virtual void calculatePlacementInRelative
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// @brief Calculate end effector velocity.  The velocity may have different meanings for different end effector types.
   /**
    * @param manip The manipulator for this end effector
    * @param actState The manipulator active state
    * @param[out] velocity The placement of the end effector
    * @param startInsertionIndex The index of velocity vector at which this end effector velocity should start
    */
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex
      ) const = 0;

   /// @brief Calculate end effector acceleration. The acceleration may have different meanings for different end effector types.
   /**
    * @param manip The manipulator for this end effector
    * @param actState The manipulator active state
    * @param[out] acceleration The placement of the end effector
    * @param startInsertionIndex The index of acceleration vector at which this end effector acceleration should start
    */
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex
      ) const = 0;

   /// calculate an end-effector velocity that drives the end
   /// effector toward the guide (desired) placement.
   /**
    * The calculated velocity is typically constrained by the motion filter of the end effector unless filtering is
    * not active. The filtered velocity is expressed through an EcXmlRealVector.  The guide frame is always
    * represented in system coordinates.
    * @param[in] manip The manipulator for this end effector
    * @param[in] guide The guide (desired) placement
    * @param[in] inputVelocity The desired end effector velocity. The will be added to the velocity that would drive
    *          the end effector toward the guide.
    * @param[in] lastVelocity The current end effector velocity (normally computed from previous step)
    * @param[in] timeStep The time step
    * @param[in,out] activeState The manipulator active state
    * @param[out] filteredVelocity The calculated end effector velocity
    * @sa setFilteringActive()
    */
   virtual void filterEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& guide,
      const EcXmlRealVector& inputVelocity,
      const EcXmlRealVector& lastVelocity,
      EcReal timeStep,
      EcManipulatorActiveState& activeState,
      EcXmlRealVector& filteredVelocity
      ) const = 0;

   /// filter an input end-effector velocity by applying velocity
   /// and acceleration thresholds
   /// @param[in] inputVelocity The desired end effector velocity
   /// @param[in] lastVelocity The current end effector velocity (normally computed from previous step)
   /// @param[in] timeStep The time step
   /// @param[out] filteredVelocity The calculated end effector velocity
   virtual void filterEndEffectorVelocity
      (
      const EcXmlRealVector& inputVelocity,
      const EcXmlRealVector& lastVelocity,
      EcReal timeStep,
      EcXmlRealVector& filteredVelocity
      ) const = 0;

   /// For estimation and simulation purposes, calculate the estimated minimum time it takes this end effector to move
   /// from one position to another
   /**
    * @param actual The end-effector's start position
    * @param desired The end-effector's end position
    * @return The minimum time
    */
   virtual EcReal minimumTime
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const = 0;

   /// Calculate the difference between start and finish. The difference is a non-negative scalar value that captures
   /// how far two end-effector's positions are to each other.
   /**
    * @param actual The end-effector's start position
    * @param desired The end-effector's end position
    */
   virtual EcReal difference
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const = 0;

   /// get the labels of all editable components
   virtual const EcXmlStringVector& editingLabels
      (
      ) const;

   /// get the tooltips of all editable components
   virtual const EcXmlStringVector& tooltipLabels
      (
      ) const;

   /// get the values of all editable components
   virtual const EcXmlStringVector& editableValues
      (
      ) const = 0;

   /// set the values of the editable components
   virtual void setEditableValues
      (
      const EcXmlStringVector& values
      ) = 0;

   /// set the values of the editable components (from the member variable)
   virtual void setEditableValues
      (
      );

   /// set the values of the editable component one at a time
   virtual void setEditableValue
      (
      const EcU32&    index,
      const EcString& valueString
      );

   /// get the (end-effector specific) measure of the motion (velocity) threshold
   virtual EcReal motionThreshold
      (
      ) const = 0;

   /// set the (end-effector specific) measure of the motion (velocity) threshold
   virtual void setMotionThreshold
      (
      EcReal motionThreshold
      ) = 0;

   /// get the (end-effector specific) measure of the acceleration threshold
   virtual EcReal accelerationThreshold
      (
      ) const = 0;

   /// set the (end-effector specific) measure of the acceleration threshold
   virtual void setAccelerationThreshold
      (
      EcReal accelerationThreshold
      ) = 0;

   /// converts an end-effector placement from the system coordinates to the relative link's frame. If the end-effector doesn't have a relative link, relXForm is simply sysXForm.
   /**
   \param[in] manip The manipulator to which this end-effector belongs.
   \param[in] sysXForm The end-effector placement in system coordinates.
   \param[in,out] activePosState The active position state.
   \param[out] relXForm The end-effector placement in the relative link's frame.
   \return True if successful or false the relative link data is invalid, e.g. the linkID doesn't exist in the manipulator.
   */
   virtual EcBoolean convertPlacementFromSystemToRelative
     (
     const EcIndividualManipulator& manip,
     const EcEndEffectorPlacement& sysXForm,
     EcManipulatorActivePositionState&  activePosState,
     EcEndEffectorPlacement& relXForm
     ) const;

   /// converts an end-effector placement from the relative link's frame to the system coordinates. If the end-effector doesn't have a relative link, sysXForm is simply relXForm.
   /**
   \param[in] manip The manipulator to which this end-effector belongs.
   \param[in] relXForm The end-effector placement in the relative link's frame.
   \param[in,out] activePosState The active position state.
   \param[out] sysXForm The end-effector placement in system coordinates.
   \return True if successful or false the relative link data is invalid, e.g. the linkID doesn't exist in the manipulator.
   */
   virtual EcBoolean convertPlacementFromRelativeToSystem
     (
     const EcIndividualManipulator& manip,
     const EcEndEffectorPlacement& relXForm,
     EcManipulatorActivePositionState&  activePosState,
     EcEndEffectorPlacement& sysXForm
     ) const;

   /// get the multiplier for soft-constraint error weights
   virtual EcReal softConstraintMultiplier
      (
      ) const;

   /// set the multiplier for soft-constraint error weights
   virtual void setSoftConstraintMultiplier
      (
      EcReal value
      ) const;

   /// calculate an end-effector differential between the current and goal.
   /// the error is represented in a vector of size doc().
   /// The derived class should implement this. By default, the implementation
   /// in this base class return the error of zero.
   /**
    * @param[in] manip The manipulator for this end effector
    * @param[in] goal The goal placement
    * @param[in,out] activeState The manipulator active state
    * @param[out] differential The calculated end effector differential
    */
   virtual void calculateEndEffectorError
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& goal,
      EcManipulatorActiveState&  activeState,
      EcXmlRealVector& differential
      ) const;

   /// get the speed factor. This factor is multiplied with the velocity and acceleration/deceleration thresholds,
   /// thus allowing the end-effector speed to be adjusted at run-time. By default, this is 1.
   virtual EcReal speedFactor
      (
      ) const;

   /// set the speed factor
   virtual void setSpeedFactor
      (
      EcReal value
      );

   /// returns whether filtering is active. If it is, then the velocity will be filtered according to the filtering mode.
   /// If not, then the velocity will be computed such that the returned velocity will result in the goal is accomplished
   /// in one step.
   virtual EcBoolean filteringActive
      (
      ) const;

   /// returns whether filtering is active.
   virtual void setFilteringActive
      (
      EcBoolean value
      );

   /// get end-effector tool-tip
   virtual const EcXmlString& endEffectorTooltip
      (
      );

   /// get whether to use external offset.
   virtual EcBoolean useExternalOffset
      (
      ) const;

   /// set whether to use external offset. This allows multiple end-effectors to share the same offset and allows easy
   /// changing of the offset.
   virtual void setUseExternalOffset
      (
      EcBoolean value
      );

   /// get the index of the external offset to be used
   virtual EcU32 externalOffsetIndex
      (
      ) const;

   /// set the index of the external offset to be used
   virtual void setExternalOffsetIndex
      (
      EcU32 value
      );

   /// the pointer to the external offset. The offset is the offset from the primary frame of the link to which this end
   /// effector is attached to the application point.
   virtual void setExternalOffsetPointer
      (
      const EcCoordinateSystemTransformation* value
      );

protected:
   /// calculate the general velocity of a frame in the outboard link's
   /// primary frame due to unit joint motion of the inboard link.
   /// (i.e., 1 m/s or 1 rad/s)
   virtual void getFrameMotion
      (
      const EcManipulatorLink& inboardLink,
      const EcManipulatorLink& outboardLink,
      const EcCoordinateSystemTransformation& frame,
      EcManipulatorActivePositionState& activePositionState,
      EcGeneralVelocity& frameMotion
      ) const;


   /// calculate the location of a point in system coordinates.  The
   /// input point vector is represented in link coordinates
   virtual EcVector pointPosition
      (
      const EcManipulatorLink& link,
      const EcVector& point,
      EcManipulatorActivePositionState& activePositionState
      ) const;

protected:
   /// the string identifier for the link
   EcXmlString                    m_LinkIdentifier;

   /// the end-effector placement
   EcEndEffectorRelativeLinkData  m_RelativeLinkData;

   /// a flag indicating that this is a hard constraint
   EcXmlBoolean                   m_IsHardConstraint;

   /// a flag indicating that this end effector is editable
   EcXmlBoolean                   m_IsEditable;

   /// a flag indicating whether to use external offset
   EcXmlBoolean                   m_UseExternalOffset;

   /// Index of the external offset to be used
   EcXmlU32                       m_ExternalOffsetIndex;

   /// the labels of all editable components
   EcXmlStringVector              m_EditingLabels;

   /// the values of all editable components
   mutable EcXmlStringVector      m_EditableValues;

   /// number of Editable Value
   EcXmlU32                       m_NumEditable;

   /// the tooltips for editable components
   EcXmlStringVector              m_TooltipLabels;

   /// non-XML data below
   /// the multiplier for soft-constraint error weights
   mutable EcReal                 m_SoftConstraintMultiplier;

   /// the degrees of freedom in a floating base
   static const EcU32             m_theBaseDof;

   /// end-effector tooltip
   EcXmlString                    m_EeTooltip;

   /// pointer to the external offset
   const EcCoordinateSystemTransformation*   m_pExternalOffset;
};

#endif // ecEndEffector_H_
