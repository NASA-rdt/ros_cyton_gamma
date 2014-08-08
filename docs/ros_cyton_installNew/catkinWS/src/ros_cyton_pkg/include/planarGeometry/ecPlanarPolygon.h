#ifndef ecPlanarPolygon_H_
#define ecPlanarPolygon_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarPolygon.h
/// @class EcPlanarPolygon
/// @brief A planar polygon defined by points specified in a clockwise direction
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlanarShape.h"

#include <foundCommon/ecPlanarVector.h>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/register/point.hpp>

BOOST_GEOMETRY_REGISTER_POINT_2D_GET_SET(EcPlanarVector, EcReal, boost::geometry::cs::cartesian, x, y, setX, setY)

/// A planar polygon defined by points specified in a clockwise direction
class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarPolygon : public EcPlanarShape
{
public:
   /// default constructor
   EcPlanarPolygon
      (
      );

   /// constructor from a vector of points
   EcPlanarPolygon
      (
      const EcPlanarVectorVector& points
      );

   /// destructor
   virtual ~EcPlanarPolygon
      (
      );

   /// copy constructor
   EcPlanarPolygon
      (
      const EcPlanarPolygon& orig
      );

   /// assignment operator
   EcPlanarPolygon& operator=
      (
      const EcPlanarPolygon& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarPolygon& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get points
   virtual const EcPlanarVectorVector& points
      (
      ) const;

   /// set points
   virtual void setPoints
      (
      const EcPlanarVectorVector& points
      );

   /// clear points
   virtual void clearPoints
      (
      );

   /// add a point
   virtual void addPoint
      (
      const EcPlanarVector& point
      );

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcPlanarVector& point
      ) const;

   /// returns the type ID of this shape
   virtual EcU32 type
      (
      ) const;

   /// get an empty polygon
   static EcPlanarPolygon nullObject
      (
      );

   /// the creator function for this object
   static EcXmlObject* creator
      (
      );

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;

protected:
   /// type definition of RingType
   typedef boost::geometry::model::ring<EcPlanarVector> RingType;

   /// the points of the polygon
   EcPlanarVectorVector m_Points;

   /// untiltiy to store the points
   mutable boost::shared_ptr<RingType> m_RingPtr;
};

#endif // ecPlanarPolygon_H_
