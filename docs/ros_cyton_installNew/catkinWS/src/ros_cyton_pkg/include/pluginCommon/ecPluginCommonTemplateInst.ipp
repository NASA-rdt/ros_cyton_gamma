//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginCommonTemplateInst.ipp
/// @brief Template instantiations for general purpose serialization and
///        deserialization methods to send data across the network.
/// @details Ec::network::TransportHandle instantiations
//
//------------------------------------------------------------------------------
#include "ecTransportHandle.h"
#include <xml/ecXmlObjectReaderWriter.h>

namespace Ec { namespace network {

//------------------------------------------------------------------------------
// TransportHandle::deserialize
// Takes a string and deserializes it into an object.
//------------------------------------------------------------------------------
template <typename T>
EcBoolean
TransportHandle::deserialize
   (
   T& value
   ) const
{
   if(!EcXmlObjectReaderWriter::readFromBuffer(value, m_pNetwork->inputString()))
   {
      EcPrint(Error) << "Unable to convert network data to " << typeid(T).name() << std::endl;
      return EcFalse;
   }
   return EcTrue;
}


//------------------------------------------------------------------------------
// TransportHandle::sendToNetwork
// General method to serialize data, generate header and write to network.
//------------------------------------------------------------------------------
template <typename T>
EcBoolean
TransportHandle::sendToNetwork
   (
   const MessageType msgType,
   const T& value
   )
{
   if(!EcXmlObjectReaderWriter::writeToBuffer(value, m_pNetwork->outputString()))
   {
      EcPrint(Error) << "Unable to serialize " << typeid(T).name() << std::endl;
      return EcFalse;
   }
   return sendToNetwork(msgType, m_pNetwork->outputString());
}

} } // namespace Ec::network
