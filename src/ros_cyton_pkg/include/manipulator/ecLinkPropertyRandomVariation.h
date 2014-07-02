#ifndef ecLinkPropertyRandomVariation_H_
#define ecLinkPropertyRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkPropertyRandomVariation.h
/// @brief Description of random variations for link properties
/// @details EcLinkPropertyRandomVariation
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlVectorType.h>
#include "ecJointActuatorRandomVariation.h"
#include "ecLinkKinematicsRandomVariation.h"
#include "ecMassPropertyRandomVariation.h"
#include "ecSurfacePropertyRandomVariation.h"

/// The class for generating random variations of properties of a manipulator link that can be used
/// in Monte-Carlo simulation
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkPropertyRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcLinkPropertyRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets link kinematics variation
   virtual const EcLinkKinematicsRandomVariation& linkKinematicsVariation
      (
      ) const;

   /// sets link kinematics variation
   virtual void setLinkKinematicsVariation
      (
      const EcLinkKinematicsRandomVariation& value
      );

   /// gets mass property variation
   virtual const EcMassPropertyRandomVariation& massPropertyVariation
      (
      ) const;

   /// sets mass property variation
   virtual void setMassPropertyVariation
      (
      const EcMassPropertyRandomVariation& value
      );

   /// gets joint actuator variation
   virtual const EcJointActuatorRandomVariation& jointActuatorVariation
      (
      ) const;

   /// sets joint actuator variation
   virtual void setJointActuatorVariation
      (
      const EcJointActuatorRandomVariation& value
      );

   /// gets surface property variation vector. Each link can have many surface properties depending on the shapes inside the link.
   virtual const EcSurfacePropertyRandomVariationVector& surfacePropertyVariationVector
      (
      ) const;

   /// sets surface property variation vector
   virtual void setSurfacePropertyVariationVector
      (
      const EcSurfacePropertyRandomVariationVector& value
      );

   /// create an object with default values
   static EcLinkPropertyRandomVariation defaultObject
      (
      );

protected:
   /// random variation of link kinematics
   EcLinkKinematicsRandomVariation     m_LinkKinematicsVariation;

   /// random variation of mass property
   EcMassPropertyRandomVariation       m_MassPropertyVariation;

   /// random variation of joint actuator
   EcJointActuatorRandomVariation      m_JointActuatorVariation;

   /// vector of random variations of surface property
   EcSurfacePropertyRandomVariationVector    m_vSurfacePropertyVariation;
};

/// type definition of XML map of string and EcLinkPropertyRandomVariation
typedef EcXmlMapType< EcXmlString, EcLinkPropertyRandomVariation >
   EcStringLinkPropertyRandomVariationMap;

/// type definition of XML vector of EcStringLinkPropertyRandomVariationMap
typedef EcXmlVectorType< EcStringLinkPropertyRandomVariationMap >
   EcStringLinkPropertyRandomVariationMapVector;

#endif // ecLinkPropertyRandomVariation_H_
