#ifndef ecGraspingDecisionTreeBranch_H_
#define ecGraspingDecisionTreeBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspingDecisionTreeBranch.h
/// @class EcGraspingDecisionTreeBranch
/// @brief Branch provider for grasping tree
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeContainer.h"
#include "ecGraspingDecisionTreeElement.h"
#include <xml/ecXmlBasicType.h>

/// Branch provider for grasping tree
/**
   Contains left and right pointer to EcGraspingDecisionTreeContainer
   which can be a leaf or branch
*/
class EC_ACTIN_GRASPING_DECL EcGraspingDecisionTreeBranch : public EcGraspingDecisionTreeElement
{
public:
   /// default constructor
   EcGraspingDecisionTreeBranch
      (
      );

   /// destructor
   virtual ~EcGraspingDecisionTreeBranch
      (
      );

   /// copy constructor
   EcGraspingDecisionTreeBranch
      (
      const EcGraspingDecisionTreeBranch& orig
      );

   /// assignment operator
   EcGraspingDecisionTreeBranch& operator=
      (
      const EcGraspingDecisionTreeBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspingDecisionTreeBranch& orig
      ) const;

   /// registers components for class
   virtual void registerComponents
      (
      );

   /// gets a pointer to the left expression
   virtual const EcGraspingDecisionTreeContainer& left
      (
      ) const;

   /// sets the left expression through a copy
   virtual void setLeft
      (
      const EcGraspingDecisionTreeContainer& left
      );

   /// sets the left expression through a copy
   virtual void setLeft
      (
      const EcGraspingDecisionTreeElement& leftElement
      );

   /// clears the left expression
   virtual void clearLeft
      (
      );

   /// gets a pointer to the right expression
   virtual const EcGraspingDecisionTreeContainer& right
      (
      ) const;

   /// sets the right expression through a copy
   virtual void setRight
      (
      const EcGraspingDecisionTreeContainer& right
      );

   /// sets the right expression through a copy
   virtual void setRight
      (
      const EcGraspingDecisionTreeElement& rightElement
      );

   /// clears the right expression
   virtual void clearRight
      (
      );

   /// gets the break point
   virtual const EcReal breakPoint
      (
      ) const;

   /// sets the break point
   virtual void setBreakPoint
      (
      EcReal breakPoint
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// read value from unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// perform an search through decision tree
   /**
       Get grasping model from tree
       \param params grasp initialization parameters
       \param objectGraspingModule return module for grasping object
       \retval status of search
   */
   virtual EcBoolean search
      (
      const EcGraspInitParams& params,
      EcObjectGraspingModule& objectGraspingModule
      ) const;

   /// test the object for traversing the decision tree
   virtual EcReal test
      (
      const EcGraspInitParams& params
      ) const = 0;

protected:
   /// left decision tree branch
   EcGraspingDecisionTreeContainer m_Left;

   /// right decision tree branch
   EcGraspingDecisionTreeContainer m_Right;

   /// break point for searching left (low) or right (high)
   EcXmlReal m_BreakPoint;
};

#endif // ecGraspingDecisionTreeBranch_H_
