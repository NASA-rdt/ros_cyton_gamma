#ifndef ec_network_SkypeImpl_H
#define ec_network_SkypeImpl_H
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkSkypeImpl.h
/// @brief Skype platform independent header.  Includes the implementation
///        for the current OS.
/// @class Ec::network::SkypeImplBase
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <foundCore/ecDeque.h>
#include <foundCore/ecMutex.h>

#include <boost/signal.hpp>

/// namespace for communication code
namespace EcComm { typedef boost::signal< void (const std::string&) > signal_t; }

namespace Ec { 

/// namespace for network code
namespace network {

/// base class for skype transport
class EC_FOUNDATION_TRANSPORT_DECL SkypeImplBase
{
public:

   /// destructor
   virtual ~SkypeImplBase
      (
      ) {}

   /// give application name of skype to dependent(skype) layers
   virtual void giveApplicationNameToPLatformDepLayer
      (
      EcString string
      ) = 0;

   /// get data from skype lower Layer
   virtual EcString dataReadFromDepLayer
      (
      ) = 0;

   /// deinit
   /**
      Wait until not sending or receiving, then clean up the implementation by
      reaping the event process thread and unregistering the callbacks

      @note this method overrides the base impl

      @param[in] _milliSeconds milliseconds to wait for deinit to complete
      @return EcBoolean true if deinit succeeded within the timeout, false otherwise
   */
   virtual EcBoolean deinit
      (
      const EcInt64 _milliSeconds
      ) = 0;

   /// sendToSkype
   /**
      Send command to skype API via this implementation
      @note this is a pure virtual method to be implemented by derived implementation
      @param[in] cmd the command to send
      @return EcBoolean true if send succeeded, false otherwise
   */
   virtual EcBoolean sendToSkype
      (
      const EcString& cmd
      ) = 0;

   /// Attach
   /**
      Connect to the local skype client
      @return EcBoolean return true if local skype client is identified and connected
   */
   virtual EcBoolean Attach
      (
      ) = 0;

   /// Detach
   /**
      Detach from local skype client
      @return EcBoolean return true if successful, false otherwise
   */
   virtual EcBoolean Detach
      (
      ) = 0;

   /// ProcessEvents
   /**
      Process any pending events from the local skype client
      @return EcBoolean true if any events were processed, false otherwise
   */
   virtual EcBoolean ProcessEvents
      (
      ) = 0;

   /// findResponse
   /**
      Look for specific string pattern in the cached replies from local skype client

      @param[in] _milliSeconds milliseconds to search for specified string pattern
      @param[in] responsePattern the string pattern to search for
      @return EcBoolean true if specific string response pattern was found within specified duration, false otherwise
   */
   virtual EcBoolean findResponse
      (
      const EcInt64 _milliSeconds,
      const EcString& responsePattern
      ) = 0;

protected:
   EcString  m_DataRead;            ///< string holding read data
   EcBoolean m_HaveSkype;           ///< flag for skype
   EcString  m_AppName;             ///< application name
   EcBoolean m_TimeToQuit;          ///< flag for quiting
   EcBoolean m_Sending;             ///< flag for sending
   EcBoolean m_Receiving;           ///< flag for receiving
   EcMutex   m_SigMutex;            ///< mutex protection for signal callback
   EcComm::signal_t m_Sig;          ///< signal callback for data received from local skype client

   Ec::EcDeque m_ReceiveHistory;    ///< stack for receive history
};

} } // namespace Ec::network

#if defined(WIN32)
#  include "ecNetworkSkypeImplWin.h"
//#elif defined(__APPLE__)
//#  include "ecNetworkSkypeImplOSX.h"
#else
#  include "ecNetworkSkypeImplX11.h"
#endif

#endif // ec_network_SkypeImpl_H
