#ifndef ecVelocityStateRandomVariation_H_
#define ecVelocityStateRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecVelocityStateRandomVariation.h
/// @class EcVelocityStateRandomVariation
/// @brief Description of random variation for velocity state of an
///        individual manipulator
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

class EcVelocityState;

/** Holds a description of random variation of the velocity state of a manipulator.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcVelocityStateRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcVelocityStateRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets one sigmas of joint velocities - const version
   virtual const EcXmlRealVector& jointVelocityOneSigmas
      (
      ) const;

   /// gets one sigmas of  joint velocities - nonconst version
   virtual EcXmlRealVector& jointVelocityOneSigmas
      (
      );

   /// sets one sigmas of joint velocities
   virtual void setJointVelocityOneSigmas
      (
      const EcXmlRealVector& values
      );

   /// gets the default one sigma used for joint velocities that are not in the vector
   virtual EcReal defaultJointVelocityOneSigma
      (
      ) const;

   /// sets the default one sigma used for joint velocities that are not in the vector
   virtual void setDefaultJointVelocityOneSigma
      (
      EcReal value
      );

   /// gets one sigma of the linear velocity of the base - const version
   virtual const EcXmlReal& baseLinearVelocityOneSigma
      (
      ) const;

   /// gets one sigma of the linear velocity of the base - nonconst version
   virtual EcXmlReal& baseLinearVelocityOneSigma
      (
      );

   /// sets one sigma of the linear velocity of the base
   virtual void setBaseLinearVelocityOneSigma
      (
      EcReal value
      );

   /// gets one sigma of the angular velocity of the base - const version
   virtual const EcXmlReal& baseAngularVelocityOneSigma
      (
      ) const;

   /// gets one sigma of the angular velocity of the base - nonconst version
   virtual EcXmlReal& baseAngularVelocityOneSigma
      (
      );

   /// sets one sigma of the angular velocity of the base
   virtual void setBaseAngularVelocityOneSigma
      (
      EcReal value
      );

   /// get a randomized velocity state based on a nominal velocity state and the random variations of this object.
   /**
   \param[in] nominal The nominal velocity state
   \param[out] random The randomized velocity state
   */
   virtual void getRandomVelocityState
      (
      const EcVelocityState& nominal,
      EcVelocityState& random
      ) const;

   /// get a null object
   static EcVelocityStateRandomVariation nullObject
      (
      );

   /// standard object
   static EcVelocityStateRandomVariation defaultObject
      (
      );

protected:
   /// the vector of one sigmas of joint velocities
   EcXmlRealVector      m_JointVelocityOneSigmas;

   /// the default one sigma used for joint velocities that are not in the vector
   EcXmlReal            m_DefaultJointVelocityOneSigma;

   /// the one sigma of the base linear velocity
   EcXmlReal            m_BaseLinearVelocityOneSigma;

   /// the one sigma of the base angular velocity
   EcXmlReal            m_BaseAngularVelocityOneSigma;
};

/// type defition of XML vector of EcVelocityStateRandomVariation
typedef EcXmlVectorType<EcVelocityStateRandomVariation> EcVelocityStateRandomVariationVector;

#endif // ecVelocityStateRandomVariation_H_
