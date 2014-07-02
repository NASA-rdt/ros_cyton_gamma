#ifndef EcXyStateEqualityConstraint_H_
#define EcXyStateEqualityConstraint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecXyStateEqualityConstraint.h
/// @class EcXyStateEqualityConstraint
/// @brief A 2D point state constraint.
//
//------------------------------------------------------------------------------

#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStateEqualityConstraint.h"
#include <xml/ecXmlVector.h>
#include <xml/ecXmlBasicType.h>

// forward declarations
class EcManipulatorLink;
class EcManipulatorActivePositionState;

/// A 2D point state constraint.
class EC_FOUNDATION_MANIPULATOR_DECL EcXyStateEqualityConstraint : public EcBaseStateEqualityConstraint
{
public:
   /// default constructor
   EcXyStateEqualityConstraint
      (
      );

   /// destructor
   virtual ~EcXyStateEqualityConstraint
      (
      );

   /// copy constructor
   EcXyStateEqualityConstraint
      (
      const EcXyStateEqualityConstraint& orig
      );

   /// assignment operator
   EcXyStateEqualityConstraint& operator=
      (
      const EcXyStateEqualityConstraint& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXyStateEqualityConstraint& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get first link label
   virtual const EcXmlString& firstLinkLabel
      (
      ) const;

   /// set first link label
   virtual void setFirstLinkLabel
      (
      const EcXmlString& firstLinkLabel
      );

   /// get second link label
   virtual const EcXmlString& secondLinkLabel
      (
      ) const;

   /// set second link label
   virtual void setSecondLinkLabel
      (
      const EcXmlString& secondLinkLabel
      );

   /// get first link point
   virtual const EcXmlVector& firstLinkPoint
      (
      ) const;

   /// set first link point
   virtual void setFirstLinkPoint
      (
      const EcXmlVector& firstLinkPoint
      );

   /// get second link point
   virtual const EcXmlVector& secondLinkPoint
      (
      ) const;

   /// set second link point
   virtual void setSecondLinkPoint
      (
      const EcXmlVector& secondLinkPoint
      );

   /// gets the xy orientation. XY orientation is the orientation represented in a reference frame that will allow the constraint to be on the XY plane.
   /// If both first and second links are valid, the reference frame is the second link's primary frame.
   /// If first or second link is invalid and the manipulator has a floating base, the reference frame is the system frame.
   virtual const EcOrientation& xyOrientation
      (
      ) const;

   /// sets the xy orientation
   virtual void setXyOrientation
      (
      const EcOrientation& xyOrientation
      );

   /// return the degrees of constraint
   virtual EcU32 doc
      (
      ) const;

   /// restrain the position state
   virtual EcBoolean constrainPosition
      (
      const EcIndividualManipulator& manipulator,
      EcPositionState& positionState
      ) const;

   /// restrain the velocity state
   virtual EcBoolean constrainVelocity
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      EcVelocityState& velocityState
      ) const;

   /// restrain the velocity state
   virtual EcBoolean constrainAcceleration
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState,
      EcAccelerationState& accelerationState
      ) const;

   /// returns the jacobian of the function.
   /**
   The columnsize of the returned Jacobian should be the number of joints for fixed-based manipulators and the number of joints + 6
   for floating-based manipulators. For floating-base manipulators, the 6-element component that represents the mobile base
   should be prepended to the joint component, with the first three corresponding to linear motion and the last three to angular motion.
   The row size should be the degrees of constraint.
   */
   virtual const EcReArray& jacobian
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& state
      ) const;

   /// returns the jacobian time derivative of the function.
   /**
   The column size of the returned Jacobian time derivative should be the number of joints for fixed-based manipulators and the number of joints + 6
   for floating-based manipulators. For floating-base manipulators, the 6-element component that represents the mobile base
   should be prepended to the joint component, with the first three corresponding to linear motion and the last three to angular motion.
   The row size should be the degrees of constraint.
   */
   virtual const EcReArray& jacobianDerivative
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& state,
      const EcVelocityState& velState
      ) const;

   /// get a null object
   static EcXyStateEqualityConstraint nullObject
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

   /// calculate the general velocity of a frame in the outboard link's
   /// primary frame due to unit joint motion of the inboard link.
   /// (i.e., 1 m/s or 1 rad/s)
   virtual void getFrameMotion
      (
      const EcManipulatorLink& inboardLink,
      const EcManipulatorLink& outboardLink,
      const EcCoordinateSystemTransformation& frame,
      EcManipulatorActivePositionState& activePositionState,
      EcGeneralVelocity& frameMotion
      ) const;

   /// calculate the location of a point in system coordinates.  The
   /// input point vector is represented in link coordinates
   virtual EcVector pointPosition
      (
      const EcManipulatorLink& link,
      const EcVector& point,
      EcManipulatorActivePositionState& activePositionState
      ) const;

   /// calculate the Jacobian if floating base for a given link and point in the link
   virtual void calculateFloatingBaseJacobian
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorLink& link,
      const EcVector& point,
      EcManipulatorActivePositionState& activePositionState
      ) const;

protected:
   // the xy constraint parameters
   EcXmlString                         m_FirstLinkLabel;    ///< The label of the first link 
   EcXmlString                         m_SecondLinkLabel;   ///< The label of the second link 
   EcXmlVector                         m_FirstLinkPoint;    ///< The point on the first link relative to its primary frame
   EcXmlVector                         m_SecondLinkPoint;   ///< The point on the second link relative to its primary frame

   /// the orientation of frame for xy constraint
   EcXmlOrientation                    m_XyOrientation;

};

#endif // EcXyStateEqualityConstraint_H_
