#ifndef ec_Plugin_H_
#define ec_Plugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlugin.h
/// @class Ec::Plugin
/// @brief Provides an abstract class to be used as a template for creating
///        dynamically loaded functions.
//
//------------------------------------------------------------------------------
#ifndef EC_NO_ACTIN
#  include "ecConfig.h"
#  include "ecMacros.h"
#else  // EC_NO_ACTIN
#  include <actinSE/actinTypes.h>
#  include "ecPluginPrint.h"
#endif // EC_NO_ACTIN

#ifdef EC_PLUGIN_SOURCE
/// plugin exports
#  define EC_PLUGIN_DECL EC_DECL_EXPORTS
#else
/// plugin imports
#  define EC_PLUGIN_DECL EC_DECL_IMPORTS
#endif

#if defined(stableFoundation_foundCore_EXPORTS) || \
    defined(actin_plugins_EXPORTS) || \
    defined(actin_hardwarePlugin_EXPORTS) || \
    defined(guiCommon_viewerCore_EXPORTS)
/// Specialized plugin exports
#  define EC_PLUGIN_DECL_SPEC EC_DECL_EXPORTS
#else
/// Specialized plugin imports
#  define EC_PLUGIN_DECL_SPEC EC_DECL_IMPORTS
#endif

/// Default plugin loader code.  This macro needs to appear in the .cpp
/// file for the plugin.  It is a wrapper subclass of the plugin so that
/// it may set internal variables and provide an entry point.
/// @param cls    Class name of plugin
/// @param traits Plugin traits (capabilities available)
#define EC_PLUGIN_STUB(cls, traits) \
   class cls##Helper : public cls\
   { \
   public: \
      cls##Helper():cls() { m_Name = #cls; m_PluginTraits |= (TraitMask&traits); } \
   }; \
   extern "C" EC_DECL_EXPORTS Ec::Plugin* loadPlugin() { return new cls##Helper; }

/// Convenience version of stub that uses the default setting for the plugin.
/// In the case of a GUI plugin, this means that a separate thread will not
/// be spawned to call the update(const EcReal time) method.  A non-GUI plugin
/// will spawn a thread.
#define EC_PLUGIN_STUB_DEFAULT(cls) EC_PLUGIN_STUB(cls,0)

/// To allow a clean build w/wo latest stable
#define EC_PLUGIN_THREAD_STARTCALL 

class EcIODataBroker;
class EcXmlReader;
class EcXmlWriter;

namespace Ec
{

struct IOBuffer;

class AsyncThread;

/// Base Implementation class used to provide minimum capability for loading.
/// It holds a pointer to the loading helper class to provide access to the
/// plugin name as well as the ability to unload when finished.
class Plugin
{
public:
   /// Current version of the plugin API.  Any plugin compiled with this header
   /// will use 'currentVersion' as the built type.  When the API changes, this
   /// number needs to be changed to invalidate older plugins.
   static const EcU8 currentVersion = 0xa;

   /// Enumeration of some characteristics about this plugin.  This describes exactly what
   /// the plugin is able to provide and accept.
   enum PluginTraitsEnum
   {
      TraitDefault      = 0x00,  ///< Standard plugin capability - set by default
      TraitHardware     = 0x01,  ///< Hardware-based plugin set for HardwarePlugin
      TraitGUI          = 0x02,  ///< Uses QT UI - set for PluginGUI

      // Characteristics able to be specified in EC_PLUGIN_STUB()
      TraitPermanent    = 0x10,  ///< Unable to be removed from memory - makes irreversible changes
      TraitWinPermanent = 0x20,  ///< Memory restriction on windows
      TraitNoThread     = 0x40,  ///< Do not spawn a thread for updates
      TraitGUIThread    = 0x80,  ///< Spawn an update thread for GUI plugins
      TraitCopySystem   = 0x100, ///< Copy the stated system for this plugin
      TraitMask         = 0x1ff, ///< Mask of all traits
   };
   /// Declare a type to hold the plugin traits.  24-bits are reserved, with 8
   /// being used for versioning.
   typedef EcU32 PluginTraits;

   /// Retrieve the name of this plugin.
   virtual const EcString& pluginName() const { return m_Name; }

   /// Retrieve the type and version number for this plugin.
   virtual PluginTraits traits() const { return m_PluginTraits; }

   /// Provides mechanism to set plugin parameters.  Called immediately
   /// before initState.
   /// @param[in] str Initialization string for parameter passing
   virtual void setConfigurationString(const EcString& str) {}

   /// Allows for saving of plugin parameters.
   /// @return EcString Configuration-specific values to save off
   virtual EcString getConfigurationString() const { return EcString(); }

   /// Provides mechanism to set plugin parameters through an XML stream.
   /// @param[in] stream XML stream to read from
   /// @return EcBoolean Success or failure of reading
   virtual EcBoolean readConfigurationString(EcXmlReader& stream) { return EcTrue; }

   /// Allows for saving of plugin parameters to an XML stream
   /// @param[in] stream XML stream to write to
   /// @return EcBoolean Success or failure of writing
   virtual EcBoolean writeConfigurationString(EcXmlWriter& stream) const { return EcTrue; }

   /// State initialization.  This method is called after file loading. It
   /// allows setting specific parameters based upon the file loaded.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean initState() { return EcTrue; }

   /// This method is called when the simulation is initialized and/or reset due to file
   /// loading.  Any state cleanup should be done here.
   /// @return EcBoolean Success or Failure of command
   virtual EcBoolean reset() { return EcTrue; }

   /// This method is called immediately before unloading the plugin.  It is
   /// available to be overriden by plugins requiring an available simulation.
   /// As an example, hardware-based plugins might use this to home, or park,
   /// the hardware before powering down.
   virtual EcBoolean shutdown() { return EcTrue; }

   /// This method will be called at the proper update rate specified.
   /// @param time Current simulation timestep
   virtual void update(const EcReal time) = 0;

   /// Retrieve the current plugin update interval.
   /// @return EcU32 Time in milliseconds between updates.  A value of 0 means
   ///               run at the same rate as the simulation
   EcU32 updatePeriodInMs() const { return m_UpdatePeriodInMs; }

   /// Whether the plugin was able to initialize.
   /// @return EcBoolean Initialization state of plugin
   EcBoolean initialized() const { return m_Initialized; }

   /// Set the delta time used for joint position extrapolation.
   /// @param time the time in seconds
   void setExtrapolationTime(const EcReal time) { m_ExtrapolationTime = time; }

   /// Get the delta time used for joint position extrapolation.  
   /// @return time EcReal in seconds
   EcReal extrapolationTime() const             { return m_ExtrapolationTime; }

   /// Get a pointer to the Ec::AsyncThread class for real time manipulation.
   AsyncThread * getThread() { return m_pAsyncThread; }

   /// -----------------------------------------------------------------------
   /// Methods that can be used to query or set data within the simulation
   /// -----------------------------------------------------------------------

   /// Set parameter at the joint or end-effector level.  Single values are accepted here.
   /// @tparam prm       Parameter to change
   /// @param  manIndex  Manipulator index
   /// @param  subIndex  Secondary index, such as joint or end-effector index
   /// @param  value     Value to set
   /// @return EcBoolean Success or failure of setting the value
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC EcBoolean setParam
      (
      const EcU32 manIndex,
      const EcU32 subIndex,
      const ParamType& value
      );

   /// Set parameter for a single manipulator.  A vector of values applied over
   /// each joint or a single value for the entire manipulator.  Allowed types are:
   /// Base, JointAngle, JointVelocity
   /// @tparam prm       Parameter to change
   /// @param  manIndex  Manipulator index
   /// @param  value     Value to set
   /// @return EcBoolean Success or failure of setting the value
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC EcBoolean setParam
      (
      const EcU32 manIndex,
      const ParamType& value
      );

   /// Set parameter for the entire system or plugin.  Allowed types are:
   /// ReInit
   /// @tparam prm       Parameter to change
   /// @param  value     Value to set
   /// @return EcBoolean Success or failure of setting the value
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC EcBoolean setParam
      (
      const ParamType& value
      );

   /// Get parameters at the joint or end-effector level.  Single values are accepted here.
   /// @tparam prm       Parameter to retrieve
   /// @param  manIndex  Manipulator index
   /// @param  subIndex  Secondary index, such as joint or end-effector index
   /// @param  value     Variable value will be stored in.
   /// @return EcBoolean Success or failure of retrieving the value
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC EcBoolean getParam
      (
      const EcU32 manIndex,
      const EcU32 subIndex,
      ParamType& value
      ) const;

   /// Get parameters for the entire manipulator.  A vector of values is needed
   /// here. Allowed types are: JointAngle, JointVelocity
   /// @tparam prm       Parameter to retrieve
   /// @param  manIndex  Manipulator index
   /// @param  value     Variable value will be stored in.
   /// @return EcBoolean Success or failure of retrieving the value
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC EcBoolean getParam
      (
      const EcU32 manIndex,
      ParamType& value
      ) const;

   /// Get parameters for the entire manipulator.  A vector of values is needed
   /// here. Allowed types are: JointAngle, JointVelocity
   /// @tparam prm       Parameter to retrieve
   /// @param  manipIdentifier  Manipulator identifier
   /// @param  value     Variable value will be stored in.
   /// @return EcBoolean Success or failure of retrieving the value
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC EcBoolean getParam
      (
      const EcString& manipIdentifier,
      ParamType& value
      ) const;

   /// Get parameters for the entire system or plugin.  Allowed types are:
   /// JointAngle, JointVelocity
   /// @tparam prm       Parameter to retrieve
   /// @param  value     Variable value will be stored in.
   /// @return EcBoolean Success or failure of retrieving the value
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC EcBoolean getParam
      (
      ParamType& value
      ) const;

   /// Get a const reference to the parameter for the entire system or plugin.
   /// No error checking value is given.  Allowed types are:
   /// CollisionResults, DesiredForce, PropagationResults, State, SystemSimulation
   /// @tparam prm        Parameter to retrieve
   /// @tparam ParamType  Variable type to retrieve
   /// @return ParamType  const value of internal variable
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC const ParamType param
      (
      ) const;

   /// Get a const pointer to the parameter.
   /// No error checking value is given.  Allowed types are:
   /// StatedSystem
   /// @tparam prm        Parameter to retrieve
   /// @tparam ParamType  Variable type to retrieve
   /// @return ParamType* const pointer to internal variable
   template <EcU32 prm, typename ParamType>
   EC_PLUGIN_DECL_SPEC const ParamType* paramPtr
      (
      ) const;

   /// Attempt to retrieve a handle to a loaded plugin.
   /// @param[in] pluginName Name of plugin to get a handle to
   /// @return Plugin* Handle to plugin or EcNULL if not loaded
   static EC_PLUGIN_DECL_SPEC Plugin* getPlugin
      (
      const EcString& pluginName
      );

protected:
   friend class PluginManager;      ///< Creates and destroys plugins
   friend class ::EcIODataBroker;   ///< Initializes and sets back-end
#ifndef EC_NO_ACTIN
   friend class PluginThread;       ///< Sets plugin's pointer to thread.
#endif

   /// Constructor.  Disallow public construction.  Use PluginManager::loadPlugin() instead.
   EC_PLUGIN_DECL_SPEC Plugin();

   /// Destructor.  Disallow public deletion.  Use PluginManager::unloadPlugin() instead.
   /// Cleans up any allocated memory.
   virtual EC_PLUGIN_DECL_SPEC ~Plugin();

   /// Initialization routine.  This method is called once when the plugin is
   /// first loaded to perform any one-time processing.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean init() { return(m_Initialized = EcTrue); }

   /// Called whenever the thread for this plugin starts.
   ///
   /// This occurs after init, and occurs everytime the simulation restarts.
   /// It is called by the ecIODataBroker class (also inherited by simulation plugin)
   /// after each thread is started, so all plugin threads are available for setup, 
   /// as well as the simulation thread. To override the "start" of the AsyncThread
   /// to get immediate thread control of the new thread, override the ctor and subclass
   /// AsyncThread. Note this is not called on the plugin's thread itself.
   /// 
   /// Code can call getThread() to get a pointer to the plugin's Ec:AsyncThread,
   /// or call dataBroker->simulationThread() to get the simulation thread or a setup
   /// a different plugin's thread via:
   ///   Ec::Plugin * p = Ec::PluginManager::instance().findPlugin(vPlugins[ii]);
   ///   if (p != EcNULL) p->getThread()->setPriority(50);
   ///
   /// @param dataBroker   Pointer to EcIODataBroker (the simulation container).
   virtual void threadingStarted(EcIODataBroker * dataBroker) { ; }

   /// This function is called just before threads are joined / stopped. It 
   /// allows plugins to save off the actual state of the thread if desired.
   virtual void threadsStopping(EcIODataBroker * dataBroker) { ; }

   EcString       m_Name;                  ///< Name of the plugin
   PluginTraits   m_PluginTraits;          ///< Describes the capabilities of this plugin
   EcU32          m_UpdatePeriodInMs;      ///< Dictates how often this plugin gets updates
   EcStringVector m_RequiredPlugins;       ///< List of plugins that this plugin depends on
   EcBoolean      m_Initialized;           ///< Whether the plugin initialized properly
   IOBuffer*      m_pBuffer;               ///< Internal data caching mechanism
   mutable EcU32  m_StatedSystemCopyIndex; ///< Index of the copy of the stated system used
   EcReal         m_ExtrapolationTime;     ///< The delta time used for joint position extrapolation
   AsyncThread *  m_pAsyncThread;          ///< Asynchronous base thread.
};

/// Create a convenience cast from a general Plugin* to a specific class.
/// @tparam T the specific plugin type
/// @param name the name of the plugin
template <typename T> T* plugin_cast(const EcString& name)
{
   return dynamic_cast<T*>(Plugin::getPlugin(name));
}
/// Convenience macro to cast from a general Plugin* to a specific class.
#define PLUGIN_CAST(p) Ec::plugin_cast<p>(#p)

} // namespace Ec

#endif // ec_Plugin_H_
