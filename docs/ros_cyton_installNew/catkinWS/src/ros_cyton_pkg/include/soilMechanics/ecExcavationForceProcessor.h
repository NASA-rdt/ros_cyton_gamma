#ifndef ecExcavationForceProcessor_H_
#define ecExcavationForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecExcavationForceProcessor.h
/// @class EcExcavationForceProcessor
/// @brief Defines a class for computing excavation forces
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecExcavationInteractionContainer.h"

#include <manipulator/ecBaseCollisionForceProcessor.h>
#include <xml/ecXmlMapType.h>

// forward declarations
class EcManipulatorLink;

/**
A class to compute excavation forces between a bucket and soil. It assumes that a bucket is a manipulator link and soil is another manipulator link. Also assumed is that the manipulator link for bucket has the word "bucket" in its label. For example, it could be "bucket_0", "0_bucket". The soil manipulator link must NOT have the word "bucket" in its label.
*/
class EC_ACTIN_SOILMECHANICS_DECL EcExcavationForceProcessor : public EcBaseCollisionForceProcessor
{
public:
   /// default constructor
   EcExcavationForceProcessor
      (
      );

   /// destructor
   virtual ~EcExcavationForceProcessor
      (
      );

   /// copy constructor
   EcExcavationForceProcessor
      (
      const EcExcavationForceProcessor& orig
      );

   /// assignment operator
   EcExcavationForceProcessor& operator=
      (
      const EcExcavationForceProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExcavationForceProcessor& orig
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
   static EcExcavationForceProcessor nullObject
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

   /// get the bucket excavation interaction container
   virtual const EcExcavationInteractionContainer& interactionContainer
      (
      ) const;

   /// set the bucket excavation interaction container
   virtual void setInteractionContainer
      (
      const EcExcavationInteractionContainer& interactionContainer
      );

   /// compute the reactive force caused by a collision on the two input shapes. In this case, the two shapes represent a wheel and soil.
   virtual EcBoolean process
      (
      EcShapeCollisionData& collision,
      EcSystemActiveState& actState,
      const EcManipulatorTorqueVector& torqueVec,
      EcManipulatorExternalForceVector& externalForceVec,
      const EcReal& time
      ) const;

protected:
   /// switch the two links if necessary. Return true if the two links are switched or false otherwise.
   virtual EcBoolean switchLinks
      (
      const EcManipulatorLink*& wheel,
      const EcManipulatorLink*& soil
      ) const;

   /// look up the surface property for a specific matertial from a specific shape in a given link
   /**
    * @param[in] link The manipulator link from which to look up the surface property
    * @param[in] shapeID The index of the shape in the link from which to look up the surface property
    * @param[in] material The material from which to look up the surface property
    * @param[out] sp The returned surface property
    * @return True if successful or false otherwise
    */
   virtual EcBoolean lookupSurfaceProperty
      (
      // INPUT
      const EcManipulatorLink& link,
      const EcU32& shapeID,
      const EcString & material,
      // OUTPUT
      const EcDataMap*& sp
      ) const;
protected:
   /// the container for excavation interaction
   mutable EcExcavationInteractionContainer    m_InteractionContainer;
};

#endif // ecExcavationForceProcessor_H_
