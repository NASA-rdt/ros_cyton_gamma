#ifndef ecDllLoader_H_
#define ecDllLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecDllLoader.h
/// @class EcDllLoader
/// @brief Wrapper for DLL and Shared Object code
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecMacros.h"

/// Wrapper for DLL and Shared Object code

class EC_STABLE_FOUNDCORE_DECL EcDllLoader
{
public:
   EcDllLoader
      (
      );

   virtual ~EcDllLoader
      (
      );

   /// Loads a shared library and returns its handle.
   /// \param[in] libraryName Name of library to load.  Can be sent with or without
   ///                        extension.
   /// \param[in] extension   Name of library extension.  Used if libraryName does
   ///                        not include an extension.
   /// \return    void *      Platform-specific handle to loaded library or EcNULL on failure.
   virtual void * loadDll
      (
      const EcString& libraryName,
      const EcString& extension = EcDllLoader::librarySuffix()
      );

   /// Closes any loaded library.
   /// \param[in] handle Platform-specific handle to loaded libarary.
   static void unloadDll
      (
      void *handle
      );

   /// Attempts to retrieve a C-style function pointer.
   /// \param[in] functionName Name of C function w/o arguments.
   /// \return const void * Platform-specific handle to functor.
   virtual const void * getFunction
      (
      const EcString& functionName
      );

   /// Retrieves the shared library extension.
   /// \return const EcString& Platform-specific extension for shared libraries.
   static const EcString& librarySuffix
      (
      );

   /// Sets the shared library extension
   /// \param[in] librarySuffix Platform-specific extension for shared libraries.
   static void setLibrarySuffix
      (
      const EcString& librarySuffix
      );

protected:
   static EcString m_LibrarySuffix; ///< Platform-dependent suffix for shared libraries.
   void*           m_LibraryHandle; ///< Opaque handle to loaded library.
};

#endif // ecDllLoader_H_
