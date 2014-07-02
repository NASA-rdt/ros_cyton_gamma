#ifndef ecParametricTranslationGraspOffsetState_H_
#define ecParametricTranslationGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecParametricTranslationGraspOffsetState.h
/// @class EcParametricTranslationGraspOffsetState
/// @brief This class provides a translation grasp offset that is parametrically defined.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffsetState.h"
#include "ecGraspOffsetStateContainer.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a translation grasp offset that is parametrically defined.
class EC_ACTIN_GRASPING_DECL EcParametricTranslationGraspOffsetState : public EcGraspOffsetState
{
public:
   /// default constructor
   EcParametricTranslationGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcParametricTranslationGraspOffsetState
      (
      );

   /// copy constructor
   EcParametricTranslationGraspOffsetState
      (
      const EcParametricTranslationGraspOffsetState& orig
      );

   /// assignment operator
   EcParametricTranslationGraspOffsetState& operator=
      (
      const EcParametricTranslationGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcParametricTranslationGraspOffsetState& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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
   virtual const EcToken& token
      (
      ) const;

   /// get the target offset
   virtual EcGraspOffsetState* targetOffsetState
      (
      );

   /// get the target offset
   virtual const EcGraspOffsetState* targetOffsetState
      (
      ) const;

   /// set the target offset
   virtual void setTargetOffsetState
      (
      const EcGraspOffsetStateContainer& targetOffsetState
      );

   /// get the parametric transform
   virtual const EcEndEffectorPlacement& parametricTransform
      (
      ) const;

   /// set the parametric transform
   virtual void setParametricTransform
      (
      const EcEndEffectorPlacement& transform
      );

   /// get the current offset
   virtual const EcEndEffectorPlacement& currentOffset
      (
      ) const;

   /// set the current offset
   virtual void setCurrentOffset
      (
      const EcEndEffectorPlacement& offset
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
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
   /// target offset for the inerpolation
   EcGraspOffsetStateContainer      m_TargetOffsetState;

   /// parametric transform
   EcEndEffectorPlacement m_ParametricTransform;

   /// current offset
   EcEndEffectorPlacement m_CurrentOffset;

   /// goal offset
   mutable EcEndEffectorPlacement m_GoalOffset;
};

#endif // ecParametricTranslationGraspOffsetState_H_
