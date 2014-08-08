#ifndef ecGaussianBlur_H_
#define ecGaussianBlur_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecGaussianBlur.h
/// @class EcGaussianBlur
/// @brief A class representing Gaussian blur.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecSensorNoise.h"

#include <xml/ecXmlVectorType.h>

/**
\class EcGaussianBlur
\brief A class representing Gaussian blur in an image sensor.

It uses FIR transform together with linear separation of the kernel matrix into horizontal and vertical projections. This can significantly reduce the execution time, depending on the kernel size.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcGaussianBlur : public EcSensorNoise
{
public:
   /// default constructor
   EcGaussianBlur
      (
      );

   /// destructor
   virtual ~EcGaussianBlur
      (
      );

   /// copy constructor
   EcGaussianBlur
      (
      const EcGaussianBlur& orig
      );

   /// assignment operator
   EcGaussianBlur& operator=
      (
      const EcGaussianBlur& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGaussianBlur& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   // returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// initialize the noise's internal properties. Should be called after all parameters have been set.
   virtual void init
      (
      const EcImageSensor& imageSensor
      );

   /// get the sigma parameter of Gaussian distribution
   EcReal sigma
      (
      ) const;

   /// set the sigma parameter of Gaussian distribution and compute the kernel matrix. Sigma must be positive. If sigma is negative, this method will do nothing.
   virtual void setSigma
      (
      EcReal sigma
      );

   /// get the horizontal projection of the kernel (impulse response) for processing
   const EcXmlRealVectorVector& horizontalImpulseResponse
      (
      ) const;

   /// get the vertical projection of the kernel (impulse response) for processing
   const EcXmlRealVectorVector& verticalImpulseResponse
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// get a null object
   static EcGaussianBlur nullObject
      (
      );

   /// standard object
   static EcGaussianBlur defaultObject
      (
      );

   /// token for this class
   /**
   \return a unique string token.
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return a pointer to a new'ed object.
   */
   static EcXmlObject* creator
      (
      );

protected:
   /// compute the kernel matrix
   virtual void computeImpulseResponse
      (
      EcReal sigma
      );

protected:
   /// The sigma parameter of the Gaussian blur
   EcXmlReal      m_Sigma;

   /// non-XML data
   /// the horizontal projection of the kernel of the filter, computed from m_Sigma
   EcXmlRealVectorVector      m_HorizontalImpulseResponse;

   /// the vertical projection of the kernel of the filter, computed from m_Sigma
   EcXmlRealVectorVector      m_VerticalImpulseResponse;

   /// the factor used to multiply the sigma parameters to determine the size of the kernel matrix
   static const EcReal        m_theSigmaMultiplier;

   /// if the kernel matrix is bigger than this threshold, an warning will be issued
   static const EcU32         m_theKernelSizeThreshold;
};

#endif // ecGaussianBlur_H_
