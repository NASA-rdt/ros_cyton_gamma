#ifndef ec_Signals_H_
#define ec_Signals_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecSignals.h
/// @brief Provides macros to facilitate the use of signals.
/// @todo complete documenation of these macros
//
//------------------------------------------------------------------------------
#include "ecApplication.h"
#include "ecConnectionManager.h"

/// foundation macro for Ec signal name 
/// @param x 
#define _ECSN(x)       boost::mpl::c_str<x::Name>::value     

/// foundation macro for creating a named signal 
/// @param src 
/// @param x 
#define _ECSNS(src, x) _ECCM.namedSignal(_ECSN(x), src)      

/// foundation macro to get signal type
/// @param x  
#define _ECST(  x)     x::Type            

/// foundation macro to get the signal type and combiner
/// @param x   
#define _ECST_R(x)     _ECST(x),x::Combiner       

/// foundation macro to get the connectionManager
#define _ECCM          Ec::Application::instance().connectionManager()   

//------------------------------------------------------------------------------
/// foundation macro to create inner struct for describing signals
/// @param x  
#define _EC_SIGNAL(  x) Ec::ConnectionManagerTypes::Signal<x>    

/// foundation macro to create the signal struct of a particular type
/// @param x  
#define  EC_SIGNAL(  x) _EC_SIGNAL(_ECST(x))      

/// foundation macro to create the signal struct of a particular type and combiner
/// @param x  
#define  EC_SIGNAL_R(x) _EC_SIGNAL(_ECST_R(x))                          

//------------------------------------------------------------------------------
/// Registers signal with the connection manager using #_ECCM
/// @param traits
/// @param provider   
#define EC_SIGNAL_REGISTER(traits, provider) \
        _ECCM.registerSignal<_ECST(traits)>(_ECSN(traits), provider)

/// Registers signal (with combiner result support) with the connection manager using #_ECCM
/// @param traits
/// @param provider  
#define EC_SIGNAL_REGISTER_R(traits, provider) \
	_ECCM.registerSignal<_ECST_R(traits)>(_ECSN(traits), provider)    

//------------------------------------------------------------------------------
/// Registers a named signal with the connection manager using #_ECCM
/// @param traits
/// @param provider  
#define EC_NAMED_SIGNAL_REGISTER(traits, provider) \
      _ECCM.registerSignal<_ECST(traits)>(_ECSNS(provider,traits), provider)

/// Registers a named signal (with combiner result support) with the connection manager using #_ECCM
/// @param traits
/// @param provider  
#define EC_NAMED_SIGNAL_REGISTER_R(traits, provider) \
      _ECCM.registerSignal<_ECST_R(traits)>(_ECSNS(provider,traits), provider)

//------------------------------------------------------------------------------
/// Connects a slot to the signal with the connection manager #_ECCM
/// @param traits
/// @param func
/// @param group  
#define _EC_CONNECT(traits, func, group) \
   _ECCM.connectSlot<_ECST(traits)>(this, _ECSN(traits), func group)

/// Connects a slot to the signal (with combiner result support) using the connection manager #_ECCM
/// @param traits
/// @param func
/// @param group
#define _EC_CONNECT_R(traits, func, group) \
   _ECCM.connectSlot<_ECST_R(traits)>(this, _ECSN(traits), func group)

//------------------------------------------------------------------------------
/// Connects a slot to a named signal using the connection manager #_ECCM
/// @param src
/// @param traits
/// @param func
/// @param group
#define _EC_NAMED_CONNECT(src, traits, func, group) \
   _ECCM.connectSlot<_ECST(traits)>(this, _ECSNS(src,traits), func group)

/// Connects a slot to a named signal (with combiner) using the connection manager #_ECCM
/// @param src
/// @param traits
/// @param func
/// @param group
#define _EC_NAMED_CONNECT_R(src, traits, func, group) \
   _ECCM.connectSlot<_ECST_R(traits)>(this, _ECSNS(src,traits), func group)

//------------------------------------------------------------------------------
/// Default connection macro with no additional arguments
/// @param traits
/// @param method  
#define EC_CONNECT_M0(traits, method) \
   _EC_CONNECT(traits, boost::bind(&method, this),)

/// Default connection macro with one additional argument
/// @param traits
/// @param method
#define EC_CONNECT_M1(traits, method) \
   _EC_CONNECT(traits, boost::bind(&method, this, _1),)

/// Default connection macro with two additional arguments
/// @param traits
/// @param method
#define EC_CONNECT_M2(traits, method) \
   _EC_CONNECT(traits, boost::bind(&method, this, _1, _2),)

/// Default connection macro with three additional arguments
/// @param traits
/// @param method
#define EC_CONNECT_M3(traits, method) \
   _EC_CONNECT(traits, boost::bind(&method, this, _1, _2, _3),)

//------------------------------------------------------------------------------
/// Default named signal connection macro with no additional arguments
/// @param src
/// @param traits
/// @param method
#define EC_NAMED_CONNECT_M0(src, traits, method) \
   _EC_NAMED_CONNECT(src, traits, boost::bind(&method, this),)

/// Default named signal connection macro with one additional argument
/// @param src
/// @param traits
/// @param method
#define EC_NAMED_CONNECT_M1(src, traits, method) \
   _EC_NAMED_CONNECT(src, traits, boost::bind(&method, this, _1),)

