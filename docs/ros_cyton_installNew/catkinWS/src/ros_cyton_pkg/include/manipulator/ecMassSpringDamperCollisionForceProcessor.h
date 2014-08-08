#ifndef ecMassSpringDamperCollisionForceProcessor_H_
#define ecMassSpringDamperCollisionForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecMassSpringDamperCollisionForceProcessor.h
/// @class EcMassSpringDamperCollisionForceProcessor
/// @brief Defines a class for computing collision force
///        using a mass-spring model
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecMassSpringCollisionForceProcessor.h"
#include "ecDissipativeForceProcessorContainer.h"
#include <geometry/ecShapeProximityData.h>

#undef  DEBUG_FORCE_PROC
#if defined(DEBUG_FORCE_PROC)
#include <iostream>
#include <fstream>
#endif

// forward declarations
class EcManipulatorLink;
class EcSystemActiveCollisionState;
class EcShapeCollisionEvent;
class EcShapeStateCacheKey;
class EcShapeProximityData;
class EcContactRegion;

/**
The class that processes collision forces using a nonlinear mass-spring-damper model. The only difference between this and EcMassSpringCollisionForceProcessor is in the way the repulsion force between two objects in contact is computed. In this class, the repulsion force is computed using the nonlinear spring-damper model found in the paper 'Stable Penalty-Based Model of Frictional Contacts' by K. Yamane and Y. Nakamura.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcMassSpringDamperCollisionForceProcessor : public EcMassSpringCollisionForceProcessor
{
public:
   /// default constructor
   EcMassSpringDamperCollisionForceProcessor
      (
      );


   /// destructor
   virtual ~EcMassSpringDamperCollisionForceProcessor
      (
      );

   /// copy constructor
   EcMassSpringDamperCollisionForceProcessor
      (
      const EcMassSpringDamperCollisionForceProcessor& orig
      );

   /// assignment operator
   EcMassSpringDamperCollisionForceProcessor& operator=
      (
      const EcMassSpringDamperCollisionForceProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMassSpringDamperCollisionForceProcessor& orig
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

   /// get an empty object
   static EcMassSpringDamperCollisionForceProcessor nullObject
      (
      );

    /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// @copydoc EcBaseCollisionForceProcessor::process()
   virtual EcBoolean process
      (
      EcShapeCollisionData& collision,
      EcSystemActiveState& actState,
      const EcManipulatorTorqueVector&  torqueVec,
      EcManipulatorExternalForceVector& externalForceVec,
      const EcReal& time
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:

   using EcMassSpringCollisionForceProcessor::computeRepulsionForce;
   /// compute the repulsion force due to linear and torsional spring/damper
   virtual EcBoolean computeRepulsionForce
      (
      // INPUT
      const EcShapeCollisionData& collision,
      // INPUT/OUTPUT
      EcSystemActiveState& actState,
      // OUTPUT
      EcVector& springDamperForceInSystem,
      EcGeneralForce& repulsionForce1Primary,
      EcGeneralForce& repulsionForce2Primary
      ) const;

   /// update the collision and force data in the system active state
   virtual void updateCollisionAndForceData
      (
      const EcShapeCollisionData& collision,
      const EcManipulatorLink* link1,
      const EcManipulatorLink* link2,
      EcU32 link1ManipulatorID,
      EcU32 link2ManipulatorID,
      const EcGeneralForce& collisionForceLink1Dh,
      const EcGeneralForce& collisionForceLink2Dh,
      EcSystemActiveState& actState
      ) const;

   /// constants
   static const EcReal   m_theDefaultDistanceTolerance;

#if defined(DEBUG_FORCE_PROC)
   /// dump debug data
   virtual void dumpDebugData()const;
   /// this is for debug
   mutable ofstream m_fout ;
#endif

};

#endif // ecMassSpringDamperCollisionForceProcessor_H_
