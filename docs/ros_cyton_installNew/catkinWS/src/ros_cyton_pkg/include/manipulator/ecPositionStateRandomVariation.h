#ifndef ecPositionStateRandomVariation_H_
#define ecPositionStateRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionStateRandomVariation.h
/// @class EcPositionStateRandomVariation
/// @brief Description of random variation for positin state of an
///        individual manipulator
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

class EcPositionState;

/** Holds a description of the position state of a manipulator.
 This includes the joint positions and the position of the base.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcPositionStateRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcPositionStateRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets one sigmas of joint positions - const version
   virtual const EcXmlRealVector& jointPositionOneSigmas
      (
      ) const;

   /// gets one sigmas of  joint positions - nonconst version
   virtual EcXmlRealVector& jointPositionOneSigmas
      (
      );

   /// sets one sigmas of joint positions
   virtual void setJointPositionOneSigmas
      (
      const EcXmlRealVector& values
      );

   /// gets the default one sigma used for joint positions that are not in the vector
   virtual EcReal defaultJointPositionOneSigma
      (
      ) const;

   /// sets the default one sigma used for joint positions that are not in the vector
   virtual void setDefaultJointPositionOneSigma
      (
      EcReal value
      );

   /// gets one sigma of the position of the base - const version
   virtual const EcXmlReal& basePositionOneSigma
      (
      ) const;

   /// gets one sigma of the position of the base - nonconst version
   virtual EcXmlReal& basePositionOneSigma
      (
      );

   /// sets one sigma of the position of the base
   virtual void setBasePositionOneSigma
      (
      EcReal value
      );

   /// gets one sigma of the angle of the base - const version
   virtual const EcXmlReal& baseAngleOneSigma
      (
      ) const;

   /// gets one sigma of the angle of the base - nonconst version
   virtual EcXmlReal& baseAngleOneSigma
      (
      );

   /// sets one sigma of the angle of the base
   virtual void setBaseAngleOneSigma
      (
      EcReal value
      );

   /// get a randomized position state based on a nominal position state and the random variations of this object.
   /**
   \param[in] nominal The nominal position state
   \param[out] random The randomized position state
   */
   virtual void getRandomPositionState
      (
      const EcPositionState& nominal,
      EcPositionState& random
      ) const;

   /// get a null object
   static EcPositionStateRandomVariation nullObject
      (
      );

   /// standard object
   static EcPositionStateRandomVariation defaultObject
      (
      );

protected:
   /// the vector of one sigmas of joint positions
   EcXmlRealVector      m_JointPositionOneSigmas;

   /// the default one sigma used for joint positions that are not in the vector
   EcXmlReal            m_DefaultJointPositionOneSigma;

   /// the one sigma of the base position
   EcXmlReal            m_BasePositionOneSigma;

   /// the one sigma of the base angle
   EcXmlReal            m_BaseAngleOneSigma;
};

/// type definition of XML vector of EcPositionStateRandomVariation
typedef EcXmlVectorType<EcPositionStateRandomVariation> EcPositionStateRandomVariationVector;

#endif // ecPositionStateRandomVariation_H_
