#ifndef EcPointDistanceEndEffector_H_
#define EcPointDistanceEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecPointDistanceEndEffector.h
/// @class EcPointDistanceEndEffector
/// @brief A point-distance end effector.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPointBasedEndEffector.h"
#include "ecScalarMotionFilter.h"

/** Holds a point-distance end-effector component.  This class constrains
    the distance between any two points on the manipulator.
*/
class EC_ACTIN_CONTROL_DECL EcPointDistanceEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcPointDistanceEndEffector
      (
      );

   /// destructor
   virtual ~EcPointDistanceEndEffector
      (
      );

   /// copy constructor
   EcPointDistanceEndEffector
      (
      const EcPointDistanceEndEffector& orig
      );

   /// assignment operator
   EcPointDistanceEndEffector& operator=
      (
      const EcPointDistanceEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPointDistanceEndEffector& orig
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

   /// gets the first point
   virtual const EcVector& pointOne
      (
      ) const;

   /// sets the first point
   virtual void setPointOne
      (
      const EcVector& point
      );

   /// gets the second point
   virtual const EcVector& pointTwo
      (
      ) const;

   /// sets the second point
   virtual void setPointTwo
      (
      const EcVector& point
      );

   /// gets the first label
   virtual const EcString& labelOne
      (
      ) const;

   /// sets the first label
   virtual void setLabelOne
      (
      const EcString& label
      );

   /// gets the second label
   virtual const EcString& labelTwo
      (
      ) const;

   /// sets the second label
   virtual void setLabelTwo
      (
      const EcString& label
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

   /// @copydoc EcEndEffector::motionThreshold
   /// For this end effector, it's the maximum speed between the two points.
   EcReal motionThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setMotionThreshold
   /// For this end effector, it's the maximum speed between the two points.
   void setMotionThreshold
      (
      EcReal motionThreshold
      );

   /// @copydoc EcEndEffector::accelerationThreshold
   /// For this end effector, it's the maximum acceleration between the two points.
   virtual EcReal accelerationThreshold
      (
      ) const;

   /// @copydoc EcEndEffector::setAccelerationThreshold
   /// For this end effector, it's the maximum acceleration between the two points.
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

   /// calculate vector placement values for the two points
   virtual void calculatePointPlacements
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcVector& pointOnePlacement,
      EcVector& pointTwoPlacement
      ) const;

   /// calculate vector velocities values for the two points
   virtual void calculatePointVelocities
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcVector& pointOneVelocity,
      EcVector& pointTwoVelocity
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
   static EcPointDistanceEndEffector nullObject
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
   /// the first point
   EcXmlVector           m_PointOne;

   /// the second point
   EcXmlVector           m_PointTwo;

   /// the link label for the first point
   EcXmlString           m_LabelOne;

   /// the link label for the second point
   EcXmlString           m_LabelTwo;

   /// the motion filter
   EcScalarMotionFilter  m_MotionFilter;

   /// the error weight for this end effector
   EcXmlReal             m_ErrorWeight;

   // non-XML below

   /// shortcut index for the link 1
   mutable EcU32         m_LinkIndexOne;
   /// shortcut index for the link 2
   mutable EcU32         m_LinkIndexTwo;

   /// a link-index validity flag
   mutable EcBoolean     m_LinkIndicesValidity;

   /// the minimum allowable distance
   static const EcReal   m_theMinimumDistance;

};

/// a vector of point end effectors
typedef EcXmlVectorType<EcPointDistanceEndEffector> EcPointDistanceEndEffectorVector;

#endif // EcPointDistanceEndEffector_H_
