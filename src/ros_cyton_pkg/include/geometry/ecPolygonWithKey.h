#ifndef ecPolygonWithKey_H_
#define ecPolygonWithKey_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecPolygonWithKey.h
/// @class EcPolygonWithKey
/// @brief interface for the EcPolygonWithKey class
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPolygon.h"

/** Defines a polygon with a surface key
*/
class EC_FOUNDATION_GEOMETRY_DECL EcPolygonWithKey : public EcPolygon
{
public:
   /// default constructor
   EcPolygonWithKey
      (
      );

   /// destructor
   virtual ~EcPolygonWithKey
      (
      );

   /// get surface key
   virtual const EcString& surfaceKey
      (
      ) const;

   /// set surface key
   virtual void setSurfaceKey
      (
      EcString key
      );

   /// copy constructor
   EcPolygonWithKey
      (
      const EcPolygonWithKey& orig
      );

   /// assignment operator
   EcPolygonWithKey& operator=
      (
      const EcPolygonWithKey& orig
      );

   /// assignment operator
   EcPolygonWithKey& operator=
      (
      const EcPolygon& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPolygonWithKey& orig
      ) const;

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

   /// get an empty polygon
   static EcPolygonWithKey nullObject
      (
      );

   /// Resets all data to an empty polgon
   void clear
      (
      );

   /// get token
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

   /// write schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

protected:
   /// the string key for the polygon's surface property
   EcXmlString     m_SurfaceKey;
};

/// A vector of polygons with key
typedef EcXmlVectorType<EcPolygonWithKey> EcPolygonWithKeyVector;

/// A vector of vector of polygons with key
typedef EcXmlVectorType<EcPolygonWithKeyVector> EcPolygonWithKeyVectorVector;

#endif // ecPolygonWithKey_H_
