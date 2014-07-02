#ifndef ec_HardwareConfigBaseVector_H_
#define ec_HardwareConfigBaseVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwareConfigBaseVector.h
/// @class Ec::HardwareConfigBaseVector
/// @brief XML Vector container for Ec::HardwareConfigBase
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include "ecHardwareConfigBase.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
#  pragma warning(disable:4661)
#endif

namespace Ec
{

/// XML Vector container for Ec::HardwareConfigBase
class EC_ACTIN_HWPLUGIN_DECL HardwareConfigBaseVector : public EcXmlVariableVectorType<HardwareConfigBase>
{
public:
   /// xml object methods
   ECXMLOBJECT(HardwareConfigBaseVector);

   /// @copydoc EcXmlVariableVectorType
   void registerComponentCreators
      (
      );

   /// Converts Actin joint angle to a servo position.
   /// @param[in] jointCommands Vector of joint angles
   /// @param[out] values       Converted servo positions
   virtual void positionFromActin
      (
      const EcRealVector& jointCommands,
      EcRealVector& values
      ) const;

   /// Converts Actin joint velocity to a servo rate.
   /// @param[in] jointVelocities Vector of joint rates
   /// @param[out] values         Converted servo rates
   virtual void velocityFromActin
      (
      const EcRealVector& jointVelocities,
      EcRealVector& values
      ) const;

   /// Converts servo position to Actin joint angle.
   /// @param[out] jointCommands Vector of joint angles
   /// @param[in]  values        Current servo positions
   virtual void positionToActin
      (
       EcRealVector& jointCommands,
      const EcRealVector& values
      ) const;

   /// Converts servo rate to Actin joint velocities.
   /// @param[out] jointVelocities Vector of joint rates
   /// @param[in]  values          Current servo rates
   virtual void velocityToActin
      (
      EcRealVector& jointVelocities,
      const EcRealVector& values
      ) const;
};

} // namespace Ec

#endif // ec_HardwareConfigBaseVector_H_
