#ifndef ecXmlTokens_H_
#define ecXmlTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlTokens.h
/// @brief Token definitions for the xml project.
/// @details namespace EcXml
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>
#include "ecToken.h"

namespace EcXml
{
   ECTOKEN_DEFINITIONS(EC_STABLE_XML_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/cr#")

      // Elements
      (EcBasicTypeToken,    ns + "basicType")
      (EcDefaultToken,      ns + "default")
      (EcEnumTypeToken,     ns + "enumType")
      (EcLinearToken,       ns + "linear")
      (EcMapTypeToken,      ns + "mapType")
      (EcNullToken,         ns + "null")
      (EcOrientationToken,  ns + "orientation")
      (EcSetTypeToken,      ns + "setType")
      (EcPairTypeToken,     ns + "pairType")
      (EcVectorTypeToken,   ns + "vectorType")

      // these elements use parent namespace
      (EcAddLibrariesToken, "addLibraries")
      (EcElementToken,      "element")
      (EcGroupToken,        "group")
      (EcKeyToken,          "key")
      (EcValueToken,        "value")
      (EcFirstToken,        "first")
      (EcSecondToken,       "second")

      // Attributes ... namespace optional
      (EcCountToken,        "size")
      (EcQuaternion0Token,  "q0")
      (EcQuaternion1Token,  "q1")
      (EcQuaternion2Token,  "q2")
      (EcQuaternion3Token,  "q3")
      (EcVectorXToken,      "x")
      (EcVectorYToken,      "y")
      (EcVectorZToken,      "z")
      (EcVersionToken,      "version")
   )
}

#endif // ecXmlTokens_H_
