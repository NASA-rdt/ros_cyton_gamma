#ifndef ecPlanarAxisAlignedBox_H_
#define ecPlanarAxisAlignedBox_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarAxisAlignedBox.h
/// @class EcPlanarAxisAlignedBox
/// @brief A planar axis-aligned box defined by a center and extents
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlanarShape.h"

#include <foundCommon/ecPlanarVector.h>

/// A planar axis-aligned box defined by a center and extents
class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarAxisAlignedBox : public EcPlanarShape
{
public:
   /// default constructor
   EcPlanarAxisAlignedBox
      (
      );

   /// constructor from a center and extents
   EcPlanarAxisAlignedBox
      (
      const EcPlanarVector& center,
      const EcPlanarVector& extents
      );

   /// destructor
   virtual ~EcPlanarAxisAlignedBox
      (
      );

   /// copy constructor
   EcPlanarAxisAlignedBox
      (
      const EcPlanarAxisAlignedBox& orig
      );

   /// assignment operator
   EcPlanarAxisAlignedBox& operator=
      (
      const EcPlanarAxisAlignedBox& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarAxisAlignedBox& orig
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

   /// set center
   virtual void setCenter
      (
      const EcPlanarVector& center
      );

   /// get extents
   const EcPlanarVector& extents
      (
      ) const;

   /// set extents
   virtual void setExtents
      (
      const EcPlanarVector& extents
      );

   /// check the intersection with a point
   virtual EcBoolean checkIntersect
      (
      const EcPlanarVector& point
      ) const;

   /// returns the type of shape.  NOTE higher number shapes know how to
   /// compute distances to lower number shapes.
   virtual EcU32 type
      (
      ) const;

   /// get an empty box
   static EcPlanarAxisAlignedBox nullObject
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
   /// the center of the axis-aligned box
   EcPlanarVector m_Center;

   /// the extents of the axis-aligned box
   EcPlanarVector m_Extents;
};

/// A vector of boxes
typedef EcXmlVectorType<EcPlanarAxisAlignedBox> EcPlanarAxisAlignedBoxVector;

#endif // ecPlanarAxisAlignedBox_H_
