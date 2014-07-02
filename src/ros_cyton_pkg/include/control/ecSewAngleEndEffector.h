#ifndef ecSewAngleEndEffector_H_
#define ecSewAngleEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSewAngleEndEffector.h
/// @class EcSewAngleEndEffector
/// @brief An end-effector component that represents a SEW
///        (Shoulder-Elbow-Wrist) angle
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include <foundCommon/ecCoordSysXForm.h>

/// An 1-doc end-effector component that represents a SEW (Shoulder-Elbow-Wrist) angle
/// This is mostly used for 7-DOF anthropomophic robotic arm
class EC_ACTIN_CONTROL_DECL EcSewAngleEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcSewAngleEndEffector
      (
      );

   /// destructor
   virtual ~EcSewAngleEndEffector
      (
      );

   /// copy constructor
   EcSewAngleEndEffector
      (
      const EcSewAngleEndEffector& orig
      );

   /// assignment operator
   EcSewAngleEndEffector& operator=
      (
      const EcSewAngleEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSewAngleEndEffector& orig
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

   /// gets the shoulder link
   virtual const EcString& shoulderLink
      (
      ) const;

   /// sets the shoulder link
   virtual void setShoulderLink
      (
      const EcString& value
      );

   /// gets the elbow link
   virtual const EcString& elbowLink
      (
      ) const;

   /// sets the elbow link
   virtual void setElbowLink
      (
      const EcString& value
      );

   /// gets the wrist link
   virtual const EcString& wristLink
      (
      ) const;

   /// sets the wrist link
   virtual void setWristLink
      (
      const EcString& value
      );

   /// gets the elbow point
   virtual const EcVector& elbowPoint
      (
      ) const;

   /// sets the elbow point
   virtual void setElbowPoint
      (
      const EcVector& value
      );

   /// gets the wrist point
   virtual const EcVector& wristPoint
      (
      ) const;

   /// sets the wrist point
   virtual void setWristPoint
      (
      const EcVector& value
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

   /// get the measure of the motion threshold
   EcReal motionThreshold
      (
      ) const;

   /// set the measure of the motion threshold
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

   /// gets the error weight
   virtual const EcReal& errorWeight
      (
      ) const;

   /// sets the error weight
   virtual void setErrorWeight
      (
      const EcReal& errorWeight
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

   /// @copydoc EcEndEffector::calculatePlacement
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// @copydoc EcEndEffector::calculateVelocity
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

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
   static EcSewAngleEndEffector nullObject
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

   /// @copydoc EcEndEffector::speedFactor()
   virtual EcReal speedFactor
      (
      ) const;

   /// @copydoc EcEndEffector::setSpeedFactor()
   virtual void setSpeedFactor
      (
      EcReal value
      );

protected:
   /// set the pointers for shoulder, elbow, and wrist links
   virtual void setLinkPointers
      (
      const EcIndividualManipulator& manip
      ) const;

   /// clear the pointers for shoulder, elbow, and wrist links
   virtual void clearLinkPointers
      (
      ) const;

   /// calculate the velocity of the point in the outboard link's
   /// primary frame due to unit joint motion of the inboard link.
   /// (i.e., 1 m/s or 1 rad/s)
   virtual EcVector pointMotion
      (
      const EcManipulatorLink& inboardLink,
      const EcManipulatorLink& outboardLink,
      const EcVector& point,
      EcManipulatorActivePositionState& activePositionState
      ) const;

   /// calculate the velocity of the point in the link's
   virtual EcVector pointVelocity
      (
      const EcManipulatorLink& link,
      const EcVector& point,
      EcManipulatorActiveState& activeState
      ) const;

   /// calculate the derivative of the unit vector of a given vector
   /**
   \param[in] v The vector
   \param[in] dv The derivative of the vector
   \param[out] du The derivative of the unit vector
   */
   virtual void unitVectorDerivative
      (
      const EcVector& v,
      const EcVector& dv,
      EcVector& du
      ) const;

   /// Calculate the derivative of SEW angle.
   virtual EcReal sewDerivative
      (
      const EcVector& dR1,
      const EcVector& dR2
      ) const;

   /// calculate intermediate values
   virtual void calculateIntermediates
      (
      EcManipulatorActivePositionState& activePositionState
      ) const;

protected:
   /// the label of the shoulder link
   EcXmlString                m_ShoulderLink;

   /// the label of the elbow link
   EcXmlString                m_ElbowLink;

   /// the label of the wrist link
   EcXmlString                m_WristLink;

   /// the point on the elbow link
   EcXmlVector                m_ElbowPoint;

   /// the point on the wrist link
   EcXmlVector                m_WristPoint;

   /// the feedback gain
   EcXmlReal                  m_Gain;

   /// the feedback threshold
   EcXmlReal                  m_Threshold;

   /// the error weight for this end effector
   EcXmlReal                  m_ErrorWeight;

   // non-XML below

   /// the speed factor
   EcReal                     m_SpeedFactor;

   // pointer to shoulder, elbow, and wrist links. Cached for performance
   mutable const EcManipulatorLink*   m_pShoulderLink;   ///< const pointer to the sholder link
   mutable const EcManipulatorLink*   m_pElbowLink;      ///< const pointer to the elbow link
   mutable const EcManipulatorLink*   m_pWristLink;      ///< const pointer to the wrist link

   // these are intermediate values (avoid reuse by derived classes)
   /// inverse of the shoulder link's DH frame
   mutable EcCoordinateSystemTransformation  m_ShoulderDhInSysInv; 
   mutable EcVector           m_r1;    ///< r1 value
   mutable EcVector           m_r2;    ///< r2 value
   mutable EcVector           m_r1u;   ///< r1u value
   mutable EcVector           m_r2u;   ///< r2u value
   mutable EcVector           m_a;     ///< a value
   mutable EcVector           m_b;     ///< b value
};

#endif // ecSewAngleEndEffector_H_
