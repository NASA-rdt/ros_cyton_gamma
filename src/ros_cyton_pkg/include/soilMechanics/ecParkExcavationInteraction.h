#ifndef ecParkExcavationInteraction_H_
#define ecParkExcavationInteraction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecParkExcavationInteraction.h
/// @class EcParkExcavationInteraction
/// @brief Defines a class for computing bucket excavation force
///        using Park model
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseExcavationInteraction.h"
#include "ecExcavationParameters.h"

#include <foundCommon/ecDataMap.h>

/// Defines a class for computing bucket excavation force using Park model
class EC_ACTIN_SOILMECHANICS_DECL EcParkExcavationInteraction : public EcBaseExcavationInteraction
{
public:
   /// default constructor
   EcParkExcavationInteraction
      (
      );

   /// destructor
   virtual ~EcParkExcavationInteraction
      (
      );

   /// copy constructor
   EcParkExcavationInteraction
      (
      const EcParkExcavationInteraction& orig
      );

   /// assignment operator
   EcParkExcavationInteraction& operator=
      (
      const EcParkExcavationInteraction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParkExcavationInteraction& orig
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
   static EcParkExcavationInteraction nullObject
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
   EcReal               m_ToolAngle;                  ///< the tool angle
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

#endif // ecParkExcavationInteraction_H_
