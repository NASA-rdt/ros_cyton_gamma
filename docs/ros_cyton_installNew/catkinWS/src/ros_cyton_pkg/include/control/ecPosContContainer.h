#ifndef ecPosContContainer_H_
#define ecPosContContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPosContContainer.h
/// @class EcPositionControlContainer
/// @brief Holds a container for a position control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>
#include "ecManipEndEffectorPlace.h"
#include "ecManipEndEffectorVel.h"
#include "ecEndEffectorTool.h"

class EcControlExpressionDescription;
class EcDataMap;
class EcEndEffectorRelativeLinkData;
class EcIndividualVelocityControlDescription;
class EcManipulatorSystemState;
class EcPositionController;
class EcPositionControllerVector;
class EcPositionControlSystem;
class EcStatedSystem;
class EcVelocityControlSystem;

/// Holds a container for a position control system.
class EC_ACTIN_CONTROL_DECL EcPositionControlContainer : public EcXmlVariableElementType<EcPositionControlSystem>
{
public:
   /// default constructor
   EcPositionControlContainer
      (
      );

   /// destructor
   virtual ~EcPositionControlContainer
      (
      );

   /// copy constructor
   EcPositionControlContainer
      (
      const EcPositionControlContainer& orig
      );

   /// assignment operator
   EcPositionControlContainer& operator=
      (
      const EcPositionControlContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControlContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   /**
       \return string token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \return cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// adds control description of input container to
   /// current control description
   /**
       \param other container to merge with
       \return error flag
   */
   virtual EcBoolean mergeWith
      (
      const EcPositionControlContainer& other
      );

   /// gets the data-map pointer for a specified manipulator
   const EcDataMap* dataMapPointer
      (
      EcU32 manipulatorIndex
      ) const;

   /// sets the data-map pointer for a specified manipulator
   void setDataMapPointer
      (
      EcU32 manipulatorIndex,
      const EcDataMap* pDataMap
      );

   /// gets the desired end-effector placements
   /**
       \return commanded placement vector
   */
   virtual const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      (
      ) const;

   /// sets the desired end-effector placements
   /**
       \param desiredPlacementVector commanded placement vector
   */
   virtual void setDesiredPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      );

   /// sets an individual desired end-effector placement
   virtual void setDesiredPlacement
      (
      const EcManipulatorEndEffectorPlacement& desiredPlacement,
      const EcU32 manipulatorIndex
      );

