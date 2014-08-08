#ifndef ecAxisRotateEndEffector_H_
#define ecAxisRotateEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecAxisRotateEndEffector.h
/// @class EcAxisRotateEndEffector
/// @brief An end effector with 1-dof rotation.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include "ecScalarMotionFilter.h"

#include <foundCommon/ecCoordSysXForm.h>

/// Hold description of an end effector with 1-dof rotation. The 1-dof rotation is defined as the angle between
/// the z-axis of the EE and a reference axis of the system frame (non-relative EE) or a reference link
/// (relative EE) minus 90 degrees.
class EC_ACTIN_CONTROL_DECL EcAxisRotateEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcAxisRotateEndEffector
      (
      );

   /// destructor
   virtual ~EcAxisRotateEndEffector
      (
      );

   /// copy constructor
   EcAxisRotateEndEffector
      (
      const EcAxisRotateEndEffector& orig
      );

   /// assignment operator
   EcAxisRotateEndEffector& operator=
      (
      const EcAxisRotateEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAxisRotateEndEffector& orig
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
   /// @param[in] other   (EcXmlObject*) pointer to EcXmlObject
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

   /// gets the motion filter
   /// @return The motion filter
   virtual const EcScalarMotionFilter& motionFilter
      (
      ) const;

   /// sets the motion filter
   /// @param[in] motionFilter   (EcScalarMotionFilter&) value to set
   virtual void setMotionFilter
      (
      const EcScalarMotionFilter& motionFilter
      );

   /// gets the orientation
   /// @return (EcOrientation&) The orientation
   virtual const EcOrientation& orientation
      (
      ) const;

   /// sets the orientation
   /// @param[in] orientation   (orientation) value to set
   virtual void setOrientation
      (
      const EcOrientation& orientation
      );

   /// gets the reference axis
   /// @return (EcVector&) The reference axis
   virtual const EcVector& referenceAxis
      (
      ) const;

   /// sets the reference axis
   /// @param[in] axis   (axis) value to set
   virtual void setReferenceAxis
      (
      const EcVector& axis
      );

   /// gets the error weight
   /// @return (EcReal) weighting factor for normalized relative joint rates
   virtual EcReal errorWeight
      (
      ) const;

   /// sets the error weight
   /// @param[in] weight   (EcReal) value to set
   virtual void setErrorWeight
      (
      EcReal weight
      );

   /// @copydoc EcEndEffector::motionThreshold()
   /// For this end-effector, it's the maximum angular velocity of the 1-dof rotation
   EcReal motionThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setMotionThreshold()
   /// For this end-effector, it's the maximum angular velocity of the 1-dof rotation
   void setMotionThreshold
      (
      EcReal motionThreshold
      );

   /// @copydoc EcEndEffector::accelerationThreshold()
   /// For this end-effector, it's the maximum angular acceleration of the 1-dof rotation
   virtual EcReal accelerationThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setAccelerationThreshold()
   /// For this end-effector, it's the maximum angular acceleration of the 1-dof rotation
   virtual void setAccelerationThreshold
      (
      EcReal accelerationThreshold
      );

   /// @copydoc EcEndEffector::editableValues()
   virtual const EcXmlStringVector& editableValues
      (
      ) const;

   /// @copydoc EcEndEffector::setEditableValues()
   virtual void setEditableValues
      (
      const EcXmlStringVector& values
      );

   /// @copydoc EcEndEffector::doc()
   /// For this end effector, it returns 1.
   virtual EcU32 doc
      (
      ) const;

   /// @copydoc EcEndEffector::insertJacobianComponent()
   virtual void insertJacobianComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcManipulatorActiveState&  activeState,
      EcManipulatorJacobian& jacobian
      ) const;

   /// @copydoc EcEndEffector::insertSparsityComponent()
   virtual void insertSparsityComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const;

   /// @copydoc EcEndEffector::insertErrorWeightComponent()
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const;

   /// For this end effector, it's the angle between the z-axis of the EE and a reference axis.
   /// Its scalar value is put in the Z translation component of the placement. @n
   /// @copydoc EcEndEffector::calculatePlacement()
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// For this end effector, it's the velocity of the defined angle. @n
   /// @copydoc EcEndEffector::calculateVelocity()
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

   /// @copydoc EcEndEffector::filterEndEffectorVelocity()
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
   /// @param[in] stream   (EcXmlReader&) stream to be read from file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream   (EcXmlWriter&) stream to be written into file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null point end effector
   /// @return (EcAxisRotateEndEffector) The null object
   static EcAxisRotateEndEffector nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The created xml object
   static EcXmlObject* creator
      (
      );

   /// @copydoc EcEndEffector::minimumTime()
   virtual EcReal minimumTime
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// @copydoc EcEndEffector::difference()
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
   /// @return The factor influencing the velocity of the end-effector
   virtual EcReal speedFactor
      (
      ) const;

   /// @copydoc EcEndEffector::setSpeedFactor()
   /// @param[in] value   (EcReal) value to be set
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
   /// the motion filter
   EcScalarMotionFilter m_MotionFilter;

   /// the end-effector orientation with respect to the link's primary frame
   EcXmlOrientation     m_Orientation;

   /// the axis of reference
   EcXmlVector          m_ReferenceAxis;

   /// the error weight for the angular components
   EcXmlReal            m_ErrorWeight;
};

#endif // ecAxisRotateEndEffector_H_
