#ifndef ecDeque_H_
#define ecDeque_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecDeque.h
/// @class Ec::EcDeque
/// @brief container for efficient caching of data
/// @details A container class providing efficient caching of data and providing timing
///          mechanisms for waiting for new data or specific data values
///          Deque is properly protected for simultaneous read/write invocations
///
/// @todo Make this a proper template class for more than just strings
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecMutex.h"
#include "ecWait.h"

#include <deque>
#include <boost/thread/condition.hpp>

namespace Ec
{

class EC_STABLE_FOUNDCORE_DECL EcDeque
{
public:
   /// this deque is for EcStrings
   typedef std::deque<EcString> Deque_t;

   /// decimate the specified milliSeconds if it is larger than 100ms
   /// break up long wait intervals into a series of smaller intervals
   /// no longer than this
   enum {DefaultInterval=100};

   /// ctor
   EcDeque
      (
      );

   /// dtor
   ~EcDeque
      (
      );

   /// copy ctor
   EcDeque
      (
      const EcDeque& rhs
      );

   /// assignment operator
   EcDeque& operator=
      (
      const EcDeque& rhs
      );

   /// clear
   /**
   Erase all values from the deque
   */
   void clear
      (
      );

   /// add
   /**
   Add a new data record to the deque. Avoid adding empty data
   @param[in] newRec the new record to add
   @return EcBoolean return true of new record was added, false if new record is empty
   */
   EcBoolean add
      (
      const EcString& newRec
      );

   /// in_avail
   /**
   Return a count of the records (not bytes) in the deque. Note the different meaning from standard
   streams method of the same name

   @return EcU32 the current number of records in the deque, as reported by size()
   */
   EcU32 in_avail
      (
      );

   /// getRec
   /**
   Return a record of data, possibly waiting for it to arrive. A value of zero means do not wait.
   Any negative value means wait forever.

   @param[in,out] rec the value from the deque if there is data within the specified duration
   @param[in] _milliSeconds millisecond duration to wait for data to arrive on the deque
   @return EcBoolean true of data was available within the duration and data is being returned, and data is not empty
   */
   EcBoolean getRec
      (
      EcString& rec,
      const EcInt64 _milliSeconds = 0
      );

   /// searchAndDestroy
   /**
   Look for a matching data record. If found, delete it and return true, otherwise return false.

   @note this method not designed for stand-alone use... no mutex protection

   @param[in] _val specific value to search for on the deque
   @return EcBoolean return true of the record was found and deleted from the deque
   */
   EcBoolean searchAndDestroy
      (
      const EcString& _val
      );

   /// timedWaitForVal
   /**
   Wait a specified duration for the target value to arrive. Zero means do not wait, negative means wait forever.
   If found, then delete it and return true.  Return false otherwise.

   @param[in] _val specific value to search for on the deque
   @param[in] _milliSeconds how long to search for the target value
   @return EcBoolean return true of the target value was found and deleted within the specific duration, false otherwise
   */
   EcBoolean timedWaitForVal
      (
      const EcString& _val,
      const EcInt64 _milliSeconds = 0
      );

protected:
   EcMutex           mutex;    ///< protect the deque
   boost::condition  cond;     ///< for notifying those waiting on values to arrive/change
   Deque_t           buffer;   ///< the std::deque of EcString
};

} // namespace Ec

#endif // ecDeque_H_
