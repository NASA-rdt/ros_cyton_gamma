#ifndef ecPointRotateEndEffector_H_
#define ecPointRotateEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPointRotateEndEffector.h
/// @class EcPointRotateEndEffector
/// @brief A 4-dof end effector with 3-dof point and 1-dof rotation.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include "ecPointMotionFilter.h"
#include "ecScalarMotionFilter.h"

#include <foundCommon/ecCoordSysXForm.h>

/// A 4-dof end effector with 3-dof point and 1-dof rotation.
/// The 1-dof rotation is defined as the angle between the z-axis of the EE
/// and a reference axis of the system frame (non-relative EE) or a reference link
/// (relative EE). Deprecated.
/// @deprecated
class EC_ACTIN_CONTROL_DECL EcPointRotateEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcPointRotateEndEffector
      (
      );

   /// destructor
   virtual ~EcPointRotateEndEffector
      (
      );

   /// copy constructor
   EcPointRotateEndEffector
      (
      const EcPointRotateEndEffector& orig
      );

   /// assignment operator
   EcPointRotateEndEffector& operator=
      (
      const EcPointRotateEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPointRotateEndEffector& orig
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

   /// gets the point motion filter
   virtual const EcPointMotionFilter& pointMotionFilter
      (
      ) const;

   /// sets the point motion filter
   virtual void setPointMotionFilter
      (
      const EcPointMotionFilter& motionFilter
      );

   /// gets the scalar motion filter
   virtual const EcScalarMotionFilter& scalarMotionFilter
      (
      ) const;

   /// sets the motion filter
   virtual void setScalarMotionFilter
      (
      const EcScalarMotionFilter& motionFilter
      );

   /// gets the frame
   virtual const EcCoordinateSystemTransformation& frame
      (
      ) const;

   /// sets the frame
   virtual void setFrame
      (
      const EcCoordinateSystemTransformation& frame
      );

   /// gets the reference axis
   virtual const EcVector& referenceAxis
      (
      ) const;

   /// sets the reference axis
   virtual void setReferenceAxis
      (
      const EcVector& axis
      );

   /// gets the linear error weight
   virtual const EcReal& linearErrorWeight
      (
      ) const;

   /// sets the linear error weight
   virtual void setLinearErrorWeight
      (
      const EcReal& linearErrorWeight
      );

   /// gets the angular error weight
   virtual const EcReal& angularErrorWeight
      (
      ) const;

   /// sets the angular error weight
   virtual void setAngularErrorWeight
      (
      const EcReal& angularErrorWeight
      );

   /// @copydoc EcEndEffector::motionThreshold()
   EcReal motionThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setMotionThreshold()
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

   /// @copydoc EcEndEffector::editableValues()
   virtual const EcXmlStringVector& editableValues
      (
      ) const;

   /// @copydoc EcEndEffector::setEditableValues()
   virtual void setEditableValues
      (
      const EcXmlStringVector& values
      );

   /// get the number of degrees of constraint
   virtual EcU32 doc
      (
      ) const;

   /// Build a strip of a jacobian
   virtual void insertJacobianComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcManipulatorActiveState&  activeState,
      EcManipulatorJacobian& jacobian
      ) const;

   /// build a strip of a sparsity description matrix
   /// (with true where there may be nonzero values and false
   /// where there cannot be nonzero values)
   virtual void insertSparsityComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const;

   /// build a segment of an end-effector error weight starting at
   /// the start-row index.
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const;

   /// calculate a placement value for the end effector
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// calculate end effector velocity.  The velocity
   /// may have different meanings for different end effector types.
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// calculate end effector acceleration.  The acceleration
   /// may have different meanings for different end effector types.
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

   // filter an input end-effector velocity by applying velocity and acceleration thresholds
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
   static EcPointRotateEndEffector nullObject
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

   /// Calculate the minimum time for position simulation
   virtual EcReal minimumTime
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// Calculate the difference between start and finish
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
   /// the point motion filter (for 3-dof point motion)
   EcPointMotionFilter  m_PointMotionFilter;

   /// the scalar motion filter (for 1-dof angular motion)
   EcScalarMotionFilter m_ScalarMotionFilter;

   /// the end-effector frame with respect to the link's primary frame
   EcCoordinateSystemTransformation  m_Frame;

   /// the axis of reference
   EcXmlVector          m_ReferenceAxis;

   /// the error weight for the linear components
   EcXmlReal            m_LinearErrorWeight;

   /// the error weight for the angular components
   EcXmlReal            m_AngularErrorWeight;
};

#endif // ecPointRotateEndEffector_H_
