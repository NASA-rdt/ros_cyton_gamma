#ifndef ecArticulatedBodyDynamics_H_
#define ecArticulatedBodyDynamics_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecArticulatedBodyDynamics.h
/// @class EcArticulatedBodyDynamics
/// @brief Holds articulated rigid body mass properties and bias forces.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecArticulatedBodyInertia.h"
#include <foundCommon/ecGeneralForce.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

/// Holds articulated rigid body mass properties and bias forces.
class EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyDynamics : public EcXmlCompoundType
{
public:
   /// default constructor
   EcArticulatedBodyDynamics
      (
      );

   /// constructor with all components
   EcArticulatedBodyDynamics
      (
      const EcArticulatedBodyInertia& inertia,
      const EcGeneralForce&           bias
      );

   /// constructor from rigid-body inertia and a bias
   EcArticulatedBodyDynamics
      (
      const EcRigidBodyMassProperties& rigidBodyInertia,
      const EcGeneralForce&     bias
      );

   /// destructor
   virtual ~EcArticulatedBodyDynamics
      (
      );

   /// copy constructor
   EcArticulatedBodyDynamics
      (
      const EcArticulatedBodyDynamics& orig
      );

   /// assignment operator
   EcArticulatedBodyDynamics& operator=
      (
      const EcArticulatedBodyDynamics& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcArticulatedBodyDynamics& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// add another dynamics properties to this and set this to the result.
   /// the result is the dynamics of a body formed by rigidly connecting
   /// the handle of this articulated body with that of another
   EcArticulatedBodyDynamics& operator+=
      (
      const EcArticulatedBodyDynamics& ad2
      );

   /// subtract another mass properties from this and set this to the result
   /// cancels the effect of +=
   EcArticulatedBodyDynamics& operator-=
      (
      const EcArticulatedBodyDynamics& ad2
      );

   /// add another dynamics properties to this and return the result
   /// the result is the inertia of a body formed by rigidly connecting
   /// the handle of this articulated body with that of another
   EcArticulatedBodyDynamics  operator+
      (
      const EcArticulatedBodyDynamics& ad2
      ) const;

   /// subtract another dynamics properties from this and return the result
   /// cancels the effect of +
   EcArticulatedBodyDynamics  operator-
      (
      const EcArticulatedBodyDynamics& ad2
      ) const;

   /// general transformation.  Returns the transformed entity.
   virtual EcArticulatedBodyDynamics& transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// rotation.  Returns the transformed entity
   virtual EcArticulatedBodyDynamics& transformBy
      (
      const EcOrientation& orientation
      );

   /// offset.  Returns the transformed entity
   /// Note that this takes mass properties represented at the tip of
   /// the transformation vector and expresses it at the origin.
   virtual EcArticulatedBodyDynamics& transformBy
      (
      const EcVector& translation
      );

   /// joins this articlulated body with another through a joint.  This
   /// is changed to represent the inertia that results from joining
   /// this with other through the joint defined by jointUnitAcceleration.
   /**
    * @param other The other articulated-body dynamics to join with this
    * @param jointUnitAcceleration Unit acceleration of the joint joining the two
    * @param effectiveMotorInertia The effective motor inertia of the joint
    * @param inputJointTorque The torque on the joint
    * @return This articulated-body dynamics after the joining process.
    */
   virtual EcArticulatedBodyDynamics& joinWith
      (
      const EcArticulatedBodyDynamics& other,
      const EcGeneralMotion& jointUnitAcceleration,
      const EcReal& effectiveMotorInertia,
      const EcReal& inputJointTorque
      );

   /// set this articlulated body to be another passed through a joint.  This
   /// is changed to represent the inertia that results from passing the
   /// other through the joint defined by jointUnitAcceleration.
   /**
    * @param other The other articulated-body dynamics to transform
    * @param jointUnitAcceleration Unit acceleration of the joint
    * @param effectiveMotorInertia The effective motor inertia of the joint
    * @param inputJointTorque The torque on the joint
    * @return This articulated-body dynamics after the transformation.
    */
   virtual EcArticulatedBodyDynamics& setToTransformedValue
      (
      const EcArticulatedBodyDynamics& other,
      const EcGeneralMotion& jointUnitAcceleration,
      const EcReal& effectiveMotorInertia,
      const EcReal& inputJointTorque
      );

   /// calculates the force on the rigid body needed to produce the velocity and acceleration
   /// (excluding bias due to velocity and external forces)
   virtual EcGeneralForce calculateForce
      (
      const EcGeneralMotion& acc
      ) const;

   /// calculates the acceleration of the rigid body due to the applied general force
   virtual EcGeneralMotion calculateAcceleration
      (
      const EcGeneralForce& genForce
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets inertia
   virtual const EcArticulatedBodyInertia& inertia
      (
      ) const;

   /// sets inertia
   virtual void setInertia
      (
      const EcArticulatedBodyInertia& inertia
      );

   /// sets inertia using rigid body mass properties
   virtual void setInertiaFromRigidBody
      (
      const EcRigidBodyMassProperties& rigidBodyMass
      );

   /// gets the bias force
   virtual const EcGeneralForce& bias
      (
      ) const;

   /// sets the bias force
   virtual void setBias
      (
      const EcGeneralForce& bias
      );

   /// sets general quantities
   virtual void set
      (
      const EcArticulatedBodyInertia& inertia,
      const EcGeneralForce&           bias
      );

   /// sets inertia from an EcReArray
   virtual void setInertiaFromArray
      (
      const EcReArray& array
      );

   /// get inertia as an EcReArray
   virtual void getInertiaArray
      (
      EcReArray& array
      ) const;

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcArticulatedBodyDynamics& sm2,
      EcReal tol
      ) const;

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
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

   /// get an zero second moment
   static EcArticulatedBodyDynamics nullObject
      (
      );

protected:
   /// inertia
   EcArticulatedBodyInertia  m_Inertia;

   /// bias force
   EcGeneralForce            m_Bias;
};

/// an XML vector of mass properties
typedef EcXmlVectorType<EcArticulatedBodyDynamics> EcArticulatedBodyDynamicsVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the second moment in a transformed frame
EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyDynamics transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcArticulatedBodyDynamics& mp
   );

/// expresses the second moment in a rotated frame
EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyDynamics transform
   (
   const EcOrientation& q,
   const EcArticulatedBodyDynamics& mp
   );

/// expresses the second moment in an offset frame
EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyDynamics transform
   (
   const EcVector& off,
   const EcArticulatedBodyDynamics& mp
   );

#endif // ecArticulatedBodyDynamics_H_
