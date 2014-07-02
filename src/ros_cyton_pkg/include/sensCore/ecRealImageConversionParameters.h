#ifndef ecRealImageConversionParameters_H_
#define ecRealImageConversionParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecRealImageConversionParameters.h
/// @class EcRealImageConversionParameters
/// @brief Holds a description of parameters for converting real data into
///        8-bit data for images.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/** Holds a description of parameters for converting real data into
 8-bit data for images.
*/
class EC_SENSOR_IMAGE_DECL EcRealImageConversionParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcRealImageConversionParameters
      (
      );

   /// destructor
   virtual ~EcRealImageConversionParameters
      (
      );

   /// copy constructor
   EcRealImageConversionParameters
      (
      const EcRealImageConversionParameters& orig
      );

   /// assignment operator
   EcRealImageConversionParameters& operator=
      (
      const EcRealImageConversionParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRealImageConversionParameters& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get lower bound
   virtual const EcXmlRealVector& lowerBounds
      (
      ) const;

   /// set lower bound
   virtual void setLowerBounds
      (
      const EcXmlRealVector& lowerBounds
      );

   /// get upper bound
   virtual const EcXmlRealVector& upperBounds
      (
      ) const;

   /// set upper bound
   virtual void setUpperBounds
      (
      const EcXmlRealVector& upperBounds
      );

   /// get logarithmic-mapping flag
   virtual EcBoolean logarithmicMapping
      (
      ) const;

   /// set logarithmic-mapping flag
   virtual void setLogarithmicMapping
      (
      EcBoolean logarithmicMapping
      );

   /// convert a single channel value
   virtual EcU8 convertChannelValue
      (
      EcReal realValue,
      EcU32 channel
      ) const;

   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcRealImageConversionParameters nullObject
      (
      );

protected:
   // the lower real value to map to 0
   EcXmlRealVector m_LowerBounds;

   // the upper real value to map to 255
   EcXmlRealVector m_UpperBounds;

   // a flag indicating whether or not to use logarithmic mapping
   EcXmlBoolean m_LogarithmicMapping;
};

/// A vector of image conversion parameters
typedef EcXmlVectorType<EcRealImageConversionParameters> EcRealImageConversionParametersVector;

#endif // ecRealImageConversionParameters_H_
