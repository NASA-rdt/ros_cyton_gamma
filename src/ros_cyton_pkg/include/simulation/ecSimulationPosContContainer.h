#ifndef ecSimulationPosContContainer_H_
#define ecSimulationPosContContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationPosContContainer.h
/// @class EcSimulationPositionControlContainer
/// @brief Holds a container for a position control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <control/ecPosContContainer.h>

/// Holds a container for a position control system.
class EC_ACTIN_SIMULATION_DECL EcSimulationPositionControlContainer : public EcPositionControlContainer
{
public:
   /// default constructor
   EcSimulationPositionControlContainer
      (
      );

   /// destructor
   virtual ~EcSimulationPositionControlContainer
      (
      );

   /// copy constructor
   EcSimulationPositionControlContainer
      (
      const EcSimulationPositionControlContainer& orig
      );

   /// assignment operator
   EcSimulationPositionControlContainer& operator=
      (
      const EcSimulationPositionControlContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSimulationPositionControlContainer& orig
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
   /**
       \return string token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \return cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// get a null object
   /**
       \return uninitialized control system container
   */
   static EcSimulationPositionControlContainer nullObject
      (
      );
};

#endif // ecSimulationPosContContainer_H_
