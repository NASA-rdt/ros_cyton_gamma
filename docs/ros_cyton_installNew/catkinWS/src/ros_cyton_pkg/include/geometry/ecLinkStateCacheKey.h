#ifndef ecLinkStateCacheKey_H_
#define ecLinkStateCacheKey_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkStateCacheKey.h
/// @class EcLinkStateCacheKey
/// @brief Defines a class for describing a key for accessing a
///        link in the shape proximity database.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecManipulatorStateCacheKey.h"

/**
 Defines a class for describing a key for accessing a link in the shape proximity
 database.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcLinkStateCacheKey : public EcManipulatorStateCacheKey
{
public:
   /// default constructor
   EcLinkStateCacheKey
      (
      );

   /// constructor from data
   EcLinkStateCacheKey
      (
      EcInt32 manipID,
      EcInt32 linkID
      );

   /// constructor from a manipulator key
   EcLinkStateCacheKey
      (
      const EcManipulatorStateCacheKey& other
      );

   /// destructor
   virtual ~EcLinkStateCacheKey
      (
      );

   /// copy constructor
   EcLinkStateCacheKey
      (
      const EcLinkStateCacheKey& other
      );

   /// assignment
   EcLinkStateCacheKey& operator=
      (
      const EcLinkStateCacheKey& other
      );

   /// equality
   EcBoolean operator==
      (
      const EcLinkStateCacheKey& other
      )const;

   /// get the link ID for the key
   virtual EcU32  linkID
      (
      )  const;

   /// set the link ID for the key
   virtual void setLinkID
      (
      EcU32 linkID
      );

   /// returns an invalid key
   static EcLinkStateCacheKey invalidKey
      (
      );

   /// returns a null object for this class
   static EcLinkStateCacheKey nullObject
      (
      );

protected:
   /// the link ID
   EcU32 m_LinkID;
};

#endif // ecLinkStateCacheKey_H_
