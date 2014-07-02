#ifndef ecSixAxisFTSensor_H_
#define ecSixAxisFTSensor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecSixAxisFTSensor.h
/// @class EcSixAxisFTSensor
/// @brief Simulates and processes a six-axis force/torque sensor.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceSensor.h"

/** Simulates and processes a six-axis sensor.
*/
class EC_ACTIN_FORCECONTROL_DECL EcSixAxisFTSensor : public EcForceSensor
{
public:

   /// constructor
   EcSixAxisFTSensor
      (
      );

   /// destructor
   virtual ~EcSixAxisFTSensor
      (
      );

   /// copy constructor
   EcSixAxisFTSensor
      (
      const EcSixAxisFTSensor& orig
      );

   /// assignment operator
   EcSixAxisFTSensor& operator=
      (
      const EcSixAxisFTSensor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSixAxisFTSensor& orig
      ) const;

   /// XML-initializes the class and all parent classes.
   EcBoolean xmlInit
      (
      );

   /// A virtual constructor that returns an EcXmlObject.
   EcXmlObject* clone
      (
      ) const;

   /// All the components registered here are automatically
   void registerComponents
      (
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

   /// virtual equality
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
};

#endif // ecSixAxisFTSensor_H_
