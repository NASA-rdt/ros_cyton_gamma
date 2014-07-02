#ifndef ecLinkMassState_H_
#define ecLinkMassState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkMassState.h
/// @class EcLinkMassState
/// @brief Holds the mass-properties state of a single manipulator link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecRigidBodyMass.h"
#include <xml/ecXmlCompType.h>

/// Holds the mass-properties state of a single manipulator link.
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkMassState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkMassState
      (
      );

   /// destructor
   virtual ~EcLinkMassState
      (
      );

   /// copy constructor
   EcLinkMassState
      (
      const EcLinkMassState& orig
      );

   /// assignment operator
   EcLinkMassState& operator=
      (
      const EcLinkMassState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkMassState& orig
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

   /// gets the composite rigid-body inertia of this and all
   /// outboard links
   virtual const EcRigidBodyMassProperties& crbi
      (
      ) const;

   /// sets the composite rigid-body inertia of this and all
   /// outboard links
   virtual void setCrbi
      (
      const EcRigidBodyMassProperties& crbi
      );

   /// gets the local CRBI validity flag
   virtual EcBoolean crbiValid
      (
      ) const;

   /// sets the local CRBI validity flag
   virtual void setCrbiValid
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
   static EcLinkMassState nullObject
      (
      );

protected:
   /// the composite rigid-body mass properties
   EcRigidBodyMassProperties m_Crbi;

   /// validity flag for the composite rigid-body mass properties
   EcXmlBoolean              m_CrbiValid;
};

/// a vector of position states
typedef EcXmlVectorType<EcLinkMassState> EcLinkMassStateVector;

#endif // ecLinkMassState_H_
