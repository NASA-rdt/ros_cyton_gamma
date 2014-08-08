#ifndef ecAntiCollisionPriorityList_H_
#define ecAntiCollisionPriorityList_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecAntiCollisionPriorityList.h
/// @class EcAntiCollisionPriorityList
/// @brief Holds a priority list used in anti-collision
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declaration
class EcManipulatorAttachmentMap;

/// Holds definition of a priority list used in anti-collision
class EC_ACTIN_CONTROL_DECL EcAntiCollisionPriorityList : public EcXmlInt32Vector
{
public:

   /// default constructor
   EcAntiCollisionPriorityList
      (
      );

   /// destructor
   virtual ~EcAntiCollisionPriorityList
      (
      );

   /// copy constructor
   EcAntiCollisionPriorityList
      (
      const EcAntiCollisionPriorityList& orig
      );

   /// assignment operator
   EcAntiCollisionPriorityList& operator=
      (
      const EcAntiCollisionPriorityList& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAntiCollisionPriorityList& orig
      ) const;

   /// set the const pointer to the attachment map. The map is used to help determine priority. Say priority
   /// of manipulator A is higher than that of B, which in turn is higher than that of C. If manipulator
   /// C is attached to manipulator A, it will then take the priority of manipulator A and therefore has
   /// higher priority than B.
   virtual void setAttachmentMapPointer
      (
      const EcManipulatorAttachmentMap* pMap
      );

   /// returns whether manipulator specified by manipIndex1 should yield to manipulator specified by manipIndex2
   virtual EcBoolean yield
      (
      EcU32 manipIndex1,
      EcU32 manipIndex2
      ) const;

protected:
   /// const pointer to the attachment map
   const EcManipulatorAttachmentMap*   m_pAttachmentMap;
};

#endif // ecAntiCollisionPriorityList_H_
