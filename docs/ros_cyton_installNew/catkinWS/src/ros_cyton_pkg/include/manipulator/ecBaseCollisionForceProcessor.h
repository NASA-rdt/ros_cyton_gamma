#ifndef ecBaseCollisionForceProcessor_H_
#define ecBaseCollisionForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseCollisionForceProcessor.h
/// @class EcBaseCollisionForceProcessor
/// @brief A class to process the forces due to collisions.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeElement.h>

// forward declarations
class EcManipulatorExternalForce;
class EcManipulatorTorque;
class EcShape;
class EcShapeCollisionData;
class EcSystemActiveCollisionState;
class EcSystemActiveState;
class EcVector;
/// type defition of XML vector of EcManipulatorTorque
typedef EcXmlVectorType<EcManipulatorTorque> EcManipulatorTorqueVector;
/// type defition of XML vector of EcManipulatorExternalForce
typedef EcXmlVectorType<EcManipulatorExternalForce> EcManipulatorExternalForceVector;

/// The abstract base class for processing collision force between two shapes
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseCollisionForceProcessor : public EcBaseExpressionTreeElement
{
public:
   /// constructor
	EcBaseCollisionForceProcessor
      (
      );

   /// destructor
	virtual ~EcBaseCollisionForceProcessor
      (
      );

   /// copy constructor
   EcBaseCollisionForceProcessor
      (
      const EcBaseCollisionForceProcessor& orig
      );

   /// assignment operator
   EcBaseCollisionForceProcessor& operator=
      (
      const EcBaseCollisionForceProcessor& orig
      );

   /// equal operator
   EcBoolean operator==
      (
      const EcBaseCollisionForceProcessor& orig
      ) const;

   /// register xml components
   virtual void registerComponents
      (
      );

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const =0;

   /// a virtual equality operator
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const=0;

   /// compute the reactive force caused by a collision on the two
   /// input shapes
   /**
    * @param[in,out] collision The collision data between two shapes. Mostly for input but the method could
    *                potentially set some values back to the collision data.
    * @param[in,out] actState The system active state.
    * @param[in] torqueVec The control torques.
    * @param[in, out] externalForceVec The external forces. This method will compute collision force and add it
    *                to the external forces as appropriate.
    * @param[in] time The simulation time.
    * @return
    */
   virtual EcBoolean process
      (
      EcShapeCollisionData& collision,
      EcSystemActiveState& actState,
      const EcManipulatorTorqueVector& torqueVec,
      EcManipulatorExternalForceVector& externalForceVec,
      const EcReal& time
      ) const=0;
protected:

   /// get the surface key identifier of the impacted surface
   virtual const EcString& impactedSurfaceKey
      (
      // INPUT
      const EcShape* shape,
      const EcU32& collisionPointIndex,
      const EcVector& collisionPoint
      ) const;

   /// get the material type of the impacted surface
   virtual EcString impactedSurfaceMaterial
      (
      // INPUT
      const EcShape* shape,
      const EcString& surfaceKeyIdentifier
      ) const;

   // constants
   static const EcString m_theDefualtSurfaceKey;      ///< The default surface key
   static const EcString m_theDefualtMaterialType;    ///< The default material type
};

#endif // ecBaseCollisionForceProcessor_H_
