#ifndef ec_network_SkypeHandle_H
#define ec_network_SkypeHandle_H
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkSkypeHandle.h
/// @class Ec::network::SkypeHandle
/// @brief Skype-based networking implementation.  It has a separate
///        thread to provide non-blocking behavior.
//
//------------------------------------------------------------------------------
#include "ecNetworkHandle.h"
#include <foundCore/ecDeque.h>
#include <foundCore/ecWatchedVar.h>

#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <boost/signal.hpp>
namespace EcComm
{
   typedef boost::signal< void (const std::string&) > signal_t;  ///< boost signal template
}

namespace Ec { namespace network {

class SkypeImplBase;

class EC_FOUNDATION_TRANSPORT_DECL SkypeHandle : public Handle
{
public:

   enum {max_windowNameLen=128 };

   enum
   {
      SKYPECONTROLAPI_ATTACH_SUCCESS = 0,
      SKYPECONTROLAPI_ATTACH_PENDING_AUTHORIZATION=1,
      SKYPECONTROLAPI_ATTACH_REFUSED=2,
      SKYPECONTROLAPI_ATTACH_NOT_AVAILABLE=3,
      SKYPECONTROLAPI_ATTACH_API_AVAILABLE=0x8001
   };

   /// constructor
   explicit SkypeHandle
      (
      const NetworkMode mode = LocalMode
      );

   /// Destructor
   ~SkypeHandle
      (
      );

   /// Get the application name for this session
   /// @return EcString& Application name
   const EcString& applicationName
      (
      ) const;

   /// Set the application name to use for this session
   /// @param app Name to set
   void setApplicationName
      (
      const EcString& app
      );

   /// Get the user ID
   /// @return EcString& User name
   const EcString& userID
      (
      ) const;

   /// Set the userID
   /// @param user User to set
   void setUserID
      (
      const EcString& user
      );

   /// Server-side method that will listen on the previously-supplied
   /// port.  If a callback handler was registered, then it will spawn
   /// a separate thread to handle the connection.  Otherwise it will
   /// block until an incoming request is made.
   /// @return EcBoolean Success or failure of command
   EcBoolean listen
      (
      );

   /// Client-side connection-oriented method that attempts to connect
   /// to a server using previously-supplied IP address and port (or
   /// their defaults).  If a callback handler was registered, then on
   /// success it will spawn a separate thread to handle return messages.
   /// Connection-oriented protocols available are TCP and Skype.
   /// @return EcBoolean Success or failure of command
   EcBoolean connectToHost
      (
      );

   /// Close down and terminate the existing connection (if any).
   /// Cleans up any memory or resources related to the connection.
   void disconnect
      (
      );

   /// For connection-oriented protocols, checks to make sure that the
   /// connection is still up and valid.  For connection-less protocols,
   /// it will simply return EcTrue.
   /// @return EcBoolean Success or failure of command
   EcBoolean isConnected
      (
      ) const;

   /// Lets the caller know if there is data available for reading
   /// @return EcBoolean EcTrue if data is available to read
   virtual EcBoolean dataAvailable
      (
      ) const;

   /// @copydoc Ec::network::Handle::read(char*, const EcU32)
   virtual EcInt32 read
      (
      char* buf,
      const EcU32 size
      );

   /// @copydoc Ec::network::Handle::write(const char*, const EcU32)
   virtual EcInt32 write
      (
      const char* buf,
      const EcU32 size
      );

   /// Handles new server connection requests
   void onActionNewConnection
      (
      );
   
   /// Reads from socket and invokes callback
   void onActionProcessRead
      (
      );

   /// Handles child socket disconnections. Cleans up SocketMap.
   void onActionDisconnected
      (
      );

   /// read thread
   void readThread
      (
      );

   enum
   {
      KEEP_ALIVE_MINUTES=3        /// after this much inactivity, send a ping to keep the connection alive
   };

protected:
   /// init
   /**
      Initialize the implementation. Call initializeSkype and register the subscriber callback.

      @param[in] _milliSeconds milliseconds to wait for initialization to complete
      @return EcBoolean true if init succeeded within the timeout, false otherwise
   */
   EcBoolean init
      (
      const EcInt64 _milliSeconds
      );

   /// deinit
   /**
      Wait until not sending or receiving, then clean up the implementation by
      reaping the event process thread and unregistering the callbacks

      @param[in] _milliSeconds milliseconds to wait for deinit to complete
      @return EcBoolean true if deinit succeeded within the timeout, false otherwise
   */
   EcBoolean deinit
      (
      const EcInt64 _milliSeconds
      );

