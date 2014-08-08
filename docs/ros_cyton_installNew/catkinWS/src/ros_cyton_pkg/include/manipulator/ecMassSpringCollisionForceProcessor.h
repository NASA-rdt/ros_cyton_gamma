#ifndef ecMassSpringCollisionForceProcessor_H_
#define ecMassSpringCollisionForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecMassSpringCollisionForceProcessor.h
/// @class EcMassSpringCollisionForceProcessor
/// @brief Defines a class for computing collision force
///        using a mass-spring model
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseCollisionForceProcessor.h"
#include "ecDissipativeForceProcessorContainer.h"
#include "ecFrictionCoefficientLookupTool.h"
#include <geometry/ecShapeProximityData.h>

#undef  DEBUG_FORCE_PROC
#if defined(DEBUG_FORCE_PROC)
#include <iostream>
#include <fstream>
#endif

// forward declarations
class EcContactRegion;
class EcDataMap;
class EcManipulatorActivePositionState;
class EcManipulatorLink;
class EcSystemActiveCollisionState;
class EcShapeCollisionEvent;
class EcShapeStateCacheKey;

// XXX FIXME: selfTest requires access to protected methods.
namespace Ec { namespace test { class EcMassSpringCollisionForceProcessorTester; } }

/**
The class that processes collision forces using a mass-spring-damper model.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcMassSpringCollisionForceProcessor : public EcBaseCollisionForceProcessor
{
public:
   /// default constructor
   EcMassSpringCollisionForceProcessor
      (
      );


   /// destructor
   virtual ~EcMassSpringCollisionForceProcessor
      (
      );

   /// copy constructor
   EcMassSpringCollisionForceProcessor
      (
      const EcMassSpringCollisionForceProcessor& orig
      );

   /// assignment operator
   EcMassSpringCollisionForceProcessor& operator=
      (
      const EcMassSpringCollisionForceProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMassSpringCollisionForceProcessor& orig
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

   /// gets the top element in the dissipative force proc container
   virtual const EcBaseDissipativeForceProcessor* dissipativeForceProcessor
      (
      )const;

   /// sets the top element in the dissipative force proc container to proc
   virtual void setDissipativeForceProcessor
      (
      const EcBaseDissipativeForceProcessor& proc
      );

  /// get the dissipative force processor
  virtual const EcDissipativeForceProcessorContainer& dissipativeForceProcessorContainer
      (
      )const;

   /// set the dissipative force processor
  virtual void setDissipativeForceProcessorContainer
      (
      const EcDissipativeForceProcessorContainer& cont
      );

   /// gets the use-friction flag
   virtual EcBoolean useFriction
      (
      ) const;

   /// sets the use-friction flag
   virtual void setUseFriction
      (
      EcBoolean useFriction
      );

   /// gets the torsional contribution factor
   virtual EcReal torsionalRepulsionContributionFactor
      (
      ) const;

   /// sets the torsional contribution factor
   virtual void setTorsionalRepulsionContributionFactor
      (
      EcReal torsionalRepulsionContributionFactor
      );

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

   /// get an empty object
   static EcMassSpringCollisionForceProcessor nullObject
      (
      );

    /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// @copydoc EcBaseCollisionForceProcessor::process()
   virtual EcBoolean process
      (
      EcShapeCollisionData& collision,
      EcSystemActiveState& actState,
      const EcManipulatorTorqueVector&  torqueVec,
      EcManipulatorExternalForceVector& externalForceVec,
      const EcReal& time
      ) const;

   /// get the spring exponent
   EcReal getSpringExponent
      (
      const EcDataMap*& sp1,
      const EcDataMap*& sp2
      )const;

   /// return the default spring exponent
   virtual EcReal defaultSpringExponent
      (
      )const;

   /// set the default spring exponent
   virtual void setDefaultSpringExponent
      (
      const EcReal& value
      );

   /// return the default spring constant
   virtual EcReal defaultSpringConstant
      (
      )const;

   /// set the default spring constant
   virtual void setDefaultSpringConstant
      (
      const EcReal& value
      );

   /// return the default damper constant
   virtual EcReal defaultDamperConstant
      (
      )const;

   /// set the default damper constant
   virtual void setDefaultDamperConstant
      (
      const EcReal& value
      );

   /// get the action radius.
   virtual EcReal actionRadius
      (
      )const;

   /// set the action radius. This is used in dissipative force processor.
   virtual void setActionRadius
      (
      EcReal value
      );

   /// get the linear inertia.
   virtual EcReal linearInertia
      (
      )const;

   /// set the linear inertia. This is used in dissipative force processor.
   virtual void setLinearInertia
      (
      EcReal value
      );

   /// get the angular inertia.
   virtual EcReal angularInertia
      (
      )const;

   /// set the angular inertia. This is used in dissipative force processor.
   virtual void setAngularInertia
      (
      EcReal value
      );

   /// get the friction coefficient lookup tool
   virtual const EcFrictionCoefficientLookupTool& frictionCoeficientLookupTool
      (
      ) const;

   /// set the friction coefficient lookup tool
   virtual void setFrictionCoeficientLookupTool
      (
      const EcFrictionCoefficientLookupTool& frictionCoefficientLookupTool
      );

protected:

   // XXX FIXME: selfTest requires access to protected methods.
   friend class Ec::test::EcMassSpringCollisionForceProcessorTester;

   /// get the spring constant for a material type pair
   EcReal getSpringConstant
      (
      const EcDataMap*& sp1,
      const EcDataMap*& sp2
      )const;

   /// get the damper constant for a material pair
   EcReal getDamperConstant
      (
      const EcDataMap*& sp1,
      const EcDataMap*& sp2
      )const;

   /// lookup the surface property for a material type tag
   EcBoolean lookupSurfaceProperty
      (
      // INPUT
      const EcManipulatorLink& link,
      const EcU32& shapeID,
      const EcU32& collisionPointID,
      const EcString & material,
      // OUTPUT
      const EcDataMap*& sp
      )const;

   /// compute the force response using mass-spring system
   EcBoolean computeSpringForceResponse
      (
      const EcVector& normal1To2InSystem,
      const EcReal& penatrationDepth,
      const EcReal& springConstant,
      const EcReal& springExponent,
      // OUTPUT
      EcVector& forceVectorInSystem
      )const;

   /// compute the force response of the damper
   EcBoolean computeDamperForceResponse
      (
      const EcVector& normal1To2InSystem,
      const EcGeneralVelocity& vPrimarySystem1,
      const EcGeneralVelocity& vPrimarySystem2,
      const EcCoordinateSystemTransformation& xformPrimary1,
      const EcCoordinateSystemTransformation& xformPrimary2,
      const EcVector& collisionPointInPrimary2,
      const EcReal& damperConstant,
      // OUTPUT
      EcVector& forceVectorInSystem
      )const;

   /// apply a torsional force to the objects based on the
   /// twist of the two colliding planes
   EcBoolean computeTorsionalForceResponse
      (
      const EcVector& normal1To2InSystem,
      const EcContactRegion& contactRegionShape1Primary,
      const EcContactRegion& contactRegionShape2Primary,
      const EcReal &torsionalSpringConstant,
      const EcReal &torsionalDampingConstant,
      const EcGeneralVelocity &velocityShape1Primary,
      const EcGeneralVelocity &velocityShape2Primary,
      const EcCoordinateSystemTransformation& xformPrimary1,
      const EcCoordinateSystemTransformation& xformPrimary2,
      // OUTPUT
      EcGeneralForce& forceOutputShape1Primary,
      EcGeneralForce& forceOutputShape2Primary,
      EcReal& torsionalPresence
      )const;

   /// compute the force response using mass-spring system
   virtual EcBoolean applyForceToLink
      (
      const EcManipulatorLink& link,
      EcManipulatorActivePositionState& linkState,
      const EcVector& collisionPointLocalPrimary,
      const EcVector& forceVectorSystem,
      // OUTPUT
      EcGeneralForce& linkForce,
      EcShapeCollisionEvent& colEvent
      )const;

   /// estimate the contact surface
   virtual EcBoolean estimateContactSurface
      (
      // INPUT
      const EcVector& collisionNormal2To1InSystem,
      const EcCoordinateSystemTransformation& primary1InSystem,
      const EcCoordinateSystemTransformation& primary2InSystem,
      // INPUT/OUTPUT
      EcShapeCollisionData& collision,
      // OUTPUT
      EcContactRegion& contactRegionShape1Primary,
      EcContactRegion& contactRegionShape2Primary
      )const;

   /// compute the repulsion force due to linear and torsional spring/damper
   virtual EcBoolean computeRepulsionForce
      (
      // INPUT
      const EcShapeCollisionData& collision,
      const EcContactRegion& contactRegionShape1Primary,
      const EcContactRegion& contactRegionShape2Primary,
      // INPUT/OUTPUT
      EcSystemActiveState& actState,
      // OUTPUT
      EcVector& springDamperForceInSystem,
      EcGeneralForce& repulsionForce1Primary,
      EcGeneralForce& repulsionForce2Primary
      )const;

   /// compute the repulsion force due to linear and torsional spring/damper
   virtual EcBoolean computeFrictionForce
      (
      // INPUT
      const EcReal& time,
      const EcVector& repulsionCollisionForceSystem,
      // INPUT/OUTPUT
      EcSystemActiveState& actState,
      EcShapeCollisionData& collision,
      // OUTPUT
      EcGeneralForce& frictionForce1Primary,
      EcGeneralForce& frictionForce2Primary
      )const;

   /// given a 2D moment of inertia |xx xy|
   ///                              |xy yy|
   /// calculate its principal moments and the angle of
   // principal axis orientation
   virtual void calculatePrincipalMoments
      (
      const EcReal& xx,
      const EcReal& yy,
      const EcReal& xy,
      EcReal& cosTheta,
      EcReal& sinTheta,
      EcReal& principalMomentX,
      EcReal& principalMomentY
      ) const;

   /// XML data
   /// dissipative force processor container, for computing
   /// friction and other dissipative forces.
   EcDissipativeForceProcessorContainer m_DissipativeForceProc;

   /// flag indicating wether to use friction in the force response
   /// calculation or not
   EcXmlBoolean m_UseFriction;

   /// the torsional contribution factor (0 to 1)
   EcXmlReal m_TorsionalRepulsionContributionFactor;

   EcXmlReal m_DefaultSpringConstant;  ///< the default spring constant
   EcXmlReal m_DefaultDamperConstant;  ///< the default damper constant
   EcXmlReal m_DefaultSpringExponent;  ///< the default spring exponent
   EcXmlReal m_ActionRadius;           ///< the action radius as part of input to dissipative force processor
   EcXmlReal m_LinearInertia;          ///< the linear inertia as part of input to dissipative force processor
   EcXmlReal m_AngularInertia;         ///< the angular inertia as part of input to dissipative force processor

   /// non-XML data

   /// temp proximity data
   mutable EcShapeProximityData  m_LocalProximityData;

   /// constants
   static const EcReal   m_theDefaultDistanceTolerance;

#if defined(DEBUG_FORCE_PROC)
   /// dump debug data
   virtual void dumpDebugData()const;
   /// this is for debug
   mutable ofstream m_fout ;
#endif

};

#endif // ecMassSpringCollisionForceProcessor_H_
