#ifndef ecIncrementalGraspContactLocator_H_
#define ecIncrementalGraspContactLocator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecIncrementalGraspContactLocator.h
/// @class EcIncrementalGraspContactLocator
/// @brief Compute contact points and normals using incremental search method
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecGraspContactLocator.h"

/**
\class EcIncrementalGraspContactLocator

This class compute the contact locations by varying the joint position of the last link of each finger
using incremental search method, given the initial joint positions of all other joints. It will only search
within the joint limits to make sure that the returned contact points can physically be acheived.
*/
class EC_ACTIN_GRASPING_DECL EcIncrementalGraspContactLocator : public EcGraspContactLocator
{
public:
   /// default constructor
   EcIncrementalGraspContactLocator
      (
      );

   /// destructor
   virtual ~EcIncrementalGraspContactLocator
      (
      );

   /// copy constructor
   EcIncrementalGraspContactLocator
      (
      const EcIncrementalGraspContactLocator& orig
      );

   /// assignment operator
   EcIncrementalGraspContactLocator& operator=
      (
      const EcIncrementalGraspContactLocator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIncrementalGraspContactLocator& orig
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

   /// get the step size used for incremental search
   virtual EcReal stepSize
      (
      ) const;

   /// set the step size used for incremental search
   virtual void setStepSize
      (
      EcReal value
      );
protected:

   /// the step size in joint-value units
   EcXmlReal   m_StepSize;

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

#endif // ecIncrementalGraspContactLocator_H_
