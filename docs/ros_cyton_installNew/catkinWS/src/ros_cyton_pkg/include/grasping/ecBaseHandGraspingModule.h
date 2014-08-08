#ifndef ecBaseHandGraspingModule_H_
#define ecBaseHandGraspingModule_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseHandGraspingModule.h
/// @class EcBaseHandGraspingModule
/// @brief This class is a base class for hand grasping modules
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeElement.h>
#include "ecGraspingDecisionTreeContainer.h"
#include "ecObjectGraspingModule.h"
#include "ecGraspStatus.h"

// Forward declarations
class EcGraspInitParams;
class EcGraspUpdateParams;

/** This class is a base class for hand grasping modules
*/
class EC_ACTIN_GRASPING_DECL EcBaseHandGraspingModule : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseHandGraspingModule
      (
      );

   /// destructor
   virtual ~EcBaseHandGraspingModule
      (
      );

   /// copy constructor
   EcBaseHandGraspingModule
      (
      const EcBaseHandGraspingModule& orig
      );

   /// assignment operator
   EcBaseHandGraspingModule& operator=
      (
      const EcBaseHandGraspingModule& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseHandGraspingModule& orig
      ) const;

   /// register XML member variables
   void registerComponents
      (
      );

   /// Calculate the grasp and save it internally for access
   virtual EcBoolean calculateGrasp
      (
      const EcGraspInitParams& params
      ) = 0;

   /// Append control descriptions required for the calculated grasp to a vector
   virtual void appendControlDescriptions
      (
      EcVelocityControlDescriptionVector& controlDescriptions,
      const EcIndividualVelocityControlDescription& prototype = EcIndividualVelocityControlDescription()
      ) = 0;

   /// Append force control descriptions required for the calculated grasp to a vector
   virtual void appendForceControlDescriptions
      (
      EcForceControlDescriptionVector& controlDescriptions,
      const EcForceControlDescription& prototype = EcForceControlDescription()
      ) = 0;

   /// Return the ative control description index to be used for the grasp
   virtual EcU32 activeControlDescription
      (
      ) = 0;

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      ) = 0;

   /// Return the grasp status
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params
      ) = 0;

   /// Return the placements for the end effectors used in the grasp motion
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPositions
      (
      ) = 0;

   /// Return the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      ) = 0;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      ) const = 0;

   /// Return the hand descriptor
   virtual const EcString& handDescriptor
      (
      ) const;

   /// Set the hand descriptor
   virtual void setHandDescriptor
      (
      const EcString& handDescriptor
      );

   /// Get the link indentifiers
   virtual const EcXmlStringVector& linkIdentifiers
      (
      ) const;

   /// Set the link indentifiers
   virtual void setLinkIdentifiers
      (
      const EcXmlStringVector& linkIdentifiers
      );

   /// Get the decision tree
   virtual const EcGraspingDecisionTreeContainer& decisionTree
      (
      ) const;

   /// Set the decision tree
   virtual void setDecisionTree
      (
      const EcGraspingDecisionTreeContainer& decisionTree
      );

protected:
   /// Hand descriptor
   EcXmlString m_HandDescriptor;

   /// List of end effectors that make up the hand
   EcXmlStringVector m_LinkIdentifiers;

   /// Decision tree
   EcGraspingDecisionTreeContainer  m_DecisionTree;

   /// Grasping module that performs grasping stages I through III.
   /// This is initialized from the decision tree through the
   /// calculateGrasp call (not through XML).
   EcObjectGraspingModule m_ObjectGraspingModule;
};

#endif // ecBaseHandGraspingModule_H_
