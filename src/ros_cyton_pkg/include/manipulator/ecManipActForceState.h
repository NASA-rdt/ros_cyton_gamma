#ifndef ecManipActForceState_H_
#define ecManipActForceState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipActForceState.h
/// @class EcManipulatorActiveForceState
/// @brief Holds the active force state of a manipulator.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkForceState.h"
#include <xml/ecXmlCompType.h>

/// Holds the active force state of a manipulator.
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorActiveForceState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorActiveForceState
      (
      );

   /// destructor
   virtual ~EcManipulatorActiveForceState
      (
      );

   /// copy constructor
   EcManipulatorActiveForceState
      (
      const EcManipulatorActiveForceState& orig
      );

   /// assignment operator
   EcManipulatorActiveForceState& operator=
      (
      const EcManipulatorActiveForceState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorActiveForceState& orig
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

   /// Resizes and reinitializes the link states
   virtual void resize
      (
      EcU32 size
      );

   /// return the size of the components
   virtual EcU32 size
      (
      );

   /// gets the active (redundant) state
   virtual const EcLinkForceStateVector& linkForceStates
      (
      ) const;

   /// gets a single force state in local
   virtual const EcGeneralForce& linkDhForceInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets a single force state in local
   virtual void setLinkDhForceInLocal
      (
      EcU32 linkIndex,
      const EcGeneralForce& dhForceInLocal
      );

   /// sets the entire active (redundant) state
   virtual void setLinkForceStates
      (
      const EcLinkForceStateVector& linkForceStates
      );

   /// gets the base force state
   virtual const EcLinkForceState& baseForceState
      (
      ) const;

   /// sets the base state
   virtual void setBaseForceState
      (
      const EcLinkForceState& baseState
      );

   /// gets a force description
   virtual const EcExternalForceDescription& externalForceDescription
      (
      const EcU32& linkIndex
      ) const;

   /// sets an external force description
   virtual void setExternalForceDescription
      (
      const EcU32& linkIndex,
      const EcExternalForceDescription& desc
      ) ;

   /// invalidates all of the state
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
   static EcManipulatorActiveForceState nullObject
      (
      );

protected:
   /// the active (redundant) state
   EcLinkForceStateVector                  m_LinkForceStates;

   /// the base state
   EcLinkForceState                        m_BaseForceState;

   /// a static state to return for error recovery
   static const EcExternalForceDescription m_theZeroForceDescription;
};

#endif // ecManipActForceState_H_
