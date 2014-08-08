//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecTransportHandleTemplateInst.ipp
/// @brief Explicit [pre-] template instantiations of types we expose.
//
//------------------------------------------------------------------------------

#define FWD_DECL_SENDTONETWORK(T) \
    template EcBoolean EC_PLUGINS_PLUGINCOMMON_DECL Ec::network::TransportHandle::sendToNetwork<T>(const EcU32, const T&)

// Explicit pre-instantiate certain types
FWD_DECL_SENDTONETWORK(EcManipulatorEndEffectorPlacementVector);
FWD_DECL_SENDTONETWORK(EcManipulatorSystemState);
FWD_DECL_SENDTONETWORK(EcXmlBoolean);
FWD_DECL_SENDTONETWORK(EcXmlU32);
FWD_DECL_SENDTONETWORK(EcXmlU32U32Pair);
FWD_DECL_SENDTONETWORK(EcXmlRealVectorVector);

#undef FWD_DECL_SENDTONETWORK
