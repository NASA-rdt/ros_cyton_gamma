#ifndef ecDh_H_
#define ecDh_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecDh.h
/// @class EcDenavitHartenberg
/// @brief Denavit Hartenberg Parameters. (A Description of the
///        link-to-link kinematic relationship in standard
///        robotics notation.)
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkKinematics.h"
#include <foundCore/ecAngle.h>

/// A class to describe the Denavit-Hartenberg link parameters.
/** It also includes a representaion of a primary frame for the link.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcDenavitHartenberg : public EcLinkKinematics
{
public:
   /// joint type enumeration
   enum {ROTATIONAL, PRISMATIC};

   /// register joint type enumeration
   virtual void   registerJointTypeEnumerations
      (
      );

   /// D-H type enumeration
   enum {PAUL, GEN_PAUL, CRAIG, GEN_CRAIG, GENERAL};

   /// register D-H type enumerations
   virtual void   registerDhTypeEnumerations
      (
      );

   /// default constructor
   EcDenavitHartenberg
      (
      );

   /// destructor
   virtual ~EcDenavitHartenberg
      (
      );

   /// copy constructor
   EcDenavitHartenberg
      (
      const EcDenavitHartenberg& orig
      );

   /// assignment operator
   EcDenavitHartenberg& operator=
      (
      const EcDenavitHartenberg& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDenavitHartenberg& orig
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

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
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

   /// get joint type
   virtual EcU32 jointType
      (
      ) const;

   /// set joint type
   virtual void setJointType
      (
      EcU32 value
      );

   /// get D-H type
   virtual EcU32 dhType
      (
      ) const;

   /// set D-H type
   virtual void setDhType
      (
      EcU32 value
      );

   /// get Precursor
   virtual const EcCoordinateSystemTransformation& precursor
      (
      ) const;

   /// set Precursor
   virtual void setPrecursor
      (
      const EcCoordinateSystemTransformation& value
      );

   /// get Theta
   virtual const EcAngle& dhTheta
      (
      ) const;

   /// set Theta
   virtual void setDhTheta
      (
      const EcAngle& value
      );

   /// get D
   virtual EcReal dhD
      (
      ) const;

   /// set D
   virtual void setDhD
      (
      EcReal value
      );

   /// get A
   virtual EcReal dhA
      (
      ) const;

   /// set A
   virtual void setDhA
      (
      EcReal value
      );

   /// get Alpha
   virtual const EcAngle& dhAlpha
      (
      ) const;

   /// set Alpha
   virtual void setDhAlpha
      (
      const EcAngle& value
      );

   /// calculate D-H transformation
   /**
   \param[in] jointValue The joint value used to calculate the DH transformation.
   \return The DH transformation at jointValue.
   */
   virtual const EcCoordinateSystemTransformation& calculateTransform
      (
      EcReal jointValue
      ) const;

   /// transform an inboard transformation to the link's DH frame
   /// The output is xform*DH(jointValue).
   /**
   \param[in,out] xform The output transformation which is xform*DH(jointValue).
   \param[in] jointValue The joint value used to calculate the DH transformation.
   */
   virtual void transformBy
      (
      EcCoordinateSystemTransformation& xform,
      EcReal jointValue
      ) const;

   /// get the general motion of the DH frame due to unit joint motion
   /// this motion is locally represented.
   virtual void getUnitFrameMotion
      (
      EcGeneralMotion& frameVelocity,
      EcReal jointValue
      ) const;

   /// get the frame velocity of the DH frame, relative to
   /// the parent, that is produced by the specified joint velocity.
   /// The answer is locally represented.
   virtual const EcGeneralMotion& calculateVelocity
      (
      EcReal jointValue,
      EcReal jointVelocity
      ) const;

   /// get the acceleration in the DH frame, w.r.t. the parent frame,
   /// represented locally.
   /// Note that the velocity calculated from calculateVelocity is w.r.t.
   /// the local frame.  Therefor the derivative of that is not the answer
   /// here.  The transformation (only the orientation part) from current
   /// frame to the parent frame needs to be applied to the velocity first,
   /// followed by time derivative, then convert back to the current frame.
   virtual const EcGeneralAcceleration& calculateAcceleration
      (
      EcReal jointValue,
      EcReal jointVelocity,
      EcReal jointAcceleration
      ) const;


   /// get the acceleration in the DH frame due to the specified
   /// joint velocity.  parentAngularVelocity is the angular velocity
   /// of the inbord frame expressed in the link's DH frame.
   /// linearAccNoJointVel and angularAccNoJointVel are the accelerations
   /// in the D-H frame if there were no joint velcity.  frameAcceleration
   /// is the returned value.
   virtual void accelerationFromJointVelocity
      (
      EcReal jointVelocity,
      const EcVector& parentAngularVelocity,
      const EcVector& linearAccNoJointVel,
      const EcVector& angularAccNoJointVel,
      EcGeneralAcceleration& frameAcceleration
      ) const;

   using EcLinkKinematics::approxEq;
   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcDenavitHartenberg& dh2,
      EcReal tol
      ) const;

   /// computes the upper-bound DH frame distance for this joint
   virtual EcReal upperBoundDhFrameDistance
      (
      const EcJointActuator& jointActuator
      )const;

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
   /// (scaleFactor=1.0 does not change the kinematics)
   virtual void scaleBy
      (
      EcReal scaleFactor
      );

   /// transform this by a general coordinate system transformation.  This
   /// transformation is inserted before the link placement.  For
   /// precursor P, this gives P=XForm*P;
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// return the scale factor for the joint parameter (=1 for
   /// a distance-based parameter, 0 for non-distance-based)
   virtual EcReal jointParameterScalability
      (
      )const;

   /// change the inboard frame by an offset. This is to account for uncertainty in link measurements, both linear and angular. If offset is identity, then this does nothing.
   virtual void changeInboardFrameBy
      (
      const EcCoordinateSystemTransformation& offset
      );

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

   /// \copydoc EcLinkKinematics::unitType
   virtual EcU32 unitType
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// get an zero offset
   static EcDenavitHartenberg nullObject
      (
      );

   /// create an object with default values
   static EcDenavitHartenberg defaultObject
      (
      );

protected:

   /// the joint type - rotational or prismatic
   EcXmlEnumU32                     m_JointType;

   /// the D-H type
   EcXmlEnumU32                     m_DhType;

   /// the precursory transformation
   EcCoordinateSystemTransformation m_Precursor;

   /// the Denavit-Hartenberg theta parameter
   EcXmlAngle                       m_DhTheta;

   /// the Denavit-Hartenberg d parameter
   EcXmlReal                        m_DhD;

   /// the Denavit-Hartenberg a parameter
   EcXmlReal                        m_DhA;

   /// the Denavit-Hartenberg alpha parameter
   EcXmlAngle                       m_DhAlpha;

   /// the sine of alpha
   EcReal                           m_SinAlpha;

   /// the cosine of alpha
   EcReal                           m_CosAlpha;

   /// the joint value for the stored D-H transformation;
   mutable EcReal m_JointValueForStoredTransform;

   /// a validity flag for the transformation
   mutable EcBoolean m_StoredDhTransformValid;
};

/// an XML vector of DH parameters
typedef EcXmlVectorType<EcDenavitHartenberg> EcDenavitHartenbergVector;

#endif // ecDh_H_
