#ifndef asyncThreadVectorData_H_
#define asyncThreadVectorData_H_
//-----------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file asyncThreadVectorData.h
//
/// @class Ec::AsyncThreadVectorData
//
/// @brief Vector of AsyncThreadData objects.
//
//-----------------------------------------------------------------------------

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

namespace Ec
{

/// Forward prototype.
class AsyncThreadData;

/// Forward prototype.
class AsyncThread;

/// List of AsyncThreadData objects.
class EC_DECL_EXPORTS AsyncThreadVectorData : public EcXmlCompoundType
{
public:
   ECXMLOBJECT(AsyncThreadVectorData);
   ECXML_XMLOBJECTCREATOR(AsyncThreadVectorData);

   /// @copydoc EcXmlCompoundType
   virtual void registerComponents
      (
      );

   /// Load our configuration from a file.
   virtual EcBoolean configureFromFile
      (
      );

   /// Generate a configuration file.
   virtual EcBoolean createConfigFile
      (
      );

   /// Get configuration file name.
   virtual EcString configFileName
      (
      );

   /// Set configuration file name.
   virtual void setConfigFileName
      (
      const EcString & fileName        ///< New file name.
      );

   /// Does this object have data by that thread name?
   virtual EcBoolean hasThreadData
      (
      EcString threadName              ///< Thread/plugin name.
      ) const;

   /// Get a thread data object by name, return generic data if can't find.
   virtual AsyncThreadData threadData
      (
      EcString threadName              ///< Thread/plugin name.
      ) const;

   /// Set a thread data object by name.
   virtual void setThreadData
      (
      const EcString &threadName,         ///< Thread/plugin name.
      const AsyncThreadData &threadData   ///< Thread data.
      );

   /// Setup a thread based on stored data, or do nothing if no data is present.
   virtual void setupThread
      (
      AsyncThread * thread             ///< Thread.
      );

   /// Store the setup of the thread data.
   virtual void storeThreadSetup
      (  
      AsyncThread * thread             ///< Thread.
      );

protected:

   /// Find a thread by name or return -1
   virtual EcInt32 findByName
      (
      const EcString threadName        ///< thread name.
      ) const;

   EcString                         m_ConfigFile;  ///< Configuration file name. 
   EcXmlVectorType<AsyncThreadData> m_ThreadData;  ///< Thread data object by name.

}; // AsyncThreadListData

} // namespace Ec

#endif // asyncThreadVectorData_H_

