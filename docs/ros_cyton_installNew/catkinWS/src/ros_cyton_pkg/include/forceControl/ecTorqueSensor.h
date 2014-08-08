#ifndef ecTorqueSensor_H_
#define ecTorqueSensor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecTorqueSensor.h
/// @class EcTorqueSensor
/// @brief Simulating and processing a torque sensor.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceSensor.h"
#include <geometry/ecShapeCollisionEvent.h>

/// Simulating and processing a torque sensor.
/**
The sensor frame is assumed to at the joint and has the Z axis along the the rotating axis of the joint.
*/
class EC_ACTIN_FORCECONTROL_DECL EcTorqueSensor : public EcForceSensor
{
public:
   /// default constructor
   EcTorqueSensor
      (
      );

   /// destructor
   virtual ~EcTorqueSensor
      (
      );

   /// copy constructor
   EcTorqueSensor
      (
      const EcTorqueSensor& orig
      );

   /// assignment operator
   EcTorqueSensor& operator=
      (
      const EcTorqueSensor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTorqueSensor& orig
      ) const;


   /// XML-initializes the class and all parent classes.
   virtual EcBoolean xmlInit
      (
      );

   /// A virtual constructor that returns an EcXmlObject.
   virtual EcXmlObject* clone
      (
      ) const;

   /// All the components registered here are automatically
   virtual void registerComponents
      (
      );

   /// get sensor Shape Name
   virtual const EcString& sensorShapeName
      (
      ) const;

   /// set sensor Shape Name
   virtual void setSensorShapeName
      (
      const EcString& sensorShapeName
      );

   /// \copydoc EcForceSensor::forceSize()
   virtual EcU32 forceSize
      (
      ) const;

   /// \copydoc EcForceSensor::simulateSensorOutput()
   virtual EcBoolean simulateSensorOutput
      (
      EcSystemActiveState& actState,
      const EcStatedSystem& statedSystem,
      EcXmlRealVector& measuredForces
      ) const;

   /// \copydoc EcForceSensor::difference()
   virtual EcReal difference
      (
      const EcXmlRealVector& measuredForces,
      const EcXmlRealVector& desiredForces
      ) const;

   /// a string token for this class
   virtual const EcToken& token
      (
      ) const;

   /// test equality
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// A static creator function.  This is registered using the class token.
   static EcXmlObject* creator
      (
      );

   /// Returns a string token for this class.
   static const EcToken& classToken
      (
      );

protected:
   /// The sensor is represented by the shape in a link with this name, can be the whole
   /// link or part of the link.
   EcXmlString m_SensorShapeName;

   /// collision events
   mutable EcActiveCollisionStateVector m_ColEvents;
};

#endif // ecTorqueSensor_H_
