#ifndef ecForceSensorSet_H_
#define ecForceSensorSet_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceSensorSet.h
/// @class EcForceSensorSet
/// @brief A set of force sensors for a single manipulator.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceSensorVector.h"
#include <xml/ecXmlCompType.h>

/// Holds a description of all force sensors on a manipulator.
class EC_ACTIN_FORCECONTROL_DECL EcForceSensorSet : public EcXmlCompoundType
{
public:
   /// default constructor
   EcForceSensorSet
      (
      );

   /// destructor
   virtual ~EcForceSensorSet
      (
      );

   /// copy constructor
   EcForceSensorSet
      (
      const EcForceSensorSet& orig
      );

   /// assignment operator
   EcForceSensorSet& operator=
      (
      const EcForceSensorSet& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceSensorSet& orig
      ) const;

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

   /// gets vector of force sensors
   virtual const EcForceSensorVector& forceSensors
      (
      ) const;

   /// sets vector of force sensors
   virtual void setForceSensors
      (
      const EcForceSensorVector& forceSensors
      );

   /// pushes back a single force sensor
   virtual void addForceSensor
      (
      const EcForceSensor& forceSensor
      );

   /// remove a single force sensor
   virtual void removeForceSensor
      (
      const EcU32 index
      );

   /// exchange an force sensor with a new one, if the old one exists
   virtual EcBoolean exchange
      (
      EcU32 index,
      const EcForceSensor& forceSensor
      );

   /// get the number of force sensors
   virtual EcU32 size
      (
      ) const;

   /// return class token
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

   /// get a null link
   static EcForceSensorSet nullObject
      (
      );

protected:
   /// a vector of force sensors
   EcForceSensorVector  m_ForceSensors;
};

/// a vector of force sensor sets
typedef EcXmlVectorType<EcForceSensorSet> EcForceSensorSetVector;

#endif // ecForceSensorSet_H_
