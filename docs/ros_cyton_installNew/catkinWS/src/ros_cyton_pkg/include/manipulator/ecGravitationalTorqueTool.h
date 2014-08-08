#ifndef ecGravitationalTorqueTool_H_
#define ecGravitationalTorqueTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGravitationalTorqueTool.h
/// @class EcGravitationalTorqueTool
/// @brief Provides a tool for gravitational torque/force and gradients.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipActiveState.h"

// forward declarations
class EcIndividualManipulator;
class EcManipulatorLink;
class EcPositionState;
class EcStatedSystemStruct;

/** Provides a tool for gravitational torque/force and gradients for a manipulator.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcGravitationalTorqueTool
{
public:
   /// default constructor
   EcGravitationalTorqueTool
      (
      );

   /// destructor
   virtual ~EcGravitationalTorqueTool
      (
      );

   /// copy constructor
   EcGravitationalTorqueTool
      (
      const EcGravitationalTorqueTool& orig
      );

   /// assignment operator
   EcGravitationalTorqueTool& operator=
      (
      const EcGravitationalTorqueTool& orig
      );

   /// get manipulator
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// set manipulator
   virtual void setManipulator
      (
      const EcIndividualManipulator* manipulator
      );

   /// get gravity vector in system
   virtual const EcVector& gravityVector
      (
      ) const;

   /// set gravity vector in system
   virtual void setGravityVector
      (
      const EcVector& gravityVector
      );

   /// set the position state.  This is only used if no external active
   /// state is provided when calculating the torque quantities
   virtual void setPositionState
      (
      const EcPositionState& positionState
      );

   /// calculate gravitational torques/forces, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return
    */
   virtual const EcReArray& gravitationalTorques
      (
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate gravitationalTorques, using (and setting) the
   /// active position state that is provided.  The gravitational
   /// torques/forces are the values required to counter gravity
   /// in a stationary manipulator. Overloaded for convenience.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return
    */
   virtual const EcReArray& gravitationalTorques
      (
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate gravitational torques/force on a single joint, using (and setting)
   /// the active position state that is provided.  If the pointer is
   /// null, an internal active state is used.
   /**
    * @param joint The joint index
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return
    */
   virtual EcReal gravitationalTorque
      (
      EcU32 joint,
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate gravitational torques/force on a single joint, using (and setting)
   /// the active position state that is provided.  The gravitational
   /// torques/forces are the values required to counter gravity
   /// in a stationary manipulator. Overloaded for convenience.
   /**
    * @param joint The joint index
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return
    */
   virtual EcReal gravitationalTorque
      (
      EcU32 joint,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate gravitational torque/force gradient for a single joint,
   /// using (and setting) the active position state that is provided.
   /// If the pointer is null, an internal active state is used.
   /**
    * @param joint The joint index
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return
    */
   virtual const EcReArray& gravitationalTorqueGradient
      (
      EcU32 joint,
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate gravitational torque/force gradient for a single joint,
   /// using (and setting) the active position state that is provided.
   /// The gravitational torques/forces are the values required to counter
   /// gravity in a stationary manipulator. Overloaded for convenience.
   /**
    * @param joint The joint index
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return
    */
   virtual const EcReArray& gravitationalTorqueGradient
      (
      EcU32 joint,
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// get a null object
   static EcGravitationalTorqueTool nullObject
      (
      );

protected:

   /// resize member variables
   virtual void resize
      (
      );

   /// calculate the partial derivatives for all inboard links
   virtual void calculateInboardPartialDerivatives
      (
      const EcGeneralForce& unitForce,
      const EcManipulatorLink* link,
      EcManipulatorActiveState& actState,
      EcReArray& gradient
      );

   /// calculate the partial derivatives for all outboard links
   virtual void calculateOutboardPartialDerivatives
      (
      const EcGeneralMotion& unitAcc,
      const EcManipulatorLink* link,
      EcManipulatorActiveState& actState,
      EcReArray& gradient,
      const EcStatedSystemStruct* systemStruct=0
      );

protected:
   /// a pointer to the manipulator
   const EcIndividualManipulator*    m_pManipulator;

   /// an active state used when none is provided
   EcManipulatorActiveState          m_ActiveState;

   /// the gravitational torques
   EcReArray                         m_GravitationalTorques;

   /// the gradient of a gravitational torque
   EcReArray                         m_GravitationalTorqueGradient;

   /// the upward pointing gravity vector
   EcVector                          m_Gravity;
};

#endif // ecGravitationalTorqueTool_H_
