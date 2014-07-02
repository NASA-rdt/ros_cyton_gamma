#ifndef ecManipActVelState_H_
#define ecManipActVelState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipActVelState.h
/// @class EcManipulatorActiveVelocityState
/// @brief Holds the active velocity state of a manipulator.
///        This includes redundant parts of the state that are
///        stored only for efficiency.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkVelState.h"
#include "ecVelocityState.h"
#include <xml/ecXmlCompType.h>

/// Holds the active velocity state of a manipulator.
/** This includes redundant
 parts of the state that are stored only for efficiency.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorActiveVelocityState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorActiveVelocityState
      (
      );

   /// destructor
   virtual ~EcManipulatorActiveVelocityState
      (
      );

   /// copy constructor
   EcManipulatorActiveVelocityState
      (
      const EcManipulatorActiveVelocityState& orig
      );

   /// assignment operator
   EcManipulatorActiveVelocityState& operator=
      (
      const EcManipulatorActiveVelocityState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorActiveVelocityState& orig
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

   /// gets the nonredundant velocity state
   virtual const EcVelocityState& velocityState
      (
      ) const;

   /// sets the nonredundant state
   virtual void setVelocityState
      (
      const EcVelocityState& velocityState
      );

   /// gets the active (redundant) state
   virtual const EcLinkVelocityStateVector& linkVelocityStates
      (
      ) const;


   /// gets the active (redundant) state (non-const)
   virtual  EcLinkVelocityStateVector& linkVelocityStates
      (
      ) ;

   /// gets a single velocity state in local
   virtual const EcGeneralVelocity& linkDhVelocityInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets a single velocity state in local
   virtual void setLinkDhVelocityInLocal
      (
      EcU32 linkIndex,
      const EcGeneralVelocity& dhVelocityInLocal
      );

   /// gets a single velocity state in system
   virtual const EcGeneralVelocity& linkDhVelocityInSystem
      (
      EcU32 linkIndex
      ) const;

   /// sets a single velocity state in system
   virtual void setLinkDhVelocityInSystem
      (
      EcU32 linkIndex,
      const EcGeneralVelocity& dhVelocityInSystem
      );

   /// gets a single primary-frame velocity state in system
   virtual const EcGeneralVelocity& linkPrimaryVelocityInSystem
      (
      EcU32 linkIndex
      ) const;

   /// sets a single primary-frame velocity state in system
   virtual void setLinkPrimaryVelocityInSystem
      (
      EcU32 linkIndex,
      const EcGeneralVelocity& primaryVelocityInSystem
      );

   /// gets the velocity at center of mass of a single link in local
   virtual const EcGeneralVelocity& linkComVelocityInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets the velocity at center of mass of a single link in local
   virtual void setLinkComVelocityInLocal
      (
      EcU32 linkIndex,
      const EcGeneralVelocity& value
      );

   /// gets the momentum at center of mass of a link in local frame
   virtual const EcGeneralMotion& linkMomentumInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets the momentum at center of mass of a link in local frame
   virtual void setLinkMomentumInLocal
      (
      EcU32 linkIndex,
      const EcGeneralMotion& value
      );

   /// gets the composite momentum of a link and its outboard links in local frame
   virtual const EcGeneralMotion& linkCompositeMomentumInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets the composite momentum of a link and its outboard links in local frame
   virtual void setLinkCompositeMomentumInLocal
      (
      EcU32 linkIndex,
      const EcGeneralMotion& value
      );

   /// sets the entire active (redundant) state
   virtual void setLinkVelocityStates
      (
      const EcLinkVelocityStateVector& linkVelocityStates
      );

   /// gets the base velocity state
   virtual const EcLinkVelocityState& baseVelocityState
      (
      ) const;

   /// gets the base velocity state (non-const)
   virtual EcLinkVelocityState& baseVelocityState
      (
      );

   /// sets the base state
   virtual void setBaseVelocityState
      (
      const EcLinkVelocityState& baseState
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
   static EcManipulatorActiveVelocityState nullObject
      (
      );

protected:
   /// the fixed state
   EcVelocityState           m_VelocityState;

   /// the active (redundant) state
   EcLinkVelocityStateVector m_LinkVelocityStates;

   /// the base state
   EcLinkVelocityState       m_BaseVelocityState;
};

#endif // ecManipActVelState_H_
