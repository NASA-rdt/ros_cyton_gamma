#ifndef ecVelocityController_H_
#define ecVelocityController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecVelocityController.h
/// @class EcVelocityController
/// @brief Holds a description of a velocity controller for one manipulator
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <manipulator/ecJacobianState.h>
#include <xml/ecXmlCompType.h>

#include "ecControlExpressionDescription.h"
#include "ecEndEffectorSet.h"
#include "ecManipEndEffectorVel.h"

// forward declarations
class EcSystemActiveState;

/// Holds a description of a velocity controller for one manipulator
class EC_ACTIN_CONTROL_DECL EcVelocityController : public EcXmlCompoundType
{
public:

   enum
   {
      JOINT_CONTROL_INDEX = 0xFFFFFFFF   /// index of the joint control description
   };

   /// default constructor
   EcVelocityController
      (
      );

   /// destructor
   virtual ~EcVelocityController
      (
      );

   /// copy constructor
   EcVelocityController
      (
      const EcVelocityController& orig
      );

   /// assignment operator
   EcVelocityController& operator=
      (
      const EcVelocityController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVelocityController& orig
      ) const;

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

   /// gets the joint control end-effector set
   virtual const EcEndEffectorSet& jointControlEndEffectorSet
      (
      ) const;

   /// sets the joint control end-effector set
   virtual void setJointControlEndEffectorSet
      (
      const EcEndEffectorSet& value
      );

   /// gets the list of control descriptions
   virtual const EcControlExpressionDescriptionVector& controlDescriptions
      (
      ) const;

   /// sets the vector of control descriptions
   virtual EcBoolean setControlDescriptions
      (
      const EcControlExpressionDescriptionVector& controlDescriptions
      );

   /// gets the list of end-effector sets (excluding the joint-control set)
   virtual const EcEndEffectorSetVector& endEffectorSets
      (
      ) const;

   /// sets the list of end-effector sets (excluding the joint-control set)
   virtual EcBoolean setEndEffectorSets
      (
      const EcEndEffectorSetVector& eeSets
      );

   /// gets the manipulator index for this controller
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// sets the manipulator index for this controller
   virtual void setManipulatorIndex
      (
      EcU32 value
      );

   /// gets the end effector velocity
   virtual const EcManipulatorEndEffectorVelocity& endEffectorVelocity
      (
      ) const;

   /// sets the end effector velocity
   virtual void setEndEffectorVelocity
      (
      const EcManipulatorEndEffectorVelocity& endEffectorVelocity
      );

   /// gets the stated system
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// sets the stated system
   virtual void setStatedSystem
      (
      const EcStatedSystem* statedSystem
      );

   /// gets the data-map pointer for a specified manipulator
   const EcDataMap* dataMapPointer
      (
      ) const;

   /// sets the data-map pointer for a specified manipulator
   void setDataMapPointer
      (
      const EcDataMap* pDataMap
      );

   /// gets the system active state
   virtual EcSystemActiveState* systemActiveState
      (
      )const;

   /// sets the system active state
   virtual void setSystemActiveState
      (
      EcSystemActiveState* sysActState
      );

   /// gets the active state
   virtual EcManipulatorActiveState& activeState
      (
      ) const;

   /// gets the calculated velocity state
   virtual const EcVelocityState& calculatedVelocityState
      (
      ) const;

   /// sets the calculated velocity state
   virtual void setCalculatedVelocityState
      (
      const EcVelocityState& value
      );

   /// sets the time step
   virtual void setTimeStep
      (
      EcReal timeStep
      );

   /// sets the primary determinants
   virtual void setPrimaryDeterminant
      (
      EcReal value
      );

   /// gets the primary determinants
   virtual EcReal primaryDeterminant
     (
     ) const;

