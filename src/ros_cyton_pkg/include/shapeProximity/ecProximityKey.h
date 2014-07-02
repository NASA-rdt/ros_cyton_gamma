#ifndef ecProximityKey_H_
#define ecProximityKey_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecProximityKey.h
/// @brief Helper classes for identifying links and shapes used for
///        distance/collision calculations
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

#include <boost/functional/hash.hpp>
/**
Helper class used to identify a link.
*/
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcLinkKey
{
public:
   /// default constructor
   EcLinkKey() {}

   /// constructor from a manipulator index and link index
   EcLinkKey(EcU32 _manipIndex, EcU32 _linkIndex) :
      manipIndex(_manipIndex),
      linkIndex(_linkIndex)
   {}

   /// equity operator
   EcBoolean operator==
      (
      const EcLinkKey& other
      ) const;

   /// < operator
   EcBoolean operator<
      (
      const EcLinkKey& other
      ) const;

   /// return a guesstimate of unique number based on the three indices. Note that this doesn't guarantee uniqueness at all but just a guess. The purpose is to help hash function.
   EcU32 guesstimate
      (
      ) const;

   /// manipulator index
   EcU32 manipIndex;
   /// link index
   EcU32 linkIndex;
};

/**
Helper class used to identify a pair of links.
*/
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcLinkProximityKey : public std::pair<EcLinkKey, EcLinkKey>
{
public:
   /// default constructor
   EcLinkProximityKey() : std::pair<EcLinkKey, EcLinkKey>() {}
   /// constructor from link keys
   EcLinkProximityKey(const EcLinkKey& x, const EcLinkKey& y) : std::pair<EcLinkKey, EcLinkKey>(x,y) {}

   /// equal operator
   EcBoolean operator==
      (
      const EcLinkProximityKey& other
      ) const;

   /// swap the keys if necessary
   void swapKeys
      (
      );
};

/**
Helper class used to identify a shape.
*/
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcShapeKey
{
public:
   /// default constructor
   EcShapeKey() {}
   /// constructor from manipulator index, link index and shape index
   EcShapeKey(EcU32 _manipIndex, EcU32 _linkIndex, EcU32 _shapeIndex) :
      manipIndex(_manipIndex),
      linkIndex(_linkIndex),
      shapeIndex(_shapeIndex)
   {}

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeKey& other
      ) const;

   /// < operator
   EcBoolean operator<
      (
      const EcShapeKey& other
      ) const;

   /// return a guesstimate of unique number based on the three indices. Note that this doesn't guarantee uniqueness at all but just a guess. The purpose is to help hash function.
   EcU32 guesstimate
      (
      ) const;

   /// manipulator index
   EcU32 manipIndex;
   /// link index
   EcU32 linkIndex;
   /// shape index
   EcU32 shapeIndex;
};


/**
Helper class used to identify a pair of shapes.
*/
class EC_FOUNDATION_SHAPEPROXIMITY_DECL EcShapeProximityKey : public std::pair<EcShapeKey, EcShapeKey>
{
public:
   /// default constructor
   EcShapeProximityKey() : std::pair<EcShapeKey, EcShapeKey>() {}
   /// constructor from shapes and keys
   EcShapeProximityKey
      (
      const EcShapeKey& shape1,
      const EcShapeKey& shape2
      ) : std::pair<EcShapeKey, EcShapeKey>(shape1, shape2) {}

   /// swap the keys if necessary
   void swapKeys();
};

/// hash function for EcLinkProximityKey
inline std::size_t hash_value
   (
   const EcLinkProximityKey& key
   )
{
   boost::hash<unsigned int> hasher;
   return hasher(key.first.guesstimate() + key.second.guesstimate());
}

/// hash function for EcShapeProximityKey
inline std::size_t hash_value
   (
   const EcShapeProximityKey& key
   )
{
   boost::hash<unsigned int> hasher;
   return hasher(key.first.guesstimate() + key.second.guesstimate());
}

/// A vector of EcShapeProximityKey
typedef std::vector< EcShapeProximityKey >   EcShapeProximityKeyVector;

#endif // ecProximityKey_H_
