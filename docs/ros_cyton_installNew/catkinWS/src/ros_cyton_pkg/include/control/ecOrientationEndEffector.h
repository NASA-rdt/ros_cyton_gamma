#ifndef ecOrientationEndEffector_H_
#define ecOrientationEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecOrientationEndEffector.h
/// @class EcOrientationEndEffector
/// @brief Holds a 3D orientation end-effector component.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include "ecGenMotionFilter.h"
#include <xml/ecXmlOrientation.h>

/** Holds a 3D orientation end-effector component.
*/
class EC_ACTIN_CONTROL_DECL EcOrientationEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcOrientationEndEffector
      (
      );

   /// destructor
   virtual ~EcOrientationEndEffector
      (
      );

   /// copy constructor
   EcOrientationEndEffector
      (
      const EcOrientationEndEffector& orig
      );

   /// assignment operator
   EcOrientationEndEffector& operator=
      (
      const EcOrientationEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcOrientationEndEffector& orig
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

   /// gets the motion filter
   virtual const EcGeneralMotionFilter& motionFilter
      (
      ) const;

   /// sets the motion filter
   virtual void setMotionFilter
      (
      const EcGeneralMotionFilter& motionFilter
      );

   /// gets the orientation
   virtual const EcOrientation& orientation
      (
      ) const;

   /// sets the orientation
   virtual void setOrientation
      (
      const EcOrientation& orientation
      );

   /// gets the linear error weight
   virtual const EcReal& errorWeight
      (
      ) const;

   /// sets the linear error weight
   virtual void setErrorWeight
      (
      const EcReal& errorWeight
      );

   /// @copydoc EcEndEffector::doc()
   /// For this end effector, it returns 3
   virtual EcU32 doc
      (
      ) const;

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
      EcManipulatorActiveState& activeState,
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
   static EcOrientationEndEffector nullObject
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
   /// the motion filter
   EcGeneralMotionFilter m_MotionFilter;

   /// the end-effector frame with respect to the link's primary frame
   EcXmlOrientation      m_Orientation;

   /// the error weight for the linear components
   EcXmlReal             m_ErrorWeight;
};

/// a vector of frame end effectors
typedef EcXmlVectorType<EcOrientationEndEffector> EcOrientationEndEffectorVector;

#endif // ecOrientationEndEffector_H_
