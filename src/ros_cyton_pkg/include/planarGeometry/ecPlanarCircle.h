#ifndef ecPlanarCircle_H_
#define ecPlanarCircle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarCircle.h
/// @class EcPlanarCircle
/// @brief A planar circle defined by a center and radius
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlanarShape.h"

#include <foundCommon/ecPlanarVector.h>

/// A planar circle defined by a center and radius
class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarCircle : public EcPlanarShape
{
public:
   /// default constructor
   EcPlanarCircle
      (
      );

   /// constructor from a line segment and a radius
   EcPlanarCircle
      (
      const EcPlanarVector& center,
      EcReal                radius
      );

   /// destructor
   virtual ~EcPlanarCircle
      (
      );

   /// copy constructor
   EcPlanarCircle
      (
      const EcPlanarCircle& orig
      );

   /// assignment operator
   EcPlanarCircle& operator=
      (
      const EcPlanarCircle& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarCircle& orig
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

   /// get center
   virtual const EcPlanarVector& center
      (
      ) const;

   /// set line segment
   virtual void setCenter
      (
      const EcPlanarVector& center
      );

   /// get radius
   virtual EcReal radius
      (
      ) const;

   /// set radius
   virtual void setRadius
      (
      EcReal radius
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

   /// Modified Least Square Fitting from points on the circle
   virtual EcBoolean MLSFitting
      (
      const EcPlanarVectorVector& points
      );

   /// get an empty circle
   static EcPlanarCircle nullObject
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
   /// the center of the circle
   EcPlanarVector m_Center;

   /// the radius of the circle
   EcXmlReal      m_Radius;
};

#endif // ecPlanarCircle_H_
