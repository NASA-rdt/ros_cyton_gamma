#ifndef ec_FileUtil_H_
#define ec_FileUtil_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecFileUtil.h
/// @class Ec::FileUtil
/// @brief Set of utilities to find and track the location of files during load.
//
//------------------------------------------------------------------------------
#include "ecConstants.h"
#include "ecMutex.h"

namespace Ec
{

class Application;

class EC_STABLE_FOUNDCORE_DECL FileUtil
{
public:
   /// Type for holding and exclusive file lock.
#if WIN32
   typedef void*   ExclusiveFileHandle;
#else
   typedef EcInt32 ExclusiveFileHandle;
#endif

   /**
   @brief A method to return the instance of this class. The instance is not
   created until this method is called the first time.
   */
   static FileUtil& instance
      (
      );

   /// Search for a file.  If given a path (relative or absolute), look there
   /// first.  If it fails, then based upon the search trait will either fail or
   /// continue with the search paths until it either finds a matching file or
   /// fails.
   /// @return EcString Either empty string or fully-qualified path + filename
   EcString findFile
      (
      const EcString& fileName ///< [in] File to search for
      );

   /// Append a search directory when performing file loading.
   /// @return EcBoolean Success or failure of command
   EcBoolean addDirectory
      (
      const EcString& path ///< [in] Directory path to add
      );

   /// Empty the search path list.
   void clearDirectories
      (
      );

   /// Specify a data directory path for a given repository name.
   void setDataDirectory
      (
      const EcString& name, ///< [in] Named repository to set
      const EcString& path ///< [in] Path to assign to this repository name
      );

   /// Retrieve data directory path.  With no argument, it returns the toolkit
   /// data directory, either from the environment variable \$(EC_TOOLKITS)/data
   /// or from a previous setDataDirectory() call.
   /// @return EcString Empty string or fully-qualified path to data directory
   EcString getDataDirectory
      (
      const EcString& name = "toolkits" ///< [in] Repository path to retrieve
      );

   /// Retrieve the Most Recently Used file path (path + file).
   /// @return EcString Last file used when loading in a file 
   EcString getMruFilePath
      (
      );

   /// Save off the Most Recently Used file path (path + file).  This is saved on a per-user
   /// basis. On windows it is a registry setting, on all other platforms it is
   /// saved in $HOME/.energidrc
   /// @return EcBoolean Success or failure of command
   EcBoolean setMruFilePath
      (
      const EcString& dir ///< [in] file path to set
      );

   /// Retrieve the last file path (path + file) used when explicitly loading a plugin.
   /// @return EcString Last file path used when loading in a plugin
   EcString getPluginMruFilePath
      (
      );

   /// Save off the plugin file path (path + file).  This is saved on a per-user basis.
   /// On windows it is a registry setting, on all other platforms it is saved
   /// in $HOME/.energidrc
   /// @return EcBoolean Success or failure of command
   EcBoolean setPluginMruFilePath
      (
      const EcString& filePath ///< [in] file path to set
      );

   /// Platform-specific implementation to open up a file for exclusive access.
   /// @param[in,out] fileName Name of file to open.  Actual opened file returned
   /// @param[out] handle Platform-specific handle to open file if successful
   /// @param[in] renameIfExists Whether to keep trying until a unique name is found
   /// @return EcBoolean Success or failure of command
   static EcBoolean openExclusiveFile
      (
      EcString& fileName,
      ExclusiveFileHandle& handle,
      const EcBoolean renameIfExists = EcTrue
      );

   /// Platform-specific implementation to close an exclusive file.
   void closeExclusiveFile
     (
     ExclusiveFileHandle& handle ///< [in] Platform-specific handle to open file
     );

protected:
   friend class Application;

   /// Default constructor
   FileUtil
      (
      );

   /// Replaces backslashes with forward slashes.
   void convertPathSeparator
      (
      EcString& fileName ///< [in,out] Path to modify
      );

   EcSharedMutex m_DirectoryListMutex; ///< Serializes access to m_DirectoryList
   EcStringVector m_DirectoryList;     ///< List of paths to search
   EcBoolean m_ExactFileMatch;         ///< Whether to limit to exact matches

   EcMutex m_DataDirMapMutex;          ///< Serializes access to m_DataDirMap
   EcStringStringMap m_DataDirMap;     ///< Data repository path lookup

   EcMutex m_MruMutex;                 ///< Serializes access to m_MruDir and m_PluginDir
   EcString m_MruFilePath;             ///< Most Recently Used file path
   EcString m_PluginDir;               ///< Most Recently Used plugin directory
};

} // namespace Ec

#endif // ec_FileUtil_H_
