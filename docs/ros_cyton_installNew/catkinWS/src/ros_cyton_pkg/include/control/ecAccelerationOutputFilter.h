#ifndef ecAccelerationOutputFilter_H_
#define ecAccelerationOutputFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecAccelerationOutputFilter.h
/// @class EcAccelerationOutputFilter
/// @brief Holds a description of a filter that limits joint acclerations
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBasePositionControlOutputFilter.h"
#include <manipulator/ecVelocityState.h>

/// forward declarations
class EcPositionState;

/// Holds a description of a filter that limits joint acclerations
class EC_ACTIN_CONTROL_DECL EcAccelerationOutputFilter : public EcBasePositionControlOutputFilter
{
public:
   /// default constructor
   EcAccelerationOutputFilter
      (
      );

   /// destructor
   virtual ~EcAccelerationOutputFilter
      (
      );

   /// copy constructor
   EcAccelerationOutputFilter
      (
      const EcAccelerationOutputFilter& orig
      );

   /// assignment operator
   EcAccelerationOutputFilter& operator=
      (
      const EcAccelerationOutputFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAccelerationOutputFilter& orig
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
   /// @param[in] other   (EcXmlObject*) pointer to EcXmlObject
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   /// @return   (EcXmlObject*) The new object
   virtual EcXmlObject* newObject
      (
      ) const;

   /// token
   /// @return   (EcToken&) The class token
   virtual const EcToken& token
      (
      ) const;

   /// gets the label of the manipulator to which this filter is applied
   /// @return   (EcString&) The manipulator label
   virtual const EcString& manipulatorLabel
      (
      ) const;

   /// sets the label of the manipulator to which this filter is applied
   /// param[in] value   (EcString&) parameter to set the manipulator label
   virtual void setManipulatorLabel
      (
      const EcString& value
      );

   ///  gets the joint acceleration thresholds
   ///  @return   (EcXmlRealVector&) The joint acceleration thresholds
   const EcXmlRealVector& jointAccelerationThresholds
      (
      ) const;

   /// sets the joint acceleration thresholds
   /// param[in] value    (EcXmlRealVector&) acceleration thresholds
   void setJointAccelerationThresholds
      (
      const EcXmlRealVector& value
      );

   /// gets the linear acceleration threshold of the base motion
   ///  @return   (EcReal) The linear acceleration threshold
   EcReal linearAccelerationThreshold
      (
      ) const;

   /// sets the linear acceleration threshold of the base motion
   /// @param[in] value   (EcReal) linear acceleration threshold value
   void setLinearAccelerationThreshold
      (
      EcReal value
      );

   /// gets the angular acceleration threshold of the base motion
   /// @return   (EcReal) The angular acceleration threshold value
   EcReal angularAccelerationThreshold
      (
      ) const;

   /// sets the angular acceleration threshold of the base motion
   /// @param[in] value   sets the angular acceleration threshold
   void setAngularAccelerationThreshold
      (
      EcReal value
      );

   /// @copydoc EcBasePositionControlOutputFilter::initialize()
   virtual EcBoolean initialize
      (
      const EcStatedSystem* statedSystem
      );

   /// @copydoc EcBasePositionControlOutputFilter::filter()
   virtual void filter
      (
      const EcSupplementalControlState& suppState,
      EcManipulatorSystemState& state
      ) const;

   /// this filter will update previousActualVelocityStates in the control state.
   /// param[in] suppState   (EcSupplementalControlState&) TODO
   virtual void updateControlState
      (
      EcSupplementalControlState& suppState
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
protected:
   /// filter a velocity state so it complies with the acceleration thresholds
   /// @param[in] timeStep      (EcReal) the amount of time that each iteration uses to look-ahead and calculate the state of the simulation
   /// @param[in] prevVelState  (EcVelocityState&) velocity state at the previous time point
   /// @param[in] velState      (EcVelocityState&) velState velocity state at the current time point
   EcBoolean filterVelocityState
      (
      EcReal timeStep,
      const EcVelocityState& prevVelState,
      EcVelocityState& velState
      ) const;

   /// filter a position state so it complies with the acceleration thresholds
   /// @param[in] timeStep         (EcReal) current timestep the amount of time that each iteration uses to look-ahead and calculate the state of the simulation
   /// @param[in] prevActVelState  (EcVelocityState&) velocity state at the previous time point
   /// @param[in] prevPosState     (EcPositionState&) position state at the previous time point
   /// @param[in] posState         (EcPositionState&) position at the current state
   EcBoolean filterPositionState
      (
      EcReal timeStep,
      const EcVelocityState& prevActVelState,
      const EcPositionState& prevPosState,
      EcPositionState& posState
      ) const;

   /// apply the scalar motion filter (experimental)
   /// @param[in] timeStep                (EcReal) current timestep
   /// @param[in] velocityThreshold       (EcReal) maximum velocity that can be reached at the current time step
   /// @param[in] accelerationThreshold   (EcReal) maximum acceleration that can be reached at the current time step
   /// @param[in] prevVelocity            (EcReal) velocity at the previous time step
   /// @param[in] prevPosition            (EcReal) position at the prevoius time step
   /// @param[out] position               (EcReal) current position
   void applyScalarFilter
      (
      EcReal timeStep,
      EcReal velocityThreshold,
      EcReal accelerationThreshold,
      EcReal prevVelocity,
      EcReal prevPosition,
      EcReal& position
      ) const;
protected:
   EcXmlString             m_ManipulatorLabel;               ///< the manipulator's label
   EcXmlRealVector         m_JointAccelerationThresholds;    ///< the joint acceleration thresholds
   EcXmlReal               m_LinearAccelerationThreshold;    ///< the linear acceleration threshold of the base
   EcXmlReal               m_AngularAccelerationThreshold;   ///< the angular acceleration threshold of the base

   // non-XML data
   EcU32                   m_ManipIndex;             ///< the manipulator index
   EcBoolean               m_IsFixedBase;            ///< flag inidicating whether the manipulator is fixed, or floating base
   const EcStatedSystem*   m_pStatedSystem;          ///< pointer to the stated system
   mutable EcVelocityState m_PrevActualVeloState;    ///< the previous actual velocity state
};

#endif // ecAccelerationOutputFilter_H_
