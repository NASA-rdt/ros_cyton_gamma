#ifndef ecStateRandomVariation_H_
#define ecStateRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecStateRandomVariation.h
/// @brief Description of random variation for manipulator state
/// @details EcStateRandomVariation
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPositionStateRandomVariation.h"
#include "ecVelocityStateRandomVariation.h"

/**
\class EcStateRandomVariation
\brief Description of random variation for manipulator state.

The random variations are used in Monte Carlo simulations to randomly perturb the state.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcStateRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcStateRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets random variations of the position states - const version
   virtual const EcPositionStateRandomVariationVector& positionStateVariations
      (
      ) const;

   /// gets random variations of the position states - nonconst version
   EcPositionStateRandomVariationVector& positionStateVariations
      (
      );

   /// sets random variations of the position states
   void setPositionStateVariations
      (
      const EcPositionStateRandomVariationVector& values
      );

   /// gets random variations of the velocity states - const version
   const EcVelocityStateRandomVariationVector& velocityStateVariations
      (
      ) const;

   /// gets random variations of the velocity states - nonconst version
   EcVelocityStateRandomVariationVector& velocityStateVariations
      (
      );

   /// sets random variations of the velocity states
   void setVelocityStateVariations
      (
      const EcVelocityStateRandomVariationVector& values
      );

   /// gets the default EcPositionStateRandomVariation instance. This is used for the position state that is out of range.
   virtual const EcPositionStateRandomVariation& defaultPositionStateRandomVariation
      (
      ) const;

   /// sets the default EcPositionStateRandomVariation instance.
   virtual void setDefaultPositionStateRandomVariation
      (
      const EcPositionStateRandomVariation& value
      );

   /// gets the default EcVelocityStateRandomVariation instance. This is used for the velocity state that is out of range.
   virtual const EcVelocityStateRandomVariation& defaultVelocityStateRandomVariation
      (
      ) const;

   /// sets the default EcVelocityStateRandomVariation instance.
   virtual void setDefaultVelocityStateRandomVariation
      (
      const EcVelocityStateRandomVariation& value
      );

   /// get a null object
   static EcStateRandomVariation nullObject
      (
      );

protected:
   /// the vector of position state random variations
   EcPositionStateRandomVariationVector   m_PositionStateVariations;

   /// the vector of velocity state random variations
   EcVelocityStateRandomVariationVector   m_VelocityStateVariations;

   /// the default random variation for position state
   EcPositionStateRandomVariation         m_DefaultPositionStateVariation;

   /// the default random variation for velocity state
   EcVelocityStateRandomVariation         m_DefaultVelocityStateVariation;
};

/// type definition of XML vector of EcStateRandomVariation
typedef EcXmlVectorType< EcStateRandomVariation > EcStateRandomVariationVector;

#endif // ecStateRandomVariation_H_
