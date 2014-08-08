#ifndef ecManipActMassState_H_
#define ecManipActMassState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipActMassState.h
/// @class EcManipulatorActiveMassState
/// @brief Holds the active mass-properties state of a manipulator.
///        This includes redundant parts of the state that are
///        stored only for efficiency.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkMassState.h"
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds the active mass-properties state of a manipulator.
/** This includes redundant
 parts of the state that are stored only for efficiency.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorActiveMassState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorActiveMassState
      (
      );

   /// destructor
   virtual ~EcManipulatorActiveMassState
      (
      );

   /// copy constructor
   EcManipulatorActiveMassState
      (
      const EcManipulatorActiveMassState& orig
      );

   /// assignment operator
   EcManipulatorActiveMassState& operator=
      (
      const EcManipulatorActiveMassState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorActiveMassState& orig
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

   /// gets the active state
   virtual const EcLinkMassStateVector& linkMassStates
      (
      ) const;

   /// sets the active state
   virtual void setLinkMassStates
      (
      const EcLinkMassStateVector& linkMassStates
      );

   /// gets the base active state
   virtual const EcLinkMassState& baseMassState
      (
      ) const;

   /// sets the base active state
   virtual void setBaseMassState
      (
      const EcLinkMassState& massState
      );

   /// gets a single composite rigid-body inertial
   virtual const EcRigidBodyMassProperties& crbi
      (
      EcU32 linkIndex
      ) const;

   /// sets a single composite rigid-body inertial
   virtual void setCrbi
      (
      EcU32 linkIndex,
      const EcRigidBodyMassProperties& crbi
      );

   /// invalidates all of the state
   virtual void invalidateAll
      (
      );

   /// resize the components
   virtual void resize
      (
      EcU32 size
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
   static EcManipulatorActiveMassState nullObject
      (
      );

protected:
   /// the active state
   EcLinkMassStateVector m_LinkMassStates;

   /// the base state
   EcLinkMassState       m_BaseMassState;
};

#endif // ecManipActMassState_H_
