#ifndef ec_RobotisPluginData_H_
#define ec_RobotisPluginData_H_
//     Copyright (c) 2011 Energid Technologies. All rights reserved. ////
//
// Filename:    ecRobotisPluginData.h
//
// Contents:    Ec::RobotisPluginData class
//
/////////////////////////////////////////////////////////////////////////
#include <base/cytonPluginData.h>
#include <foundCore/ecMutex.h>
#include <cytonTypes.h>

namespace Ec
{

struct CommandStruct;
class RobotisHardwareConfig;

class RobotisPluginData : public cyton::PluginData
{
public:
   typedef std::vector<EcU8Vector> EcU8VectorVector;
   enum ParamTypeEnum
   {
      // Addresses 0x00-0x17 are in EEPROM. They persist after power down.
      ModelNumber           = 0x00,   ///< (R ,16) Servo type
      FirmwareVersion       = 0x02,   ///< (R ) Servo firmware rev
      ServoIDAddress        = 0x03,   ///< (RW) Unique ID value from 1-254
      ServoBaudRate         = 0x04,   ///< (RW) Comm rate for the servo
      ReturnDelayTime       = 0x05,   ///< (RW) Set delay between cmd and response
      CWAngleLimit          = 0x06,   ///< (RW,16) Min angle setting
      CCWAngleLimit         = 0x08,   ///< (RW,16) Max angle setting
      MaxTempLimit          = 0x0B,   ///< (RW) Limit before setting flag in status or alarm
      MinVoltageLimit       = 0x0C,   ///< (RW) Limit before setting flag in status or alarm
      MaxVoltageLimit       = 0x0D,   ///< (RW) Limit before setting flag in status or alarm
      MaxTorque             = 0x0E,   ///< (RW,16) Copies value to TorqueLimit in RAM on power up
      StatusReturnLevel     = 0x10,   ///< (RW) When should status be returned
      AlarmLED              = 0x11,   ///< (RW) Bits on which errors should turn on LED
      AlarmShutdown         = 0x12,   ///< (RW) Bits on which errors should turn off torque
      
      // The following addresses lie within the RAM Area
      TorqueEnable          = 0x18,   ///< (RW) Whether torque control is on or off
      LEDOnOff              = 0x19,   ///< (RW) Whether LED is on or off

      //RX only
      CWComplianceMargin    = 0x1A,   ///< (RW) Number of ticks for margin
      CCWComplianceMargin   = 0x1B,   ///< (RW) Number of ticks for margin
      CWComplianceSlope     = 0x1C,   ///< (RW) Number of ticks for slope
      CCWComplianceSlope    = 0x1D,   ///< (RW) Number of ticks for slope
      
      //MX only
      DGain                 = 0x1A,   ///< (RW) Derivative gain for PID control
      IGain                 = 0x1B,   ///< (RW) Integral gain for PID control
      PGain                 = 0x1C,   ///< (RW) Proportional gain for PID control
      
      GoalPosition          = 0x1E,   ///< (RW,16) Location to move to
      MovingSpeed           = 0x20,   ///< (RW,16) Speed to move to goal position
      TorqueLimit           = 0x22,   ///< (RW,16) 
      CurrentPosition       = 0x24,   ///< (R ,16) Current position
      CurrentSpeed          = 0x26,   ///< (R ,16) Current speed
      CurrentLoad           = 0x28,   ///< (R ,16) % of load on servo
      CurrentVoltage        = 0x2A,   ///< (R ) Current voltage
      CurrentTemperature    = 0x2B,   ///< (R ) Current temperature
      InstructionRegistered = 0x2C,   ///< (RW) Whether a write has been registered
      CurrentlyMoving       = 0x2E,   ///< (R ) True when moving to goal position
      LockEEPROM            = 0x2F,   ///< (RW) Disables writes to EEPROM addresses
      Punch                 = 0x30,   ///< (RW,16) Minimum torque for compliance slope
   };

   RobotisPluginData
      (
      );

   RobotisPluginData
      (
      const RobotisPluginData& orig
      );

   ECXMLOBJECT_CLONE(RobotisPluginData)
   ECXMLOBJECT_EQUALITY(RobotisPluginData)
   ECXMLOBJECT_NEWOBJECT(RobotisPluginData)
   ECXML_XMLOBJECTCREATOR(RobotisPluginData);
   ECXML_DECLARE_TOKENS;

   /// @copydoc EcXmlCompoundType::registerComponents()
   void registerComponents
      (
      );

   /// @copydoc cyton::PluginData::initSerial()
   EcBoolean initSerial
      (
      );

   /// Adjusts settings for servos based upon configuration and servo type.
   void initMaxVelocity
      (
      );

   /// General method to read a number of bytes from each servo at the specified location.
   /// @param[in] param Location to read
   /// @param[in] dataSize Number of bytes to read per servo
   /// @param[out] results Vector of results
   /// @return EcBoolean Success or failure of read command
   EcBoolean readDataCommand
      (
      const ParamTypeEnum param,
      const EcU8 dataSize,
      EcU8VectorVector& results
      ) const;

   // Used as part of cytonSetup application for verifying data and writing.
   EcBoolean CYTON_DECL checkEEPROMCommand();
   EcBoolean CYTON_DECL checkModelNumberCommand();
   EcBoolean CYTON_DECL setConfigCommand();

   EcBoolean checkConfigCommand
      (
      );

   EcU32Vector checkTorqueCommand
      (
      const EcU8 transitionTemperature,
      EcU16Vector gripperServos,
      const EcBoolean OneAtATime = EcTrue,
      EcU8Vector* const pvStatusBytes = EcNULL
      );

   EcBoolean checkFinishedCommand
      (
      ) const;

   EcBoolean getPositionCommand
      (
      EcRealVector& jointAngles,
      EcRealVector& jointVelocities
      );

   EcBoolean pingCommand
      (
      );

   EcBoolean setGripperPosition
      (
      const EcU8 id,
      const EcU16 pos 
      );

   EcBoolean setPositionCommand
      (
      const EcRealVector& jointAngles,
      const EcRealVector& jointVelocities
      );

   EcBoolean setTorqueEnable
      (
      const EcBoolean torqueEnable
      );

   EcBoolean setTorqueLimitCommand
      (
      const EcU16 torqueLimitInCounts
      );

protected:
   EcBoolean setTorqueLimit
      (
      const EcU8 id, 
      const EcU16 torqueLimitInCounts
      );

   EcBoolean compare
      (
      const RobotisHardwareConfig& lhs,
      const EcU8* data
      );

   EcBoolean setPIDGains
      (
      const EcU8 proportionGain,
      const EcU8 integralGain,
      const EcU8 derivativeGain
      );

   mutable boost::shared_ptr<CommandStruct> m_pCmd;
   mutable EcMutex m_Mutex;
   EcXmlU16 MaxSetupVelocityInHWUnits; ///< Max velocity to use during init operations
};

} // namespace Ec

#endif // ec_RobotisPluginData_H_
