#ifndef ecLinkArtState_H_
#define ecLinkArtState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkArtState.h
/// @class EcLinkArticulationState
/// @brief Holds the link-articulation-dynamics state of a single
///        manipulator link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecArticulatedBodyDynamics.h"
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>

/// Holds the link-articulation-dynamics state of a single manipulator link.
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkArticulationState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkArticulationState
      (
      );

   /// destructor
   virtual ~EcLinkArticulationState
      (
      );

   /// copy constructor
   EcLinkArticulationState
      (
      const EcLinkArticulationState& orig
      );

   /// assignment operator
   EcLinkArticulationState& operator=
      (
      const EcLinkArticulationState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkArticulationState& orig
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

   /// gets the articulated-body dynamics of this and all
   /// outboard links
   virtual const EcArticulatedBodyDynamics& arbd
      (
      ) const;

   /// sets the articulated-body dynamics of this and all
   /// outboard links
   virtual void setArbd
      (
      const EcArticulatedBodyDynamics& arbd
      );

   /// gets the local ARBD validity flag
   virtual EcBoolean arbdValid
      (
      ) const;

   /// sets the local ARBD validity flag
   virtual void setArbdValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the supplemental acceleration of this link expressed
   /// in the DH frame.
   virtual const EcGeneralMotion& supplementalDhAcceleration
      (
      ) const;

   /// sets the supplemental acceleration of this link expressed
   /// in the DH frame.
   virtual void setSupplementalDhAcceleration
      (
      const EcGeneralAcceleration& supplementalDhAcceleration
      );

   /// gets the supplemental link acceleration validity flag
   virtual EcBoolean supplementalDhAccelerationValid
      (
      ) const;

   /// sets the supplemental link acceleration validity flag
   virtual void setSupplementalDhAccelerationValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the supplemental joint acceleration of this link
   virtual EcReal supplementalJointAcceleration
      (
      ) const;

   /// sets the supplemental joint acceleration of this link
   virtual void setSupplementalJointAcceleration
      (
      EcReal supplementalJointAcceleration
      );

   /// gets the supplemental joint acceleration validity flag
   virtual EcBoolean supplementalJointAccelerationValid
      (
      ) const;

   /// sets the supplemental joint acceleration validity flag
   virtual void setSupplementalJointAccelerationValid
      (
      EcBoolean valid=EcTrue
      );

   /// invalidates all values
   virtual void invalidateAll
      (
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

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

   /// get a null object
   static EcLinkArticulationState nullObject
      (
      );

protected:

   /// the composite rigid-body mass properties for this and
   /// all child links
   EcArticulatedBodyDynamics m_Arbd;

   /// validity flag for the articulated body dynamics
   EcXmlBoolean              m_ArbdValid;

   /// the supplemental acceleration produced by the action of
   /// inboard joint and base supplemental accelerations.  The
   /// acceleration of the DH frame expressed in the DH frame.
   EcGeneralAcceleration     m_SupplementalDhAcceleration;

   /// validity flag for the general acceleration
   EcXmlBoolean              m_SupplementalDhAccelerationValid;

   /// the supplemental joint acceleration calculated through
   /// the arbi direct dynamics algorithm.
   EcXmlReal                 m_SupplementalJointAcceleration;

   /// validity flag for the joint acceleration
   EcXmlBoolean              m_SupplementalJointAccelerationValid;
};

/// a vector of position states
typedef EcXmlVectorType<EcLinkArticulationState> EcLinkArticulationStateVector;

#endif // ecLinkArtState_H_
