#ifndef ecSurfacePropertyRandomVariation_H_
#define ecSurfacePropertyRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSurfacePropertyRandomVariation.h
/// @brief Description of random variation of surface property
/// @details EcSurfacePropertyRandomVariation
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcDataMap;

/// The class for generating random variations of surface properties that can be used
/// in Monte-Carlo simulation
class EC_FOUNDATION_MANIPULATOR_DECL EcSurfacePropertyRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcSurfacePropertyRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the surface material (key)
   virtual const EcString& material
      (
      ) const;

   /// sets the surface material (key)
   virtual void setMaterial
      (
      const EcString& value
      );

   /// gets the random variation of tension spring constant.
   /**
   This value is the one sigma value describing the uncertainty in the tension spring constant of the surface.
   */
   virtual EcReal tensionSpringConstantOneSigma
      (
      ) const;

   /// gets the random variation of tension spring constant.
   virtual void setTensionSpringConstantOneSigma
      (
      EcReal value
      );

   /// gets the random variation of tension damper constant.
   /**
   This value is the one sigma value describing the uncertainty in the tension damper constant of the surface.
   */
   virtual EcReal tensionDamperConstantOneSigma
      (
      ) const;

   /// gets the random variation of tension damper constant.
   virtual void setTensionDamperConstantOneSigma
      (
      EcReal value
      );

   /// return the default spring constant
   virtual EcReal defaultSpringConstant
      (
      )const;

   /// set the default spring constant
   virtual void setDefaultSpringConstant
      (
      const EcReal& value
      );

   /// return the default damper constant
   virtual EcReal defaultDamperConstant
      (
      )const;

   /// set the default damper constant
   virtual void setDefaultDamperConstant
      (
      const EcReal& value
      );

   /// get a randomized surface property based on a nominal surface property and the random variations of this object.
   /**
   \param[in] nominal The nominal surface property
   \param[out] random The randomized surface property
   */
   virtual void getRandomSurfaceProperty
      (
      const EcDataMap& nominal,
      EcDataMap& random
      ) const;

   /// create an object with default values
   static EcSurfacePropertyRandomVariation defaultObject
      (
      );

protected:
   /// the surface material
   EcXmlString    m_Material;

   /// the one sigma value of random variation of tension spring constant
   EcXmlReal      m_TensionSpringConstantOneSigma;

   /// the one sigma value of random variation of tension damper constant
   EcXmlReal      m_TensionDamperConstantOneSigma;

   /// the default tension spring constant. This is used when one doesn't exist
   EcXmlReal      m_DefaultSpringConstant;

   /// the default tension damper constant. This is used when one doesn't exist
   EcXmlReal      m_DefaultDamperConstant;
};

/// type definition of XML vector of EcSurfacePropertyRandomVariation
typedef EcXmlVectorType<EcSurfacePropertyRandomVariation> EcSurfacePropertyRandomVariationVector;

#endif // ecSurfacePropertyRandomVariation_H_
