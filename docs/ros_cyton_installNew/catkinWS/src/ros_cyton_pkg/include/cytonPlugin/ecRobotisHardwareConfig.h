#ifndef ec_RobotisHardwareConfig_H_
#define ec_RobotisHardwareConfig_H_
//-----------------------------------------------------------------------------
//     Copyright (c) 2011 Energid Technologies. All rights reserved.
//
/// @file ecRobotisHardwareConfig.h
//
/// @class Ec::RobotisHardwareConfig
//
/// @brief Additional servo parameters for Robotis servos
//
//-----------------------------------------------------------------------------
#include <cytonTypes.h>
#include <hardwarePlugin/ecHardwareConfigBase.h>
#include <xml/ecXmlEnumType.h>

namespace Ec
{

/// This class extends HardwareConfigBase to provide additional default
/// parameters for the given hardware servo.
class CYTON_DECL RobotisHardwareConfig : public HardwareConfigBase
{
public:
   ECXMLOBJECT(RobotisHardwareConfig);
   ECXML_XMLOBJECTCREATOR(RobotisHardwareConfig);

   /// List of servo categories that define capabilities.
   enum ServoTypeEnum
   {
      ServoUnknown    = 0,
      Robotis_AX12   = 12,   ///< 1.5 N-m torque servo
      Robotis_AX18   = 18,   ///< 1.8 N-m torque servo

      Robotis_RX10    = 10,   ///< 12.0 kg-cm torque servo
      Robotis_RX24F   = 24,   ///< 26.0 kg-cm torque servo 
      Robotis_RX28    = 28,   ///< 28.0 kg-cm torque servo 
      Robotis_RX64    = 64,   ///< 64.0 kg-cm torque servo

      Robotis_EX106   = 106,  ///< 106  kg-cm torque servo (4096 counts)
      Robotis_EX106P  = 107,  ///< EX-106+

      Robotis_MX28    = 29,   ///< 2.5 N-m torque servo
      Robotis_MX64    = 310,  ///< 6.0 N-m torque servo
      Robotis_MX106   = 320,  ///< 8.4 N-m torque servo
   };
   typedef EcU16 ServoType;

   /// Set default values based upon the servo type.
   void setServoType
      (
      const ServoType type,              ///< [in] Servo type to get values for
      const EcBoolean fromRead = EcFalse ///< [in] When EcTrue, only non-XML-read values are set
      );

   /// @copydoc Ec::HardwareConfigBase::registerComponents()
   void registerComponents
      (
      );

   /// @copydoc Ec::HardwareConfigBase::read(EcXmlReader&)
   EcBoolean read
      (
      EcXmlReader& stream
      );

   /// @copydoc Ec::HardwareConfigBase::velocityFromActin(const EcRealVector&) const
   /// Adds voltage compensation into conversion to hardware units.
   virtual EcReal velocityFromActin
      (
      const EcRealVector& jointVelocities
      ) const;

   EcXmlEnumType<ServoType> modelNumber;
   EcXmlU8  returnDelay;         ///< Return Delay Time = 2x value in usec
   EcXmlU8  maxTemperature;      ///< Temperature limit. If exceeded, LED will blink
   EcXmlU8  minVoltage;          ///< Lowest Voltage allowed w/o setting error flag
   EcXmlU8  maxVoltage;          ///< Highest Voltage allowed w/o setting error flag
   EcXmlU16 maxTorque;           ///< Highest torque value [0,1023]
   EcXmlU8  statusReturnLevel;   ///< Status Return Level. 0=no Ack, 1=Ack on read, 2=Always Ack
   EcXmlU8  alarmShutdown;       ///< Alarm Shutdown. Disables torque when one of the bits get triggered.
   EcXmlU8  torqueEnable;        ///< Torque Enable     
   EcXmlU16 cwAngleLimit;        ///< Clockwise Angle Limit
   EcXmlU16 ccwAngleLimit;       ///< Counter Clockwise Angle Limit

   //RX only
   EcXmlU8  cwComplianceMargin;  ///< Clockwise Compliance Margin
   EcXmlU8  ccwComplianceMargin; ///< Counter Clockwise Compliance Margin
   EcXmlU8  cwComplianceSlope;   ///< Clockwise Compliance Slope
   EcXmlU8  ccwComplianceSlope;  ///< Counter Clockwise Compliance Slope
   
   //MX only
   EcXmlU8  dGain;               ///< Derivative gain for PID control
   EcXmlU8  iGain;               ///< Integral gain for PID control
   EcXmlU8  pGain;               ///< Proportional gain for PID control

   EcXmlU16 punch;               ///< Punch. The limit value of torque being reduced when the output torque is decreased in the Compliance Slope area.
                                 ///< In other words, it is the mimimum torque. The initial value is 32 (0x20) and can be extended up to 1023 (0x3FF).

   mutable EcBoolean m_UseMaxVelocity;     ///< Whether to disregard velocity and use max instead
   mutable EcReal m_VoltageVelocityFactor; ///< Read off servo and used to scale velocity
};

} // namespace Ec

#endif // ec_RobotisHardwareConfig_H_
