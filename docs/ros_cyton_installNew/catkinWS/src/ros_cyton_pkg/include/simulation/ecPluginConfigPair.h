#ifndef ecPluginConfigPair_H_
#define ecPluginConfigPair_H_
//------------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginConfigPair.h
/// @class EcPluginConfigPair
/// @brief Xml string pair that sets custom tags
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecXmlEmbeddedString.h>
#include <xml/ecXmlPairType.h>

/// type definition of EcXmlStringEStringPair
typedef EcXmlPairType<EcXmlString, EcXmlEmbeddedString> EcXmlStringEStringPair;

/// Xml string pair that sets custom tags
class EC_ACTIN_SIMULATION_DECL EcPluginConfigPair : public EcXmlStringEStringPair
{
public:
   /// Default constructor
   EcPluginConfigPair
      (
      );
};

#endif // ecPluginConfigPair_H_
