#ifndef ecDissipativeForceInput_H_
#define ecDissipativeForceInput_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDissipativeForceInput.h
/// @class EcDissipativeForceInput
/// @brief Holds a class to convey information to the dissipative
///        force processor.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecGeneralForce.h>
#include <foundCommon/ecGeneralMotion.h>

class EcManipulatorLink;

/// Holds a class to convey information to the dissipative force processor.
class EC_FOUNDATION_MANIPULATOR_DECL EcDissipativeForceInput : public EcXmlCompoundType
{
public:
   /// default constructor
   EcDissipativeForceInput
      (
      );

   /// destructor
   virtual ~EcDissipativeForceInput
      (
      );

   /// copy constructor
   EcDissipativeForceInput
      (
      const EcDissipativeForceInput& orig
      );

   /// assignment operator
   EcDissipativeForceInput& operator=
      (
      const EcDissipativeForceInput& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDissipativeForceInput& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone
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

   /// get body 1's material type
   virtual const EcString& body1MaterialType
      (
      )const;

   /// set body 1's material type
   virtual void setBody1MaterialType
      (
      const EcString& type
      );

   /// get body 2's material type
   virtual const EcString& body2MaterialType
      (
      )const;

   /// set body 2's material type
   virtual void setBody2MaterialType
      (
      const EcString& type
      );

   /// get body 1's current velocity in the system coordinates
   virtual const EcGeneralVelocity& body1Velocity
      (
      )const;

   /// set body 1's current velocity in the system coordinates
   virtual void setBody1Velocity
      (
      const EcGeneralVelocity& vel
      );

   /// get body 2's current velocity in the system coordinates
   virtual const EcGeneralVelocity& body2Velocity
      (
      )const;

   /// set body 2's current velocity in the system coordinates
   virtual void setBody2Velocity
      (
      const EcGeneralVelocity& vel
      );

   /// get body 1's last velocity in the system coordinates
   virtual const EcGeneralVelocity& lastBody1Velocity
      (
      )const;

   /// set body 1's last velocity in the system coordinates
   virtual void setLastBody1Velocity
      (
      const EcGeneralVelocity& vel
      );

   /// get body 2's last velocity in the system coordinates
   virtual const EcGeneralVelocity& lastBody2Velocity
      (
      )const;

   /// set body 2's last velocity in the system coordinates
   virtual void setLastBody2Velocity
      (
      const EcGeneralVelocity& vel
      );

   /// get normal force in system coordinates
   virtual const EcVector& normalForceInSystem
      (
      )const;

   /// set normal force in system coordinates
   virtual void setNormalForceInSystem
      (
      const EcVector& force
      );

   /// get collision normal, out of body 2, into 1
   virtual const EcVector& collisionNormalInSystem
      (
      )const;

   /// set collision normal, out of body 2, into 1
   virtual void setCollisionNormalInSystem
      (
      const EcVector& collisionNormalInSystem
      );

   /// get collision point in primary frame 2 coordinates
   virtual const EcVector& currentCollisionPointInPrimary2
      (
      )const;

   /// set collision point in system coordinates
   virtual void setCurrentCollisionPointInPrimary2
      (
      const EcVector& cp
      );

   /// get the object 1 primary frame
   virtual const EcCoordinateSystemTransformation& primaryFrame1InSystem
      (
      )const;

   /// set the object 1 primary frame
   virtual void setPrimaryFrame1InSystem
      (
      const EcCoordinateSystemTransformation& primaryFrame1InSystem
      );

   /// get the object 2 primary frame
   virtual const EcCoordinateSystemTransformation& primaryFrame2InSystem
      (
      )const;

   /// set the object 2 primary frame
   virtual void setPrimaryFrame2InSystem
      (
      const EcCoordinateSystemTransformation& primaryFrame2InSystem
      );

   /// get the mode flag
   virtual EcBoolean inStaticFrictionMode
      (
      )const;

   /// set the mode flag
   virtual void setInStaticFrictionMode
      (
      EcBoolean inStaticFrictionMode
      );

   /// get the static start collision point for object 1
   virtual const EcVector& staticStartCollisionPointInPrimary1
      (
      )const;

   /// set the static start collision point for object 1
   virtual void setStaticStartCollisionPointInPrimary1
      (
      const EcVector& staticStartCollisionPointInPrimary1
      );

   /// get the static start collision point for object 2
   virtual const EcVector& staticStartCollisionPointInPrimary2
      (
      )const;

   /// set the static start collision point for object 2
   virtual void setStaticStartCollisionPointInPrimary2
      (
      const EcVector& staticStartCollisionPointInPrimary2
      );

   /// get the object 1 primary frame
   virtual const EcCoordinateSystemTransformation& staticStartPrimaryFrame1InSystem
      (
      )const;

   /// set the object 1 primary frame
   virtual void setStaticStartPrimaryFrame1InSystem
      (
      const EcCoordinateSystemTransformation& staticStartPrimaryFrame1InSystem
      );

   /// get the object 2 primary frame
   virtual const EcCoordinateSystemTransformation& staticStartPrimaryFrame2InSystem
      (
      )const;

   /// set the object 2 primary frame
   virtual void setStaticStartPrimaryFrame2InSystem
      (
      const EcCoordinateSystemTransformation& primaryFrame2InSystem
      );

   /// get the estimated action radius of the collision region
   virtual EcReal actionRadius
      (
      )const;

   /// set the estimated action radius of the collision region
   virtual void setActionRadius
      (
      EcReal actionRadius
      );

   /// get the linear inertia along the collision normal
   virtual EcReal linearInertiaAlongNormal
      (
      )const;

   /// set the linear inertia along the collision normal
   virtual void setLinearInertiaAlongNormal
      (
      EcReal linearInertiaAlongNormal
      );

   /// get the angular inertia about the collision normal
   virtual EcReal angularInertiaAboutNormal
      (
      )const;

   /// set the angular inertia about the collision normal
   virtual void setAngularInertiaAboutNormal
      (
      EcReal angularInertiaAboutNormal
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

protected:
   /// material type of body 1
   const EcString* m_pBody1MaterialType;

   /// material type of body 2
   const EcString* m_pBody2MaterialType;

   /// current velocity of body1
   EcGeneralVelocity m_Body1Velocity;

   /// current velocity of body2
   EcGeneralVelocity m_Body2Velocity;

   /// last velocity of body1
   EcGeneralVelocity m_LastBody1Velocity;

   /// last velocity of body2
   EcGeneralVelocity m_LastBody2Velocity;

   /// normal force applied in system coordinates
   EcVector m_NormalForceInSystem;

   /// normal unit vector
   EcVector m_CollisionNormalInSystem;

   /// the collision point in system coordinates
   EcVector m_CurrentCollisionPointInPrimary2;

   /// the body 1 primary frame in system coordinates
   EcCoordinateSystemTransformation m_PrimaryFrame1InSystem;

   /// the body 1 primary frame in system coordinates
   EcCoordinateSystemTransformation m_PrimaryFrame2InSystem;

   /// the body 1 static start primary frame in system coordinates
   EcCoordinateSystemTransformation m_StaticStartPrimaryFrame1InSystem;

   /// the body 2 static start primary frame in system coordinates
   EcCoordinateSystemTransformation m_StaticStartPrimaryFrame2InSystem;

   /// friction mode flag
   EcXmlBoolean m_InStaticFrictionMode;

   /// the colision point in object 1 coordinates at static-mode start
   EcVector m_StaticStartCollisionPointInPrimary1;

   /// the colision point in object 2 coordinates at static-mode start
   EcVector m_StaticStartCollisionPointInPrimary2;

   /// the estimated action radius of the collision region
   EcXmlReal m_ActionRadius;

   /// the estimated linear inertia along the impact normal
   EcXmlReal m_LinearInertiaAlongNormal;

   /// the estimated angular inertia about the impact normal
   EcXmlReal m_AngularInertiaAboutNormal;

   /// constants

   /// default material type
   static const EcString m_theNullMaterialType;
};

#endif // ecDissipativeForceInput_H_
