#ifndef ecForceSensor_H_
#define ecForceSensor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceSensor.h
/// @class EcForceSensor
/// @brief Base class of force sensor
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>

class EcStatedSystem;
class EcSystemActiveState;

/// implementation of base class of force sensor
class EC_ACTIN_FORCECONTROL_DECL EcForceSensor: public EcXmlCompoundType
{
public:
   /// default constructor
   EcForceSensor
      (
      );

   /// desctuctor
   virtual ~EcForceSensor
      (
      );

   /// copy constructor
   EcForceSensor
      (
      const EcForceSensor& orig
      );

   /// assignment operator
   EcForceSensor& operator=
      (
      const EcForceSensor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceSensor& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// get sensor frame relative to the primary frame of the link
   virtual const EcCoordinateSystemTransformation& sensorFrame
      (
      ) const;

   /// set sensor frame relative to the primary frame of the link
   virtual void setSensorFrame
      (
      const EcCoordinateSystemTransformation& sensorFrame
      );

   /// get manipulator Index
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// set manipulator Index
   virtual void setManipulatorIndex
      (
      const EcU32 manipulatorIndex
      );

   /// get the link identifier
   virtual const EcString& linkIdentifier
      (
      ) const;

   /// set the link identifier
   virtual void setLinkIdentifier
      (
      const EcString& linkIdentifier
      );

   /// the labels for the force of this sensor
   virtual const EcStringVector& forceLabels
      (
      ) const;

   /// the size of the measured/desired force
   virtual EcU32 forceSize
      (
      ) const=0;

   /// simulate sensor output
   virtual EcBoolean simulateSensorOutput
      (
      EcSystemActiveState& actState,
      const EcStatedSystem& statedSystem,
      EcXmlRealVector& measuredForces
      ) const=0;

   /// a measure of the difference between measured and desired forces
   virtual EcReal difference
      (
      const EcXmlRealVector& measuredForces,
      const EcXmlRealVector& desiredForces
      ) const=0;

protected:

   /// Sensor frame represented in the primary frame of the associated link
   EcCoordinateSystemTransformation m_SensorFrame;

   /// the index of the associated manipulator
   EcXmlU32             m_ManipulatorIndex;

   /// name of the link to which the sensor is attached
   EcXmlString          m_LinkIdentifier;

   /// non-XML
   EcStringVector       m_vForceLabels;
};

#endif // ecForceSensor_H_
