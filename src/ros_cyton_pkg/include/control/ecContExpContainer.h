#ifndef ecContExpContainer_H_
#define ecContExpContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpContainer.h
/// @class EcControlExpressionContainer
/// @brief Holds a control-system-based mathematical expression.  This class
///        inherits from EcExpressionContainer, and adds a pointer to an individual
///        manipulator, an end effector, a desired end-effector velocity, and
///        a time step.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecCoreResult.h"
#include "ecExpContainer.h"

// forward declarations
class EcEndEffectorSet;
class EcJacobianState;
class EcManipulatorEndEffectorVelocity;
class EcPropagationResultData;
class EcVelocityController;
class EcVelocityControlSystem;

/// Holds a control-system-based mathematical expression.
/// This class inherits from EcExpressionContainer, and adds a pointer to an individual manipulator, an end effector, a desired end-effector velocity, and a time step.
class EC_ACTIN_CONTROL_DECL EcControlExpressionContainer : public EcExpressionContainer
{
public:
   /// default constructor
   EcControlExpressionContainer
      (
      );

   /// destructor
   virtual ~EcControlExpressionContainer
      (
      );

   /// copy constructor
   /// @param[in] orig (EcControlExpressionContainer&) value to initialize
   EcControlExpressionContainer
      (
      const EcControlExpressionContainer& orig
      );

   /// assignment operator
   /// @param[in] orig (EcControlExpressionContainer&) value to initialize
   EcControlExpressionContainer& operator=
      (
      const EcControlExpressionContainer& orig
      );

   /// equality operator
   /// @param[in] orig (EcControlExpressionContainer&) value to compare
   /// @return The comparison flag
   EcBoolean operator==
      (
      const EcControlExpressionContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   /// @param[in] other (EcXmlObject*) pointer value to compare
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   /// @return (EcXmlObject*) The new xml object
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   /// @return The xml string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /// @return (EcXmlObject*) The cloned object
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// get a pointer to the individual manipulator
   /// @return The individual manipulator
   virtual const EcIndividualManipulator* individualManipulator
      (
      ) const;

   /// set a pointer to the individual manipulator
   /// @param[in] individualManipulator (EcIndividualManipulator*) value to set
   virtual void setIndividualManipulator
      (
      const EcIndividualManipulator* individualManipulator
      );

   /// get a pointer to the end-effector set
   /// @return The endeffector set pointer
   virtual const EcEndEffectorSet* endEffectorSet
      (
      ) const;

   /// set a pointer to the end-effector set
   /// @param[in] endEffectorSet (EcEndEffectorSet*) value to set
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet* endEffectorSet
      );

   /// get the floating-base flag
   /// @return The fixed or floating base flag
   virtual EcBoolean isFixedBase
      (
      ) const;

   /// set the floating-base flag
   /// @param[in] isFixedBase The fixed base flag, default=Fixed base
   virtual void setIsFixedBase
      (
      EcBoolean isFixedBase=EcTrue
      );

   /// get a pointer to the position state
   /// @return (EcPositionState*)The position state pointer
   virtual const EcPositionState* positionState
      (
      ) const;

   /// set a pointer to the position state
   /// @param[in] positionState (EcPositionState*)  value to set
   virtual void setPositionState
      (
      const EcPositionState* positionState
      );

   /// get a pointer to the desired end-effector velocity
   /// @return (EcManipulatorEndEffectorVelocity*) The desired end-effector velocity pointer
   virtual const EcManipulatorEndEffectorVelocity* desiredEndEffectorVelocity
      (
      ) const;

   /// set a pointer to the desired end-effector velocity
   /// @param[in] desiredEndEffectorVelocity (EcManipulatorEndEffectorVelocity*) expected velocity of the end-effector
   virtual void setDesiredEndEffectorVelocity
      (
      const EcManipulatorEndEffectorVelocity* desiredEndEffectorVelocity
      );

   /// get the time step
   /// @return The time step
   virtual EcReal timeStep
      (
      ) const;

   /// set the time step
   /// @param[in] timeStep (EcReal) set the current time step
   virtual void setTimeStep
      (
      EcReal timeStep
      );

   /// gets the velocity control system
   /// @return(EcVelocityControlSystem*) The velocity control system pointer
   virtual const EcVelocityControlSystem* velocityControlSystem
      (
      ) const;

