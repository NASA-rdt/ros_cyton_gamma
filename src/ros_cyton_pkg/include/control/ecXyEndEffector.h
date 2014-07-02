#ifndef ecXyEndEffector_H_
#define ecXyEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecXyEndEffector.h
/// @class EcXyEndEffector
/// @brief Holds a base class for a 2D point end-effector component.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPointBasedEndEffector.h"
#include <xml/ecXmlOrientation.h>

/** Holds a base class for a 2D point end-effector component. The point is constrained in X and Y,
 * but free in Z.  The frame specifying X, Y, and Z is defined through the class member
 * m_XyOrientation, which is a transformation that right-multiplies the system frame nominally,
 * or the link frame when the end effector is relative.
*/
class EC_ACTIN_CONTROL_DECL EcXyEndEffector : public EcPointBasedEndEffector
{
public:
   /// default constructor
   EcXyEndEffector
      (
      );

   /// destructor
   virtual ~EcXyEndEffector
      (
      );

   /// copy constructor
   EcXyEndEffector
      (
      const EcXyEndEffector& orig
      );

   /// assignment operator
   EcXyEndEffector& operator=
      (
      const EcXyEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXyEndEffector& orig
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

   /// gets the point
   virtual const EcVector& point
      (
      ) const;
   /// sets the point
   virtual void setPoint
      (
      const EcVector& point
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

   /// @copydoc EcEndEffector::
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const;

   /// calculate a vector placement value for the end effector
   virtual void calculate2DPointPlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcPlanarVector& xyPlacement
      ) const;

   /// For this type of end effector, only the x and y values in
   /// translation have meaning. @n
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
   static EcXyEndEffector nullObject
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

   /// @copydoc EcEndEffector::calculateEndEffectorError()
   virtual void calculateEndEffectorError
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& goal,
      EcManipulatorActiveState&  activeState,
      EcXmlRealVector& differential
      ) const;

protected:
   /// return either the local point or total pint depending on whether external offset is used
   const EcVector pointOffset
      (
      ) const;

   /// the point describing the location end effector
   EcXmlVector           m_Point;

   /// the orientation of frame for xy control (in system coordinates)
   EcXmlOrientation      m_XyOrientation;

   /// the error weight for this end effector
   EcXmlReal             m_ErrorWeight;
};

#endif // ecXyEndEffector_H_
