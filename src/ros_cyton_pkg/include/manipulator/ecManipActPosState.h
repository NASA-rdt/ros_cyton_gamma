#ifndef ecManipActPosState_H_
#define ecManipActPosState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipActPosState.h
/// @class EcManipulatorActivePositionState
/// @brief Holds the active state of a manipulator.  This include
///        redundant parts of the state that are stored only for
///        efficiency.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkPosState.h"
#include "ecPositionState.h"
#include <xml/ecXmlCompType.h>

/// Holds the active position state of a manipulator.
/** This includes redundant
 parts of the state that are stored only for efficiency.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorActivePositionState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorActivePositionState
      (
      );

   /// destructor
   virtual ~EcManipulatorActivePositionState
      (
      );

   /// copy constructor
   EcManipulatorActivePositionState
      (
      const EcManipulatorActivePositionState& orig
      );

   /// assignment operator
   EcManipulatorActivePositionState& operator=
      (
      const EcManipulatorActivePositionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorActivePositionState& orig
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

   /// gets the nonredundant state
   virtual const EcPositionState& positionState
      (
      ) const;

   /// sets the nonredundant state
   virtual void setPositionState
      (
      const EcPositionState& positionState
      );

   /// gets the active (redundant) state
   virtual const EcLinkPositionStateVector& linkPositionStates
      (
      ) const;

   /// sets a single location-in-system state
   virtual void setLinkPositionState
      (
      EcU32 linkIndex,
      const EcCoordinateSystemTransformation& dh,
      const EcCoordinateSystemTransformation& primary
      );

   /// sets a single D-H transform
   virtual void setDhTransform
      (
      EcU32 linkIndex,
      const EcCoordinateSystemTransformation& dhTransform
      );

   /// sets the entire active (redundant) state
   virtual void setLinkPositionStates
      (
      const EcLinkPositionStateVector& linkPositionStates
      );

   /// gets the base state
   virtual const EcLinkPositionState& basePositionState
      (
      ) const;

   /// sets the base state using components
   virtual void setBaseLinkPositionState
      (
      const EcCoordinateSystemTransformation& dh,
      const EcCoordinateSystemTransformation& primary
      );

   /// sets the base state
   virtual void setBasePositionState
      (
      const EcLinkPositionState& baseState
      );

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
   static EcManipulatorActivePositionState nullObject
      (
      );

protected:

   /// the fixed state
   EcPositionState m_PositionState;

   /// the active (redundant) state
   EcLinkPositionStateVector m_LinkPositionStates;

   /// the base state
   EcLinkPositionState m_BasePositionState;

};

/// a vector of individual velocity control descriptions
typedef EcXmlVectorType<EcManipulatorActivePositionState>
   EcManipulatorActivePositionStateVector;

#endif // ecManipActPosState_H_
