#ifndef ecVelContSystem_H_
#define ecVelContSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecVelContSystem.h
/// @class EcVelocityControlSystem
/// @brief Holds a description of a velocity control system, which includes
///        a manipulator system, a description of end effectors, and a description
///        of control systems.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecIndVelContDesc.h"
#include <manipulator/ecSystemActiveState.h>
#include "ecManipEndEffectorVel.h"
#include <xml/ecXmlCompType.h>

/// Holds a description of a velocity control system. Includes a manipulator system,
/// a description of end effectors, and, for each manipulator, a set of selectable control descriptions.
/// Mostly deprecated.
/// @deprecated
class EC_ACTIN_CONTROL_DECL EcVelocityControlSystem : public EcXmlCompoundType
{
public:
   /// default constructor
   EcVelocityControlSystem
      (
      );

   /// destructor
   virtual ~EcVelocityControlSystem
      (
      );

   /// copy constructor
   EcVelocityControlSystem
      (
      const EcVelocityControlSystem& orig
      );

   /// assignment operator
   EcVelocityControlSystem& operator=
      (
      const EcVelocityControlSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVelocityControlSystem& orig
      ) const;

   /// merge control description vectors with another control system by adding the control description vectors of the other control system to the end of this one.
   /**
   \param[in] other The other velocity control system.
   */
   virtual EcBoolean mergeWith
      (
      const EcVelocityControlSystem& other
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

   /// sets the vector of control descriptions
   /**
   \deprecated Use setControlDescriptionVectors(const EcVelocityControlDescriptionVectorVector&) or setControlDescriptions(const EcVelocityControlDescriptionVector&, const EcU32&) instead.
   */
   virtual void setControlDescriptions
      (
      const EcVelocityControlDescriptionVector& controlDescriptions
      );

   /// pushes back a velocity control description
   /**
   \deprecated Use addControlDescriptions(const EcVelocityControlDescriptionVector&) or addControlDescription(const EcIndividualVelocityControlDescription&, const EcU32&) instead.
   */
   virtual void addControlDescription
      (
      const EcIndividualVelocityControlDescription& controlDescription
      );

   /// gets the end effector velocities
   virtual const EcManipulatorEndEffectorVelocityVector& endEffectorVelocities
      (
      ) const;

   /// sets the end effector velocities
   virtual void setEndEffectorVelocities
      (
      const EcManipulatorEndEffectorVelocityVector& endEffectorVelocities
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
      EcU32 manipulatorIndex
      ) const;

   /// sets the data-map pointer for a specified manipulator
   void setDataMapPointer
      (
      EcU32 manipulatorIndex,
      const EcDataMap* pDataMap
      );

   /// gets the system active state
   virtual EcSystemActiveState& systemActiveState
      (
      )const;

   /// sets the system active state
   virtual void setSystemActiveState
      (
      const EcSystemActiveState& sysActState
      );

   /// gets the active states
   virtual EcManipulatorActiveStateVector& activeStates
      (
      ) const;

   /// gets the calculated velocity states
   virtual const EcVelocityStateVector& calculatedVelocityStates
      (
      ) const;

   /// sets the calculated velocity states
   virtual void setCalculatedVelocityStates
      (
      const EcVelocityStateVector& calculatedVelocityStates
      );

   /// sets the time step for all the manipulators in the system
   virtual void setSystemTimeStep
      (
      EcReal timeStep
      );

   /// sets the primary determinants
   virtual void setPrimaryDeterminant
      (
      const EcXmlRealVector& vPrimaryDeterminant
      );


   /// gets the primary determinants
   virtual const EcXmlRealVector& primaryDeterminant
     (
     ) const;

   /// sets the relative link data
   virtual EcBoolean setEndEffectorRelativeLinkData
      (
      const EcU32 manipulatorIndex,
      const EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets the relative link data.  Returns identity if the indices
   /// are not valid.
   virtual const EcEndEffectorRelativeLinkData& endEffectorRelativeLinkData
      (
      const EcU32 manipulatorIndex,
      const EcU32 endEffectorIndex
      ) const;

   /// sets the vector of nullspace of the Jacobian
   virtual void setVNullSpace
      (
      const std::vector<EcReArray>& vNullSpace
      );

   /// gets the vNullSpace
   virtual const std::vector<EcReArray>& vNullSpace
      (
      ) const;

   /// gets an individual velocity control description
   /**
   \deprecated Replaced by activeControlDescription(const EcU32&) const.
   */
   virtual const EcIndividualVelocityControlDescription& individualVelocityControlDescription
      (
      const EcU32 manipulatorIndex
      ) const;

   /// Replace the active velocity control description of the specified manipulator with another.
   /**
   \param[in] individualVelocityControlDescription The control description to be set as the new active.
   \param[in] manipulatorIndex The index of the manipulator to which the control description will be added.
   */
   virtual void setIndividualVelocityControlDescription
      (
      const EcIndividualVelocityControlDescription& individualVelocityControlDescription,
      const EcU32 manipulatorIndex
      );

   /// gets control expression container
   virtual const EcControlExpressionContainer& controlExpressionContainer
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets control expression container
   virtual void setControlExpressionContainer
      (
      const EcControlExpressionContainer& controlExpressionContainer,
      const EcU32 manipulatorIndex
      );

   /// gets an end effector
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets an end effector
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet,
      const EcU32 manipulatorIndex
      );

   /// calculates the inverse velocity kinematics
   virtual EcBoolean calculate
      (
      );

   /// check to see if end-effector motion exactly matches that desired
   virtual EcBoolean exactHandMotion
      (
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

   /// get a null object
   static EcVelocityControlSystem nullObject
      (
      );

   /// initialize XML components for reading and writing the desired end-effector velocities to zero
   void initializeEndEffectorVelocities
      (
      );

   /// check for the dimensional integrity of components
   virtual EcBoolean integrityCheck
      (
      );

   /// invalidates the active states and sets new position and velocity values
   /// This should be called whenever the state changes.
   virtual void resetActiveStates
      (
      );

   /// gets the control description vectors
   virtual const EcVelocityControlDescriptionVectorVector& controlDescriptionVectors
      (
      ) const;

   /// sets the control description vectors
   virtual void setControlDescriptionVectors
      (
      const EcVelocityControlDescriptionVectorVector& controlDescriptionVectors
      );

   /// adds a control description to a manipulator
   /**
   \param[in] individualVelocityControlDescription The control description to be added.
   \param[in] manipulatorIndex The index of the manipulator to which the control description will be added.
   \return True if successful or false if manipulatorIndex is out of range.
   */
   virtual EcBoolean addControlDescription
      (
      const EcIndividualVelocityControlDescription& individualVelocityControlDescription,
      const EcU32& manipulatorIndex
      );

   /// adds a control system with default parameters
   /**
   \param[in] manipulator The manipulator for which the control description will be added.
   \param[in] manipulatorIndex The index of the manipulator to which the control description will be added.
   \return True if successful.
   */
   virtual EcBoolean addDefaultControlDescription
      (
      const EcIndividualManipulator& manipulator,
      const EcU32& manipulatorIndex
      );

   /// deletes a control description from a manipulator
   /**
   Deletes a control description from a manipulator. Note the after this operation, the indices of control descriptions for that manipulator may be shifted.
   \param[in] manipulatorIndex The index of the manipulator from which a control description will be deleted.
   \param[in] controlDescriptionIndex The index of the control description to be deleted. If this index is currently the active index, then the active index will be changed to 0.
   \return True if successful or false if manipulatorIndex or controlDescriptionIndex is out of range. Also, if there's only one control description for this manipulator, then it will not be deleted and false will be returned.
   */
   virtual EcBoolean deleteControlDescription
      (
      const EcU32& manipulatorIndex,
      const EcU32& controlDescriptionIndex
      );

   /// deletes the list of control descriptions of a manipulator
   /**
   Deletes the list of control descriptions of a manipulator. Since end-effector set and end-effector relative data are parts of control description, they will also be deleted.
   \param[in] manipulatorIndex The index of the manipulator from which the control descriptions will be deleted.
   \return True if successful or false if manipulatorIndex is out of range.
   */
   virtual EcBoolean deleteControlDescriptions
      (
      const EcU32& manipulatorIndex
      );

   /// gets the list of control descriptions for a manipulator
   /**
   \param[in] manipulatorIndex The index of the manipulator from which the control description is queried.
   \return The list of control descriptions for the specified manipulator or null object if manipulatorIndex is out of range.
   */
   virtual const EcVelocityControlDescriptionVector& controlDescriptions
      (
      const EcU32& manipulatorIndex
      ) const;

   /// sets the control descriptions of a manipulator
   /**
   \param[in] velocityControlDescriptions The control descriptions to be set.
   \param[in] manipulatorIndex The index of the manipulator to which the control descriptions will be set.
   \return True if successful or false if manipulatorIndex is out of range.
   */
   virtual EcBoolean setControlDescriptions
      (
      const EcVelocityControlDescriptionVector& velocityControlDescriptions,
      const EcU32& manipulatorIndex
      );

   /// adds a list of control descriptions for a new manipulator.
   /**
   Adds a list of control descriptions for a new manipulator (not yet in index). This will increment the index by one. The index of active control description for the new manipulator will be set to 0. Call setActiveControlDescription(const EcU32&, const EcU32&) to set the active control description as desired.
   \param[in] velocityControlDescriptions The vector of control descriptions to be added.
   \return The index of the newly added vector of control descriptions.
   */
   virtual EcU32 addControlDescriptions
      (
      const EcVelocityControlDescriptionVector& velocityControlDescriptions
      );

   /// gets the active control description for the specified manipulator index
   /**
   \param[in] manipulatorIndex The manipulator index in query.
   \return The active control description for manipulatorIndex.
   */
   virtual const EcIndividualVelocityControlDescription& activeControlDescription
      (
      const EcU32& manipulatorIndex
      ) const;

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

   /// sets the active control description of a manipulator by label
   /**
   \param[in] manipulatorIndex The index of the manipulator to which the control descriptions will be set.
   \param[in] activeControlDescriptionLabel The label of the active control description to be set.
   \return True if successful or false if either manipulatorIndex is out of range or activeControlDescriptionLabel doesn't exist.
   */
   virtual EcBoolean setActiveControlDescription
      (
      const EcU32& manipulatorIndex,
      const EcString& activeControlDescriptionLabel
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

   /// gets the number of manipulators that this control system supports
   virtual inline EcU32 getNumSupportedManipulators
      (
      ) const
   {
      return this->m_ControlDescriptionVectors.size();
   }

   /// gets the number of available control descriptions for the specified manipulator
   /**
   \param[in] manipulatorIndex The index of the manipulator in query.
   \return The number of available control descriptions for the specified manipulator or 0 if manipulatorIndex is out of range.
   */
   virtual EcU32 getNumControlDescriptions
      (
      const EcU32& manipulatorIndex
      ) const;

protected:

   /// sets all data and pointers needed by member variables
   virtual void connectComponents
      (
      );

   /// connects the stated system to other components
   virtual void connectStatedSystem
      (
      );

   /// copies the control descriptions to vectors of control descriptions
   virtual void copyControlDescriptions
      (
      );

protected:
   /// the control descriptions
   EcVelocityControlDescriptionVector           m_ControlDescriptions;

   /// vectors of control descriptions
   EcVelocityControlDescriptionVectorVector     m_ControlDescriptionVectors;

   /// the indices of active control descriptions
   EcXmlU32Vector                               m_ActiveControlDescriptionIndices;

   // nonXML data below

   /// the end effector velocities
   EcManipulatorEndEffectorVelocityVector       m_EndEffectorVelocities;

   /// the stated system
   const EcStatedSystem*                        m_pStatedSystem;

   /// the vector of manipulator calculated velocity states
   EcVelocityStateVector                        m_CalculatedVelocityStates;

   /// the system active state
   mutable EcSystemActiveState                  m_SystemActiveState;

   /// the vector of manipulator active states
   mutable EcManipulatorActiveStateVector       m_ManipulatorActiveStates;

   /// store the determinants for each manipluator
   EcXmlRealVector                              m_vPrimaryDeterminant;

   /// store the null space for two steps velocity control singularity detection
   std::vector<EcReArray>                       m_vNullSpace;

   /// the null control description for error recovery
   static const EcIndividualVelocityControlDescription   m_theNullControlDescription;

   /// the null end effector set for error recovery
   static const EcEndEffectorSet                m_theNullEndEffectorSet;

   /// the null control expression container for error recovery
   static const EcControlExpressionContainer    m_theNullControlExpressionContainer;

   /// the null control description vector for error recovery
   static const EcVelocityControlDescriptionVector    m_theNullControlDescriptions;
};

#endif // ecVelContSystem_H_
