#ifndef ecShapePointEvent_H_
#define ecShapePointEvent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapePointEvent.h
/// @class EcShapePointEvent
/// @brief Holds data describing a point event on a shape.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/** Holds a class to describe a point event on a shape.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcShapePointEvent : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShapePointEvent
      (
      );

   /// destructor
   virtual ~EcShapePointEvent
      (
      );

   /// copy constructor
   EcShapePointEvent
      (
      const EcShapePointEvent& orig
      );

   /// assignment operator
   EcShapePointEvent& operator=
      (
      const EcShapePointEvent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapePointEvent& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components
   virtual void registerComponents
      (
      );

   /// get the distance to the point event
   virtual const EcReal& distance
      (
      )const;

   /// set the distance to the point event
   virtual void setDistance
      (
      const EcReal& distance
      );

   /// get the is-impacted flag
   virtual EcBoolean isImpacted
      (
      )const;

   /// set the is-impacted flag
   virtual void setIsImpacted
      (
      const EcBoolean& isImpacted
      );

   /// get token
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
   /// distance to the point event
   EcXmlReal      m_Distance;

   /// a flag indicating that an impact has occurred
   EcXmlBoolean   m_IsImpacted;
};

#endif // ecShapePointEvent_H_
