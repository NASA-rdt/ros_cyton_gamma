#ifndef ecTrajGeneratorVector_H_
#define ecTrajGeneratorVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecTrajGeneratorVector.h
/// @brief Vector of trajectory generators
/// @details EcTrajectoryGeneratorVector
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>

#include "ecBaseTrajGenerator.h"

/// type definition of XML variable vector of EcBaseTrajectoryGenerator to be used as a base class
typedef EcXmlVariableVectorType<EcBaseTrajectoryGenerator> EcBaseTrajectoryGeneratorVector;

/// Vector of trajectory generators
class EC_ACTIN_WALKING_DECL EcTrajectoryGeneratorVector : public EcBaseTrajectoryGeneratorVector
{
public:
   /// default constructor
   EcTrajectoryGeneratorVector
      (
      );

   /// destructor
   virtual ~EcTrajectoryGeneratorVector
      (
      );

   /// copy constructor
   EcTrajectoryGeneratorVector
      (
      const EcTrajectoryGeneratorVector& orig
      );

   /// assignment operator
   EcTrajectoryGeneratorVector& operator=
      (
      const EcTrajectoryGeneratorVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTrajectoryGeneratorVector& orig
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
   static EcTrajectoryGeneratorVector nullObject
      (
      );
};

#endif // ecTrajGeneratorVector_H_
