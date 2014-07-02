#ifndef ecConvertSimulationTokens_H_
#define ecConvertSimulationTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecConvertSimulationTokens.h
/// @brief Holds tokens for the convert project
/// @details namespace EcConvertSimulation
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecToken.h>

/// Holds tokens for the convert project
namespace EcConvertSimulation
{
   ECTOKEN_DEFINITIONS(EC_ACTIN_CONVERTSIMULATION_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/sm#")

      // Elements
      (EcSimulationAllLoaderToken, ns + "simulationAllLoader")
      (EcSimulationExpanderToken,  ns + "simulationExpander")
   )
}

#endif // ecConvertSimulationTokens_H_
