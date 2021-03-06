#ifndef ecBalovnevExcavationInteraction_H_
#define ecBalovnevExcavationInteraction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBalovnevExcavationInteraction.h
/// @class EcBalovnevExcavationInteraction
/// @brief Defines a class for computing blade excavation force
///        using Balovnev model
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseExcavationInteraction.h"
#include "ecExcavationParameters.h"

#include <foundCommon/ecDataMap.h>

/// Defines a class for computing blade excavation force using Balovnev model
class EC_ACTIN_SOILMECHANICS_DECL EcBalovnevExcavationInteraction : public EcBaseExcavationInteraction
{
public:
   /// default constructor
   EcBalovnevExcavationInteraction
      (
      );

   /// destructor
   virtual ~EcBalovnevExcavationInteraction
      (
      );

   /// copy constructor
   EcBalovnevExcavationInteraction
      (
      const EcBalovnevExcavationInteraction& orig
      );

   /// assignment operator
   EcBalovnevExcavationInteraction& operator=
      (
      const EcBalovnevExcavationInteraction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBalovnevExcavationInteraction& orig
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
   static EcBalovnevExcavationInteraction nullObject
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

   /// compute intermediate data
   virtual void computeIntermediateData
      (
      );

protected:
   // non-XML data
   EcReal               m_BladeWidth;                 ///< the blade width
   EcReal               m_BladeHeight;                ///< the blade height
   EcReal               m_SoilCohesion;               ///< the soil cohesion
   EcReal               m_SoilInternalFrictionAngle;  ///< the soil interal friction angle
   EcReal               m_SoilExternalFrictionAngle;  ///< the soil external friction angle
   EcReal               m_SoilSpecificMass;           ///< the soil specific mass
   EcReal               m_CutSoilSpecificMass;        ///< the cut soil specific mass
   EcExcavationParameters  m_Params;                  ///< the excavation parameters

   // internal (intermediate) data
   EcReal               m_A;                          ///< internal parameter A
   EcReal               m_K;                          ///< internal parameter K
   mutable EcReal       m_HorizontalForce;            ///< horizontal force

   const static EcStringVector   m_theRequiredToolProperties;  ///< the list of required tool properties
   const static EcStringVector   m_theRequiredSoilProperties;  ///< the list of required soil properties
};

#endif // ecBalovnevExcavationInteraction_H_