   /// sets the relative link data
   virtual EcBoolean setEndEffectorRelativeLinkData
      (
      const EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets the relative link data.  Returns identity if the indices
   /// are not valid.
   virtual const EcEndEffectorRelativeLinkData& endEffectorRelativeLinkData
      (
      const EcU32 endEffectorIndex
      ) const;

   /// sets the nullspace of the Jacobian
   virtual void setNullSpace
      (
      const EcReArray& value
      );

   /// gets the nullspace
   virtual const EcReArray& nullSpace
      (
      ) const;

   /// gets the active control expression description
   virtual const EcControlExpressionDescription& controlExpressionDescription
      (
      ) const;

   /// gets the active control expression description -- non-const version
   virtual EcControlExpressionDescription& controlExpressionDescription
      (
      );

   /// sets the active control expression description
   virtual void setControlExpressionDescription
      (
      const EcControlExpressionDescription& controlExpressionDescription
      );

   /// gets the tool offsets
   virtual const EcCoordinateSystemTransformationVector& toolOffsets
      (
      ) const;

   /// sets the tool offsets
   virtual void setToolOffsets
      (
      const EcCoordinateSystemTransformationVector& value
      );

   /// sets the tool offset at a given index
   /// Returns false if index is invalid or true otherwise.
   virtual EcBoolean setToolOffset
      (
      EcU32 index,
      const EcCoordinateSystemTransformation& value
      );

   /// calculates the inverse velocity kinematics
   virtual EcBoolean calculate
      (
      );

   /// check to see if end-effector motion exactly matches that desired
   virtual EcBoolean exactHandMotion
      (
      ) const;

   /// gets the token
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
   static EcVelocityController nullObject
      (
      );

   /// initialize XML components for reading and writing the desired end-effector velocity to zero
   void initializeEndEffectorVelocity
      (
      );

   /// invalidates the active states and sets new position and velocity values
   /// This should be called whenever the state changes.
   virtual void resetActiveState
      (
      );

   /// adds a control control description and an effector set with default parameters
   /**
   \param[in] manipulator The manipulator for which the control description will be added.
   \return True if successful.
   */
   virtual EcBoolean addDefaultControlDescriptionAndEndEffectorSet
      (
      const EcIndividualManipulator& manipulator
      );

   /// adds a control description
   virtual void addControlDescription
      (
      const EcControlExpressionDescription& value
      );

   /// deletes a control description from a manipulator
   /**
   Deletes a control description from a manipulator. Note the after this operation, the indices of control descriptions for that manipulator may be shifted.
   \param[in] controlDescriptionIndex The index of the control description to be deleted. If this index is currently the active index, then the active index will be changed to 0.
   \return True if successful or false if controlDescriptionIndex is out of range. Also, if there's only one control description for this manipulator, then it will not be deleted and false will be returned.
   */
   virtual EcBoolean deleteControlDescription
      (
      EcU32 controlDescriptionIndex
      );

   /// sets the active control description by index.
   /**
   \param[in] index The index of the active control description to be set.
   \return True if successful or false if value is out of range.
   */
   virtual EcBoolean setActiveControlDescription
      (
      EcU32 index
      );

   /// gets the index of the active control description
   /**
   \return The index of the active control description.
   */
   virtual EcU32 activeControlDescriptionIndex
      (
      ) const;

   /// adds an end-effector set
   virtual void addEndEffectorSet
      (
      const EcEndEffectorSet& value
      );

   /// deletes the end-effector set at a specified index
   virtual EcBoolean deleteEndEffectorSet
      (
      EcU32 index
      );

   /// sets the active end-effector set by index.
   /**
   \param[in] index The index of the active control description to be set. Use JOINT_CONTROL_INDEX to set the joint control end-effector set active.
   \return True if successful or false if value is out of range.
   */
   virtual EcBoolean setActiveEndEffectorSet
      (
      EcU32 index
      );

   /// gets the active end-effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      ) const;

   /// gets the active end-effector set -- non-const version
   EcEndEffectorSet& endEffectorSet
      (
      );

   /// sets the active end-effector set
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet
      );

   /// gets the index of the active end-effector set
   virtual EcU32 activeEndEffectorSetIndex
      (
      ) const;

