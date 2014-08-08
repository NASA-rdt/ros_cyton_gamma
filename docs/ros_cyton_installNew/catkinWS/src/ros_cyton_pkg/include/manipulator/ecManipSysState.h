#ifndef ecManipSysState_H_
#define ecManipSysState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipSysState.h
/// @class EcManipulatorSystemState
/// @brief A state for holding the manipulator state.  Enough information
///        is held to calculate the joint accelerations for simulation.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPositionState.h"
#include "ecVelocityState.h"
#include <xml/ecXmlCompType.h>
#include <geometry/ecSystemShapeProximityState.h>

/// Holds a description of the state of an entire manipulator system.
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorSystemState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorSystemState
      (
      );

   /// destructor
   virtual ~EcManipulatorSystemState
      (
      );

   /// copy constructor
   EcManipulatorSystemState
      (
      const EcManipulatorSystemState& orig
      );

   /// assignment operator
   EcManipulatorSystemState& operator=
      (
      const EcManipulatorSystemState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorSystemState& orig
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcManipulatorSystemState& orig
      );

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

   /// gets position states - const version
   virtual const EcPositionStateVector& positionStates
      (
      ) const;

   /// gets position states - nonconst version
   virtual EcPositionStateVector& positionStates
      (
      );

   /// sets position states
   virtual void setPositionStates
      (
      const EcPositionStateVector& positionStates
      );

   /// gets velocity states - const version
   virtual const EcVelocityStateVector& velocityStates
      (
      ) const;

   /// gets velocity states - nonconst version
   virtual EcVelocityStateVector& velocityStates
      (
      );

   /// sets velocity states
   virtual void setVelocityStates
      (
      const EcVelocityStateVector& velocityStates
      );

   /// zeros the velocity states
   virtual void zeroVelocityStates
      (
      );

   /// gets the time
   virtual EcTime time
      (
      ) const;

   /// sets the time
   virtual void setTime
      (
      EcTime time
      );

   /// tests that each element is within a tolerance of another
   virtual EcBoolean approxEq
      (
      const EcManipulatorSystemState& state2,
      const EcReal tol,
      const EcBoolean includeTime = EcTrue
      ) const;

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

   /// read this object from a binary stream
   virtual EcBoolean readBin
      (
      std::istream& stream
      );

   /// write this object to a binary stream
   virtual EcBoolean writeBin
      (
      std::ostream& stream
      ) const;

   /// get a null link
   static const EcManipulatorSystemState& nullObject
      (
      );

   /// sets this to be a linear interpolation between two
   /// other state values.  Returns True for success, False
   /// if the two times are the same.
   virtual EcBoolean linearInterpolation
      (
      const EcManipulatorSystemState& state1,
      const EcManipulatorSystemState& state2,
      const EcReal& time
      );

   /// sets this to be a linear interpolation between two
   /// other state values.  Sets this equal to
   //  (1-factor)*state1 + factor*state2
   virtual EcBoolean linearFactorInterpolation
      (
      const EcManipulatorSystemState& state1,
      const EcManipulatorSystemState& state2,
      const EcReal& factor
      );

   /// check to see whether the other state is compatible with this state. i.e. it must have the same numbers of position and velocity states and each position and velocity state must have the same number of joints.
   virtual EcBoolean checkCompatibleState
      (
      const EcManipulatorSystemState& other
      ) const;

protected:

   /// validate the numbers of position states and velocity states
   virtual EcBoolean validateTopLevelDimensions
      (
      );

   /// validate the sizes of the position states and velocity states
   virtual EcBoolean validateLowLevelDimensions
      (
      );

   /// the vector of manipulator position states
   EcPositionStateVector       m_PositionStates;

   /// the vector of manipulator velocity states
   EcVelocityStateVector       m_VelocityStates;

   /// the time associated with the state
   EcXmlTime                   m_Time;
};

/// A vector of system states
typedef EcXmlVectorType<EcManipulatorSystemState>
   EcManipulatorSystemStateVector;

#endif // ecManipSysState_H_
