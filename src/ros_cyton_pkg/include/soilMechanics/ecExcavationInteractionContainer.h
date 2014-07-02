#ifndef ecExcavationInteractionContainer_H_
#define ecExcavationInteractionContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecExcavationInteractionContainer.h
/// @class EcExcavationInteractionContainer
/// @brief An container class for computing bucket excavation forces
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>
#include "ecBaseExcavationInteraction.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EC_ACTIN_SOILMECHANICS_DECL EcExcavationInteractionContainer : public EcXmlVariableElementType<EcBaseExcavationInteraction>
{
public:
   /// default constructor
   EcExcavationInteractionContainer
      (
      );

   /// destructor
   virtual ~EcExcavationInteractionContainer
      (
      );

   /// copy constructor
   EcExcavationInteractionContainer
      (
      const EcExcavationInteractionContainer& orig
      );

   /// assignment operator
   EcExcavationInteractionContainer& operator=
      (
      const EcExcavationInteractionContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExcavationInteractionContainer& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// set the tool properties
   virtual EcBoolean setToolProperties
      (
      const EcToolProperties& toolProps
      );

   /// set the soil properties
   virtual EcBoolean setSoilProperties
      (
      const EcSoilProperties& soilProps
      );

   /// set the parameters
   virtual EcBoolean setParameters
      (
      const EcExcavationParameters& params
      );

   /// compute and return the horizontal force on the bucket
   virtual EcReal horizontalForce
      (
      ) const;

   /// compute and return the vertical force on the bucket
   virtual EcReal verticalForce
      (
      ) const;
};

#endif // ecExcavationInteractionContainer_H_
