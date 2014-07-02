#ifndef ecBaseSimulationLoader_H_
#define ecBaseSimulationLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseSimulationLoader.h
/// @class EcBaseSimulationLoader
/// @brief Holds a base class for loading systems from various file types.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecSimulationExpander.h"
#include <convertSystem/ecBaseSystemLoader.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

class EcSystemSimulation;
class EcVisualizableStatedSystem;

/// Holds a base class for loading systems from various file types.
class EC_ACTIN_CONVERTSIMULATION_DECL EcBaseSimulationLoader : public EcBaseSystemLoader
{
public:
   /// default constructor
   EcBaseSimulationLoader
      (
      );

   /// destructor
   virtual ~EcBaseSimulationLoader
      (
      );

   /// copy constructor
   EcBaseSimulationLoader
      (
      const EcBaseSimulationLoader& orig
      );

   /// assignment operator
   EcBaseSimulationLoader& operator=
      (
      const EcBaseSimulationLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseSimulationLoader& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the vec simulation expander
   /**
   \retval simulation expander
   */
   virtual const EcSimulationExpander& simulationExpander
      (
      ) const;

   /// sets the vec physical system expander
   /**
   \param[in] physicalSystemExpander physical system expander
   */
   virtual void setSimulationExpander
      (
      const EcSimulationExpander& physicalSystemExpander
      );

   /// return a string token
   /**
   \return token
   */
   virtual const EcToken& token
      (
      ) const = 0;

   /// load a file and build a simulation
   /**
   \param[out] simulation new simulation
   \param[in] filename filename for building simulation
   \retval error status
   */
   virtual EcBoolean loadSimulationFromFile
      (
      EcSystemSimulation&  simulation,
      const EcString& filename
      ) const;

protected:
   /// Expands physical components into stated systems and simulations
   EcSimulationExpander     m_SimulationExpander;
};

#endif // ecBaseSimulationLoader_H_
