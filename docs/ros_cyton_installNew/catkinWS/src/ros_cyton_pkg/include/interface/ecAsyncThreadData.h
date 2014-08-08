#ifndef ecAsyncThreadData_H_
#define ecAsyncThreadData_H_
//-----------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecAsyncThreadData.h
//
/// @class ec::AsyncThreadData
//
/// @brief Asynchronous thread setup data.
//
//-----------------------------------------------------------------------------

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>


namespace Ec
{

/// Prototype AsynchThread.
class AsyncThread;   

/// Allows users to serialize thread setup state.
class EC_DECL_EXPORTS AsyncThreadData : public EcXmlCompoundType
{
public:
   //--------------------------------------------------------------------------
   // Base calls.
   //--------------------------------------------------------------------------
   
   /// @copydoc EcXmlCompoundType
   virtual void registerComponents
      (
      );

   ECXMLOBJECT(AsyncThreadData);
   ECXML_XMLOBJECTCREATOR(AsyncThreadData);

   //--------------------------------------------------------------------------
   // XML utility.
   //--------------------------------------------------------------------------

   /// Get the XML representation of this object.
   EcString toXml
      (
      ) const;

   /// Set this based on the XML of this object, return success / failure.
   static EcBoolean fromXml
      (
      AsyncThreadData &data,     ///< The data.
      const EcString &xmlStr     ///< The xml.
      );

   //--------------------------------------------------------------------------
   // Thread setup utility.
   //--------------------------------------------------------------------------
   
   /// Setup the thread.
   void setFromThread
      (
      AsyncThread * thread       ///< Thread pointer.
      );

   /// Set thread from the data.
   void setToThread
      (
      AsyncThread * thread       ///< Thread pointer.
      );

   //--------------------------------------------------------------------------
   // Accessor calls.
   //--------------------------------------------------------------------------

   /// Get is this thread realtime.
   virtual EcBoolean realTime
      (
      ) const;

   /// Set is this thread realtime.
   virtual void setRealTime
      (
      const EcBoolean &value
      );

   /// Get the thread name / plugin name.
   virtual EcString threadName
      (
      ) const;

   /// Set the thread name / plugin name.
   virtual void setThreadName
      (
      const EcString &value
      );

   /// Get the update period in milliseconds.
   virtual EcU32 updatePeriodInMs
      (
      ) const;

   /// Set the update period in milliseconds.
   virtual void setUpdatePeriodInMs
      (
      const EcU32 &value
      );

   /// Get the update period in nanoseconds.
   virtual EcU32 updateFractionNs
      (
      ) const;

   /// Set the update period in nanoseconds.
   virtual void setUpdateFractionNs
      (
      const EcU32 &value
      );

   /// Get the threading affinity mask.
   virtual EcU32 threadAffinity
      (
      ) const;

   /// Set the threading affinity mask.
   virtual void setThreadAffinity
      (
      const EcU32 &value
      );

   /// Get the thread priority.
   virtual EcU32 threadPriority
      (
      ) const;

   /// Set the thread priority.
   virtual void setThreadPriority
      (
      const EcU32 &value
      );

protected:
   EcXmlBoolean   m_IsRealTime;        ///< Is this thread realtime or not.
   EcXmlString    m_ThreadName;        ///< The thread / plugin name.
   EcXmlU32       m_UpdatePeriodInMs;  ///< The update period in milliseconds.
   EcXmlU32       m_UpdateFractionNs;  ///< The update period in nanoseconds.
   EcXmlU32       m_ThreadAffinity;    ///< The threading affinity mask.
   EcXmlU32       m_ThreadPriority;    ///< The thread priority.

}; // AsyncThreadData

} // namespace ec

#endif // ecAsyncThreadData_H_