   /// sets an individual desired end-effector placement (returns True for success)
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \param placement commanded placement for one end effector
       \return error flag
   */
   virtual EcBoolean setDesiredPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcEndEffectorPlacement& placement
      );

   /// add placement vector to the current disiredplacement vector
   void addDesiredPlacement
      (
      const EcU32& index,
      const EcManipulatorEndEffectorPlacement& desiredPlacemet
      );

   /// sets the relative link data
   /**
       \param manipulatorIndex index for selecting the manipulator
       \param endEffectorIndex index for selecting the end effector
       \param relData relative link data for end effector
       \return error flag
   */
   virtual EcBoolean setEndEffectorRelativeLinkData
      (
      const EcU32 manipulatorIndex,
      const EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets the desired end-effector velocities
   /**
       \return commanded velocity vector
   */
   virtual const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      (
      ) const;

   /// sets the desired end-effector velocities
   /**
       \param desiredVelocityVector commanded velocity vector
   */
   virtual void setDesiredVelocityVector
      (
      const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      );

   /// sets an individual desired end-effector velocity
   virtual void setDesiredVelocity
      (
      const EcManipulatorEndEffectorVelocity& desiredVelocity,
      const EcU32 manipulatorIndex
      );

   /// sets an individual desired end-effector velocity (returns True for success)
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \param velocity commanded velocity for one end effector
       \return error flag
   */
   virtual EcBoolean setDesiredVelocity
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcXmlRealVector& velocity
      );

   /// zeros the desired velocity vector
   virtual void zeroDesiredVelocityVector
      (
      );

   /// set the passed value to a zero desired velocity vector
   virtual void setToZeroDesiredVelocityVector
      (
      EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      ) const;

   /// gets an individual actual end-effector placement
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \return end effector placement
   */
   virtual const EcEndEffectorPlacement& actualPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex
      ) const;

   /// gets the actual end-effector placements
   /**
       \return current placement vector
   */
   virtual const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      (
      ) const;

   /// sets the actual end-effector placements
   /**
       \param actualPlacementVector current placement vector
   */
   virtual void setActualPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      );

   /// adds a control control description and an effector set with default parameters
   /**
   \param[in] manipulator The manipulator for which the control description and end effector will be added.
   \param[in] manipulatorIndex The index of the manipulator to which the control description and end effector will be added.
   \return True if successful.
   */
   virtual EcBoolean addDefaultControlDescriptionAndEndEffectorSet
      (
      const EcIndividualManipulator& manipulator,
      const EcU32& manipulatorIndex
      );

   /// sets the active control description of a manipulator by index
   /**
   \param[in] manipulatorIndex The index of the manipulator to which the control descriptions will be set.
   \param[in] activeControlDescriptionIndex The index of the active control description to be set.
   \return True if successful or false if either manipulatorIndex or activeControlDescriptionIndex is out of range.
   */
   virtual EcBoolean setActiveControlDescription
      (
      const EcU32& manipulatorIndex,
      const EcU32& activeControlDescriptionIndex
      );

   /// gets the index of the active control description of the specified manipulator
   /**
   \param[in] manipulatorIndex The index of the manipulator in query.
   \return The index of the active control description of the specified manipulator.
   */
   virtual EcU32 activeControlDescriptionIndex
      (
      const EcU32& manipulatorIndex
      ) const;

   /// gets the vector of position controllers
   virtual const EcPositionControllerVector& positionControllers
      (
      ) const;

   /// gets the vector of position controllers
   virtual void setPositionControllers
      (
      const EcPositionControllerVector& controllers
      );

   /// sets the velocity control system. Depracated.
   virtual void setVelocityControlSystem
      (
      const EcVelocityControlSystem& velocityControlSystem
      );

   /// gets the stated system
   /**
       \return current stated system
   */
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// sets the stated system
   /**
       \param statedSystem current stated system
   */
   virtual void setStatedSystem
      (
      const EcStatedSystem* statedSystem
      );

   /// set the current state
   /**
   \param[in] state The current state
   */
   virtual void setCurrentState
      (
      const EcManipulatorSystemState& state
      );

   /// gets control expression description
   virtual const EcControlExpressionDescription& controlExpressionDescription
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets control expression description
   virtual void setControlExpressionDescription
      (
      const EcControlExpressionDescription& controlExpressionDescription,
      const EcU32 manipulatorIndex
      );

   /// gets an end effector
   /**
       \param manipulatorIndex index for selecting manipulator
       \return end effector data for one manipulator
   */
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets an end effector
   /**
       \param endEffectorSet end effector data for one manipulator
       \param manipulatorIndex index for selecting manipulator
   */
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet,
      const EcU32 manipulatorIndex
      );

   /// calculate a new manipulator state
   /**
       \param time current time
       \param state current state
       \return error flag
   */
   virtual EcBoolean calculateState
      (
      EcReal time,
      EcManipulatorSystemState& state
      );

   /// Return the position control system.
   /// if the container is empty, a dummy value is returned.
   /**
       \return control system reference
   */
   virtual const EcPositionControlSystem& controlSystem
      (
      ) const;

   /// Return the non-const position control system that is the top element
   /// if no top element exists, one is created.
   /**
       \return control system reference (nonconstant)
   */
   virtual EcPositionControlSystem& controlSystem
      (
      );

   /// feed back the externally sensed state to the position controller
   virtual void setSensedState
      (
      const EcManipulatorSystemState& state,
      const EcReal& timeStep
      );

   /// calculate the placement of an end-effector in the manipulator specified by a given index
   /**
   \param[in] manipIndex The index of the manipulator.
   \param[in] endEffectorIndex The index of the end-effector whose placement is to be calculated.
   \param[in, out] activeState The active state of the manipulator. Some elements of the active state may be modified.
   \param[out] placement Upon return, the placement of the end-effector.
   \return False if the index is out of range or true otherwise.
   */
   virtual EcBoolean calcEndEffectorPlacement
      (
      EcU32 manipIndex,
      EcU32 endEffectorIndex,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// calculate the placements of all end-effectors in the manipulator specified by a given index
   /**
   \param[in] manipIndex The index of the manipulator.
   \param[in, out] activeState The active state of the manipulator. Some elements of the active state may be modified.
   \param[out] placements Upon return, the placements of all end-effectors in the manipulator.
   */
   virtual EcBoolean calcAllEndEffectorPlacements
      (
      EcU32 manipIndex,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacementVector& placements
      ) const;

   /// calculate the placements of all end-effectors in all manipulators
   /**
   \param[in, out] activeState The active state of the manipulator. Some elements of the active state may be modified.
   \param[out] placements Upon return, the placements of all end-effectors in the manipulator.
   */
   virtual void calcAllEndEffectorPlacements
      (
      EcManipulatorActiveStateVector&  activeState,
      EcEndEffectorPlacementVectorVector& placements
      ) const;

   /// self test
   /**
       \return self test result
   */

   /// sets the collision avoidance mode
   /**
   \param collisionAvoidanceMode collision avoidance mode
   */
   virtual void setCollisionAvoidanceMode
	   (
	   EcU32 collisionAvoidanceMode
	   );

   /// exchange the position controller at the index
   /**
   \param index index of the control description
   \param posController the controller to exchange
   */
   virtual EcBoolean exchangePositionController
      (
      EcU32 index,
      const EcPositionController& posController
      );

   /// add a position controller
   /**
   \param posController the controller to add
   */
   virtual void addPositionController
      (
      const EcPositionController& posController
      );

   /// delete position controller
   /**
   \param index index of the control description to delete
   */
   virtual EcBoolean deletePositionController
      (

      EcU32 index
      );

   /// get a null object
   /**
       \return uninitialized control system container
   */
   static EcPositionControlContainer nullObject
      (
      );

   /// get a test object
   /**
       \return control system container
   */

protected:

   /// a dummy value to return for error recovery
   /// only needed if container is empty
   static const EcPositionControlSystem m_theEmptyControlSystem;
};

#endif // ecPosContContainer_H_
