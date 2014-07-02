#ifndef ecFrameBasedEndEffector_H_
#define ecFrameBasedEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrameBasedEndEffector.h
/// @class EcFrameBasedEndEffector
/// @brief An abstract class for end effector that uses general motion filter.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include "ecGenMotionFilter.h"

#include <foundCommon/ecCoordSysXForm.h>

// forward declarations
class EcManipulatorLink;

/// An abstract class for end effector that uses general motion filter and the end effector
/// is specified by a frame (or EcCoordinateSystemTransformation).
class EC_ACTIN_CONTROL_DECL EcFrameBasedEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcFrameBasedEndEffector
      (
      );

   /// destructor
   virtual ~EcFrameBasedEndEffector
      (
      );

   /// copy constructor
   EcFrameBasedEndEffector
      (
      const EcFrameBasedEndEffector& orig
      );

   /// assignment operator
   EcFrameBasedEndEffector& operator=
      (
      const EcFrameBasedEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFrameBasedEndEffector& orig
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the motion filter
   virtual const EcGeneralMotionFilter& motionFilter
      (
      ) const;

   /// sets the motion filter
   virtual void setMotionFilter
      (
      const EcGeneralMotionFilter& motionFilter
      );

   /// gets the frame. This is where the end effector is located with respect to the
   /// primary frame of the link to which this end effector is attached.
   /// @sa EcEndEffector::linkIdentifier
   virtual const EcCoordinateSystemTransformation& frame
      (
      ) const;

   /// sets the frame
   virtual void setFrame
      (
      const EcCoordinateSystemTransformation& frame
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
   /// For this end-effector, it's the maximum linear velocity of the end-effector.
   EcReal motionThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setMotionThreshold()
   /// For this end-effector, it's the maximum linear velocity of the end-effector.
   void setMotionThreshold
      (
      EcReal motionThreshold
      );

   /// @copydoc EcEndEffector::accelerationThreshold()
   /// For this end-effector, it's the maximum linear acceleration of the end-effector.
   virtual EcReal accelerationThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setAccelerationThreshold()
   /// For this end-effector, it's the maximum linear acceleration of the end-effector.
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

   /// calculate an end-effector velocity that drives the end effector toward the guide placement.
   /// This is the same as EcFrameBasedEndEffector::filterEndEffectorVelocity except the velocities in all the
   /// parameters are EcGeneralVelocity, instead of EcXmlRealVector.
   /// @sa filterEndEffectorVelocity, convertToGeneralVelocity, convertFromGeneralVelocity
   virtual void filterFrameEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& guide,
      const EcGeneralVelocity& inputFrameVelocity,
      const EcGeneralVelocity& lastFrameVelocity,
      EcReal timeStep,
      EcManipulatorActiveState&  activeState,
      EcGeneralVelocity& filteredFrameVelocity
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
   /// Convert the velocity from the vector form to the general velocity form. This is end-effector specific.
   /// Derived class should override this method. The default implementation is provided for convenience and
   /// basically put the first three elements as linear and the last three as angular if the size allows.
   virtual void convertToGeneralVelocity
      (
      const EcXmlRealVector& velocity,
      EcGeneralVelocity& generalVelocity
      ) const;

   /// Convert the velocity from the general velocity form to the vector form. This is end-effector specific.
   /// Derived class should override this method.
   virtual void convertFromGeneralVelocity
      (
      const EcGeneralVelocity& generalVelocity,
      EcXmlRealVector& velocity
      ) const;

protected:
   /// return either the local frame or total offset depending on whether external offset is used
   const EcCoordinateSystemTransformation frameOffset
      (
      ) const;

   /// the motion filter
   EcGeneralMotionFilter m_MotionFilter;

   /// the end-effector frame with respect to the link's primary frame
   EcCoordinateSystemTransformation  m_Frame;

   /// the error weight for the linear components
   EcXmlReal             m_LinearErrorWeight;

   /// the error weight for the angular components
   EcXmlReal             m_AngularErrorWeight;
};

#endif // ecFrameBasedEndEffector_H_
