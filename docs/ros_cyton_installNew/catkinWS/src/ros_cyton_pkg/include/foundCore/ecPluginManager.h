#ifndef ecPluginManager_H_
#define ecPluginManager_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginManager.h
/// @class Ec::PluginManager
/// @brief Provides a loader class for handling the loading and unloading
///        of plugins.
//
//------------------------------------------------------------------------------
#include "ecConnectionManagerTypes.h" // for signals
#include "ecFoundCoreSignals.h"       // for signals
#include "ecMacros.h"  // Required to be first header.

namespace Ec
{

#ifdef _DEBUG
   const EcString PluginExtension = ".ecpd";      ///< The plugin file extension 
#else
   const EcString PluginExtension = ".ecp";       ///< The plugin file extension
#endif

class Application;
class Plugin;
// Structure to keep track of loaded plugins.
struct PluginStruct;

/// Vector type of Ec::Plugin* from std::vector
typedef std::vector<Plugin*> PluginVector;

class EC_STABLE_FOUNDCORE_DECL PluginManager
{
public:
   /// Access to interface
   static PluginManager& instance
      (
      );

   /// Destructor
   ~PluginManager
      (
      );

   /// Use this method to create a new instance of a plugin.  It loads the shared library
   /// into memory and adds it to the list of managed plugins.
   /// @return Ec::Plugin* Returns pointer to loaded plugin, or EcNULL on failure
   Plugin *loadPlugin
      (
      const EcString &pluginName,              ///< [in] Plugin to load
      const EcBoolean unloadOnFailure = EcTrue ///< [in] Response if init fails
      );

   /// Add an existing plugin to the list of loaded plugins.  If the handle is
   /// empty, then it will be marked as a permament plugin so that it can't be
   /// unloaded since there won't be a handle to the shared library.
   void loadPlugin
      (
      Plugin* plugin,       ///< [in] Handle to plugin
      void* handle = EcNULL ///< [in] Optional platform specific handle to library
      );

   /// Use this method to remove a loaded plugin.  It removes it from the list of managed
   /// plugins.
   /// @return EcBoolean Returns EcTrue or EcFalse if the plugin was in the list.
   EcBoolean unloadPlugin
      (
      const EcString &pluginName ///< [in] Plugin to remove
      );

   /// Clears out the list of currently loaded plugins from memory.
   void unloadAllPlugins
      (
      );

   /// Retrieve the current list of loaded plugins.
   EcStringVector pluginList
      (
      );

   /// Get a const handle to plugin list.
   const PluginVector &plugins
      (
      );

   /// Types of fields available to search by.
   enum FindType
   {
      FindByPluginName,
      FindByFileName,
      FindByHandle
   };

   /// Searches loaded plugins to see if library is already loaded.
   /// @return Plugin* Pointer to valid plugin or EcNULL if not found.
   Plugin* findPlugin
      (
      const EcString& name,                  ///< [in] Name of plugin to search for
      const FindType type = FindByPluginName ///< [in] Field element to match
      );

   /// Performs initialization of plugin using supplied init callbacks.
   /// @return        EcBoolean Success or failure of init
   EcBoolean initPlugin
      (
      Plugin* plugin ///< [in,out] Plugin to process
      );

protected:
   friend class Application;
   friend struct PluginStruct;
   typedef boost::shared_ptr<PluginStruct> SharedPluginStruct;   ///< shared pointer to a Ec::PluginStruct
   typedef std::vector<SharedPluginStruct> PluginDataVector;     ///< std::vector of shared pointers to Ec::PluginStruct

   /// @copydoc Ec::Application::init()
   void init
      (
      );

   /// Searches loaded plugins to see if library is already loaded.
   /// @return PluginVector::iterator Iterator pointing to entry or end() entry if not found.
   PluginDataVector::iterator find
      (
      const void *handle,                ///< [in] Handle to library
      const FindType type = FindByHandle ///< [in] Field element to match
      );

   /// Internal method to unload plugin
   void unload
      (
      const PluginStruct& ps ///< [in] Element to unload
      );

   PluginDataVector m_PluginDataPtr;             ///< Vector of shared points to plugin data structs
   PluginVector m_LoadedPlugins;                 ///< List of plugins currently loaded in memory

   /// Pointer to the signal for initPlugin()
   ConnectionManagerTypes::Signal<SignalInitPluginTraits::Type,SignalInitPluginTraits::Combiner>::PtrType m_InitPluginSignalPtr;

   /// Pointer to the signal for loadPlugin()
   ConnectionManagerTypes::Signal<SignalLoadPluginTraits::Type>::PtrType m_LoadPluginSignalPtr;

   /// Pointer to the signal for unloadPlugin()
   ConnectionManagerTypes::Signal<SignalUnloadPluginTraits::Type>::PtrType m_UnloadPluginSignalPtr;
};

} // namespace Ec

#endif // ecPluginManager_H_
