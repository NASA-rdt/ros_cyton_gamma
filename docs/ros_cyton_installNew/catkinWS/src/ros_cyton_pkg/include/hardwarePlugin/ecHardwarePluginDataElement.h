#ifndef ec_HardwarePluginDataElement_H_
#define ec_HardwarePluginDataElement_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwarePluginDataElement.h
/// @class Ec::HardwarePluginData
/// @brief XML pointer class to Ec::HardwarePluginData
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include "ecHardwarePluginData.h"
#include <xml/ecXmlVarElemType.h>

namespace Ec
{
/// XML pointer class to Ec::HardwarePluginData
class EC_ACTIN_HWPLUGIN_DECL HardwarePluginDataElement : public EcXmlVariableElementType<HardwarePluginData>
{
public:
   /// xml object methods
   ECXMLOBJECT(HardwarePluginDataElement);

   /// @copydoc EcXmlVariableElementType
   virtual void registerComponentCreators
      (
      );
};

} // namespace Ec

#endif // ec_HardwarePluginDataElement_H_
