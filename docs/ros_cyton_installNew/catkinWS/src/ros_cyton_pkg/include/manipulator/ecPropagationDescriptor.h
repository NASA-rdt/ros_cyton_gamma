#ifndef ecPropagationDescriptor_H_
#define ecPropagationDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecPropagationDescriptor.h
/// @class EcPropagationDescriptor
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include "ecManipulatorLink.h"
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>


// forward declarations
class EcShape;

/** Holds a class to describe a shape query descriptor
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcPropagationDescriptor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPropagationDescriptor
      (
      );

   /// destructor
   virtual ~EcPropagationDescriptor
      (
      );

   /// copy constructor
   EcPropagationDescriptor
      (
      const EcPropagationDescriptor& orig
      );

   /// assignment operator
   EcPropagationDescriptor& operator=
      (
      const EcPropagationDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPropagationDescriptor& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// check for collisions during propagation
   virtual EcBoolean checkForCollisions
      (
      )const;

   /// set the check for collisions flag
   virtual void setCheckForCollisions
      (
         EcBoolean value
      );


   /// get the collision detection tolerance
   virtual EcReal collisionDetectionTolerance
      (
      )const;

   /// set the collision detection tolerance.
   virtual void setCollisionDetectionTolerance
      (
      EcReal value
      );

   /// returns the fidelity used for collision detection.  This is
   /// the level in the BVH used to determine if
   /// a collision occured
   virtual EcU32 collisionDetectionFidelity
      (
      ) const;

   /// returns the fidelity used for collision detection.  This is
   /// the level in the BVH used to determine if
   /// a collision occured
   virtual void setCollisionDetectionFidelity
      (
      EcU32 value
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone
   virtual EcXmlObject* clone
      (
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

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

protected:
   /// check for collisions when propagating forward
   EcXmlBoolean                     m_CheckForCollisions;

   /// the collision detection tolerance, this is the max distance where
   /// we declare a collision has occured
   EcXmlReal                        m_CollisionDetectionTolerance;

   /// the collision detection fidelity. this describes what level
   /// in the BVH to use when checking for collisions.
   EcXmlU32                         m_CollisionDetectionFidelity;
};

/// type definition of XML vector of EcPropagationDescriptor
typedef EcXmlVectorType<EcPropagationDescriptor> EcPropagationDescriptorVector;

#endif // ecPropagationDescriptor_H_
