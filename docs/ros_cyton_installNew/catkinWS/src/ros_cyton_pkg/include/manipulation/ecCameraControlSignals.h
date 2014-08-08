#ifndef ecCameraControlSignals_H_
#define ecCameraControlSignals_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecCameraControlSignals.h
/// @brief Provides traits classes for signals used by sensCore.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecConstants.h>

#include <boost/mpl/string.hpp>

#ifndef WIN32
// Avoid getting warnings from gcc related to the use of multichar below.
// FIXME: I would like to use "diagnostic ignored"; however, the pragma does not seem to work.
//        system_header is a bit heavy-handed here.
//#  pragma GCC diagnostic ignored "-Wmultichar"
#  pragma GCC system_header
#endif

// Forward declarations

namespace Ec
{

//------------------------------------------------------------------------------
/// Signal to set focus distance
/// @param cameraName The name of camera
/// @param focusDistance The focus distance
struct SignalSetFocusDistance
{
   /// type definition of Name
   typedef boost::mpl::string<'setF', 'ocus', 'Dist', 'ance'> Name;
   /// type definition of (Type)(const EcString& cameraName, const EcReal focusDistance)
   typedef void (Type)(const EcString& cameraName, const EcReal focusDistance);
};

//------------------------------------------------------------------------------
/// Signal to trigger image capture
/// @param cameraName The name of camera
struct SignalTriggerImageCapture
{
   /// type definition of Name
   typedef boost::mpl::string<'trig', 'gerI', 'mage', 'Capt', 'ure'> Name;
   /// type definition of (Type)(const EcString& cameraName)
   typedef void (Type)(const EcString& cameraName);
};

} // namespace Ec

#endif // ecCameraControlSignals_H_
