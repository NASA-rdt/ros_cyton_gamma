#ifndef ecBisectionGraspContactLocator_H_
#define ecBisectionGraspContactLocator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBisectionGraspContactLocator.h
/// @class EcBisectionGraspContactLocator
/// @brief Compute contact points and normals using bisection method
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecGraspContactLocator.h"

/**
\class EcBisectionGraspContactLocator

This class compute the contact locations by varying the joint position of the last link of each finger
using bisection method, given the initial joint positions of all other joints. It will only search
within the joint limits to make sure that the returned contact points can physically be acheived.
*/
class EC_ACTIN_GRASPING_DECL EcBisectionGraspContactLocator : public EcGraspContactLocator
{
public:
   /// default constructor
   EcBisectionGraspContactLocator
      (
      );

   /// destructor
   virtual ~EcBisectionGraspContactLocator
      (
      );

   /// copy constructor
   EcBisectionGraspContactLocator
      (
      const EcBisectionGraspContactLocator& orig
      );

   /// assignment operator
   EcBisectionGraspContactLocator& operator=
      (
      const EcBisectionGraspContactLocator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBisectionGraspContactLocator& orig
      ) const;

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

   /// default XML token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// \copydoc EcGraspContactLocator::search();
   virtual EcBoolean search
      (
      EcReal lowerBound,
      EcReal upperBound,
      DistanceCalculation& distanceFunctor,
      EcBoolean forward,
      EcReal& solution
      );

};

#endif // ecBisectionGraspContactLocator_H_
