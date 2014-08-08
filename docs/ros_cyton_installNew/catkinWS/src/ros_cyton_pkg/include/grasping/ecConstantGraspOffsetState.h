#ifndef ecConstantGraspOffsetState_H_
#define ecConstantGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecConstantGraspOffsetState.h
/// @class EcConstantGraspOffsetState
/// @brief This class provides a grasp offset that remains constant.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffsetState.h"

/// This class provides a grasp offset that remains constant.
class EC_ACTIN_GRASPING_DECL EcConstantGraspOffsetState : public EcGraspOffsetState
{
public:
   /// default constructor
   EcConstantGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcConstantGraspOffsetState
      (
      );

   /// copy constructor
   EcConstantGraspOffsetState
      (
      const EcConstantGraspOffsetState& orig
      );

   /// assignment operator
   EcConstantGraspOffsetState& operator=
      (
      const EcConstantGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcConstantGraspOffsetState& orig
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
};

#endif // ecConstantGraspOffsetState_H_
