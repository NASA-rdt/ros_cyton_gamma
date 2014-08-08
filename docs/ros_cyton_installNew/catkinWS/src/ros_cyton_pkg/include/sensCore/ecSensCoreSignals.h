#ifndef ec_SensCoreSignals_H_
#define ec_SensCoreSignals_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecSensCoreSignals.h
/// @brief Provides traits classes for signals used by sensCore.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecConstants.h>

#include "ecImage.h"
#include <foundCommon/ecCoordSysXForm.h>

#include <boost/mpl/string.hpp>

#ifndef WIN32
// Avoid getting warnings from gcc related to the use of multichar below.
// FIXME: I would like to use "diagnostic ignored"; however, the pragma does not seem to work.
//        system_header is a bit heavy-handed here.
//#  pragma GCC diagnostic ignored "-Wmultichar"
#  pragma GCC system_header
#endif

// Forward declarations
class EcCoordinateSystemTransformation;
class EcImage;

namespace Ec
{

struct ImageRequestResult
{
   EcImage                          image;
   EcCoordinateSystemTransformation cameraPose;
   EcReal                           horizontalIfov;
   EcReal                           verticalIFov;
};

//------------------------------------------------------------------------------
// Combiner struct that will exit the first time a non-null EcImage is found
// meaning the image was successfully provided.
struct ImageRequestCombiner
{
   typedef ImageRequestResult* result_type;
   template <typename T> result_type operator()(T f, T l) const
   {
      result_type r = EcNULL;
      for (; f != l; ++f)
      {
         r = *f;
         if (r != EcNULL)
         {
            break;
         }
      }

      return r;
   }
};

//------------------------------------------------------------------------------
/// Signal to request an image
/// @param cameraName The source of the image to cleanup
struct SignalImageRequest
{
   typedef boost::mpl::string<'imag', 'eReq', 'uest'> Name;
   typedef ImageRequestCombiner Combiner;
   typedef Combiner::result_type (Type)(const EcString& cameraName);
};

//------------------------------------------------------------------------------
/// Signal to cleanup a previously requested image
/// @param cameraName The source of the image to cleanup
struct SignalImageCleanup
{
   typedef boost::mpl::string<'imag', 'eCle', 'anup'> Name;
   typedef void (Type)(const EcString& cameraName);
};

} // namespace Ec

#endif // ec_SensCoreSignals_H_
