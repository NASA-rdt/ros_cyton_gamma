#ifndef cyton_PluginData_H_
#define cyton_PluginData_H_
//     Copyright (c) 2011 Energid Technologies. All rights reserved. ////
//
// Filename:    cytonPluginData.h
//
// Contents:    cyton::PluginData class
//
/////////////////////////////////////////////////////////////////////////
#include <hardwarePlugin/ecHardwarePluginData.h>
#include <xml/ecXmlBasicType.h>

#include <boost/shared_ptr.hpp>

class EcSerial;

namespace cyton
{

class PluginData : public Ec::HardwarePluginData
{
public:
   ECXMLOBJECT(PluginData);
   ECXML_XMLOBJECTCREATOR(PluginData);

   /// @copydoc EcXmlCompoundType
   virtual void registerComponents
      (
      );

   /// Initializes the serial port and sets attributes
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean initSerial
      (
      );

   /// Retrieve the list of available serial ports
   /// @return const EcStringVector& List of serial ports
   EcStringVector ports() const;

   /// Sets the current port
   /// @param[in] name Port to use
   void setPort(const EcString& name);

   EcXmlU32 BaudRate;           ///< Specified baudrate of port
   EcXmlU32 Timeout;            ///< Timeout in ms
   EcXmlU8Vector GripperJoints; ///< Which joints are grippers
   mutable boost::shared_ptr<EcSerial> m_pSerial; ///< Serial port to communicate through
};

} // namespace cyton

#endif // cyton_PluginData_H_
