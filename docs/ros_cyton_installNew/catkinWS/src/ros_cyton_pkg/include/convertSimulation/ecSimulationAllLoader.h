#ifndef ecSimulationAllLoader_H_
#define ecSimulationAllLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationAllLoader.h
/// @class EcSystemAllLoader
/// @brief Holds a tool for loading simulations from various file types.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseSimulationLoader.h"
#include <convertSystem/ecSystemAllLoader.h>

class EcXmlReader;

/// Holds a tool for loading simulations from various file types.
class EC_ACTIN_CONVERTSIMULATION_DECL EcSimulationAllLoader : public EcBaseSimulationLoader
{
public:
   /// default constructor
   EcSimulationAllLoader
      (
      );

   /// destructor
   virtual ~EcSimulationAllLoader
      (
      );

   /// copy constructor
   EcSimulationAllLoader
      (
      const EcSimulationAllLoader& orig
      );

   /// assignment operator
   EcSimulationAllLoader& operator=
      (
      const EcSimulationAllLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSimulationAllLoader& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// @copydoc EcBaseSimulationLoader::token()
   virtual const EcToken& token
      (
      ) const;

   /// load a file and build a simulation
   /**
   \param[out]  simulation new simulation
   \param[in]  filename   filename for building simulation
   \retval EcBoolean  error status
   */
   virtual EcBoolean loadSimulationFromFile
      (
      EcSystemSimulation& simulation,
      const EcString& filename
      ) const;

   /// load from a stram and build a simulation
   /**
   \param[out]  simulation new simulation
   \param[in,out]  stream     file stream for building simulation
   \retval EcBoolean  error status
   */
   virtual EcBoolean loadSimulationFromStream
      (
      EcSystemSimulation& simulation,
      EcXmlReader& stream
      ) const;

   /// load a file and build a visualizable stated system
   /**
   \param[out] visStatedSystem stated system
   \param[in] filename filename for building stated system
   \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem& visStatedSystem,
      const EcString& filename
      ) const;

   /// a token unique to this class
   /**
   \return token
   */
   static const EcToken& classToken
      (
      );

   /// get an empty object
   /**
   \return simulation loader
   */
   static EcSimulationAllLoader nullObject
      (
      );

protected:
   /// load an XML file and build a simulation
   /**
   \param[out] simulation simulation
   \param[in] filename filename for building simulation
   \retval error status
   */
   virtual EcBoolean loadSimulationFromXmlFile
      (
      EcSystemSimulation& simulation,
      const EcString& filename
      ) const;

protected:
   EcSystemAllLoader m_SystemAllLoader;  ///< Holds a tool for loading systems from various file types.
};

#endif // ecSimulationAllLoader_H_
