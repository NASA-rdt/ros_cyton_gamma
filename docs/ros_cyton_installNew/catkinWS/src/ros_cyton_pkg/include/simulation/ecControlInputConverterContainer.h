#ifndef ecControlInputConverterContainer_H_
#define ecControlInputConverterContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecControlInputConverterContainer.h
/// @class EcControlInputConverterContainer
/// @brief Holds a container for a system that converts the control
///        torques to control inputs.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseControlInputConverter.h"

/// Holds a container for a system that converts the control torques to control inputs.
class EC_ACTIN_SIMULATION_DECL EcControlInputConverterContainer : public EcBaseExpressionTreeContainer<EcBaseControlInputConverter>
{
public:
   /// default constructor
   EcControlInputConverterContainer
      (
      );

   /// destructor
   virtual ~EcControlInputConverterContainer
      (
      );

   /// copy constructor
   EcControlInputConverterContainer
      (
      const EcControlInputConverterContainer& orig
      );

   /// assignment operator
   EcControlInputConverterContainer& operator=
      (
      const EcControlInputConverterContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlInputConverterContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
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

   /// calculates control inputs
   virtual void calculateControlInputs
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      const EcManipulatorTorqueVector& manipulatorTorqueVector,
      EcManipulatorControlInputVector& manipulatorControlInputVector
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcControlInputConverterContainer& other,
      const EcStatedSystem& otherStatedSystem
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcControlInputConverterContainer nullObject
      (
      );
};

#endif // ecControlInputConverterContainer_H_
