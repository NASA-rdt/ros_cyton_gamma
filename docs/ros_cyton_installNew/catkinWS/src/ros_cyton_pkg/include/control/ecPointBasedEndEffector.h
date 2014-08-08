#ifndef ecPointBasedEndEffector_H_
#define ecPointBasedEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPointBasedEndEffector.h
/// @class EcPointBasedEndEffector
/// @brief An abstract class for end effector that uses point motion filter.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include "ecPointMotionFilter.h"

// forward declarations
class EcManipulatorLink;

class EC_ACTIN_CONTROL_DECL EcPointBasedEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcPointBasedEndEffector
      (
      );

   /// destructor
   virtual ~EcPointBasedEndEffector
      (
      );

   /// copy constructor
   EcPointBasedEndEffector
      (
      const EcPointBasedEndEffector& orig
      );

   /// assignment operator
   EcPointBasedEndEffector& operator=
      (
      const EcPointBasedEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPointBasedEndEffector& orig
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the motion filter
   virtual const EcPointMotionFilter& pointMotionFilter
      (
      ) const;

   /// sets the motion filter
   virtual void setPointMotionFilter
      (
      const EcPointMotionFilter& pointMotionFilter
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
   /// parameters are EcVector (for point velocity), instead of EcXmlRealVector.
   /// @sa filterEndEffectorVelocity, convertToPointVelocity, convertFromPointVelocity
   virtual void filterPointEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& guide,
      const EcVector& inputPointVelocity,
      const EcVector& lastPointVelocity,
      EcReal timeStep,
      EcManipulatorActiveState&  activeState,
      EcVector& filteredPointVelocity
      ) const;

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

   /// Convert the velocity from the vector form to the point velocity form. This is end-effector specific.
   /// Derived class should override this method. The default implementation is provided for convenience and
   /// basically put the first three elements as linear and the last three as angular if the size allows.
   virtual void convertToPointVelocity
      (
      const EcXmlRealVector& velocity,
      EcVector& pointVelocity
      ) const;

   /// Convert the velocity from the point velocity form to the vector form. This is end-effector specific.
   /// Derived class should override this method.
   virtual void convertFromPointVelocity
      (
      const EcVector& pointVelocity,
      EcXmlRealVector& velocity
      ) const;

protected:
   /// the motion filter
   EcPointMotionFilter   m_PointMotionFilter;
};

#endif // ecPointBasedEndEffector_H_
