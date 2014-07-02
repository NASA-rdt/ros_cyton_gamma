#ifndef ecRendCoreTokens_H_
#define ecRendCoreTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecRendCoreTokens.h
/// @brief Defines tokens for render core.
/// @details namespace EcRenderCore
//
//------------------------------------------------------------------------------
#include <render/render_config.h>
#include <xml/ecToken.h>

/// Defines tokens for render core.
namespace EcRenderCore
{
   ECTOKEN_DEFINITIONS(EC_RENDER_RENDCORE_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/rn#")

      // Elements
      (EcBackgroundColorToken,        ns + "backgroundColor")
      (EcHeightToken,                 ns + "height")
      (EcNumberChannelsToken,         ns + "numberChannels")
      (EcRenderWindowParametersToken, ns + "renderWindowParameters")
      (EcUpperLeftCornerToken,        ns + "upperLeftCorner")
      (EcUsePBufferingToken,          ns + "usePBuffering")
      (EcWidthToken,                  ns + "width")
   )
}

#endif // ecRendCoreTokens_H_
