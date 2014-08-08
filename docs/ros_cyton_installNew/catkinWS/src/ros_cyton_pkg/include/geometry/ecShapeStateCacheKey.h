#ifndef ecShapeStateCacheKey_H_
#define ecShapeStateCacheKey_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeStateCacheKey.h
/// @class EcShapeStateCacheKey
/// @brief Defines a key used for accessing the database of shape
///        proximity data.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecLinkStateCacheKey.h"

/// Defines a class for describing a key for accessing the shape proximity database.
class EC_FOUNDATION_GEOMETRY_DECL EcShapeStateCacheKey : public EcLinkStateCacheKey
{
public:
   /// default constructor
   EcShapeStateCacheKey
      (
      );

   /// constructor from data
   EcShapeStateCacheKey
      (
      EcInt32 manipID,
      EcInt32 linkID,
      EcInt32 shapeID
      );

   /// constructor from a link key
   EcShapeStateCacheKey
      (
      const EcLinkStateCacheKey& other
      );

   /// destructor
   virtual ~EcShapeStateCacheKey
      (
      );

   /// copy constructor
   EcShapeStateCacheKey
      (
      const EcShapeStateCacheKey& other
      );

   /// assignment
   EcShapeStateCacheKey& operator=
      (
      const EcShapeStateCacheKey& other
      );

   /// equality
   EcBoolean operator==
      (
      const EcShapeStateCacheKey& other
      )const;

   /// get the shape ID for the key
   virtual EcU32  shapeID
      (
      ) const;

   /// set the  shape ID for the key
   virtual void setShapeID
      (
      EcU32 shapeID
      );

   /// returns an invalid key
   static EcShapeStateCacheKey invalidKey
      (
      );

   /// returns a null object for this class
   static EcShapeStateCacheKey nullObject
      (
      );

protected:
   /// the shape ID
   EcU32 m_ShapeID;
};

/// A pair of EcShapeStateCacheKey
typedef std::pair<EcShapeStateCacheKey,EcShapeStateCacheKey>  EcShapeKeyPair;

/// A vector of EcShapeStateCacheKey pairs
typedef std::vector<EcShapeKeyPair> EcShapeKeyPairVector;

/// A vector of EcShapeKeyPair
typedef std::vector<EcShapeStateCacheKey> EcShapeStateCacheKeyVector;

#endif // ecShapeStateCacheKey_H_
