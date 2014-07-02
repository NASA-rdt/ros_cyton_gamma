#ifndef ecManipulatorSystemConfiguration_H_
#define ecManipulatorSystemConfiguration_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorSystemConfiguration.h
/// @class EcManipulatorSystemConfiguration
/// @brief Holds the data that is slowly or intermittently changing, i.e
///        the data is neither permanent (like in system) nor changing
///        every time step (like in state)
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipulatorAttachmentMap.h"
#include "ecSystemCollisionExclusionMap.h"

#include <xml/ecXmlCompType.h>

/// Holds the data that is slowly or intermittently changing, i.e
/// the data is neither permanent (like in system) nor changing
/// every time step (like in state)
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorSystemConfiguration : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorSystemConfiguration
      (
      );

   /// destructor
   virtual ~EcManipulatorSystemConfiguration
      (
      );

   /// copy constructor
   EcManipulatorSystemConfiguration
      (
      const EcManipulatorSystemConfiguration& orig
      );

   /// assignment operator
   EcManipulatorSystemConfiguration& operator=
      (
      const EcManipulatorSystemConfiguration& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorSystemConfiguration& orig
      ) const;

   /// shift all the manipulator indices in the configuration by a given value. Used when merging two systems
   virtual void shiftManipulatorIndices
      (
      EcU32 shiftValue
      );

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcManipulatorSystemConfiguration& other
      );

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// gets the manipulator attachment map - const version
   virtual const EcManipulatorAttachmentMap& attachmentMap
      (
      ) const;

   /// gets the manipulator attachment map - nonconst version
   virtual EcManipulatorAttachmentMap& attachmentMap
      (
      );

   /// sets the manipulator attachment map
   virtual void setAttachmentMap
      (
      const EcManipulatorAttachmentMap& value
      );

   /// gets the collision exclusion map - const version
   virtual const EcSystemCollisionExclusionMap& collisionExclusionMap
      (
      ) const;

   /// gets the collision exclusion map - nonconst version
   virtual EcSystemCollisionExclusionMap& collisionExclusionMap
      (
      );

   /// sets the collision exclusion map
   virtual void setCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// @copydoc EcXmlObject::token()
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

protected:
   /// the manipulator attachment map
   EcManipulatorAttachmentMap       m_AttachmentMap;

   /// the dynamic collision exclusion map
   EcSystemCollisionExclusionMap    m_CollisionExclusionMap;
};

#endif // ecManipulatorSystemConfiguration_H_
