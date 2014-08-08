#ifndef ecPiForceControlFunction_H_
#define ecPiForceControlFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecPiForceControlFunction.h
/// @class EcPiForceControlFunction
/// @brief PI force control algorithm
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceControlFunction.h"
#include <foundCommon/ecGeneralForce.h>
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlVectorType.h>

/// V = ( kp*deltaF + ki*integral(deltaF)dt)
class EC_ACTIN_FORCECONTROL_DECL EcPiForceControlFunction : public EcForceControlFunction
{
public:

   /// default constructor
   EcPiForceControlFunction
      (
      );

   /// destructor
   virtual ~EcPiForceControlFunction
      (
      );

   /// copy constructor
   EcPiForceControlFunction
      (
      const EcPiForceControlFunction& orig
      );

   /// assignment operator
   EcPiForceControlFunction& operator=
      (
      const EcPiForceControlFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPiForceControlFunction& orig
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

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// token
   virtual const EcToken& token
      (
      ) const;

   /// get the proportional gains
   virtual const EcXmlRealVector& kp
      (
      ) const;

   /// set the proportional gains
   virtual void setKp
      (
      const EcXmlRealVector& kp
      );

   /// get the integral gains
   virtual const EcXmlRealVector& ki
      (
      ) const;

   /// set the integral gains
   virtual void setKi
      (
      const EcXmlRealVector& ki
      );

   /// \copydoc EcForceControlFunction::reset()
   virtual void reset
      (
      );

   /// \copydoc EcForceControlFunction::computeDifferential()
   virtual EcBoolean computeDifferential
      (
      EcReal deltaTime,
      const EcXmlRealVector& measuredForce,
      const EcXmlRealVector& desiredForce,
      EcRealVector& differential
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
protected:
   /// proportional constants for the PI controller
   EcXmlRealVector         m_Kp;

   /// integral constants
   EcXmlRealVector         m_Ki;

   // non-XML data
   /// accumulated (force delta)*(delta time)
   mutable EcRealVector    m_AccuForceDeltaTime;
};

#endif // ecPiForceControlFunction_H_
