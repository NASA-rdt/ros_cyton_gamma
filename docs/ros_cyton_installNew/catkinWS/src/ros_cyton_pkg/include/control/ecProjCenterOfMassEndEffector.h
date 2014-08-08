#ifndef EcProjectedCenterOfMassEndEffector_H_
#define EcProjectedCenterOfMassEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecProjCenterOfMassEndEffector.h
/// @class EcProjectedCenterOfMassEndEffector
/// @brief A projected (2D) center-of-mass constraint.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPointBasedEndEffector.h"
#include <xml/ecXmlOrientation.h>

/// A 2D center-of-mass constraint, i.e. the 3D center of mass projected on to a virtual plane.
class EC_ACTIN_CONTROL_DECL EcProjectedCenterOfMassEndEffector : public EcPointBasedEndEffector
{
public:
   /// default constructor
   EcProjectedCenterOfMassEndEffector
      (
      );

   /// destructor
   virtual ~EcProjectedCenterOfMassEndEffector
      (
      );

   /// copy constructor
   EcProjectedCenterOfMassEndEffector
      (
      const EcProjectedCenterOfMassEndEffector& orig
      );

   /// assignment operator
   EcProjectedCenterOfMassEndEffector& operator=
      (
      const EcProjectedCenterOfMassEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcProjectedCenterOfMassEndEffector& orig
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

   /// gets the xy orientation
   virtual const EcOrientation& xyOrientation
      (
      ) const;
   /// sets the xy orientation
   virtual void setXyOrientation
      (
      const EcOrientation& xyOrientation
      );

   /// gets the projection flag (true to use system vector)
   virtual EcBoolean projectAlongSystemVector
      (
      ) const;

   /// sets the projection flag (true to use system vector)
   virtual void setProjectAlongSystemVector
      (
      EcBoolean projectAlongSystemVector
      );

   /// gets the system vector
   virtual const EcVector& systemVector
      (
      ) const;

   /// sets the system vector
   virtual void setSystemVector
      (
      const EcVector& systemVector
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
   /// For this end effector, it returns 2.
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

   /// calculate a 2D vector placement value for the center of mass
   virtual void calculate2DPointPlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcPlanarVector& xyPlacement
      ) const;

   /// calculate a 3D vector placement value for the center of mass
   virtual void calculatePointPlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcVector& pointPlacement
      ) const;

   /// For this end effector, it's the placement value for the center of mass. @n
   /// @copydoc EcEndEffector::calculatePlacement
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// For this end effector, it's the center-of-mass velocity. @n
   /// @copydoc EcEndEffector::calculateVelocity
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// For this end effector, it's the center-of-mass acceleration. However, it's currently NOT implemented. @n
   /// @copydoc EcEndEffector::calculateAcceleration
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex=0
      ) const;

   /// calculate an end-effector velocity that drives the end
   /// effector toward the guide placement.  This is done
   /// in the plane of the end effector.
   virtual void filter2DPointEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcCoordinateSystemTransformation& guide,
      const EcPlanarVector& inputPointVelocity,
      const EcPlanarVector& lastPointVelocity,
      EcReal timeStep,
      EcManipulatorActiveState&  activeState,
      EcPlanarVector& filteredPointVelocity
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
   static EcProjectedCenterOfMassEndEffector nullObject
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

protected:
   /// calculate the velocity of the center of mass in the link's
   /// kinematic frame due to unit joint motion of the inboard link.
   virtual EcVector firstMomentRate
      (
      const EcManipulatorLink& link,
      EcManipulatorActiveState& activeState
      ) const;

   /// update working xy-frame orientation
   virtual void updateWorkingXyOrientation
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      const EcEndEffectorRelativeLinkData& relativeLinkData
      ) const;

   /// access to the working xy orientation
   virtual const EcOrientation& workingXyOrientation
      (
      ) const;


protected:

   /// the orientation of frame for the xy frame of projection
   EcXmlOrientation      m_XyOrientation;

   /// a flag indicating to project along a system vector (rather than z-axis of xy-frame)
   EcXmlBoolean          m_ProjectAlongSystemVector;

   /// the system vector for projection (if flagged)
   EcXmlVector           m_SystemVector;

   /// the error weight for this end effector
   EcXmlReal             m_ErrorWeight;

   /// non-XML below

   /// a working xy-orientation frame (equal to the xml value for z-projection, different for gravity projection)
   mutable EcOrientation         m_WorkingXyOrientation;

   /// a threshold for determining whether or not to use inverse trig
   static const EcReal           m_theCosThreshold;
};

/// a vector of point end effectors
typedef EcXmlVectorType<EcProjectedCenterOfMassEndEffector> EcProjectedCenterOfMassEndEffectorVector;

#endif // EcProjectedCenterOfMassEndEffector_H_
