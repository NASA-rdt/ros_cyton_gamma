#ifndef ecManipulatorPointEvent_H_
#define ecManipulatorPointEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorPointEvent.h
/// @class EcManipulatorPointEvent
/// @brief Holds data describing a point event on a manipulator.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include "ecLinkPointEvent.h"

/// Holds a point event on a single manipulator
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorPointEvent : public EcLinkPointEvent
{
public:
   /// default constructor
   EcManipulatorPointEvent
      (
      );

   /// destructor
   virtual ~EcManipulatorPointEvent
      (
      );

   /// copy constructor
   EcManipulatorPointEvent
      (
      const EcManipulatorPointEvent& orig
      );

   /// assignment operator
   EcManipulatorPointEvent& operator=
      (
      const EcManipulatorPointEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorPointEvent& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components
   virtual void registerComponents
      (
      );

   /// get the link ID of the impacted link
   virtual const EcU32& linkID
      (
      )const;

   /// set the link ID of the impacted link
   virtual void setLinkID
      (
      EcU32 linkID
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
   /// the ID of the impacted link
   EcXmlU32       m_LinkID;
};

#endif // ecManipulatorPointEvent_H_
