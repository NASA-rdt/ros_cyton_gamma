#ifndef ecLinkKinematics_H_
#define ecLinkKinematics_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkKinematics.h
/// @class EcLinkKinematics
/// @brief Holds a description of a base class for link motion.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeElement.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecGeneralMotion.h>

// forward declarations
class EcArticulatedBodyDynamics;
class EcArticulatedBodyInertia;
class EcGeneralForce;
class EcJointActuator;

/// Holds a description of a base class for link motion. It supports general joint types with one degree of freedom.
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkKinematics : public EcBaseExpressionTreeElement
{
public:
   /// unit type enumeration
   enum {LINEAR, ANGULAR, OTHER};

   /// default constructor - should not be used
   EcLinkKinematics
      (
      );

   /// destructor
   virtual ~EcLinkKinematics
      (
      );

   /// copy constructor
   EcLinkKinematics
      (
      const EcLinkKinematics& orig
      );

   /// assignment operator
   EcLinkKinematics& operator=
      (
      const EcLinkKinematics& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkKinematics& orig
      ) const;

   /// register components in this class
   virtual void registerComponents
      (
      );

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcLinkKinematics& dh2,
      EcReal tol
      ) const;

   /// kinematics functions

   /// get Primary Frame, which is the primary frame for the link represented in the link's DH frame
   /**
   \return The primary frame for this link. This frame is used to specify physical extent, mass properties, and end effectors.
   */
   virtual const EcCoordinateSystemTransformation& primaryFrame
      (
      ) const;

   /// get Primary Frame Inverse
   virtual const EcCoordinateSystemTransformation& primaryFrameInverse
      (
      ) const;

   /// set Primary Frame
   virtual void setPrimaryFrame
      (
      const EcCoordinateSystemTransformation& value
      );

   /// calculate transformation
   /**
   \param[in] jointValue The joint value used to calculate the link transformation.
   \return The link transformation at jointValue.
   */
   virtual const EcCoordinateSystemTransformation& calculateTransform
      (
      EcReal jointValue
      ) const=0;

   /// transform an inboard transformation to the link's frame
   /**
   \param[in,out] xform The output transformation which is xform*calculateTransform(jointValue).
   \param[in] jointValue The joint value used to calculate the transformation.
   */
   virtual void transformBy
      (
      EcCoordinateSystemTransformation& xform,
      EcReal jointValue
      ) const=0;

   ///  get the general motion of the frame (locally represented).
   /**
   The default frame velocity calculation. The velocity is the relative speed of the current frame to the parent frame represented in the current frame.  The default method will do a differentiation of the transformation, which is not as accurate if the close form solution of the frame velocity can be implemented in the child class.
   \param[in] jointValue The joint value.
   \param[in] jointVelocity The joint velocity.
   */
   virtual const EcGeneralMotion& calculateVelocity
      (
      EcReal jointValue,
      EcReal jointVelocity
      ) const;

   ///  get the general acceleration of the frame (locally represented).
   /**
   The default frame velocity calculation. The acceleration is the relative acceleration of the current frame to the parent frame represented in the current frame.  The default method will do a differentiation of the velocity, which is not as accurate if the close form solution of the frame acceleration can be implemented in the child class.
   \param[in] jointValue The joint value.
   \param[in] jointVelocity The joint velocity.
   \param[in] jointAcceleration The joint acceleration.
   */
   virtual const EcGeneralAcceleration& calculateAcceleration
      (
      EcReal jointValue,
      EcReal jointVelocity,
      EcReal jointAcceleration
      ) const;

   /// get the torque required to produce a unit acceleration of an
   /// articulated rigid body
   /**
   \param[in] jointValue The joint value.
   \param[in] inertia The articulated body inertia attached to the link.
   \return The torque required to produce a unit acceleration.
   */
   virtual EcReal unitAccelerationTorque
      (
      EcReal jointValue,
      const EcArticulatedBodyInertia& inertia
      ) const;

   /// get the torque required to exert the specified general force
   /**
   \param[in] jointValue The joint value.
   \param[in] exertedGeneralForce The desired general force.
   \return The torque required to exert the desired force.
   */
   virtual EcReal torqueRequiredToExert
      (
      EcReal jointValue,
      const EcGeneralForce& exertedGeneralForce
      ) const;

   /// compute an upper-bound distance between this DH
   /// and the parent
   virtual EcReal upperBoundDhFrameDistance
      (
      const EcJointActuator& jointActuator
      )const=0;

   /// add child arbd to parent's arbd
   virtual EcBoolean addChildArbdToParent
      (
      EcArticulatedBodyDynamics& parentArbd,
      const EcArticulatedBodyDynamics& childArbd,
      const EcReal jointValue,
      const EcReal jointTorque,
      const EcReal effectiveMotorInertia
      ) const;

   /// scale the kinematics by the specified distance-scale value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleBy
      (
      EcReal scaleFactor
      )=0;

   /// transform this by a general coordinate system transformation.  This
   /// transformation is inserted before the link placement.  If the
   /// kinematics class has a precursor P, the P=XForm*P;
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      )=0;

   /// return the scale factor for the joint parameter (=1 for
   /// a distance-based parameter, 0 for non-distance-based)
   virtual EcReal jointParameterScalability
      (
      )const=0;

   /// change the inboard frame by an offset. This is to account for uncertainty in link measurements, both linear and angular. If offset is identity, then this does nothing.
   virtual void changeInboardFrameBy
      (
      const EcCoordinateSystemTransformation& offset
      )=0;

   /// return the unit type of the link kinematics (joint).
   virtual EcU32 unitType
      (
      ) const=0;

protected:

   /// the primary frame for the link represented in the link's DH frame
   EcCoordinateSystemTransformation m_PrimaryFrame;

   /// non-XML data below

   /// the inverse of the primary frame for the link represented in the link's DH frame
   /// this is stored for easy access
   EcCoordinateSystemTransformation m_PrimaryFrameInverse;

   /// a value for the transformation
   mutable EcCoordinateSystemTransformation m_FrameTransform;

   /// a value for the frame velocity
   mutable EcGeneralMotion m_FrameVelocity;

   /// a value for the frame Acceleration
   mutable EcGeneralAcceleration m_FrameAcceleration;

   // temporary variables for speed
   mutable EcGeneralMotion m_GMotion0;    ///< First utility EcGeneralMotion
   mutable EcGeneralMotion m_GMotion1;    ///< Second utility EcGeneralMotion
   mutable EcGeneralMotion m_GMotion2;    ///< Third utility EcGeneralMotion
   mutable EcCoordinateSystemTransformation m_XForm0; ///< First utility EcCoordinateSystemTransformation
   mutable EcCoordinateSystemTransformation m_XForm1; ///< Second utility EcCoordinateSystemTransformation
};

#endif // ecLinkKinematics_H_
