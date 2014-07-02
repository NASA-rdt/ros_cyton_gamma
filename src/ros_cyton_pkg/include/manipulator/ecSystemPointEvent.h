#ifndef ecSystemPointEvent_H_
#define ecSystemPointEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemPointEvent.h
/// @class EcSystemPointEvent
/// @brief Holds data describing a point collision.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipulatorPointEvent.h"
#include <xml/ecXmlCompType.h>

/** Holds a class to describe a point event for the system.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcSystemPointEvent : public EcManipulatorPointEvent
{
public:
   /// default constructor
   EcSystemPointEvent
      (
      );

   /// destructor
   virtual ~EcSystemPointEvent
      (
      );

   /// copy constructor
   EcSystemPointEvent
      (
      const EcSystemPointEvent& orig
      );

   /// assignment operator
   EcSystemPointEvent& operator=
      (
      const EcSystemPointEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemPointEvent& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components
   virtual void registerComponents
      (
      );

   /// get the contact point in system coordinates
   virtual const EcVector& contactPoint
      (
      )const;

   /// set the contact point in system coordinates
   virtual void setContactPoint
      (
      const EcVector& contactPoint
      );

   /// get the manipulator ID of the impacted manipulator
   virtual const EcU32& manipulatorID
      (
      )const;

   /// set the manipulator ID of the impacted manipulator
   virtual void setManipulatorID
      (
      EcU32 manipulatorID
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// clone
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

protected:
   /// the point of impact
   EcXmlVector    m_ContactPoint;

   /// the ID of the impacted manipulator
   EcXmlU32       m_ManipulatorID;
};

#endif // ecSystemPointEvent_H_
