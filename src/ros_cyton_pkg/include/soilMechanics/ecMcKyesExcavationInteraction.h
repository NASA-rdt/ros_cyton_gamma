#ifndef ecMcKyesExcavationInteraction_H_
#define ecMcKyesExcavationInteraction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecMcKyesExcavationInteraction.h
/// @class EcMcKyesExcavationInteraction
/// @brief Defines a class for computing bucket excavation force
///        using McKyes model
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseExcavationInteraction.h"
#include "ecExcavationParameters.h"

#include <foundCommon/ecDataMap.h>

/// Defines a class for computing bucket excavation force using McKyes model
class EC_ACTIN_SOILMECHANICS_DECL EcMcKyesExcavationInteraction : public EcBaseExcavationInteraction
{
public:
   /// default constructor
   EcMcKyesExcavationInteraction
      (
      );

   /// destructor
   virtual ~EcMcKyesExcavationInteraction
      (
      );

   /// copy constructor
   EcMcKyesExcavationInteraction
      (
      const EcMcKyesExcavationInteraction& orig
      );

   /// assignment operator
   EcMcKyesExcavationInteraction& operator=
      (
      const EcMcKyesExcavationInteraction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMcKyesExcavationInteraction& orig
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

   /// get an empty object
   static EcMcKyesExcavationInteraction nullObject
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

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// \copydoc EcBaseExcavationInteraction::requiredToolProperties()
   virtual const EcStringVector& requiredToolProperties
      (
      ) const;

   /// \copydoc EcBaseExcavationInteraction::requiredSoilProperties()
   virtual const EcStringVector& requiredSoilProperties
      (
      ) const;

   /// \copydoc EcBaseExcavationInteraction::setSoilProperties()
   virtual EcBoolean setSoilProperties
      (
      const EcSoilProperties& soilProps
      );

   /// \copydoc EcBaseExcavationInteraction::setParameters()
   virtual EcBoolean setParameters
      (
      const EcExcavationParameters& params
      );

   /// \copydoc EcBaseExcavationInteraction::horizontalForce()
   virtual EcReal horizontalForce
      (
      ) const;

   /// \copydoc EcBaseExcavationInteraction::verticalForce()
   virtual EcReal verticalForce
      (
      ) const;

protected:
   /// assign the tool properties from the data map
   virtual EcBoolean assignToolProperties
      (
      );
protected:
   // non-XML data
   EcReal               m_ToolWidth;                  ///< the tool width
   EcReal               m_SoilCohesion;               ///< the soil cohesion
   EcReal               m_SoilToolAdhesion;           ///< the soil-tool adhesion
   EcReal               m_SoilInternalFrictionAngle;  ///< the soil interal friction angle
   EcReal               m_SoilExternalFrictionAngle;  ///< the soil external friction angle
   EcReal               m_SoilSpecificMass;           ///< the soil specific mass
   EcReal               m_SoilShearPlaneFailureAngle; ///< the soil shear-plane failure angle
   EcExcavationParameters  m_Params;                  ///< the excavation parameters

   // internal (intermediate) data
   mutable EcReal       m_TotalForce;                 ///< total force

   const static EcStringVector   m_theRequiredToolProperties;  ///< the list of required tool properties
   const static EcStringVector   m_theRequiredSoilProperties;  ///< the list of required soil properties
};

#endif // ecMcKyesExcavationInteraction_H_
