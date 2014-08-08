#ifndef ec_SimulationThread_H_
#define ec_SimulationThread_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationThread.h
/// @class Ec::SimulationThread
/// @brief Thread to handle asynchronous simulation data flow
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecAsyncThread.h"

namespace Ec {

class EC_ACTIN_INTERFACE_DECL SimulationThread : public AsyncThread
{
public:
   /// constructor
   explicit SimulationThread
      (
      EcIODataBroker* pBroker
      );

   /// set the update period in MS
   void setUpdatePeriodInMS
      (
      EcU32 value
      );

protected:
   /// process the asynchronous event
   void processThread
   (
   );
};

} // namespace Ec

#endif // ec_SimulationThread_H_