   /// sets all data and pointers needed by member variables
   virtual void connectComponents
      (
      );

   /// connects the stated system to other components
   virtual void connectStatedSystem
      (
      );

   /// gets whether the joint control description is active
   virtual EcBoolean jointControlActive
      (
      ) const;

   /// get the active jacobian state
   virtual EcJacobianState& jacobianState
      (
      ) const;

   /// get the speed factor, allowing the robot to move slower or faster than limitations in the
   /// joint rate limits and end-effector speed limits
   virtual EcReal speedFactor
      (
      ) const;

   /// set the speed factor. This sets the speed factor for all end-effector sets as well as the underlying
   /// controller. Must be positive. Use this to speed up (value > 1) or slow down (value < 1) the whole robot.
   virtual void setSpeedFactor
      (
      EcReal value
      );

   /// set the speed factor of all end-effectors in the current end-effector set only.
   virtual void setEndEffectorSpeedFactor
      (
      EcReal value
      );

   /// set the speed factor for the end-effector specified by index in the current end-effector set only.
   virtual EcBoolean setEndEffectorSpeedFactor
      (
      EcU32 index,
      EcReal value
      );

   /// set whether filtering is active of all end-effectors in the current end-effector set only. If it's false, then
   /// the end-effectors will essentially have no limits.
   virtual void setEndEffectorFilteringActive
      (
      EcBoolean value
      );

   /// set whether filtering is active for the end-effector specified by index in the current end-effector set only. If it's false,
   /// then the end-effector will essentially have no limits. Returns false if index is invalid or true otherwise.
   virtual EcBoolean setEndEffectorFilteringActive
      (
      EcU32 index,
      EcBoolean value
      );

protected:
   /// gets the active control description -- non-const version
   virtual EcControlExpressionDescription& activeControlDescription
      (
      );

   /// the end effector set for joint control
   EcEndEffectorSet                             m_JointControlEndEffectorSet;

   /// the control descriptions
   EcControlExpressionDescriptionVector         m_vControlDescriptions;

   /// the end effector sets
   EcEndEffectorSetVector                       m_vEndEffectorSets;

   /// the index of active control description
   EcXmlU32                                     m_ActiveControlDescriptionIndex;

   /// the index of active end effector set
   EcXmlU32                                     m_ActiveEndEffectorSetIndex;

   /// the vector containing all tool offsets for the robot
   EcCoordinateSystemTransformationVector       m_vToolOffsets;

   // nonXML data below
   /// the manipulator index
   EcU32                                        m_ManipulatorIndex;

   /// the end effector velocity
   EcManipulatorEndEffectorVelocity             m_EndEffectorVelocity;

   /// the stated system
   const EcStatedSystem*                        m_pStatedSystem;

   /// the manipulator calculated velocity state
   EcVelocityState                              m_CalculatedVelocityState;

   /// the system active state
   EcSystemActiveState*                         m_pSystemActiveState;

   /// the manipulator active state
   mutable EcManipulatorActiveState             m_ManipulatorActiveState;

   /// store the determinant
   EcReal                                       m_PrimaryDeterminant;

   /// store the null space for two steps velocity control singularity detection
   EcReArray                                    m_NullSpace;

   /// the Jacobian state for the joint control end-effector set
   mutable EcJacobianState                      m_JointControlJacobianState;

   /// vector of Jacobian states
   mutable std::vector< EcJacobianState >       m_vJacobianStates;

   /// the speed factor, allowing the robot to move slower or faster than limitations in the
   /// joint rate limits and end-effector speed limits
   EcReal                                       m_SpeedFactor;

   /// the null end effector set for error recovery
   static const EcEndEffectorSet                m_theNullEndEffectorSet;

   /// the null control description for error recovery
   static const EcControlExpressionDescription  m_theControlDescription;
};

/// type definition of XML vector of EcVelocityController
typedef EcXmlVectorType< EcVelocityController >    EcVelocityControllerVector;

#endif // ecVelocityController_H_
