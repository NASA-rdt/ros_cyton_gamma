#ifndef ecHydraulicCylinder_H_
#define ecHydraulicCylinder_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecHydraulicCylinder.h
/// @class EcHydraulicCylinder
/// @brief A class describing power conversion by a hydraulic cylinder.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBasePowerConverter.h"

/**
\class EcHydraulicCylinder
\brief A class describing power conversion by a hydraulic cylinder.

A simple hydraulic cylinder system consists of a hydraulic cylinder (which could be asymmetric, i.e. the two areas of the two sides of the piston are necessary equal) and a servovalve. The flows from the supply (e.g. pump) to the cylinder and from the cylinder to drain are caused by the valve openings.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcHydraulicCylinder : public EcBasePowerConverter
{
public:
   /// default constructor
   EcHydraulicCylinder
      (
      );

   /// destructor
   virtual ~EcHydraulicCylinder
      (
      );

   /// copy constructor
   EcHydraulicCylinder
      (
      const EcHydraulicCylinder& orig
      );

   /// assignment operator
   EcHydraulicCylinder& operator=
      (
      const EcHydraulicCylinder& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcHydraulicCylinder& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the fluid's bulk modulus
   virtual EcReal fluidBulkModulus
      (
      ) const;

   /// sets the fluid's bulk modulus
   virtual void setFluidBulkModulus
      (
      EcReal value
      );

   /// gets the fluid's density
   virtual EcReal fluidDensity
      (
      ) const;

   /// sets the fluid's density
   virtual void setFluidDensity
      (
      EcReal value
      );

   /// gets the pressure of the supply (e.g. from pump)
   virtual EcReal supplyPressure
      (
      ) const;

   /// sets the pressure of the supply (e.g. from pump)
   virtual void setSupplyPressure
      (
      EcReal value
      );

   /// gets the pressure of the drain
   virtual EcReal drainPressure
      (
      ) const;

   /// sets the pressure of the drain
   virtual void setDrainPressure
      (
      EcReal value
      );

   /// gets the valve orifice's coefficient of discharge
   virtual EcReal dischargeCoefficient
      (
      ) const;

   /// sets the valve orifice's coefficient of discharge
   virtual void setDischargeCoefficient
      (
      EcReal value
      );

   /// gets the valve's flow area gradient
   virtual EcReal flowAreaGradient
      (
      ) const;

   /// sets the valve's flow area gradient
   virtual void setFlowAreaGradient
      (
      EcReal value
      );

   /// gets the valve's maximum opening
   virtual EcReal maximumValveOpening
      (
      ) const;

   /// sets the valve's maximum opening
   virtual void setMaximumValveOpening
      (
      EcReal value
      );

   /// gets the effective area of side 1 of the piston. This area is where the pressure acts upon to generate force
   virtual EcReal effectiveArea1
      (
      ) const;

   /// sets the effective area of side 1 of the piston
   virtual void setEffectiveArea1
      (
      EcReal value
      );

   /// gets the effective area of side 2 of the piston. This area is where the pressure acts upon to generate force
   virtual EcReal effectiveArea2
      (
      ) const;

   /// sets the effective area of side 2 of the piston
   virtual void setEffectiveArea2
      (
      EcReal value
      );

   /// gets the fluid volume from valve to port 1 of the cylinder
   virtual EcReal fluidVolume1
      (
      ) const;

   /// sets the fluid volume from valve to port 1 of the cylinder
   virtual void setFluidVolume1
      (
      EcReal value
      );

   /// gets the fluid volume from valve to port 2 of the cylinder
   virtual EcReal fluidVolume2
      (
      ) const;

   /// sets the fluid volume from valve to port 1 of the cylinder
   virtual void setFluidVolume2
      (
      EcReal value
      );

   /// gets the maximum fluid length of the cylinder
   virtual EcReal maximumFluidLength
      (
      ) const;

   /// sets the maximum fluid length of the cylinder
   virtual void setMaximumFluidLength
      (
      EcReal value
      );

   /// return the number of state variables for this power converter
   virtual EcU32 numStateVariables
      (
      ) const;

   /// computes and returns the output torque. The torque is generated by this power converter and passed on as an input torque to the mechanical part of the actuator.
   /**
   \param[in] input The control input
   \param[in, out] actuatorState The actuator state. Upon return the actuator state may be modified.
   */
   virtual EcReal outputTorque
      (
      EcReal input,
      EcActuatorState& actuatorState
      ) const;

   /// computes the time derivatives of the states of this power converter.
   /**
   \param[in] input The control input
   \param[in, out] actuatorState The actuator state. Upon return the actuator state may be modified.
   \param[out] derivatives Upon return, it will contain the time derivatives of the states.
   */
   virtual void computeStateDerivatives
   (
      EcReal input,
      EcActuatorState& actuatorState,
      EcXmlRealVector& derivatives
   ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// get an zero-information instance
   static EcHydraulicCylinder nullObject
      (
      );
protected:
   /// the fluid's bulk modulus
   EcXmlReal      m_BulkModulus;

   /// the fluid's density
   EcXmlReal      m_Density;

   /// the pressure of the hydraulic supply (e.g. from pump)
   EcXmlReal      m_SupplyPressure;

   /// the pressure of the drain
   EcXmlReal      m_DrainPressure;

   /// the valve's coefficient of discharge
   EcXmlReal      m_DischargeCoefficient;

   /// the valve's flow area gradient
   EcXmlReal      m_FlowAreaGradient;

   /// the maximum opening of the valve
   EcXmlReal      m_MaxValveOpening;

   /// the effective area of side 1 of the piston
   EcXmlReal      m_EffectiveArea1;

   /// the effective area of side 2 of the piston
   EcXmlReal      m_EffectiveArea2;

   /// the fluid volume from valve to port 1 of the cylinder
   EcXmlReal      m_FluidVolume1;

   /// the fluid volume from valve to port 1 of the cylinder
   EcXmlReal      m_FluidVolume2;

   /// the maximum fluid length of the cylinder
   EcXmlReal      m_MaxFluidLength;

   /// non-XML data
   static const EcU32   m_theStateSize;
};

#endif // ecHydraulicCylinder_H_
