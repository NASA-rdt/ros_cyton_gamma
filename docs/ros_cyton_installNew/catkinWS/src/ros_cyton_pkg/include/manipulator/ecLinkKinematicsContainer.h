#ifndef ecLinkKinematicsContainer_H_
#define ecLinkKinematicsContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkKinematicsContainer.h
/// @class EcLinkKinematicsContainer
/// @brief Holds a container for link-motion description.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeContainer.h>
#include "ecLinkKinematics.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

// forward declarations
class EcArticulatedBodyDynamics;

/** Holds a container for link-motion description.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkKinematicsContainer : public EcBaseExpressionTreeContainer<EcLinkKinematics>
{
public:
   /// default constructor
   EcLinkKinematicsContainer
      (
      );

   /// destructor
   virtual ~EcLinkKinematicsContainer
      (
      );

   /// copy constructor
   EcLinkKinematicsContainer
      (
      const EcLinkKinematicsContainer& orig
      );

   /// assignment operator
   EcLinkKinematicsContainer& operator=
      (
      const EcLinkKinematicsContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkKinematicsContainer& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

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
      );

   /// transform this by a general coordinate system transformation.  This
   /// transformation is inserted before the link placement.  If the
   /// kinematics class has a precursor P, the P=XForm*P;
   virtual EcBoolean transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// return the scale factor for the joint parameter (=1 for
   /// a distance-based parameter, 0 for non-distance-based)
   virtual EcReal jointParameterScalability
      (
      )const;

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

   /// get a null object
   static EcLinkKinematicsContainer nullObject
      (
      );

   /// get Primary Frame
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
   virtual const EcCoordinateSystemTransformation& calculateTransform
      (
      EcReal jointValue
      ) const;

   /// transform an inboard transformation to the link's frame
   /// The output is xform*DH(jointValue).
   virtual void transformBy
      (
      EcCoordinateSystemTransformation& xform,
      EcReal jointValue
      ) const;

   ///  get the general motion of the frame (locally represented).
   virtual const EcGeneralMotion& calculateVelocity
      (
      EcReal jointValue,
      EcReal jointVelocity
      ) const;

   ///  get the general acceleration of the frame (locally represented).
   virtual const EcGeneralAcceleration& calculateAcceleration
      (
      EcReal jointValue,
      EcReal jointVelocity,
      EcReal jointAcceleration
      ) const;

   /// get the torque required to produce a unit acceleration of an
   /// articulated rigid body
   virtual EcReal unitAccelerationTorque
      (
      EcReal jointValue,
      const EcArticulatedBodyInertia& inertia
      ) const;

   /// get the torque required to exert the specified general force
   virtual EcReal torqueRequiredToExert
      (
      EcReal jointValue,
      const EcGeneralForce& exertedGeneralForce
      ) const;

   /// return the unit type of the underlying link kinematics
   virtual EcU32 unitType
      (
      ) const;
protected:
   /// define an identity transformation
   static const EcCoordinateSystemTransformation m_theIdentity;

   /// define a null general motion
   static const EcGeneralMotion m_theNullMotion;
};

#endif // ecLinkKinematicsContainer_H_