   /// sendToSkype
   /**
      Send command to skype API via this implementation
      @note this is a pure virtual method to be implemented by derived implementation
      @param[in] cmd the command to send
      @return EcBoolean true if send succeeded, false otherwise
   */
   EcBoolean sendToSkype
      (
      const EcString& cmd
      );

   /// keepAlive
   /**
      If there has been no read or write activity in KEE_ALIVE_MINUTES, send a ping.
      This method called from within the event processing thread

      @note not clear of we should just use write activity
   */
   void keepAlive
      (
      );

   /// boost ptime
   typedef boost::posix_time::ptime PTIME;

   /// storeResponse
   /**
      Store response from local skype client. This is the callback registered and used during init(),
      then unregistered upon success there
   */
   void storeResponse
      (
      const EcString& buffer
      );

   /// Attach
   /**
      Connect to the local skype client
      @note this is a pure virtual method to be implemented by derived implementation
      @return EcBoolean return true if local skype client is identified and connected
   */
   EcBoolean   Attach
      (
      );

   /// Detach
   /**
      Detach from local skype client
      @note this is a pure virtual method to be implemented by derived implementation
      @return EcBoolean return true if successful, false otherwise
   */
   EcBoolean   Detach
      (
      );

   /// initializeSkype
   /**
      Initialize the skype client. Create the event loop, register the local callback storeResponse(),
      create the application name, and test the connection using ping

      @return EcBoolean return true if successful, false otherwise
   */
   EcBoolean   initializeSkype
      (
      );

   /// startEventLoop
   /**
      Start the thread to process events from the local skype client
      @return EcBoolean true if even processing thread created successfully, false otherwise
   */
   EcBoolean   startEventLoop
      (
      );

   /// updateSendTime
   /**
      Refresh the timer that determines if a keep alive should be sent
   */
   void updateSendTime
      (
      );

   /// ProcessEvents
   /**
      Process any pending events from the local skype client

      @note this is a pure virtual method to be implemented by derived implementation

      @return EcBoolean true if any events were processed, false otherwise
   */
   EcBoolean   ProcessEvents
      (
      );

   /// eventLoop
   /**
      Perpetual method that invokes ProcessEvents for any work to be done
   */
   void eventLoop
      (
      );

   /// findResponse
   /**
      Look for specific string pattern in the cached replies from local skype client

      @param[in] _milliSeconds milliseconds to search for specified string pattern
      @param[in] responsePattern the string pattern to search for
      @return EcBoolean true if specific string response pattern was found within specified duration, false otherwise

      @note this is a pure virtual method to be implemented by derived implementation
    */
   EcBoolean   findResponse
      (
      const EcInt64 _milliSeconds,
      const EcString& responsePattern
      );

protected:
   EcMutex* m_mutex;    ///< mutex
   EcBoolean header;    ///< header flag
   EcBoolean m_Var;     ///< Variable flag

   Ec::EcWatchedVar<EcBoolean>         m_HaveSkype;               ///< true if local skype client has been identified and connected with
   EcMutex                             m_SigMutex;                ///< mutex protection for signal callbacks
   EcComm::signal_t                    m_Sig;                     ///< signal callback for data received from local skype client

   Ec::EcDeque                         m_ReceiveHistory;          ///< the cached data received from local skype client, populated by storeResponse callback
   volatile EcBoolean                  m_TimeToQuit;              ///< loop exit variable
   boost::thread*                      m_EventLoop;               ///< pointer to the even processing thread
   EcInt64                             m_ConnectTimeout;          ///< millisecond duration for connecting
   EcInt64                             m_DisconnectTimeout;       ///< millisecond duration for disconnecting
   PTIME                               m_LastSendTime;            ///< absolute clock time for last send, used in keep alive calculation
   Ec::EcWatchedVar<EcBoolean>         m_Sending;                 ///< true if we are currently sending data, false otherwiser; used in disconnect
   Ec::EcWatchedVar<EcBoolean>         m_Receiving;               ///< true if we are currently receiving data, false otherwise; used in disconnect


   EcString m_AppName; ///< Application name to use
   EcString m_UserID;  ///< User name to use
   SkypeImplBase* m_pImpl; ///< Platform-dependent implementation layer
};

} } // namespace Ec::network

#endif // ec_network_SkypeHandle_H
