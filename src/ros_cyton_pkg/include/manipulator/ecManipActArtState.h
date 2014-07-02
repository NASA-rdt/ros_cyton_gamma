#ifndef ecManipActArtState_H_
#define ecManipActArtState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipActArtState.h
/// @class EcManipulatorActiveArticulationState
/// @brief Holds the active articulation-based state of a manipulator.
///        This includes redundant parts of the state that are stored only for
///        efficiency in calculation.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkArtState.h"
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds the active articulation-based state of a manipulator.
/** This includes redundant parts of the state that are stored only for efficiency in calculation.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorActiveArticulationState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorActiveArticulationState
      (
      );

   /// destructor
   virtual ~EcManipulatorActiveArticulationState
      (
      );

   /// copy constructor
   EcManipulatorActiveArticulationState
      (
      const EcManipulatorActiveArticulationState& orig
      );

   /// assignment operator
   EcManipulatorActiveArticulationState& operator=
      (
      const EcManipulatorActiveArticulationState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorActiveArticulationState& orig
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
   virtual const EcLinkArticulationStateVector& linkArticulationStates
      (
      ) const;

   /// sets the active state
   virtual void setLinkArticulationStates
      (
      const EcLinkArticulationStateVector& linkArticulationStates
      );

   /// gets the base active state
   virtual const EcLinkArticulationState& baseArticulationState
      (
      ) const;

   /// sets the base active state
   virtual void setBaseArticulationState
      (
      const EcLinkArticulationState& baseState
      );

   /// gets a single articulated-body dynamics object
   virtual const EcArticulatedBodyDynamics& arbd
      (
      EcU32 linkIndex
      ) const;

   /// sets a single composite rigid-body dynamics object
   virtual void setArbd
      (
      EcU32 linkIndex,
      const EcArticulatedBodyDynamics& arbd
      );

   /// sets the base composite rigid-body dynamics object
   virtual void setBaseArbd
      (
      const EcArticulatedBodyDynamics& arbd
      );

   /// gets a supplemental frame acceleleration
   virtual const EcGeneralAcceleration& supplementalDhAcceleration
      (
      EcU32 linkIndex
      ) const;

   /// sets a supplemental frame acceleration
   virtual void setSupplementalDhAcceleration
      (
      EcU32 linkIndex,
      const EcGeneralAcceleration& supplementalDhAcceleration
      );

   /// gets the base supplemental frame acceleleration
   virtual const EcGeneralAcceleration& baseSupplementalDhAcceleration
      (
      ) const;

   /// sets the base supplemental frame acceleration
   virtual void setBaseSupplementalDhAcceleration
      (
      const EcGeneralAcceleration& supplementalDhAcceleration
      );

   /// gets a supplemental joint acceleleration
   virtual EcReal supplementalJointAcceleration
      (
      EcU32 linkIndex
      ) const;

   /// sets a supplemental joint acceleration
   virtual void setSupplementalJointAcceleration
      (
      EcU32 linkIndex,
      EcReal supplementalJointAcceleration
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
   static EcManipulatorActiveArticulationState nullObject
      (
      );

protected:
   /// the link states
   EcLinkArticulationStateVector m_LinkArticulationStates;

   /// the base state
   EcLinkArticulationState       m_BaseArticulationState;
};

#endif // ecManipActArtState_H_
