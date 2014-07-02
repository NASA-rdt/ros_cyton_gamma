#ifndef ecSpatialMomentumEndEffector_H_
#define ecSpatialMomentumEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSpatialMomentumEndEffector.h
/// @class EcSpatialMomentumEndEffector
/// @brief A momentum end effector.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffector.h"
#include <manipulator/ecMatrixDTool.h>

/** A spatial (linear and angular) momentum constrait.  There is no positional component
    to this constraint--it just sets the linear and angular momentum produced by by the
    robot motion.
*/
class EC_ACTIN_CONTROL_DECL EcSpatialMomentumEndEffector : public EcEndEffector
{
public:
   /// default constructor
   EcSpatialMomentumEndEffector
      (
      );

   /// destructor
   virtual ~EcSpatialMomentumEndEffector
      (
      );

   /// copy constructor
   EcSpatialMomentumEndEffector
      (
      const EcSpatialMomentumEndEffector& orig
      );

   /// assignment operator
   EcSpatialMomentumEndEffector& operator=
      (
      const EcSpatialMomentumEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSpatialMomentumEndEffector& orig
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

   /// gets the error weight
   virtual const EcReal& errorWeight
      (
      ) const;

   /// sets the error weight
   virtual void setErrorWeight
      (
      const EcReal& errorWeight
      );

   /// gets the desired linear momentum
   virtual const EcVector& desiredLinearMomentum
      (
      ) const;

   /// sets the desired linear momentum
   virtual void setDesiredLinearMomentum
      (
      const EcVector& desiredLinearMomentum
      );

   /// gets the desired angular momentum
   virtual const EcVector& desiredAngularMomentum
      (
      ) const;

   /// sets the desired angular momentum
   virtual void setDesiredAngularMomentum
      (
      const EcVector& desiredAngularMomentum
      );

   /// gets the include-angular flag
   virtual const EcBoolean& includeAngular
      (
      ) const;

   /// sets the include-angular flag
   virtual void setIncludeAngular
      (
      const EcBoolean& includeAngular
      );

   /// @copydoc EcEndEffector::doc()
   /// For this end effector, if includeAngular is true, then it returns 6 (linear and angular momentum).
   /// Otherwise, it returns 3 (only linear momentum).
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

   /// For this end effector, it is always the identity. @n
   /// @copydoc EcEndEffector::calculatePlacement
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// For this end effector, it's the momentum. @n
   /// @copydoc EcEndEffector::calculateVelocity
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// For this end effector, it's the time derivative of momentum. @n
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
   static EcSpatialMomentumEndEffector nullObject
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

protected:
   /// the error weight for this end effector
   EcXmlReal             m_ErrorWeight;

   /// the desired linear momentum
   EcXmlVector           m_DesiredLinearMomentum;

   /// the desired angular momentum
   EcXmlVector           m_DesiredAngularMomentum;

   /// a flag indicating whether or not to include angular momentum
   EcXmlBoolean          m_IncludeAngular;

   // non-XML below
   mutable EcMatrixDTool m_MatrixDTool;         ///< the matrix D tool
   mutable EcReArray     m_TransformedMatrixD;  ///< the transformed matrix D
};

/// a vector of point end effectors
typedef EcXmlVectorType<EcSpatialMomentumEndEffector> EcSpatialMomentumEndEffectorVector;

#endif // ecSpatialMomentumEndEffector_H_
