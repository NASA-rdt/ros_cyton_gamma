#ifndef ec_HardwareCalibrationPoint_H_
#define ec_HardwareCalibrationPoint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwareCalibrationPoint.h
/// @class Ec::HardwareCalibrationPoint
/// @brief Individual parameters used to configure hardware.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

namespace Ec
{

/// Individual parameters used to configure hardware.
class EC_ACTIN_HWPLUGIN_DECL HardwareCalibrationPoint : public EcXmlCompoundType
{
public:
   /// xml object methods
   ECXMLOBJECT(HardwareCalibrationPoint);
   /// declaration for xmlObjectCreator()
   ECXML_XMLOBJECTCREATOR(HardwareCalibrationPoint);

   /// contructor from actinJointValue and hardwareJointValue
   HardwareCalibrationPoint
      (
      const EcXmlReal& actinJointValue,
      const EcXmlReal& hardwareJointValue
      );

   /// @copydoc EcXmlCompoundType::registerComponents()
   virtual void registerComponents
      (
      );

   /// @copydoc EcXmlCompoundType::read(EcXmlReader&)
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// compare if the lhs actin joint value is less than rhs
   static EcBoolean actinJointValueCompareLess (const HardwareCalibrationPoint& lhs, const HardwareCalibrationPoint& rhs)
   {
      return (lhs.m_ActinJointValue < rhs.m_ActinJointValue);
   }

   /// compare if the lhs actin joint value is equal to rhs
   static EcBoolean actinJointValueCompareEquality (const HardwareCalibrationPoint& lhs, const HardwareCalibrationPoint& rhs)
   {
      return (lhs.m_ActinJointValue == rhs.m_ActinJointValue);
   }

   /// compare if the lhs hardware joint value is less than rhs
   static EcBoolean hardwareJointValueCompareLess(const HardwareCalibrationPoint& lhs, const HardwareCalibrationPoint& rhs)
   {
      return (lhs.m_HardwareJointValue < rhs.m_HardwareJointValue);
   }

   /// compare if the lhs hardware joint value is equal to rhs
   static EcBoolean hardwareJointValueCompareGreater(const HardwareCalibrationPoint& lhs, const HardwareCalibrationPoint& rhs)
   {
      return (lhs.m_HardwareJointValue > rhs.m_HardwareJointValue);
   }

   EcXmlReal m_ActinJointValue;      ///< Joint value in Actin units
   EcXmlReal m_HardwareJointValue;   ///< Joint value in hardware units
};

} // namespace Ec

#endif // ec_HardwareCalibrationPoint_H_
