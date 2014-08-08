#ifndef ec_SignalTypes_H_
#define ec_SignalTypes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecSignalTypes.h
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>
#include <foundCore/ecTypes.h>

#include <boost/mpl/string.hpp>

namespace Ec
{

#ifndef WIN32
// Avoid getting warnings from gcc related to the use of multichar below.
// FIXME: I would like to use "diagnostic ignored"; however, the pragma does not seem to work.
//        system_header is a bit heavy-handed here.
//#  pragma GCC diagnostic ignored "-Wmultichar"
#  pragma GCC system_header
#endif
// NOTE: Must split Name into groups of 4 (or fewer) characters.

//------------------------------------------------------------------------------
/// Signal for status message while reading / writing 
struct SignalReadWriteStatusTraits
{
   typedef boost::mpl::string<'sign', 'alRe', 'adWr', 'iteM', 'sg'> Name;    ///< the signal name
   
   /// Method to provide status messages while reading and writing
   /// @param statusText the status string
   typedef void (Type)(const EcString statusText);
};

//------------------------------------------------------------------------------
/// Signal that gives progress while reading / writing 
struct SignalReadWriteProgressTraits
{
   typedef boost::mpl::string<'sign', 'alRe', 'adWr', 'iteP', 'rogr', 'ess'> Name;   ///< the signal name
   
   /// Method to provide progress while reading and writing
   /// @param progress the progress value
   typedef void (Type)(const EcReal progress);
};

} // namespace Ec

#endif // ec_SignalTypes_H_
