#ifndef ecQinsenExcavationInteraction_H_
#define ecQinsenExcavationInteraction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecQinsenExcavationInteraction.h
/// @class EcQinsenExcavationInteraction
/// @brief Defines a class for computing bulldoze blade excavation force
///        using Qinsen model
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseExcavationInteraction.h"
#include "ecExcavationParameters.h"

#include <foundCommon/ecDataMap.h>

/// Defines a class for computing bulldoze blade excavation force using Qinsen model
class EC_ACTIN_SOILMECHANICS_DECL EcQinsenExcavationInteraction : public EcBaseExcavationInteraction
{
public:
   /// default constructor
   EcQinsenExcavationInteraction
      (
      );

   /// destructor
   virtual ~EcQinsenExcavationInteraction
      (
      );

   /// copy constructor
   EcQinsenExcavationInteraction
      (
      const EcQinsenExcavationInteraction& orig
      );

   /// assignment operator
   EcQinsenExcavationInteraction& operator=
      (
      const EcQinsenExcavationInteraction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcQinsenExcavationInteraction& orig
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
   static EcQinsenExcavationInteraction nullObject
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

   /// compute the horizonal and vertical forces
   virtual void computeForces
      (
      ) const;
protected:
   // non-XML data
   EcReal               m_BladeWidth;                 ///< the blade width
   EcReal               m_BladeHeight;                ///< the blade height
   EcReal               m_BladeRadius;                ///< the radius of curvature of the blade
   EcReal               m_BladeAngle;                 ///< the angle of curvature of the blade
   EcReal               m_SoilCohesion;               ///< the soil cohesion
   EcReal               m_SoilToolAdhesion;           ///< the soil-tool adhesion
   EcReal               m_SoilInternalFrictionAngle;  ///< the soil interal friction angle
   EcReal               m_SoilExternalFrictionAngle;  ///< the soil external friction angle
   EcReal               m_SoilSpecificMass;           ///< the soil specific mass
   EcReal               m_SoilShearPlaneFailureAngle; ///< the soil shear-plane failure angle
   EcReal               m_CutSoilCohesion;            ///< the cut soil cohesion
   EcReal               m_CutSoilSpecificMass;        ///< the cut soil specific mass
   EcReal               m_CutSoilAccumulationAngle;   ///< the cut soil accumulation angle
   EcExcavationParameters  m_Params;                  ///< the excavation parameters

   // internal (intermediate) data
   mutable EcReal       m_HorizontalForce;            ///< horizontal force
   mutable EcReal       m_VerticalForce;              ///< vertical force

   const static EcStringVector   m_theRequiredToolProperties;  ///< the list of required tool properties
   const static EcStringVector   m_theRequiredSoilProperties;  ///< the list of required soil properties
};

#endif // ecQinsenExcavationInteraction_H_
