#ifndef ec_network_SkypeImplWin_H_
#define ec_network_SkypeImplWin_H_
#  ifndef ec_network_SkypeImpl_H
#    pragma message("Do not directly include this file.  Use ecNetworkSkypeImpl.h")
#  endif
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkSkypeImplWin.h
/// @class Ec::network::SkypeImpl
/// @brief Windows-based version of Skype networking.
//
//------------------------------------------------------------------------------
#include <windows.h>

namespace Ec { namespace network {

/**\class SkypeImpl
 * \brief concrete implementation for the Windows-specific portion of the skype transport
 *
 Concrete implementation for the Windows-specific portion of the skype transport. This implementation
 uses the WMCOPYDATA method, the only method currently availble under windows.
 */
class SkypeImpl :public SkypeImplBase
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

   /// ctor
   SkypeImpl();

   /// dtor
   virtual ~SkypeImpl();

   /// deinit
   /**
    Wait until not sending or receiving, then clean up the implementation by
    reaping the event process thread and unregistering the callbacks

    @note this method overrides the base impl

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

protected:
   /// Attach
   /**
    Connect to the local skype client
    @return EcBoolean return true if local skype client is identified and connected
    */
   EcBoolean   Attach
      (
      );

   /// Detach
   /**
    Detach from local skype client
    @return EcBoolean return true if successful, false otherwise
    */
   EcBoolean   Detach
      (
      );

   /// ProcessEvents
   /**
    Process any pending events from the local skype client
    @return EcBoolean true if any events were processed, false otherwise
    */
   virtual EcBoolean ProcessEvents
      (
      );

   /// findResponse
   /**
    Look for specific string pattern in the cached replies from local skype client

    @param[in] _milliSeconds milliseconds to search for specified string pattern
    @param[in] responsePattern the string pattern to search for
    @return EcBoolean true if specific string response pattern was found within specified duration, false otherwise
    */
   virtual EcBoolean   findResponse
      (
      const EcInt64 _milliSeconds,
      const EcString& responsePattern
      );

   /// WindowProcedure
   /**
    Callback method registered to receive events from the skype client.
    This method invokes ProcessEvent()
    @return the value 1, as required by the skype api.
    */
   static LRESULT CALLBACK WindowProcedure
      (
      HWND hWindow,
      UINT uiMessage,
      WPARAM uiParam,
      LPARAM ulParam
      );

   /// ProcessEvent
   /**
    Handle an event from the skype client, setting state as appropriate, invoking the registered storeResponse slot,
    and setting thread termination
    */
   virtual LRESULT ProcessEvent
      (
      HWND hWindow,
      UINT uiMessage,
      WPARAM uiParam,
      LPARAM ulParam
      );

   /// CreateWindowClass
   /**
    An invisible window must be created so windows can send us events
    @return EcBoolean true on success, false otherwise
    */
   virtual EcBoolean CreateWindowClass
      (
      );

   /// CreateMainWindow
   /**
    Create an empty window so windows callback methods can send messages to us
    @return EcBoolean true on success, false otherwise
    */
   virtual EcBoolean CreateMainWindow
      (
      );

   /// @copydoc SkypeImplBase::giveApplicationNameToPLatformDepLayer()
   void giveApplicationNameToPLatformDepLayer
      (
      EcString string
      );

   /// @copydoc SkypeImplBase::dataReadFromDepLayer()
   EcString  dataReadFromDepLayer
      (
      );

   UINT                        m_SkypeControlAPIAttachID;               ///< Skype control API attachment ID
   UINT                        m_SkypeControlAPIDiscoverID;             ///< Skype control API Discover ID
   HINSTANCE                   m_ProcessHandle;                         ///< process handle
   HWND                        m_MainWindowHandle;                      ///< main window handle
   HWND                        m_SkypeWindowHandle;                     ///< Skype window handle
   char                        m_WindowClassName[max_windowNameLen];    ///< window class name

private:

   /// copy constructor
   SkypeImpl(const SkypeImpl& rhs);

   /// assignment operator
   SkypeImpl& operator=(const SkypeImpl& rhs);
};

} } // namespace Ec::network

#endif // ec_network_SkypeImplWin_H_
