#ifndef ecCollisionDescriptor_H_
#define ecCollisionDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecCollisionDescriptor.h
/// @class EcCollisionDescriptor
/// @brief Contains a class describing a link-link collision
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <foundCommon/ecCoordSysXForm.h>


// forward declarations
class EcShape;
class EcManipulatorLink;

/** Holds a class to describe a collision between two links
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcCollisionDescriptor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcCollisionDescriptor
      (
      );

   /// destructor
   virtual ~EcCollisionDescriptor
      (
      );

   /// copy constructor
   EcCollisionDescriptor
      (
      const EcCollisionDescriptor& orig
      );

   /// assignment operator
   EcCollisionDescriptor& operator=
      (
      const EcCollisionDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCollisionDescriptor& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// set the link pointer of the first link in the collision
   virtual void setLink1Pointer
      (
         const EcManipulatorLink* ptr
      );

   /// get the link pointer of the first link in the collision
   virtual const EcManipulatorLink* link1Pointer
      (
      )const;

   /// set the link pointer of the second link in the collision
   virtual void setLink2Pointer
      (
         const EcManipulatorLink* ptr
      );

   /// get the link pointer of the second link in the collision
   virtual const EcManipulatorLink* link2Pointer
      (
      )const;

   /// set the collision normal vector  REMOVE?
   virtual void setCollisionNormal
      (
         const EcVector& normal
      );

   /// get the collision normal vector REMOVE?
   virtual const EcVector& collisionNormal
      (
      )const;

   /// set the contact point of the collision
   virtual void setContactPointRel1
      (
         const EcVector& contactPt
      );

   /// get the contact point of the collision
   virtual const EcVector& contactPointRel1
      (
      )const;

   /// set the contact point of the collision
   virtual void setContactPointRel2
      (
         const EcVector& contactPt
      );

   /// get the contact point of the collision
   virtual const EcVector& contactPointRel2
      (
      )const;

   /// set the index of the closest point for shape 1
   /// used by GJK to compute the penetration distance
   virtual void setClosestPointIndex1
      (
      const EcU32& ppointIndex
      );

   /// set the index of the closest point for shape 2
   /// used by GJK to compute the penetration distance
   virtual void setClosestPointIndex2
      (
      const EcU32& ppointIndex
      );

   /// return the index of the closest point for shape 1
   /// used by GJK to compute the penetration distance
   virtual const EcU32& closestPointIndex1
      (
      )const;

   /// return the index of the closest point for shape 2
   /// used by GJK to compute the penetration distance
   virtual const EcU32& closestPointIndex2
      (
      )const;

   /// set the shape ID of shape one
   virtual void setShapeOneID
      (
      const EcU32 shapeID
      );

   /// get the shape ID of shape one
   virtual const EcU32& shapeOneID
      (
      )const;

   /// set the shape ID of shape one
   virtual void setShapeTwoID
      (
      const EcU32 shapeID
      );

   /// get the shape ID of shape one
   virtual const EcU32& shapeTwoID
      (
      )const;

   /// set the manipulator ID of link one
   virtual void setManipulatorOneID
      (
      const EcU32 manipulatorID
      );

   /// get the manipulator ID of link one
   virtual const EcU32& manipulatorOneID
      (
      )const;

   /// set the manipulator ID for link one
   virtual void setManipulatorTwoID
      (
      const EcU32 manipulatorID
      );

   /// get the manipulator ID for link one
   virtual const EcU32& manipulatorTwoID
      (
      )const;

   /// set the separation distance
   virtual void setSeparationDistance
      (
         const EcReal& depth
      );

   /// get the separation distance of the collision
   virtual const EcReal& separationDistance
      (
      )const;

   /// get the collision point in system coordinates
   virtual const EcVector& collisionPointSystem
      (
      )const;

   /// set the collision point in system coordinates
   virtual void setCollisionPointSystem
      (
      const EcVector& colPoint
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

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

protected:
   /// pointer to the first link involved in the collision
   const EcManipulatorLink* m_pLink1;

   /// pointer to the second link involved in the collision
   const EcManipulatorLink* m_pLink2;

   /// vector pointing in the direction of the collision normal
   EcVector m_CollisionNormal;

   /// the point of impact in the local DH frame of link1
   EcVector m_CollisionPointRel1;

   /// the point of impact in the local DH frame of link2
   EcVector m_CollisionPointRel2;

   /// the relative velocity between the contact points just before
   /// collision
   EcVector m_RelativeVelocity;

   /// the relative acceleration between the contact points just before
   /// collision
   EcVector m_RelativeAcceleration;

   /// the tangent vector opposing the relative velocity tangent to
   /// the contacting plane
   EcVector m_CollisionTangent;

   /// the separation distance of the two links
   EcReal m_SeparationDistance;

   /// the shape ID of the shape involved in link one's collision
   EcU32 m_Shape1ID;

   /// the shape ID of the shape involved in link two's collision
   EcU32 m_Shape2ID;

   /// the manipulator ID for link one's collision
   EcU32 m_Manipulator1ID;

   /// the manipulator ID for link two's collision
   EcU32 m_Manipulator2ID;

   /// the closest point used by GJK to compute the penetration distance
   /// for shape 1
   EcU32 m_ClosestPoint1;

   /// the closest point used by GJK to compute the penetration distance
   /// for shape 2
   EcU32 m_ClosestPoint2;

   /// the collision point of the collision is system coordinates
   EcVector m_CollisionPointSystem;
};

/// type definition of XML vector of EcCollisionDescriptor
typedef EcXmlVectorType<EcCollisionDescriptor> EcCollisionDescriptorVector;

#endif // ecCollisionDescriptor_H_
