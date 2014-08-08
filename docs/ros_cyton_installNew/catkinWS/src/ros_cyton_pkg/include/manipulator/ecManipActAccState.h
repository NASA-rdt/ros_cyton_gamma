#ifndef ecManipActAccState_H_
#define ecManipActAccState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipActAccState.h
/// @class EcManipulatorActiveAccelerationState
/// @brief Holds the active acceleration state of a manipulator.
///        This includes redundant parts of the state that are stored only
///        for efficiency.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecAccelerationState.h"
#include "ecLinkAccState.h"
#include <xml/ecXmlCompType.h>

/// Holds the active acceleration state of a manipulator.
/** This includes redundant parts of the state that are stored only for efficiency.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorActiveAccelerationState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorActiveAccelerationState
      (
      );

   /// destructor
   virtual ~EcManipulatorActiveAccelerationState
      (
      );

   /// copy constructor
   EcManipulatorActiveAccelerationState
      (
      const EcManipulatorActiveAccelerationState& orig
      );

   /// assignment operator
   EcManipulatorActiveAccelerationState& operator=
      (
      const EcManipulatorActiveAccelerationState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorActiveAccelerationState& orig
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

   /// gets the nonredundant acceleration state
   virtual const EcAccelerationState& accelerationState
      (
      ) const;

   /// sets the nonredundant state
   virtual void setAccelerationState
      (
      const EcAccelerationState& accelerationState
      );

   /// gets the active (redundant) state
   virtual const EcLinkAccelerationStateVector& linkAccelerationStates
      (
      ) const;

   /// gets a single acceleration state in local
   virtual const EcGeneralAcceleration& linkDhAccelerationInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets a single acceleration state in local
   virtual void setLinkDhAccelerationInLocal
      (
      EcU32 linkIndex,
      const EcGeneralAcceleration& dhAccelerationInLocal
      );

   /// gets a single acceleration state in system
   virtual const EcGeneralAcceleration& linkDhAccelerationInSystem
      (
      EcU32 linkIndex
      ) const;

   /// sets a single acceleration state in system
   virtual void setLinkDhAccelerationInSystem
      (
      EcU32 linkIndex,
      const EcGeneralAcceleration& dhAccelerationInSystem
      );

   /// gets a single primary-frame acceleration state in system
   virtual const EcGeneralAcceleration& linkPrimaryAccelerationInSystem
      (
      EcU32 linkIndex
      ) const;

   /// sets a single primary-frame acceleration state in system
   virtual void setLinkPrimaryAccelerationInSystem
      (
      EcU32 linkIndex,
      const EcGeneralAcceleration& primaryAccelerationInSystem
      );

   /// gets the acceleration at center of mass of a single link in local
   virtual const EcGeneralAcceleration& linkComAccelerationInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets the acceleration at center of mass of a single link in local
   virtual void setLinkComAccelerationInLocal
      (
      EcU32 linkIndex,
      const EcGeneralAcceleration& value
      );

   /// gets the momentum rate at center of mass of a link in local frame
   virtual const EcGeneralMotion& linkMomentumRateInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets the momentum rate at center of mass of a link in local frame
   virtual void setLinkMomentumRateInLocal
      (
      EcU32 linkIndex,
      const EcGeneralMotion& value
      );

   /// gets the composite momentum rate of a link and its outboard links in local frame
   virtual const EcGeneralMotion& linkCompositeMomentumRateInLocal
      (
      EcU32 linkIndex
      ) const;

   /// sets the composite momentum rate of a link and its outboard links in local frame
   virtual void setLinkCompositeMomentumRateInLocal
      (
      EcU32 linkIndex,
      const EcGeneralMotion& value
      );

   /// sets the entire active (redundant) state
   virtual void setLinkAccelerationStates
      (
      const EcLinkAccelerationStateVector& linkAccelerationStates
      );

   /// gets the base acceleration state
   virtual const EcLinkAccelerationState& baseAccelerationState
      (
      ) const;

   /// sets the base state
   virtual void setBaseAccelerationState
      (
      const EcLinkAccelerationState& baseState
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

   /// return the size of the components
   virtual EcU32 size
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
   static EcManipulatorActiveAccelerationState nullObject
      (
      );

protected:
   /// the fixed state
   EcAccelerationState           m_AccelerationState;

   /// the active (redundant) state
   EcLinkAccelerationStateVector m_LinkAccelerationStates;

   /// the base state
   EcLinkAccelerationState       m_BaseAccelerationState;
};

#endif // ecManipActAccState_H_
