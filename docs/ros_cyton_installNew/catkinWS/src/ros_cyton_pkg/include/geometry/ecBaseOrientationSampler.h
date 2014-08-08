#ifndef ecBaseOrientationSampler_H_
#define ecBaseOrientationSampler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseOrientationSampler.h
/// @class EcBaseOrientationSampler
/// @brief base class for sampling the orientation space.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCore/ecConstants.h>
#include <foundCore/ecOrientation.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlPairType.h>

/** Base class for sampling the orientation space.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcBaseOrientationSampler
{
public:

   /// a number specifying an invalid sample
   enum{INVALID=0xFFFFFFFF};

   /// various sampler
   enum
   {
      sixHundredCell,                   ///< use 600 cell sampling
      viewPoint                         /// view point based
   };


   /**
    * @brief Default constructor.
    */
   EcBaseOrientationSampler
      (
      );

   /**
    * @brief Destructor
    */
   virtual ~EcBaseOrientationSampler
      (
      );

   /**
    * @brief Copy constructor
    * @param[in] orig
    */
   EcBaseOrientationSampler
      (
      const EcBaseOrientationSampler& orig
      );

   /**
    * @brief Assignment operator.
    * @param[in] orig
    * @return EcBaseOrientationSampler&
    */
   EcBaseOrientationSampler& operator=
      (
      const EcBaseOrientationSampler& orig
      );

   /**
    * @brief Equality operator.
    * @param[in] orig
    * @return EcBoolean
    */
   EcBoolean operator==
      (
      const EcBaseOrientationSampler& orig
      ) const;

   /**
    * @brief Get the total count of all unique orientations.
    * @details This equals the number of samples per tetrahedron times the number of tetrahedrons.
    * @return EcU32
    */
   virtual EcU32 totalSampleCount
      (
      ) const=0;

   /**
    * @brief Setup for sampling (samples per radian).
    * @details The default just picks the center of each tetrahedron.
    *          A value of 0 creates no samples.
    * @param[in] samplesPerRadian
    * @return EcBoolean
    */
   virtual EcBoolean setupForSampling
      (
      const EcU32& samplesPerRadian
      )=0;

   /**
    * @brief Get a sample.
    * @param[in] sampleIndex
    * @return EcOrientation
    */
   virtual EcOrientation sample
      (
      const EcU32& sampleIndex
      )=0;

   /**
    * @brief Get ofsets to three linearly independent neighbors.
    * @details 0 is returned when a neighbor is not available.
    * @param[in] sampleIndex
    * @param[in] neighborOffset0
    * @param[in] neighborOffset1
    * @param[in] neighborOffset2
    * @return void
    */
   virtual void getNeighborOffsets
      (
      EcU32 sampleIndex,
      EcInt32& neighborOffset0,
      EcInt32& neighborOffset1,
      EcInt32& neighborOffset2
      ) const=0;

   /**
    * @brief Get all the valid neighbors that are available, up to some maximum.
    * @details The maximum may not be available.
    * @param[in] sampleIndex
    * @param[in] maximumNumber
    * @param[in] neighborOffsets
    * @return void
    */
   virtual void getNeighborOffsets
      (
      EcU32 sampleIndex,
      EcU32 maximumNumber,
      EcXmlInt32Vector& neighborOffsets
      ) const=0;

   /**
    * @brief Get range vector.
    * @return const EcXmlRealRealPairVector&
    */
   virtual const EcXmlRealRealPairVector& rangeVector
      (
      ) const;

   /**
    * @brief Set range vector.
    * @param[in] rangeVector
    * @return void
    */
   virtual void setRangeVector
      (
      const EcXmlRealRealPairVector& rangeVector
      );


protected:

   /// general purpose vector of ranges, used for view based sampler
   EcXmlRealRealPairVector    m_RangeVector;

};

#endif // ecBaseOrientationSampler_H_
