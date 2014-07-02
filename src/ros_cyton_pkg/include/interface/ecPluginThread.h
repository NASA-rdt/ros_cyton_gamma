#ifndef ec_PluginThread_H_
#define ec_PluginThread_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginThread.h
/// @class Ec::PluginThread
/// @brief Thread to handle asynchronous plugin data flow
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecAsyncThread.h"

// forward declarations.
namespace Ec {

class Plugin;

class EC_ACTIN_INTERFACE_DECL PluginThread : public AsyncThread
{
public:
   /// constructor
   PluginThread
      (
      EcIODataBroker* pBroker,
      Plugin* pPlugin
      );

   /// process the asynchronous data flow
   void processThread
      (
      );

   Plugin* m_pPlugin; ///< pointer to a output plugin
};

} // namespace Ec

#endif // ec_PluginThread_H_
