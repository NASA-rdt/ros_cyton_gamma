#ifndef ecRigidWheelSoilForceProcessor_H_
#define ecRigidWheelSoilForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecRigidWheelSoilForceProcessor.h
/// @class EcRigidWheelSoilForceProcessor
/// @brief Defines a class for computing interaction force between
///        rigid wheel and soil
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRigidWheelSoilInteractionContainer.h"

#include <manipulator/ecBaseCollisionForceProcessor.h>
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlVector.h>

// forward declarations
class EcManipulatorLink;
class EcVector;

/**
A class to compute interaction forces between a rigid wheel and soil. It assumes that a wheel is a manipulator link and soil is another manipulator link. Also assumed is that the manipulator link for wheel has the word "wheel" in its label. For example, it could be "wheel_0", "0_wheel". The soil manipulator link must NOT have the word "wheel" in its label.
*/
class EC_ACTIN_SOILMECHANICS_DECL EcRigidWheelSoilForceProcessor : public EcBaseCollisionForceProcessor
{
public:
   /// default constructor
   EcRigidWheelSoilForceProcessor
      (
      );

   /// destructor
   virtual ~EcRigidWheelSoilForceProcessor
      (
      );

   /// copy constructor
   EcRigidWheelSoilForceProcessor
      (
      const EcRigidWheelSoilForceProcessor& orig
      );

   /// assignment operator
   EcRigidWheelSoilForceProcessor& operator=
      (
      const EcRigidWheelSoilForceProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRigidWheelSoilForceProcessor& orig
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
   static EcRigidWheelSoilForceProcessor nullObject
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

   /// get the rigid wheel-soil interaction container
   virtual const EcRigidWheelSoilInteractionContainer& interactionContainer
      (
      ) const;

   /// set the rigid wheel-soil interaction container
   virtual void setInteractionContainer
      (
      const EcRigidWheelSoilInteractionContainer& interactionContainer
      );

   /// get the default wheel radius
   virtual EcReal defaultWheelRadius
      (
      ) const;

   /// set the default wheel radius
   virtual void setDefaultWheelRadius
      (
      EcReal value
      );

   /// get the wheel radius of the wheel identified by linkId
   virtual EcReal wheelRadius
      (
      const EcString& linkId
      ) const;

   /// set the wheel radius of the wheel identified by linkId
   virtual void setWheelRadius
      (
      const EcString& linkId,
      EcReal radius
      );

   /// get the default wheel width
   virtual EcReal defaultWheelWidth
      (
      ) const;

   /// set the default wheel width
   virtual void setDefaultWheelWidth
      (
      EcReal value
      );

   /// get the wheel width of the wheel identified by linkId
   virtual EcReal wheelWidth
      (
      const EcString& linkId
      ) const;

   /// set the wheel width of the wheel identified by linkId
   virtual void setWheelWidth
      (
      const EcString& linkId,
      EcReal width
      );

   /// get the default offset of the center of the wheel in DH frame
   virtual const EcVector& defaultWheelCenterOffsetInDh
      (
      ) const;

   /// set the default offset of the center of the wheel in DH frame
   virtual void setDefaultWheelCenterOffsetInDh
      (
      const EcVector& value
      );

   /// get the offset of the center of the wheel identified by linkId in DH frame
   virtual const EcVector& wheelCenterOffsetInDh
      (
      const EcString& linkId
      ) const;

   /// set the offset of the center of the wheel identified by linkId in DH frame
   virtual void setWheelCenterOffsetInDh
      (
      const EcString& linkId,
      const EcVector& offset
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

   /// return the computed sinkage. Must be called after process.
   virtual EcReal sinkage
      (
      ) const;

   /// return the computed slip ratio. Must be called after process.
   virtual EcReal slipRatio
      (
      ) const;

   /// return the computed slip angle. Must be called after process.
   virtual EcReal slipAngle
      (
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

   /// Compute the lateral friction force. Currently not implemented and simply return 0
   virtual EcReal computeLateralFrictionForce
      (
      const EcReal maxLateralForce,
      EcSystemActiveState& actState
      ) const;
protected:
   EcXmlReal         m_DefaultWheelRadius;      ///< the default wheel radius
   EcXmlReal         m_DefaultWheelWidth;       ///< the default wheel width
   EcXmlVector       m_DefaultWheelOffset;      ///< the default wheel offset

   EcXmlStringRealMap   m_WheelRadiusMap;       ///< the wheel radius map
   EcXmlStringRealMap   m_WheelWidthMap;        ///< the wheel width map
   EcXmlMapType<EcXmlString, EcXmlVector>  m_WheelOffsetMap;   ///< the wheel offset map

   /// the container of rigid-wheel soil interaction
   mutable EcRigidWheelSoilInteractionContainer    m_InteractionContainer;

   /// non-XML data
   mutable EcReal    m_Sinkage;                 ///< the sinkage
   mutable EcReal    m_SlipRatio;               ///< the slip ratio
   mutable EcReal    m_SlipAngle;               ///< the slip angle
};

#endif // ecRigidWheelSoilForceProcessor_H_