   /// sets the velocity control system
   /// @param[in] value (EcVelocityControlSystem*) value to set
   virtual void setVelocityControlSystem
      (
      const EcVelocityControlSystem* value
      );

   /// gets the system active state
   /// @return (EcSystemActiveState*) The active state pointer
   virtual EcSystemActiveState* systemActiveState
      (
      ) const;

   /// sets the system active state
   /// @param[in] value (EcSystemActiveState*) value to set
   virtual void setSystemActiveState
      (
      EcSystemActiveState* value
      );

   /// gets the velocity controller
   /// @return (EcVelocityController*) The velocity state controller pointer
   virtual const EcVelocityController* velocityController
      (
      ) const;

   /// sets the velocity controller pointer
   /// @param[in] value (EcVelocityController*) value to set
   virtual void setVelocityController
      (
      const EcVelocityController* value
      );

   /// gets the data map pointer
   /// @return The data map pointer TODO(Description about data map?)
   virtual const EcDataMap* dataMap
      (
      ) const;

   /// sets the data map pointer
   /// @param[in] dataMap (EcDataMap*) value to set
   virtual void setDataMap
      (
      const EcDataMap* dataMap
      );

   /// gets the core results as a non-const reference
   /// @return (EcCoreResult&) TODO(core result?)
   virtual EcCoreResult& coreResult
      (
      ) const;

   /// get the index
   /// @return The index TODO
   virtual EcU32 index
      (
      ) const;

   /// set the index
   /// @param[in] index value to set the end-effecor index
   virtual void setIndex
      (
      EcU32 index
      );

   /// gets a pointer to the stated system
   /// @return (EcStatedSystem*) The stated system pointer
   virtual const EcStatedSystem* system
      (
      ) const;

   /// sets the stated system
   /// @param[in] system (EcStatedSystem*) Set the stated system
   virtual void setSystem
      (
      const EcStatedSystem* system
      );

   /// gets the Jacobian state
   /// @return The jacobian state
   virtual EcJacobianState* jacobianState
      (
      ) const;

   /// sets the Jacobian state
   /// @param[in] jacobian (EcJacobianState*) the jacobian state
   virtual void setJacobianState
      (
      EcJacobianState* jacobian
      );

   /// get the pointer to the propagation result data
   /// @return (EcPropagationResultData*) The propogation result data pointer
   virtual EcPropagationResultData* propagationResultData
      (
      ) const;

   /// set the pointer to the propagation result data
   /// @param[in] value (EcPropagationResultData*) value to set
   virtual void setPropagationResultData
      (
      EcPropagationResultData* value
      );

   /// get a null object
   /// @return (EcControlExpressionContainer) The null object
   static EcControlExpressionContainer nullObject
      (
      );

protected:
   /// a pointer to a stated system
   const EcStatedSystem*                      m_pSystem;

   /// a pointer to an individual manipulator
   const EcIndividualManipulator*             m_pIndividualManipulator;

   /// a pointer to an position state
   const EcPositionState*                     m_pPositionState;

   /// a pointer to an end-effector set
   const EcEndEffectorSet*                    m_pEndEffectorSet;

   /// a flag indicating that the base is floating
   EcBoolean                                  m_IsFixedBase;

   /// a pointer to a desired end-effector velocity
   const EcManipulatorEndEffectorVelocity *   m_pDesiredEndEffectorVelocity;

   /// a time step
   EcReal                                     m_TimeStep;

   /// a pointer to the parent control system
   const EcVelocityControlSystem*             m_pVelocityControlSystem;

   /// a pointer to a system active state
   EcSystemActiveState*                       m_pSystemActiveState;

   /// a pointer to the parent controller
   const EcVelocityController*                m_pVelocityController;

   /// a pointer to the data map used to support control configuration
   const EcDataMap*                           m_pDataMap;

   /// an index for use with the velocity control system
   EcU32                                      m_Index;

   /// a pointer to the Jacobian state
   EcJacobianState*                           m_pJacobianState;

   /// a pointer to the propagation result data
   EcPropagationResultData*                   m_pPropagationResultData;

   /// a mutable repository for the core results that can be shared by all
   mutable EcCoreResult                       m_CoreResult;
};

/// a vector of control expression containers
typedef EcXmlVectorType<EcControlExpressionContainer>
   EcControlExpressionContainerVector;

#endif // ecContExpContainer_H_
