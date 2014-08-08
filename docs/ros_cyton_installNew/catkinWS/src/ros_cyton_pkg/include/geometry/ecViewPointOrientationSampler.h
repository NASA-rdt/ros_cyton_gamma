#ifndef ecViewPointOrientationSampler_H_
#define ecViewPointOrientationSampler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecViewPointOrientationSampler.h
/// @class EcViewPointOrientationSampler
/// @brief Provides a tool for sampling the orientation space specified
///        via view parameters azimuth, elevation, and roll
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecOrientation.h>
#include <xml/ecXmlOrientation.h>
#include <xml/ecXmlVectorType.h>
#include "ecBaseOrientationSampler.h"

/** Provides a tool for sampling the orientation space specified
//              via view parameters azimuth, elevation, and roll
*/
class EC_FOUNDATION_GEOMETRY_DECL EcViewPointOrientationSampler : public EcBaseOrientationSampler
{
public:

   /// a number specifying an invalid sample
   enum{INVALID=0xFFFFFFFF};

   /// default constructor
   EcViewPointOrientationSampler
      (
      );

   /// destructor
   virtual ~EcViewPointOrientationSampler
      (
      );

   /// copy constructor
   EcViewPointOrientationSampler
      (
      const EcViewPointOrientationSampler& orig
      );

   /// assignment operator
   EcViewPointOrientationSampler& operator=
      (
      const EcViewPointOrientationSampler& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcViewPointOrientationSampler& orig
      ) const;

   /// get the total count of all unique orientations.  This equals the number of
   /// samples per tetrahedron times the number of tetrahedrons.
   virtual EcU32 totalSampleCount
      (
      ) const;

   /*
   /// self test
   virtual EcBoolean selfTest
      (
      ) const;  */

   /// setup for sampling (samples per radian)
   /// the default just picks the center of each tetrahedron.  A value of
   /// 0 creates no samples.
   virtual EcBoolean setupForSampling
      (
      const EcU32& samplesPerRadian
      );

   /// get a sample
   virtual EcOrientation sample
      (
      const EcU32& sampleIndex
      );

   /// get ofsets to three linearly independent neighbors
   /// (0 is returned when a neighbor is not available)
   virtual void getNeighborOffsets
      (
      EcU32 sampleIndex,
      EcInt32& neighborOffset0,
      EcInt32& neighborOffset1,
      EcInt32& neighborOffset2
      ) const;

   /// get all the valid neighbors that are available, up to
   /// some maximum.  The maximum may not be available.
   virtual void getNeighborOffsets
      (
      EcU32 sampleIndex,
      EcU32 maximumNumber,
      EcXmlInt32Vector& neighborOffsets
      ) const;

   /// a random sample within ranges
   virtual EcOrientation randomSample
      (
      );

protected:

   /// for each sample, list the neighbors from closest
   EcXmlU32VectorVector     m_NeighborVectorVector;

   /// store all the angles used for generating the samples in the order of (az,el,roll)
   EcRealVectorVector          m_SampleAnglesVec;

   /// store index of (az,el,roll) for building neighbors
   EcU32VectorVector           m_IndexVecVec;

   /// the orientation samples
   EcXmlOrientationVector   m_OrientationSamples;

   /// the following is utility data
   mutable EcXmlInt32Vector m_UtilityNeighborVector;

};

#endif // ecViewPointOrientationSampler_H_
