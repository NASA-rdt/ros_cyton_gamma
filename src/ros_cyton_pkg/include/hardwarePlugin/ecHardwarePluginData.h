#ifndef ec_HardwarePluginData_H_
#define ec_HardwarePluginData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwarePluginData.h
/// @class Ec::HardwarePluginData
/// @brief XML class used to hold hardware configuration.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include "ecHardwareConfigBaseVector.h"
#include "ecHardwarePluginTypes.h"
#include <xml/ecXmlCompType.h>

namespace Ec
{
/// XML class used to hold hardware configuration.
class EC_ACTIN_HWPLUGIN_DECL HardwarePluginData : public EcXmlCompoundType
{
public:
   /// xml object methods
   ECXMLOBJECT(HardwarePluginData);
   /// declaration of xmlObjectCreator()
   ECXML_XMLOBJECTCREATOR(HardwarePluginData);

   /// @copydoc EcXmlCompoundType
   virtual void registerComponents
      (
      );

   HardwareConfigBaseVector m_vpHardwareConfig; ///< Vector container for Ec::HardwareConfigBase
   EcXmlU32 m_InitAndShutdownMode;              ///< initiation and shutdown mode
   EcXmlReal m_FeedbackGain;                    ///< feedback gain
   EcXmlU32 m_ManipIndex;                       ///< manipulator index
   EcXmlU32 m_StatusUpdateInMs;                 ///< Frequency to query h/w status
   EcXmlU32 m_JointControlDescriptorID;         ///< Joint control descriptor ID
   EcXmlString m_PortName;                      ///< Name of port hardware is connected to
};

} // namespace Ec

#endif // ec_HardwarePluginData_H_
