#ifndef ecShapeCollisionEvent_H_
#define ecShapeCollisionEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeCollisionEvent.h
/// @class EcShapeCollisionEvent
/// @brief Class describing a collision between two links.  Where the
///        first link is implied and the second link is stated
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

/// Holds a class to describe a shape query descriptor
class EC_FOUNDATION_GEOMETRY_DECL EcShapeCollisionEvent : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShapeCollisionEvent
      (
      );

   /// destructor
   virtual ~EcShapeCollisionEvent
      (
      );

   /// copy constructor
   EcShapeCollisionEvent
      (
      const EcShapeCollisionEvent& orig
      );

   /// assignment operator
   EcShapeCollisionEvent& operator=
      (
      const EcShapeCollisionEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeCollisionEvent& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// set the collision normal vector
   virtual void setContactDirection
      (
      const EcVector& normal
      );

   /// get the collision normal vector
   virtual const EcVector& contactDirection
      (
      )const;

   /// set the contact point of the collision in the primary frame
   virtual void setContactPoint
      (
      const EcVector& contactPt
      );

   /// get the contact point of the collision in the primary frame
   virtual const EcVector& contactPoint
      (
      )const;

   /// set the penetration depth
   virtual void setPenetrationDepth
      (
      const EcReal& depth
      );

   /// get the penetration depth of the collision
   virtual const EcReal& penetrationDepth
      (
      )const;

   /// set the impacted links manipulator ID
   virtual void setContactManipulatorID
      (
      EcU32 manipID
      );

   /// get the impacted links manipulator ID
   virtual const EcU32& contactManipulatorID
      (
      )const;

   /// set the impacted link ID
   virtual void setContactLinkID
      (
      EcU32 linkID
      );

   /// get the impacted link ID
   virtual const EcU32& contactLinkID
      (
      )const;

   /// set the impacted shape ID
   virtual void setContactShapeID
      (
      EcU32 shapeID
      );

   /// get the impacted shape ID
   virtual const EcU32& contactShapeID
      (
      )const;


   /// set the impacted link force
   virtual void setLinkCollisionForce
      (
      const EcGeneralForce& colForce
      );

   /// get the impacted link force
   virtual const EcGeneralForce& linkCollisionForce
      (
      ) const;


   /// get the closest point index
   virtual const EcU32& closestPointIndexShape1
      (
      )const;


   /// set the closest point index
   virtual void setClosestPointIndexShape1
      (
      const EcU32& pointIndex
      );

   /// get the closest point index s2
   virtual const EcU32& closestPointIndexShape2
      (
      )const;


   /// set the closest point index s2
   virtual void setClosestPointIndexShape2
      (
      const EcU32& pointIndex
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   virtual const EcToken& token
      (
      ) const;

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

protected:

   /// vector pointing in the direction of the collision normal
   EcXmlVector    m_CollisionNormal;

   /// the point of impact in the primary frame of link
   EcXmlVector    m_CollisionPointPrimaryFrame;

   /// the translational and rotational force on the link in the primary frame
   EcGeneralForce m_LinkCollisionForce;

   /// the depth of penetration of the two links
   EcXmlReal      m_PenetrationDepth;

   /// the ID of the impacted link
   EcXmlU32       m_ImpactedLinkID;

   /// the ID of the impacted manipulator
   EcXmlU32       m_ImpactedManipulatorID;

   /// the ID of the impacted shape
   EcXmlU32       m_ImpactedShapeID;

   /// the index of the closest point in the polyhedron to the collision used by GJK
   EcXmlU32       m_ClosestPointIndexShape1;

   /// the index of the closest point in the polyhedron to the collision used by GJK
   EcXmlU32       m_ClosestPointIndexShape2;
};

/// A vector of EcShapeCollisionEvent
typedef std::vector<EcShapeCollisionEvent> EcActiveCollisionStateVector;

/// An array of EcShapeCollisionEvent
typedef std::vector<
        std::vector<
        std::vector<
        std::vector<EcShapeCollisionEvent> > > > EcActiveCollisionStateArray;

#endif // ecShapeCollisionEvent_H_
