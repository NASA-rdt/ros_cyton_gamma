#ifndef ec_Application_H_
#define ec_Application_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecApplication.h
/// @class Ec::Application
/// @brief Provides global allocation and access to manager objects.
//
//------------------------------------------------------------------------------
#include "ecMacros.h"  // Required to be first header.

#include <boost/any.hpp>
#include <boost/noncopyable.hpp>

namespace Ec
{

// Forward declarations
class ConnectionManager;
class FileUtil;
class Plugin;
class PluginManager;
class Print;

//------------------------------------------------------------------------------
class EC_STABLE_FOUNDCORE_DECL Application : private boost::noncopyable
{
public:
   
   /// a static method that returns the only instance of this class. The instance is only created
   /// the first time this method is called
   static Application& instance
      (
      );

   /// @copydoc Ec::PluginManager::loadPlugin(const EcString&, const EcBoolean)
   static Plugin *loadPlugin
      (
      const EcString& fileName,
      const EcBoolean unloadOnFailure = EcTrue
      );

   /// @copydoc Ec::PluginManager::unloadPlugin(const EcString&)
   static EcBoolean unloadPlugin
      (
      const EcString& pluginName
      );

   /// @copydoc Ec::FileUtil::findFile(const EcString&)
   static EcString findFile
      (
      const EcString& fileName
      );

   /// @copydoc Ec::FileUtil::addDirectory(const EcString&)
   static EcBoolean addDirectory
      (
      const EcString& path
      );

   /// @copydoc Ec::FileUtil::getDataDirectory(const EcString&)
   static EcString getDataDirectory
      (
      const EcString& name = "toolkits"
      );

   /// @copydoc Ec::FileUtil::getMruFilePath()
   static EcString getMruFilePath
      (
      );

   /// Specify whether to enable or disable file searches when trying to load
   /// a file given the pathname.  The default is to perform the search until it
   /// finds the file or all paths have been searched.  This provides behavior
   /// to the application that keeps it from finding potentially incorrect files
   /// that are named the same as the desired file, but located somewhere else.
   void setFileExactMatch
   (
    const EcBoolean exactMatch ///< [in] Whether to allow searching for files
    );

   /// get the connection manager
   ConnectionManager& connectionManager
      (
      );

   /// get the FileUtil object
   FileUtil& fileUtil
      (
      );

   /// get the plugin manager
   PluginManager& pluginManager
      (
      );

   /// get teh print maanger
   Print& printManager
      (
      );

   /// Provide a mechanism to register global manager objects.  This class will
   /// own the object and cleanup when the application exits.  It also provides
   /// thread-safe access.
   template <typename T>
   void registerManager
      (
      const EcString& mgrName, ///< [in] Name to associate with this manager
      T* pManager              ///< [in] Handle of object to own
      )
   {
      if(pManager)
      {
         m_ManagerMap.insert(std::make_pair(mgrName, boost::any(boost::shared_ptr<T>(pManager))));
      }
   }

   /// Attempt to retrieve a thread-safe handle to a managerial object.
   /// @return T* Handle to object or NULL if unavailable
   template <typename T>
   static T* instance
      (
      const EcString& managerName ///< [in] Name of manager object to retrieve
      )
   {
      ManagerMap::iterator it = instance().m_ManagerMap.find(managerName);
      if(it != instance().m_ManagerMap.end())
      {
         try
         {
            return boost::any_cast<boost::shared_ptr<T> >(it->second).get();
         }
         catch(boost::bad_any_cast&)
         {
         }
      }
      return EcNULL;
   }

   /// A static method to destroy the only instance of this class, if it exists, by deleting it and
   /// setting the static pointer to NULL. A new istance will be created when instance() is called.
   static void destroyInstance
      (
      );

private:
   Application
      (
      );

   ~Application
      (
      );

   /// Perform initialization routines by manager object after constructors.
   void init
      (
      );

   typedef std::map<EcString, boost::any> ManagerMap;
   ManagerMap m_ManagerMap;
};

} // namespace Ec

#endif // ec_Application_H_
