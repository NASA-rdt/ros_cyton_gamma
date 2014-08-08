#ifndef ecShapeQueryResult_H_
#define ecShapeQueryResult_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeQueryResult.h
/// @class EcShapeQueryResult
/// @brief Class to describe the results of a shape query
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorVector.h>

/// Holds a class to describe a shape query result
class EC_FOUNDATION_GEOMETRY_DECL EcShapeQueryResult : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShapeQueryResult
      (
      );

   /// destructor
   virtual ~EcShapeQueryResult
      (
      );

   /// copy constructor
   EcShapeQueryResult
      (
      const EcShapeQueryResult& orig
      );

   /// assignment operator
   EcShapeQueryResult& operator=
      (
      const EcShapeQueryResult& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeQueryResult& orig
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

   /// the distance to the object
   virtual EcReal distance
      (
      ) const;

   /// the intersection volume
   virtual EcReal intersectionVolume
      (
      ) const;

   /// set the distance to the object
   virtual void setDistance
      (
      const EcReal& dist
      );

   /// set the intersection volume
   virtual void setIntersectionVolume
      (
      const EcReal& vol
      );

   /// set the intersection points
   virtual void setIntersectionPoints
      (
      const EcXmlVectorVector points
      );

   /// sets a boolean indicating whether or not a collision occured
   virtual void setCollisionOccurred
      (
      EcBoolean col
      );

   /// returns a boolean indicating whether or not a collision occured
   virtual EcBoolean collisionOccurred
      (
      ) const ;

   /// get the intersection points
   virtual const EcXmlVectorVector& intersectionPoints
      (
      ) const;

   /// get the intersection points (non-const)
   virtual EcXmlVectorVector& intersectionPoints
      (
      );

   /// get the witness point on shape1
   virtual const EcVector& witnessPoint1
      (
      ) const;

   /// set the witness point on shape1
   virtual void setWitnessPoint1
      (
      const EcVector& pt
      );

   /// get the witness point on shape2
   virtual const EcVector& witnessPoint2
      (
      ) const;

   /// set the witness point on shape2
   virtual void setWitnessPoint2
      (
      const EcVector& pt
      );

   /// get token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// distance to shape
   EcReal m_Distance;

   /// the intersection volume
   EcReal m_IntersectionVolume;

   /// boolean describing whether or not a collision resulted from the query
   EcBoolean m_CollisionOccurred;

   /// the points of intersection
   EcXmlVectorVector m_IntersectionPoints;

   /// the witness point on shape1
   EcVector m_WitnessPoint1;

   /// the witness point on shape2
   EcVector m_WitnessPoint2;

   /// constants used by the class

   /// defines the maximum number of points allowed in a point collection
   static const EcU32 EcMAX_INTERSECTION_POINTS;
};

#endif // ecShapeQueryResult_H_
