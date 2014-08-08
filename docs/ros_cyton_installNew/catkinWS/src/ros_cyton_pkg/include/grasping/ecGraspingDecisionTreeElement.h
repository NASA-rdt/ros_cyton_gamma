#ifndef ecGraspingDecisionTreeElement_H_
#define ecGraspingDecisionTreeElement_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspingDecisionTreeElement.h
/// @class EcGraspingDecisionTreeElement
/// @brief Base class for decision tree leaf nodes and branches
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeElement.h>
#include "ecObjectGraspingModule.h"

class EcGraspInitParams;

/// Decision Tree Base Class
/**
   Abstract base class for decision tree leaf node and branch.
*/
class EC_ACTIN_GRASPING_DECL EcGraspingDecisionTreeElement : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcGraspingDecisionTreeElement
      (
      );

   /// constructor given container pointer
   explicit EcGraspingDecisionTreeElement
      (
      const EcXmlBaseVariableCompoundType*  containerPointer
      );

   /// destructor
   virtual ~EcGraspingDecisionTreeElement
      (
      );

   /// copy constructor
   EcGraspingDecisionTreeElement
      (
      const EcGraspingDecisionTreeElement& orig
      );

   /// assignment operator
   EcGraspingDecisionTreeElement& operator=
      (
      const EcGraspingDecisionTreeElement& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspingDecisionTreeElement& orig
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// Perform an search through decision tree
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
      ) const = 0;

   /// Get object grasping module
   /**
       \retval object grasping module
   */
   virtual const EcObjectGraspingModule& objectGraspingModule
      (
      ) const;

   /// Set object grasping module
   /**
       \param objectGraspingModule object grasping module
   */
   virtual void setObjectGraspingModule
      (
      const EcObjectGraspingModule& objectGraspingModule
      );

   /// Get tag used for referencing this element
   virtual const EcXmlString& tag
      (
      ) const;

   /// Set tag used for referencing this element
   virtual void setTag
      (
      const EcXmlString& tag
      );

protected:
   /// object grasping module
   EcObjectGraspingModule m_ObjectGraspingModule;

   /// tag used for referencing this element
   EcXmlString m_Tag;
};

#endif // ecGraspingDecisionTreeElement_H_
