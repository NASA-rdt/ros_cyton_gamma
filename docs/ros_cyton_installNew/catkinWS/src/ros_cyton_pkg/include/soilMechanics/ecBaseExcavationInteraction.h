#ifndef ecBaseExcavationInteraction_H_
#define ecBaseExcavationInteraction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseExcavationInteraction.h
/// @class EcBaseExcavationInteraction
/// @brief An abstract base class for computing excavation forces
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecDataMap.h>

/// cotangent of x
extern EcReal cot(EcReal x);

/// type definition of EcToolProperties
typedef EcDataMap EcToolProperties;
/// type definition of EcSoilProperties
typedef EcDataMap EcSoilProperties;

// forward declarations
class EcExcavationParameters;

/// An abstract base class for computing excavation forces
class EC_ACTIN_SOILMECHANICS_DECL EcBaseExcavationInteraction : public EcXmlCompoundType
{
public:
   /// Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcBaseExcavationInteraction);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// return the list of all necessary tool properties for this excavation interaction
   virtual const EcStringVector& requiredToolProperties
      (
      ) const=0;

   /// return the list of all necessary soil properties for this excavation interaction
   virtual const EcStringVector& requiredSoilProperties
      (
      ) const=0;

   /// get the tool properties
   virtual const EcToolProperties& toolProperties
      (
      ) const;

   /// set the tool properties. Returns true if toolProps contains all necessary tool properties or false otherwise. Call requiredToolProperties() for the list of required tool properties.
   virtual EcBoolean setToolProperties
      (
      const EcToolProperties& toolProps
      );

   /// set the soil properties. Returns true if soilProps contains all necessary soil properties or false otherwise. Call requiredSoilProperties() for the list of required tool properties.
   virtual EcBoolean setSoilProperties
      (
      const EcSoilProperties& soilProps
      )=0;

   /// set the parameters.
   virtual EcBoolean setParameters
      (
      const EcExcavationParameters& params
      )=0;

   /// compute and return the horizontal force on the bucket
   virtual EcReal horizontalForce
      (
      ) const=0;

   /// compute and return the vertical force on the bucket
   virtual EcReal verticalForce
      (
      ) const=0;

   /// read object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

protected:
   /// assign the tool properties from the data map. Returns true if all necessary tool properties are assigned.
   virtual EcBoolean assignToolProperties
      (
      )=0;
protected:
   /// the tool properties
   EcToolProperties      m_ToolProperties;
};

#endif // ecBaseExcavationInteraction_H_
