//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file remoteCommandPluginTemplateInst.ipp
//
//------------------------------------------------------------------------------
#include "remoteCommandPlugin.h"
#include <pluginCommon/ecTransportHandle.h>
#include <networkPlugin/ecNetworkSerialization.h>

//------------------------------------------------------------------------------
template <typename T>
EcBoolean remoteCommandPlugin::sendToNetwork
   (
   const EcU32 msgType,
   const T& msg
   )
{
   if(!isConnected() || !Ec::network::sendToNetwork(m_TransportPtr.get(), msgType, msg))
   {
      terminate();
      return EcFalse;
   }
   return EcTrue;
}
