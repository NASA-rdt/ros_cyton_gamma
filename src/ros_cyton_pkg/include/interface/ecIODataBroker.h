#ifndef ecIODataBroker_H_
#define ecIODataBroker_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecIODataBroker.h
/// @class EcIODataBroker
/// @brief Manages flow of input and output data between plugins and simulation
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecAsyncThread.h"

#include <foundCore/ecElapsedTime.h>
#include <foundCore/ecMutex.h>
#include <plugins/ecIOParams.h>

#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/scoped_ptr.hpp>

// forward declarations.
namespace Ec
{
   class Plugin;
   class PluginThread;
   class SimulationThread;
   struct IOBuffer;
}
class EcSystemSimulation;
class EcXmlReader;

class EC_ACTIN_INTERFACE_DECL EcIODataBroker
{
public:

   /// time modes
   enum TimeMode
   {
      AsFastAsPossible,  ///< Open loop running.
      Locked             ///< Lock to input data.
   };

   /// state requested modes
   enum StateRequested
   {
      InitRecieved,      ///< Input requests initialization of simulation.
      ResetReceived,     ///< Input requests reset of simulation.
      DataReceived,      ///< Input received data.
      NothingReceived    ///< No update from input.
   };

   /// Constructor
   EcIODataBroker
      (
      );

   /// Destructor
   virtual ~EcIODataBroker
      (
      );

   /// Load simulation from file.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean loadFile
      (
      const EcString& fileName ///< [in] Simulation file to load
      );

   /// Load simulation from stream
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean loadStream
      (
      EcXmlReader& reader ///< [in] Simulation stream to load from
      );

   /// Merge existing simulation with new file.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean merge
      (
      const EcString& fileName ///< [in] The name of the file to load
      );

   /// prepare itself for the plugins. This includes manage priority of the plugins.
   virtual void registerPlugins
      (
      );

   /// register a new plugin
   virtual void registerPlugin
      (
      Ec::Plugin* plugin ///< [in] Plugin pointer to operate on
      );

   /// Calls reset() on all currently loaded plugins.  Used when [re-]loading a file.
   virtual void resetPlugins
      (
      );

   /// set input data to simulation, run one simulation cycle, and set the output data to output plugins
   virtual void runSimulationCycle
      (
      );

   /// start the loop that manages the data flow
   virtual void startSimulation
      (
      );

   /// stop the loop that manages the data flow
   virtual void stopSimulation
      (
      );

   /// pause the simulation timer
   virtual void pauseSimulation
      (
      );

   /// Allows other threads to wait on the simulation to finish its timestep.
   virtual void waitUntilSimulationStep
      (
      );

   /// Get the rate at which the simulation is updating.
   EcU32 simulationPeriodInMs
      (
      ) const;

   /// set time
   virtual void setTime
      (
      const EcReal currentTime ///< [in] Current time
      );

   /// gets the rate at which to run the simulation in Hz
   virtual EcReal rate
      (
      ) const;

   /// sets the rate at which to run the simulation in Hz
   virtual void setRate
      (
      const EcReal value ///< [in] Simulation rate in Hz
      );

   /// returns the time elapsed in seconds since the simulation started
   virtual EcReal elapsedSimulationTime
      (
      ) const;

   /// Returns the amount of time taken to calculate last state.
   EcReal calculationTime
      (
      ) const;

   /// Difference in time.
   EcReal timeDifference
      (
      ) const;

   /// Get the pointer to the simulation thread, allows realtime access control
   /// of the thread.
   Ec::AsyncThread * simulationThread
      (
      );

   /// Get the pointer to the simulation thread, allows realtime access control
   /// of the thread.
   Ec::AsyncThread * pluginThread
      (
      Ec::Plugin * plugin  ///< Plugin to find the thread of.
      );

protected:
   /// Initialize internal state based upon simulation file loaded.
   /// @return EcBoolean Success or failure of command
   virtual EcBoolean initState
      (
      );

   /// Intialize a newly-loaded plugin.
   /// @return    EcBoolean Success or failure of command
   EcBoolean initPlugin
      (
      Ec::Plugin* plugin ///< [in] Plugin pointer to operate on
      );

   /// Remove memory associated with a plugin.
   /// @return    EcBoolean Success or failure of command
   EcBoolean unloadPlugin
      (
      Ec::Plugin* plugin ///< [in] Plugin pointer to operate on
      );

   /// Calls the shutdown() method on all plugins.  This happens right before
   /// stopping and deleting the simulation.  Plugins are unloaded after that.
   void shutdownPlugins
      (
      );

   typedef boost::scoped_ptr<Ec::SimulationThread> SimulationPtrType;   ///< boost scoped pointer for simulation thread
   typedef boost::ptr_vector<Ec::PluginThread> PluginThreadVectorPtr;   ///< boost pointer vector for plugin thread
   typedef boost::scoped_ptr<Ec::IOBuffer> IOBufferPtrType;             ///< boost scoped pointer for io buffer

   mutable EcMutex       m_OutputDataMutex;     ///< Mutex to protect output data
   EcCondition           m_OutputDataCondition; ///< Plugin thread wait condition
   SimulationPtrType     m_pAsyncSimThread;     ///< Simulation thread
   PluginThreadVectorPtr m_vPluginThreadPtr;    ///< Plugin threads
   EcElapsedTime         m_SimulationTimer;     ///< Simulation timer
   EcMicroTimer          m_CalculationTime;     ///< Time taken to compute
   EcReal                m_Time;                ///< Current time value
   EcReal                m_Rate;                ///< Rate at which to run simulation
   IOBufferPtrType       m_BufferPtr;           ///< Location for all simulation data
   Ec::SimulationRunState m_SimRunState;        ///< Local copy of simulation state
   mutable EcMutex       m_TimerMutex;          ///< Mutex to protect timers
   EcMicroTimer          m_ThreadTimer;         ///< Timer used to compute time difference
   EcBoolean             m_LoadPlugins;         ///< Flag to load plugin config saved in simulation filed
};

#endif // ecIODataBroker_H_
