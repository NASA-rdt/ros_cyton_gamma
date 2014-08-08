#ifndef ecShapeProximityDescriptor_H_
#define ecShapeProximityDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeProximityDescriptor.h
/// @class EcShapeProximityDescriptor
/// @brief Holds a descriptor class to describe a shape query
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShapeStateCacheKey.h"
#include <xml/ecXmlCompType.h>

class EcStatedSystem;

/// Holds a class to describe a shape query descriptor
class EC_FOUNDATION_GEOMETRY_DECL EcShapeProximityDescriptor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShapeProximityDescriptor
      (
      );

   /// destructor
   virtual ~EcShapeProximityDescriptor
      (
      );

   /// copy constructor
   EcShapeProximityDescriptor
      (
      const EcShapeProximityDescriptor& orig
      );

   /// assignment operator
   EcShapeProximityDescriptor& operator=
      (
      const EcShapeProximityDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeProximityDescriptor& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone
   virtual EcXmlObject* clone
      (
      ) const;

   /// get key 1
   virtual const EcShapeStateCacheKey& key1
      (
      )const;

   /// set key 1
   virtual void setKey1
      (
      const EcShapeStateCacheKey& key
      );

   /// get key 2
   virtual const EcShapeStateCacheKey& key2
      (
      )const;

   /// set key 2
   virtual void setKey2
      (
      const EcShapeStateCacheKey& key
      );

   /// get stated system
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// set stated system
   virtual void setStatedSystem
      (
      const EcStatedSystem* ptr
      );

   virtual const EcToken& token
      (
      ) const;

protected:
   /// key for this shape
   EcShapeStateCacheKey m_Key1;

   /// key for other shape
   EcShapeStateCacheKey m_Key2;

   /// stated system pointer
   const EcStatedSystem* m_pStSystem;
};

#endif // ecShapeProximityDescriptor_H_
