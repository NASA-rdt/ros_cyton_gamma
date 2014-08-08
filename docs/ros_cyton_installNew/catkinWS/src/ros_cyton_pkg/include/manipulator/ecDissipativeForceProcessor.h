#ifndef ecDissipativeForceProcessor_H_
#define ecDissipativeForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDissipativeForceProcessor.h
/// @class EcDissipativeForceProcessor
/// @brief Holds a class for processing dissipative forces that arise
///        from object interaction
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseDissipativeForceProcessor.h"
#include <foundCommon/ecGeneralMotion.h>

/**
Holds a class to describe a dissipative force processor that has 3 components -- static friction, kinetic friction, and viscous friction. The static friction is modeled as a virtual breaking spring-damper as described in Actin User's Guide.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcDissipativeForceProcessor : public EcBaseDissipativeForceProcessor
{
public:
   /// default constructor
   EcDissipativeForceProcessor
      (
      );

   /// destructor
   virtual ~EcDissipativeForceProcessor
      (
      );

   /// copy constructor
   EcDissipativeForceProcessor
      (
      const EcDissipativeForceProcessor& orig
      );

   /// assignment operator
   EcDissipativeForceProcessor& operator=
      (
      const EcDissipativeForceProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDissipativeForceProcessor& orig
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
   static EcDissipativeForceProcessor nullObject
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

   /// get the flag indicating whether to use viscous friction
   virtual EcBoolean useViscousFriction
      (
      ) const;

    /// set the flag indicating whether to use viscous friction
   virtual void setUseViscousFriction
      (
      const EcBoolean vf
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

   /// get the angular static-friction-model spring coefficient
   virtual EcReal angularStaticFrictionModelMaxAngularError
      (
      ) const;

   /// set the angular static-friction-model spring coefficient
   virtual void setAngularStaticFrictionModelMaxAngularError
      (
      EcReal angularStaticFrictionModelMaxAngularError
      );

   /// @copydoc EcBaseDissipativeForceProcessor::process()
   virtual EcBoolean process
      (
      const EcDissipativeForceInput& inputData,
      EcDissipativeForceOutput& outputData
      ) const;

protected:

   /// flag indicating whether to use static friction
   EcXmlBoolean m_ComputeStaticFriction;

   /// flag indicating whether to use kinetic friction
   EcXmlBoolean m_ComputeKineticFriction;

   /// flag indicating whether to use viscous friction.
   EcXmlBoolean m_ComputeVicousFriction;

   /// linear normal static-friction-model max distance error
   EcXmlReal    m_LinearStaticFrictionModelMaxDistanceError;

   /// linear normal static-friction-model spring ratio
   EcXmlReal    m_LinearStaticFrictionModelNormalToTangentialSpringRatio;

   /// angular static-friction-model spring coefficient
   EcXmlReal    m_AngularStaticFrictionModelMaxAngularError;
};

#endif // ecDissipativeForceProcessor_H_
