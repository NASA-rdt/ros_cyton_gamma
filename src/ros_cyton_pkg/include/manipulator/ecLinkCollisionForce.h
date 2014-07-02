#ifndef ecLinkCollisionForce_H_
#define ecLinkCollisionForce_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkCollisionForce.h
/// @class EcLinkCollisionForce
/// @brief Compute the collision force at the link level
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseLinkInteractions.h"
#include "ecCollisionForceContainer.h"
//#include "ecCollisionDescriptor.h"
#include "ecManipExternalForce.h"
#include "ecManipulatorCollisionTool.h"

#include <iostream>
#include <fstream>

/// Compute the collision force at the link level
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkCollisionForce : public EcBaseLinkInteractions
{
public:
   /// constructor
   EcLinkCollisionForce
      (
      );

   /// destructor
   virtual ~EcLinkCollisionForce
      (
      );

   /// copy constructor
   EcLinkCollisionForce
      (
      const EcLinkCollisionForce& orig
      );

   /// assignment operator
   EcLinkCollisionForce& operator=
      (
      const EcLinkCollisionForce& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkCollisionForce& orig
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

   /// XML-initializes the class by registering the components
   virtual EcBoolean xmlInit
      (
      );

   /// A virtual constructor that returns an EcXmlObject.
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers all the components for this class that are
   /// read and written to XML files.
   virtual void registerComponents
      (
      );


   /// get the bvh precision level used for collision detection
   virtual EcU32 precisionLevel
      (
      )const;

   /// set the bvh precision level used for collision detection
   virtual void setPrecisionLevel
      (
      EcU32 precLevel
      );

   /// set the collision force container
   virtual void setCollisionForceContainer
      (
      const EcCollisionForceContainer& cont
      );

   /// get the collision force container
   virtual const EcCollisionForceContainer& collisionForceContainer
      (
      )const;

   /// Reads class data from an XML stream.
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Writes class data to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcLinkCollisionForce nullObject
      (
      );


   /// calculate the general force caused by collisions
   /// between links.  The force is represented in the DH frame
   /// of the link, with point of application at the DH frame
   /// origin.
   /// @copydoc EcBaseLinkInteractions::forceBetweenLinks()
   virtual void forceBetweenLinks
      (
      // INPUT
      EcSystemActiveState&              actState,
      const EcManipulatorSystem&        manipSystem,
      const EcReal&                     time,
      const EcManipulatorTorqueVector&  torqueVec,
      // OUTPUT
      EcManipulatorExternalForceVector& manipExtForceVec
      ) const;

   /// a virtual function returning the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// a static function returning the token for this class
   static const EcToken& classToken
      (
      );

   /// a creator function for this class
   static EcXmlObject* creator
      (
      );

protected:
   /// The collision force processor container
   EcCollisionForceContainer  m_CollisionForceProcessorContainer;

   /// the level of the BVH to use for collision detection
   EcXmlU32 m_PrecisionLevel;

   /// tool for computing collision data
   EcManipulatorCollisionTool m_CollisionTool;

   /// a utility array for the collisions
   //mutable EcCollisionDescriptorVector m_Collisions;

   /// minimum distance value beyond which we don't care about
   /// investigating collisions
   static const EcReal m_theBoundaryTolerance;

#undef EC_LINK_COLLISION_FORCE_DEBUG
#if defined(EC_LINK_COLLISION_FORCE_DEBUG)
   mutable std::ofstream fout;
   mutable std::ofstream fout2;
#endif
};

/// describes a vector of link collision force processors
typedef EcXmlVectorType<EcLinkCollisionForce>
   EcLinkCollisionForceVector;

#endif // ecLinkCollisionForce_H_
