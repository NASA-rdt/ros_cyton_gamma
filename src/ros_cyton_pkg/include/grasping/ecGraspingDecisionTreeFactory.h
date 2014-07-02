#ifndef ecGraspingDecisionTreeFactory_H_
#define ecGraspingDecisionTreeFactory_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspingDecisionTreeFactory.h
/// @class EcGraspingDecisionTreeFactory
/// @brief Factory for creating grasping decision trees
/// @todo remove global one-of-a-kind nature of the tree
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>

class EcGraspingDecisionTreeContainer;

/// Factory for creating grasping decision trees
class EC_ACTIN_GRASPING_DECL EcGraspingDecisionTreeFactory
{
public:

   /// a static method to return a one-of tree
   static const EcGraspingDecisionTreeContainer& robonautHandGraspingTree
      (
      );
};

#endif // ecGraspingDecisionTreeFactory_H_
