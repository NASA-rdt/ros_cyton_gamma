#ifndef ec_FoundCoreSignals_H_
#define ec_FoundCoreSignals_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecFoundCoreSignals.h
/// @class Ec::LogicalAndCompleteResults
/// @class Ec::LogicalAndResults
/// @brief Provides traits classes for signals used by foundCore and network.
/// @todo Separate classes/structs into separate files
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecConstants.h"

#include <boost/logic/tribool.hpp>
#include <boost/mpl/string.hpp>

#ifndef WIN32
// Avoid getting warnings from gcc related to the use of multichar below.
// FIXME: I would like to use "diagnostic ignored"; however, the pragma does not seem to work.
//        system_header is a bit heavy-handed here.
//#  pragma GCC diagnostic ignored "-Wmultichar"
#  pragma GCC system_header
#endif

class EcXmlObject;
namespace Ec
{

// Forward declarations
class Plugin;

//------------------------------------------------------------------------------
/// Combiner struct that will perform a logical AND of EcBoolean return values.
/// It will exit the first time an EcFalse value is found.
struct LogicalAndResults
{
   typedef EcBoolean result_type;  ///< the result type

   /// template to define a logical operator on two objects
   /// @tparam T The type of the object used for the analysis
   template <typename T> result_type operator()(T f, T l) const
   { for(; f!=l; ++f) if(!*f) return EcFalse; return EcTrue; }
};

//------------------------------------------------------------------------------
/// Combiner struct that will perform a logical AND of tribool return values.  It
/// will continue through all receivers and accumulate the results.  This allows
/// cases where even when an error occurs, other slots still get triggered.  The
/// overall return code is returned.
struct LogicalAndCompleteResults
{
   typedef boost::logic::tribool result_type;    ///< tribool result type
   /// template method to perform a logical AND of tribool return values
   /// @tparam T the type
   /// @param f
   /// @param l
   /// @return the return code
   template <typename T> result_type operator()(T f, T l) const
   {
      result_type r(true),set(boost::logic::indeterminate);
      for(; f!=l; ++f)
      {
         result_type ir = *f;
         if(boost::logic::indeterminate(ir)) continue;
         set = true;
         // Preserve any EcFalse values
         r = r && ir;
      }
      return set ? r : set;
   }
};

//------------------------------------------------------------------------------
/// Combiner struct that will perform a logical NOR of EcBoolean return values.
/// It will exit the first time an EcTrue value is found meaning the message was
/// successfully handled.
struct LogicalNorResults
{
   typedef boost::logic::tribool result_type;       ///< tribool result type

   /// template method to perform a logical NOR of EcBoolean return values.
   /// @tparam T the type
   /// @param f
   /// @param l
   /// @return True if successful
   template <typename T> result_type operator()(T f, T l) const
   {
      result_type r(boost::logic::indeterminate);
      for(; f!=l; ++f)
      {
         r = *f;
         if(!boost::logic::indeterminate(r)) break;
      }
      return r;
   }
};


//------------------------------------------------------------------------------
/// Signal to notify that a plugin has been loaded in memory
struct SignalLoadPluginTraits
{
   typedef boost::mpl::string<'load', 'Plug', 'in'> Name;     ///< Signal name string
   
   /// @param copydoc SignalLoadPluginTraits
   /// @param plugin 
   typedef void (Type)(Plugin* plugin);                       
};

//------------------------------------------------------------------------------
/// Signal to notify that a plugin has been initialized
struct SignalInitPluginTraits
{
   typedef boost::mpl::string<'init', 'Plug', 'in'> Name;    ///< Signal name string

   typedef LogicalAndResults Combiner;                       ///< The combiner results type  

   /// @copydoc SignalInitPluginTraits
   /// @param plugin
   typedef LogicalAndResults::result_type (Type)(Plugin* plugin);
};

//------------------------------------------------------------------------------
/// Signal to notify that a plugin has been unloaded from memory
struct SignalUnloadPluginTraits
{
   typedef boost::mpl::string<'unlo', 'adPl', 'ugin'> Name;   ///< Signal name string
   
   /// @copydoc SignalUnloadPluginTraits
   /// @param plugin
   typedef void (Type)(Plugin* plugin);
};

//------------------------------------------------------------------------------
/// Signal for dealing with messages before standard processing
struct SignalNetworkMessageTraits
{
   typedef boost::mpl::string<'netw', 'orkM', 'essa', 'ge'> Name;   ///< Signal name string
   typedef LogicalAndCompleteResults Combiner;                      ///< The combiner results type

   /// @copydoc SignalNetworkMessageTraits
   /// @param msgType
   /// @param msg
   typedef LogicalAndCompleteResults::result_type (Type)(const EcU32 msgType, const EcString& msg);
};

//------------------------------------------------------------------------------
/// Signal for dealing with custom messages
struct SignalNetworkCustomMessageTraits
{
   typedef boost::mpl::string<'netw', 'orkC', 'usto', 'mMes', 'sage'> Name;  ///< Signal name string
   typedef LogicalAndCompleteResults Combiner;                               ///< The combiner results type

   /// @copydoc SignalNetworkCustomMessageTraits
   /// @param msgType
   /// @param msg
   typedef LogicalAndCompleteResults::result_type (Type)(const EcU32 msgType, const EcString& msg);
};

//------------------------------------------------------------------------------
/// Signal for dealing with return messages from non-network plugins
struct SignalNetworkObjectTraits
{
   typedef boost::mpl::string<'netw', 'orkO', 'bjec', 't'> Name;   ///< Signal name string
   typedef LogicalAndCompleteResults Combiner;                     ///< The combiner results type
   
   /// @copydoc SignalNetworkObjectTraits
   /// @param msgType
   /// @param msg
   typedef LogicalAndCompleteResults::result_type (Type)(const EcU32 msgType, const EcXmlObject& obj);
};

//------------------------------------------------------------------------------
/// Signal for reporting back network results messages
struct SignalNetworkResultsTraits
{
   typedef boost::mpl::string<'netw', 'orkR', 'esul', 'ts'> Name;   ///< Signal name string
   
   /// @copydoc SignalNetworkResultsTraits
   /// @param msgType
   /// @param msg
   typedef void (Type)(const EcU32 msgType, const EcString& msg);
};

//------------------------------------------------------------------------------
/// Signal for reporting when a TCP connection is established
struct SignalNetworkConnectTraits
{
   typedef boost::mpl::string<'netw', 'orkC', 'onne', 'ct'> Name;      ///< Signal name string

   /// @copydoc SignalNetworkConnectTraits
   /// @param port
   /// @param ipAddress
   typedef void (Type)(const EcU32 port, const EcString& ipAddress);
};

//------------------------------------------------------------------------------
/// Signal for reporting when a TCP connection is severed
struct SignalNetworkDisconnectTraits
{
   typedef boost::mpl::string<'netw', 'orkD', 'isco', 'nnec', 't'> Name;   ///< Signal name string

   /// @copydoc SignalNetworkDisconnectTraits
   /// @param port
   /// @param ipAddress
   typedef void (Type)(const EcU32 port, const EcString& ipAddress);
};

} // namespace Ec

#endif // ec_FoundCoreSignals_H_