/// Default named signal connection macro with two additional arguments
/// @param src
/// @param traits
/// @param method
#define EC_NAMED_CONNECT_M2(src, traits, method) \
   _EC_NAMED_CONNECT(src, traits, boost::bind(&method, this, _1, _2),)

/// Default named signal connection macro with three additional arguments
/// @param src
/// @param traits
/// @param method
#define EC_NAMED_CONNECT_M3(src, traits, method) \
   _EC_NAMED_CONNECT(src, traits, boost::bind(&method, this, _1, _2, _3),)

//------------------------------------------------------------------------------
/// Connection macro to provide combiner result support
/// @param traits
/// @param method
#define EC_CONNECTR_M1(traits, method) \
   _EC_CONNECT_R(traits, boost::bind(&method, this, _1),)

/// @copydoc EC_CONNECTR_M1
#define EC_CONNECTR_M2(traits, method) \
   _EC_CONNECT_R(traits, boost::bind(&method, this, _1, _2),)

/// @copydoc EC_CONNECTR_M1
#define EC_CONNECTR_M3(traits, method) \
   _EC_CONNECT_R(traits, boost::bind(&method, this, _1, _2, _3),)

//------------------------------------------------------------------------------
/// Connection macro to provide named combiner result support
/// @param src
/// @param traits
/// @param method
#define EC_NAMED_CONNECTR_M1(src, traits, method) \
   _EC_NAMED_CONNECT_R(src, traits, boost::bind(&method, this, _1),)

/// @copydoc EC_NAMED_CONNECTR_M1
#define EC_NAMED_CONNECTR_M2(src, traits, method) \
   _EC_NAMED_CONNECT_R(src, traits, boost::bind(&method, this, _1, _2),)

/// @copydoc EC_NAMED_CONNECTR_M1
#define EC_NAMED_CONNECTR_M3(src, traits, method) \
   _EC_NAMED_CONNECT_R(src, traits, boost::bind(&method, this, _1, _2, _3),)

//------------------------------------------------------------------------------
/// These provide grouping prioritization of signals
#define EC_CONNECTG(traits, func, group) \
   _EC_CONNECT(traits, func, BOOST_PP_COMMA() group)

///@copydoc EC_CONNECTG
#define EC_CONNECTG_M1(traits, method, group) \
   EC_CONNECTG(traits, boost::bind(&method, this, _1), group)

///@copydoc EC_CONNECTG
#define EC_CONNECTG_M2(traits, method, group) \
   EC_CONNECTG(traits, boost::bind(&method, this, _1, _2), group)

///@copydoc EC_CONNECTG
#define EC_CONNECTG_M3(traits, method, group) \
   EC_CONNECTG(traits, boost::bind(&method, this, _1, _2, _3), group)

//------------------------------------------------------------------------------
/// These provide named grouping prioritization of signals
#define EC_NAMED_CONNECTG(src, traits, func, group) \
   _EC_NAMED_CONNECT(src, traits, func, BOOST_PP_COMMA() group)

///@copydoc EC_NAMED_CONNECTG
#define EC_NAMED_CONNECTG_M1(src, traits, method, group) \
   EC_NAMED_CONNECTG(src, traits, boost::bind(&method, this, _1), group)

///@copydoc EC_NAMED_CONNECTG
#define EC_NAMED_CONNECTG_M2(src, traits, method, group) \
   EC_NAMED_CONNECTG(src, traits, boost::bind(&method, this, _1, _2), group)

///@copydoc EC_NAMED_CONNECTG
#define EC_NAMED_CONNECTG_M3(src, traits, method, group) \
   EC_NAMED_CONNECTG(src, traits, boost::bind(&method, this, _1, _2, _3), group)

//------------------------------------------------------------------------------
/// These provide grouping prioritization of signals and combiner result support
#define EC_CONNECTGR(traits, func, group) \
   _EC_CONNECT_R(traits, func, BOOST_PP_COMMA() group)

///@copydoc EC_CONNECTGR
#define EC_CONNECTGR_M1(traits, method, group) \
   EC_CONNECTGR(traits, boost::bind(&method, this, _1), group)

///@copydoc EC_CONNECTGR
#define EC_CONNECTGR_M2(traits, method, group) \
   EC_CONNECTGR(traits, boost::bind(&method, this, _1, _2), group)

///@copydoc EC_CONNECTGR
#define EC_CONNECTGR_M3(traits, method, group) \
   EC_CONNECTGR(traits, boost::bind(&method, this, _1, _2, _3), group)

//------------------------------------------------------------------------------
/// These provide named grouping prioritization of signals and combiner result support
#define EC_NAMED_CONNECTGR(src, traits, func, group) \
   _EC_NAMED_CONNECT_R(src, traits, func, BOOST_PP_COMMA() group)

///@copydoc EC_NAMED_CONNECTGR
#define EC_NAMED_CONNECTGR_M1(src, traits, method, group) \
   EC_NAMED_CONNECTGR(src, traits, boost::bind(&method, this, _1), group)

///@copydoc EC_NAMED_CONNECTGR
#define EC_NAMED_CONNECTGR_M2(src, traits, method, group) \
   EC_NAMED_CONNECTGR(src, traits, boost::bind(&method, this, _1, _2), group)

///@copydoc EC_NAMED_CONNECTGR
#define EC_NAMED_CONNECTGR_M3(src, traits, method, group) \
   EC_NAMED_CONNECTGR(src, traits, boost::bind(&method, this, _1, _2, _3), group)

#endif // ec_Signals_H_
