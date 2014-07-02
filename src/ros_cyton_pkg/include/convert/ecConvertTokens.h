#ifndef ecConvertTokens_H_
#define ecConvertTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecConvertTokens.h
/// @brief Holds tokens for the convert project
/// @details namespace EcConvert
//
//------------------------------------------------------------------------------
#include <render/render_config.h>
#include <xml/ecToken.h>

/// Holds tokens for the convert project
namespace EcConvert
{
   ECTOKEN_DEFINITIONS(EC_RENDER_CONVERT_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns_, "http://www.energid.com/namespace/sm#")

      // Elements
      (EcSystemDtedLoaderToken,    ns_ + "systemDtedLoader")
      (EcSystemOsgLoaderToken,     ns_ + "systemOsgLoader")
      (EcSystemOsgS3dsLoaderToken, ns_ + "SystemOsgS3dsLoader")
      (EcSystemSdtedLoaderToken,   ns_ + "systemSdtedLoader")
   )
}

#endif // ecConvertTokens_H_
