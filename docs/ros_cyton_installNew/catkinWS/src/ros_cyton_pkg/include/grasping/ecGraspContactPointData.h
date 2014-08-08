#ifndef ecGraspContactPointData_H_
#define ecGraspContactPointData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspContactPointData.h
/// @class EcGraspContactPointData
/// @brief Data for a grasp contact point.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <foundCore/ecVector.h>

class EC_ACTIN_GRASPING_DECL EcGraspContactPointData
{
public:
   /// default constructor
   EcGraspContactPointData
      (
      );

   /// destructor
   ~EcGraspContactPointData
      (
      );

   /// copy constructor
   EcGraspContactPointData
      (
      const EcGraspContactPointData& orig
      );

   /// assignment operator
   EcGraspContactPointData& operator=
      (
      const EcGraspContactPointData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspContactPointData& orig
      ) const;

   /// get the friction coefficient
   const EcReal frictionCoefficient
      (
      ) const;

   /// set the friction coefficient
   void setFrictionCoefficient
      (
      const EcReal friction
      );

   /// get the contact point relative to the origin
   const EcVector& contactPoint
      (
      ) const;

   /// set the contact point relative to the origin
   void setContactPoint
      (
      const EcVector& contactPoint
      );

   /// get the normal force
   const EcVector& normalForce
      (
      ) const;

   /// set the normal force (pointing out of the object)
   void setNormalForce
      (
      const EcVector& normalForce
      );

   /// get the basis forces
   const EcVectorVector& basisForces
      (
      ) const;

   /// get the basis torques
   const EcVectorVector& basisTorques
      (
      ) const;

   /// compute the basis wrenches
   /**
   \param[in] numSides The number of sides of the pyramid used to approximate the friction cone. Must be greater than 2.
   \param[in] torqueMultiplier The torque multiplier
   */
   void computeBasisWrenches
      (
      const EcU8 numSides,
      const EcReal torqueMultiplier
      );

protected:
   /// the friction for the contact point
   EcReal         m_Friction;

   /// the location of the contact point
   EcVector       m_ContactPoint;

   /// the nomral force at the contact point
   EcVector       m_NormalForce;

   /// vector basis forces
   EcVectorVector m_BasisForces;

   /// vector basis moments
   EcVectorVector m_BasisTorques;
};

/// a standard-library vector of EcGraspContactPointData values
typedef std::vector<EcGraspContactPointData> EcGraspContactPointDataVector;

#endif // ecGraspContactPointData_H_
