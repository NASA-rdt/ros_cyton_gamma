#ifndef ecLinearConstraintEndEffector_H_
#define ecLinearConstraintEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinearConstraintEndEffector.h
/// @class EcLinearConstraintEndEffector
/// @brief Holds a base class for a end-effector component that
///        represents a linear constraint on the joint values.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include "ecScalarMotionFilter.h"

/// Holds a base class for a end-effector component that represents a linear constraint on the joint values.
class EC_ACTIN_CONTROL_DECL EcLinearConstraintEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcLinearConstraintEndEffector
      (
      );

   /// destructor
   virtual ~EcLinearConstraintEndEffector
      (
      );

   /// copy constructor
   EcLinearConstraintEndEffector
      (
      const EcLinearConstraintEndEffector& orig
      );

   /// assignment operator
   EcLinearConstraintEndEffector& operator=
      (
      const EcLinearConstraintEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinearConstraintEndEffector& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the link labels
   virtual const EcXmlStringVector& linkLabels
      (
      ) const;

   /// sets the link labels
   virtual void setLinkLabels
      (
      const EcXmlStringVector& linkLabels
      );

   /// gets the link weights
   virtual const EcXmlRealVector& linkWeights
      (
      ) const;

   /// sets the link weights
   virtual void setLinkWeights
      (
      const EcXmlRealVector& linkWeights
      );

   /// gets the weighted sum
   virtual EcReal weightedSum
      (
      ) const;

   /// sets the weighted sum
   virtual void setWeightedSum
      (
      EcReal weightedSum
      );

   /// gets the gain
   virtual EcReal gain
      (
      ) const;

   /// sets the gain
   virtual void setGain
      (
      EcReal gain
      );

   /// gets the is-interactive flag
   virtual EcBoolean isInteractive
      (
      ) const;

   /// sets the is-interactive flag
   virtual void setIsInteractive
      (
      EcBoolean isInteractive
      );

   /// gets the error weight
   virtual const EcReal& errorWeight
      (
      ) const;

   /// sets the error weight
   virtual void setErrorWeight
      (
      const EcReal& errorWeight
      );

   /// gets the motion filter
   virtual const EcScalarMotionFilter& motionFilter
      (
      ) const;

   /// sets the motion filter
   virtual void setMotionFilter
      (
      const EcScalarMotionFilter& filter
      );

   /// @copydoc EcEndEffector::doc()
   /// For this end effector, it returns 1.
   virtual EcU32 doc
      (
      ) const;

   /// get the labels of all editable components
   virtual const EcXmlStringVector& editingLabels
      (
      ) const;

   /// get the values of all editable components
   virtual const EcXmlStringVector& editableValues
      (
      ) const;

   /// set the values of the editable components
   virtual void setEditableValues
      (
      const EcXmlStringVector& values
      );

   /// get the (end-effector specific) measure of the motion threshold
   EcReal motionThreshold
      (
      ) const;

   /// set the (end-effector specific) measure of the motion threshold
   void setMotionThreshold
      (
      EcReal motionThreshold
      );

   /// @copydoc EcEndEffector::accelerationThreshold()
   virtual EcReal accelerationThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setAccelerationThreshold()
   virtual void setAccelerationThreshold
      (
      EcReal accelerationThreshold
      );

   /// @copydoc EcEndEffector::insertJacobianComponent
   virtual void insertJacobianComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcManipulatorActiveState&  activeState,
      EcManipulatorJacobian& jacobian
      ) const;

   /// @copydoc EcEndEffector::insertSparsityComponent
   virtual void insertSparsityComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const;

   /// @copydoc EcEndEffector::insertErrorWeightComponent
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const;

   /// For this end effector, it is the error in the weighted sum. It's a scalar and its value
   /// is put in the Z translation component of the placement. @n
   /// @copydoc EcEndEffector::calculatePlacement
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// For this end effector, it's the weighted (specified by linkWeights()) sum of the joint velocities of
   /// all joints specified by linkLabels(). @n
   /// @copydoc EcEndEffector::calculateVelocity
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// Currently NOT implemented for this end effector, the acceleration is simply set to 0. @n
   /// @copydoc EcEndEffector::calculateAcceleration
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex=0
      ) const;

   /// @copydoc EcEndEffector::filterEndEffectorVelocity
   virtual void filterEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& guide,
      const EcXmlRealVector& inputVelocity,
      const EcXmlRealVector& lastVelocity,
      EcReal timeStep,
      EcManipulatorActiveState&  activeState,
      EcXmlRealVector& filteredVelocity
      ) const;

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

   /// get a null point end effector
   static EcLinearConstraintEndEffector nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// @copydoc EcEndEffector::minimumTime
   virtual EcReal minimumTime
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// @copydoc EcEndEffector::difference
   virtual EcReal difference
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// @copydoc EcEndEffector::calculateEndEffectorError()
   virtual void calculateEndEffectorError
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& goal,
      EcManipulatorActiveState&  activeState,
      EcXmlRealVector& differential
      ) const;

   /// @copydoc EcEndEffector::speedFactor()
   virtual EcReal speedFactor
      (
      ) const;

   /// @copydoc EcEndEffector::setSpeedFactor()
   virtual void setSpeedFactor
      (
      EcReal value
      );

   /// @copydoc EcEndEffector::filteringActive()
   virtual EcBoolean filteringActive
      (
      ) const;

   /// @copydoc EcEndEffector::setFilteringActive()
   virtual void setFilteringActive
      (
      EcBoolean value
      );

protected:

   /// set the shortcut link indices
   virtual void setLinkIndices
      (
      const EcIndividualManipulator& manip
      ) const;

   /// clear the shortcut link indices
   virtual void clearLinkIndices
      (
      ) const;

protected:
   /// the point describing the location end effector
   EcXmlStringVector           m_LinkLabels;

   /// the scaling terms
   EcXmlRealVector             m_LinkWeights;

   /// the constraint value for the weighted sum
   EcXmlReal                   m_WeightedSum;

   /// a flag indicating that this constraint is editable
   EcXmlBoolean                m_IsInteractive;

   /// the error weight for this end effector
   EcXmlReal                   m_ErrorWeight;

   /// the motion filter
   EcScalarMotionFilter        m_MotionFilter;

   /// deprecated
   /// the feedback gain
   EcXmlReal                   m_Gain;

   /// the feedback threshold
   EcXmlReal                   m_Threshold;

   // non-XML below

   /// an array for holding shortcut indices for the links
   mutable EcU32Vector         m_LinkIndices;

   /// an array of link-index validity flags
   mutable EcBooleanVector     m_LinkIndicesValidity;
};

#endif // ecLinearConstraintEndEffector_H_
