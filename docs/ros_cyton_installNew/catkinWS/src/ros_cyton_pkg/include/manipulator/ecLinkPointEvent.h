#ifndef ecLinkPointEvent_H_
#define ecLinkPointEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkPointEvent.h
/// @class EcLinkPointEvent
/// @brief Holds data describing a point event on a link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include <xml/ecXmlCompType.h>
#include <geometry/ecShapePointEvent.h>

/** Holds a class to describe a point event on a link.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkPointEvent : public EcShapePointEvent
{
public:
   /// default constructor
   EcLinkPointEvent
      (
      );

   /// destructor
   virtual ~EcLinkPointEvent
      (
      );

   /// copy constructor
   EcLinkPointEvent
      (
      const EcLinkPointEvent& orig
      );

   /// assignment operator
   EcLinkPointEvent& operator=
      (
      const EcLinkPointEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkPointEvent& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components
   virtual void registerComponents
      (
      );

   /// get the shape ID of the impacted shape
   virtual const EcU32& shapeID
      (
      )const;

   /// set the shape ID of the impacted shape
   virtual void setShapeID
      (
      EcU32 shapeID
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
   /// the ID of the impacted shape
   EcXmlU32       m_ShapeID;
};

#endif // ecLinkPointEvent_H_
