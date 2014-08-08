#ifndef ecSensorNoiseVector_H_
#define ecSensorNoiseVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSensorNoiseVector.h
/// @class EcSensorNoiseVector
/// @brief Holds a vector of instances of EcSensorNoise and its
///        derived classes.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>
#include "ecSensorNoise.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// a vector of sensor noise
typedef EcXmlVariableVectorType<EcSensorNoise> EcBaseSensorNoiseVector;

/**
\class EcSensorNoiseVector
\brief Holds a vector of instances of EcSensorNoise and its derived classes.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcSensorNoiseVector : public EcBaseSensorNoiseVector
{
public:
   /// default constructor
   EcSensorNoiseVector
      (
      );

   /// destructor
   virtual ~EcSensorNoiseVector
      (
      );

   /// copy constructor
   EcSensorNoiseVector
      (
      const EcSensorNoiseVector& orig
      );

   /// assignment operator
   EcSensorNoiseVector& operator=
      (
      const EcSensorNoiseVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSensorNoiseVector& orig
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
   static EcSensorNoiseVector nullObject
      (
      );

   /// standard object
   static EcSensorNoiseVector defaultObject
      (
      );
};

#endif // ecSensorNoiseVector_H_
