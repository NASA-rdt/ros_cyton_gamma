#ifndef ec_ConnectionManagerTypes_H_
#define ec_ConnectionManagerTypes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecConnectionManagerTypes.h
/// @class Ec::ConnectionManagerTypes
/// @brief Provides signal mechanism for plugins and simulation components.
/// @todo Better document Signal struct. Can it be removed?
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.

#include <boost/signals2/signal.hpp>

namespace Ec
{

//------------------------------------------------------------------------------
struct ConnectionManagerTypes
{
   /// convenient typedef for a boost connection
   typedef boost::signals2::connection        ConnectionType;

   /// convenient typedef for a boost scoped connection
   typedef boost::signals2::scoped_connection ScopedConnectionType;

   /// inner struct for describing signals
   /// @tparam T First type used in the signal
   /// @tparam C Second type 
   template <typename T, typename C=boost::signals2::optional_last_value<typename boost::function_traits<T>::result_type> >
   struct Signal
   {
      /// convenient typedef for a two-tparameter signal
      typedef typename boost::signals2::signal<T,C> Type;

      /// convenient typedef for a shared pointer of the two-tparameter signal type
      typedef boost::shared_ptr<Type>               PtrType;
   };
};

} // namespace Ec

#endif // ec_ConnectionManagerTypes_H_
