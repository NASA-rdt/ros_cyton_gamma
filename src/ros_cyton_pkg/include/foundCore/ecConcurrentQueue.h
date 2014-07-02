#ifndef ecConcurrentQueue_H_
#define ecConcurrentQueue_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecConcurrentQueue.h
/// @class EcConcurrentQueue
/// @brief Provides a thread safe FIFO queue data container.
///        This container will manage threads by allowing them to wait until elements
///        are available to pop. This is used manage work flow in a mulitple
///        producer/consumer threading model.
//
//------------------------------------------------------------------------------

#include "ecConstants.h"

#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <queue>


template<typename Data>
class EcConcurrentQueue
{
public:
         /// constructor
	EcConcurrentQueue() 
	{
	}

        /// destructor
	virtual ~EcConcurrentQueue() 
	{
	}

        /// push adds data to the top of the queue
	virtual void push(const Data& data)
	{
		boost::mutex::scoped_lock lock(m_Mutex);
		m_Queue.push(data);
		lock.unlock();
		m_ConditionVariable.notify_one();
	}

        /// size returns the number of elements currently in the queue
	virtual inline EcU32 size() const { return m_Queue.size();  }

        /// returns false if the queue contains data
	virtual EcBoolean empty()
	{
		boost::mutex::scoped_lock lock(m_Mutex);
		return m_Queue.empty();
	}

        /// clears the contents of the queue
	virtual inline void clear() 
	{
		boost::mutex::scoped_lock lock(m_Mutex);
		m_Queue = std::queue<Data>();
	}

        /// This method allows a thread to try to pop an element from the queue
        /// and does not block the thread if the queue is empty
	virtual bool try_pop(Data& poppedValue)
	{
		boost::mutex::scoped_lock lock(m_Mutex);
		if( m_Queue.empty() )
			return EcFalse;

		poppedValue = m_Queue.front();
		m_Queue.pop();
		return EcTrue;
	}

        /// This method will block the queue until an element is available
        /// Multiple threads can be waiting at the same time. When an element is pushed
        /// into the queue only one waiting thread will be notified and allowed to pop.
	virtual void wait_and_pop(Data& poppedValue)
	{
		boost::mutex::scoped_lock lock(m_Mutex);
		while( m_Queue.empty() ) 
		{
			m_ConditionVariable.wait(lock);
		}
		poppedValue = m_Queue.front();
		m_Queue.pop();
	}

protected:
        std::queue<Data>           m_Queue;              ///< the queue container
        boost::mutex               m_Mutex;              ///< a mutex for thread safe push and pop

        /// a condition variable to notify waiting threads
        /// that a new element has been pushed into the queue
        boost::condition_variable  m_ConditionVariable;
};

#endif // ecConcurrentQueue_H_
