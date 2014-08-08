#ifndef ecDryFrictionForceProcessor_H_
#define ecDryFrictionForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecDryFrictionForceProcessor.h
/// @class EcDryFrictionForceProcessor
/// @brief Holds a class for processing dissipative forces that arise
///        from object interaction
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseDissipativeForceProcessor.h"
#include <foundCommon/ecGeneralMotion.h>

/**
Holds a class to describe a dissipative force processor type II. This is different from the original dissipative force processor in the following areas:
1. There's no viscous friction.
2. The virtual spring force of static friction can exceed the maximum static friction (coefficient * normal force). This is to help stop the momentum that builds up when the virtual spring force is small.
3. The dynamic (kinetic) friction is computed with a weighting function as suggested by K. Yamane and Y. Nakamura in "Stable Penalty-Based Model of Frictional Contants".
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcDryFrictionForceProcessor : public EcBaseDissipativeForceProcessor
{
public:
   /// default constructor
   EcDryFrictionForceProcessor
      (
      );

   /// destructor
   virtual ~EcDryFrictionForceProcessor
      (
      );

   /// copy constructor
   EcDryFrictionForceProcessor
      (
      const EcDryFrictionForceProcessor& orig
      );

   /// assignment operator
   EcDryFrictionForceProcessor& operator=
      (
      const EcDryFrictionForceProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDryFrictionForceProcessor& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
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

   /// get an empty object
   static EcDryFrictionForceProcessor nullObject
      (
      );

    /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// Reads class data from an XML stream.
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Writes class data to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;


   /// static creator function
   static EcXmlObject* creator
      (
      );


   /// registers components for class
   virtual void registerComponents
      (
      );

   /// get the flag indicating whether to use kinetic friction
   virtual EcBoolean useKineticFriction
      (
      ) const;

   /// set the flag indicating whether to use kinetic friction
   virtual void setUseKineticFriction
      (
      const EcBoolean kf
      );

   /// get the flag indicating whether to use static friction
   virtual EcBoolean useStaticFriction
      (
      ) const;

   /// set the flag indicating whether to use static friction
   virtual void setUseStaticFriction
      (
      const EcBoolean sf
      );

   /// get the linear normal static-friction-model max distance error
   virtual EcReal linearStaticFrictionModelMaxDistanceError
      (
      ) const;

   /// set the linear normal static-friction-model max distance error
   virtual void setLinearStaticFrictionModelMaxDistanceError
      (
      EcReal linearStaticFrictionModelMaxDistanceError
      );

   /// get the linear normal static-friction-model spring ratio
   virtual EcReal linearStaticFrictionModelNormalToTangentialSpringRatio
      (
      ) const;

   /// set the linear normal static-friction-model spring ratio
   virtual void setLinearStaticFrictionModelNormalToTangentialSpringRatio
      (
      EcReal linearStaticFrictionModelNormalToTangentialSpringRatio
      );

   /// get the angular static-friction-model spring max distance error
   virtual EcReal angularStaticFrictionModelMaxAngularError
      (
      ) const;

   /// set the angular static-friction-model spring max distance error
   virtual void setAngularStaticFrictionModelMaxAngularError
      (
      EcReal angularStaticFrictionModelMaxAngularError
      );

   /// get the fraction of the max distance error at which the spring force reaches the maximum value. Default to 2/3.
   virtual EcReal staticFrictionMaxSpringForceFraction
      (
      ) const;

   /// set the fraction of the max distance error at which the spring force reaches the maximum value. Must be between 0.5 and 1. If value is not between 0.5 and 1, then nothing is done.
   virtual void setStaticFrictionMaxSpringForceFraction
      (
      EcReal value
      );

   /// get the exponent of the weighting function for the kinetic friction
   virtual EcReal kineticFrictionWeightingExponent
      (
      ) const;

   /// set the exponent of the weighting function for the kinetic friction. A suggested value is 0.1/dt where dt is the integration time step.
   virtual void setKineticFrictionWeightingExponent
      (
      EcReal value
      );

   /// @copydoc EcBaseDissipativeForceProcessor::process()
   virtual EcBoolean process
      (
      const EcDissipativeForceInput& inputData,
      EcDissipativeForceOutput& outputData
      ) const;

protected:
   /// evaluates and returns the weighting function for kinetic friction. The input is the magnitude of the relative velocity.
   virtual EcReal weightingFunction
      (
      EcReal relVeloMag
      ) const;

protected:

   /// flag indicating whether to use static friction
   EcXmlBoolean m_ComputeStaticFriction;

   /// flag indicating whether to use kinetic friction
   EcXmlBoolean m_ComputeKineticFriction;

   /// linear static-friction-model max distance error
   EcXmlReal    m_LinearStaticFrictionModelMaxDistanceError;

   /// linear normal static-friction-model spring ratio
   EcXmlReal    m_LinearStaticFrictionModelNormalToTangentialSpringRatio;

   /// angular static-friction-model spring max distance error
   EcXmlReal    m_AngularStaticFrictionModelMaxAngularError;

   /// the fraction of the max distance error at which the spring force reaches the maximum value
   EcXmlReal    m_StaticFrictionMaxSpringForceFraction;

   /// the exponent of the weighting function for the kinetic friction
   EcXmlReal m_KineticFrictionWeightingExponent;
};

#endif // ecDryFrictionForceProcessor_H_
