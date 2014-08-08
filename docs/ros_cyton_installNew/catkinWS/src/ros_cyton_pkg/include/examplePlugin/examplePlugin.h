#ifndef examplePlugin_H_
#define examplePlugin_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file examplePlugin.h
/// @class examplePlugin
/// @brief Plugin device driver example for creating code that will
///        interface with Energid's viewer.  It can be used for a
///        variety of applications, from a simple data logger, to a
///        hardware interface, to a customized GUI.
//
//------------------------------------------------------------------------------
#include <foundCore/ecPlugin.h>
#include <fstream>

/// This plugin is mostly an output plugin, but it does set an initial
/// state on startup to initialize the joint angles.
class examplePlugin : public Ec::Plugin
{
public:
   /// Constructor.
   examplePlugin
      (
      );

   /// Destructor.
   ~examplePlugin
      (
      );

   /// Initialize plugin.  Called before first use.
   /// @return EcBoolean Success or failure of reset command.
   EcBoolean init
      (
      );

   /// Reset plugin.  Called in viewer when a new file is loaded.
   /// @return EcBoolean Success or failure of reset command.
   EcBoolean reset
      (
      );

   /// Give ability to set simulation state, used to sync hardware.
   EcBoolean initState
      (
      );

   /// This method will get called at the specified update interval.
   /// @param time Current simulation time
   void update
      (
      const EcReal time
      );

protected:
   std::ofstream m_out; ///< Handle to our output file.
};

#endif // examplePlugin_H_
