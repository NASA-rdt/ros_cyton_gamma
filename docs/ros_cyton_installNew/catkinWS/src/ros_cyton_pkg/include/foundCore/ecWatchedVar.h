#ifndef ecWatchedVar_H_
#define ecWatchedVar_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecWatchedVar.h
/// @class Ec::EcWatchedVar
/// @brief A template class for timed waits on data
/// @details This template class provides updating, notification, and waiting for
///          a data value within some millisecond duration.
//
//------------------------------------------------------------------------------
#include "ecWait.h"
#include "ecMutex.h"

#include <boost/thread/thread.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/bind.hpp>

namespace Ec
{

template <typename T>
class EcWatchedVar
{
public:
   /// default constructor
   EcWatchedVar
      (
      ) : var(T())
   {
   }

   /// constructor
   /**
   Non-default constructor with initial value
   @param[in] _val initial value for the instance
   */
   EcWatchedVar
      (
      const T& _val
      ) : var(_val)
   {
   }

   /// destructor
   virtual ~EcWatchedVar
      (
      )
   {
   }

   ///  copy constructor
   EcWatchedVar
      (
      const EcWatchedVar& rhs
      )
   {
      EcMutexScopedLock lock (mutex);
      var = rhs.var;
      cond.notify_all();
   }

   /// assignment operator
   EcWatchedVar& operator=
      (
      const EcWatchedVar& rhs
      )
   {
      if ( this == &rhs )
      {
         return *this;
     }
      EcMutexScopedLock lock (mutex);
      var = rhs.var;
      cond.notify_all();
      return *this;
   }

   /// accessor
   /**
   Accessor for value
   @return current value of the variable
   */
   T get
      (
      ) const
   {
      return var;
   }

   /// timedWaitForVal
   /**
   wait for the variable to attain the specified value, within milliSeconds
   Zero milliseconds means do not wait. Negative value means wait forever
   @param[in] _val target value to wait for
   @param[in] _milliSeconds time to wait for variable to achieve the target value
   @return EcBoolean return true of value is achieved within milliseconds, false otherwise
   */
   EcBoolean timedWaitForVal
      (
      const T& _val,
      const EcInt64 _milliSeconds = 0
      )
   {
      EcMutexScopedLock lock (mutex);

      if ( _val == var )
      {
         return true;
      }

      boost::posix_time::time_duration AlarmTime = boost::posix_time::milliseconds(_milliSeconds);
      if ( cond.timed_wait ( lock , AlarmTime, boost::bind ( std::equal_to<T>(), boost::bind(&Ec::EcWatchedVar<T>::get,this), _val) ))
       {
          return true;
       }
       return false;
   }

   /// set value and notify anyone waiting
   /**
   Set the variable to the specified value and notify anyone waiting that there is a new value to check
   @param[in] _val the new value for the watched variable
   */
   void set
      (
      const T& _val
      )
   {
      EcMutexScopedLock lock (mutex);
      var = _val;
      cond.notify_all();
   }

protected:
   volatile T        var;   ///< the value holder
   boost::condition  cond;  ///< condition variable for signalling
   EcMutex           mutex; ///< mutex for protecting the value
};

} // namespace Ec

#endif // ecWatchedVar_H_
