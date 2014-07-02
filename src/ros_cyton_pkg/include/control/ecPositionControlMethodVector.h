#ifndef ecPositionControlMethodVector_H_
#define ecPositionControlMethodVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionControlMethodVector.h
/// @class EcPositionControlMethodVector
/// @brief Holds a description of a vector of general position control methods.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPositionControlMethod.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of XML variable vector of EcPositionControlMethod to be used as a base class
typedef EcXmlVariableVectorType<EcPositionControlMethod> EcBasePositionControlMethodVector;

/// Holds a description of a vector of general end effectors.
class EC_ACTIN_CONTROL_DECL EcPositionControlMethodVector : public EcBasePositionControlMethodVector
{
public:
   /// default constructor
   EcPositionControlMethodVector
      (
      );

   /// destructor
   virtual ~EcPositionControlMethodVector
      (
      );

   /// copy constructor
   EcPositionControlMethodVector
      (
      const EcPositionControlMethodVector& orig
      );

   /// assignment operator
   EcPositionControlMethodVector& operator=
      (
      const EcPositionControlMethodVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControlMethodVector& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );
};

#endif // ecPositionControlMethodVector_H_
