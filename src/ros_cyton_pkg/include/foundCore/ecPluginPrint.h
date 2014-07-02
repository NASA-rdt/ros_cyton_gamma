#ifndef ecPluginPrint_H_
#define ecPluginPrint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginPrint.h
/// @brief Printing capability for plugins regardless of whether
///        they are compiled with or without the Actin libraries.
/// @details Print stream macros The following C++ output stream macros are available:
///
/// EcTRACE - Very verbose printing
/// EcDEBUG - Debugging statements.  Turned on in debug builds
/// EcINFO  - Informational messages
/// EcWARN  - Non-fatal, undesirable behavior
/// EcERROR - Serious problem, typically fatal or unrecoverable
/// EcPRINT - Always print out without prefix
///
/// @def EC_ADD_PRINT_HANDLE(std::stream&) - This will append the given
///                                     output stream to be used
///                                     with the above macros.
/// @def EC_REMOVE_PRINT_HANDLE(std::stream&) - Remove the attached stream.  This is
///                                        necessary if unloading a plugin yet
///                                        still keeping the application active.
//
//------------------------------------------------------------------------------

#  if !defined(EC_NO_ACTIN)
// Use Actin's printing facility, but add our stream support
#    define EC_ADD_PRINT_HANDLE(x)    Ec::Print::addStreamHandle(x)
#    define EC_REMOVE_PRINT_HANDLE(x) Ec::Print::removeStreamHandle(x)
#  elif defined(EC_NO_ACTIN_LIBS)
// In the extreme case where we don't link against any Actin libraries, we
// just redirect the printing to cout or cerr.
#    include <iostream>
#    define EcTRACE std::cout << "EcTrace: "
#    define EcDEBUG std::cout << "EcDebug: "
#    define EcINFO  std::cout << "EcInfo : "
#    define EcWARN  std::cerr << "EcWarn : "
#    define EcERROR std::cerr << "EcError: "
#    define EcPRINT std::cout
     // No support for multi-output streaming
#    define EC_ADD_PRINT_HANDLE(x)
#    define EC_REMOVE_PRINT_HANDLE(x)
#  else
#    include <ostream>

namespace Ec
{

/// Use the same enumerations from the main Actin headers.
enum PrintType
{
   PrintAll = 0, ///< Stub - not used in plugin code
   PrintTrace,   ///< "EcTrace: "
   PrintDebug,   ///< "EcDebug: "
   PrintInfo,    ///< "EcInfo : "
   PrintWarning, ///< "EcWarn : "
   PrintError,   ///< "EcError: "
   PrintFatal,   ///< Stub - not supported in plugins
   PrintNone     ///< No prefix / Print no message
};

EC_STABLE_FOUNDCORE_DECL std::ostream&
PluginPrint
   (
   const PrintType level
   );

EC_STABLE_FOUNDCORE_DECL void
addStreamHandle
   (
   std::ostream& handle
   );

EC_STABLE_FOUNDCORE_DECL void
removeStreamHandle
   (
   std::ostream& handle
   );

} // namespace Ec

#    define EcTRACE                   EcPrint(Trace)
#    define EcDEBUG                   EcPrint(Debug)
#    define EcINFO                    EcPrint(Info)
#    define EcWARN                    EcPrint(Warning)
#    define EcERROR                   EcPrint(Error)
#    define EcPRINT                   EcPrint(None)
#    define EC_ADD_PRINT_HANDLE(x)    Ec::addStreamHandle(x)
#    define EC_REMOVE_PRINT_HANDLE(x) Ec::removeStreamHandle(x)

#  endif  // defined(EC_NO_ACTIN)

#endif // ecPluginPrint_H_
