#ifndef ec_network_SkypeImplX11_H_
#define ec_network_SkypeImplX11_H_
#  ifndef ec_network_SkypeImpl_H
#    warning "Do not directly include this file.  Use ecNetworkSkypeImpl.h"
#  endif
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecNetworkSkypeImplX11.h
/// @class Ec::network::SkypeImpl
/// @brief X11-based version of Skype networking.
//
//------------------------------------------------------------------------------

namespace Ec { namespace network {

/**
 * \class SkypeImpl
 * \brief concrete implementation for the Linux-specific portion of the skype transport
 *
   Concrete implementation for the Linux-specific portion of the skype transport. This implementation
   uses the X11 even method for communicating with the local skype client. Another method would be to
   use the dbus library, but this requires some sytem setup by the user and the added library.
 */
class SkypeImpl : public SkypeImplBase
{
public:
   enum
   {
      XEVENTBYTEFORMAT=8,         ///< 8 bit format
      MAX_EVENT_SIZE=20           ///< an xevent can only hold 20 bytes
   };

   /// ctor
   SkypeImpl();

   /// dtor
   ~SkypeImpl();

protected:
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
   EcBoolean   ProcessEvents
      (
      );

   /// processEventsNoWait
   /**
    Dont wait, but process any single events from the skype api.
    Called by both findResponse and ProcessEvents
    @return EcBoolean true if any events were processed, false otherwise
    */
   EcBoolean   ProcessEventsNoWait
      (
      );

   /// findResponse
   /**
    Look for specific string pattern in the cached replies from local skype client

    @param[in] _milliSeconds milliseconds to search for specified string pattern
    @param[in] responsePattern the string pattern to search for
    @return EcBoolean true if specific string response pattern was found within specified duration, false otherwise
    */
   EcBoolean   findResponse
      (
      const EcInt64 _milliSeconds,
      const EcString& responsePattern
      );

   /// timedWait
   /**
    For X11 impl, we must watch for events ourselves. Uses select() on the skype client display and a timer.
    */
   void timedWait
      (
      );

   //Vint::To pass app name to x11 Skype
   void giveApplicationNameToPLatformDepLayer
      (
      EcString string
      );

   //Vint::To get values from skype
   EcString  dataReadFromDepLayer
      (
      );

   //Vint:abstract class consists this so we use this
   EcBoolean deinit
      (
      const EcInt64 _milliSeconds
      );

private:
   SkypeImpl(const SkypeImpl& rhs);
   SkypeImpl& operator=(const SkypeImpl& rhs);
};

} } // namespace Ec::network

#endif // ecCommTransportSkypeImpl_H_
