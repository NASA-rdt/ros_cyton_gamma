#ifndef ec_HardwareConfigBase_H_
#define ec_HardwareConfigBase_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwareConfigBase.h
/// @class Ec::HardwareConfigBase
/// @brief Individual parameters used to configure hardware.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

#include "ecHardwareCalibrationPointVector.h"

namespace Ec
{

class EC_ACTIN_HWPLUGIN_DECL HardwareConfigBase : public EcXmlCompoundType
{
public:
   /// xml object methods
   ECXMLOBJECT(HardwareConfigBase);
   /// declaration for xmlObjectCreator()
   ECXML_XMLOBJECTCREATOR(HardwareConfigBase);

   /// @copydoc EcXmlCompoundType::registerComponents()
   virtual void registerComponents
      (
      );

   /// @copydoc EcXmlCompoundType::read(EcXmlReader&)
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Convert an Actin joint angle to a servo position.  Doesn't map joint index.
   /// @param[in] joint  Single joint angle to convert
   /// @return    EcReal Converted servo position
   EcReal positionFromActin
      (
      const EcReal joint
      ) const;

   /// Converts Actin joint angle to a servo position.
   /// @param[in] jointCommands Vector of joint angles
   /// @return    EcReal        Converted servo position
   virtual EcReal positionFromActin
      (
      const EcRealVector& jointCommands
      ) const;

   /// Converts Actin joint velocity to a servo rate.
   /// @param[in] jointVelocities Vector of joint rates
   /// @return    EcReal          Converted servo rate
   virtual EcReal velocityFromActin
      (
      const EcRealVector& jointVelocities
      ) const;

   /// Converts servo position to Actin joint angle.
   /// @param[out] jointCommands Vector of joint angles
   /// @param[in]  value         Current servo position
   virtual void positionToActin
      (
       EcRealVector& jointCommands,
      const EcReal value
      ) const;

   /// Converts servo rate to Actin joint velocities.
   /// @param[out] jointVelocities Vector of joint rates
   /// @param[in]  value           Current servo rate
   virtual void velocityToActin
      (
      EcRealVector& jointVelocities,
      const EcReal value
      ) const;

   /// Based on current servo settings, makes a determination on whether
   /// the servo has reached its goal position.
   /// @param[in] goalCommands  Target positions
   /// @param[in] jointCommands Current servo positions
   /// @return    EcBoolean     Success or failure of command
   virtual EcBoolean isFinished
      (
      const EcRealVector& goalCommands,
      const EcRealVector& jointCommands
      ) const;

   EcXmlU8 jointMapIndex;           ///< Mapping to data within joint command vector
   EcXmlU8 servoID;                 ///< Unique identifier for servo
   EcXmlReal maxVelocity;           ///< Maximum configured joint velocity
   EcXmlReal maxAcceleration;       ///< Max configured joint acceleration
   EcXmlReal offsetValue;           ///< Offset value applied to incoming commands
   EcXmlReal hardwareToActinFactor; ///< Conversion factor from hw position units to Actin(radians)
   EcXmlReal hardwareVelocityToActinFactor; ///< Conversion from hw velocity units to Actin(rad/sec)
   EcXmlBoolean invert;             ///< Polarity - true for negative
   HardwareCalibrationPointVector actinToHardwareCalibrationPoints;  ///< Vector of calibration points, each with data of Actin joint angle (radians) and Hardware value
};

} // namespace Ec

#endif // ec_HardwareConfigBase_H_
