#ifndef ecManipulatorStateCacheKey_H_
#define ecManipulatorStateCacheKey_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorStateCacheKey.h
/// @class EcManipulatorStateCacheKey
/// @brief Defines a class for describing a key for accessing
///        manipulators in the shape proximity database.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

/// Defines a class for describing a key for accessing manipulators in the shape proximity database.
class EC_FOUNDATION_GEOMETRY_DECL EcManipulatorStateCacheKey
{
public:
   /// default constructor
   EcManipulatorStateCacheKey
      (
      );

   /// constructor
   EcManipulatorStateCacheKey
      (
      EcInt32 manipID
      );

   /// destructor
   virtual ~EcManipulatorStateCacheKey
      (
      );

   /// copy constructor
   EcManipulatorStateCacheKey
      (
      const EcManipulatorStateCacheKey& other
      );

   /// assignment
   EcManipulatorStateCacheKey& operator=
      (
      const EcManipulatorStateCacheKey& other
      );

   /// equality
   EcBoolean operator==
      (
      const EcManipulatorStateCacheKey& other
      )const;

   /// get the manipulator ID for the key
   virtual EcU32 manipID
      (
      ) const;

   /// set the manipulator ID for the key
   virtual void setManipID
      (
      EcU32 manipID
      );

   /// returns an invalid key
   static EcManipulatorStateCacheKey invalidKey
      (
      );

   /// returns a null object for this class
   static EcManipulatorStateCacheKey nullObject
      (
      );

protected:
   /// the manipulator ID
   EcU32 m_ManipID;
};

#endif // ecManipulatorStateCacheKey_H_
