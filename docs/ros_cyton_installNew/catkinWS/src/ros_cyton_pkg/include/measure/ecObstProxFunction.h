#ifndef ecObstProxFunction_H_
#define ecObstProxFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecObstProxFunction.h
/// @class EcObstacleProximityFunction
/// @brief Provides a measure of proximity to obstacles.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCore/ecConstants.h>
#include "ecScalarManipFunction.h"
#include <geometry/ecCapsule.h>

// forward declarations
class EcIndividualManipulator;

/** Provides a measure of proximity to obstacles.
*/
class EC_ACTIN_MEASURE_DECL EcObstacleProximityFunction : public EcScalarManipulatorFunction
{
public:
   /// default constructor
   EcObstacleProximityFunction
      (
      );

   /// destructor
   virtual ~EcObstacleProximityFunction
      (
      );

   /// copy constructor
   EcObstacleProximityFunction
      (
      const EcObstacleProximityFunction& orig
      );

   /// assignment operator
   EcObstacleProximityFunction& operator=
      (
      const EcObstacleProximityFunction& orig
      );

   /// gets a pointer to the manipulator
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// sets the manipulator pointer
   virtual void setManipulator
      (
      const EcIndividualManipulator* pManipulator
      );

   /// gets a pointer to the capsules
   virtual const EcCapsuleVector* capsules
      (
      ) const;

   /// sets the pointer to the capsules
   virtual void setCapsules
      (
      const EcCapsuleVector* capsules
      );

   /// gets the exponent
   virtual EcReal exponent
      (
      ) const;
   /// sets the exponent
   virtual void setExponent
      (
      EcReal exponent
      );

   /// gets the boundary value
   virtual EcReal boundaryValue
      (
      ) const;

   /// sets the boundary value
   virtual void setBoundaryValue
      (
      EcReal boundaryValue
      );

   /// gets the cutoff distance
   virtual EcReal avoidanceDistance
      (
      ) const;

   /// sets the cutoff distance
   virtual void setAvoidanceDistance
      (
      EcReal avoidanceDistance
      );

   /// evaluate the function using an active state
   virtual EcReal evaluate
      (
      EcManipulatorActiveState& actState,
      EcBoolean nominal = EcTrue
      ) const;

   /// get a null object
   static EcObstacleProximityFunction nullObject
      (
      );

protected:

   /// a pointer to the manipulator
   const EcIndividualManipulator* m_pManipulator;

   /// a pointer to a vector of capsules enclosing obstacles
   const EcCapsuleVector*         m_pCapsules;

   /// the exponent of a polynomial function
   EcXmlReal                       m_Exponent;

   /// the value at a bounding volume boundary
   EcReal m_BoundaryValue;

   /// the cutoff distance
   EcReal m_AvoidanceDistance;
};

#endif // ecObstProxFunction_H_
