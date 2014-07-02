#ifndef ecMassPropertyRandomVariation_H_
#define ecMassPropertyRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecMassPropertyRandomVariation.h
/// @brief Description of random variation of mass property
/// @details EcMassPropertyRandomVariation
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

// forward declarations
class EcRigidBodyMassProperties;

/// The class for generating random variations of mass properties that can be used
/// in Monte-Carlo simulation
class EC_FOUNDATION_MANIPULATOR_DECL EcMassPropertyRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcMassPropertyRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the random variation of mass.
   /**
   This mass value is the one sigma value describing the uncertainty in the mass of the link.
   */
   virtual EcReal massOneSigma
      (
      ) const;

   /// sets the random variation of mass.
   virtual void setMassOneSigma
      (
      EcReal value
      );

   /// get a randomized mass property based on a nominal mass property and the random variations of this object.
   /**
   \param[in] nominal The nominal mass property
   \param[out] random The randomized mass property
   */
   virtual void getRandomMassProperty
      (
      const EcRigidBodyMassProperties& nominal,
      EcRigidBodyMassProperties& random
      ) const;

   /// create an object with default values
   static EcMassPropertyRandomVariation defaultObject
      (
      );
protected:
   // compute the standard deviation for a diagonal term of a second moment of inertia using an ellipsoid.
   /**
   \param[in] a1 First length of a semi-axis of the ellipsoid
   \param[in] a2 Second length of a semi-axis of the ellipsoid
   \return The standard deviation
   */
   virtual EcReal diagonalDeviation
      (
      EcReal a1,
      EcReal a2
      ) const;

   // compute the standard deviation for an off-diagonal term of a second moment of inertia using an ellipsoid.
   /**
   \param[in] a1 First length of a semi-axis of the ellipsoid
   \param[in] a2 Second length of a semi-axis of the ellipsoid
   \return The standard deviation
   */
   virtual EcReal offDiagonalDeviation
      (
      EcReal a1,
      EcReal a2
      ) const;

protected:
   /// the one sigma value of random variation of mass
   EcXmlReal      m_MassOneSigma;
};

#endif // ecMassPropertyRandomVariation_H_
