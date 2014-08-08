#ifndef ecImageSensorVector_H_
#define ecImageSensorVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageSensorVector.h
/// @class EcImageSensorVector
/// @brief Holds a vector of instances of EcImageSensor and its derived
///        classes.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>
#include "ecImageSensor.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// a variable vector of EcImage Sensor
typedef EcXmlVariableVectorType<EcImageSensor> EcBaseImageSensorVector;

/**
\class EcImageSensorVector
\brief Holds a vector of instances of EcImageSensor and its derived classes.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcImageSensorVector : public EcBaseImageSensorVector
{
public:
   /// default constructor
   EcImageSensorVector
      (
      );

   /// destructor
   virtual ~EcImageSensorVector
      (
      );

   /// copy constructor
   EcImageSensorVector
      (
      const EcImageSensorVector& orig
      );

   /// assignment operator
   EcImageSensorVector& operator=
      (
      const EcImageSensorVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImageSensorVector& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// get a null object
   static EcImageSensorVector nullObject
      (
      );
};

#endif // ecImageSensorVector_H_
